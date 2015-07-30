/* just like Unix wc */
%{
	int chars = 0;
	int words = 0;
	int lines = 0;
	int spaces = 0;
%}

%%
[a-zA-Z]+  { words++; chars += strlen(yytext); }
[ ]		   { chars++; spaces++;}
\n         { chars++; lines++; }
.          { chars++; }
%%

main(int argc, char **argv)
{
  if (argc < 2)
  {
  	printf("%s\n", "usage: <input file>");
  	return -1;
  }

  yyin = fopen(argv[1], "r");

  yylex();
  printf("lines: %d\nwords: %d\nchars: %d\nnspaces: %d\n", lines, words, chars, spaces);
}