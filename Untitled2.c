#include<stdio.h>
void main(int argc,char *argv[])
{
	char ch;
	FILE *fp1,*fp2;
	fp1=fopen(argv[2],"r");
	fp2=fopen(argv[1]),"w");
	while((ch=getc(fp1))!=EOF)
	{
		if((int)ch>96&&(int)ch<123)
			putc(ch-32,fp2);
		else
			putc(ch,fp2);
	}
	fclose(fp1);
	fclose(fp2);
}
