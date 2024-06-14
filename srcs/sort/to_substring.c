/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cimy <cimy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:54:14 by cimy              #+#    #+#             */
/*   Updated: 2024/06/14 11:40:31 by cimy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/node.h"

int	count_double_ptr(char **argv)
{
	int	count;

	count = 0;
	while (argv[count] != NULL)
		count++;
	return (count);
}

int	count_dwords(char  **s, char c)
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
	substring = malloc(sizeof(char *) * (count_dwords(argv, ' ') + 1));
	// printf("to num: %d\n", count_dwords(argv, ' ') + 1);
	joined = malloc(sizeof(char *) * (count_double_ptr(argv) + 1));
	// printf("to null: %d\n", (count_double_ptr(argv) + 1));
	while (argv[i] != NULL)
	{
		j = 0;
		substring = ft_split(argv[i], ' ');
		while (substring[j] != NULL)
		{
			joined[indx] = substring[j];
			j++;
			indx++;
		}
		i++;
	}
	joined[indx] = NULL;
	return (joined);
}
