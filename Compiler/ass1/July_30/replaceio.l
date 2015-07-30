%{
	int nscanf = 0;
	int nprintf = 0;
%}

%%
[ |\t|^]scanf\(.*\)\;	{ nscanf++; printf("%s", "read"); }
[ |\t|^]printf\(.*\)\;		{ nprintf++; printf("%s", "write");}
%%


main(int argc, char **argv)
{

  if (argc < 2)
  {
  	printf("%s\n", "usage: <input file>");
  	return -1;
  }

  const char *path = argv[1] ;
  yyin = fopen(path, "r");
  yylex();
  printf("nscanf: %d\n", nscanf);
  printf("nprintf: %d\n", nprintf);
}