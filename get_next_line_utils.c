#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(char *str, int ch)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len && str[i] != '\0')
	{
		if (str[i] == (char)ch)
			return (str + i);
		i++;
	}
	if (str[i] != (char)ch)
		return (NULL);
	return (str);
}

char	*ft_strdup(char *src)
{
	char	*str;
	size_t	len;
	char	*p;

	len = ft_strlen(src);
	str = (char *)malloc(1 * (len + 1));
	if (!str)
		return (NULL);
	p = str;
	while (*src)
		*(p++) = *(src++);
	*p = '\0';
	return (str);
}

char	*ft_join(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(1 * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
