/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** main
*/

#include "my.h"
#include "lib.h"
#include <stdlib.h>

int parser_loop(char *buffer)
{
    char **array = my_word_array_delim(buffer, "\n");

    for (int i = 0; array[i] != NULL; i++) {
        array[i] = remove_spaces(array[i]);
        printf("%s\n", array[i]);
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 5 || ac < 2)
        return 84;
    char *buffer = copy_content_file(av[1]);
    parser_loop(buffer);
    return 0;
}
