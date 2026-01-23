/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:43:15 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/23 13:25:40 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Data Strucutures
typedef struct s_dict_pair
{
	char				*key;
	char				*value;
	struct s_dict_pair	*next;
}						t_dict_pair;

typedef struct s_dict
{
	t_dict_pair			*head;
	int					size;
}						t_dict;

// Argument parsing (parsing.c)
void					parse_args(int ac, char **av, char **path, char **nbr);
int						validate_nbr(char *nbr);

// File reading (read_utils.c)
char					*read_dict(char *path);

// String utilities (string_utils.c)
size_t					ft_strlen(const char *s);
int						ft_atoi(const char *nptr);
char					*ft_strchr(const char *s, int c);
void					*ft_memcpy(void *dest, const void *src, size_t n);
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_strdup(const char *s);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_isdigit(int i);
char					**ft_split(char const *s, char c);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
void					*ft_calloc(size_t nbe, size_t size);
char					*ft_itoa(int n);
size_t					ft_strlcpy(char *dst, const char *src, size_t siz);
void					ft_putstr_fd(char *s, int fd);
char					*ft_strjoin(char const *s1, char const *s2);

// String utilities 2 (string_utils2.c)
int						is_all_digits(char *str);
unsigned long			str_to_ulong(char *str);
char					*join_with_space(char *s1, char *s2);
char					*append_part(char *result, char *new_part);

// Line utilities (line_foos.c)
int						is_empty_line(char *line);
void					free_lines(char **lines);

// Dictionary utilities (dict_foos.c)
t_dict					*create_empty_dictionary(void);
t_dict_pair				*create_entry(char *key, char *value);
void					add_entry(t_dict *dict, t_dict_pair *entry);
int						key_exists(t_dict *dict, char *key);
void					free_dictionary(t_dict *dict);

// Dictionary parsing (dict_pars.c)
void					free_entry(t_dict_pair *entry);
t_dict_pair				*parse_dictionary_line(char *line);
t_dict					*parse_dictionary_content(char *content);

// Number conversion (algo.c)
char					*lookup_value(t_dict *dict, char *key);
char					*find_largest_key_below(t_dict *dict, char *number);
char					*convert_number(char *number, t_dict *dict);
char					*number_to_words(char *number_str, t_dict *dict);

// Additional string utility
int						ft_strcmp(const char *s1, const char *s2);

// Algo utils
char					*process_remainder(char *number, char *scale,
							t_dict *dict, char *result);
char					*process_large_scale(char *number, char *scale,
							t_dict *dict, char *result);
char					*get_zero_value(t_dict *dict);

// String comparison (string_compare.c)
int						compare_number_strings(char *n1, char *n2);
int						is_power_of_ten(char *str);
char					*trim_leading_zeros(char *str);
int						is_valid_scale(char *str);

// String math (string_math.c)
char					*divide_by_power_of_10(char *number, char *divisor);
char					*modulo_by_power_of_10(char *number, char *divisor);
char					*subtract_strings(char *n1, char *n2);

#endif
