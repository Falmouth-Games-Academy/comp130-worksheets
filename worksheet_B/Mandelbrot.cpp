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

			// TODO: implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			// The code below simply fills the screen with random pixels
			double xI = 0;
			double yI = 0;
			int iteration = 0;
			int max_iteration = 200;

			while (iteration < max_iteration && xI * xI + yI + yI < 4)
			{
				double xtemp = xI * xI - yI * yI + x0;
				yI = 2 * xI * yI + y0;
				xI = xtemp;
				iteration++;
			}

			// Write the pixel
			int RedValue = 0;
			int GreenValue = 0;
			int BlueValue = 0;

			if (iteration <= 60)
			{
				RedValue = 255;
				GreenValue = (iteration / 60.0) * 255;
			}
			else if (iteration <= 120)
			{
				RedValue = 255 - (((iteration - 60) / 60.0) * 255);
				GreenValue = 255;
			}
			else if (iteration <= 180)
			{
				GreenValue = 255;
				BlueValue = ((iteration - 120) / 60.0) * 255;
			}
			else if (iteration <= 199)
			{
				GreenValue = 255 - (((iteration - 60) / 60.0) * 255);
				BlueValue = 255;
			}
			else
			{
				RedValue = 0;
				GreenValue = 0;
				BlueValue = 0;
			}
				// TODO: change the right-hand side of these three lines to write the desired pixel colour value
					image(pixelX, pixelY, 0, 0) = RedValue; // red component
					image(pixelX, pixelY, 0, 1) = GreenValue; // green component
					image(pixelX, pixelY, 0, 2) = BlueValue; // blue component
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


