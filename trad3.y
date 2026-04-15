/*
    Matias Djukic, Roberto Soriano Diez, 223
    100504112@alumnos.uc3m.es, 100522222@alumnos.uc3m.es
*/

%{                          // SECCION 1 Declaraciones de C-Yacc

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

%}

// Definitions for explicit attributes

%token NUMBER
%token IDENTIF       // Identificador=variable
%token INTEGER       // identifica el tipo entero
%token STRING
%token PUTS
%token PRINTF
%token AND           // para &&
%token OR            // para ||
%token EQ            // para ==
%token NEQ           // para !=
%token LEQ           // para <=
%token GEQ           // para >=
%token IF
%token ELSE
%token MAIN          // identifica el comienzo del proc. main
%token WHILE         // identifica el bucle while
%token FOR           // para el bucle for (punto 9)
%token INC           // para INC(x) (punto 9)
%token DEC           // para DEC(x) (punto 9)
%token RETURN        // para return (punto 11)
%token SWITCH        // para switch (punto 10)
%token CASE          // para case (punto 10)
%token BREAK         // para break (punto 10)
%token DEFAULT       // para default (punto 10)

%right '='                    // es la ultima operacion que se debe realizar
%left OR                      // menor orden de precedencia
%left AND
%left EQ NEQ
%left '<' '>' LEQ GEQ
%left '+' '-'
%left '*' '/' '%'
%left UNARY_SIGN              // mayor orden de precedencia

%%                            // Seccion 3 Gramatica - Semantico


axioma:         programa                     { printf ("%s\n", $1.code) ; }
            ;

programa:       lista_declaraciones def_funciones {
                                           sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            |   def_funciones            { $$.code = $1.code ; }
            |   lista_declaraciones      { $$.code = $1.code ; }
            ;

lista_declaraciones:
                declaracion_var ';'      { $$.code = $1.code ; }
            |   lista_declaraciones declaracion_var ';' {
                                           sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;


// --- INICIO PARTE 1: VARIABLES GLOBALES ---

declaracion_var:
                INTEGER lista_ids        { $$.code = $2.code ; }
            ;

lista_ids:      id_decl                  { $$.code = $1.code ; }
            |   lista_ids ',' id_decl    {
                                           sprintf (temp, "%s\n%s", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

id_decl:        IDENTIF                  {
                                           sprintf (temp, "(setq %s 0)", $1.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            |   IDENTIF '=' NUMBER       {
                                           sprintf (temp, "(setq %s %d)", $1.code, $3.value) ;
                                           $$.code = gen_code (temp) ;
                                         }
            |   IDENTIF '[' NUMBER ']'   {
                                           sprintf (temp, "(setq %s (make-array %d))", $1.code, $3.value) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

// --- FIN PARTE 1 ---

// --- INICIO PARTE 2 ---

def_funciones:  def_main                 { $$.code = $1.code ; }
            |   lista_def_user def_main  {
                                           sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

// --- INICIO PUNTO 11: Funciones de usuario ---

lista_def_user: def_funcion              { $$.code = $1.code ; }
            |   lista_def_user def_funcion {
                                           sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

def_funcion:    IDENTIF { strcpy(current_func, $1.code) ; clear_locals() ; }
                '(' params_opt ')' '{' cuerpo_funcion '}' {
                                           sprintf (temp, "(defun %s (%s)\n%s\n)", $1.code, $4.code, $7.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

params_opt:     /* vacio */              { $$.code = gen_code ("") ; }
            |   lista_params             { $$.code = $1.code ; }
            ;

lista_params:   INTEGER IDENTIF          { $$.code = $2.code ; }
            |   lista_params ',' INTEGER IDENTIF {
                                           sprintf (temp, "%s %s", $1.code, $4.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

// --- FIN PUNTO 11 ---

def_main:       MAIN { strcpy(current_func, "main") ; clear_locals() ; }
                '(' ')' '{' cuerpo_funcion '}' {
                                           sprintf (temp, "(defun main ()\n%s\n)", $6.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

// --- INICIO PUNTO 8: Cuerpo de funcion con variables locales ---

cuerpo_funcion: lista_decl_locales lista_sentencias {
                                           sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            |   lista_sentencias         { $$.code = $1.code ; }
            |   lista_decl_locales       { $$.code = $1.code ; }
            ;

lista_decl_locales:
                declaracion_local ';'    { $$.code = $1.code ; }
            |   lista_decl_locales declaracion_local ';' {
                                           sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

declaracion_local:
                INTEGER lista_ids_local  { $$.code = $2.code ; }
            ;

lista_ids_local:
                id_local                 { $$.code = $1.code ; }
            |   lista_ids_local ',' id_local {
                                           sprintf (temp, "%s\n%s", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

id_local:       IDENTIF                  {
                                           add_local($1.code) ;
                                           sprintf (temp, "(setq %s_%s 0)", current_func, $1.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            |   IDENTIF '=' NUMBER       {
                                           add_local($1.code) ;
                                           sprintf (temp, "(setq %s_%s %d)", current_func, $1.code, $3.value) ;
                                           $$.code = gen_code (temp) ;
                                         }
            |   IDENTIF '[' NUMBER ']'   {
                                           add_local($1.code) ;
                                           sprintf (temp, "(setq %s_%s (make-array %d))", current_func, $1.code, $3.value) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

// --- FIN PUNTO 8 ---

// --- FIN PARTE 2 ---

lista_sentencias:
                sentencia                { $$.code = $1.code ; }
            |   lista_sentencias sentencia {
                                           sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

sentencia:      IDENTIF '=' expresion ';'  {
                                             if (is_local($1.code))
                                                 sprintf (temp, "(setf %s_%s %s)", current_func, $1.code, $3.code) ;
                                             else
                                                 sprintf (temp, "(setf %s %s)", $1.code, $3.code) ;
                                             $$.code = gen_code (temp) ; }
            |   IDENTIF '[' expresion ']' '=' expresion ';' {
                                             if (is_local($1.code))
                                                 sprintf (temp, "(setf (aref %s_%s %s) %s)", current_func, $1.code, $3.code, $6.code) ;
                                             else
                                                 sprintf (temp, "(setf (aref %s %s) %s)", $1.code, $3.code, $6.code) ;
                                             $$.code = gen_code (temp) ; }
            |   PUTS '(' STRING ')' ';'    { sprintf (temp, "(print \"%s\")", $3.code) ;
                                             $$.code = gen_code (temp) ; }
            |   PRINTF '(' STRING ',' lista_impresiones ')' ';' {
                                             sprintf (temp, "%s", $5.code) ;
                                             $$.code = gen_code (temp) ; }
            |   WHILE '(' expresion ')' '{' lista_sentencias '}' {
                                             sprintf (temp, "(loop while %s do\n%s)", $3.code, $6.code) ;
                                             $$.code = gen_code (temp) ;
                                         }
            |   IF '(' expresion ')' '{' lista_sentencias '}' {
                                             sprintf (temp, "(if %s\n(progn\n%s))", $3.code, $6.code) ;
                                             $$.code = gen_code (temp) ;
                                         }
            |   IF '(' expresion ')' '{' lista_sentencias '}' ELSE '{' lista_sentencias '}' {
                                             sprintf (temp, "(if %s\n(progn\n%s)\n(progn\n%s))", $3.code, $6.code, $10.code) ;
                                             $$.code = gen_code (temp) ;
                                         }
            |   FOR '(' IDENTIF '=' expresion ';' expresion ';' inc_dec ')' '{' lista_sentencias '}' {
                                             char *varname ;
                                             char *init_str ;
                                             if (is_local($3.code)) {
                                                 sprintf (temp, "%s_%s", current_func, $3.code) ;
                                                 varname = gen_code (temp) ;
                                             } else {
                                                 varname = $3.code ;
                                             }
                                             sprintf (temp, "(setf %s %s)", varname, $5.code) ;
                                             init_str = gen_code (temp) ;
                                             sprintf (temp, "%s\n(loop while %s do\n%s\n%s)", init_str, $7.code, $12.code, $9.code) ;
                                             $$.code = gen_code (temp) ;
                                         }
            |   SWITCH '(' expresion ')' '{' lista_casos '}' {
                                             sprintf (temp, "(case %s\n%s\n)", $3.code, $6.code) ;
                                             $$.code = gen_code (temp) ;
                                         }
            |   RETURN expresion ';'     {
                                             sprintf (temp, "(return-from %s %s)", current_func, $2.code) ;
                                             $$.code = gen_code (temp) ;
                                         }
            |   IDENTIF '(' ')' ';'     {
                                             sprintf (temp, "(%s)", $1.code) ;
                                             $$.code = gen_code (temp) ;
                                         }
            |   IDENTIF '(' lista_args ')' ';' {
                                             sprintf (temp, "(%s %s)", $1.code, $3.code) ;
                                             $$.code = gen_code (temp) ;
                                         }
            ;

// --- INICIO PUNTO 9: Incremento/Decremento para FOR ---

inc_dec:        INC '(' IDENTIF ')' {
                                         if (is_local($3.code))
                                             sprintf (temp, "(setq %s_%s (+ %s_%s 1))", current_func, $3.code, current_func, $3.code) ;
                                         else
                                             sprintf (temp, "(setq %s (+ %s 1))", $3.code, $3.code) ;
                                         $$.code = gen_code (temp) ;
                                     }
            |   DEC '(' IDENTIF ')' {
                                         if (is_local($3.code))
                                             sprintf (temp, "(setq %s_%s (- %s_%s 1))", current_func, $3.code, current_func, $3.code) ;
                                         else
                                             sprintf (temp, "(setq %s (- %s 1))", $3.code, $3.code) ;
                                         $$.code = gen_code (temp) ;
                                     }
            ;

// --- FIN PUNTO 9 ---

// --- INICIO PUNTO 10: Switch/Case ---

lista_casos:    caso                     { $$.code = $1.code ; }
            |   lista_casos caso         {
                                           sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

caso:           CASE NUMBER ':' lista_sentencias BREAK ';' {
                                           sprintf (temp, "(%d\n%s)", $2.value, $4.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            |   DEFAULT ':' lista_sentencias BREAK ';' {
                                           sprintf (temp, "(otherwise\n%s)", $3.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

// --- FIN PUNTO 10 ---

lista_impresiones:
                elem_impresion           { $$.code = $1.code ; }
            |   lista_impresiones ',' elem_impresion {
                                           sprintf (temp, "%s\n%s", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            ;

elem_impresion:
                expresion                { sprintf (temp, "(princ %s)", $1.code) ;
                                           $$.code = gen_code (temp) ; }
            |   STRING                   { sprintf (temp, "(princ \"%s\")", $1.code) ;
                                           $$.code = gen_code (temp) ; }
            ;

lista_args:     expresion                { $$.code = $1.code ; }
            |   lista_args ',' expresion {
                                           sprintf (temp, "%s %s", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            ;

expresion:      termino                  { $$ = $1 ; }
            |   expresion '+' expresion  { sprintf (temp, "(+ %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '-' expresion  { sprintf (temp, "(- %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '*' expresion  { sprintf (temp, "(* %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '/' expresion  { sprintf (temp, "(/ %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion AND expresion  { sprintf (temp, "(and %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion OR expresion   { sprintf (temp, "(or %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion EQ expresion   { sprintf (temp, "(= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion NEQ expresion  { sprintf (temp, "(/= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '<' expresion  { sprintf (temp, "(< %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '>' expresion  { sprintf (temp, "(> %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion LEQ expresion  { sprintf (temp, "(<= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion GEQ expresion  { sprintf (temp, "(>= %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '%' expresion  { sprintf (temp, "(mod %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            ;

termino:        operando                               { $$ = $1 ; }
            |   '+' operando %prec UNARY_SIGN          { $$ = $2 ; }
            |   '-' operando %prec UNARY_SIGN          { sprintf (temp, "(- %s)", $2.code) ;
                                                         $$.code = gen_code (temp) ; }
            |   '!' operando %prec UNARY_SIGN          { sprintf (temp, "(not %s)", $2.code) ;
                                                         $$.code = gen_code (temp) ; }
            ;

operando:       IDENTIF                  {
                                           if (is_local($1.code))
                                               sprintf (temp, "%s_%s", current_func, $1.code) ;
                                           else
                                               sprintf (temp, "%s", $1.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            |   IDENTIF '[' expresion ']' {
                                           if (is_local($1.code))
                                               sprintf (temp, "(aref %s_%s %s)", current_func, $1.code, $3.code) ;
                                           else
                                               sprintf (temp, "(aref %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            |   IDENTIF '(' ')'          {
                                           sprintf (temp, "(%s)", $1.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            |   IDENTIF '(' lista_args ')' {
                                           sprintf (temp, "(%s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ;
                                         }
            |   NUMBER                   { sprintf (temp, "%d", $1.value) ;
                                           $$.code = gen_code (temp) ; }
            |   '(' expresion ')'        { $$ = $2 ; }
            ;



%%                            // SECCION 4  Codigo en C

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