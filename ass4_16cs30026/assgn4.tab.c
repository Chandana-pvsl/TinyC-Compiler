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
#line 1 "ass4_16cs30026.y" /* yacc.c:339  */

	#define YYSTYPE double
	#include <ctype.h>
	#include <stdio.h>
	void yyerror(const char*);
	extern int yylex();


#line 75 "ass4_16cs30026.tab.c" /* yacc.c:339  */

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
   by #include "ass4_16cs30026.tab.h".  */
#ifndef YY_YY_ASS4_16CS30026_TAB_H_INCLUDED
# define YY_YY_ASS4_16CS30026_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TYPEDEF = 258,
    EXTERN = 259,
    STATIC = 260,
    AUTO = 261,
    REGISTER = 262,
    INLINE = 263,
    RESTRICT = 264,
    CHAR = 265,
    SHORT = 266,
    INT = 267,
    LONG = 268,
    SIGNED = 269,
    UNSIGNED = 270,
    FLOAT = 271,
    DOUBLE = 272,
    CONST = 273,
    VOLATILE = 274,
    VOID = 275,
    BOOL = 276,
    COMPLEX = 277,
    IMAGINARY = 278,
    STRUCT = 279,
    UNION = 280,
    ENUM = 281,
    BREAK = 282,
    CASE = 283,
    CONTINUE = 284,
    DEFAULT = 285,
    DO = 286,
    IF = 287,
    ELSE = 288,
    FOR = 289,
    GOTO = 290,
    WHILE = 291,
    SWITCH = 292,
    SIZEOF = 293,
    RETURN = 294,
    IDENTIFIER = 295,
    STRING_LITERAL = 296,
    INTEGER_CONSTANT = 297,
    FLOATING_CONSTANT = 298,
    ENUM_CONSTANT = 299,
    CHAR_CONSTANT = 300,
    ELLIPSE = 301,
    ASSIGN = 302,
    ASSIGN_RS = 303,
    ASSIGN_LS = 304,
    ASSIGN_ADD = 305,
    ASSIGN_SUB = 306,
    ASSIGN_MUL = 307,
    ASSIGN_DIV = 308,
    ASSIGN_MODULO = 309,
    ASSIGN_BIT_AND = 310,
    ASSIGN_BIT_XOR = 311,
    ASSIGN_BIT_OR = 312,
    RS = 313,
    LS = 314,
    INCREMENT = 315,
    DECREMENT = 316,
    AND = 317,
    OR = 318,
    LTE = 319,
    GTE = 320,
    EQ = 321,
    NEQ = 322,
    LT = 323,
    GT = 324,
    ARROW = 325,
    BIT_AND = 326,
    BIT_OR = 327,
    BIT_XOR = 328,
    THEN = 329
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASS4_16CS30026_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "ass4_16cs30026.tab.c" /* yacc.c:358  */

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
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  209
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  341

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    87,     2,     2,     2,    89,     2,     2,
      75,    76,    83,    84,    82,    85,    79,    88,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    91,    92,
       2,     2,     2,    90,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    80,     2,    81,    86,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    28,    28,    29,    30,    31,    36,    37,    38,    39,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    54,
      55,    59,    60,    64,    65,    66,    67,    68,    69,    73,
      74,    75,    76,    77,    78,    82,    83,    87,    88,    89,
      90,    93,    94,    95,    99,   100,   101,   105,   106,   107,
     108,   109,   113,   114,   115,   119,   120,   124,   125,   129,
     130,   134,   135,   139,   140,   144,   145,   150,   151,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     169,   170,   174,   175,   179,   183,   184,   190,   191,   192,
     193,   194,   195,   196,   197,   201,   202,   206,   207,   211,
     212,   213,   214,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   234,   235,   239,   240,
     245,   246,   247,   251,   252,   256,   257,   261,   262,   266,
     267,   268,   272,   276,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   293,   294,   298,   299,   303,   304,   308,
     309,   313,   314,   317,   318,   322,   323,   327,   328,   332,
     333,   337,   341,   342,   343,   347,   348,   349,   350,   354,
     358,   359,   363,   364,   368,   369,   370,   371,   372,   373,
     377,   378,   379,   383,   384,   389,   390,   394,   395,   399,
     403,   407,   408,   409,   413,   414,   415,   416,   420,   421,
     422,   423,   427,   428,   432,   433,   437,   438,   443,   444
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "RESTRICT", "CHAR", "SHORT", "INT", "LONG",
  "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID",
  "BOOL", "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM", "BREAK",
  "CASE", "CONTINUE", "DEFAULT", "DO", "IF", "ELSE", "FOR", "GOTO",
  "WHILE", "SWITCH", "SIZEOF", "RETURN", "IDENTIFIER", "STRING_LITERAL",
  "INTEGER_CONSTANT", "FLOATING_CONSTANT", "ENUM_CONSTANT",
  "CHAR_CONSTANT", "ELLIPSE", "ASSIGN", "ASSIGN_RS", "ASSIGN_LS",
  "ASSIGN_ADD", "ASSIGN_SUB", "ASSIGN_MUL", "ASSIGN_DIV", "ASSIGN_MODULO",
  "ASSIGN_BIT_AND", "ASSIGN_BIT_XOR", "ASSIGN_BIT_OR", "RS", "LS",
  "INCREMENT", "DECREMENT", "AND", "OR", "LTE", "GTE", "EQ", "NEQ", "LT",
  "GT", "ARROW", "BIT_AND", "BIT_OR", "BIT_XOR", "THEN", "'('", "')'",
  "'['", "']'", "'.'", "'{'", "'}'", "','", "'*'", "'+'", "'-'", "'~'",
  "'!'", "'/'", "'%'", "'?'", "':'", "';'", "$accept",
  "primary_expression", "constant", "postfix_expression",
  "argument_expression_list_opt", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "AND_expression",
  "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression_opt", "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier",
  "specifier_qualifier_list_opt", "specifier_qualifier_list",
  "enum_specifier", "identifier_opt", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "pointer_opt", "pointer", "type_qualifier_list_opt",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list_opt", "identifier_list",
  "type_name", "initializer", "initializer_list", "designation",
  "designator_list", "designator", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement_base",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "declaration_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    40,    41,    91,    93,    46,
     123,   125,    44,    42,    43,    45,   126,    33,    47,    37,
      63,    58,    59
};
# endif

#define YYPACT_NINF -231

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-231)))

#define YYTABLE_NINF -157

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1244,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,    23,  -231,   -41,  1244,  1244,  -231,  1244,  1244,  1221,
    -231,  -231,   -32,    35,    57,  -231,   -33,  -231,   611,   -28,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,    37,  -231,    14,
      57,    14,  -231,   835,   280,  -231,   -41,  -231,   634,  -231,
      14,    41,    38,   -63,  -231,  -231,  -231,  -231,    82,   985,
    -231,  -231,  -231,  -231,  -231,  -231,  1021,  1021,  -231,   527,
     785,  -231,  -231,  -231,  -231,  -231,  -231,  -231,   -15,   204,
    1057,  -231,   -66,    78,   111,    68,   105,    54,    61,    66,
      96,   -49,  -231,  -231,  -231,    90,  1057,    97,    94,   635,
     112,   117,   154,   124,   128,  1057,   113,  -231,  -231,   114,
     125,  -231,  -231,  -231,  -231,   364,  -231,  -231,   175,  -231,
    -231,  -231,  -231,  -231,   133,  1184,    52,  1057,  -231,   -27,
     527,  -231,   527,  -231,  -231,   -39,  1159,  -231,  1159,   134,
    1057,   171,  -231,    93,   835,   -21,  -231,  -231,  -231,   172,
    1057,  1057,   173,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  1057,  -231,  -231,  1057,  1057,  1057,
    1057,  1057,  1057,  1057,  1057,  1057,  1057,  1057,  1057,  1057,
    1057,  1057,  1057,  1057,  1057,  1057,  -231,  -231,   123,  -231,
     635,   180,  1057,   448,   126,  1057,  1057,   127,   635,  -231,
    1057,  -231,  -231,   635,  -231,  -231,     8,   141,   138,  -231,
     145,   140,    57,   885,    64,  -231,  -231,  -231,   148,   149,
    -231,  -231,  -231,  -231,   935,   150,  -231,  -231,   685,  -231,
    -231,  -231,  -231,   151,   144,  -231,    27,  -231,  -231,  -231,
    -231,  -231,   -66,   -66,    78,    78,   111,   111,   111,   111,
      68,    68,   105,    54,    61,    66,    96,    -3,   635,  -231,
     157,     5,   142,  1057,  -231,    13,    16,  -231,  -231,  -231,
    -231,  -231,  -231,  1141,  -231,   193,  1057,  -231,   159,   160,
    1057,   155,   155,   785,  -231,  -231,  -231,  -231,   835,  -231,
    1057,  -231,  1057,  -231,  1057,   635,  1057,   147,   635,   635,
    -231,  -231,  -231,   163,  -231,  -231,   164,    95,  -231,  -231,
    -231,    32,  -231,   152,  1057,  -231,  -231,  -231,  -231,  -231,
     735,   153,  1057,   186,  -231,  -231,   187,   635,   635,  -231,
    -231
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    99,   100,   101,   102,   132,   130,   104,   105,   106,
     107,   110,   111,   108,   109,   129,   131,   103,   112,   113,
     114,   124,   205,   144,    88,    90,   115,    92,    94,     0,
     202,   204,   122,     0,   148,    86,     0,    95,    97,     0,
     143,    87,    89,    91,    93,     1,   203,     0,   149,   145,
     147,   144,    85,     0,    81,   208,   144,   207,     0,   134,
     144,   133,   127,     0,   125,   146,   150,    96,    97,     0,
       2,     4,     6,     7,     8,     9,     0,     0,    29,     0,
       0,    30,    31,    32,    33,    34,    10,     3,    23,    35,
       0,    37,    41,    44,    47,    52,    55,    57,    59,    61,
      63,    65,    67,   162,    98,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,    81,     2,   184,    82,     0,
      80,   187,   188,   174,   175,    81,   185,   176,   191,   177,
     178,   179,   209,   206,     0,   158,   148,     0,   120,     0,
       0,    27,     0,    24,    25,     0,   117,   161,   117,     0,
       0,     0,   165,     0,     0,     0,   170,    15,    16,     0,
      20,     0,     0,    69,    76,    75,    73,    74,    70,    71,
      72,    77,    78,    79,     0,    35,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,    84,     0,   199,
      81,     0,     0,    81,     0,     0,     0,     0,    81,   189,
       0,   183,   186,    81,   135,   159,   144,     0,   151,   153,
       0,   157,   148,     0,   147,   128,   121,   126,     0,     0,
       5,   118,   116,   119,     0,     0,   173,   163,     0,   166,
     169,   171,    14,     0,    19,    21,     0,    13,    68,    38,
      39,    40,    42,    43,    46,    45,    50,    51,    48,    49,
      53,    54,    56,    58,    60,    62,    64,     0,    81,   182,
       0,     0,     0,    81,   198,     0,     0,   201,   180,    83,
     192,   155,   141,     0,   142,     0,     0,   137,    30,     0,
       0,    28,     0,     0,    36,   172,   164,   167,     0,    12,
       0,    11,     0,   181,     0,    81,    81,     0,    81,    81,
     152,   154,   160,     0,   140,   136,     0,     0,   168,    22,
      66,     0,   190,     0,    81,   194,   193,   138,   139,    17,
       0,     0,    81,     0,    18,   195,     0,    81,    81,   197,
     196
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,  -231,  -231,  -231,  -231,   -38,  -231,   -56,    -1,
       1,   -19,     2,    59,    56,    73,    74,    72,  -231,   -97,
     -50,  -231,  -109,   -75,  -117,   -22,     0,  -231,   217,  -231,
     -68,   121,   -20,  -231,  -231,  -231,   131,   -29,  -231,   -16,
    -231,  -231,   222,  -126,   136,  -231,  -231,   -10,  -231,  -231,
      17,   -52,   -18,  -230,  -231,   119,  -107,  -231,   -23,  -231,
     156,  -231,  -231,  -231,  -231,  -231,  -231,   247,  -231,  -231
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    86,    87,    88,   243,   244,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     118,   174,   119,   120,   198,    22,    56,    36,    37,    24,
      25,   231,   147,    26,    33,    63,    64,    27,    28,    68,
      61,    39,    40,    49,    50,   217,   218,   219,   220,   221,
     149,   152,   153,   154,   155,   156,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    29,    30,    31,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,   104,   201,   103,   145,    48,   207,    38,   298,   197,
     223,   146,    59,    62,   194,    57,    55,   177,   138,   139,
     225,    66,   178,   179,    41,    42,   240,    43,    44,    23,
     103,   141,   121,   235,   176,   133,   132,   230,   143,   144,
     197,   195,    34,   210,   134,   157,   158,    60,  -123,    51,
     148,    35,   175,   197,   226,   159,   150,   222,   151,    52,
     160,     6,   161,    32,   162,   145,     6,   145,   175,   290,
      15,    16,   146,     6,   146,    15,    16,    62,   146,   210,
     146,   305,    15,    16,  -156,   137,   246,   210,   302,   308,
    -156,    34,   309,   269,   272,   210,   286,    34,   210,   175,
     298,   278,   239,   121,   103,   301,   280,    48,   331,   210,
     245,   148,   175,   148,   210,    47,   135,   148,   136,   148,
     267,   249,   250,   251,   248,   190,   232,   271,   232,    53,
     275,   276,   184,   185,   191,   216,   186,   187,   192,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   228,   193,   229,
     279,   303,   180,   181,   307,   256,   257,   258,   259,   182,
     183,   188,   189,   289,   237,   238,   329,   330,   294,   252,
     253,   273,   196,   254,   255,   200,   297,   202,   103,   199,
     260,   261,   203,    48,   204,    66,   175,   323,   322,   205,
     281,   325,   326,   206,   208,   320,   209,   210,   213,   214,
     234,   236,   242,   247,   268,   333,   270,   282,   274,   277,
     283,   284,   285,   336,   291,   292,   300,   299,   295,   321,
     339,   340,   304,   312,   306,   293,   313,   314,   315,   324,
     316,   327,   328,   103,   332,   335,   318,   263,   103,   262,
     319,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   337,   338,   175,   264,   266,   265,    67,   233,
     227,    65,   224,   311,   241,   317,    46,     0,   297,     0,
     103,   212,     0,   216,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,    21,   105,   106,   107,
     108,   109,   110,     0,   111,   112,   113,   114,    69,   115,
     116,    71,    72,    73,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,    79,     0,     0,     0,     0,
      54,   117,     0,    81,    82,    83,    84,    85,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
      21,   105,   106,   107,   108,   109,   110,     0,   111,   112,
     113,   114,    69,   115,   116,    71,    72,    73,    74,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,    79,
       0,     0,     0,     0,    54,   211,     0,    81,    82,    83,
      84,    85,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,    70,    71,
      72,    73,    74,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,    81,    82,    83,    84,    85,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,     0,    70,    71,    72,
      73,    74,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,    21,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    53,     0,
      21,     0,   105,   106,   107,   108,   109,   110,     0,   111,
     112,   113,   114,    69,   115,   116,    71,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
      79,     0,     0,     0,    54,    54,     0,     0,    81,    82,
      83,    84,    85,    69,     0,    70,    71,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
      79,     0,   150,     0,   151,    80,   296,     0,    81,    82,
      83,    84,    85,    69,     0,    70,    71,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
      79,     0,   150,     0,   151,    80,   334,     0,    81,    82,
      83,    84,    85,    69,     0,    70,    71,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
      79,     0,   150,     0,   151,    80,     0,     0,    81,    82,
      83,    84,    85,    69,     0,    70,    71,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
      79,     0,     0,     0,     0,    80,     0,     0,    81,    82,
      83,    84,    85,    69,     0,    70,    71,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
      79,     0,     0,   287,     0,     0,     0,     0,   288,    82,
      83,    84,    85,    69,     0,    70,    71,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
      79,     0,     0,     0,     0,   293,     0,     0,    81,    82,
      83,    84,    85,    69,     0,    70,    71,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,    69,
     140,    70,    71,    72,    73,    74,    75,     0,    81,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,    69,   142,    70,    71,    72,
      73,    74,    75,     0,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,    21,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,    21,     0,   310,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,     0,     0,   215,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,    21,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
      21
};

static const yytype_int16 yycheck[] =
{
       0,    53,   109,    53,    79,    34,   115,    23,   238,   106,
     136,    79,    40,    40,    63,    38,    38,    83,    81,    82,
     137,    50,    88,    89,    24,    25,    47,    27,    28,    29,
      80,    69,    54,   150,    90,    58,    58,    76,    76,    77,
     137,    90,    83,    82,    60,    60,    61,    75,    80,    82,
      79,    92,    90,   150,    81,    70,    77,     5,    79,    92,
      75,     9,    77,    40,    79,   140,     9,   142,   106,     5,
      18,    19,   140,     9,   142,    18,    19,    40,   146,    82,
     148,    76,    18,    19,    76,    47,   161,    82,    91,    76,
      82,    83,    76,   200,   203,    82,   222,    83,    82,   137,
     330,   208,   154,   125,   154,    78,   213,   136,    76,    82,
     160,   140,   150,   142,    82,    80,    75,   146,    77,   148,
     195,   177,   178,   179,   174,    71,   146,   202,   148,    47,
     205,   206,    64,    65,    73,   135,    68,    69,    72,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   140,    62,   142,
     210,   268,    84,    85,   273,   184,   185,   186,   187,    58,
      59,    66,    67,   223,    81,    82,    81,    82,   234,   180,
     181,   203,    92,   182,   183,    91,   238,    75,   238,    92,
     188,   189,    75,   222,    40,   224,   234,   306,   305,    75,
     216,   308,   309,    75,    91,   302,    92,    82,    33,    76,
      76,    40,    40,    40,    91,   324,    36,    76,    92,    92,
      82,    76,    82,   332,    76,    76,    82,    76,    78,   304,
     337,   338,    75,    40,    92,    80,   286,    78,    78,    92,
     290,    78,    78,   293,    92,    92,   298,   191,   298,   190,
     300,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    76,    76,   302,   192,   194,   193,    51,   148,
     139,    49,   136,   283,   155,   293,    29,    -1,   330,    -1,
     330,   125,    -1,   283,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      80,    81,    -1,    83,    84,    85,    86,    87,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    80,    81,    -1,    83,    84,    85,
      86,    87,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    87,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    86,    87,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    26,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    47,    -1,
      26,    -1,    27,    28,    29,    30,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    80,    80,    -1,    -1,    83,    84,
      85,    86,    87,    38,    -1,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      75,    -1,    77,    -1,    79,    80,    81,    -1,    83,    84,
      85,    86,    87,    38,    -1,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      75,    -1,    77,    -1,    79,    80,    81,    -1,    83,    84,
      85,    86,    87,    38,    -1,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      75,    -1,    77,    -1,    79,    80,    -1,    -1,    83,    84,
      85,    86,    87,    38,    -1,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,    84,
      85,    86,    87,    38,    -1,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    38,    -1,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,    84,
      85,    86,    87,    38,    -1,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    38,
      75,    40,    41,    42,    43,    44,    45,    -1,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    38,    75,    40,    41,    42,
      43,    44,    45,    -1,    83,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    86,    87,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    26,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    26,    -1,    46,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,    -1,    -1,    40,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    26,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    26,   118,   119,   122,   123,   126,   130,   131,   159,
     160,   161,    40,   127,    83,    92,   120,   121,   132,   134,
     135,   119,   119,   119,   119,     0,   160,    80,   130,   136,
     137,    82,    92,    47,    80,   118,   119,   151,   162,    40,
      75,   133,    40,   128,   129,   135,   130,   121,   132,    38,
      40,    41,    42,    43,    44,    45,    60,    61,    71,    75,
      80,    83,    84,    85,    86,    87,    94,    95,    96,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   144,    27,    28,    29,    30,    31,
      32,    34,    35,    36,    37,    39,    40,    81,   113,   115,
     116,   118,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   118,   151,   132,    75,    77,    47,    81,    82,
      75,    99,    75,    99,    99,   116,   123,   125,   130,   143,
      77,    79,   144,   145,   146,   147,   148,    60,    61,    70,
      75,    77,    79,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,   114,    99,   101,    83,    88,    89,
      84,    85,    58,    59,    64,    65,    68,    69,    66,    67,
      71,    73,    72,    62,    63,    90,    92,   112,   117,    92,
      91,   149,    75,    75,    40,    75,    75,   115,    91,    92,
      82,    81,   153,    33,    76,    40,   119,   138,   139,   140,
     141,   142,     5,   136,   137,   117,    81,   129,   143,   143,
      76,   124,   125,   124,    76,   117,    40,    81,    82,   144,
      47,   148,    40,    97,    98,   113,   116,    40,   113,   101,
     101,   101,   102,   102,   103,   103,   104,   104,   104,   104,
     105,   105,   106,   107,   108,   109,   110,   116,    91,   149,
      36,   116,   115,   118,    92,   116,   116,    92,   149,   113,
     149,   132,    76,    82,    76,    82,   136,    78,    83,   113,
       5,    76,    76,    80,   101,    78,    81,   144,   146,    76,
      82,    78,    91,   149,    75,    76,    92,   115,    76,    76,
      46,   140,    40,   113,    78,    78,   113,   145,   144,   113,
     112,   116,   149,   115,    92,   149,   149,    78,    78,    81,
      82,    76,    92,   115,    81,    92,   115,    76,    76,   149,
     149
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    94,    94,    94,    95,    95,    95,    95,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    99,    99,    99,    99,    99,    99,   100,
     100,   100,   100,   100,   100,   101,   101,   102,   102,   102,
     102,   103,   103,   103,   104,   104,   104,   105,   105,   105,
     105,   105,   106,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   112,   112,   113,   113,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   116,   116,   117,   118,   118,   119,   119,   119,
     119,   119,   119,   119,   119,   120,   120,   121,   121,   122,
     122,   122,   122,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   124,   124,   125,   125,
     126,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     130,   130,   131,   132,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   138,   139,   139,   140,   140,   141,   141,   142,
     142,   143,   144,   144,   144,   145,   145,   145,   145,   146,
     147,   147,   148,   148,   149,   149,   149,   149,   149,   149,
     150,   150,   150,   151,   151,   152,   152,   153,   153,   154,
     155,   156,   156,   156,   157,   157,   157,   157,   158,   158,
     158,   158,   159,   159,   160,   160,   161,   161,   162,   162
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     4,     4,     3,     3,     2,     2,     6,     7,     1,
       0,     1,     3,     1,     2,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     3,     1,     3,     2,     2,     1,     2,
       1,     2,     1,     2,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     2,
       5,     6,     2,     1,     0,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     1,     3,     5,     4,     6,     6,
       5,     4,     4,     1,     0,     2,     3,     1,     0,     1,
       2,     1,     3,     1,     3,     2,     1,     1,     0,     1,
       3,     1,     1,     3,     4,     1,     2,     3,     4,     2,
       1,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     3,     2,     1,     2,     1,     1,     2,
       5,     1,     3,     5,     5,     7,     9,     8,     3,     2,
       2,     3,     1,     2,     1,     1,     4,     3,     1,     2
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
  YYUSE (yytype);
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
#line 28 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("primary_expression-> identifier \n");}
#line 1746 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 29 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("primary_expression-> constant \n");}
#line 1752 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 30 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("primary_expression-> string literal \n");}
#line 1758 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 31 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("primary_expression-> expression \n");}
#line 1764 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 36 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("constant->integer constant \n");}
#line 1770 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 37 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("constant->floating constant \n");}
#line 1776 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 38 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("constant->enumeration constant \n");}
#line 1782 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 39 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("constant->character constant \n");}
#line 1788 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 42 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("postfix expression-> primary expression\n");}
#line 1794 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 43 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("postfix expression-> postfix_expression [expression] \n");}
#line 1800 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 44 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("postfix expression-> postfix_expression (argument_expression_list_opt) \n");}
#line 1806 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 45 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("postfix expression-> postfix_expression.IDENTIFIER \n");}
#line 1812 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 46 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("postfix expression-> postfix_expression ARROW IDENTIFIER \n");}
#line 1818 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 47 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("postfix expression-> postfix_expression INCREMENT \n");}
#line 1824 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 48 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("postfix expression-> postfix_expression DECREMENT \n");}
#line 1830 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 49 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("postfix expression-> (type_name) {initializer_list} \n");}
#line 1836 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 50 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("postfix expression-> (type_name)  {initializer_list,} \n");}
#line 1842 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 54 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("argument_expression_list \n");}
#line 1848 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 59 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("argument_expression \n");}
#line 1854 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 60 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("argument_expression_list, assignment_expression \n");}
#line 1860 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 64 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("unary expression -> postfix_expression");}
#line 1866 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 65 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("unary expression -> ++unary_expression");}
#line 1872 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 66 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("unary expression -> --unary_expression");}
#line 1878 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 67 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("unary expression -> unary_operator cast_expression");}
#line 1884 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 68 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("unary expression -> sizeof unary_expression");}
#line 1890 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 69 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("unary expression -> sizeof (type-name) ");}
#line 1896 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 73 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("unary operator-> &\n");}
#line 1902 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 74 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("unary operator-> *\n");}
#line 1908 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 75 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("unary operator-> +\n");}
#line 1914 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 76 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("unary operator-> -\n");}
#line 1920 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 77 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("unary operator-> ~\n");}
#line 1926 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 78 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("unary operator-> !\n");}
#line 1932 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 82 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("cast-expression-> unary-expression\n");}
#line 1938 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 83 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("cast-expression-> (type_name) cast_expression n\n");}
#line 1944 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 87 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("multiplicative-expression-> cast-expression\n");}
#line 1950 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 88 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("multiplicative-expression->multiplicative-expression * cast-expression\n");}
#line 1956 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 89 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("multiplicative-expression-> multiplicative-expression / cast-expression\n");}
#line 1962 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 90 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("multiplicative-expression-> multiplicative-expression %% cast-expression\n");}
#line 1968 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 93 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("additive-expression-> multiplicative-expression\n");}
#line 1974 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 94 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("additive-expression-> additive-expression + multiplicative-expression\n");}
#line 1980 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 95 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("additive-expression-> additive-expression - multiplicative-expression\n");}
#line 1986 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 99 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("shift-expression-> additive-expression\n");}
#line 1992 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 100 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("shift-expression-> shift_expression << additive-expression\n");}
#line 1998 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 101 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("shift-expression-> shift_expression >>additive-expression\n");}
#line 2004 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 105 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("relational-expression -> shift-expression\n");}
#line 2010 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 106 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("relational-expression -> relational_expression < shift-expression\n");}
#line 2016 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 107 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("relational-expression -> relational_expression > shift-expression\n");}
#line 2022 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 108 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("relational-expression -> relational_expression <=  shift-expression\n");}
#line 2028 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 109 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("relational-expression -> relational_expression >= shift-expression\n");}
#line 2034 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 113 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("equality-expression -> relational_expression\n");}
#line 2040 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 114 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("equality-expression -> equality_expression == relational-expression\n");}
#line 2046 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 115 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("equality-expression -> equality_expression != relational-expression\n");}
#line 2052 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 119 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("AND-expression -> equality-expression\n");}
#line 2058 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 120 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("AND-expression -> AND_expression & equality_expression \n");}
#line 2064 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 124 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("exclusive_OR_expression -> AND_expression \n");}
#line 2070 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 125 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("exclusive_OR_expression -> exclusive_OR_expression ^ AND_expression \n");}
#line 2076 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 129 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("inclusive_OR_expression->exclusive_OR_expression\n");}
#line 2082 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 130 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("inclusive_OR_expression->inclusive_OR_expression | exclusive_OR_expression\n");}
#line 2088 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 134 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("logical_AND_expression->inclusive_OR_expression\n");}
#line 2094 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 135 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("logical_AND_expression->logical_AND_expression && inclusive_OR_expression\n");}
#line 2100 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 139 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("logical_OR_expression->logical_AND_expression\n");}
#line 2106 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 140 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("logical_OR_expression->logical_OR_expression || logical_AND_expression\n");}
#line 2112 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 144 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("conditional-expression->logical_OR_expression\n");}
#line 2118 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 145 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("conditional-expression->logical_OR_expression ? expression : conditional_expression\n");}
#line 2124 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 150 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("assignment_expression->conditional_expression\n");}
#line 2130 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 151 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("assignment_expression->unary_expression assignment_operator assignment_expression\n");}
#line 2136 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 155 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("assignment_operator-> = \n");}
#line 2142 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 156 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("assignment_operator-> *= \n");}
#line 2148 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 157 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("assignment_operator-> /= \n");}
#line 2154 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 158 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("assignment_operator-> %%= \n");}
#line 2160 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 159 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("assignment_operator-> += \n");}
#line 2166 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 160 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("assignment_operator-> -= \n");}
#line 2172 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 161 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("assignment_operator-> <<= \n");}
#line 2178 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 162 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("assignment_operator-> >>= \n");}
#line 2184 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 163 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("assignment_operator-> &= \n");}
#line 2190 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 164 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("assignment_operator-> ^= \n");}
#line 2196 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 165 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("assignment_operator-> |= \n");}
#line 2202 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 169 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("expression_opt -> expression \n");}
#line 2208 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 170 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("expression_opt -> empty \n");}
#line 2214 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 174 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("expression -> assignment-expression \n");}
#line 2220 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 175 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("expression -> expression , assignment-expression \n");}
#line 2226 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 179 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("constant-expression \n");}
#line 2232 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 183 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("declaration ->declaration_specifiers initializer_list; \n");}
#line 2238 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 184 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("declaration -> declaration_specifiers ; \n");}
#line 2244 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 190 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("declaration_specifiers -> storage_class_specifier declaration_specifiers \n");}
#line 2250 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 191 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("declaration_specifiers -> storage_class_specifier \n");}
#line 2256 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 192 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("declaration_specifiers -> type_specifier declaration_specifiers \n");}
#line 2262 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 193 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("declaration_specifiers -> type_specifier \n");}
#line 2268 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 194 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("declaration_specifiers -> type_qualifier declaration_specifiers \n");}
#line 2274 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 195 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("declaration_specifiers -> type_qualifier \n");}
#line 2280 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 196 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("declaration_specifiers -> function_specifier declaration_specifiers \n");}
#line 2286 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 197 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("declaration_specifiers -> type_qualifier \n");}
#line 2292 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 201 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("init_declarator_list -> init_declarator");}
#line 2298 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 202 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("init_declarator_list -> init_declarator_list , init_declarator \n");}
#line 2304 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 206 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("init-declarator -> declarator\n");}
#line 2310 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 207 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("init-declarator -> declarator = initializer\n");}
#line 2316 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 211 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("storage_class_specifier -> extern\n");}
#line 2322 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 212 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("storage_class_specifier -> static\n");}
#line 2328 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 213 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("storage_class_specifier -> auto\n");}
#line 2334 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 214 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("storage_class_specifier -> register\n");}
#line 2340 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 218 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("type_specifier -> void\n");}
#line 2346 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 219 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("type_specifier -> char\n");}
#line 2352 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 220 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("type_specifier -> short\n");}
#line 2358 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 221 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("type_specifier -> int\n");}
#line 2364 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 222 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("type_specifier -> long\n");}
#line 2370 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 223 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("type_specifier -> float\n");}
#line 2376 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 224 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("type_specifier -> double\n");}
#line 2382 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 225 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("type_specifier -> signed\n");}
#line 2388 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 226 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("type_specifier -> unsigned\n");}
#line 2394 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 227 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("type_specifier -> _bool\n");}
#line 2400 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 228 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("type_specifier -> _complex\n");}
#line 2406 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 229 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("type_specifier -> _imaginary\n");}
#line 2412 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 230 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("type_specifier -> enum_specifier\n");}
#line 2418 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 234 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("specifier_qualifier_list_opt-> specifier_qualifier_list\n");}
#line 2424 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 239 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("specifier_qualifier_list -> type_specifier specifier_qualifier_list_opt\n");}
#line 2430 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 240 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("specifier_qualifier_list -> type_qualifier specifier_qualifier_list_opt\n");}
#line 2436 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 245 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("enum specifier -> ENUM identifier_opt { enumerator_list }\n");}
#line 2442 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 246 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("enum specifier -> ENUM identifier_opt { enumerator_list , }\n");}
#line 2448 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 247 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("enum specifier -> ENUM identifier\n");}
#line 2454 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 251 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("identifier_opt -> identifier\n");}
#line 2460 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 256 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("enumerator_list -> enumerator \n");}
#line 2466 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 257 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" enumerator_list-> enumerator_list , enumerator \n");}
#line 2472 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 261 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" enumerator -> identifier \n");}
#line 2478 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 262 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" enumerator -> identifier = constant_expression \n");}
#line 2484 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 266 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" type_qualifier -> const \n");}
#line 2490 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 267 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" type_qualifier -> restrict \n");}
#line 2496 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 268 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" type_qualifier -> volatile \n");}
#line 2502 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 272 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" function-specifier -> inline \n");}
#line 2508 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 276 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" declarator -> pointer_opt direct_declarator \n");}
#line 2514 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 281 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" direct_declarator -> identifier \n");}
#line 2520 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 282 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" direct_declarator -> ( direct_declarator)\n");}
#line 2526 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 283 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" direct_declarator-> [type_qualifier_list_opt assignment_expression ] \n");}
#line 2532 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 284 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" direct_declarator-> [type_qualifier_list_opt ] \n");}
#line 2538 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 285 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" direct_declarator-> [static type_qualifier_list_opt assignment_expression ] \n");}
#line 2544 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 286 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" direct_declarator-> [type_qualifier_list static assignment_expression ] \n");}
#line 2550 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 287 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" direct_declarator-> [type_qualifier_list_opt *] \n");}
#line 2556 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 288 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" direct_declarator-> direct_declarator (parameter_list)\n");}
#line 2562 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 289 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" direct_declarator-> direct_declarator (identifier_list_opt)\n");}
#line 2568 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 293 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" pointer_opt -> pointer\n");}
#line 2574 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 294 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" pointer_opt -> empty\n");}
#line 2580 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 298 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" pointer -> *type_qualifier_list_opt\n");}
#line 2586 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 299 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" pointer -> *type_qualifier_list_opt pointer\n");}
#line 2592 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 303 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" type_qualifier_list_opt-> type_qualifier_list\n");}
#line 2598 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 308 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" type_qualifier_list-> type_qualifier\n");}
#line 2604 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 309 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" type_qualifier_list-> type_qualifier_list type_qualifier\n");}
#line 2610 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 313 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" parameter_type_list-> parameter_list\n");}
#line 2616 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 314 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" parameter_type_list-> parameter_list, ...\n");}
#line 2622 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 317 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" parameter_list-> parameter_declaration\n");}
#line 2628 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 318 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" parameter_list-> parameter_list, parameter_declaration\n");}
#line 2634 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 322 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" parameter_declaration-> declaration_specifiers declarator\n");}
#line 2640 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 323 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" parameter_declaration-> declaration_specifiers \n");}
#line 2646 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 327 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" identifier_list_opt-> identifier_list \n");}
#line 2652 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 328 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" identifier_list_opt-> empty\n");}
#line 2658 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 332 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" identifier_list-> identifier \n");}
#line 2664 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 333 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" identifier_list-> identifier_list , identifier \n");}
#line 2670 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 337 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" type_name->specifier_qualifier_list \n");}
#line 2676 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 341 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("initializer-> assignment_expression \n");}
#line 2682 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 342 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" initializer->{initializer-list} \n");}
#line 2688 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 343 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" initializer->{initializer-list ,} \n");}
#line 2694 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 347 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" initializer_list->initializer \n");}
#line 2700 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 348 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" initializer_list->designation initializer \n");}
#line 2706 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 349 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" initializer_list->initializer_list , initializer \n");}
#line 2712 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 350 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" initializer_list->initializer_list, designation initializer \n");}
#line 2718 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 354 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" designation-> designator_list =  \n");}
#line 2724 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 358 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" designator_list-> designator\n");}
#line 2730 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 359 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" designator_list-> designator_list designator\n");}
#line 2736 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 363 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" designator->[constant expression]\n");}
#line 2742 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 364 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" designator-> .identifier\n");}
#line 2748 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 368 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" statement->labeled_statement\n");}
#line 2754 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 369 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" statement->compound_statement\n");}
#line 2760 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 370 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" statement->expression_statement\n");}
#line 2766 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 371 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" statement->selection_statement\n");}
#line 2772 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 372 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" statement->iteration_statement\n");}
#line 2778 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 373 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" statement->jump_statement\n");}
#line 2784 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 377 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" labeled_statement -> identifier : statement\n");}
#line 2790 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 378 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" labeled_statement ->CASE constant_expression ':' statement \n");}
#line 2796 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 379 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" labeled_statement -> DEFAULT : statement\n");}
#line 2802 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 383 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" compund_statement -> {block_item_list}	\n");}
#line 2808 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 384 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" compund_statement -> {}	\n");}
#line 2814 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 389 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" block_item_list -> block_item	\n");}
#line 2820 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 390 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" block_item_list -> block_item_list block_item	\n");}
#line 2826 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 394 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" block_item -> declaration	\n");}
#line 2832 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 395 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" block_item ->statement\n");}
#line 2838 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 399 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf(" expression_statement-> expression_opt	\n");}
#line 2844 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 403 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("selection_statement_base-> if (expression) statement	\n");}
#line 2850 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 408 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("selection_statement-> selection_statement_base else statement\n");}
#line 2856 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 409 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("selection_statement-> switch (expression) statement\n");}
#line 2862 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 413 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("iteration_statement-> while (expression) statement 	\n");}
#line 2868 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 414 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("iteration_statement-> do statement while (expression);	\n");}
#line 2874 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 415 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("iteration_statement-> for(expression_opt;expression_opt ;expression_opt ) statement \n");}
#line 2880 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 416 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("iteration_statement->for(declaration  expression_opt ;  expression_opt ) statement\n");}
#line 2886 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 420 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("jump_statement-> GOTO IDENTIFIER ; 	\n");}
#line 2892 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 421 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("jump_statement-> CONTINUE ;	\n");}
#line 2898 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 422 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("jump_statement-> BREAK ;	\n");}
#line 2904 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 423 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("jump_statement-> RETURN expression_opt;	\n");}
#line 2910 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 427 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("translational_unit->external_declaration\n");}
#line 2916 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 428 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("translational_unit->translational_unit external_declaration\n");}
#line 2922 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 432 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("external_declaration -> function_definition 	\n");}
#line 2928 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 433 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("external_declaration -> declaration	\n");}
#line 2934 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 437 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement 	\n");}
#line 2940 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 438 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("function_definition -> declaration_specifiers declarator compound_statement 	\n");}
#line 2946 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 443 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("decalaration_list -> declaration\n");}
#line 2952 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 444 "ass4_16cs30026.y" /* yacc.c:1646  */
    {printf("decalaration_list -> declaration_list declaration\n");}
#line 2958 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
    break;


#line 2962 "ass4_16cs30026.tab.c" /* yacc.c:1646  */
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
#line 447 "ass4_16cs30026.y" /* yacc.c:1906  */


void yyerror (const char *s)  /* Called by yyparse on error */
{
  printf ("%s\n", s);
}
