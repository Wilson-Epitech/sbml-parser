/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** ignore_after_equal
*/

#include <stdlib.h>

char *ignore_after_equal(char *str)
{
    char *new_str = NULL;
    int count = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '=') {
            break;
        }
        count++;
    }
    new_str = malloc(sizeof(char) * (count + 1));
    for (i = 0; i < count; i++) {
        new_str[i] = str[i];
    }
    new_str[count] = '\0';
    return new_str;
}
