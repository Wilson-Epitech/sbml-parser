/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    char *copy_content_file(char *file);
    char *remove_spaces(const char *str);
    int parser_loop(char *buffer);
    int count_class(char *str);
    int get_nb_lines(char **array);
    char *getclassname(char *str);
    char** remove_duplicates_lines(char** array, int nb_lines);

#endif /* !MY_H_ */
