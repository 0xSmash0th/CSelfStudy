/*
 * Ch2-9.c
 *
 *  Created on: Jan 23, 2016
 *      Author: smashoth
 */


#include <stdio.h>
#include <stdlib.h>
/*
 * The purpose of the gitbits funtion is to
 * get get n number of bits at position "p" from variable "x"
 * the "~" bitwise operator is will operate based on the architecture word size
 * e.g. ~0 on a 8bit would be ff, ~0 on 32bit would be ff ff ff ff
 */
unsigned getbits(unsigned x, int p, int n);

int main(void) {
/* I run through a breakdown of the bitwise operations provided in ch 2.9 before I call the function.
 * If you want to see a breakdown with different variables you will have to change the hard-coded "printf" values.
 * I remain in hex throughout the code but it is much easier to visualize in binary.
 * SO, I have added extra comments to show what is going on in binary.
 */


	unsigned x = 198;
	int p = 4;
	int n = 3;

	puts("Breakdown:");
//	1. (p +1 -n) = 4 + 1 - 3 = 2,
	printf("p + 1 -n = %d\n", p + 1 - n);
//	2. x >> 2 = 1100 0110 >> 2 = 0011 0001 = 0x31
	printf("x >> 2 = %08x\n", x >> 2);
//	3. ~(~0 << n) = ~(1111 1111 <<  3) =  ~(1111 1111 1111 1111 1111 1111 1111 1000) =  ~(ff ff ff f8)
	printf("~0 << n = %x\n", ~0 << n);
//	4. ~(ff ff ff f8) = 00 00 00 07 = 0000 0000 0000 0000 0000 0000 0000 0111
	printf("~(ff ff ff f8) = %08x\n", ~(0xfffffff8));
//	5.  0x31 & 0x07 = 00 00 00 01 = 0x01
	printf("0x31 & 0x07 = %08x\n", 0x31 & 0x07);

//	Call the acctual function. If you just change the vars x, p and n, this call will be correct but the breakdown will be wrong.
	x = getbits(x, p, n);
	printf("bitfield contains: %08x\n", x);

	return EXIT_SUCCESS;
}

unsigned getbits(unsigned x, int p, int n){

	return (x >> (p +1 - n)) & ~(~0 << n);
}


