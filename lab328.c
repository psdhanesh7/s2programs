#include<stdio.h>
void main()
{
	FILE *fp;
	int rollno,m1,m2,m3,m4,m5,m6,regno,flag=0;
	char name[30];
	fp=fopen("test.dat","r");
	printf("Enter the reigster number of the student:");
	scanf(" %d",&regno);
	while(fscanf(fp,"%3d %20c %3d %3d %3d %3d %3d %3d\n",&rollno,name,&m1,&m2,&m3,&m4,&m5,&m6)!=EOF)
	{
		if(regno==rollno)
		{
			name[29]='\0';
			flag=1;
			printf("Details of the student:\nRegister no.:%d\nName:%s\nMark 1:%d\nMark 2:%d\nMark 3:%d\nMark 4:%d\nMark 5:%d\nMark 6:%d\n",rollno,name,m1,m2,m3,m4,m5,m6);
			break;
		}
		  
	}
	if(flag==0)
		  	printf("Student not found!!!");
	fclose(fp);
}
