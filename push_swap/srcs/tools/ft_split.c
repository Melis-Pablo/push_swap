/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:59:12 by pmelis            #+#    #+#             */
/*   Updated: 2023/10/09 19:39:29 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
count_words:	counts the number of words within the given character array str,
				where words are separated by the specified separator character.

Parameters:		char *str
				char separator

Returns:		int count

How it Works:	1. Initialize count int
				2. Initialize inside int (used as boolean)
				3. Set Count to 0
				4. While str still going
					5. Set Inside to 0 (false)
					6. While *str == Separator
						7. str++ (move to next character)
					8. While *str !== separator and still going
						9.If is not inside word
							10. add to Count
							11. set inside to 1 (true)
						12.  str++ (move to next character)
				13. Return Count

*/

static int	count_words(char *str, char separator)
{
	int	count;
	int	inside;

	count = 0;
	while (*str)
	{
		inside = 0;
		while (*str == separator)
			str++;
		while (*str != separator && *str)
		{
			if (!inside)
			{
				count++;
				inside = 1;
			}
			str++;
		}
	}
	return (count);
}

/*
get_word:	Extracts and allocates memory for the next word in str.

Parameters:		char *str
				char separator

Returns:		char *next

How it works:	1. Set static cursor to 0 (static so it remembers the position)
				2. Initialize char *next
				3. Initialize int len
				4. Initialize int i
				5. set len to 0
				6. set i to 0
				7. While str[cursor] == separator
					8. cursor++ (move along str)
				9. While str[cursor + len] != separator and still going
					10. len++
				11. Allocates for word size and end char
				12. Allocation check
					13. return null if failed
				14. While str[cursor] not separator and still going
					15. copy str word into *next
				16. terminate str with \0
				17. Return next
*/

static char	*get_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		cursor++;
	while ((str[cursor + len] != separator) && str[cursor + len])
		len++;
	next = malloc((size_t)len * sizeof(char) + 1);
	if (next == NULL)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next[i++] = str[cursor++];
	next[i] = '\0';
	return (next);
}

/*
ft_split:		splits str into str array of words separated by separator chr

Parameters:		char *str
				char separator

Returns:		char **new_array

How it works:	1. Initialize int word_count
				2. Initialize char **new array
				3. Initialize int i
				4. set i to 0
				5. set word_count to count_words(str, separator)
				6. If no words
					7. Exit
				8. Allocate memory for new_array + Null termination + Fake argv
				9. Allocation check
					10. return null if failed allocation
				11. While word_count -- >= 0
					12. if i == 0 (first word)
						13. Allocate for char 
						14. Allocation check
							15. Return null if allocation fails
						16. New array first word = \0
						17. continue
					18. New_array [i++] = get_word(str, separator)
				19. New array [i] = Null terminating char
				20. Return new_array
*/

char	**ft_split(char *str, char separator)
{
	int		word_count;
	char	**new_array;
	int		i;

	i = 0;
	word_count = count_words(str, separator);
	if (!word_count)
		exit(1);
	new_array = malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (new_array == NULL)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			new_array[i] = malloc(sizeof(char));
			if (new_array[i] == NULL)
				return (NULL);
			new_array[i++][0] = '\0';
			continue ;
		}
		new_array[i++] = get_word(str, separator);
	}
	new_array[i] = NULL;
	return (new_array);
}
