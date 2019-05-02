#include<stdio.h>
void main()
{
	FILE *fp;
	char fname[30],pc='\0',ch;
	int wcount,scount;
	printf("Enter the name of the file:");
	scanf(" %[^\n]",fname);
	fp=fopen(fname,"r");
	
	while((ch=getc(fp))!=EOF)
	{
		if(ch=='.'||ch=='\n')
			scount++;
		if((ch==' ' ||ch=='\t' || ch=='\n')&&pc!=' '&&pc!='\t' && pc!='\n')
			wcount++;
		pc=ch;
	}
	if(pc!=' '&&pc!='\t' && pc!='\n')
		wcount++;
	printf("Number of words in the file are %d\n",wcount);
	printf("Number of sentences in the file are %d\n",scount);
	fclose(fp);
	
}
