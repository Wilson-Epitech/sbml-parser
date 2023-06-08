/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** replace_space_commas
*/

#include <string.h>

char *replace_spaces_dollars(char* str)
{
    int len = strlen(str);
    int inside_quotes = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == '"') {
            inside_quotes = !inside_quotes;
        }
        if (inside_quotes && str[i] == ' ') {
            str[i] = '$';
        }
    }
    return str;
}
