/*
 likai
 2016-10-24
 */

#include "globals.h"
#include "lex.h"
static int pos=0;
static int lineid=0;
static char currentLine[500];
static int currentLineSize;
static int isEnd=FALSE;

static int getNextChar(void){
    if(pos>=currentLineSize)
    {
        if (fgets(currentLine,500,source))
        {
//        printf("line:%4d",lineid);//print line id first
        currentLineSize = strlen(currentLine);
        pos = 0;
        return currentLine[pos++];
        }
        else
        {
        isEnd = TRUE;
        return 0;
        }
    }
    else
        return currentLine[pos++];

}

TokenType getToken(void){
TokenType currentToken=ID;
int c=getNextChar();
    switch (c) {
        case 0:
            currentToken=ENDFILE;
            break;
            
        default:
            printf("%c",c);
            break;
    }
    return currentToken;
}

