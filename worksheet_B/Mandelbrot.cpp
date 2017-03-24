// Mandelbrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//hsv to rgb converter https://www.programmingalgorithms.com/algorithm/hsv-to-rgb?lang=C%2B%2B
class RGBvalue
{
public:
	unsigned char R;
	unsigned char G;
	unsigned char B;

	RGBvalue(unsigned char r, unsigned char g, unsigned char b)
	{
		R = r;
		G = g;
		B = b;
	}

	bool Equals(RGBvalue rgb)
	{
		return (R == rgb.R) && (G == rgb.G) && (B == rgb.B);
	}
};

class HSVvalue
{
public:
	double H;
	double S;
	double V;

	HSVvalue(double h, double s, double v)
	{
		H = h;
		S = s;
		V = v;
	}

	bool Equals(HSVvalue hsv)
	{
		return (H == hsv.H) && (S == hsv.S) && (V == hsv.V);
	}
};

static RGBvalue convertHSVToRGB(HSVvalue hsv) {
	double r = 0, g = 0, b = 0;

	if (hsv.S == 0)
	{
		r = hsv.V;
		g = hsv.V;
		b = hsv.V;
	}
	else
	{
		int i;
		double f, p, q, t;

		if (hsv.H == 360)
			hsv.H = 0;
		else
			hsv.H = hsv.H / 60;

		i = (int)trunc(hsv.H);
		f = hsv.H - i;

		p = hsv.V * (1.0 - hsv.S);
		q = hsv.V * (1.0 - (hsv.S * f));
		t = hsv.V * (1.0 - (hsv.S * (1.0 - f)));

		switch (i)
		{
		case 0:
			r = hsv.V;
			g = t;
			b = p;
			break;

		case 1:
			r = q;
			g = hsv.V;
			b = p;
			break;

		case 2:
			r = p;
			g = hsv.V;
			b = t;
			break;

		case 3:
			r = p;
			g = q;
			b = hsv.V;
			break;

		case 4:
			r = t;
			g = p;
			b = hsv.V;
			break;

		default:
			r = hsv.V;
			g = p;
			b = q;
			break;
		}

		if (hsv.H > 200)
		{
			r = 0;
			g = 0;
			b = 0;
		}
	}

	return RGBvalue((unsigned char)(r * 255), (unsigned char)(g * 255), (unsigned char)(b * 255));
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
		// Map the y coordinate into the range minY to maxY
		
		double y0 = (pixelY / (double) image.height()) * (maxY-minY) + minY;
		// Sets the y coordinate to 0 and then iterates it until it hits the maximum value
		for (int pixelX = 0; pixelX < image.height(); pixelX++)
		{
			// Map the x coordinate into the range minX to maxX
			
			// Does the same as the previous line but for the X axis
			double x0 = (pixelX / (double)image.width()) * (maxX - minX) + minX;

			// Implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			
			// This algorithm colours a single pixel and depending on it's location on the screen, colours it according to the Mandelbrot set calculation, the process is then looped for every pixel onscreen
			double X = 0;
			double Y = 0;
			int iteration = 0;
			int maximum_iteration = 200;

			while (X*X + Y*Y < 4 && iteration < maximum_iteration)
			{
				double xtemp = X*X - Y*Y + x0;
				Y = 2 * X*Y + y0;
				X = xtemp;
				iteration++;
			}
			

			// Sets the value for the HSV to RGB converter so that the colours are changed and displayed correctly onscreen
			HSVvalue value = HSVvalue(iteration, 1, 1);
			RGBvalue colourvalue = convertHSVToRGB(value);
			
			// If the iteration is above 200 it is set to zero so that the colour is black 
			if (iteration == 200)
			{
				colourvalue.R = 0;
				colourvalue.G = 0;
				colourvalue.B = 0;
			}
			

			// Write the pixel
			// Change the right-hand side of these three lines to write the desired pixel colour value
			image(pixelX, pixelY, 0, 0) = colourvalue.R; // red component
			image(pixelX, pixelY, 0, 1) = colourvalue.G; // green component
			image(pixelX, pixelY, 0, 2) = colourvalue.B; // blue component
		}

		// Uncomment this line to redisplay the image after each row is generated
		// Useful if your program is slow and you want to verify that it is actually doing something
		display.display(image);
	}

	// Display the complete image
	display.display(image);

	// Uncomment this line to save the image to disk
	//image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}

	return 0;
}
