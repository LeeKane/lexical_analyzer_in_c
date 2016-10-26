/*
 likai
 2016-10-24
 */

#include "globals.h"
#include "lex.h"
void printToken(TokenType, const char*);
int getNextChar(void);
TokenType checkReserved (char* s);
static int pos=0;
static int lineid=0;
static char currentLine[500];//set size 500
static int currentLineSize;
static int isEnd=FALSE;
static int isComment=FALSE;
char getString[500];

TokenType getToken(void){
StateType state = START;
TokenType currentToken=ID;//Initialization
int getStringSize=0;

    
    while (state!=OVER)
    {
        int isSave=TRUE;
        int c=getNextChar();
//        printf("%c  sss\n",c);
        if(isComment)
        {
            isSave=FALSE;
            state=OVER;
            return 1;
        }
        switch (state)
        {
            case START:
                //diffcult and set
                if(isalpha(c))
                    state=IDSTA;
                else if(isdigit(c))
                    state=NUMSTA;
                else if(c=='<')
                    state=LESTA;
                else if(c=='>')
                    state=GESTA;
                else if(c=='=')
                    state=ASSIGNSTA;
                else if(c=='!')
                    state=NEQSTA;
                else if(c=='/')
                    state=ENTERCOMMENT;
                    //blank
                else if ((c == ' ') || (c == '\t') || (c == '\n'))
                    isSave = FALSE;
                //simple
                else
                {
                    state=OVER;
                    switch (c)
                    {
                        case 0:
                            currentToken=ENDFILE;
                            break;
                        case'+':
                            currentToken=PLUS;
                            break;
                        case'-':
                            currentToken=MINUS;
                            break;
                        case '%':
                            currentToken =MOD;
                            break;
                        case '*':
                            currentToken = TIMES;
                            break;
                        case '(':
                            currentToken = LPAREN;
                            break;
                        case ')':
                            currentToken = RPAREN;
                            break;
                        case '[':
                            currentToken=LSQUARE;
                            break;
                        case ']':
                            currentToken=RSQUARE;
                            break;
                        case '{':
                            currentToken=LBRACE;
                            break;
                        case '}':
                            currentToken=RBRACE;
                            break;
                        case ';':
                            currentToken = SEMI;
                            break;
                        case ',':
                            currentToken=COMMA;
                            break;
                        default:
                            currentToken = ERROR;
                            break;
                    }
                    
                }
                break;
            //state ananlyze
            case IDSTA:
                if(!(isalpha(c)||isdigit(c)))
                {
                    pos--;//reset pos to previous char for next analyze
                    isSave=FALSE;//it is not this token's char
                    state=OVER;
                    currentToken=ID;
                }
                break;
            case NUMSTA:
                if(!isdigit(c))
                {
                    pos--;
                    isSave=FALSE;
                    state=OVER;
                    currentToken=NUM;
                }
                break;
            case LESTA:
                if(c=='=')
                {
                    state=OVER;
                    currentToken=LE;
                }
                else
                {
                    pos--;
                    isSave=FALSE;
                    state=OVER;
                    currentToken=LT;
                }
                break;
            case GESTA:
                if(c=='=')
                {
                    state=OVER;
                    currentToken=GE;
                }
                else
                {
                    pos--;
                    isSave=FALSE;
                    state=OVER;
                    currentToken=GT;
                }
                break;
            case ASSIGNSTA:
                if(c=='=')
                {
                    state=OVER;
                    currentToken=EQ;
                }
                else
                {
                    pos--;
                    isSave=FALSE;
                    state=OVER;
                    currentToken=ASSIGN;
                }
                break;
            case NEQSTA:
                if(c=='=')
                {
                    state=OVER;
                    currentToken=NEQ;
                }
                else
                {
                    pos--;
                    isSave=FALSE;
                    state=OVER;
                    currentToken=NOT;
                }
                break;
            case ENTERCOMMENT:
                if(c=='/')
                {
                    state=OVER;
                    currentToken=COMMENT;
                    isComment=TRUE;
                }
                else if(c=='*')
                {
                    state=COMMENTSTA;
                }
                else
                {
                    pos--;
                    state=OVER;
                    currentToken=ERROR;
                }
                break;
            case COMMENTSTA:
                if(c=='*')
                {
                    state=OUTCOMMENT;
                }
                else
                {
                    state=COMMENTSTA;
                    if(isEnd)
                    {
                        state=OVER;
                        currentToken=ERROR;
                    }
                }
                break;
            case OUTCOMMENT:
                if(c=='/')
                {
                    state=OVER;
                    currentToken=COMMENT;
                }
                else
                {
                    state=COMMENTSTA;
                    if(isEnd)
                    {
                        state=OVER;
                        currentToken=ERROR;
                    }
                    
                }
                break;
            case OVER:
            default:
                printf("ERROR IN %d\n",state);
                state=OVER;
                currentToken=ERROR;
                break;
        }
        if(isSave)
            getString[getStringSize++]=(char)c;
        if(state==OVER)
        {
            getString[getStringSize]='\0';
        }
    }
    printf("line:%d  ",lineid);//print line id first
    if(currentToken==ID)
    {
        currentToken=checkReserved(getString);
    }
    printToken(currentToken,getString);
    return currentToken;
}

void printToken(TokenType token,const char* getString){
    switch(token){
        case SIGN:
            printf("sign,            %s\n",getString);
            break;
        case MOD:
            printf("%%\n");
            break;
        case ASSIGN:
            printf("=\n");
            break;
        case LT:
            printf("<\n");
            break;
        case LE:
            printf("<=\n");
            break;
        case GT:
            printf(">\n");
            break;
        case GE:
            printf(">=\n");
            break;
        case EQ:
            printf("==\n");
            break;
        case NEQ:
            printf("!=\n");
            break;
        case NOT:
            printf("!\n");
            break;
        case LPAREN:
            printf("(\n");
            break;
        case RPAREN:
            printf(")\n");
            break;
        case SEMI:
            printf(";\n");
            break;
        case COMMA:
            printf(",\n");
            break;
        case LSQUARE:
            printf("[\n");
            break;
        case RSQUARE:
            printf("]\n");
            break;
        case LBRACE:
            printf("{\n");
            break;
        case RBRACE:
            printf("}\n");
            break;
        case PLUS:
            printf("+\n");
            break;
        case MINUS:
            printf("-\n");
            break;
        case TIMES:
            printf("*\n");
            break;
        case SLASH:
            printf("/\n");
            break;
        case ENDFILE:
            printf("END\n");
            break;
        case COMMENT:
            printf("COMMENT\n");
            break;
        case NUM:
            printf("NUM,             numberVal=%s\n",getString);
            break;
        case ID:
            printf("ID,              idName=%s\n",getString);
            break;
        case RESERVEDWORD:
            printf("reserved word:   %s\n",getString);
            break;
        case ERROR:
            printf("ERROR:          in this line\n");
            break;
        default: /* should never happen */
            printf("Unknown token: %d\n",token);
            break;
    }
}



int getNextChar(void){
    if(pos>=currentLineSize)
    {
        isComment=FALSE;
        lineid++;
        if (fgets(currentLine,500,source))
        {
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

TokenType checkReserved (char* s){
    int i;
    for(i=0;i<reservedNum;i++)
        if(!strcmp(s,reservedWords[i])){
            return RESERVEDWORD;
        }
    return ID;
}



