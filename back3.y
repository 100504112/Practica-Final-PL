/*
    Matias Djukic, Roberto Soriano Diez, 223
    100504112@alumnos.uc3m.es, 100522222@alumnos.uc3m.es
*/

%{                          // SECTION 1 Declarations for C-Bison
#include <stdio.h>
#include <ctype.h>            // tolower()
#include <string.h>           // strcmp()
#include <stdlib.h>           // exit()

#define FF fflush(stdout);    // to force immediate printing

int yylex () ;
void yyerror (char *) ;
char *my_malloc (int) ;

char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;

char temp [2048] ;

typedef struct s_attr {
    int value ;
    char *code ;
} t_attr ;

#define YYSTYPE t_attr

%}

%token NUMBER
%token IDENTIF
%token STRING
%token MAIN
%token WHILE
%token LOOP
%token DO
%token SETQ
%token SETF
%token DEFUN
%token PRINT
%token PRINC
%token AND
%token OR
%token NOT
%token NEQ
%token LEQ
%token GEQ
%token MOD
%token IF
%token PROGN


%%

axiom:        exprSeq                           { ; }
            ;

exprSeq:      expression1
                 r_exprSeq                      { ; }
            ;

r_exprSeq:    exprSeq                           { ; }
            | /* lambda */                      { ; }
            ;

expression1:  expression                        { ; }

            // --- INICIO PUNTO 1: VARIABLES GLOBALES ---
            // (setq a 0) -> "variable a"
            // (setq a 5) -> "variable a  5 a !"
            | '(' SETQ IDENTIF NUMBER ')'       {
                printf("variable %s ", $3.code) ;
                if ($4.value != 0)
                    printf(" %d %s ! ", $4.value, $3.code) ;
                printf("\n") ;
              }
            // --- FIN PUNTO 1 ---

            // --- INICIO PUNTO 5: ASIGNACION ---
            // (setf a expr) -> "expr a !"
            | '(' SETF IDENTIF expression ')'   {
                printf(" %s ! ", $3.code) ;
              }
            // --- FIN PUNTO 5 ---

            // --- INICIO PUNTO 3: IMPRESION DE CADENAS ---
            // (print "Hola") -> .\" Hola\" cr
            | '(' PRINT STRING ')'              {
                printf(" .\" %s\" cr ", $3.code) ;
              }
            // --- FIN PUNTO 3 ---

            // --- INICIO PUNTO 4: IMPRESION DE VALORES ENTEROS ---
            // (princ expr)   -> "expr ."
            // (princ "str")  -> ".\" str\""
            | '(' PRINC expression ')'          {
                printf(" . ") ;
              }

            | '(' PRINC STRING ')'              {
                printf(" .\" %s\" ", $3.code) ;
              }
            // --- FIN PUNTO 4 ---

            | '(' PROGN exprSeq ')'             { ; }

            // --- INICIO PUNTO 2: FUNCIONES GENERICAS ---
            // Llamada a main: (main) -> "main"
            | '(' MAIN ')'                      { printf(" main\n") ; }

            // Definicion de main: (defun main () ...) -> ": main ... ;"
            | '(' DEFUN MAIN                    { printf(": main ") ; }
                '(' ')' exprSeq ')'             { printf(" ; \n") ; }
            // --- FIN PUNTO 2 ---

            // --- INICIO PUNTO 6: BUCLES WHILE ---
            // (loop while cond do body) -> "begin cond while body repeat"
            | '(' LOOP WHILE                    { printf(" begin ") ; }
                 expression                     { printf(" while ") ; }
                 DO exprSeq ')'                 { printf(" repeat ") ; }
            // --- FIN PUNTO 6 ---

            // --- INICIO PUNTO 7: ESTRUCTURA IF/ELSE ---
            // (if cond then)      -> "cond IF then THEN"
            // (if cond then else) -> "cond IF then ELSE else THEN"
            | '(' ifHead expression1 ')'        { printf(" THEN ") ; }

            | '(' ifHead expression1            { printf(" ELSE ") ; }
                 expression1 ')'               { printf(" THEN ") ; }
            // --- FIN PUNTO 7 ---
            ;


ifHead:       IF expression                     { printf(" IF ") ; }
            ;


// --- INICIO PUNTO 8: OPERADORES ARITMETICOS ---
expression:   operand                                       { ; }

            // Operadores aritmeticos
            | '(' '+' expression expression ')'             { printf(" + ") ; }
            | '(' '-' expression expression ')'             { printf(" - ") ; }
            | '(' '*' expression expression ')'             { printf(" * ") ; }
            | '(' '/' expression expression ')'             { printf(" / ") ; }
            | '(' MOD expression expression ')'             { printf(" mod ") ; }

            // Operadores logicos: not -> "0=" (no existe en Forth como tal)
            | '(' AND expression expression ')'             { printf(" and ") ; }
            | '(' OR  expression expression ')'             { printf(" or ") ; }
            | '(' NOT expression ')'                        { printf(" 0= ") ; }

            // Operadores relacionales: /= -> "= 0=" (negacion de igualdad)
            | '(' '=' expression expression ')'             { printf(" = ") ; }
            | '(' NEQ expression expression ')'             { printf(" = 0= ") ; }
            | '(' '<' expression expression ')'             { printf(" < ") ; }
            | '(' LEQ expression expression ')'             { printf(" <= ") ; }
            | '(' '>' expression expression ')'             { printf(" > ") ; }
            | '(' GEQ expression expression ')'             { printf(" >= ") ; }

            // Negacion unaria
            | '(' '-' expression ')'                        { printf(" negate ") ; }
            ;
// --- FIN PUNTO 8 ---


operand:      IDENTIF                           { printf(" %s @ ", $1.code) ; }
            | number                            { ; }
            ;

number:       NUMBER                            { printf(" %d ", $1.value) ; }
            ;


%%                            // SECTION 4    Code in C

int n_line = 1 ;

void yyerror (char *message)
{
    fprintf (stderr, "%s in line %d\n", message, n_line) ;
    printf ("\n") ;
}

char *int_to_string (int n)
{
    char temp [1024] ;
    sprintf (temp, "%d", n) ;
    return gen_code (temp) ;
}

char *char_to_string (char c)
{
    char temp [1024] ;
    sprintf (temp, "%c", c) ;
    return gen_code (temp) ;
}

char *gen_code (char *name)
{
    char *p ;
    int l ;
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
    return p ;
}

char *my_malloc (int nbytes)
{
    char *p ;
    static long int nb = 0 ;
    static int nv = 0 ;

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No memory left for additional %d bytes\n", nbytes) ;
        fprintf (stderr, "%ld bytes reserved in %d calls \n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/***************************** Keyword Section *****************************/
/***************************************************************************/

typedef struct s_keyword {
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = {
    "main",        MAIN,
    "defun",       DEFUN,
    "print",       PRINT,
    "princ",       PRINC,
    "loop",        LOOP,
    "while",       WHILE,
    "do",          DO,
    "setq",        SETQ,
    "setf",        SETF,
    "and",         AND,
    "or",          OR,
    "not",         NOT,
    "/=",          NEQ,
    "<=",          LEQ,
    ">=",          GEQ,
    "mod",         MOD,
    "if",          IF,
    "progn",       PROGN,
    NULL,          0
} ;

t_keyword *search_keyword (char *symbol_name)
{
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
        if (strcmp (sim [i].name, symbol_name) == 0) {
            return &(sim [i]) ;
        }
        i++ ;
    }
    return NULL ;
}


/***************************************************************************/
/******************** Section for the Lexical Analyzer  ********************/
/***************************************************************************/

int yylex ()
{
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char expandable_ops [] =  "!<>=|%&/-*+" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;
        if (c == '#') {
            do {
                c = getchar () ;
            } while (c != '\n') ;
        }
        if (c == '/') {
            cc = getchar () ;
            if (cc != '/') {
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;
                if (c == '@') {
                    do {
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n' && c != EOF) ;
                    if (c == EOF) {
                        ungetc (c, stdin) ;
                    }
                } else {
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        }
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
            printf ("WARNING: string with more than 255 characters in line %d\n", n_line) ;
        }
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
        if (symbol == NULL) {
            return (IDENTIF) ;
        } else {
            return (symbol->token) ;
        }
    }

    if (strchr (expandable_ops, c) != NULL) {
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ;
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
}