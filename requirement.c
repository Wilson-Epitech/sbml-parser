/*
** SBML_PARSER PROJECT, 2023
** SBML
** File description:
** word_array_synthesis
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static bool is_separator(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9');
}

static int count_words_i(char const *str, int i)
{
    while (!is_separator(str[i])) {
        i++;
    }
    return i;
}

static int get_nb_words(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (!is_separator(str[i])) {
            nb++;
            i = count_words_i(str, i);
        } else {
            i++;
        }
    }
    return nb + 1;
}

static int word_len(char const *str, int i)
{
    int count = 0;

    while (is_separator(str[i]) && str[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

char **my_str_to_word_array_synthesis(char const *str)
{
    int word_length; int nb_words = get_nb_words(str);
    char **result = malloc(sizeof(char*) * (nb_words + 1));
    int i = 0; int x = 0;

    while (str[i] != '\0') {
        if (!is_separator(str[i])) {
            i++;
        } else {
            word_length = word_len(str, i);
            result[x] = malloc(sizeof(char) * (word_length + 1));

            int y = 0;
            while (is_separator(str[i]) && str[i] != '\0') {
                result[x][y] = str[i];
                i++; y++;
            }
            result[x][y] = '\0'; x++;
        }
    }
    result[x] = 0; return result;
}
