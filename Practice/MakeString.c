#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}


char* primeIndexDigits(char s[]) {
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int j = 0;

    for (int i = 1; i <= len; i++) {
        if (isPrime(i)) {
            result[j++] = s[i - 1];
        }
    }

    result[j] = '\0';
    return result;
}

int main() {
    char s[100];
    printf("Enter the string: ");
    scanf("%s", s);

    char* result = primeIndexDigits(s);
    printf("Result: %s\n", result);

    free(result); // Free the dynamically allocated memory
    return 0;
}
