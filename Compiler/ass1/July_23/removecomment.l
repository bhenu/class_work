%{
	int ncomments = 0;
	int nblocks = 0;
%}

%%
\/\*.*\*\/	{ncomments++;}
\/\/.*\n 	{nblocks++; }
%%


main(int argc, char **argv)
{
  yylex();
  printf("no of block comments: %d\n", nblocks);
  printf("no of inline comments: %d\n", ncomments);
}