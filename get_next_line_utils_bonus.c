/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:49:36 by jarumuga          #+#    #+#             */
/*   Updated: 2024/06/19 17:54:08 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* calculates the length of a string
1. if 'src' is NULL -> return '0'
2. while there is a character in the string 'src' we increment the count 'i'
3. we return the count 'i' */
size_t	ft_strlen(const char *src)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

/* searches for the first occurence of character 'c' in string 'src'
1. while there is a character in the string 'src', we go forward in 'src'
	a. if the current character '*src' is equal to the character 'c'
	b. the characters match -> return the current position of the character
2. special case : if the search character 'c' is the end of the string
	a. we return the positin of '*src'
3. in the other case we return 'NULL' */
char	*ft_strchr(const char *src, int c)
{
	while (*src)
	{
		if (*src == (char)c)
			return ((char *)src);
		src++;
	}
	if (c == '\0')
		return ((char *)src);
	return (NULL);
}

/* copies 'n' bytes from 'src' to 'dst'
1. we cast 'dst' and 'src' in unsigned
2. while 'n' is true, we copy 's' into 'd'
3. we return 'dst' */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

/* duplicates a string
1. if 'src' is NULL -> return 'NULL' because nothing to duplicates
2. calculates the length of 'src'
3. allocates memory from 'dst' (the duplicate string)
4. if allocatioon fails -> we return 'NULL'
5. copies 'src' into 'dst' using 'ft_memcpy'
6. sets the last char of 'dst' at '\0'
7. return dst */
char	*ft_strdup(const char *src)
{
	size_t	n;
	char	*dst;

	if (!src)
		return (NULL);
	n = ft_strlen(src);
	dst = malloc(n + 1);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, n);
	dst[n] = '\0';
	return (dst);
}

/* duplicates a string up to 'n' bytes
1. calculates the length of 'src'
2. if length of 'src' is greater than 'n' bytes, it sets len to n
3. allocates memory from 'dst' (the duplicate string)
4. if allocatioon fails -> we return 'NULL'
6. copies 'src' into 'dst' using 'ft_memcpy'
5. sets the last char of 'dst' at '\0'
6. return 'dst' */
char	*ft_strndup(const char *src, size_t n)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(src);
	if (len > n)
		len = n;
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, len);
	dst[len] = '\0';
	return (dst);
}
