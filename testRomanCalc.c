/*
 * Filename: testRomanCalc.c
 * Author: Shubham Shrivastava
 *
 * Description: This is a test file that tests the functionality of the
 * romanCalc library.
 * This test file expects the user input from console. Which is then filtered
 * and passed to library which then returns the result of operation.
 * An example of the user input is "XI + V"
 *
 * Simpler way to achieve this would be directly passing the Numerals and Operators.
 * Example: char* res = romanCalc("IX", "V", "+");
 * The above line returns the result of the operation "IX + V" in the char pointer "res".
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "romanCalc.h"

int main() {
    uint8_t i, j, indexAssign;
    char *inputArg = (char *)malloc(30*sizeof(char));
    memset(inputArg, 0, 30*sizeof(char));
    char *romanNum1 = (char *)malloc(10*sizeof(char));
    memset(romanNum1, 0, 10*sizeof(char));
    char *opr = (char *)malloc(10*sizeof(char));
    memset(opr, 0, 10*sizeof(char));
    char *romanNum2 = (char *)malloc(10*sizeof(char));
    memset(romanNum2, 0, 10*sizeof(char));
    printf("Please enter the operation to be performed in following format:\n\t");
    printf("Format: [num1] [opr] [num2]\n\tWhere:  num1 = First Roman Numeral\n\t\topr = Operator\n\t\tnum2 = Second Roman Numeral\n\tExample: IV + X\n");
    printf("Input: ");
    gets(inputArg);
    j = 0, indexAssign = 0;
    /*
    * Filter the input string and assign it to three different fields
    * to pass it to the library romanCalc.
    */
    for(i=0;i<strlen(inputArg);i++) {
        if(inputArg[i] == ' ') {
            j++;
            indexAssign = 0;
        }
        else {
            switch(j) {
            case 0:
                romanNum1[indexAssign] = inputArg[i];
                romanNum1[indexAssign+1] = '\0';
                indexAssign++;
                break;
            case 1:
                opr[indexAssign] = inputArg[i];
                opr[indexAssign+1] = '\0';
                indexAssign++;
                break;
            case 2:
                romanNum2[indexAssign] = inputArg[i];
                romanNum2[indexAssign+1] = '\0';
                indexAssign++;
                break;
            default:
                DieWithError("Only 3 fields are permitted,\n Example: IX + V");
            }
        }
    }
    /*
     * Pass the Roman Numerals and the operator to the library romanCalc
     * which returns the operation result.
     *
     * Simpler way to achieve this would be directly passing the Numerals and Operators.
     * Example: char* res = romanCalc("IX", "V", "+");
     * The above line returns the result of the operation "IX + V" in the char pointer "res".
     */
    char* res = romanCalc(romanNum1, romanNum2, opr);
    printf("Result: %s %s %s = %s\n", romanNum1, opr, romanNum2, res);
    free(inputArg);
    free(romanNum1);
    free(romanNum2);
    return 0;
}
