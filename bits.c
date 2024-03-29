/* 
 * CS:APP Data Lab 
 * 
 * <Deng Ze 18307130177>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
/*get the same part by x&y*/
  int z = x & y;
  int a = (~0)&(~x)&(~y);
  return (~a)&(~z);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
/* -2^31 */
  return 1<<31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int NotNeg = !(x + 1) + (~0);
  int y = ~x + (~0);
  return NotNeg&(!(x^y));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
/* lbyte means least byte , if all odd-numbered bits set to 1 ,lbyte = 0xAA 
   otherwise the lbyte < 0xAA (some bits set 0)*/
  int lbyte = 0xAA&x&(x>>8)&(x>>16)&(x>>24);
  return !(0xAA^lbyte);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
/* just follow the complement rule */
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
/* hbyte means half byte , set the bits (higher than 4) 0 
   0xA + 6 = 0x10 so that >>4 can not turn 0 */
  int ZeroFlag = !(x>>8);
  int Flag = ~(ZeroFlag + (~0));
  int hbyte = 0x30^x;
  return (!((hbyte+6)>>4))&Flag;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
/*if x = 0 , flag = 0 ; if x != 0 flag = -1*/
/*if flag = 0 , dflag = -1 ; if flag = -1 , dflag = 0*/
  int flag = (!x)+(~0);
  int dflag = flag^(~0);
  return (flag&y)|(dflag&z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int xflag = (x>>31)&1;
  int yflag = (y>>31)&1;
  int NotSame = xflag^yflag;
  int cha = y + ~x + 1;
  int chaflag = (cha>>31)&1;
  /*if not same Not+Same = 1 , (NotSame^yflag) == result*/
  /*if same Notsame = 0 , !chaflag == result*/
  return (NotSame&(NotSame^yflag))|((!NotSame)&(!chaflag));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  return ((x|((~x)+1))>>31)+1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */

int howManyBits(int x) {
  int xflag = (x>>31)&1;
  int NotZero = (!x) + (~0);
  int NotFF = (!(x+1)) + (~0);
  int NotSpe = NotZero & NotFF;
  int flag = ~((!xflag) + (~0));
/*log(absolute value)*/
  int temp1,temp2,temp3,temp4,temp5;
  int sign;
/*if x > 0*/
  int abs = x;
  sign = !!(abs>>16);
  temp1 = sign<<4;
  abs = abs>>temp1;

  sign = !!(abs>>8);
  temp2 = sign<<3;
  abs = abs>>temp2;

  sign = !!(abs>>4);
  temp3 = sign<<2;
  abs = abs>>temp3;

  sign = !!(abs>>2);
  temp4 = sign<<1;
  abs = abs>>temp4;

  temp5 = !!(abs>>1);
  int PosRet = (temp1 + temp2 + temp3 + temp4 + temp5 + 2);
/*if x <= 0*/
  int negx;
  negx = ~x;
  sign = !!(negx>>16);
  temp1 = sign<<4;
  negx = negx>>temp1;

  sign = !!(negx>>8);
  temp2 = sign<<3;
  negx = negx>>temp2;

  sign = !!(negx>>4);
  temp3 = sign<<2;
  negx = negx>>temp3;

  sign = !!(negx>>2);
  temp4 = sign<<1;
  negx = negx>>temp4;

  temp5 = !!(negx>>1);
  int NegRet = (temp1 + temp2 + temp3 + temp4 + temp5 + 2);
  int NotSpeRet;
  NotSpeRet = (flag&PosRet)|((~flag)&(NegRet));
  return (NotSpe & NotSpeRet)|((~NotSpe)&1);
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */

unsigned floatScale2(unsigned uf) {
  unsigned sign = uf&0x80000000;
  unsigned exp = uf&0x7F800000;
  unsigned frac = uf&0x007FFFFF;
/* NaN and infinite*/
  if(!(exp^0x7F800000)) return uf;
/* Innormalize */
  if(!exp) return (uf<<1)|sign;
/* Normalize */
  return (sign|(exp+(1<<23))|frac);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */

int floatFloat2Int(unsigned uf) {
  unsigned sign = uf&0x80000000;
  unsigned exp = uf&0x7F800000;
  unsigned frac = uf&0x007FFFFF;
/*out of range*/
  if(!(exp^0x7F800000)) return 0x80000000u;
/*Innormalize*/
  if(!exp)  return 0;
/*Normalize*/
  int Negflag;
  Negflag= (!sign) + (~0);
  int E;
  E = ((exp>>23)&0xFF) + (~127) + 1;
  int signE;
  signE = (E>>31)&1;
  if(!E) return (Negflag&(~0))|((~Negflag)&1);
  if(signE) return 0;
  int NotOver = ((E + (~32) + 1)>>31)&1;
  if(NotOver)
  return (1<<E) + (frac>>(24 + (~E)));
  return 0x80000000u;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */

unsigned floatPower2(int x) {
/*too small*/
  if(x < -126) return 0;
/*too large*/
  if(x > 127) return 0x7F800000;
/*Normalize*/
    return (x+127)<<23;
}
