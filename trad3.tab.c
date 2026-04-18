/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "trad3.y"
                          // SECCION 1 Declaraciones de C-Yacc

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata

int yylex () ;
int yyerror (char *mensaje) ;
char *my_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;

char temp [2048] ;

// Abstract Syntax Tree (AST) Node Structure

typedef struct ASTnode t_node ;

struct ASTnode {
    char *op ;
    int type ;      // leaf, unary or binary nodes
    t_node *left ;
    t_node *right ;
} ;


// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER
    char *code ;   // - to pass IDENTIFIER names, and other translations
    t_node *node ; // - for possible future use of AST
} t_attr ;

#define YYSTYPE t_attr

// --- INICIO PUNTO 8: Tabla de variables locales ---

#define MAX_LOCALS 256
char local_vars[MAX_LOCALS][256] ;
int n_locals = 0 ;
char current_func[256] = "" ;

void clear_locals()
{
    n_locals = 0 ;
}

void add_local(char *name)
{
    if (n_locals < MAX_LOCALS) {
        strcpy(local_vars[n_locals], name) ;
        n_locals++ ;
    }
}

int is_local(char *name)
{
    int i ;
    for (i = 0 ; i < n_locals ; i++) {
        if (strcmp(local_vars[i], name) == 0) return 1 ;
    }
    return 0 ;
}

// --- FIN PUNTO 8 ---


#line 144 "trad3.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "trad3.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_PUTS = 7,                       /* PUTS  */
  YYSYMBOL_PRINTF = 8,                     /* PRINTF  */
  YYSYMBOL_AND = 9,                        /* AND  */
  YYSYMBOL_OR = 10,                        /* OR  */
  YYSYMBOL_EQ = 11,                        /* EQ  */
  YYSYMBOL_NEQ = 12,                       /* NEQ  */
  YYSYMBOL_LEQ = 13,                       /* LEQ  */
  YYSYMBOL_GEQ = 14,                       /* GEQ  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_MAIN = 17,                      /* MAIN  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_INC = 20,                       /* INC  */
  YYSYMBOL_DEC = 21,                       /* DEC  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_SWITCH = 23,                    /* SWITCH  */
  YYSYMBOL_CASE = 24,                      /* CASE  */
  YYSYMBOL_BREAK = 25,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 26,                   /* DEFAULT  */
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_UNARY_SIGN = 35,                /* UNARY_SIGN  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* ','  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* ':'  */
  YYSYMBOL_45_ = 45,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_axioma = 47,                    /* axioma  */
  YYSYMBOL_programa = 48,                  /* programa  */
  YYSYMBOL_lista_declaraciones = 49,       /* lista_declaraciones  */
  YYSYMBOL_declaracion_var = 50,           /* declaracion_var  */
  YYSYMBOL_lista_ids = 51,                 /* lista_ids  */
  YYSYMBOL_id_decl = 52,                   /* id_decl  */
  YYSYMBOL_def_funciones = 53,             /* def_funciones  */
  YYSYMBOL_lista_def_user = 54,            /* lista_def_user  */
  YYSYMBOL_def_funcion = 55,               /* def_funcion  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_params_opt = 57,                /* params_opt  */
  YYSYMBOL_lista_params = 58,              /* lista_params  */
  YYSYMBOL_def_main = 59,                  /* def_main  */
  YYSYMBOL_60_2 = 60,                      /* $@2  */
  YYSYMBOL_cuerpo_funcion = 61,            /* cuerpo_funcion  */
  YYSYMBOL_lista_decl_locales = 62,        /* lista_decl_locales  */
  YYSYMBOL_declaracion_local = 63,         /* declaracion_local  */
  YYSYMBOL_lista_ids_local = 64,           /* lista_ids_local  */
  YYSYMBOL_id_local = 65,                  /* id_local  */
  YYSYMBOL_lista_sentencias = 66,          /* lista_sentencias  */
  YYSYMBOL_sentencia = 67,                 /* sentencia  */
  YYSYMBOL_inc_dec = 68,                   /* inc_dec  */
  YYSYMBOL_lista_casos = 69,               /* lista_casos  */
  YYSYMBOL_caso = 70,                      /* caso  */
  YYSYMBOL_lista_impresiones = 71,         /* lista_impresiones  */
  YYSYMBOL_elem_impresion = 72,            /* elem_impresion  */
  YYSYMBOL_lista_args = 73,                /* lista_args  */
  YYSYMBOL_expresion = 74,                 /* expresion  */
  YYSYMBOL_termino = 75,                   /* termino  */
  YYSYMBOL_operando = 76                   /* operando  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   535

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  212

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,     2,     2,    34,     2,     2,
      40,    41,    32,    30,    37,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    36,
      28,    27,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      25,    26,    35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   118,   118,   121,   125,   126,   130,   131,   141,   144,
     145,   151,   155,   159,   169,   170,   178,   179,   185,   185,
     192,   193,   196,   197,   205,   205,   214,   218,   219,   223,
     224,   231,   235,   236,   242,   247,   252,   264,   265,   271,
     277,   283,   285,   288,   292,   296,   300,   314,   318,   322,
     326,   334,   341,   354,   355,   361,   365,   374,   375,   381,
     383,   387,   388,   394,   395,   397,   399,   401,   403,   405,
     407,   409,   411,   413,   415,   417,   419,   423,   424,   425,
     427,   431,   438,   445,   449,   453,   455
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "PUTS", "PRINTF", "AND", "OR", "EQ", "NEQ", "LEQ",
  "GEQ", "IF", "ELSE", "MAIN", "WHILE", "FOR", "INC", "DEC", "RETURN",
  "SWITCH", "CASE", "BREAK", "DEFAULT", "'='", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "UNARY_SIGN", "';'", "','", "'['", "']'", "'('",
  "')'", "'{'", "'}'", "':'", "'!'", "$accept", "axioma", "programa",
  "lista_declaraciones", "declaracion_var", "lista_ids", "id_decl",
  "def_funciones", "lista_def_user", "def_funcion", "$@1", "params_opt",
  "lista_params", "def_main", "$@2", "cuerpo_funcion",
  "lista_decl_locales", "declaracion_local", "lista_ids_local", "id_local",
  "lista_sentencias", "sentencia", "inc_dec", "lista_casos", "caso",
  "lista_impresiones", "elem_impresion", "lista_args", "expresion",
  "termino", "operando", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,   -56,    -1,   -56,    48,   -56,    19,    18,   -56,    21,
     -56,   -56,    37,    -9,    46,   -56,    38,   -56,    50,   -56,
     -56,   -56,   -56,    85,    88,    97,    -1,    72,   -56,   114,
      81,    84,   -56,    86,   -56,    87,   -56,    89,   121,   -56,
     512,   512,   123,   -23,   124,    96,    98,   103,   106,   112,
      49,   119,   117,   512,   127,   503,   -56,   130,   -56,    49,
      49,     2,    43,   133,   -56,   174,   175,    49,    49,   178,
     -56,   -10,     6,     6,    49,     6,   312,   -56,   -56,    49,
     -56,   147,   503,   -56,   -56,   -56,   321,   269,   148,    55,
     395,   182,   184,   124,   150,   151,   165,   191,   162,    49,
       4,   -56,   -56,   217,   -56,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,   -56,   243,
     -56,   -56,   163,   -56,    49,   171,   -56,   169,   -56,   173,
      10,   168,   170,    49,   281,   -56,    56,   -56,   428,   421,
     450,   450,    41,    41,    41,    41,    74,    74,   -56,   -56,
     -56,   172,    49,   395,   -56,   -56,   -56,   -56,    64,   -56,
     395,   503,   503,   349,   -56,   -56,    93,   358,    10,   177,
      80,   126,    49,   208,   189,    13,   -56,   -56,   -56,   -56,
     199,   -56,   386,   190,   503,   -56,   -56,   176,     1,   503,
     481,   503,   195,   196,   197,   490,   180,   143,   213,   233,
     198,   203,   -56,   -56,   200,   201,   503,   -56,   -56,   -56,
     149,   -56
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,     0,    24,     0,     2,     5,     0,     4,     0,
      16,    14,     0,    11,     8,     9,     0,     1,     0,     3,
       6,    17,    15,    20,     0,     0,     0,     0,     7,     0,
       0,    21,    12,     0,    10,     0,    22,     0,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,    27,    37,     0,    23,     0,
       0,     0,    34,    31,    32,     0,     0,     0,     0,     0,
      85,    81,     0,     0,     0,     0,     0,    63,    77,     0,
      25,     0,    26,    29,    38,    19,     0,     0,     0,     0,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,    79,     0,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
      30,    39,     0,    49,     0,     0,    35,     0,    33,     0,
       0,     0,     0,     0,     0,    83,     0,    86,    68,    69,
      70,    71,    74,    75,    72,    73,    64,    65,    66,    67,
      76,     0,     0,    62,    50,    36,    41,    60,     0,    57,
      59,     0,     0,     0,    82,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    40,    58,    42,
      44,    43,     0,     0,     0,    47,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    45,     0,     0,     0,    55,    51,    52,
       0,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   -56,   -56,   -56,   237,   -56,   218,   253,   -56,   251,
     -56,   -56,   -56,   252,   -56,   221,   -56,   210,   -56,   192,
     -52,   -55,   -56,   -56,    90,   -56,    99,   164,   -48,   -56,
      39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    14,    15,     8,     9,    10,
      12,    30,    31,    11,    16,    52,    53,    54,    63,    64,
      55,    56,   194,   175,   176,   158,   159,    89,    90,    77,
      78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      84,    82,    76,    13,    59,    70,    71,    70,    71,    70,
      71,    86,    87,    70,    71,    60,   157,    61,    24,    96,
      97,   192,   193,     1,     2,     1,   103,    84,    99,    25,
     100,   119,    72,    73,    72,    73,     3,   173,     3,   174,
      72,    73,    74,    88,    74,   135,    74,    75,    17,    75,
      74,   134,    70,    71,    20,    75,   185,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
      91,   113,   114,   115,   116,   117,   153,    23,    27,    72,
      73,    92,   160,    26,    43,   163,    28,    45,    46,    74,
      29,    32,   124,   124,    75,    47,   125,   165,    48,    49,
      33,   168,    50,    51,   167,   169,   115,   116,   117,   170,
     171,   101,   102,    35,   104,    84,    84,   173,    36,   174,
     160,    38,    37,   180,   182,    39,    42,    58,    62,    40,
      43,    41,   190,    45,    46,    84,    65,   195,    66,   197,
      84,    47,    84,    67,    48,    49,    68,    43,    50,    51,
      45,    46,    69,    43,   210,    84,    45,    46,    47,    79,
      80,    48,    49,    83,    47,    50,    51,    48,    49,   181,
      93,    50,    51,    85,   105,   106,   107,   108,   109,   110,
      94,    95,    98,   120,   123,   126,   203,   127,   130,   133,
     152,   129,   211,   111,   112,   113,   114,   115,   116,   117,
     105,   106,   107,   108,   109,   110,   131,   154,   155,   156,
     161,   183,   162,   179,   166,   187,   202,   204,   191,   111,
     112,   113,   114,   115,   116,   117,   105,   106,   107,   108,
     109,   110,   132,   184,   189,   198,   199,   205,   200,   207,
     206,   208,   209,    18,    34,   111,   112,   113,   114,   115,
     116,   117,   105,   106,   107,   108,   109,   110,   137,    19,
      21,    22,    57,    81,   136,   186,     0,   178,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   105,   106,
     107,   108,   109,   110,   151,   128,     0,     0,     0,     0,
     105,   106,   107,   108,   109,   110,     0,   111,   112,   113,
     114,   115,   116,   117,     0,     0,     0,     0,   122,   111,
     112,   113,   114,   115,   116,   117,     0,     0,     0,     0,
     164,   105,   106,   107,   108,   109,   110,     0,     0,     0,
     105,   106,   107,   108,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,     0,   118,   111,
     112,   113,   114,   115,   116,   117,     0,   121,   105,   106,
     107,   108,   109,   110,     0,     0,     0,   105,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,     0,   172,   111,   112,   113,   114,
     115,   116,   117,     0,   177,   105,   106,   107,   108,   109,
     110,     0,     0,     0,   105,   106,   107,   108,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,     0,   188,   111,   112,   113,   114,   115,   116,   117,
     105,     0,   107,   108,   109,   110,     0,     0,     0,   107,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   111,   112,   113,   114,
     115,   116,   117,   109,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,    43,     0,     0,    45,    46,
       0,     0,     0,     0,    43,     0,    47,    45,    46,    48,
      49,     0,     0,    50,    51,    47,   196,    43,    48,    49,
      45,    46,    50,    51,     0,   201,    43,    44,    47,    45,
      46,    48,    49,     0,     0,    50,    51,    47,     0,     0,
      48,    49,     0,     0,    50,    51
};

static const yytype_int16 yycheck[] =
{
      55,    53,    50,     4,    27,     3,     4,     3,     4,     3,
       4,    59,    60,     3,     4,    38,     6,    40,    27,    67,
      68,    20,    21,     4,     5,     4,    74,    82,    38,    38,
      40,    79,    30,    31,    30,    31,    17,    24,    17,    26,
      30,    31,    40,    41,    40,    41,    40,    45,     0,    45,
      40,    99,     3,     4,    36,    45,    43,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      27,    30,    31,    32,    33,    34,   124,    40,    40,    30,
      31,    38,   130,    37,     4,   133,    36,     7,     8,    40,
       5,     3,    37,    37,    45,    15,    41,    41,    18,    19,
       3,    37,    22,    23,   152,    41,    32,    33,    34,   161,
     162,    72,    73,    41,    75,   170,   171,    24,     4,    26,
     168,    37,    41,    43,   172,    39,     5,     4,     4,    42,
       4,    42,   184,     7,     8,   190,    40,   189,    40,   191,
     195,    15,   197,    40,    18,    19,    40,     4,    22,    23,
       7,     8,    40,     4,   206,   210,     7,     8,    15,    40,
      43,    18,    19,    36,    15,    22,    23,    18,    19,    43,
      37,    22,    23,    43,     9,    10,    11,    12,    13,    14,
       6,     6,     4,    36,    36,     3,    43,     3,    37,    27,
      27,    41,    43,    28,    29,    30,    31,    32,    33,    34,
       9,    10,    11,    12,    13,    14,    41,    36,    39,    36,
      42,     3,    42,    36,    42,    16,    36,     4,    42,    28,
      29,    30,    31,    32,    33,    34,     9,    10,    11,    12,
      13,    14,    41,    44,    44,    40,    40,     4,    41,    36,
      42,    41,    41,     6,    26,    28,    29,    30,    31,    32,
      33,    34,     9,    10,    11,    12,    13,    14,    41,     6,
       9,     9,    41,    53,   100,   175,    -1,   168,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,     9,    10,
      11,    12,    13,    14,    41,    93,    -1,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    14,    -1,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      39,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    28,    29,    30,    31,
      32,    33,    34,    -1,    36,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    28,    29,    30,    31,    32,    33,    34,
       9,    -1,    11,    12,    13,    14,    -1,    -1,    -1,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    28,    29,    30,    31,
      32,    33,    34,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,     4,    -1,    -1,     7,     8,
      -1,    -1,    -1,    -1,     4,    -1,    15,     7,     8,    18,
      19,    -1,    -1,    22,    23,    15,    25,     4,    18,    19,
       7,     8,    22,    23,    -1,    25,     4,     5,    15,     7,
       8,    18,    19,    -1,    -1,    22,    23,    15,    -1,    -1,
      18,    19,    -1,    -1,    22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,    17,    47,    48,    49,    50,    53,    54,
      55,    59,    56,     4,    51,    52,    60,     0,    50,    53,
      36,    55,    59,    40,    27,    38,    37,    40,    36,     5,
      57,    58,     3,     3,    52,    41,     4,    41,    37,    39,
      42,    42,     5,     4,     5,     7,     8,    15,    18,    19,
      22,    23,    61,    62,    63,    66,    67,    61,     4,    27,
      38,    40,     4,    64,    65,    40,    40,    40,    40,    40,
       3,     4,    30,    31,    40,    45,    74,    75,    76,    40,
      43,    63,    66,    36,    67,    43,    74,    74,    41,    73,
      74,    27,    38,    37,     6,     6,    74,    74,     4,    38,
      40,    76,    76,    74,    76,     9,    10,    11,    12,    13,
      14,    28,    29,    30,    31,    32,    33,    34,    36,    74,
      36,    36,    39,    36,    37,    41,     3,     3,    65,    41,
      37,    41,    41,    27,    74,    41,    73,    41,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    41,    27,    74,    36,    39,    36,     6,    71,    72,
      74,    42,    42,    74,    39,    41,    42,    74,    37,    41,
      66,    66,    36,    24,    26,    69,    70,    36,    72,    36,
      43,    43,    74,     3,    44,    43,    70,    16,    36,    44,
      66,    42,    20,    21,    68,    66,    25,    66,    40,    40,
      41,    25,    36,    43,     4,     4,    42,    36,    41,    41,
      66,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    49,    49,    50,    51,
      51,    52,    52,    52,    53,    53,    54,    54,    56,    55,
      57,    57,    58,    58,    60,    59,    61,    61,    61,    62,
      62,    63,    64,    64,    65,    65,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    75,
      75,    76,    76,    76,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     3,     2,     1,
       3,     1,     3,     4,     1,     2,     1,     2,     0,     8,
       0,     1,     2,     4,     0,     7,     2,     1,     1,     2,
       3,     2,     1,     3,     1,     3,     4,     1,     2,     4,
       7,     5,     7,     7,     7,    11,    13,     7,     3,     4,
       5,     4,     4,     1,     2,     6,     5,     1,     3,     1,
       1,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     2,     2,
       2,     1,     4,     3,     4,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* axioma: programa  */
#line 118 "trad3.y"
                                             { printf ("%s\n", yyvsp[0].code) ; }
#line 1406 "trad3.tab.c"
    break;

  case 3: /* programa: lista_declaraciones def_funciones  */
#line 121 "trad3.y"
                                                  {
                                           sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1415 "trad3.tab.c"
    break;

  case 4: /* programa: def_funciones  */
#line 125 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1421 "trad3.tab.c"
    break;

  case 5: /* programa: lista_declaraciones  */
#line 126 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1427 "trad3.tab.c"
    break;

  case 6: /* lista_declaraciones: declaracion_var ';'  */
#line 130 "trad3.y"
                                         { yyval.code = yyvsp[-1].code ; }
#line 1433 "trad3.tab.c"
    break;

  case 7: /* lista_declaraciones: lista_declaraciones declaracion_var ';'  */
#line 131 "trad3.y"
                                                        {
                                           sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1442 "trad3.tab.c"
    break;

  case 8: /* declaracion_var: INTEGER lista_ids  */
#line 141 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1448 "trad3.tab.c"
    break;

  case 9: /* lista_ids: id_decl  */
#line 144 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1454 "trad3.tab.c"
    break;

  case 10: /* lista_ids: lista_ids ',' id_decl  */
#line 145 "trad3.y"
                                         {
                                           sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1463 "trad3.tab.c"
    break;

  case 11: /* id_decl: IDENTIF  */
#line 151 "trad3.y"
                                         {
                                           sprintf (temp, "(setq %s 0)", yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1472 "trad3.tab.c"
    break;

  case 12: /* id_decl: IDENTIF '=' NUMBER  */
#line 155 "trad3.y"
                                         {
                                           sprintf (temp, "(setq %s %d)", yyvsp[-2].code, yyvsp[0].value) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1481 "trad3.tab.c"
    break;

  case 13: /* id_decl: IDENTIF '[' NUMBER ']'  */
#line 159 "trad3.y"
                                         {
                                           sprintf (temp, "(setq %s (make-array %d))", yyvsp[-3].code, yyvsp[-1].value) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1490 "trad3.tab.c"
    break;

  case 14: /* def_funciones: def_main  */
#line 169 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1496 "trad3.tab.c"
    break;

  case 15: /* def_funciones: lista_def_user def_main  */
#line 170 "trad3.y"
                                         {
                                           sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1505 "trad3.tab.c"
    break;

  case 16: /* lista_def_user: def_funcion  */
#line 178 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1511 "trad3.tab.c"
    break;

  case 17: /* lista_def_user: lista_def_user def_funcion  */
#line 179 "trad3.y"
                                           {
                                           sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1520 "trad3.tab.c"
    break;

  case 18: /* $@1: %empty  */
#line 185 "trad3.y"
                        { strcpy(current_func, yyvsp[0].code) ; clear_locals() ; }
#line 1526 "trad3.tab.c"
    break;

  case 19: /* def_funcion: IDENTIF $@1 '(' params_opt ')' '{' cuerpo_funcion '}'  */
#line 186 "trad3.y"
                                                          {
                                           sprintf (temp, "(defun %s (%s)\n%s\n)", yyvsp[-7].code, yyvsp[-4].code, yyvsp[-1].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1535 "trad3.tab.c"
    break;

  case 20: /* params_opt: %empty  */
#line 192 "trad3.y"
                                         { yyval.code = gen_code ("") ; }
#line 1541 "trad3.tab.c"
    break;

  case 21: /* params_opt: lista_params  */
#line 193 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1547 "trad3.tab.c"
    break;

  case 22: /* lista_params: INTEGER IDENTIF  */
#line 196 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1553 "trad3.tab.c"
    break;

  case 23: /* lista_params: lista_params ',' INTEGER IDENTIF  */
#line 197 "trad3.y"
                                                 {
                                           sprintf (temp, "%s %s", yyvsp[-3].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1562 "trad3.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 205 "trad3.y"
                     { strcpy(current_func, "main") ; clear_locals() ; }
#line 1568 "trad3.tab.c"
    break;

  case 25: /* def_main: MAIN $@2 '(' ')' '{' cuerpo_funcion '}'  */
#line 206 "trad3.y"
                                               {
                                           sprintf (temp, "(defun main ()\n%s\n)", yyvsp[-1].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1577 "trad3.tab.c"
    break;

  case 26: /* cuerpo_funcion: lista_decl_locales lista_sentencias  */
#line 214 "trad3.y"
                                                    {
                                           sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1586 "trad3.tab.c"
    break;

  case 27: /* cuerpo_funcion: lista_sentencias  */
#line 218 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1592 "trad3.tab.c"
    break;

  case 28: /* cuerpo_funcion: lista_decl_locales  */
#line 219 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1598 "trad3.tab.c"
    break;

  case 29: /* lista_decl_locales: declaracion_local ';'  */
#line 223 "trad3.y"
                                         { yyval.code = yyvsp[-1].code ; }
#line 1604 "trad3.tab.c"
    break;

  case 30: /* lista_decl_locales: lista_decl_locales declaracion_local ';'  */
#line 224 "trad3.y"
                                                         {
                                           sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[-1].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1613 "trad3.tab.c"
    break;

  case 31: /* declaracion_local: INTEGER lista_ids_local  */
#line 231 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1619 "trad3.tab.c"
    break;

  case 32: /* lista_ids_local: id_local  */
#line 235 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1625 "trad3.tab.c"
    break;

  case 33: /* lista_ids_local: lista_ids_local ',' id_local  */
#line 236 "trad3.y"
                                             {
                                           sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1634 "trad3.tab.c"
    break;

  case 34: /* id_local: IDENTIF  */
#line 242 "trad3.y"
                                         {
                                           add_local(yyvsp[0].code) ;
                                           sprintf (temp, "(setq %s_%s 0)", current_func, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1644 "trad3.tab.c"
    break;

  case 35: /* id_local: IDENTIF '=' NUMBER  */
#line 247 "trad3.y"
                                         {
                                           add_local(yyvsp[-2].code) ;
                                           sprintf (temp, "(setq %s_%s %d)", current_func, yyvsp[-2].code, yyvsp[0].value) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1654 "trad3.tab.c"
    break;

  case 36: /* id_local: IDENTIF '[' NUMBER ']'  */
#line 252 "trad3.y"
                                         {
                                           add_local(yyvsp[-3].code) ;
                                           sprintf (temp, "(setq %s_%s (make-array %d))", current_func, yyvsp[-3].code, yyvsp[-1].value) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1664 "trad3.tab.c"
    break;

  case 37: /* lista_sentencias: sentencia  */
#line 264 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1670 "trad3.tab.c"
    break;

  case 38: /* lista_sentencias: lista_sentencias sentencia  */
#line 265 "trad3.y"
                                           {
                                           sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1679 "trad3.tab.c"
    break;

  case 39: /* sentencia: IDENTIF '=' expresion ';'  */
#line 271 "trad3.y"
                                           {
                                             if (is_local(yyvsp[-3].code))
                                                 sprintf (temp, "(setf %s_%s %s)", current_func, yyvsp[-3].code, yyvsp[-1].code) ;
                                             else
                                                 sprintf (temp, "(setf %s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                             yyval.code = gen_code (temp) ; }
#line 1690 "trad3.tab.c"
    break;

  case 40: /* sentencia: IDENTIF '[' expresion ']' '=' expresion ';'  */
#line 277 "trad3.y"
                                                            {
                                             if (is_local(yyvsp[-6].code))
                                                 sprintf (temp, "(setf (aref %s_%s %s) %s)", current_func, yyvsp[-6].code, yyvsp[-4].code, yyvsp[-1].code) ;
                                             else
                                                 sprintf (temp, "(setf (aref %s %s) %s)", yyvsp[-6].code, yyvsp[-4].code, yyvsp[-1].code) ;
                                             yyval.code = gen_code (temp) ; }
#line 1701 "trad3.tab.c"
    break;

  case 41: /* sentencia: PUTS '(' STRING ')' ';'  */
#line 283 "trad3.y"
                                           { sprintf (temp, "(print \"%s\")", yyvsp[-2].code) ;
                                             yyval.code = gen_code (temp) ; }
#line 1708 "trad3.tab.c"
    break;

  case 42: /* sentencia: PRINTF '(' STRING ',' lista_impresiones ')' ';'  */
#line 285 "trad3.y"
                                                                {
                                             sprintf (temp, "%s", yyvsp[-2].code) ;
                                             yyval.code = gen_code (temp) ; }
#line 1716 "trad3.tab.c"
    break;

  case 43: /* sentencia: WHILE '(' expresion ')' '{' lista_sentencias '}'  */
#line 288 "trad3.y"
                                                                 {
                                             sprintf (temp, "(loop while %s do\n%s)", yyvsp[-4].code, yyvsp[-1].code) ;
                                             yyval.code = gen_code (temp) ;
                                         }
#line 1725 "trad3.tab.c"
    break;

  case 44: /* sentencia: IF '(' expresion ')' '{' lista_sentencias '}'  */
#line 292 "trad3.y"
                                                              {
                                             sprintf (temp, "(if %s\n(progn\n%s))", yyvsp[-4].code, yyvsp[-1].code) ;
                                             yyval.code = gen_code (temp) ;
                                         }
#line 1734 "trad3.tab.c"
    break;

  case 45: /* sentencia: IF '(' expresion ')' '{' lista_sentencias '}' ELSE '{' lista_sentencias '}'  */
#line 296 "trad3.y"
                                                                                            {
                                             sprintf (temp, "(if %s\n(progn\n%s)\n(progn\n%s))", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code) ;
                                             yyval.code = gen_code (temp) ;
                                         }
#line 1743 "trad3.tab.c"
    break;

  case 46: /* sentencia: FOR '(' IDENTIF '=' expresion ';' expresion ';' inc_dec ')' '{' lista_sentencias '}'  */
#line 300 "trad3.y"
                                                                                                     {
                                             char *varname ;
                                             char *init_str ;
                                             if (is_local(yyvsp[-10].code)) {
                                                 sprintf (temp, "%s_%s", current_func, yyvsp[-10].code) ;
                                                 varname = gen_code (temp) ;
                                             } else {
                                                 varname = yyvsp[-10].code ;
                                             }
                                             sprintf (temp, "(setf %s %s)", varname, yyvsp[-8].code) ;
                                             init_str = gen_code (temp) ;
                                             sprintf (temp, "%s\n(loop while %s do\n%s\n%s)", init_str, yyvsp[-6].code, yyvsp[-1].code, yyvsp[-4].code) ;
                                             yyval.code = gen_code (temp) ;
                                         }
#line 1762 "trad3.tab.c"
    break;

  case 47: /* sentencia: SWITCH '(' expresion ')' '{' lista_casos '}'  */
#line 314 "trad3.y"
                                                             {
                                             sprintf (temp, "(case %s\n%s\n)", yyvsp[-4].code, yyvsp[-1].code) ;
                                             yyval.code = gen_code (temp) ;
                                         }
#line 1771 "trad3.tab.c"
    break;

  case 48: /* sentencia: RETURN expresion ';'  */
#line 318 "trad3.y"
                                         {
                                             sprintf (temp, "(return-from %s %s)", current_func, yyvsp[-1].code) ;
                                             yyval.code = gen_code (temp) ;
                                         }
#line 1780 "trad3.tab.c"
    break;

  case 49: /* sentencia: IDENTIF '(' ')' ';'  */
#line 322 "trad3.y"
                                        {
                                             sprintf (temp, "(%s)", yyvsp[-3].code) ;
                                             yyval.code = gen_code (temp) ;
                                         }
#line 1789 "trad3.tab.c"
    break;

  case 50: /* sentencia: IDENTIF '(' lista_args ')' ';'  */
#line 326 "trad3.y"
                                               {
                                             sprintf (temp, "(%s %s)", yyvsp[-4].code, yyvsp[-2].code) ;
                                             yyval.code = gen_code (temp) ;
                                         }
#line 1798 "trad3.tab.c"
    break;

  case 51: /* inc_dec: INC '(' IDENTIF ')'  */
#line 334 "trad3.y"
                                    {
                                         if (is_local(yyvsp[-1].code))
                                             sprintf (temp, "(setq %s_%s (+ %s_%s 1))", current_func, yyvsp[-1].code, current_func, yyvsp[-1].code) ;
                                         else
                                             sprintf (temp, "(setq %s (+ %s 1))", yyvsp[-1].code, yyvsp[-1].code) ;
                                         yyval.code = gen_code (temp) ;
                                     }
#line 1810 "trad3.tab.c"
    break;

  case 52: /* inc_dec: DEC '(' IDENTIF ')'  */
#line 341 "trad3.y"
                                    {
                                         if (is_local(yyvsp[-1].code))
                                             sprintf (temp, "(setq %s_%s (- %s_%s 1))", current_func, yyvsp[-1].code, current_func, yyvsp[-1].code) ;
                                         else
                                             sprintf (temp, "(setq %s (- %s 1))", yyvsp[-1].code, yyvsp[-1].code) ;
                                         yyval.code = gen_code (temp) ;
                                     }
#line 1822 "trad3.tab.c"
    break;

  case 53: /* lista_casos: caso  */
#line 354 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1828 "trad3.tab.c"
    break;

  case 54: /* lista_casos: lista_casos caso  */
#line 355 "trad3.y"
                                         {
                                           sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1837 "trad3.tab.c"
    break;

  case 55: /* caso: CASE NUMBER ':' lista_sentencias BREAK ';'  */
#line 361 "trad3.y"
                                                           {
                                           sprintf (temp, "(%d\n%s)", yyvsp[-4].value, yyvsp[-2].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1846 "trad3.tab.c"
    break;

  case 56: /* caso: DEFAULT ':' lista_sentencias BREAK ';'  */
#line 365 "trad3.y"
                                                       {
                                           sprintf (temp, "(otherwise\n%s)", yyvsp[-2].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1855 "trad3.tab.c"
    break;

  case 57: /* lista_impresiones: elem_impresion  */
#line 374 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1861 "trad3.tab.c"
    break;

  case 58: /* lista_impresiones: lista_impresiones ',' elem_impresion  */
#line 375 "trad3.y"
                                                     {
                                           sprintf (temp, "%s\n%s", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1869 "trad3.tab.c"
    break;

  case 59: /* elem_impresion: expresion  */
#line 381 "trad3.y"
                                         { sprintf (temp, "(princ %s)", yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1876 "trad3.tab.c"
    break;

  case 60: /* elem_impresion: STRING  */
#line 383 "trad3.y"
                                         { sprintf (temp, "(princ \"%s\")", yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1883 "trad3.tab.c"
    break;

  case 61: /* lista_args: expresion  */
#line 387 "trad3.y"
                                         { yyval.code = yyvsp[0].code ; }
#line 1889 "trad3.tab.c"
    break;

  case 62: /* lista_args: lista_args ',' expresion  */
#line 388 "trad3.y"
                                         {
                                           sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 1898 "trad3.tab.c"
    break;

  case 63: /* expresion: termino  */
#line 394 "trad3.y"
                                         { yyval = yyvsp[0] ; }
#line 1904 "trad3.tab.c"
    break;

  case 64: /* expresion: expresion '+' expresion  */
#line 395 "trad3.y"
                                         { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1911 "trad3.tab.c"
    break;

  case 65: /* expresion: expresion '-' expresion  */
#line 397 "trad3.y"
                                         { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1918 "trad3.tab.c"
    break;

  case 66: /* expresion: expresion '*' expresion  */
#line 399 "trad3.y"
                                         { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1925 "trad3.tab.c"
    break;

  case 67: /* expresion: expresion '/' expresion  */
#line 401 "trad3.y"
                                         { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1932 "trad3.tab.c"
    break;

  case 68: /* expresion: expresion AND expresion  */
#line 403 "trad3.y"
                                         { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1939 "trad3.tab.c"
    break;

  case 69: /* expresion: expresion OR expresion  */
#line 405 "trad3.y"
                                         { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1946 "trad3.tab.c"
    break;

  case 70: /* expresion: expresion EQ expresion  */
#line 407 "trad3.y"
                                         { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1953 "trad3.tab.c"
    break;

  case 71: /* expresion: expresion NEQ expresion  */
#line 409 "trad3.y"
                                         { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1960 "trad3.tab.c"
    break;

  case 72: /* expresion: expresion '<' expresion  */
#line 411 "trad3.y"
                                         { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1967 "trad3.tab.c"
    break;

  case 73: /* expresion: expresion '>' expresion  */
#line 413 "trad3.y"
                                         { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1974 "trad3.tab.c"
    break;

  case 74: /* expresion: expresion LEQ expresion  */
#line 415 "trad3.y"
                                         { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1981 "trad3.tab.c"
    break;

  case 75: /* expresion: expresion GEQ expresion  */
#line 417 "trad3.y"
                                         { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1988 "trad3.tab.c"
    break;

  case 76: /* expresion: expresion '%' expresion  */
#line 419 "trad3.y"
                                         { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1995 "trad3.tab.c"
    break;

  case 77: /* termino: operando  */
#line 423 "trad3.y"
                                                       { yyval = yyvsp[0] ; }
#line 2001 "trad3.tab.c"
    break;

  case 78: /* termino: '+' operando  */
#line 424 "trad3.y"
                                                       { yyval = yyvsp[0] ; }
#line 2007 "trad3.tab.c"
    break;

  case 79: /* termino: '-' operando  */
#line 425 "trad3.y"
                                                       { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                         yyval.code = gen_code (temp) ; }
#line 2014 "trad3.tab.c"
    break;

  case 80: /* termino: '!' operando  */
#line 427 "trad3.y"
                                                       { sprintf (temp, "(not %s)", yyvsp[0].code) ;
                                                         yyval.code = gen_code (temp) ; }
#line 2021 "trad3.tab.c"
    break;

  case 81: /* operando: IDENTIF  */
#line 431 "trad3.y"
                                         {
                                           if (is_local(yyvsp[0].code))
                                               sprintf (temp, "%s_%s", current_func, yyvsp[0].code) ;
                                           else
                                               sprintf (temp, "%s", yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 2033 "trad3.tab.c"
    break;

  case 82: /* operando: IDENTIF '[' expresion ']'  */
#line 438 "trad3.y"
                                          {
                                           if (is_local(yyvsp[-3].code))
                                               sprintf (temp, "(aref %s_%s %s)", current_func, yyvsp[-3].code, yyvsp[-1].code) ;
                                           else
                                               sprintf (temp, "(aref %s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 2045 "trad3.tab.c"
    break;

  case 83: /* operando: IDENTIF '(' ')'  */
#line 445 "trad3.y"
                                         {
                                           sprintf (temp, "(%s)", yyvsp[-2].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 2054 "trad3.tab.c"
    break;

  case 84: /* operando: IDENTIF '(' lista_args ')'  */
#line 449 "trad3.y"
                                           {
                                           sprintf (temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code) ;
                                           yyval.code = gen_code (temp) ;
                                         }
#line 2063 "trad3.tab.c"
    break;

  case 85: /* operando: NUMBER  */
#line 453 "trad3.y"
                                         { sprintf (temp, "%d", yyvsp[0].value) ;
                                           yyval.code = gen_code (temp) ; }
#line 2070 "trad3.tab.c"
    break;

  case 86: /* operando: '(' expresion ')'  */
#line 455 "trad3.y"
                                         { yyval = yyvsp[-1] ; }
#line 2076 "trad3.tab.c"
    break;


#line 2080 "trad3.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 460 "trad3.y"
                            // SECCION 4  Codigo en C

int n_line = 1 ;

int yyerror (char *mensaje)
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;    // bye
    return 0;
}

char *int_to_string (int n)
{
    char ltemp [2048] ;

    sprintf (ltemp, "%d", n) ;

    return gen_code (ltemp) ;
}

char *char_to_string (char c)
{
    char ltemp [2048] ;

    sprintf (ltemp, "%c", c) ;

    return gen_code (ltemp) ;
}

char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = { // define las palabras reservadas y los
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "puts",        PUTS,
    "printf",      PRINTF,
    "&&",          AND,
    "||",          OR,
    "==",          EQ,
    "!=",          NEQ,
    "<=",          LEQ,
    ">=",          GEQ,
    "while",       WHILE,
    "if",          IF,
    "else",        ELSE,
    "for",         FOR,
    "inc",         INC,
    "dec",         DEC,
    "return",      RETURN,
    "switch",      SWITCH,
    "case",        CASE,
    "break",       BREAK,
    "default",     DEFAULT,
    NULL,          0               // para marcar el fin de la tabla
} ;

t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
        if (strcmp (sim [i].name, symbol_name) == 0) {
                                     // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}


/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;

    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;

    return p ;
}


int yylex ()
{
// NO MODIFICAR ESTA FUNCION SIN PERMISO
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=|>%&/+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') { // Ignora las lineas que empiezan por #  (#define, #include)
            do {        //  OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') { // Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;    // ...
                if (c == '@') { // Si es la secuencia //@  ==> transcribimos la linea
                    do {        // Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {        // ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;

        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }           // habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes variable
            return (IDENTIF) ;
        } else {
            return (symbol->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

    if (c == EOF || c == 255 || c == 26) {
        return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
    return 0;
}
