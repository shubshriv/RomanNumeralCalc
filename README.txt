This folder contains a library which allows the addition and subtraction of
Roman numerals.

The library has three files: romanCalc.c; romanCalc.h; romanCalcFunc.c

The test file to check its functionality is testRomanCalc.c
This test file takes the input from user during execution.

The syntax to use the library from any other file is: romanCalc(romanNum1, romanNum2, opr);
where romanNum1 is the first roman numeral, romanNum2 is the second numeral and opr defines the operation to be performed.
The return type of the result from this function is (char *).
Example: char* res = romanCalc("IX", "V", "+");

The codes and Makefile are written to be compiled by GNU GCC in C environment of Ubuntu Linux.

To create the binary: 	
						change the directory to the current location of this folder in Ubuntu
						Type: make
						This creates a binary named "testRomanCalc"
						
To run the binary:		
						change the directory to the current location of this folder in Ubuntu
						Type: ./testRomanCalc
						The code will then ask you to input.
						Type your in the format: [Num1] [opr] [Num1]
						Example: IX + V
						The code will then print out the result returned by the library
						
To remove the object and binary files:
						change the directory to the current location of this folder in Ubuntu
						Type: make clean

--------------------
Files in this folder
--------------------
romanCalc.h
romanCalc.c
romanCalcFunc.c
testRomanCalc.c
Makefile
README
-------------------