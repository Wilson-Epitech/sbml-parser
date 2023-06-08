/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** remove
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *remove_spaces(const char *str)
{
    int j = 0;
    int len = strlen(str);
    char *result = malloc(sizeof(char) * (len + 1));
    bool inside_balise = false;
    char current_char = 'a';

    if (result == NULL)
        return NULL;
    for (int i = 0; i < len; i++) {
        current_char = str[i];
        if (current_char == '<')
            inside_balise = true;
        if (inside_balise) {
            result[j] = current_char;
            j++;
        }
    }
    result[j] = '\0';
    return result;
}
