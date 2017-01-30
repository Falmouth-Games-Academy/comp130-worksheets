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
	float imageWidth = image.width();
	int R =250, G = 0, B = 0;

	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		// TODO: Map the y coordinate into the range minY to maxY
		double y0 = ((pixelY / imageWidth) * (maxY - minY) + minY);

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// TODO: Map the x coordinate into the range minX to maxX
			double x0 = ((pixelX / imageWidth) * (maxX - minX) + minY);

			// TODO: implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			// The code below simply fills the screen with random pixels
			double x = 0.0;
			double y = 0.0;
			int iteration = 0;
			int max_iteration = 1000;

			while ((x*x + y*y < 2 * 2) && (iteration < max_iteration))
			{
				int xtemp = x*x - y*y + x0;
				y = 2 * x*y + y0;
				x = xtemp;
				iteration++;
			}

			// Write the pixel
			// TODO: change the right-hand side of these three lines to write the desired pixel colour value
			image(pixelX, pixelY, 0, 0) = R; // red component
			image(pixelX, pixelY, 0, 1) = G; // green component
			image(pixelX, pixelY, 0, 2) = B; // blue component

			if (iteration == max_iteration)
			{
				image(pixelX, pixelY, 0, 0) = 0; // red component
				image(pixelX, pixelY, 0, 1) = 0; // green component
				image(pixelX, pixelY, 0, 2) = 0; // blue component
			}
			else if (iteration < 200)
			{
				image(pixelX, pixelY, 0, 0) = 122; // red component
				image(pixelX, pixelY, 0, 1) = 20; // green component
				image(pixelX, pixelY, 0, 2) = 20; // blue component
			}
			else if (iteration < 600)
			{
				image(pixelX, pixelY, 0, 0) = 70; // red component
				image(pixelX, pixelY, 0, 1) = 30; // green component
				image(pixelX, pixelY, 0, 2) = 255; // blue component
			}
		}

		// Uncomment this line to redisplay the image after each row is generated
		// Useful if your program is slow and you want to verify that it is actually doing something
		//display.display(image);
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
