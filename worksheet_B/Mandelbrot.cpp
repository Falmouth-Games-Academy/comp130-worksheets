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
<<<<<<< HEAD
		double y0 = ((pixelY/800.0) * (maxY - minY) + minY);
=======
		double y0 = ((pixelY / image.width()) * (maxY - minY) + minY);
>>>>>>> 57551f56bbcf3ce3b86f5f0595e52701068c1f11

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// TODO: Map the x coordinate into the range minX to maxX
			double x0 = ((pixelX / 800.0) * (maxX - minX) + minX);

			// TODO: implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			// The code below simply fills the screen with random pixels
			int iteration = 0;
			int maxIteration = 200;
			double x = 0;
			double y = 0;

<<<<<<< HEAD
			while (iteration < maxIteration && (x*x) + (y*y) < 4)
			{
				double xTemp = (x*x) - (y*y) + x0;
				y = 2 * x * y + y0;
				x = xTemp;
				iteration++;
			}

			int red = 0;
			int green = 0;
			int blue = 0;
			int maxValue = 255;

			if (iteration <= 60)
			{
				green = maxValue;
				red = (iteration / 60) * maxValue;
			}

			else if (iteration <= 120)
			{
				red = maxValue;
				green = maxValue - (((iteration - 60) / 60) * maxValue);
			}

			else if (iteration <= 180)
			{
				blue = maxValue;
				green = maxValue - (((iteration - 120) / 60) * maxValue);
			}

			else if (iteration <= 199)
			{
				red = maxValue;
				blue = maxValue - (((iteration - 60) / 60) * maxValue);
			}

			else
			{
				red = 0;
				green = 0;
				blue = 0;
			}

			image(pixelX, pixelY, 0, 0) = red; // red component
			image(pixelX, pixelY, 0, 1) = green; // green component
			image(pixelX, pixelY, 0, 2) = blue; // blue component
		}

		// Uncomment this line to redisplay the image after each row is generated
		// Useful if your program is slow and you want to verify that it is actually doing something
		display.display(image);
=======
			int iteration = 0;
			int max_iteration = 1000;
			double x = 0.0;
			double y = 0.0;

			while ((x*x + y*y < 2 * 2) || iteration < max_iteration)
			{
				int x_storage = x*x - y*y + x0;
				y = 2 * x*y + y0;
				x = x_storage;
				iteration++;
			}

			// Write the pixel
			// TODO: change the right-hand side of these three lines to write the desired pixel colour value

			int red = 255;
			int green = 200;
			int blue = 180;

			image(pixelX, pixelY, 0, 0) = (red); // red component
			image(pixelX, pixelY, 0, 1) = (green); // green component
			image(pixelX, pixelY, 0, 2) = (blue); // blue component

			if (iteration < max_iteration)
			{
				image(pixelX, pixelY, 0, 0) = (0); // red component
				image(pixelX, pixelY, 0, 1) = (0); // green component
				image(pixelX, pixelY, 0, 2) = (0); // blue component
			}

			// Uncomment this line to redisplay the image after each row is generated
			display.display(image);
		}

>>>>>>> 57551f56bbcf3ce3b86f5f0595e52701068c1f11
	}

	// Display the complete image
	display.display(image);

	// Uncomment this line to save the image to disk
	image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}

	return 0;
}
