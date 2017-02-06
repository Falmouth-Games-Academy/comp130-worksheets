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
		
		double y0 = (pixelY / 800.0) * (maxY - minY) + minY;

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
		
			double x0 = (pixelX / 800.0) * (maxX - minX) + minX;

			double Xi = 0;
			double Yi = 0;
			int Iterations = 0;
			int MaxIterations = 200;
			while (Iterations < MaxIterations && Xi * Xi + Yi + Yi < 4)
			{
				
				double temp = Xi * Xi - Yi * Yi + x0;
				Yi = 2 * Xi * Yi + y0;
				Xi = temp;
				Iterations++;
			}
			// Write the pixel
			int Red = 0;
			int Green = 0;
			int Blue = 0;

			if (Iterations <= 60)
			{
				Red = 255;
				Green = (Iterations / 60.0) * 255;
			}
			else if (Iterations <= 120)
			{
				Red = 255 - (((Iterations - 60) / 60.0) * 255);
				Green = 255;
			}
			else if (Iterations <= 180)
			{
				Green = 255;
				Blue = ((Iterations - 120) / 60.0) * 255;
			}
			else if (Iterations <= 199)
			{
				Green = 255 - (((Iterations - 60) / 60.0) * 255);
				Blue = 255;
			}
			else
			{
				Red = 0;
				Green = 0;
				Blue = 0;
			}
			image(pixelX, pixelY, 0, 0) = Red; // red component
			image(pixelX, pixelY, 0, 1) = Green; // green component
			image(pixelX, pixelY, 0, 2) = Blue; // blue component
		}

		// Uncomment this line to redisplay the image after each row is generated
		// Useful if your program is slow and you want to verify that it is actually doing something
		display.display(image);
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
