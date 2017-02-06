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
	float imageHeight = image.height();
	int R =0, G = 0, B = 0; //initialising colours

	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		// Map the y coordinate into the range minY to maxY
		double y0 = ((pixelY / imageHeight) * (maxY - minY) + minY);

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// Map the x coordinate into the range minX to maxX
			double x0 = ((pixelX / imageWidth) * (maxX - minX) + minY);

			// Algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			// The code below simply fills the screen with random pixels
			double x = 0.0;
			double y = 0.0;

			double iteration = 0;
			int maxIteration = 200;

			while ((x*x + y*y < 2 * 2) && (iteration < maxIteration))
			{
				double xtemp = x*x - y*y + x0;
				y = 2 * x*y + y0;
				x = xtemp;
				++iteration;
			}

			// Break down of colour formula
			double i = iteration; // Used in the formula
			double loopPoint = 10; // Initial number of iterations before looping
			double loopMultiplier = 1.2; // Increase in the amount of iterations needed before looping

			if (iteration > loopPoint)
			// loops colours and then increases loop size each time
			{
				i = iteration - loopPoint;
				loopPoint *= loopMultiplier;
			}


			double firstRatio = (i) / (i + 1); // Ration of I(n) : I(n + 1)
			double secondRatio = (i + 1) / (i + 2); // Ratio of I(n + 1) : I(n + 2)
			double ratioDifference = secondRatio - firstRatio; // produces decimal values from 0.167, tending towards 0 when iteration = infinity
			double contrast = 6; // 0 = no contrast, 6 = max contrast (values higher than 6 results in rgb values above 255, thus looping)


			// subtracting from 255 inverses black and white, ratioDifference increases slower at higher iterations
			R = 255 - contrast*(255 * ratioDifference);
			G = 255 - contrast*(255 * ratioDifference);
			B = 255 - contrast*(255 * ratioDifference);


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
