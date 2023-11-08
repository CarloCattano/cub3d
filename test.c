#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "libft/inc/libft.h" 


char    **cub_splits(char const *str, char const *set);

typedef struct  s_load
{
        char *wall[4];
        int *floor;
        int *ceiling;
        t_list *map;
        t_list *extra;
} t_load;

void lprint(void *value)
{	
	printf( "value: %i\n", *(int *)value);
}
int ltest(t_load *t1)
{
	t_list *nnode;
	int *c;
	
	c = malloc(sizeof(int));
	
	*c = 0;
	while ((*c)++ < 10)
	{ 
		nnode = ft_lstnew(c);
		if (!nnode)
			return (1);
		lprint(nnode->content);
		ft_lstadd_back(&(t1->extra), nnode);
	}
	*c -=2;
	return (0);
}	



	
int main (void)
{
	t_load t1;
	ft_bzero(&t1, sizeof(t_load));	
	if (ltest(&t1))
		printf("%s\n", "ERROR");
	else 
	{
		printf("OUT \n");
		ft_lstiter(t1.extra, lprint);
	}	

}

