#include <cstdlib>
#include <cstdio>

void hack()
{
	printf("Ai fost atacat\n");
	exit(EXIT_SUCCESS);
}

void load()
{
	int v[3];
	v[0]=1;
	v[1]=2;
	v[2]=3;
	v[4]=(int)&hack;
}

int load()
{
	init();
	printf("Toate decurg minunat.\n");
	return 0;
}
