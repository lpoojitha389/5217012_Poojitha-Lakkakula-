#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

char** copy_grid(int r, int c, char** source) {
    char** new_grid = malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        new_grid[i] = malloc((c + 1) * sizeof(char));
        strcpy(new_grid[i], source[i]);
    }
    return new_grid;
}

char** full_bomb_grid(int r, int c) {
    char** grid = malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        grid[i] = malloc((c + 1) * sizeof(char));
        for (int j = 0; j < c; j++) {
            grid[i][j] = 'O';
        }
        grid[i][c] = '\0';
    }
    return grid;
}

char** explode(int r, int c, char** grid) {
    char** result = full_bomb_grid(r, c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'O') {
                result[i][j] = '.';
                if (i > 0) result[i-1][j] = '.';
                if (i < r-1) result[i+1][j] = '.';
                if (j > 0) result[i][j-1] = '.';
                if (j < c-1) result[i][j+1] = '.';
            }
        }
    }

    return result;
}

char** bomberMan(int n, int grid_count, char** grid, int* result_count) {
    *result_count = grid_count;

    if (n == 1) {
        return copy_grid(grid_count, strlen(grid[0]), grid);
    }

    int r = grid_count;
    int c = strlen(grid[0]);

    if (n % 2 == 0) {
        return full_bomb_grid(r, c);
    }

    char** state3 = explode(r, c, grid);
    char** state5 = explode(r, c, state3);

    if (n % 4 == 3) {
        return state3;
    } else {
        return state5;
    }
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int r = parse_int(*(first_multiple_input + 0));

    int c = parse_int(*(first_multiple_input + 1));

    int n = parse_int(*(first_multiple_input + 2));

    char** grid = malloc(r * sizeof(char*));

    for (int i = 0; i < r; i++) {
        char* grid_item = readline();

        *(grid + i) = grid_item;
    }

    int result_count;
    char** result = bomberMan(n, r, grid, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%s", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
