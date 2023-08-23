#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * removeExtraSpace - removes extra space
 * @data: shell's data
 */
void handleOpcode(char *str) {
    if (str == NULL) {
        printf("Input string is NULL.\n");
        return;
    }

    int i, j;
    int spaceFound = 0;
    int leadingSpaces = 0;

    // Count leading spaces
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ')
            break;
        leadingSpaces++;
    }

    // Allocate memory for modified string
    char *newStr = (char *)malloc(strlen(str) + 1);

    if (newStr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Loop to remove extra spaces
    for (i = leadingSpaces, j = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (!spaceFound) {
                newStr[j++] = ' ';
                spaceFound = 1;
            }
        } else {
            newStr[j++] = str[i];
            spaceFound = 0;
        }
    }

    // Remove trailing spaces
    if (j > leadingSpaces) {
        while (j > leadingSpaces && newStr[j - 1] == ' ')
            j--;
    }

    // Terminate the modified string
    newStr[j] = '\0';

    // Copy the modified string back to the original location
    strcpy(str, newStr);

    // Free dynamically allocated memory
    free(newStr);
}

int main() {
    char str[] = "            hello         world            ";

    printf("%s\n", str);
    handleOpcode(str);
    printf("%s\n", str);
    return 0;
}
