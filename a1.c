#include<string.h>
#include<stdio.h>

int main()
{	
	char a[10]="Hello<a";
	if(strstr(a,"Hello")!=NULL)
	{
		printf("If");
	}
	else
	{
		printf("Else");
	}
	return 0;
}
