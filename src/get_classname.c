/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** get_classname
*/

#include <stdlib.h>
#include <unistd.h>

char *getclassname(char *str)
{
    char *newstr = NULL;
    int len = 0;
    int i = 0;
    int j = 0;

    while (str[i] != ' ' && str[i] != '\0') {
        i++;
    }
    len = i;
    newstr = malloc(sizeof(char*) * (len));
    for (int k = 0; str[k] != ' ' && str[k] != '\0'; k++) {
        newstr[j] = str[k];
        j++;
    }
    newstr[len] = '\0';
    return newstr;
}
