// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW_quantize:
//
// Quantize I1 to specified number of levels. Apply dither if flag is set.
// Output is in I2.
//
// //	Written by :	BASHIR AHAMED
//			SHOFIQUR RAHMAN
//			UCHA SAMADASHVILI
//
//	Semester   :	FALL 2018
//
void
HW_quantize(ImagePtr I1, int levels, bool dither, ImagePtr I2)
{
	int w = I1->width();
	int h = I1->height();
	int total =  w * h;

	int i, lut[MXGRAY];

	IP_copyImageHeader(I1, I2);

	double scale = double(MXGRAY)/levels;

	// assign the values of the look up table

	for(i = 0; i < MXGRAY; ++i)
		 // Use maro function CLIP(int a, int b, int c): min(max(a.b),c)
		lut[i] = CLIP(int( floor(i/scale) * scale + scale/2 ), 0, MXGRAY);

	// dither disabled
	
	if( !dither) {
		int type;
		ChannelPtr<uchar> p1, p2, endPtr;
		for(int ch = 0; IP_getChannel(I1, ch, p1, type); ++ch) {
			IP_getChannel(I2, ch, p2, type);
			for(endPtr = p1 + total; endPtr > p1; )
				*p2++ = lut[*p1++];
		}
	}


	// dither is enabled
	
	else {

	}
}
