//
//	Run Length Encoding test program
//
//	Eduardo Perez, Ph.D.
//	December 16, 2015
//	(c) 2015 - 2017 Digital Gap, Inc.
//

#include <stdio.h>
#include <string.h>
#include "rle.h"

#define MAX_LINE_SIZE	500

int	 getLine(Byte* line);
void printLine(Byte* line, int size);

void main() {
	Byte line[MAX_LINE_SIZE];

	printf("\n Type line of maximum length %d\n\n", MAX_LINE_SIZE);
	int size = getLine(line);

	//	Initialize the Run Length Encoder and Decoder
	Byte* rle = rleInit(size);
	Byte* rld = rldInit(size);

	//	Run Length Encode
	int length = rlEncode(line, size, rle);
	printf("\n RLE Length:  %d", length);
	printf("\n Line Length: %d\n", size);

	printf("\n Line: ");
	printLine(line, size);

	printf(" RLE:  ");
	for (int i = 0; i < length; i += 2)
		printf("%c%x", rle[i], rle[i + 1]);

	//	Run Length Decode
	rlDecode(rle, size, rld);
	printf("\n RLD:  ");
	printLine(line, size);

	//	Clean up
	rleClose(rle);
	rldClose(rld);
}

int getLine(Byte* line) {
	int size = 0;
	int n = MAX_LINE_SIZE;

	Byte c;
	while ((c = getchar()) != '\n' && n--) {
		*line++ = c;
		size++;
	}

	return size;
}

void printLine(Byte* line, int size) {
	while (size--)
		printf("%c", *line++);
	printf("\n");
}