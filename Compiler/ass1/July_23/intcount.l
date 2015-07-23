%{
	int positiveint = 0;
	int negativeint = 0;
	int positivereal = 0;
	int negativereal = 0;
%}

%%
[-][0-9]+\.[0-9]+	{ negativereal++; }
[ +]*[0-9]+\.[0-9]+	{ positivereal++; }
[-][0-9]+	{ negativeint++; }
[ +]*[0-9]+	{ positiveint++; }
%%


main(int argc, char **argv)
{
  yylex();
  printf("positive int: %d\n", positiveint);
  printf("negative int: %d\n", negativeint);
  printf("positive real: %d\n", positivereal);
  printf("negative real: %d\n", negativereal);
}