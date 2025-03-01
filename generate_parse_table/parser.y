%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

/* Token Definitions */
%token PLUS MINUS MULTIPLY DIVIDE OPEN_PARENTHESIS CLOSE_PARENTHESIS IDENT INT_LITERAL INC DEC

%left PLUS MINUS
%left MULTIPLY DIVIDE
%right INC DEC

/* Grammar Rules */
%%
PROGRAM  : Start ;
Start    : Expr ;
Expr     : Expr PLUS Term
         | Expr MINUS Term
         | Term ;
Term     : Term MULTIPLY Factor
         | Term DIVIDE Factor
         | Factor ;
Factor   : OPEN_PARENTHESIS Expr CLOSE_PARENTHESIS
         | IDENT
         | INT_LITERAL
         | IDENT INC
         | IDENT DEC
         | DEC IDENT
         | INC IDENT ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}