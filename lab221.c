#include<stdio.h>
#include<string.h>
#define max 100
int palindrome(char string[])
{
	int len=strlen(string),i;
	for(i=0;i<len;i++)
		if(tolower(string[i])!=tolower(string[len-i-1]))
			return 0;
	return 1;
}
int vcount(char string[])
{
	int count=0,i;
	for(i=0;string[i]!='\0';i++)
		if(tolower(string[i])=='a'||tolower(string[i])=='e'||tolower(string[i])=='i'||tolower(string[i])=='o'||tolower(string[i])=='u')
			count++;
	return count;
	
}
int ncount(char string[])
{
	int count=0,i;
	for(i=0;string[i]!='\0';i++)
		if(string[i]<='9'&&string[i]>='0')
			count++;
	return count;
}
int search(char string[],char substring[],int index[])
{
	int i,j,k=0,stringlen=strlen(string),sublen=strlen(substring);
	for(i=0;i<=stringlen-sublen;i++)
	{
		for(j=0;j<sublen;j++)
			if(string[j+i]==substring[j])
				continue;
			else
				break;
		if(j==sublen)
			index[k++]=i;
			
	}
	return k; 
}
void replace(char string[],int sublen,char rsub[],char rstring[],int index[],int ilen)
{
	int i,j=0,k,l=0,stringlen;
	stringlen=strlen(string);
	for(i=0;string[i]!='\0';)
	{
		if(i==index[l]&&l<ilen)
		{
			for(k=0;rsub[k]!='\0';k++)
				rstring[j+k]=rsub[k];
			i+=sublen;
			j+=k;
			l++;
		}
		else
			rstring[j++]=string[i++];
	}
	rstring[j]='\0';
}
void main()
{
	char string[max],substring[max],rsub[max],rstring[max];
	int index[max],ilen,i;
	printf("Enter a string:");
	scanf(" %[^\n]",string);
	printf("Number of vowels in the string are :\t%d",vcount(string));
	printf("\nNumber of digits in the string are:\t%d",ncount(string));
	printf("\nEnter the substring to be searched:");
	scanf(" %[^\n]",substring);
	ilen=search(string,substring,index);
	if(ilen)
	{
		for(i=0;i<ilen;i++)
			printf("\nSubsring is found at index %d",index[i]);
	}
	else
	{
		printf("\nSubstring not found!!");
		goto label;
	}
	printf("\nEnter the string to be replaced:");
	scanf(" %[^\n]",rsub);
	replace(string,strlen(substring),rsub,rstring,index,ilen);
	printf("\nNew string with %s replaced by %s is :\n%s",substring,rsub,rstring);
	label:;
	
}

