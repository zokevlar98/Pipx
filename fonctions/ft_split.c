/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:42:46 by zqouri            #+#    #+#             */
/*   Updated: 2024/02/20 12:45:03 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	*ft_word(char *s, char c, size_t *idx)
{
	int		i;
	int		word_len;
	char	*tab;

	i = 0;
	word_len = 0;
	while (s[*idx] && s[*idx] == c)
		(*idx)++;
	if (s[*idx])
	{
		i = *idx;
		while (s[*idx] && s[*idx] != c)
		{
			(*idx)++;
			word_len++;
		}
	}
	tab = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!tab)
		return (NULL);
	word_len = 0;
	while (s[i] && s[i] != c)
		tab[word_len++] = s[i++];
	tab[word_len] = '\0';
	return (tab);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		count;
	size_t	idx;
	char	**dest;

	if (!s)
		return (NULL);
	i = 0;
	count = ft_count_word(s, c);
	dest = (char **)malloc(sizeof(char *) * (count + 1));
	if (!dest)
		return (NULL);
	idx = 0;
	while (i < count)
	{
		dest[i] = ft_word(s, c, &idx);
		if (dest[i] == NULL)
			return (ft_free(dest), NULL);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
