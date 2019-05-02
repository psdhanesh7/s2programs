#include<stdio.h>
#define max 70
struct student{
	int regno;
	char name[max];
	int m1,m2,m3,m4,total;
}s[max];
void main()
{
	int i,n,j;
	struct student temp;
	printf("Enter the number of students:");
	scanf(" %d",&n);
	printf("Enter the details of the students");
	printf("\n---------------------------------");
	for(i=0;i<n;i++)
	{
		printf("\nStudent %d",i+1);
		printf("\nRegister number:");
		scanf(" %d",&s[i].regno);
		printf("Name:");
		scanf(" %[^\n]",&s[i].name);
		printf("Mark 1:");
		scanf(" %d",&s[i].m1);
		printf("Mark 2:");
		scanf(" %d",&s[i].m2);
		printf("Mark 3:");
		scanf(" %d",&s[i].m3);
		printf("Mark 4:");
		scanf(" %d",&s[i].m4);
		s[i].total=s[i].m1+s[i].m2+s[i].m3+s[i].m4;
		
		
	}
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(s[i].total<s[i+1].total)
			{
				temp=s[i];
				s[i]=s[i+1];
				s[i+1]=temp;
			}
			
	printf("\n\nDetails of students\n");
	printf("-------------------\n");
	for(i=0;i<n;i++)
	{
		printf("Student %d:\n",i+1);
		printf("Register No.:%d\nName:%s\nMark 1:%d\nMark 2:%d\nMark 3:%d\nMark 4:%d\nTotal:%d\n",s[i].regno,s[i].name,s[i].m1,s[i].m2,s[i].m3,s[i].m4,s[i].total);
	}
}
