%{
	int positiveint = 0;
	int negativeint = 0;
	int positivereal = 0;
	int negativereal = 0;
	int mt42 = 0;
%}

%%
[-][0-9]*\.[0-9]+	{ negativereal++; }
[+]*[0-9]*\.[0-9]+	{ positivereal++; if( atof(yytext) > 42) { mt42++; }}
[-][0-9]+	{ negativeint++; }
[+]*[0-9]+	{ positiveint++; if( atoi(yytext) > 42) { mt42++; }}
%%


main(int argc, char **argv)
{
  yylex();
  printf("positive int: %d\n", positiveint);
  printf("negative int: %d\n", negativeint);
  printf("positive real: %d\n", positivereal);
  printf("negative real: %d\n", negativereal);
  printf("greater than 42: %d\n", mt42);
}