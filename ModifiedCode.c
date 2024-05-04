#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Function to read a line of input
char* readline() {
   size_t alloc_length  = 1024;
   size_t data_length = 0;
   char* data = malloc(alloc_length);
   while(true){
    char* cursor = data + data_length;
    char* line = fgets(cursor, alloc_length-data_length, stdin);

    if(!line){
        break;
    }
    data_length += strlen(cursor);
    if(data_length < alloc_length-1 || data[data_length-1]=='\n'){
        break;
    }
    alloc_length <<= 1;

    data = realloc(data, alloc_length);

    if(!data){
        data = '\0';
        break;
    }
   }
   if(data[data_length-1]== '\n'){
    data[data_length-1] = '\0';
    data = realloc(data, alloc_length);

    if(!data){
        data = '\0';
    }
   }
   else{
        data = realloc(data, alloc_length);

        if(!data){
            data = '\0';
        }
        else{
            data[data_length] = '\0';
        }
   }
   return data;
}

// Function to trim leading whitespace
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

// Function to trim trailing whitespace
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

// Function to parse an integer from a string
int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }
    return value;
}

// Function to calculate the number of distinct shops visited
/*
int* solve(char *s, int u_count, int *u, int v_count, int *v, int *result_count) {
    int *result = (int *)malloc(v_count * sizeof(int));


    for (int i = 0; i < v_count; i++) {
        int visited_shops[26] = {0}; // Initialize an array to keep track of visited shops (assuming 26 shops with unique IDs)
        int start = u[i] - 1; // Adjust for 0-based indexing
        int end = v[i] - 1; // Adjust for 0-based indexing

        // Count visited shops in the substring from u[i] to v[i]
        for (int j = start; j <= end; j++) {
            if (s[j] != 'L' && s[j] != 'R') {
                visited_shops[s[j] - 'a'] = 1;
            }
        }

        // Count the distinct visited shops
        int count = 0;
        for (int j = 0; j < 26; j++) {
            if (visited_shops[j] == 1) {
                count++;
            }
        }

        result[i] = count;
    }

    *result_count = v_count;
    return result;

}
*/

int* solve(char *s, int u_count, int *u, int v_count, int *v, int *result_count) {
    int *result = (int *)malloc(v_count * sizeof(int));

    for (int i = 0; i < v_count; i++) {
        int visited_shops[26] = {0}; // Initialize an array to keep track of visited shops (assuming 26 shops with unique IDs)
        int start = u[i] - 1; // Adjust for 0-based indexing
        int end = v[i] - 1; // Adjust for 0-based indexing

        // Count visited shops in the substring from u[i] to v[i]
        for (int j = start; j <= end; j++) {
            if (s[j] != 'L' && s[j] != 'R') {
                visited_shops[s[j] - 'a'] = 1;
            }
        }

        // Count the distinct visited shops
        int count = 0;
        for (int j = 0; j < 26; j++) {
            if (visited_shops[j] == 1) {
                count++;
            }
        }

        result[i] = count;
    }

    *result_count = v_count;
    return result;
}

int main() {
    char *s = readline();
    int u_count = parse_int(ltrim(rtrim(readline())));
    int *u = malloc(u_count * sizeof(int));

    for (int i = 0; i < u_count; i++) {
        int u_item = parse_int(ltrim(rtrim(readline())));
        *(u + i) = u_item;
    }

    int v_count = parse_int(ltrim(rtrim(readline())));
    int *v = malloc(v_count * sizeof(int));

    for (int i = 0; i < v_count; i++) {
        int v_item = parse_int(ltrim(rtrim(readline())));
        *(v + i) = v_item;
    }

    int result_count;
    int *result = solve(s, u_count, u, v_count, v, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d", *(result + i));

        if (i != result_count - 1) {
            printf("\n");
        }
    }

    return 0;
}





