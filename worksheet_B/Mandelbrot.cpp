#include "stdafx.h"

float ImageWidth = 800.0;
float ImageHeight = 800.0;

int main()
{
	// Initialise the image
	CImg<unsigned char> image(800, 800, 1, 3, 0);

	// Display the image
	CImgDisplay display(image, "Mandelbrot Set");

	// Minimum and maximum coordinates for the fractal
	const double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;

	// Generate the image
	for (int pixelY = 0; pixelY < ImageHeight; pixelY++)
	{
		// Maps the y coordinate into the range minY to maxY
		double y0 = ((pixelY / ImageWidth) * (maxY - minY) + minY);

		for (int pixelX = 0; pixelX < ImageWidth; pixelX++)
		{
			// Maps the x coordinate into the range minX to maxX
			double x0 = ((pixelX / ImageWidth) * (maxX - minX) + minX);

			// The algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			// http://rijndael.ece.vt.edu/challenge/codesigndata/2012_assign.pdf [online at 30/01/2017]
			double x = 0;
			double y = 0;
			int iteration = 0;
			int MaxIteration = 200;
			while ((x * x) + (y * y) < 4 && iteration < MaxIteration)
			{
				double xtemp = (x * x) - (y * y) + x0;
				y = 2 * x * y + y0;
				x = xtemp;
				iteration++;
			}

			//Converts the colours from HSV to RGB
			int MaxColourValue = 255;
			int MinColourValue = 0;
			int Red = 0;
			int Green = 0;
			int Blue = 0;

			if (iteration <= 60)
			{
				Blue = MaxColourValue;
				Green = (iteration / 60) * MaxColourValue;
			}
			else if (iteration <= 120)
			{
				Blue = MaxColourValue - (((iteration - 60) / 60) * MaxColourValue);
				Green = MaxColourValue;
			}
			else if (iteration <= 180)
			{
				Red = MaxColourValue;
				Blue = ((iteration - 120) / 60) * MaxColourValue;
			}
			else if (iteration <= 199)
			{
				Red = MaxColourValue - (((iteration - 60) / 60) * MaxColourValue);
				Blue = MaxColourValue;
			}
			else
			{
				Red = MinColourValue;
				Green = MinColourValue;
				Blue = MinColourValue;
			}

			// Write the pixel
			// The right-hand side of these three lines writes the desired pixel colour value
			image(pixelX, pixelY, 0, 0) = Red; // red component
			image(pixelX, pixelY, 0, 1) = Green; // green component
			image(pixelX, pixelY, 0, 2) = Blue; // blue component
		}

		//display.display(image);
	}

	// Display the complete image
	display.display(image);
	// Save the image to disk
	image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}

	return 0;
}
