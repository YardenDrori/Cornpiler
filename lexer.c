#include "lexer.h"
#include "token.h"
#include "state.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "ExampleScript.txt"

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//INSTRUCTIONS FOR ADDING NEW TOKENS IN CASE I FORGOR💀
//when adding new token need to add it in token.h
//need to write it's name letter by letter
//need to add final state to array
//need to increase MAX_STATES in lexer.h accordingly
//if path to state includes a special charecter i.e &^% need to add it to reservedSymbols array
//add appropiate print in the util.c
//add exceptions at manual labour section near the start should look like:
//lexer->transition_table[1]['-'] = -1;
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

//self explanetory but for the dummies: 
//initializes values and other stuff for a new lexer struct
Lexer *initLexer(const char *filename){
    printf("Initializing lexer\n");
    char reservedSymbols[] = {"=><!+-=&|*/\\%{}()"};
    char escapeCharecters[] = {"\\\'\"ntrbfv0"};
    Lexer *lexer = (Lexer *)malloc(sizeof(Lexer));
    if (!lexer) {
        fprintf(stderr, "Memory allocation failed for Lexer.\n");
        return NULL;
    }
    lexer->file = fopen(FILENAME, "r");
    if(!lexer->file){
        printf("Error opening specified file %s\n", FILENAME);
        free(lexer);
        return NULL;
    }
    Lexme *lexme = (Lexme *)malloc(sizeof(Lexme));
    lexer->lexme = lexme;
    lexer->lexme->row = 0;
    lexer->lexme->col = -1;
    lexer->lexme->input_len = 0;
    lexer->pos = 0;
    lexer->buffer_length = 0;
    lexer->current_state = 0;
    lexer->token_capacity = INITIAL_TOKEN_CAPACITY;
    lexer->token_id = 0;
    lexer->tokens = (Token *)malloc(sizeof(Token) * lexer->token_capacity);
    if (!lexer->tokens){
        printf("Memory allocation of token array failed");
        fclose(lexer->file);
        free(lexer);
        return NULL;
    }
    printf("memory allocation complete\nfilling state array\n");
    //initialize state array========================
    for (int i = 0; i < MAX_STATES; i++){
        lexer->states[i].is_final = 1;
        lexer->states[i].type = IDENT;
    }
    lexer->states[0].is_final = 0;
    lexer->states[3].is_final = 0;
    lexer->states[5].is_final = 0;
    lexer->states[6].is_final = 0;
    lexer->states[61].is_final = 0;
    lexer->states[63].is_final = 0;

    //lexer->states[0].type = ERROR;
    lexer->states[2].type = INT_LITERAL;
    lexer->states[4].type = FLOAT_LITERAL;
    lexer->states[7].type = CHAR_LITERAL;
    lexer->states[11].type = BOOLEAN;
    lexer->states[15].type = CHAR;
    lexer->states[18].type = INT;
    lexer->states[23].type = FLOAT;
    lexer->states[27].type = TRUE;
    lexer->states[31].type = FALSE;
    lexer->states[33].type = FOR;
    lexer->states[38].type = WHILE;
    lexer->states[39].type = IF;
    lexer->states[43].type = ELSE;
    lexer->states[46].type = THEN; //deprecated
    lexer->states[47].type = EQUAL;
    lexer->states[48].type = IS_EQUAL;
    lexer->states[49].type = GREATER_THAN;
    lexer->states[50].type = EQUAL_GREATER;
    lexer->states[51].type = LESSER_THAN;
    lexer->states[52].type = EQUAL_LESSER;
    lexer->states[53].type = NOT;
    lexer->states[54].type = NOT_EQUAL;
    lexer->states[55].type = PLUS;
    lexer->states[56].type = PLUS_EQUAL;
    lexer->states[57].type = INC;
    lexer->states[58].type = MINUS;
    lexer->states[59].type = MINUS_EQUAL;
    lexer->states[60].type = DEC;
    lexer->states[62].type = AND;
    lexer->states[64].type = OR;
    lexer->states[65].type = MULTIPLY;
    lexer->states[66].type = MULTIPLY_EQUAL;
    lexer->states[67].type = DIVIDE;
    lexer->states[68].type = DIVIDE_EQUAL;
    lexer->states[69].type = MODULU;
    lexer->states[70].type = MODULU_EQUAL;
    lexer->states[71].type = END_OF_FILE;
    lexer->states[73].type = OPEN_PARENTHESIS;
    lexer->states[74].type = CLOSE_PARENTHESIS;
    lexer->states[75].type = OPEN_CURLY_BRACKETS;
    lexer->states[76].type = CLOSE_CURLY_BRACKETS;
    lexer->states[77].type = SKIP;
    lexer->states[72].type = SKIP;
    lexer->states[78].type = NEXT_LINE;
    lexer->states[79].type = ERROR;







    //=============================================
    printf("Completed state array\ninitializing state matrix\n");
    //initiallize state matrix=====================
    for (int i = 0; i < MAX_STATES; i++){
        for (int j = 0; j < 256; j++){
            lexer->transition_table[i][j] = -1;
        }
    }
    for (int i = 0; i < 256; i++){
        lexer->transition_table[0][i] = 79;
    }
    for (int i = 'A'; i <= 'Z'; i++){// A-Z
        lexer->transition_table[0][i] = 1;
        lexer->transition_table[1][i] = 1;
        lexer->transition_table[2][i] = 1;
        lexer->transition_table[3][i] = 1;
        lexer->transition_table[4][i] = 1;
        lexer->transition_table[5][i] = 6;
        lexer->transition_table[79][i] = 79;
        for (int j = 8; j <= 46; j++){
            lexer->transition_table[j][i] = 1;
        }

    }
    for(int i = 'a'; i <= 'z'; i++){ //a-z
        lexer->transition_table[0][i] = 1;
        lexer->transition_table[1][i] = 1;
        lexer->transition_table[2][i] = 1;
        lexer->transition_table[3][i] = 1;
        lexer->transition_table[4][i] = 1;
        lexer->transition_table[5][i] = 6;
        lexer->transition_table[79][i] = 79;
        for (int j = 8; j <= 46; j++){
            lexer->transition_table[j][i] = 1;
        }
    }
    for(int i = '0'; i <= '9'; i++){ //0-9
        lexer->transition_table[0][i] = 2;
        lexer->transition_table[1][i] = 1;
        lexer->transition_table[2][i] = 2;
        lexer->transition_table[3][i] = 4;
        lexer->transition_table[4][i] = 4;
        lexer->transition_table[5][i] = 6;
        lexer->transition_table[79][i] = 79;
        for (int j = 8; j <= 46; j++){
            lexer->transition_table[j][i] = 1;
        }
    }
    //symbols
    for(int i = '!'; i <= '/'; i++){
        if (!isCharInArray(i, reservedSymbols)){
            //lexer->transition_table[0][i] = -1;
            lexer->transition_table[1][i] = 1;
            lexer->transition_table[2][i] = 1;
            lexer->transition_table[3][i] = 1;
            lexer->transition_table[4][i] = 1;
            lexer->transition_table[5][i] = 6;
            lexer->transition_table[79][i] = 79;
            for (int j = 8; j <= 46; j++){
                lexer->transition_table[j][i] = 1;
            }
        }
    }
    for(int i = ':'; i <= '@'; i++){
        if (!isCharInArray(i, reservedSymbols)){
            //lexer->transition_table[0][i] = -1;
            lexer->transition_table[1][i] = 1;
            lexer->transition_table[2][i] = 1;
            lexer->transition_table[3][i] = 1;
            lexer->transition_table[4][i] = 1;
            lexer->transition_table[5][i] = 6;
            lexer->transition_table[79][i] = 79;
            for (int j = 8; j <= 46; j++){
                lexer->transition_table[j][i] = 1;
            }
        }
    }
    for(int i = '['; i <= '`'; i++){
        if (!isCharInArray(i, reservedSymbols)){
            //lexer->transition_table[0][i] = -1;
            lexer->transition_table[1][i] = 1;
            lexer->transition_table[2][i] = 1;
            lexer->transition_table[3][i] = 1;
            lexer->transition_table[4][i] = 1;
            lexer->transition_table[5][i] = 6;
            lexer->transition_table[79][i] = 79;
            for (int j = 8; j <= 46; j++){
                lexer->transition_table[j][i] = 1;
            }
        }
    }
    for(int i = '{'; i <= '~'; i++){
        if(!isCharInArray(i, reservedSymbols)){
            //lexer->transition_table[0][i] = -1;
            lexer->transition_table[1][i] = 1;
            lexer->transition_table[2][i] = 1;
            lexer->transition_table[3][i] = 1;
            lexer->transition_table[4][i] = 1;
            lexer->transition_table[5][i] = 6;
            lexer->transition_table[79][i] = 79;
            for (int j = 8; j <= 46; j++){
                lexer->transition_table[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < 256; i++){
        lexer->transition_table[72][i] = 72;
        lexer->transition_table[77][i] = -1;
        lexer->transition_table[80][i] = 79;
    }


    //manual labor starts here :(
    lexer->transition_table[0]['.'] = 3;
    lexer->transition_table[0][' '] = 77;
    lexer->transition_table[0]['\n'] = 78;
    lexer->transition_table[1]['+'] = -1;
    lexer->transition_table[1]['-'] = -1;
    lexer->transition_table[1]['*'] = -1;
    lexer->transition_table[1]['/'] = -1;
    lexer->transition_table[1]['='] = -1;
    lexer->transition_table[1]['&'] = -1;
    lexer->transition_table[1]['|'] = -1;
    lexer->transition_table[1]['>'] = -1;
    lexer->transition_table[1]['<'] = -1;
    lexer->transition_table[1]['!'] = -1;
    lexer->transition_table[1]['%'] = -1;
    lexer->transition_table[1]['('] = -1;
    lexer->transition_table[1][')'] = -1;
    lexer->transition_table[1]['{'] = -1;
    lexer->transition_table[1]['}'] = -1;
    lexer->transition_table[2]['.'] = 3;
    lexer->transition_table[0]['\''] = 5;
    lexer->transition_table[5]['\\'] = 80;
    lexer->transition_table[80]['\\'] = 6;
    lexer->transition_table[80]['\''] = 6;
    lexer->transition_table[80]['\"'] = 6;
    lexer->transition_table[80]['n'] = 6;
    lexer->transition_table[80]['t'] = 6;
    lexer->transition_table[80]['r'] = 6;
    lexer->transition_table[80]['b'] = 6;
    lexer->transition_table[80]['f'] = 6;
    lexer->transition_table[80]['v'] = 6;
    lexer->transition_table[80]['0'] = 6;

    lexer->transition_table[6]['\''] = 7;
    lexer->transition_table[0]['b'] = 8;
    lexer->transition_table[8]['o'] = 9;
    lexer->transition_table[9]['o'] = 10;
    lexer->transition_table[10]['l'] = 11;
    lexer->transition_table[0]['c'] = 12;
    lexer->transition_table[12]['h'] = 13;
    lexer->transition_table[13]['a'] = 14;
    lexer->transition_table[14]['r'] = 15;
    lexer->transition_table[0]['t'] = 24;
    //lexer->transition_table[24]['h'] = 44; DEPRECATED
    //lexer->transition_table[44]['e'] = 45; DEPRECATED
    //lexer->transition_table[45]['n'] = 46; DEPRECATED
    lexer->transition_table[24]['r'] = 25;
    lexer->transition_table[25]['u'] = 26;
    lexer->transition_table[26]['e'] = 27;
    lexer->transition_table[0]['i'] = 16;
    lexer->transition_table[16]['f'] = 39;
    lexer->transition_table[16]['n'] = 17;
    lexer->transition_table[17]['t'] = 18;
    lexer->transition_table[0]['e'] = 40;
    lexer->transition_table[40]['l'] = 41;
    lexer->transition_table[41]['s'] = 42;
    lexer->transition_table[42]['e'] = 43;
    lexer->transition_table[0]['f'] = 19;
    lexer->transition_table[19]['a'] = 28;
    lexer->transition_table[28]['l'] = 29;
    lexer->transition_table[29]['s'] = 30;
    lexer->transition_table[30]['e'] = 31;
    lexer->transition_table[19]['l'] = 20;
    lexer->transition_table[20]['o'] = 21;
    lexer->transition_table[21]['a'] = 22;
    lexer->transition_table[22]['t'] = 23;
    lexer->transition_table[19]['o'] = 32;
    lexer->transition_table[32]['r'] = 33;
    lexer->transition_table[0]['w'] = 34;
    lexer->transition_table[34]['h'] = 35;
    lexer->transition_table[35]['i'] = 36;
    lexer->transition_table[36]['l'] = 37;
    lexer->transition_table[37]['e'] = 38;
    lexer->transition_table[0]['='] = 47;
    lexer->transition_table[47]['='] = 48;
    lexer->transition_table[0]['>'] = 49;
    lexer->transition_table[49]['='] = 50;
    lexer->transition_table[0]['<'] = 51;
    lexer->transition_table[51]['='] = 52;
    lexer->transition_table[0]['!'] = 53;
    lexer->transition_table[53]['='] = 54;
    lexer->transition_table[0]['+'] = 55;
    lexer->transition_table[55]['='] = 56;
    lexer->transition_table[55]['+'] = 57;
    lexer->transition_table[0]['-'] = 58;
    lexer->transition_table[58]['='] = 59;
    lexer->transition_table[58]['-'] = 60;
    lexer->transition_table[0]['&'] = 61;
    lexer->transition_table[61]['&'] = 62;
    lexer->transition_table[0]['|'] = 63;
    lexer->transition_table[63]['|'] = 64;
    lexer->transition_table[0]['*'] = 65;
    lexer->transition_table[65]['='] = 66;
    lexer->transition_table[0]['/'] = 67;
    lexer->transition_table[67]['/'] = 72;
    lexer->transition_table[67]['='] = 68;
    lexer->transition_table[0]['%'] = 69;
    lexer->transition_table[69]['='] = 70;
    lexer->transition_table[0]['\0'] = 71;
    lexer->transition_table[72]['\n'] = -1;
    lexer->transition_table[72]['\0'] = 71;
    lexer->transition_table[0]['('] = 73;
    lexer->transition_table[0][')'] = 74;
    lexer->transition_table[0]['{'] = 75;
    lexer->transition_table[0]['}'] = 76;

//=================================================
    loadBuffer(lexer);
    printf("lexer initialized succesfully\n");
    return lexer;
}

//loads the buffer from the input file
void loadBuffer(Lexer *lexer){
    //printf("Loading the buffer: ");
    size_t bytes_read = fread(lexer->buffer, 1, BUFFER_SIZE, lexer->file);
    lexer->buffer_length = (int)bytes_read;
    //printf("%d",lexer->buffer_length);
    lexer->pos = 0;
    if(bytes_read < BUFFER_SIZE){
        lexer->buffer[bytes_read] = '\0';
    }
    if (bytes_read == 0 && feof(lexer->file)){
        return;
    }
    if (bytes_read == 0 && ferror(lexer->file)){
        perror("Failed to read file");
        lexer->buffer_length = 0;
    }
    //printf("buffer loaded successfully!\n");
}

//reads a charecter from the buffer and reloads it if reached it's end
char nextChar(Lexer *lexer){ // c=1
    
    if (lexer->pos >= lexer->buffer_length-1){
        loadBuffer(lexer);
        lexer->pos = 0;
    }else{
        lexer->pos++;
    }
    return lexer->buffer[lexer->pos];
}

//returns next read token from the buffer
Token nextToken(Lexer *lexer){
    //making function pointer array
    void (*tokenValueAssignerArray[TOTAL_TOKENS])(Token *, Lexme *) = {0};
    tokenValueAssignerArray[INT_LITERAL] = handle_int_literal;
    tokenValueAssignerArray[FLOAT_LITERAL] = handle_float_literal;
    tokenValueAssignerArray[CHAR_LITERAL] = handle_char_literal;
    tokenValueAssignerArray[IDENT] = handle_ident;
    tokenValueAssignerArray[TRUE]= handle_true;
    tokenValueAssignerArray[FALSE] = handle_false;
    tokenValueAssignerArray[NEXT_LINE] = handle_next_line;
    tokenValueAssignerArray[ERROR] = handle_error;


    
    Token returnToken; //the token we return currently empty
    int currentInputSize = 4; //self explanetory
    lexer->lexme->input = malloc(sizeof(char) * currentInputSize); // the actuall input incase it is literal
    if (!lexer->lexme->input){
        printf("Error initializing array input");
    }
    lexer->lexme->input_len = 0; //remembers the size of the current input incase the array isn't big enough, somehow
    char currentChar = lexer->buffer[lexer->pos];// the current charecter read from the buffer
    int lastState = 0; //the previous state read so that when the automaton finishes we can remember what it was on
    lexer->current_state = 0; // reset current state from last operation

    lexer->current_state = lexer->transition_table[lexer->current_state][currentChar];
    while (lexer->current_state != -1){
        lexer->lexme->col++;
        lexer->lexme->input[lexer->lexme->input_len] = currentChar;
        lexer->lexme->input_len++;
        lastState = lexer->current_state;
        currentChar = nextChar(lexer);
        if (lexer->lexme->input_len >= currentInputSize-1){
            currentInputSize *= 2;
            lexer->lexme->input = realloc(lexer->lexme->input, currentInputSize * sizeof(char));
            if (!lexer->lexme->input){
                printf("Error reallocating memory for input");
            }
        }
        lexer->current_state = lexer->transition_table[lexer->current_state][currentChar];
    }
    returnToken.type = lexer->states[lastState].type;

    if (tokenValueAssignerArray[returnToken.type] != 0){
        tokenValueAssignerArray[returnToken.type](&returnToken, lexer->lexme);
    }
    return returnToken;
}

//frees all the memory in the lexer struct
void freeLexer(Lexer *lexer){
    if (lexer == NULL){
        return;
    }
    if (lexer->tokens != NULL){
        free(lexer->tokens);
    }
    if (lexer->file != NULL){
        fclose(lexer->file);
    }
    free(lexer);
}

//fills the lexer's tokens array with the appropiate tokens
void getTokenList(Lexer *lexer){
    lexer->lexme->row = 1;
    lexer->lexme->col = -1;
    lexer->token_id = 0;
    Token token = nextToken(lexer);
    if (token.type != SKIP && token.type != NEXT_LINE){
        lexer->tokens[lexer->token_id] = token;
    }
    while (token.type != END_OF_FILE){
        //increase array size if full
        if (lexer->token_id >= lexer->token_capacity-1){
            lexer->token_capacity += 32;
            lexer->tokens = realloc(lexer->tokens, lexer->token_capacity * sizeof(Token));
            if (!lexer->tokens){
                printf("error reallocating the tokens array");
                return;
            }
        }
        
        //insert token to array
        token = nextToken(lexer);
        if (token.type !=SKIP && token.type != NEXT_LINE){
            lexer->token_id++;
            lexer->tokens[lexer->token_id] = token;
        }
    }

    //decrease token array size to fit perfectly
    if (lexer->token_capacity-1 > lexer->token_id){
        lexer->token_capacity = lexer->token_id+1;
        lexer->tokens = realloc(lexer->tokens, lexer->token_capacity * sizeof(Token));
        if (!lexer->tokens){
            printf("error reallocating the tokens array");
            return;
        }
    }
}
