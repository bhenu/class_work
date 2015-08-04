#include "stdio.h"
main(int n,char const *g[]){char p[5][5], c, t; int i, j;const char *k=g[1];char *m=(char*)p;for(j=0;j<26;++j){if('a'+j=='j') continue;*m++ ='a'+j;}j=0;m=p;while((c= *(k++))!='\0'){t=*(m+j);*(m+j)=c;if(c-'a'>c-'j') *(m+c-'a'-1)=t;else *(m+c-'a')=t;j++;}m=p;for(i=0;i<25;++i){if(i%5==0){puts("");}putchar(*m++);}return 0;}

