#include <sys/types.h>
#include <stdio.h>
#include <math.h>

void fill_circle(int x, int y, int r, int w, int h, u_int32_t color, u_int32_t* pixels) {
	for (int i = 0; i < r; i++) {
		static const double PI = 3.1415926535;
		double j, angle, x1, y1;

		for (j = 0; j < 360; j += 0.1)
		{
			angle = j;
			x1 = (double)i * cos(angle * PI / 180);
			y1 = (double)i * sin(angle * PI / 180);
			if ((x + x1 < w) && (x + x1 > 0) && (y + y1 > 0) && (y + y1 < h)) {
				*(pixels + (int)(y + y1) * w + (int)(x + x1)) = color;
			}
		}
	}
}
