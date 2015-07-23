%{
	int count = 0;
%}

%%
(ab)+	{count++;}
(AB)+	{count++;}
%%


main(int argc, char **argv)
{
  yylex();
  printf("number of occurrences of \"ab\": %d\n", count);
}