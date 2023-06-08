/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** clean_str
*/

#include <string.h>
#include <stdlib.h>

char *clean_str(char *str, char *list)
{
    int len = strlen(str);
    char *new_str = malloc(sizeof(char) * (len + 1));
    int j = 0;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        k = 0;
        while (list[k] != '\0' && str[i] != list[k]) {
            k++;
        }
        if (list[k] == '\0') {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    return new_str;
}
