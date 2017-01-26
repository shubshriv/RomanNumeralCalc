/*
 * Filename: romanCalc.h
 * Author: Shubham Shrivastava
 *
 * Description: This header file contains declarations of
 * all the functions being used in this library.
 */

 #include <stdbool.h>
 #include <stdint.h>
 #include <stdio.h>

uint8_t countI, countV, countX, countL, countC, countD, countM;
char *romanRes;
char *romanCalc( char *num1, char *num2, char *opr);
void DieWithError(char *errorMessage);
void initCount();
int getIntValueOfLetter(char ltr);
bool isNumValid(char *str);
int getValOfNumeral(char *str);
int performOperation(int val1, int val2, char* opr);
void preDigits(char c1,char c2);
void postDigits(char c,int n);
void convertDecToRoman(int val);
