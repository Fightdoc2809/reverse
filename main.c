#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    FILE *in = stdin;
    int count = 0;
    char liste[1000][255];
    char buffer[400];
    char delimit[] = ",:;\n";
    char *token;

    if (argc > 2) {
        fprintf(stderr, "Usage: %s [<file>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (argc == 2) {
        in = fopen(argv[1], "r");
        if (!in) {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    while (fgets(buffer, 400, in)) {
        token = strtok(buffer, delimit);
        if (!token) {
            break;
        }
        for (int i = 0; i < 255; ++i) {
            liste[count][i] = token[i];
        }
        count++;
    }
    while (count >= 0) {
        printf("%s\n", liste[count]);
        count--;
    }


    if (in != stdin) {
        fclose(in);
    }
    exit(EXIT_SUCCESS);
}