/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:43:15 by salsoysa          #+#    #+#             */
/*   Updated: 2026/03/24 00:00:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dict_pair
{
	char				*key;
	char				*value;
	struct s_dict_pair	*next;
}						t_dict_pair;

typedef struct s_dict
{
	t_dict_pair			*head;
}						t_dict;

void					parse_args(int ac, char **av, char **path, char **nbr);

char					*read_dict(char *path);

size_t					ft_strlen(const char *s);
char					*ft_strchr(const char *s, int c);
void					*ft_memcpy(void *dest, const void *src, size_t n);
char					*ft_strdup(const char *s);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s1, char const *set);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_isdigit(int i);
int						is_all_digits(char *str);
char					*append_with_space(char *result, char *new_part);
char					*trim_leading_zeros(char *str);

char					**ft_split(char const *s, char c);
int						fill_words(char **newstr, char *str, char c, int len);
void					free_split(char **split);

int						is_empty_line(char *line);
void					free_lines(char **lines);

t_dict					*create_empty_dictionary(void);
t_dict_pair				*create_entry(char *key, char *value);
void					add_entry(t_dict *dict, t_dict_pair *entry);
int						key_exists(t_dict *dict, char *key);
void					free_dictionary(t_dict *dict);

void					free_entry(t_dict_pair *entry);
t_dict_pair				*parse_dictionary_line(char *line);
t_dict					*parse_dictionary_content(char *content);

char					*lookup_value(t_dict *dict, char *key);
int						is_zero_value(char *str);
char					*dict_zero_value(t_dict *dict);
char					*consume_zero_input(char *trimmed, t_dict *dict);
char					*convert_group(char *group, t_dict *dict);
char					**split_into_groups(char *nbr);
int						count_split_groups(char **groups);
char					*process_groups(char **groups, int num_groups, t_dict *dict);
int						check_scale_limit(char **groups, t_dict *dict);
char					*get_scale_name(int scale_index, t_dict *dict);
char					*number_to_words(char *number_str, t_dict *dict);

#endif
