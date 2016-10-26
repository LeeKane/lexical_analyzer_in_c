/*
 likai
 2016-10-24
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define reservedNum 9
typedef enum{
    /* reserved words */
    RESERVEDWORD,
    /* set */
    ID,NUM,
    /* simple symbols */
	PLUS,MINUS,TIMES,LPAREN,RPAREN,SEMI,COMMA,
	LSQUARE,RSQUARE,LBRACE,RBRACE,MOD,
    /* diffcult symbols*/
    LE,GE,NEQ,NOT,ASSIGN,EQ,LT,GT,SLASH,SIGN,
    /*comment*/
    COMMENT,
    /*other*/
    ENDFILE,ERROR
   } TokenType;

typedef enum{
    START,
    ASSIGNSTA,EQUALSTA,
    ENTERCOMMENT,COMMENTSTA,OUTCOMMENT,
    SLASHSTA,SIGNSTA,
    NUMSTA,IDSTA,
    LTSTA,LESTA,
    GTSTA,GESTA,
    NEQSTA,
    OVER}StateType;

extern FILE* source;
extern int Error; 

static char* reservedWords[reservedNum]={"if","while","for","else","void","int","char","return","printf"};
