/*
 * Ch2-9.c
 *
 *  Created on: Jan 23, 2016
 *      Author: smashoth
 */


#include <stdio.h>
#include <stdlib.h>

unsigned getbits(unsigned x, int p, int n);

int main(void) {
	unsigned x = 198;
	int p = 4;
	int n = 3;
	puts("Breakdown:");
	printf("p + 1 -n = %d\n", p + 1 - n);
	printf("x >> 2 = %08x\n", x >> 2);
	printf("~0 << n = %x\n", ~0 << n);
	printf("~(ff ff ff f8) = %08x\n", ~(0xfffffff8));
	printf("0x31 & 0x07 = %08x\n", 0x31 & 0x07);

	x = getbits(x, p, n);
	printf("bitfield contains: %08x\n", x);
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

unsigned getbits(unsigned x, int p, int n){

	return (x >> (p +1 - n)) & ~(~0 << n);
}


