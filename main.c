/*
 liaki
 2016-10-24
 */

#include "globals.h"
#include "util.h"
#include "scan.h"

int lineno = 0;
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
	listing = stdout;
	printf("\nlexical analyze-> %s\n",souecrFile);
    printf("\n--->");
	while (getToken()!=ENDFILE);
	fclose(source);
	return 0;
}


