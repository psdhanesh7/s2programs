#include<stdio.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
	int i;
	float sum=0;
	for(i=1;i<argc;i++)
		sum+=*argv[i];
	sum/=argc-1;
	printf("Average = %d",sum);
}
