/*
 likai
 2016-10-24
 */
#ifndef _GLOBALS_H_
#define _GLOBALS_H_

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
	ENDFILE,ERROR,	
    /* reserved words */
    IF,WHILE,ELSE,INT,RETURN,VOID,
    /* multicharacter tokens */
    ID,NUM,
    /* special symbols */
    ASSIGN,EQ,NEQ,
	LT,LTE,
	GT,GTE,
	PLUS,MINUS,TIMES,OVER,LPAREN,RPAREN,SEMI,
	COMMA,
	LSQUARE,RSQUARE,LBRACE,RBRACE,
   } TokenType;

extern FILE* source; 	//point to source code file
extern FILE* listing; 	//output stream
extern FILE* code; 		//code text file

extern int lineno;		//line no for listing
extern int EchoSource;	//the control signal to print the source code 
extern int TraceScan;	//the control signal to print the tokens
extern int Error; 
#endif

