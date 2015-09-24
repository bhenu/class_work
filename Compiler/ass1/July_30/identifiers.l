%{
	int count = 0;
%}

%%
[\n| |^][A-Za-z_]+[A-Za-z_0-9]*  {count++; }
%%


main(int argc, char **argv)
{
  yylex();
  printf("no of identifiers statements: %d\n", count);
  
}