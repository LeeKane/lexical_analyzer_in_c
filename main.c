/*
 liaki
 2016-10-24
 */

#include "globals.h"
#include "lex.h"

FILE * source;
FILE * listing;
FILE * code;
int EchoSource = FALSE;
int TraceScan = TRUE;
int Error = FALSE;

int main(int argc, char * argv[]){
	char souecrFile[200];
    strcpy(souecrFile,argv[1]) ;
	source = fopen(souecrFile,"r");
	printf("lexical analyze-> %s\n",souecrFile);
    printf("\n--->\n");
	while (getToken()!=ENDFILE);
	fclose(source);
	return 0;
}


