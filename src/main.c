/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac > 5 || ac < 2)
        return 84;
    char *buffer = copy_content_file(av[1]);
    parser_loop(buffer);
    return 0;
}
