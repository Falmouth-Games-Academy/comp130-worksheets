#include "stdafx.h"

int main()
{
	// Initialise the image
	CImg<unsigned char> image(800, 800, 1, 3, 0);

	// Display the image
	CImgDisplay display(image, "Mandelbrot Set");

	// Minimum and maximum coordinates for the fractal
	const double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;

	// Generate the image
	for (int pixelY = 0; pixelY < 800.0; pixelY++)
	{
		// Maps the y coordinate into the range minY to maxY
		double y0 = ((pixelY / 800.0) * (maxY - minY) + minY);

		for (int pixelX = 0; pixelX < 800.0; pixelX++)
		{
			// Maps the x coordinate into the range minX to maxX
			double x0 = ((pixelX / 800.0) * (maxX - minX) + minX);

			// The algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
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
			int Red = 0;
			int Green = 0;
			int Blue = 0;

			if (iteration <= 60)
			{
				Red = 255;
				Green = (iteration / 60) * 255;
			}
			else if (iteration <= 120)
			{
				Red = 255 - (((iteration - 60) / 60) * 255);
				Green = 255;
			}
			else if (iteration <= 180)
			{
				Green = 255;
				Blue = ((iteration - 120) / 60) * 255;
			}
			else if (iteration <= 199)
			{
				Green = 255 - (((iteration - 60) / 60) * 255);
				Blue = 255;
			}
			else
			{
				Red = 0;
				Green = 0;
				Blue = 0;
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
