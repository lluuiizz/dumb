#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void get_file_name (char *file, char **args) {
    for(size_t i = 0; i < strlen(args[1]); ++i) {
        file[i] = args[1][i];
    }
}

bool check_file_format(char *file_name) {
    size_t i = 0;
    for (i; file_name[i] != '.'; ++i);

    char *buff = malloc(4);
    
    for(size_t j = 0; i < strlen(file_name); ++i, ++j) {
        buff[j] = file_name[i];
    }
    
    if (strcmp(buff, ".dumb") == 0) {
        return true;
    }
    return false;
}

int main (int argc, char **argv) {
    if (argc < 2) {
        printf("Please you need to pass an valid .dumb file!\n"); 
        return -1;
    }

    char *file = malloc(sizeof(argv[1]));
    get_file_name(file, argv);

    if (!check_file_format(file)) {
        printf("The format of the file is not '.dumb'\n");
    }
    return 0;

}
