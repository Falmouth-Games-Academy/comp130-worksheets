// Mandelbrot.cpp : Defines the entry point for the console application.
//

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
	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		// TODO: Map the y coordinate into the range minY to maxY
		double y0 = (pixelY / 800.0) * (maxY - minY) + minY;

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// TODO: Map the x coordinate into the range minX to maxX
			double x0 = (pixelX / 800.0) * (maxX - minX) + minX;
			double Xholder = 0;
			int iterations = 0;
			int maxIterations = 200;
			double Yholder = 0;

			// TODO: implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			// The code below simply fills the screen with random pixels

			
			while (iterations < maxIterations && Xholder * Xholder + Yholder * Yholder < 4)
			{
				double Xholdertemp = Xholder * Xholder - Yholder * Yholder + x0;
				Yholder = 2 * Xholder * Yholder + y0;
				Xholder = Xholdertemp;
				iterations++;
			}

			// Write the pixel
			// TODO: change the right-hand side of these three lines to write the desired pixel colour value
			int red = 0;
			int blue = 0;
			int green = 0;
			
			if (iterations <= 0)
			{
				blue = 255;
			}
			
			else if (iterations <= 60)
			{
				green = 255;
				blue = 255;
			}

			else if (iterations <= 120)
			{
				blue = 255;
				red = 255;
			}

			else if (iterations <= 180)
			{
				red = 255;
				green = 255;
			}
			
			else if (iterations <= 199)
			{
				red = 125;
				blue = 124;
				green = 124;
			}
			else
			{
				red = 0;
				blue = 0;
				green = 0;
			}
			
			image(pixelX, pixelY, 0, 0) = red; // red component
			image(pixelX, pixelY, 0, 1) = green; // green component
			image(pixelX, pixelY, 0, 2) = blue; // blue component

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
