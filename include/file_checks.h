/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:11:31 by ctruchot          #+#    #+#             */
/*   Updated: 2024/04/04 19:43:50 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_CHECKS_H
# define FILE_CHECKS_H

# include "minishell.h"

// checker.c
int	error_checks(t_cmd *cmd, char **mini_env, t_persistent *pers);

// infile_checks.c
int			check_in(t_redirect *in, t_cmd *cmd, t_persistent *pers);
t_redirect	*get_valid_in(t_redirect *in);

// outfile_checks.c
int			check_out(t_redirect *out);
t_redirect	*get_valid_out(t_redirect *out);

// here_doc.c
// int			get_here_doc(char *path);
int	get_here_doc(char *path, t_cmd *cmd, t_persistent *pers);


// cmd_checks.c
int			check_builtins(t_cmd *cmd, int total_cmd);
int			is_directory(t_cmd *cmd);
int			get_cmd_path(t_cmd *cmd, char **env);

// cmd_checks2.c
char		**get_all_paths(char *ptr);
char		*check_paths(char **paths, char *command, t_cmd *cmd);
int			is_valid_path(char *path, char **ptr, char *command);

// utils_checks.c
void		kill_child(t_cmd *cmd, int code);
void		print_str_fd(char *s1, char *s2, char *s3, int fd);
int			ft_cmd_lstsize(t_cmd *lst);
t_redirect	*ft_in_lstlast(t_redirect *lst);
void		ft_in_lstclear(t_redirect *lst);

#endif
