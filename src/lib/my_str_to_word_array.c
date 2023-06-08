/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** my_str_to_word_array_test
*/

#include "lib.h"
#include <stdbool.h>
#include "stdlib.h"

static int count_i_nb_words(char const *str, int i)
{
    while (is_word_separator(str[i])) {
        i++;
    }
    return i;
}

static int get_nb_words(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (is_word_separator(str[i])) {
            nb++;
            i = count_i_nb_words(str, i);
        } else {
            i++;
        }
    }
    return nb + 1;
}

static int get_word_length(char const *str, int i)
{
    int count = 0;

    while (!is_word_separator(str[i]) && str[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

static char *parse_word(char const *str, int *i)
{
    int y = 0;
    int word_length = get_word_length(str, *i);
    char *word = malloc(sizeof(char) * (word_length + 1));

    if (word == NULL)
        return NULL;
    while (!is_word_separator(str[*i]) && str[*i] != '\0') {
        word[y] = str[*i];
        (*i)++;
        y++;
    }
    word[y] = '\0';
    return word;
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int x = 0;
    int nb_words = get_nb_words(str);
    char **result = malloc(sizeof(char*) * (nb_words + 1));

    if (result == NULL)
        return NULL;
    while (str[i] != '\0') {
        if (is_word_separator(str[i])) {
            i++;
        } else {
            result[x] = parse_word(str, &i);
            x++;
        }
    }
    result[x] = NULL;
    return result;
}
