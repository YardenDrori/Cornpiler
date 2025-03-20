#ifndef PARSER_TYPES_H
#define PARSER_TYPES_H
#include <stdio.h>
#include <stdlib.h>
#include "../../Lexer/H_Files/lexer.h"
#include "../../Lexer/H_Files/token.h"





typedef enum {
    program, //0
    external_declaration_list, //1
    external_declaration, //2
    declaration,  //3
    init_declarator_list,  //4
    init_declarator, //5
    type_specifier, //6
    function_definition, //7
    parameter_list_opt, //8
    parameter_list, //9
    parameter_declaration, //10
    compound_statement, //11
    declaration_list_opt, //12
    declaration_list,//13
    statement_list_opt,//14
    statement_list,//15
    statement,//16
    expression_statement,//17
    selection_statement,//18
    iteration_statement,//19
    expression_opt,//20
    expression,//21
    assignment_expression,//22
    assignment_operator,//23
    conditional_expression,//24
    logical_or_expression,//25
    logical_and_expression,//26
    bitwise_or_expression,//27
    bitwise_xor_expression,//28
    bitwise_and_expression,//29
    equality_expression,//30
    relational_expression,//31
    shift_expression,//32
    additive_expression,//33
    multiplicative_expression,//34
    unary_expression,//35
    unary_operator,//36
    postfix_expression,//37
    argument_expression_list_opt,//38
    argument_expression_list,//39
    primary_expression, //40
    GRAMMER_SYMBOL_COUNT//41
} grammarSymbol;

typedef enum DataType{
    GRAMMER_SYMBOL_DATA_TYPE,
    TOKEN_DATA_TYPE,
    NUMBER_DATA_TYPE
} DataType;

#endif