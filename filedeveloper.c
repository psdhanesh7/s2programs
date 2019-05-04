#include<stdio.h>
void main()
{
	FILE *fp;
	fp=fopen("test.dat","w");
	fprintf(fp,"%4d %-20s %3d %3d %3d %3d %3d %3d\n",1,"Akash",98,78,85,86,84,75);
	fprintf(fp,"%4d %-20s %3d %3d %3d %3d %3d %3d\n",2,"Alan",87,95,69,98,97,99);
	fprintf(fp,"%4d %-20s %3d %3d %3d %3d %3d %3d\n",3,"Akhil",84,86,84,56,78,79);
	fprintf(fp,"%4d %-20s %3d %3d %3d %3d %3d %3d\n",4,"Arun",89,79,84,87,89,85);
	fclose(fp);
}
