
/*
 * Filename: romanCalcFunc.h
 * Author: Shubham Shrivastava
 *
 * Description: This file contains definition of all the
 * functions being used in the main function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "romanCalc.h"

uint8_t indexRes = 0;
/* Print the error and terminate the execution */
void DieWithError(char *errorMessage)
{
    perror(errorMessage);
    exit(EXIT_FAILURE);
}

/*
 * Initialize the count of each letters. Its being used before
 * validating the input numerals.
 */
void initCount() {
    countI = 0;
    countV = 0;
    countX = 0;
    countL = 0;
    countC = 0;
    countD = 0;
    countM = 0;
}

/* This function returns the integer value of each roman letter */
int getIntValueOfLetter(char ltr) {
    int valueToReturn;
    switch(ltr) {
        case 'I':
        valueToReturn = 1;
        break;
        case 'V':
        valueToReturn = 5;
        break;
        case 'X':
        valueToReturn = 10;
        break;
        case 'L':
        valueToReturn = 50;
        break;
        case 'C':
        valueToReturn = 100;
        break;
        case 'D':
        valueToReturn = 500;
        break;
        case 'M':
        valueToReturn = 1000;
        break;
        default:
        valueToReturn = 0;
        DieWithError("Letter Not Recognized!");
    }
    return valueToReturn;
}

/* This function is called to validate the input numerals */
bool isNumValid(char *str) {
    int i;
    int len = strlen(str);
    for( i=0;i<len; i++ ) {
        switch(str[i]) {
            case 'I':
            countI++;;
            break;
            case 'V':
            countV++;
            break;
            case 'X':
            countX++;
            break;
            case 'L':
            countL++;
            break;
            case 'C':
            countC++;
            break;
            case 'D':
            countD++;
            break;
            case 'M':
            countM++;
            break;
        }
    }
    if((countI > 3) | (countX > 3) | (countC > 3) | (countV > 1) | (countL > 1) | (countD > 1)) {
        return false;
    }
    else {
        return true;
    }
}

/* This function returns the integer value of a roman numeral */
int getValOfNumeral(char *str) {
    uint8_t i;
    uint8_t len = strlen(str);
    int valOfChar[10], valToRet = 0;
    for(i=0; i<len; i++) {
        valOfChar[i] = getIntValueOfLetter(str[i]);
        if(i > 0) {
            if(valOfChar[i] > valOfChar[i-1]) {
                valToRet = valOfChar[i] - valToRet;
            }
            else {
                valToRet = valOfChar[i] + valToRet;
            }
        }
        else {
            valToRet = valOfChar[i];
        }
    }
    return valToRet;
}

/* This function performs the operation between two roman numerals as intended by the user */
int performOperation(int val1, int val2, char* opr) {
    if(((opr[0]!='+') & (opr[0]!='-')) | (strlen(opr)!=1)) {
            DieWithError("Invalid Operator");
    }
    if(opr[0] == '+') {
        return val1 + val2;
    }
    else {
        if(val1 < val2) {
            DieWithError("Cannot subtract! First numeral must be bigger than the Second numeral");
        }
        else {
                return val1 - val2;
        }
    }
}

/*
 * The functions preDigits and postDigits are used by convertDecToRoman
 * to assign the roman letters based on the integer value of result
 * returned by the function performOperation .
 */
void preDigits(char c1,char c2){
    romanRes[indexRes++] = c1;
    romanRes[indexRes++] = c2;
}

void postDigits(char c,int n){
    int j;
    for(j=0;j<n;j++)
         romanRes[indexRes++] = c;
}

/* This function converts a decimal number to a roman numeral */
void convertDecToRoman(int val) {
        while(val != 0){

         if(val >= 1000){
             postDigits('M',val/1000);
             val = val - (val/1000) * 1000;
         }
         else if(val >=500){
             if(val < (500 + 4 * 100)){
                 postDigits('D',val/500);
                 val = val - (val/500) * 500;
             }
             else{
                 preDigits('C','M');
                 val = val - (1000-100);
             }
         }
         else if(val >=100){
             if(val < (100 + 3 * 100)){
                 postDigits('C',val/100);
                 val = val - (val/100) * 100;
             }
             else{
                 preDigits('L','D');
                 val = val - (500-100);
             }
         }
         else if(val >=50){
             if(val < (50 + 4 * 10)){
                 postDigits('L',val/50);
                 val = val - (val/50) * 50;
             }
             else{
                 preDigits('X','C');
                 val = val - (100-10);
             }
         }
         else if(val >=10){
             if(val < (10 + 3 * 10)){
                 postDigits('X',val/10);
                 val = val - (val/10) * 10;
             }
             else{
                 preDigits('X','L');
                 val = val - (50-10);
             }
         }
         else if(val >=5){
             if(val < (5 + 4 * 1)){
                 postDigits('V',val/5);
                 val = val - (val/5) * 5;
             }
             else{
                 preDigits('I','X');
                 val = val - (10-1);
             }
         }
         else if(val >=1){
             if(val < 4){
                 postDigits('I',val/1);
                 val = val - (val/1) * 1;
             }
             else{
                 preDigits('I','V');
                 val = val - (5-1);
             }
         }
    }
}
