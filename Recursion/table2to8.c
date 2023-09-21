#include <stdio.h>

void printTable(int num, int multiplier) {
    if (multiplier > 10) {
        // Base case: Stop recursion when multiplier exceeds 10
        return;
    }

    printf("%d x %d = %d\n", num, multiplier, num * multiplier);

    // Recursive call to print the next row of the table
    printTable(num, multiplier + 1);
}

void printTables(int num) {
    if (num > 8) {
        // Base case: Stop recursion when num exceeds 8
        return;
    }

    printf("Multiplication Table for %d:\n", num);
    printTable(num, 1); // Start printing from multiplier 1

    printf("\n"); // Add a separator between tables

    // Recursive call to print the table for the next number
    printTables(num + 1);
}

int main() {
    printTables(2); // Start with the multiplication table for 2

    return 0;
}
