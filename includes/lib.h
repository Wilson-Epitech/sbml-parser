/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** lib
*/

#include <stdbool.h>

#ifndef LIB_H_
    #define LIB_H_

    bool is_delim(char c, char *separators);
    char **my_word_array_delim(char const *str, char *separators);
    void free_array(char **array);
    void my_swap_str(char **a, char **b);

#endif /* !LIB_H_ */
