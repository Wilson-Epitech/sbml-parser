/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** remove_duplicate_line
*/

#include "lib.h"
#include "my.h"
#include <stdlib.h>
#include <string.h>

static int get_duplicate_value(int count, char *line, char **new_array, int len)
{
    int is_duplicate = 0;

    for (int j = 0; j < count; j++) {
        if (strncmp(new_array[j], line, len) == 0) {
            is_duplicate = 1;
            break;
        }
    }
    return is_duplicate;
}

static char **is_duplicated(char **array, int i, int count, char **new_array)
{
    int len = strlen(array[i]) + 1;
    new_array[count] = malloc(sizeof(char) * len);
    strcpy(new_array[count], array[i]);
    return new_array;
}

char** remove_duplicates_lines(char** array, int nb_lines)
{
    int count = 0;
    char** new_array = malloc(sizeof(char*) * (nb_lines + 1));
    char* line = NULL;
    int is_duplicate = 0; int len_line = 0;

    for (int i = 0; array[i] != NULL; i++) {
        array[i] = remove_spaces(array[i]);
        line = getclassname(array[i]);
        is_duplicate = 0;
        len_line = strlen(line);
        is_duplicate = get_duplicate_value(count, line, new_array, len_line);
        if (!is_duplicate) {
            is_duplicated(array, i, count, new_array);
            count++;
        }
        free(line);
    }
    new_array[count] = NULL;
    free_array(array);
    return new_array;
}
