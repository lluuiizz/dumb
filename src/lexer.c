#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"



void entryhoho() {
    token *newtoken = (token*) malloc(sizeof(token));

    newtoken->value = "10";
    newtoken->type = NUM;


    printf("The value is: %s\nThe type is %d\n", newtoken->value, newtoken->type);
}
