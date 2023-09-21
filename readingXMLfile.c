/*#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s myFile.xml\n", argv[0]);
        return 1;
    }

    const char *xmlFilePath = argv[1];
    FILE *xmlFile = fopen(xmlFilePath, "r");
    if (xmlFile == NULL) {
        perror("Failed to open XML file");
        return 1;
    }

    char line[1024];
    int insideStudent = 0;

    while (fgets(line, sizeof(line), xmlFile) != NULL) {
        if (strstr(line, "<student>") != NULL) {
            insideStudent = 1;
            printf("Node Name: student\n");
        } else if (strstr(line, "</student>") != NULL) {
            insideStudent = 0;
            printf("\n");
        } else if (insideStudent) {
            char *startTag = strchr(line, '<');
            char *endTag = strchr(line, '>');
            if (startTag != NULL && endTag != NULL && startTag < endTag) {
                printf("%.*s\n", (int)(endTag - startTag - 1), startTag + 1);
            }
        }
    }

    fclose(xmlFile);

    return 0;
}
*/



#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trimWhitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) {
        str++;
    }

    if (*str == 0) {  // All spaces?
        return;
    }

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    // Write new null terminator character
    *(end + 1) = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path_to_xml_file>\n", argv[0]);
        return 1;
    }

    const char *xmlFilePath = argv[1];
    FILE *xmlFile = fopen(xmlFilePath, "r");
    if (xmlFile == NULL) {
        perror("Failed to open XML file");
        return 1;
    }

    char line[1024];
    int insideStudent = 0;
    int insideTag = 0;

    while (fgets(line, sizeof(line), xmlFile) != NULL) {
        trimWhitespace(line);

        if (strstr(line, "<student>") != NULL) {
            insideStudent = 1;
            printf("Node Name: student\n");
        } else if (strstr(line, "</student>") != NULL) {
            insideStudent = 0;
            insideTag = 0;
            printf("\n");
        } else if (insideStudent) {
            char *startTag = strchr(line, '<');
            char *endTag = strchr(line, '>');
            if (startTag != NULL && endTag != NULL && startTag < endTag) {
                *endTag = '\0';
                printf("%s: %s\n", startTag + 1, endTag + 1);
            }
        }
    }

    fclose(xmlFile);

    return 0;
}


/*Install libxml2 Library:

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trimWhitespace(char *str) {
    char *end;

    // Trim leading space
    while (*str && isspace((unsigned char)*str)) {
        str++;
    }

    if (*str == 0) {  // All spaces?
        return;
    }

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    // Write new null terminator character
    *(end + 1) = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path_to_xml_file>\n", argv[0]);
        return 1;
    }

    const char *xmlFilePath = argv[1];
    FILE *xmlFile = fopen(xmlFilePath, "r");
    if (xmlFile == NULL) {
        perror("Failed to open XML file");
        return 1;
    }

    char line[1024];
    int insideStudent = 0;

    while (fgets(line, sizeof(line), xmlFile) != NULL) {
        trimWhitespace(line);

        if (strstr(line, "<student>") != NULL) {
            insideStudent = 1;
            printf("Node Name: student\n");
        } else if (strstr(line, "</student>") != NULL) {
            insideStudent = 0;
            printf("\n");
        } else if (insideStudent) {
            char *startTag = strchr(line, '>');
            char *endTag = strchr(line, '<');
            if (startTag != NULL && endTag != NULL && startTag < endTag) {
                printf("%.*s\n", (int)(endTag - startTag - 1), startTag + 1);
            }
        }
    }

    fclose(xmlFile);

    return 0;
}
*/