#ifndef PARSER_H
#define PARSER_H
#include <stdlib.h>

typedef enum {
    Expr,
    Term,
    Factor
} grammarSymbol;

/* FOR NOW ONLY THESE WILL BE USED
Expr -> Expr + Term
Expr -> Expr - Term
Expr -> Term
Term -> Term * Factor
Term -> Term / Factor
Term -> Factor
Factor -> ( Expr )
Factor -> id
Factor -> intlit
Factor -> id inc
Factor -> id dec
Factor -> dec id
Factor -> inc id
*/


#endif