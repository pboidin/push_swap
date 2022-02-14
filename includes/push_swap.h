/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <piboidin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:41:11 by piboidin          #+#    #+#             */
/*   Updated: 2022/02/14 17:28:24 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

# ifndef __LINUX__
#  define OPEN_MAX 256
# endif

typedef struct s_stack_elem
{
	int	value;
}		t_stack_elem;

typedef enum e_bool {
	TRUE = 1,
	FALSE = 0,
}		t_bool;

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}		t_list;

typedef struct s_slist
{
	int		size;
	int		*sorted_values;
	int		*parts_limits;
	t_list	*stack_a;
	t_list	*stack_b;
}		t_slist;

typedef struct s_file
{
	int		s_fd;
	char	*file_path;
	char	*read_line;
	char	*backup;
}		t_file;

typedef enum e_read
{
	read_success = 1,
	read_success_end = 0,
	read_error = -1,
}		t_read;

int				ft_get_first_a(t_slist *list);
int				ft_get_first_b(t_slist *list);
int				ft_get_last_a(t_slist *list);
int				ft_get_stack_value(t_list *stack, int i);
int				ft_get_value_index(t_list *stack, int value);
int				ft_lstsize(t_list *lst);
int				ft_strcmp(char *s1, char *s2);

char			*ft_add_strs(char *s1, char *s2, t_bool free1, t_bool free2);	
char			*ft_strdup(const char *str, t_bool free_str);

char			**ft_split(char const *s, char c);

long long		ft_atoll(char *str);

size_t			ft_get_size(char **argmts);
size_t			ft_putchar_fd(int fd, char c);
size_t			ft_strlen(const char *s);
size_t			ft_putstr_nl(char *str);
ssize_t			ft_find_char(char *str, char c);

t_bool			ft_check(t_slist *list);
t_bool			ft_cont_char(char *str, char c);
t_bool			ft_close_file(t_file *file);

t_file			*ft_open(const char *path, int flags);
t_file			*ft_open_file(const char *path, int flags);

t_list			*ft_lst_create_elem(t_list *data);
t_list			*ft_lstget(t_list *begin_list, int i);

t_read			ft_read_next_line(t_file *file);

t_slist			*ft_lstinit(int len);
t_slist			*ft_struct_list_creator(char **argmts);

t_stack_elem	*ft_create_stack_elem(int value);

void			ft_big_sort(t_slist *list, int part);
void			ft_bzero(void *s, size_t n);
void			ft_destroy_stack_elem(void *stack_elem);
void			ft_display_action(t_slist *list, t_list *stack,
					char *action, t_bool display);
void			ft_fill_sorted_values(t_slist *list, t_list *stack);
void			ft_switcher(t_slist *list, char *cmd);
void			ft_lowest_to_top(t_slist *list, t_list **stack, int lowest);
void			ft_lstadd_back_new(t_list **begin_list, void *data);
void			ft_lstadd_front_new(t_list **begin_list, void *data);
void			ft_lstremove(t_list **begin_list,
					void (*free_fct)(void *), int i);
void			ft_push(t_slist *list, t_list **from,
					t_list **to, t_bool display);
void			ft_puterror(void);
void			ft_putstr(char *str);
void			ft_quick_sort(int array[], int index_start, int index_end);
void			ft_reverse(t_slist *list, t_list **stack, t_bool display);
void			ft_rotate(t_slist *list, t_list **stack, t_bool display);
void			ft_sort(t_slist *list);
void			ft_sort_3(t_slist *list);
void			ft_sort_4(t_slist *list);
void			ft_swap(t_slist *list, t_list *stack, t_bool display);
void			ft_switcher(t_slist *list, char *cmd);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_destroy_splitted(char ***splitted);
void			*ft_list_destroyer(t_slist **list);

#endif
