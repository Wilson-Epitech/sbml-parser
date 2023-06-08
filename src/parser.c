/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** parser
*/

#include "lib.h"
#include "my.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

static int no_flag_loop(char *buffer)
{
    char **array = my_word_array_delim(buffer, "\n");
    int nb = 0;
    int nb_lines = get_nb_lines(array);

    array = remove_duplicates_lines(array, nb_lines);
    for (int i = 0; array[i] != NULL; i++) {
        array[i] = remove_spaces(array[i]);
        nb = count_class(array[i]);
        if (nb != 0) {
            printf("%s\n", array[i]);
        }
    }
    return 0;
}

int parser_loop(char *buffer)
{
    no_flag_loop(buffer);
    return 0;
}
