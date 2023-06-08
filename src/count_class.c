/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** count_class
*/

int count_class(char *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '=')
            j++;
    }
    return j;
}
