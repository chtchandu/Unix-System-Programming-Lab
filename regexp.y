%{
	#include<stdio.h>
	#include<ctype.h>
	#include<string.h>
	#include<stdlib.h>
	
	int getre(const char*);
	signed char prodn[100][100];
	char temp[100],temp2[100];
	int count = 0,i,j;
	
%}

%token alphabet
%left '.'
%left '|'
%nonassoc '+''*'

%%
s:re '\n'
{
	printf("rmd\n");
	
	for(i=count-1;i>=0;i--)
	{
		if(i==count-1)
		{
			printf("\nre=>");
			strcpy(temp,prodn[i]);
			printf("%s",prodn[i]);
		}
		
		else
		{
			printf("\n=>");
			j=getre(temp);
			temp[j]='\0';
			
			sprintf(temp2,"%s%s%s",temp,prodn[i],(temp+j+2));
			printf("%s",temp2);
			strcpy(temp,temp2);
		}
	}
	
	printf("\n");
	exit(0);
}

re:alphabet
{
	temp[1]=yylval;
	temp[2]='\0';
	strcpy(prodn[count++],temp);
}

|re'.'re { strcpy(prodn[count++],"re.re"); }

|re'|'re { strcpy(prodn[count++],"re|re"); }

|re'*' { strcpy(prodn[count++],"re*"); }

|re'+' { strcpy(prodn[count++],"re+"); }

|'('re')' { strcpy(prodn[count++],"(re)"); }

%%

int main()
{
	yyparse();
	return 0;
}

yylex()
{
	const char ch = getchar();
	yylval =  ch;
	
	if(isalpha(ch))
		return alphabet;
	return ch;
}

yyerror()
{
	fprintf(stderr,"invalid re \n");
	exit(0);
}

int getre(const char *str)
{
	int i = strlen(str)-1;
	
	for(;i>=0;i--)
	{
		if(str[i]=='e' && str[i-1]=='r')
			return i-1;
	}
}
