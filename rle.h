//
//	Run Length Encoding Header file
//
//	Eduardo Perez, Ph.D.
//	December 16, 2015
//	(c) 2015 - 2017 Digital Gap, Inc.
//

#ifndef	RLE_H
#define RLE_H

#include <stdlib.h>

typedef unsigned char Byte;

Byte* rleInit(int size);
Byte* rldInit(int size);
int	  rlEncode(Byte* s, int size, Byte* rle);
void  rlDecode(Byte* rle, int size, Byte* rld);
void  rleClose(Byte* rle);
void  rldClose(Byte* rld);

#endif // RLE_H
