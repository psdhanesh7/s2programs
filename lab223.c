#include<stdio.h>
int stringlength(char *s)
{
	int i=0;
	while(*s++!='\0')
		i++;
	return i;
	
}
void stringcopy(char *s1,char *s2)
{
	while(*s1++=*s2++)
		;
	
}
void strconcantination( char *s1,char *s2)
{
	while(*s1)
		s1++;
	while(*s2!='\0')
	{
		*s1=*s2;
		s1++;
		s2++;
		
	}
	*s1='\0';
}
int stringcompare(char *s1,char *s2)
{

	while(*s1!='\0' && *s2!='\0' && *s1==*s2)
	{
		s1++;
		s2++;
	}
	return *s1-*s2;
}
void main()
{
	char s1[30],s2[30],s3[30];
	printf("Enter a string 1:");
	scanf(" %[^\n]",s1);
	printf("Enter string 2:");
	scanf(" %[^\n]",s2);
	printf("Lenght of the string 1 is %d\n",stringlength(s1));
	printf("Length of the string 2 is %d\n",stringlength(s2));
	if(stringcompare(s1,s2)>0)
		printf("String 1 is greater than string 2\n");
	else if(stringcompare(s1,s2)<0)
		printf("String 2 is greater than string 1\n");
	else
		printf("Both string are same\n");
	stringcopy(s3,s1);
	printf("New string with string 1 copied to another value is :\n%s\n",s3);
	strconcantination(s1,s2);
	printf("String 2 appended to string 1 is :\n%s",s1);	
}
