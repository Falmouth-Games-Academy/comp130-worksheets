// Mandelbrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// source for hsv-rgb "http://stackoverflow.com/questions/3018313/algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-both"
typedef struct {
	double r;       // percent
	double g;       // percent
	double b;       // percent
} rgb;

typedef struct {
	double h;       // angle in degrees
	double s;       // percent
	double v;       // percent
} hsv;

static hsv   rgb2hsv(rgb in);
static rgb   hsv2rgb(hsv in);

hsv rgb2hsv(rgb in)
{
	hsv         out;
	double      min, max, delta;

	min = in.r < in.g ? in.r : in.g;
	min = min  < in.b ? min : in.b;

	max = in.r > in.g ? in.r : in.g;
	max = max  > in.b ? max : in.b;

	out.v = max;                                // v
	delta = max - min;
	if (delta < 0.00001)
	{
		out.s = 0;
		out.h = 0; // undefined, maybe nan?
		return out;
	}
	if (max > 0.0) { // NOTE: if Max is == 0, this divide would cause a crash
		out.s = (delta / max);                  // s
	}
	else {
		// if max is 0, then r = g = b = 0              
		// s = 0, v is undefined
		out.s = 0.0;
		out.h = NAN;                            // its now undefined
		return out;
	}
	if (in.r >= max)                           // > is bogus, just keeps compilor happy
		out.h = (in.g - in.b) / delta;        // between yellow & magenta
	else
		if (in.g >= max)
			out.h = 2.0 + (in.b - in.r) / delta;  // between cyan & yellow
		else
			out.h = 4.0 + (in.r - in.g) / delta;  // between magenta & cyan

	out.h *= 60.0;                              // degrees

	if (out.h < 0.0)
		out.h += 360.0;

	return out;
}


rgb hsv2rgb(hsv in)
{
	double      hh, p, q, t, ff;
	long        i;
	rgb         out;

	if (in.s <= 0.0) {       // < is bogus, just shuts up warnings
		out.r = in.v;
		out.g = in.v;
		out.b = in.v;
		return out;
	}
	hh = in.h;
	if (hh >= 360.0) hh = 0.0;
	hh /= 60.0;
	i = (long)hh;
	ff = hh - i;
	p = in.v * (1.0 - in.s);
	q = in.v * (1.0 - (in.s * ff));
	t = in.v * (1.0 - (in.s * (1.0 - ff)));

	switch (i) {
	case 0:
		out.r = in.v;
		out.g = t;
		out.b = p;
		break;
	case 1:
		out.r = q;
		out.g = in.v;
		out.b = p;
		break;
	case 2:
		out.r = p;
		out.g = in.v;
		out.b = t;
		break;

	case 3:
		out.r = p;
		out.g = q;
		out.b = in.v;
		break;
	case 4:
		out.r = t;
		out.g = p;
		out.b = in.v;
		break;
	case 5:
	default:
		out.r = in.v;
		out.g = p;
		out.b = q;
		break;
	}
	return out;
}

int main()
{
	// Initialise the image
	CImg<unsigned char> image(800, 800, 1, 3, 0);

	// Display the image
	CImgDisplay display(image, "Mandelbrot Set");

	// Minimum and maximum coordinates for the fractal
	const double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;

	// Generate the image
	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		// TODO: Map the y coordinate into the range minY to maxY
		double y0 = (pixelY / 800.0) * (maxY - minY) + minY;

		for (int pixelX = 0.0; pixelX < image.width(); pixelX++)
		{
			// TODO: Map the x coordinate into the range minX to maxX
			double x0 = (pixelX / 800.0) * (maxX - minX) + minX;

			// TODO: implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			double yi = 0.0;
			double xi = 0.0;
			double loops = 0.0;
			
			while (loops < 200 && xi*xi + yi*yi < 4.0)
			{
				double tempX = xi*xi - yi*yi + x0;
				yi = (2 * xi*yi) + y0;
				xi = tempX;
				++loops;

			}
			rgb rgbValue;

			if (loops >= 200)                                       
			{
				rgbValue = { 0.0, 0.0, 0.0 };                    
			}
			else
			{
				hsv currentHSV = { loops, 1.0, 1.0 };               
				rgbValue = hsv2rgb(currentHSV);
			}
				// TODO: change the right-hand side of these three lines to write the desired pixel colour value
			image(pixelX, pixelY, 0, 0) = rgbValue.g*255.0 ; // red component
			image(pixelX, pixelY, 0, 1) = rgbValue.b*255.0; // green component
			image(pixelX, pixelY, 0, 2) = rgbValue.r*255.0; // blue component
		}

		// Uncomment this line to redisplay the image after each row is generated
		// Useful if your program is slow and you want to verify that it is actually doing something
		//display.display(image);
	}

	// Display the complete image
	display.display(image);
	std::cout << "done";

	// Uncomment this line to save the image to disk
	//image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();

	}

	return 0;
}
