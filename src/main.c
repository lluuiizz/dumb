#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "lexer.h"

void get_file_name (char *file, char **args); 
bool check_file_format(char *file_name);
size_t get_file_size(FILE* file);
void get_string(char *str_to, FILE* content_from);

int main (int argc, char **argv) {
    if (argc < 2) {
        printf("Please you need to pass an valid .dumb file!\n"); 
        return -1;
    }

    char *file = malloc(sizeof(argv[1]));
    get_file_name(file, argv);

    if (!check_file_format(file)) {
        printf("The format of the file is not '.dumb'\n");
        return -1;
    }

    FILE* content = fopen(file, "r");

    if (content == NULL) {
        printf("Some error ocurred while reading the file!\n");
        return -1;
    }

    size_t file_size = get_file_size(content);

    char *content_string = malloc(sizeof(char) * file_size);

    get_string(content_string, content);
    fclose(content);

    printf("%s", content_string);
    return 0;
}

void get_file_name (char *file, char **args) {
    for(size_t i = 0; i < strlen(args[1]); ++i) {
        file[i] = args[1][i];
    }
}

bool check_file_format(char *file_name) {
    size_t per = 0;
    for (size_t i = 0; i < strlen(file_name); ++i) {
        if (file_name[i] == '.') {
            per = i;
        }
    }

    char *buff = malloc(6);
    
    for(size_t j = 0; per < strlen(file_name); ++per, ++j) {
        buff[j] = file_name[per];
    }
    
    if (strcmp(buff, ".dumb") == 0) {
        return true;
    }
    return false;
}

size_t get_file_size(FILE* file) {
    size_t i = 0;

    for (i; fgetc(file) != EOF; i++);
    fseek(file, 0, SEEK_SET);
    return i;
}

void get_string(char *str_to, FILE* content_from) {
    for (size_t i = 0; !feof(content_from); str_to[i] = fgetc(content_from), ++i);
}
