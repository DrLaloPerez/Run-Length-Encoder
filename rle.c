//
//	Run Length Encoding functions
//
//	Eduardo Perez, Ph.D.
//	December 16, 2015
//	(c) 2015 - 2017 Digital Gap, Inc.
//

#include "rle.h"

int rlEncode(Byte* s, int size, Byte* rle) {
	int length = 0;

	for (int i = 0; i < size; i++) {
		Byte byte = *rle++ = *s++;
		int  j;

		for (j = 1; *s == byte && i < size && j < 255; i++, j++, s++)
			;

		*rle++ = j;
		length += 2;
	}

	return length;
}

void rlDecode(Byte* rle, int size, Byte* rld) {
	for (int i = 0; i < size; i++) {
		Byte byte = *rld++ = *rle++;
		int  j = *rle++;

		for (i += --j; j--; *rld++ = byte)
			;
	}
}

Byte* rleInit(int size) {
	return calloc(size << 1, sizeof(Byte));
}

Byte* rldInit(int size) {
	return calloc(size, sizeof(Byte));
}

void rleClose(Byte* rle) {
	if (rle) free(rle);
}

void rldClose(Byte* rld) {
	if (rld) free(rld);
}