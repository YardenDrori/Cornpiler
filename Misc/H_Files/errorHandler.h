#include "../../Lexer/H_Files/lexer.h"
#include "../../Lexer/H_Files/token.h"
#include "../H_Files/util.h"
#include "../../Parser/H_Files/stack.h"
#include "../../Parser/H_Files/parser.h"
#include "../../Parser/H_Files/parser_types.h"
#include <stdio.h>
#include <stdarg.h>

void handleLexingError(Token token);
void handleParsingError(struct Parser* parser, int actionParam);