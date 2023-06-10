/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** ignore_before_equal
*/

#include <stdlib.h>
#include <string.h>

char *ignore_before_equal(char *str)
{
    char *new_str = NULL;
    int count = 0;
    int i = 0;

    for (i = 0; str[i] != '"'; i++) {
        count++;
    }
    new_str = malloc(sizeof(char) * (strlen(str) - count));
    for (i = 0; str[i] != '\0'; i++) {
        new_str[i - count] = str[i];
    }
    new_str[i - count] = '\0';
    return new_str;
}
