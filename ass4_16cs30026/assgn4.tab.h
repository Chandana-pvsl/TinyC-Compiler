/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
