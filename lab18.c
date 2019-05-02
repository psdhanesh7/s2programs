
#include<stdio.h>
void readmatrix(int a[][20],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf(" %d",&a[i][j]);
}
void displaymatrix(int a[][20],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d\t",a[i][j]);
		printf("\n");	
	}
}
void add(int a[][20],int b[][20],int c[][20],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			c[i][j]=a[i][j]+b[i][j];
			
}
void product(int a[][20],int b[][20],int c[][20],int r1,int c1,int c2)
{
	int i,j,k,sum;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			sum=0;
			for(k=0;k<c1;k++)
				sum+=a[i][k]*b[k][j];
			c[i][j]=sum;
		}
	}
}
void main()
{
	int a[20][20] ,b[20][20] ,c[20][20] ,m,n,p,q,ch;
	while(1)
	{
		printf("*****MENU******");
		printf("\n1.Matrix addition\n2.Matrix multiplication\n3.Exit\n");
		printf("ENter your choice:");
		scanf(" %d",&ch);
		if(ch==3)
			break;
		if(ch==1||ch==2)
		{
			printf("\nEnter the order of the matrix A:\nNumber of rows:");
			scanf(" %d",&m);
			printf("\nNumber of coloumns:");
			scanf(" %d",&n);
			printf("\nEnter the order of matrix B:\nEnter the number of rows:");
			scanf(" %d",&p);
			printf("\nNumber of coloumns:");
			scanf(" %d",&q);
		}
		switch(ch)
		{
			case 1:if(m!=p||n!=q)
						printf("Order of the matrices are different.Addition not possible!!!\n");
					else
					{
						printf("Enter the elements of the matrix A:\n");
						readmatrix(a,m,n);
						printf("Enter the elements of the matrix B:\n");
						readmatrix(b,p,q);
						add(a,b,c,m,n);
						printf("Sum of the matrices is :");
						displaymatrix(c,m,n);
						printf("\n");
					}
					break;
			case 2:if(n!=p)
						printf("Matrix multiplication not possible!!!!\n");
					else
					{
						printf("Enter the elements of the matrix A:\n");
						readmatrix(a,m,n);
						printf("Enter the elements of the matrix B:\n");
						readmatrix(b,p,q);
						product(a,b,c,m,n,q);
						printf("Product of the matrices is :\n");
						displaymatrix(c,m,q);
						printf("\n");
					}
					break;
			default:printf("Invalid Entry!!!!\n");		
		}
		
	}
}
