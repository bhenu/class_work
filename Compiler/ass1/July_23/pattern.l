%{
	int count = 0;
%}

%%
^abb.*ccd$	{count++;}
%%


main(int argc, char **argv)
{
  yylex();
  printf("lines starting with abb and ending with ccd: %d\n", count);
}