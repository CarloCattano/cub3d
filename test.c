#include <stdio.h>
#include <unistd.h>
       #include <errno.h>

int aaa(void)
{
	return (5);
}



int retuurn(void)
{
	return (close(4), aaa(), 3);
}


	
int main (void)
{

	printf("return: %i \n", retuurn());
	perror("ERROR ");

}

