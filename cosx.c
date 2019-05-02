#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
	float x,s=1,term,r;
	int i;
	printf("Enter the angle in degrees:");
	scanf(" %f",&x);
	r=x*M_PI/180;
	term=(-1)*r*r/2;
	printf("%f",term);
	while (fabsf(term)>0.0000001)
	{
		printf("\n%f",term);
		s+=term;
		term=-term*r*r/((2*i+2)*(2*i+1));
		i++;
	}
	printf("\n%f\n",term);
	printf("Cos(x)=%f",s);
}
