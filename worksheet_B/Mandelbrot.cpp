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
	int R =0, G = 0, B = 0; //initialising colours

	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		// Map the y coordinate into the range minY to maxY
		double y0 = ((pixelY / imageWidth) * (maxY - minY) + minY);

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// Map the x coordinate into the range minX to maxX
			double x0 = ((pixelX / imageWidth) * (maxX - minX) + minY);

			// Algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			// The code below simply fills the screen with random pixels
			double x = 0.0;
			double y = 0.0;
			int previousPreviousIteration = 0;
			int previousIteration = 0;
			double iteration = 0;
			int maxIteration = 255; // Keep this value as it is used to generate RGB values

			while ((x*x + y*y < 2 * 2) && (iteration < maxIteration))
			{
				double xtemp = x*x - y*y + x0;
				y = 2 * x*y + y0;
				x = xtemp;
				iteration++;
			}

			// Setting colours

			// First number changes colours, iteration formula cycles through shades.
			R = 5 - (255 / 1 / (iteration / (iteration + 1) - (iteration + 1) / (iteration + 2)));
			G = 10 - (255 / 1 / (iteration / (iteration + 1) - (iteration + 1) / (iteration + 2)));
			B = 135 - (255 / 1 / (iteration / (iteration + 1) - (iteration + 1) / (iteration + 2)));


			// Applies chosen colours
			image(pixelX, pixelY, 0, 0) = R; // red component
			image(pixelX, pixelY, 0, 1) = G; // green component
			image(pixelX, pixelY, 0, 2) = B; // blue component
		}

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
