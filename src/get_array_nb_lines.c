/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** get_array_nb_lines
*/

#include <stdlib.h>

int get_nb_lines(char **array)
{
    int i = 0;
    while (array[i] != NULL) {
        i += 1;
    }
    return i;
}
