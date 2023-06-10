/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** parser
*/

#include "my.h"
#include "lib.h"
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int flag_i_loop(char *buffer, char **av)
{
    char *check = av[3];
    char **array = my_word_array_delim(buffer, "\n");
    char **new_array = NULL;
    char **tmp = NULL;
    int nb = 0;

    for (int i = 0; array[i] != NULL; i++) {
        array[i] = remove_spaces(array[i]);
        array[i] = replace_spaces_dollars(array[i]);
        array[i] = clean_str(array[i], "<>?");
        nb = count_class(array[i]);
        if (nb != 0) {
            new_array = keep_important_line(array[i]);
        }
    }
    new_array = sort_alphabetic_str(new_array);
    display_name(new_array, check, tmp);
    return 0;
}

int parser_loop(int ac, char **av, char *buffer)
{
    struct stat sb;
    if (stat(av[1], &sb) != 0 || !S_ISREG(sb.st_mode)) {
        printf("Error: %s is not a valid file\n", av[1]);
        return 84;
    }
    if (ac == 2)
        no_flag_loop(ac, buffer);
    if (ac == 4 && av[2][0] == '-' && av[2][1] == 'i') {
        flag_i_loop(buffer, av);
    }
    if ((ac == 4 || ac == 5) && av[2][0] == '-' && av[2][1] != 'i') {
        return 84;
    }
    if (ac == 3 && av[2][0] == '-' && av[2][1] != 'i') {
        return 84;
    }
    return 0;
}
