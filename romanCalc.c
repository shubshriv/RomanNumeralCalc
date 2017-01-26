/*
 * Filename: romanCalc.c
 * Author: Shubham Shrivastava
 *
 * Description: This file contains the function "romanCalc" that
 * takes the numerals and operator as its input arguments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "romanCalc.h"

char *romanCalc( char *num1, char *num2, char *opr) {
    bool isNum1Valid, isNum2Valid;
    int valNum1, valNum2, valRes;
    initCount();
    isNum1Valid = isNumValid(num1);
    initCount();
    isNum2Valid = isNumValid(num2);
    if(!isNum1Valid | !isNum2Valid) {
        DieWithError("Input Numerals not Valid!");
    }
    valNum1 = getValOfNumeral(num1);
    valNum2 = getValOfNumeral(num2);
    valRes = performOperation(valNum1, valNum2, opr);
    romanRes = (char *)malloc(10*sizeof(char));
	memset(romanRes, 0, 10*sizeof(char));
    convertDecToRoman(valRes);
    return romanRes;
    free(romanRes);
}
