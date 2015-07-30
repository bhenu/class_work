%{
	int vowel = 0;
	int consonent = 0;
%}

%%
[aeiouAEIOU]	{ vowel++; }
[a-zA-Z]		{ consonent++; }
%%


main(int argc, char **argv)
{
  yylex();
  printf("vowel: %d\n", vowel);
  printf("consonent: %d\n", consonent);
}