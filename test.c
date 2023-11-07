#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "libft/inc/libft.h" 




int aaa(void)
{
	return (5);
}



int retuurn(void)
{
	return (close(4), aaa(), 3);
}

int ft_count_parts(char **parts)
{
    int c = 0;
    while (parts[c])
        c++;
    return (c);
}


	
int main (int ac, char *ag[])
{
	(void)ac;
	char **parts = ft_split(ag[1], ag[2][0]);
	
	


	printf("return: %i  %s\n", ft_count_parts(parts + 2), *(parts + 2));
}

