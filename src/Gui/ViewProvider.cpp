/***************************************************************************
 *   Copyright (c) 2004 Jürgen Riegel <juergen.riegel@web.de>              *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#include "PreCompiled.h"

#ifndef _PreComp_
# include <QPixmap>
# include <QTimer>
# include <Inventor/SoPickedPoint.h>
# include <Inventor/nodes/SoSeparator.h>
# include <Inventor/nodes/SoSwitch.h>
# include <Inventor/details/SoDetail.h>
# include <Inventor/nodes/SoTransform.h>
# include <Inventor/nodes/SoCamera.h>
# include <Inventor/events/SoMouseButtonEvent.h>
# include <Inventor/events/SoLocation2Event.h>
# include <Inventor/actions/SoGetMatrixAction.h>
# include <Inventor/actions/SoSearchAction.h>
#endif

/// Here the FreeCAD includes sorted by Base,App,Gui......
#include <Base/Console.h>
#include <Base/Exception.h>
#include <Base/Matrix.h>
#include <App/PropertyGeo.h>

#include "ViewProvider.h"
#include "Application.h"
#include "ActionFunction.h"
#include "Document.h"
#include "ViewProviderPy.h"
#include "BitmapFactory.h"
#include "View3DInventor.h"
#include "View3DInventorViewer.h"
#include "SoFCDB.h"
#include "ViewProviderExtension.h"
#include "SoFCUnifiedSelection.h"

#include <boost/bind.hpp>

FC_LOG_LEVEL_INIT("ViewProvider",true,true)

using namespace std;
using namespace Gui;


//**************************************************************************
//**************************************************************************
// ViewProvider
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

PROPERTY_SOURCE_ABSTRACT(Gui::ViewProvider, App::TransactionalObject)

ViewProvider::ViewProvider()
    : pcAnnotation(0)
    , pyViewObject(0)
    , overrideMode("As Is")
    , _iActualMode(-1)
    , _iEditMode(-1)
    , viewOverrideMode(-1)
{
    setStatus(UpdateData, true);

    pcRoot = new SoSeparator();
    pcRoot->ref();
    pcModeSwitch = new SoSwitch();
    pcModeSwitch->ref();
    pcTransform  = new SoTransform();
    pcTransform->ref();
    pcRoot->addChild(pcTransform);
    pcRoot->addChild(pcModeSwitch);
    sPixmap = "px";
    pcModeSwitch->whichChild = _iActualMode;
}

ViewProvider::~ViewProvider()
{
    if (pyViewObject) {
        pyViewObject->setInvalid();
        pyViewObject->DecRef();
    }

    pcRoot->unref();
    pcTransform->unref();
    pcModeSwitch->unref();
    if (pcAnnotation)
        pcAnnotation->unref();
}

ViewProvider *ViewProvider::startEditing(int ModNum)
{
    if(setEdit(ModNum)) {
        _iEditMode = ModNum;
        return this;
    }
    return 0;
}

int ViewProvider::getEditingMode() const
{
    return _iEditMode;
}

bool ViewProvider::isEditing() const
{
    return getEditingMode() > -1;
}

void ViewProvider::finishEditing()
{
    unsetEdit(_iEditMode);
    _iEditMode = -1;
}

bool ViewProvider::setEdit(int ModNum)
{
    Q_UNUSED(ModNum); 
    return true;
}

void ViewProvider::unsetEdit(int ModNum)
{
    Q_UNUSED(ModNum); 
}

void ViewProvider::setEditViewer(View3DInventorViewer*, int ModNum)
{
    Q_UNUSED(ModNum); 
}

void ViewProvider::unsetEditViewer(View3DInventorViewer*)
{
}

bool ViewProvider::isUpdatesEnabled () const
{
    return testStatus(UpdateData);
}

void ViewProvider::setUpdatesEnabled (bool enable)
{
    setStatus(UpdateData, enable);
}

void highlight(const HighlightMode& high)
{
    Q_UNUSED(high); 
}

void ViewProvider::eventCallback(void * ud, SoEventCallback * node)
{
    const SoEvent * ev = node->getEvent();
    Gui::View3DInventorViewer* viewer = reinterpret_cast<Gui::View3DInventorViewer*>(node->getUserData());
    ViewProvider *self = reinterpret_cast<ViewProvider*>(ud);
    assert(self);

    try {
        // Keyboard events
        if (ev->getTypeId().isDerivedFrom(SoKeyboardEvent::getClassTypeId())) {
            SoKeyboardEvent * ke = (SoKeyboardEvent *)ev;
            const SbBool press = ke->getState() == SoButtonEvent::DOWN ? true : false;
            switch (ke->getKey()) {
            case SoKeyboardEvent::ESCAPE:
                if (self->keyPressed (press, ke->getKey())) {
                    node->setHandled();
                }
                else {
                    Gui::TimerFunction* func = new Gui::TimerFunction();
                    func->setAutoDelete(true);
                    Gui::Document* doc = Gui::Application::Instance->activeDocument();
                    func->setFunction(boost::bind(&Document::resetEdit, doc));
                    QTimer::singleShot(0, func, SLOT(timeout()));
                }
                break;
            default:
                // call the virtual method
                if (self->keyPressed (press, ke->getKey()))
                    node->setHandled();
                break;
            }
        }
        // switching the mouse buttons
        else if (ev->getTypeId().isDerivedFrom(SoMouseButtonEvent::getClassTypeId())) {

            const SoMouseButtonEvent * const event = (const SoMouseButtonEvent *) ev;
            const int button = event->getButton();
            const SbBool press = event->getState() == SoButtonEvent::DOWN ? true : false;

            // call the virtual method
            if (self->mouseButtonPressed(button,press,ev->getPosition(),viewer))
                node->setHandled();
        }
        // Mouse Movement handling
        else if (ev->getTypeId().isDerivedFrom(SoLocation2Event::getClassTypeId())) {
            if (self->mouseMove(ev->getPosition(),viewer))
                node->setHandled();
        }
    }
    catch (const Base::Exception& e) {
        Base::Console().Error("Unhandled exception in ViewProvider::eventCallback: %s\n", e.what());
    }
    catch (const std::exception& e) {
        Base::Console().Error("Unhandled std exception in ViewProvider::eventCallback: %s\n", e.what());
    }
    catch (...) {
        Base::Console().Error("Unhandled unknown C++ exception in ViewProvider::eventCallback");
    }
}

SoSeparator* ViewProvider::getAnnotation(void)
{
    if (!pcAnnotation) {
        pcAnnotation = new SoSeparator();
        pcAnnotation->ref();
        pcRoot->addChild(pcAnnotation);
    }
    return pcAnnotation;
}

void ViewProvider::update(const App::Property* prop)
{
    // Hide the object temporarily to speed up the update
    if (!isUpdatesEnabled())
        return;
    bool vis = ViewProvider::isShow();
    if (vis) ViewProvider::hide();
    updateData(prop);
    if (vis) ViewProvider::show();
}

QIcon ViewProvider::getIcon(void) const
{
    return Gui::BitmapFactory().pixmap(sPixmap);
}

void ViewProvider::setTransformation(const Base::Matrix4D &rcMatrix)
{
    double dMtrx[16];
    rcMatrix.getGLMatrix(dMtrx);

    pcTransform->setMatrix(SbMatrix(dMtrx[0], dMtrx[1], dMtrx[2],  dMtrx[3],
                                    dMtrx[4], dMtrx[5], dMtrx[6],  dMtrx[7],
                                    dMtrx[8], dMtrx[9], dMtrx[10], dMtrx[11],
                                    dMtrx[12],dMtrx[13],dMtrx[14], dMtrx[15]));
}

void ViewProvider::setTransformation(const SbMatrix &rcMatrix)
{
    pcTransform->setMatrix(rcMatrix);
}

SbMatrix ViewProvider::convert(const Base::Matrix4D &rcMatrix)
{
    double dMtrx[16];
    rcMatrix.getGLMatrix(dMtrx);
    return SbMatrix(dMtrx[0], dMtrx[1], dMtrx[2],  dMtrx[3],
                    dMtrx[4], dMtrx[5], dMtrx[6],  dMtrx[7],
                    dMtrx[8], dMtrx[9], dMtrx[10], dMtrx[11],
                    dMtrx[12],dMtrx[13],dMtrx[14], dMtrx[15]);
}

Base::Matrix4D ViewProvider::convert(const SbMatrix &smat)
{
    Base::Matrix4D mat;
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
            mat[i][j] = smat[j][i];
    return mat;
}

void ViewProvider::addDisplayMaskMode(SoNode *node, const char* type)
{
    _sDisplayMaskModes[type] = pcModeSwitch->getNumChildren();
    pcModeSwitch->addChild(node);
}

void ViewProvider::setDisplayMaskMode(const char* type)
{
    std::map<std::string, int>::const_iterator it = _sDisplayMaskModes.find(type);
    if (it != _sDisplayMaskModes.end())
        _iActualMode = it->second;
    else
        _iActualMode = -1;
    setModeSwitch();
}

SoNode* ViewProvider::getDisplayMaskMode(const char* type) const
{
    std::map<std::string, int>::const_iterator it = _sDisplayMaskModes.find( type );
    if (it != _sDisplayMaskModes.end()) {
        return pcModeSwitch->getChild(it->second);
    }

    return 0;
}

std::vector<std::string> ViewProvider::getDisplayMaskModes() const
{
    std::vector<std::string> types;
    for (std::map<std::string, int>::const_iterator it = _sDisplayMaskModes.begin();
         it != _sDisplayMaskModes.end(); ++it)
        types.push_back( it->first );
    return types;
}

/**
 * If you add new viewing modes in @ref getDisplayModes() then you need to reimplement
 * also seDisplaytMode() to handle these new modes by setting the appropriate display
 * mode.
 */
void ViewProvider::setDisplayMode(const char* ModeName)
{
    _sCurrentMode = ModeName;
    
    //infom the exteensions
    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector)
        ext->extensionSetDisplayMode(ModeName);
}

const char* ViewProvider::getDefaultDisplayMode() const {

    return 0;
}

vector<std::string> ViewProvider::getDisplayModes(void) const {

    std::vector< std::string > modes;
    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector) {
        auto extModes = ext->extensionGetDisplayModes();
        modes.insert( modes.end(), extModes.begin(), extModes.end() );
    }
    return modes;
}

std::string ViewProvider::getActiveDisplayMode(void) const
{
    return _sCurrentMode;
}

void ViewProvider::hide(void)
{
    pcModeSwitch->whichChild = -1;

    //tell extensions that we hide
    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector)
        ext->extensionHide();
}

void ViewProvider::show(void)
{
    setModeSwitch();
    
    //tell extensions that we show
    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector)
        ext->extensionShow();
}

bool ViewProvider::isShow(void) const
{
    return pcModeSwitch->whichChild.getValue() != -1;
}

void ViewProvider::setVisible(bool s)
{
    s ? show() : hide();
}

bool ViewProvider::isVisible() const
{
    return isShow();
}

void ViewProvider::setOverrideMode(const std::string &mode)
{
    if (mode == "As Is") {
        viewOverrideMode = -1;
        overrideMode = mode;
    }
    else {
        std::map<std::string, int>::const_iterator it = _sDisplayMaskModes.find(mode);
        if (it == _sDisplayMaskModes.end())
            return; //view style not supported
        viewOverrideMode = (*it).second;
        overrideMode = mode;
    }
    if (pcModeSwitch->whichChild.getValue() != -1)
        setModeSwitch();
}

const string ViewProvider::getOverrideMode() {
    return overrideMode;
}


void ViewProvider::setModeSwitch()
{
    if (viewOverrideMode == -1)
        pcModeSwitch->whichChild = _iActualMode;
    else if (viewOverrideMode < pcModeSwitch->getNumChildren())
        pcModeSwitch->whichChild = viewOverrideMode;
}

void ViewProvider::setDefaultMode(int val)
{
    _iActualMode = val;
}

void ViewProvider::onChanged(const App::Property* prop)
{
    Application::Instance->signalChangedObject(*this, *prop);

    App::TransactionalObject::onChanged(prop);
}

std::string ViewProvider::toString() const
{
    return SoFCDB::writeNodesToString(pcRoot);
}

PyObject* ViewProvider::getPyObject()
{
    if (!pyViewObject)
        pyViewObject = new ViewProviderPy(this);
    pyViewObject->IncRef();
    return pyViewObject;
}

#include <boost/graph/topological_sort.hpp>

namespace Gui {
typedef boost::adjacency_list <
        boost::vecS,           // class OutEdgeListS  : a Sequence or an AssociativeContainer
        boost::vecS,           // class VertexListS   : a Sequence or a RandomAccessContainer
        boost::directedS,      // class DirectedS     : This is a directed graph
        boost::no_property,    // class VertexProperty:
        boost::no_property,    // class EdgeProperty:
        boost::no_property,    // class GraphProperty:
        boost::listS           // class EdgeListS:
> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef boost::graph_traits<Graph>::edge_descriptor Edge;

void addNodes(Graph& graph, std::map<SoNode*, Vertex>& vertexNodeMap, SoNode* node)
{
    if (node->getTypeId().isDerivedFrom(SoGroup::getClassTypeId())) {
        SoGroup* group = static_cast<SoGroup*>(node);
        Vertex groupV = vertexNodeMap[group];

        for (int i=0; i<group->getNumChildren(); i++) {
            SoNode* child = group->getChild(i);
            auto it = vertexNodeMap.find(child);

            // the child node is not yet added to the map
            if (it == vertexNodeMap.end()) {
                Vertex childV = add_vertex(graph);
                vertexNodeMap[child] = childV;
                add_edge(groupV, childV, graph);
                addNodes(graph, vertexNodeMap, child);
            }
            // the child is already there, only add the edge then
            else {
                add_edge(groupV, it->second, graph);
            }
        }
    }
}
}

bool ViewProvider::checkRecursion(SoNode* node)
{
    if (node->getTypeId().isDerivedFrom(SoGroup::getClassTypeId())) {
        std::list<Vertex> make_order;
        Graph graph;
        std::map<SoNode*, Vertex> vertexNodeMap;
        Vertex groupV = add_vertex(graph);
        vertexNodeMap[node] = groupV;
        addNodes(graph, vertexNodeMap, node);

        try {
            boost::topological_sort(graph, std::front_inserter(make_order));
        }
        catch (const std::exception&) {
            return false;
        }
    }

    return true;
}

SoPickedPoint* ViewProvider::getPointOnRay(const SbVec2s& pos, const View3DInventorViewer* viewer) const
{
    return viewer->getPointOnRay(pos,const_cast<ViewProvider*>(this));
}

SoPickedPoint* ViewProvider::getPointOnRay(const SbVec3f& pos,const SbVec3f& dir, const View3DInventorViewer* viewer) const
{
    return viewer->getPointOnRay(pos,dir,const_cast<ViewProvider*>(this));
}


std::vector<Base::Vector3d> ViewProvider::getModelPoints(const SoPickedPoint* pp) const
{
    // the default implementation just returns the picked point from the visual representation
    std::vector<Base::Vector3d> pts;
    const SbVec3f& vec = pp->getPoint();
    pts.push_back(Base::Vector3d(vec[0],vec[1],vec[2]));
    return pts;
}

bool ViewProvider::keyPressed(bool pressed, int key)
{
    (void)pressed;
    (void)key;
    return false;
}

bool ViewProvider::mouseMove(const SbVec2s &cursorPos,
                             View3DInventorViewer* viewer)
{
    (void)cursorPos;
    (void)viewer;
    return false;
}

bool ViewProvider::mouseButtonPressed(int button, bool pressed,
                                      const SbVec2s &cursorPos,
                                      const View3DInventorViewer* viewer)
{
    (void)button;
    (void)pressed;
    (void)cursorPos;
    (void)viewer;
    return false;
}

bool ViewProvider::onDelete(const vector< string >& subNames) {
    bool del = true;
    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector)
        del &= ext->extensionOnDelete(subNames);

    return del;
}

bool ViewProvider::canDelete(App::DocumentObject*) const
{
    return false;
}

bool ViewProvider::canDragObject(App::DocumentObject* obj) const {

    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector) {
        if(ext->extensionCanDragObject(obj))
            return true;
    }

    return false;
}

bool ViewProvider::canDragObjects() const {

    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector) {
        if(ext->extensionCanDragObjects())
            return true;
    }

    return false;
}

void ViewProvider::dragObject(App::DocumentObject* obj) {

    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector) {
        if(ext->extensionCanDragObject(obj)) {
            ext->extensionDragObject(obj);
            return;
        }
    }

    throw Base::RuntimeError("ViewProvider::dragObject: no extension for dragging given object available.");
}


bool ViewProvider::canDropObject(App::DocumentObject* obj) const {

    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
#if FC_DEBUG
    Base::Console().Log("Check extensions for drop\n");
#endif
    for(Gui::ViewProviderExtension* ext : vector){
#if FC_DEBUG
        Base::Console().Log("Check extensions %s\n", ext->name().c_str());
#endif
        if(ext->extensionCanDropObject(obj))
            return true;
    }

    return false;
}

bool ViewProvider::canDropObjects() const {

    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector)
        if(ext->extensionCanDropObjects())
            return true;

    return false;
}

bool ViewProvider::canDragAndDropObject(App::DocumentObject* obj) const {

    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector){
        if(!ext->extensionCanDragAndDropObject(obj))
            return false;
    }

    return true;
}

void ViewProvider::dropObject(App::DocumentObject* obj) {

    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector) {
        if(ext->extensionCanDropObject(obj)) {
            ext->extensionDropObject(obj);
            return;
        }
    }

    throw Base::RuntimeError("ViewProvider::dropObject: no extension for dropping given object available.");
}

bool ViewProvider::canDropObjectEx(App::DocumentObject* obj, App::DocumentObject *owner, 
        const char *subname, const std::vector<std::string> &elements) const
{
    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector){
        if(ext->extensionCanDropObjectEx(obj,owner,subname, elements))
            return true;
    }
    return canDropObject(obj);
}

void ViewProvider::dropObjectEx(App::DocumentObject* obj, App::DocumentObject *owner, 
        const char *subname, const std::vector<std::string> &elements) 
{
    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector) {
        if(ext->extensionCanDropObjectEx(obj, owner, subname, elements)) {
            ext->extensionDropObjectEx(obj, owner, subname, elements);
            return;
        }
    }
    dropObject(obj);
}

void ViewProvider::Restore(Base::XMLReader& reader) {
    // Because some PropertyLists type properties are stored in a separate file,
    // and is thus restored outside this function. So we rely on Gui::Document
    // to set the isRestoring flags for us.
    //
    // setStatus(Gui::isRestoring, true);

    TransactionalObject::Restore(reader);

    // setStatus(Gui::isRestoring, false);
}

void ViewProvider::updateData(const App::Property* prop) {

    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector)
        ext->extensionUpdateData(prop);
}

SoSeparator* ViewProvider::getBackRoot(void) const {

    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector) {
        auto* node = ext->extensionGetBackRoot();
        if(node)
            return node;
    }
    return nullptr;
}

SoGroup* ViewProvider::getChildRoot(void) const {

    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector) {
        auto* node = ext->extensionGetChildRoot();
        if(node)
            return node;
    }
    return nullptr;
}

SoSeparator* ViewProvider::getFrontRoot(void) const {

    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector) {
        auto* node = ext->extensionGetFrontRoot();
        if(node)
            return node;
    }
    return nullptr;
}

std::vector< App::DocumentObject* > ViewProvider::claimChildren(void) const {

    std::vector< App::DocumentObject* > vec;
    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector) {
        std::vector< App::DocumentObject* > nvec = ext->extensionClaimChildren();
        if(!nvec.empty())
            vec.insert(std::end(vec), std::begin(nvec), std::end(nvec));  
    }
    return vec;
}

std::vector< App::DocumentObject* > ViewProvider::claimChildren3D(void) const {

    std::vector< App::DocumentObject* > vec;
    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector) {
        std::vector< App::DocumentObject* > nvec = ext->extensionClaimChildren3D();
        if(!nvec.empty())
            vec.insert(std::end(vec), std::begin(nvec), std::end(nvec));  
    }
    return vec;
}
bool ViewProvider::getElementPicked(const SoPickedPoint *pp, std::string &subname) const {
    if(!isSelectable()) return false;
    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector)
        if(ext->extensionGetElementPicked(pp,subname))
            return true;
    subname = getElement(pp?pp->getDetail():0);
    return true;
}

bool ViewProvider::getDetailPath(const char *subelement, SoFullPath *pPath, bool append, SoDetail *&det) const {
    if(pcRoot->findChild(pcModeSwitch) < 0) {
        // this is possible in case of editing, where the switch node
        // of the linked view object is temparaly removed from its root
        // if(append)
        //     pPath->append(pcRoot);
        return false;
    }
    if(append) {
        pPath->append(pcRoot);
        pPath->append(pcModeSwitch);
    }
    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector)
        if(ext->extensionGetDetailPath(subelement,pPath,det))
            return true;
    det = getDetail(subelement);
    return true;
}

const std::string &ViewProvider::hiddenMarker() {
    return App::DocumentObject::hiddenMarker();
}

const char *ViewProvider::hasHiddenMarker(const char *subname) {
    return App::DocumentObject::hasHiddenMarker(subname);
}

int ViewProvider::partialRender(const std::vector<std::string> &elements, bool clear) {
    if(elements.empty()) {
        auto node = pcModeSwitch->getChild(_iActualMode);
        if(node) {
            FC_LOG("partial render clear");
            SoSelectionElementAction action(SoSelectionElementAction::None,true);
            action.apply(node);
        }
    }
    int count = 0;
    SoFullPath *path = static_cast<SoFullPath*>(new SoPath);
    path->ref();
    SoSelectionElementAction action;
    action.setSecondary(true);
    for(auto element : elements) {
        bool hidden = hasHiddenMarker(element.c_str());
        if(hidden) 
            element.resize(element.size()-hiddenMarker().size());
        path->truncate(0);
        SoDetail *det = 0;
        if(getDetailPath(element.c_str(),path,false,det)) {
            if(!hidden && !det) {
                FC_LOG("partial render element not found: " << element);
                continue;
            }
            FC_LOG("partial render (" << path->getLength() << "): " << element);
            if(!hidden) 
                action.setType(clear?SoSelectionElementAction::Remove:SoSelectionElementAction::Append);
            else
                action.setType(clear?SoSelectionElementAction::Show:SoSelectionElementAction::Hide);
            action.setElement(det);
            action.apply(path);
            ++count;
        }
        delete det;
    }
    path->unref();
    return count;
}

bool ViewProvider::useNewSelectionModel() const {
    static int useNewModel = -1;
    if(useNewModel<0) {
        ParameterGrp::handle hGrp = 
            App::GetApplication().GetParameterGroupByPath("User parameter:BaseApp/Preferences/View");
        useNewModel = hGrp->GetBool("UseNewSelection",true)?1:0;
    }
    return useNewModel>0;
}

void ViewProvider::beforeDelete() {
    auto vector = getExtensionsDerivedFromType<Gui::ViewProviderExtension>();
    for(Gui::ViewProviderExtension* ext : vector)
        ext->extensionBeforeDelete();
}

