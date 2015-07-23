%{
	int vowel = 0;
%}

%%
[aeiouAEIOU]	{ vowel++; }
[a-zA-Z]+  { }
\n         { }
.          { }
%%


main(int argc, char **argv)
{
  yylex();
  printf("vowel: %d\n", vowel);
}