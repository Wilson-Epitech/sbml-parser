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
    int parser_loop(int ac, char **av, char *buffer);
    int count_class(char *str);
    int get_nb_lines(char **array);
    char *getclassname(char *str);
    char** remove_duplicates_lines(char** array, int nb_lines);
    char *replace_spaces_dollars(char* str);
    char *clean_str(char *str, char *list);
    char *ignore_after_equal(char *str);
    int sort_alphabetic_buffer(char *buffer);
    int no_flag_loop(int ac, char *buffer);
    char **sort_alphabetic_str(char **tab);
    char *ignore_before_equal(char *str);
    char *replace_dollars_space(char* str);
    char **keep_important_line(char *str);
    // char **display_name(char **new_array, char *check, char **tmp);
    char **display_name(char **new_array, char *check,
        char **tmp, char *buffer);
    int nothing_loop(char *buffer);

#endif /* !MY_H_ */
