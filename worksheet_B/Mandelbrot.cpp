#include "stdafx.h"

float ImageWidth = 800.0;
float ImageHeight = 800.0;

int main()
{
	// Initialise the image
	CImg<unsigned char> image(ImageWidth, ImageHeight, 1, 3, 0);

	// Display the image
	CImgDisplay display(image, "Mandelbrot Set");

	// Minimum and maximum coordinates for the fractal
	const double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;

	// Generate the image
	for (int PixelY = 0; PixelY < ImageHeight; PixelY++)
	{
		// Maps the y coordinate into the range minY to maxY
		double y0 = ((PixelY / ImageWidth) * (maxY - minY) + minY);

		for (int PixelX = 0; PixelX < ImageWidth; PixelX++)
		{
			// Maps the x coordinate into the range minX to maxX
			double x0 = ((PixelX / ImageWidth) * (maxX - minX) + minX);

			// The algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			// http://rijndael.ece.vt.edu/challenge/codesigndata/2012_assign.pdf [online at 30/01/2017]
			double x = 0;
			double y = 0;
			int Iteration = 0;
			int MaxIteration = 200;
			while ((x * x) + (y * y) < 4 && Iteration < MaxIteration)
			{
				double XTemp = (x * x) - (y * y) + x0;
				y = 2 * x * y + y0;
				x = XTemp;
				Iteration++;
			}

			//Converts the colours from HSV to RGB
			// http://chaosinmotion.com/blog/?p=878 [online at 30/01/2017]
			int MaxColourValue = 255;
			int MinColourValue = 0;
			int Red = 0;
			int Green = 0;
			int Blue = 0;

			if (Iteration <= 60)
			{
				Blue = MaxColourValue;
				Green = (Iteration / 60) * MaxColourValue;
			}
			else if (Iteration <= 120)
			{
				Blue = MaxColourValue - (((Iteration - 60) / 60) * MaxColourValue);
				Green = MaxColourValue;
			}
			else if (Iteration <= 180)
			{
				Red = MaxColourValue;
				Blue = ((Iteration - 120) / 60) * MaxColourValue;
			}
			else if (Iteration <= 199)
			{
				Red = MaxColourValue - (((Iteration - 60) / 60) * MaxColourValue);
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
			image(PixelX, PixelY, 0, 0) = Red; // red component
			image(PixelX, PixelY, 0, 1) = Green; // green component
			image(PixelX, PixelY, 0, 2) = Blue; // blue component
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
