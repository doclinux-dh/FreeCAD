/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "ExpressionParser.y" /* yacc.c:339  */


#define YYSTYPE App::ExpressionParser::semantic_type

std::stack<FunctionExpression::Function> functions;                /**< Function identifier */

       //#define YYSTYPE yystype
       #define yyparse ExpressionParser_yyparse
       #define yyerror ExpressionParser_yyerror

#line 77 "ExpressionParser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "ExpressionParser.tab.h".  */
#ifndef YY_YY_EXPRESSIONPARSER_TAB_H_INCLUDED
# define YY_YY_EXPRESSIONPARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNC = 258,
    ONE = 259,
    NUM = 260,
    IDENTIFIER = 261,
    UNIT = 262,
    INTEGER = 263,
    CONSTANT = 264,
    CELLADDRESS = 265,
    EQ = 266,
    NEQ = 267,
    LT = 268,
    GT = 269,
    GTE = 270,
    LTE = 271,
    STRING = 272,
    MINUSSIGN = 273,
    PROPERTY_REF = 274,
    DOCUMENT = 275,
    OBJECT = 276,
    EXPONENT = 277,
    NUM_AND_UNIT = 278,
    NEG = 279,
    POS = 280
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXPRESSIONPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 149 "ExpressionParser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   398

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    38,     2,    28,     2,     2,
      36,    33,    26,    25,    34,     2,    37,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    24,    35,
       2,     2,     2,    23,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    29,    31,
      32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    88,
      89,    90,    91,    93,    94,    95,    96,    97,    98,   101,
     104,   105,   106,   107,   108,   109,   112,   115,   116,   117,
     118,   119,   120,   121,   122,   125,   126,   130,   131,   135,
     136,   140,   144,   148,   152,   161,   166,   170,   177,   178,
     179,   180,   181,   182,   183,   184,   188,   189,   190,   191,
     195,   196,   200,   201
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNC", "ONE", "NUM", "IDENTIFIER",
  "UNIT", "INTEGER", "CONSTANT", "CELLADDRESS", "EQ", "NEQ", "LT", "GT",
  "GTE", "LTE", "STRING", "MINUSSIGN", "PROPERTY_REF", "DOCUMENT",
  "OBJECT", "EXPONENT", "'?'", "':'", "'+'", "'*'", "'/'", "'%'",
  "NUM_AND_UNIT", "'^'", "NEG", "POS", "')'", "','", "';'", "'('", "'.'",
  "'#'", "'['", "']'", "$accept", "input", "exp", "num", "args", "range",
  "cond", "unit", "unit_exp", "integer", "id_or_cell", "identifier",
  "iden", "indexer", "indexable", "document", "object", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    63,    58,    43,    42,    47,    37,   278,
      94,   279,   280,    41,    44,    59,    40,    46,    35,    91,
      93
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     162,   162,   -35,   -35,   -34,   -35,   -35,   -35,    17,   162,
     162,   162,    73,    32,   360,    -5,    30,    26,    29,    37,
     -10,    31,    41,   360,    12,   -35,   -18,   -35,   -35,   317,
     -35,   -35,   -35,   -35,   162,   162,   162,   162,   162,   162,
     162,   162,   162,    92,   162,   162,   -35,   -35,    16,   -35,
      50,   162,   116,   -35,   121,    75,   -35,   129,   144,   -35,
     162,   162,    -3,   -35,   360,   360,   360,   360,   360,   360,
     -15,   -15,    56,    56,   -35,    56,   -35,    60,    85,    -5,
      -5,    10,   340,   139,   177,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   360,   -35,   360,   -35,   -35,    -5,   -35,
      50,    50,   -35,   -35,    22,   -35,   162,   162,   197,    67,
     -35,   365,   -35,   156,   237,   162,   -35,   162,   -35,   217,
     -35,   -35,   257,   277,   162,   -35,   -35,   -35,   297,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    19,    20,    47,    21,    22,    48,     5,     0,
       0,     0,     0,     0,     2,     3,     0,    49,     6,    50,
      16,     0,     0,    23,     0,    24,    49,     7,     8,     0,
      47,    51,    52,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    36,     0,    37,
       4,     0,     0,    67,     0,     0,    68,     0,     0,    17,
       0,     0,     0,    66,    30,    31,    32,    33,    34,    35,
      10,     9,    11,    12,    14,    13,    15,     0,     0,     0,
       0,     0,     0,     0,     0,    56,    57,    69,    72,    73,
      55,    53,    54,    25,    27,    26,    28,    29,     0,    43,
      40,    39,    46,    45,     0,    41,     0,     0,     0,     0,
      58,     0,    42,    18,     0,     0,    60,     0,    59,     0,
      44,    61,     0,     0,     0,    62,    64,    63,     0,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,   -35,    -1,    40,   -35,    -4,   -35,    46,   -31,   -11,
       4,   -35,   -35,    74,   -35,   -35,    79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,    14,    15,    24,    25,    16,    49,    50,   105,
      17,    18,    19,    53,    20,    21,    22
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    46,    47,    30,   -71,    26,    62,     7,    27,    28,
      29,    42,    43,    44,   102,    45,    32,    78,   103,   -73,
       2,     3,    46,    47,     5,     6,   102,    55,   104,    52,
     103,    48,    33,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    75,    76,    59,    60,    61,   100,   101,
      82,    84,    48,    51,   -72,   -70,    94,    96,    86,    93,
      95,    89,    92,   -73,    26,    26,    97,   111,    52,    57,
       1,     2,     3,     4,    54,     5,     6,     7,    58,    30,
      81,    87,   108,     7,     8,     9,    45,    98,    77,    74,
      31,   117,    10,   112,    56,     1,     2,     3,     4,    47,
       5,     6,     7,    11,    12,   113,   114,   118,   119,     8,
       9,    79,    80,     0,   122,    81,   123,    10,    99,     1,
       2,     3,     4,   128,     5,     6,     7,    30,    11,    12,
       0,     7,     0,     8,     9,    30,    90,     0,    85,     7,
      83,    10,     1,     2,     3,     4,    88,     5,     6,     7,
      30,     0,    11,    12,     7,     0,     8,     9,     0,     0,
       0,    91,     0,   107,    10,     1,     2,     3,     4,     0,
       5,     6,     7,     0,    40,    11,    12,     0,     0,     8,
       9,    41,    42,    43,    44,     0,    45,    10,    34,    35,
      36,    37,    38,    39,     0,    40,     0,     0,    11,    12,
       0,   109,    41,    42,    43,    44,     0,    45,    34,    35,
      36,    37,    38,    39,     0,    40,     0,   110,     0,     0,
       0,   115,    41,    42,    43,    44,     0,    45,    34,    35,
      36,    37,    38,    39,     0,    40,     0,   116,     0,     0,
       0,   124,    41,    42,    43,    44,     0,    45,    34,    35,
      36,    37,    38,    39,     0,    40,     0,   125,     0,     0,
       0,     0,    41,    42,    43,    44,     0,    45,    34,    35,
      36,    37,    38,    39,     0,    40,     0,   121,     0,     0,
       0,     0,    41,    42,    43,    44,     0,    45,    34,    35,
      36,    37,    38,    39,     0,    40,     0,   126,     0,     0,
       0,     0,    41,    42,    43,    44,     0,    45,    34,    35,
      36,    37,    38,    39,     0,    40,     0,   127,     0,     0,
       0,     0,    41,    42,    43,    44,     0,    45,    34,    35,
      36,    37,    38,    39,     0,    40,     0,   129,     0,     0,
       0,     0,    41,    42,    43,    44,     0,    45,     0,     0,
      63,    34,    35,    36,    37,    38,    39,     0,    40,     0,
       0,     0,     0,     0,   106,    41,    42,    43,    44,     0,
      45,    34,    35,    36,    37,    38,    39,     0,    40,     0,
       0,     0,     0,     0,     0,    41,    42,    43,    44,     0,
      45,    79,    80,     0,     0,    81,     0,     0,   120
};

static const yytype_int8 yycheck[] =
{
       1,     6,     7,     6,    38,     1,    24,    10,     9,    10,
      11,    26,    27,    28,     4,    30,    12,    48,     8,    37,
       4,     5,     6,     7,     8,     9,     4,    37,    18,    39,
       8,    36,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    33,    34,    35,    79,    80,
      51,    52,    36,    23,    37,    38,    60,    61,    54,    60,
      61,    57,    58,    37,    60,    61,    62,    98,    39,    38,
       3,     4,     5,     6,    37,     8,     9,    10,    37,     6,
      30,     6,    83,    10,    17,    18,    30,    27,    48,    43,
      17,    24,    25,   104,    20,     3,     4,     5,     6,     7,
       8,     9,    10,    36,    37,   106,   107,    40,   109,    17,
      18,    26,    27,    -1,   115,    30,   117,    25,    33,     3,
       4,     5,     6,   124,     8,     9,    10,     6,    36,    37,
      -1,    10,    -1,    17,    18,     6,    57,    -1,    17,    10,
      24,    25,     3,     4,     5,     6,    17,     8,     9,    10,
       6,    -1,    36,    37,    10,    -1,    17,    18,    -1,    -1,
      -1,    17,    -1,    24,    25,     3,     4,     5,     6,    -1,
       8,     9,    10,    -1,    18,    36,    37,    -1,    -1,    17,
      18,    25,    26,    27,    28,    -1,    30,    25,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    -1,    36,    37,
      -1,    24,    25,    26,    27,    28,    -1,    30,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    40,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    -1,    30,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    40,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    -1,    30,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    40,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    40,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    40,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    40,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    40,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      33,    11,    12,    13,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    -1,
      30,    11,    12,    13,    14,    15,    16,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    26,    27,    -1,    -1,    30,    -1,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    10,    17,    18,
      25,    36,    37,    42,    43,    44,    47,    51,    52,    53,
      55,    56,    57,    43,    45,    46,    51,    43,    43,    43,
       6,    17,    51,     0,    11,    12,    13,    14,    15,    16,
      18,    25,    26,    27,    28,    30,     6,     7,    36,    48,
      49,    23,    39,    54,    37,    37,    54,    38,    37,    33,
      34,    35,    24,    33,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    48,    43,    43,    44,    49,    26,
      27,    30,    43,    24,    43,    17,    51,     6,    17,    51,
      57,    17,    51,    43,    46,    43,    46,    51,    27,    33,
      49,    49,     4,     8,    18,    50,    24,    24,    43,    24,
      40,    49,    50,    43,    43,    24,    40,    24,    40,    43,
      33,    40,    43,    43,    24,    40,    40,    40,    43,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    44,
      44,    44,    44,    45,    45,    45,    45,    45,    45,    46,
      47,    47,    47,    47,    47,    47,    48,    49,    49,    49,
      49,    49,    49,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    55,    55,    55,
      56,    56,    57,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     5,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     3,
       3,     3,     4,     3,     5,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     3,     3,     3,     3,     3,     4,
       4,     5,     5,     6,     6,     7,     3,     2,     2,     3,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 43: /* exp  */
#line 59 "ExpressionParser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).expr); }
#line 1111 "ExpressionParser.tab.c" /* yacc.c:1257  */
        break;

    case 44: /* num  */
#line 59 "ExpressionParser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).expr); }
#line 1117 "ExpressionParser.tab.c" /* yacc.c:1257  */
        break;

    case 45: /* args  */
#line 61 "ExpressionParser.y" /* yacc.c:1257  */
      { std::vector<Expression*>::const_iterator i = ((*yyvaluep).arguments).begin(); while (i != ((*yyvaluep).arguments).end()) { delete *i; ++i; } }
#line 1123 "ExpressionParser.tab.c" /* yacc.c:1257  */
        break;

    case 46: /* range  */
#line 59 "ExpressionParser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).expr); }
#line 1129 "ExpressionParser.tab.c" /* yacc.c:1257  */
        break;

    case 47: /* cond  */
#line 59 "ExpressionParser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).expr); }
#line 1135 "ExpressionParser.tab.c" /* yacc.c:1257  */
        break;

    case 48: /* unit  */
#line 59 "ExpressionParser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).expr); }
#line 1141 "ExpressionParser.tab.c" /* yacc.c:1257  */
        break;

    case 49: /* unit_exp  */
#line 59 "ExpressionParser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).expr); }
#line 1147 "ExpressionParser.tab.c" /* yacc.c:1257  */
        break;

    case 54: /* indexer  */
#line 60 "ExpressionParser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).component); }
#line 1153 "ExpressionParser.tab.c" /* yacc.c:1257  */
        break;

    case 55: /* indexable  */
#line 59 "ExpressionParser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).expr); }
#line 1159 "ExpressionParser.tab.c" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 67 "ExpressionParser.y" /* yacc.c:1646  */
    { ScanResult = (yyvsp[0].expr); valueExpression = true;                                        }
#line 1423 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 70 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);                                                                        }
#line 1429 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 71 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-1].expr), OperatorExpression::UNIT, (yyvsp[0].expr));  }
#line 1435 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 72 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new StringExpression(DocumentObject, (yyvsp[0].string));                                  }
#line 1441 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 73 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new VariableExpression(DocumentObject, std::move((yyvsp[0].path)));                                }
#line 1447 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 74 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[0].expr), OperatorExpression::NEG, new NumberExpression(DocumentObject, Quantity(-1))); }
#line 1453 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 75 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[0].expr), OperatorExpression::POS, new NumberExpression(DocumentObject, Quantity(1))); }
#line 1459 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 76 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::ADD, (yyvsp[0].expr));   }
#line 1465 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 77 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::SUB, (yyvsp[0].expr));   }
#line 1471 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 78 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::MUL, (yyvsp[0].expr));   }
#line 1477 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 79 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::DIV, (yyvsp[0].expr));   }
#line 1483 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 80 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::MOD, (yyvsp[0].expr));   }
#line 1489 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 81 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::DIV, (yyvsp[0].expr));   }
#line 1495 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 82 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::POW, (yyvsp[0].expr));   }
#line 1501 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 83 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);                                                                        }
#line 1507 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 84 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FunctionExpression(DocumentObject, (yyvsp[-2].func), (yyvsp[-1].arguments));                   }
#line 1513 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 85 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ConditionalExpression(DocumentObject, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));                     }
#line 1519 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 88 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NumberExpression(DocumentObject, Quantity((yyvsp[0].fvalue)));                        }
#line 1525 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 89 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NumberExpression(DocumentObject, Quantity((yyvsp[0].fvalue)));                        }
#line 1531 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 90 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NumberExpression(DocumentObject, Quantity((double)(yyvsp[0].ivalue)));                }
#line 1537 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 91 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ConstantExpression(DocumentObject, (yyvsp[0].constant).name, Quantity((yyvsp[0].constant).fvalue));      }
#line 1543 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 93 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.arguments).push_back((yyvsp[0].expr));                                                               }
#line 1549 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 94 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.arguments).push_back((yyvsp[0].expr));                                                               }
#line 1555 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 95 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyvsp[-2].arguments).push_back((yyvsp[0].expr));  (yyval.arguments) = (yyvsp[-2].arguments);                                                     }
#line 1561 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 96 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyvsp[-2].arguments).push_back((yyvsp[0].expr));  (yyval.arguments) = (yyvsp[-2].arguments);                                                     }
#line 1567 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 97 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyvsp[-2].arguments).push_back((yyvsp[0].expr));  (yyval.arguments) = (yyvsp[-2].arguments);                                                     }
#line 1573 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 98 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyvsp[-2].arguments).push_back((yyvsp[0].expr));  (yyval.arguments) = (yyvsp[-2].arguments);                                                     }
#line 1579 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 101 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new RangeExpression(DocumentObject, (yyvsp[-2].string), (yyvsp[0].string));                               }
#line 1585 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 104 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::EQ, (yyvsp[0].expr));    }
#line 1591 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 105 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::NEQ, (yyvsp[0].expr));   }
#line 1597 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 106 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::LT, (yyvsp[0].expr));    }
#line 1603 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 107 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::GT, (yyvsp[0].expr));    }
#line 1609 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 108 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::GTE, (yyvsp[0].expr));   }
#line 1615 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 109 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::LTE, (yyvsp[0].expr));   }
#line 1621 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 112 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = UnitExpression::create(DocumentObject, (yyvsp[0].string).c_str() ); if (!(yyval.expr)) YYERROR; }
#line 1627 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 115 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1633 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 116 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = UnitExpression::create(DocumentObject, (yyvsp[0].string).c_str() ); if (!(yyval.expr)) YYERROR; }
#line 1639 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 117 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::DIV, (yyvsp[0].expr));   }
#line 1645 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 118 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::MUL, (yyvsp[0].expr));   }
#line 1651 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 119 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-2].expr), OperatorExpression::POW, new NumberExpression(DocumentObject, Quantity((double)(yyvsp[0].ivalue))));   }
#line 1657 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 120 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-3].expr), OperatorExpression::POW, new OperatorExpression(DocumentObject, new NumberExpression(DocumentObject, Quantity((double)(yyvsp[0].ivalue))), OperatorExpression::NEG, new NumberExpression(DocumentObject, Quantity(-1))));   }
#line 1663 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 121 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr);                                                                        }
#line 1669 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 122 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new OperatorExpression(DocumentObject, (yyvsp[-3].expr), OperatorExpression::DIV, (yyvsp[-1].expr));   }
#line 1675 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 125 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.ivalue) = (yyvsp[0].ivalue); }
#line 1681 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 126 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.ivalue) = (yyvsp[0].fvalue); }
#line 1687 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 130 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.string) = std::move((yyvsp[0].string)); }
#line 1693 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 131 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.string) = std::move((yyvsp[0].string)); }
#line 1699 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 135 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.path) = ObjectIdentifier(DocumentObject); (yyval.path) << ObjectIdentifier::SimpleComponent(std::move((yyvsp[0].string))); }
#line 1705 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 136 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.path) = std::move((yyvsp[0].path)); (yyval.path).resolveAmbiguity(); }
#line 1711 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 140 "ExpressionParser.y" /* yacc.c:1646  */
    {
                                                (yyval.path) = ObjectIdentifier(DocumentObject,true);
                                                (yyval.path).addComponent(ObjectIdentifier::LabelComponent(std::move((yyvsp[0].string))));
                                            }
#line 1720 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 144 "ExpressionParser.y" /* yacc.c:1646  */
    {
                                                (yyval.path) = ObjectIdentifier(DocumentObject,true);
                                                (yyval.path).addComponent(ObjectIdentifier::SimpleComponent(std::move((yyvsp[0].string))));
                                            }
#line 1729 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 148 "ExpressionParser.y" /* yacc.c:1646  */
    {
                                                (yyval.path) = ObjectIdentifier(DocumentObject);
                                                (yyval.path).setDocumentObjectName(std::move((yyvsp[-2].string_or_identifier)), true, ObjectIdentifier::String(std::move((yyvsp[0].string)),true),true);
                                            }
#line 1738 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 152 "ExpressionParser.y" /* yacc.c:1646  */
    {
                                                (yyval.path) = ObjectIdentifier(DocumentObject);
                                                (yyvsp[-2].string_or_identifier).checkImport(DocumentObject);
                                                if((yyvsp[-2].string_or_identifier).isRealString())
                                                    (yyval.path).addComponent(ObjectIdentifier::LabelComponent(std::move((yyvsp[-2].string_or_identifier).getString())));
                                                else
                                                    (yyval.path).addComponent(ObjectIdentifier::SimpleComponent(std::move((yyvsp[-2].string_or_identifier).getString())));
                                                (yyval.path).addComponent(ObjectIdentifier::SimpleComponent(std::move((yyvsp[0].string))));
                                            }
#line 1752 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 161 "ExpressionParser.y" /* yacc.c:1646  */
    {
                                                (yyval.path) = ObjectIdentifier(DocumentObject);
                                                (yyval.path).setDocumentName(std::move((yyvsp[-2].string_or_identifier)), true);
                                                (yyval.path).setDocumentObjectName(std::move((yyvsp[0].string_or_identifier)), true);
                                            }
#line 1762 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 166 "ExpressionParser.y" /* yacc.c:1646  */
    {
                                                (yyval.path) = std::move((yyvsp[-2].path));
                                                (yyval.path).addComponent(ObjectIdentifier::LabelComponent(std::move((yyvsp[0].string))));
                                            }
#line 1771 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 170 "ExpressionParser.y" /* yacc.c:1646  */
    {
                                                (yyval.path) = std::move((yyvsp[-2].path));
                                                (yyval.path).addComponent(ObjectIdentifier::SimpleComponent(std::move((yyvsp[0].string))));
                                            }
#line 1780 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 177 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.component) = Expression::createComponent((yyvsp[-1].expr));   }
#line 1786 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 178 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.component) = Expression::createComponent((yyvsp[-2].expr),0,0,true); }
#line 1792 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 179 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.component) = Expression::createComponent(0,(yyvsp[-1].expr)); }
#line 1798 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 180 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.component) = Expression::createComponent(0,0,(yyvsp[-1].expr)); }
#line 1804 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 181 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.component) = Expression::createComponent((yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 1810 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 182 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.component) = Expression::createComponent((yyvsp[-4].expr),0,(yyvsp[-1].expr)); }
#line 1816 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 183 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.component) = Expression::createComponent(0,(yyvsp[-3].expr),(yyvsp[-1].expr)); }
#line 1822 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 184 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.component) = Expression::createComponent((yyvsp[-5].expr),(yyvsp[-3].expr),(yyvsp[-1].expr));}
#line 1828 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 188 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1834 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 189 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.expr) = new VariableExpression(DocumentObject,std::move((yyvsp[-1].path))); (yyval.expr)->addComponent((yyvsp[0].component)); }
#line 1840 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 190 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyvsp[-1].expr)->addComponent(std::move((yyvsp[0].component))); (yyval.expr) = (yyvsp[-1].expr); }
#line 1846 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 191 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyvsp[-2].expr)->addComponent(Expression::createComponent((yyvsp[0].string))); (yyval.expr) = (yyvsp[-2].expr); }
#line 1852 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 195 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.string_or_identifier) = ObjectIdentifier::String(std::move((yyvsp[0].string)), true); }
#line 1858 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 196 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.string_or_identifier) = ObjectIdentifier::String(std::move((yyvsp[0].string)), false, true);}
#line 1864 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 200 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.string_or_identifier) = ObjectIdentifier::String(std::move((yyvsp[0].string)), true); }
#line 1870 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 201 "ExpressionParser.y" /* yacc.c:1646  */
    { (yyval.string_or_identifier) = ObjectIdentifier::String(std::move((yyvsp[0].string)), false);}
#line 1876 "ExpressionParser.tab.c" /* yacc.c:1646  */
    break;


#line 1880 "ExpressionParser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 204 "ExpressionParser.y" /* yacc.c:1906  */

