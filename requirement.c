/*
** SBML_PARSER PROJECT, 2023
** SBML
** File description:
** word_array_synthesis
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static int count_num_words(char const *str, int i)
{
    while (str[i] && !((str[i] >= 'a' && str[i] <= 'z')
        || (str[i] >= 'A' && str[i] <= 'Z')
        || (str[i] >= '0' && str[i] <= '9'))) {
        i++;
    }
    return i;
}

static int num_words(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i]) {
        if (!((str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= '0' && str[i] <= '9'))) {
            nb++;
            i = count_num_words(str, i);
        } else {
            i++;
        }
    }
    return nb + 1;
}

static int get_len_of_word(char const *str, int i)
{
    int count = 0;

    while (str[i] && ((str[i] >= 'a' && str[i] <= 'z')
        || (str[i] >= 'A' && str[i] <= 'Z')
        || (str[i] >= '0' && str[i] <= '9'))) {
        count++;
        i++;
    }
    return count;
}

static char *split_str(char const *str, int *i)
{
    int y = 0;
    int word_length = get_len_of_word(str, *i);
    char *word = malloc(sizeof(char) * (word_length + 1));

    if (word == NULL)
        return NULL;
    while (str[*i] && ((str[*i] >= 'a' && str[*i] <= 'z')
        || (str[*i] >= 'A' && str[*i] <= 'Z')
        || (str[*i] >= '0' && str[*i] <= '9'))) {
        word[y] = str[*i];
        (*i)++;
        y++;
    }
    word[y] = '\0';
    return word;
}

char **my_str_to_word_array_synthesis(char const *str)
{
    if (str == NULL)
        return NULL;
    int i = 0;
    int x = 0;
    int nb_words = num_words(str);
    char **result = malloc(sizeof(char*) * (nb_words + 1));

    if (result == NULL)
        return NULL;
    while (str[i]) {
        if (!((str[i] >= 'a' && str[i] <= 'z')
    || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))) {
            i++;
        } else {
            result[x] = split_str(str, &i);
            x++;
        }
    }
    result[x] = NULL;
    return result;
}
