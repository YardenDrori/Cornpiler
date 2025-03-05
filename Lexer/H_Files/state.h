#ifndef STATE_H
#define STATE_H

#include "token.h"
#include <stdio.h>


typedef struct {
    int is_final;
    TokenType type;
} State;


#endif