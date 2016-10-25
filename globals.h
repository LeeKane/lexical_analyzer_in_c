/*
 likai
 2016-10-24
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

typedef enum{
    /* reserved words */
    IF,WHILE,ELSE,INT,CHAR,RETURN,VOID,
    /* set */
    ID,NUM,
    /* simple symbols */
	PLUS,MINUS,TIMES,LPAREN,RPAREN,SEMI,COMMA,
	LSQUARE,RSQUARE,LBRACE,RBRACE,
    /* diffcult symbols*/
    LE,GE,NEQ,ASSIGN,EQ,LT,GT,SLASH,
    /*other*/
    ENDFILE,ERROR
   } TokenType;

typedef enum{
    START,
    ASG,EQUAL,
    ENTERCOMMENT,INCOMMENT,EXISTCOMMENT,
    INOVER,
    INNUM,INID,
    INLT,INLTE,
    INGT,INGTE,
    INNEQ,
    DONE}StateType;

extern FILE* source; 	//point to source code file
extern FILE* listing; 	//output stream
extern FILE* code; 		//code text file

extern int lineno;		//line no for listing
extern int EchoSource;	//the control signal to print the source code 
extern int TraceScan;	//the control signal to print the tokens
extern int Error; 

