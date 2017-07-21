#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stmt[3][50],input[100];
int l1=101,l2=102,l3=103;
int len,cur,i,j;

void gen()
{
	printf("if %s then %d :\n",stmt[0],l1);
	printf("goto: %d\n",l2);
	printf("%d:%s\n",l1,stmt[0]);
	
	if(cur<3)
	{
		printf("%d:stop\n",l2);
	}
	else
	{
		printf("goto: %d\n",l3);
		printf("%d:%s\n",l2,stmt[1]);
		printf("%d:stop \n",l3);
	}
}

int main()
{
	printf("enter the statement: \n");
	gets(input);
	
	len = strlen(input);
	int index = 0;
	
	for(i=0;i<len && input[i]!=';';i++)
	{
		if(input[i]=='(')
		{
			index=0;
			for(j=i;input[j]!='(';j++)
			{
				stmt[cur][index++]=input[j];
			}
			cur++;
			i=j;
		}
	}
	gen();
	return 0;
}
	
