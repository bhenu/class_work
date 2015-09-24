%{
	int count = 0;
%}

%%
[A-Za-z0-9]+[ ]*(AND|and|OR|or|BUT|but)+[ ]*[A-Za-z0-9]+ {count++; }
%%


main(int argc, char **argv)
{
  yylex();
  printf("no of compound statements: %d\n", count);
  
}