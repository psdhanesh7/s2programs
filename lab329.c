#include<stdio.h>
struct node{
	int num;
	struct node *link;
}*list,*p,*last;
void main()
{
	int n;
	list=NULL;
	printf("Creation of linked list in LIFO \n");
	printf("-------------------------------\n");
	printf("\nEnter the list of numbers(End of the list is indicated by 0):\n");
	while(1)
	{
	
		scanf(" %d",&n);
		if(n)
		{
				p=(struct node *)malloc(sizeof(struct node));
				p->num=n;
				p->link=list;
				list=p;
				
		}
		else
			break;
		
	}
	printf("Created linked list is:\n");
	while(list!=NULL)
	{
		printf("  %d\t",list->num);
		list=list->link;		
	}
	printf("\n\nCreation of linked list in FIFO\n");
	printf("-----------------------------------\n");
	printf("Enter the list of numbers(End of the list is indicated by 0):\n");
	list=NULL;
	last=NULL;
	while(1)
	{
		scanf("%d",&n);
		if(n)
		{
				p=(struct node *)malloc(sizeof(struct node));
				p->num=n;
				p->link=NULL;
				if(list==NULL)
					list=p;
				else
					last->link=p;
				last=p;
		}
		else
			break;
			
	}
	printf("Created linked list is :\n");
	while(list!=NULL)
	{
		printf(" %d\t",list->num);
		list=list->link;
	}
	
	
	
}
