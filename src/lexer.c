#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lexer.h"


static bool is_separator (char ch) {
    if (ch == ' ') {
        return true;
    }
        return false;
}



void tokenizer (char *content) {

    for (size_t i = 0; i < strlen(content); ++i) {
        if (is_separator(content[i]))  {
            printf("Is space\n");
        }
        else {
            printf("Is not space\n");
        }
    
    }

}
