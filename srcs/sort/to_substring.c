/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:54:14 by cimy              #+#    #+#             */
/*   Updated: 2024/06/16 14:47:41 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

int	count_num_arr(char **s, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != NULL)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] != c && (s[i][j + 1] == '\0' || s[i][j + 1] == c))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	**ft_double_strjoin(char **argv)
{
	int		i;
	int		j;
	int		indx;
	char	**substring;
	char	**joined;

	i = 0;
	indx = 0;
	joined = malloc(sizeof(char *) * (count_num_arr(argv, ' ') + 1));
	if (!joined)
		return (NULL);
	while (argv[i] != NULL)
	{
		j = 0;
		substring = ft_split(argv[i], ' ');
		while (substring[j] != NULL)
		{
			joined[indx++] = free_dup(substring[j++]);
		}
		if (substring != NULL)
			free(substring);
		i++;
	}
	joined[indx] = NULL;
	return (joined);
}

char	*free_dup(char *str)
{
	char	*dup_str;

	dup_str = ft_strdup(str);
	if (str != NULL)
		free(str);
	return (dup_str);
}
