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


typedef enum{
    /* reserved words */
    IF,WHILE,ELSE,INT,CHAR,RETURN,VOID,
    /* set */
    ID,NUM,
    /* simple symbols */
	PLUS,MINUS,TIMES,LPAREN,RPAREN,SEMI,COMMA,
	LSQUARE,RSQUARE,LBRACE,RBRACE,
    /* diffcult symbols*/
    LE,GE,NEQ,NOT,ASSIGN,EQ,LT,GT,SLASH,SIGN,
    /*other*/
    ENDFILE,ERROR
   } TokenType;

typedef enum{
    START,
    ASSIGNSTA,EQUALSTA,
    ENTERCOMMENT,COMMENTSTA,EXISTCOMMENT,
    SLASHSTA,SIGNSTA,
    NUMSTA,IDSTA,
    LTSTA,LESTA,
    GTSTA,GESTA,
    NEQSTA,
    OVER}StateType;

extern FILE* source; 	//point to source code file
extern FILE* listing; 	//output stream
extern FILE* code; 		//code text file

extern int lineno;		//line no for listing
extern int EchoSource;	//the control signal to print the source code 
extern int TraceScan;	//the control signal to print the tokens
extern int Error; 

