// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

float ImageWidth = 800.0;
float ImageHeight = 800.0;
int Iteration = 0;
int maxIteration = 200;
int Red = 0;
int Green = 0;
int Blue = 0;
int minValue = 0;
int maxValue = 255;

int main()
{
	// Initialise the image
	CImg<unsigned char> image(ImageHeight, ImageWidth, 1, 3, 0);
	// Display the image
	CImgDisplay display(image, "Mandelbrot Set");
	// Minimum and maximum coordinates for the fractal
	const double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;
	// Generate the image
	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		//Map the y coordinate into the range minY to maxY0
		double y0 = ((pixelY / ImageWidth) * (maxY - minY) + minY);
		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			//Map the x coordinate into the range minX to maxX
			double x0 = ((pixelX / ImageWidth) * (maxX - minX) + minX);
			//implement the algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal
			// The code below simply fills the screen with random pixels
			double x = 0;
			double y = 0;
			int Iteration = 0;
			int maxIteration = 200;
			while (Iteration < maxIteration && (x*x + (y*y) < 4)) {
				double xTemp = (x*x - y*y + x0);
				y = 2 * x*y + y0;
				x = xTemp;
				Iteration = Iteration + 1;
			}
			int Red = 0;
			int Green = 0;
			int Blue = 0;
			int minValue = 0;
			int maxValue = 255;
			if (Iteration <= 60)
			{
				Green = maxValue;
				Red = (Iteration / 60) * maxValue;
			}
			else if (Iteration <= 120)
			{
				Red = maxValue;
				Green = maxValue - (((Iteration - 60) / 60) * maxValue);
			}
			else if (Iteration <= 180)
			{
				Blue = maxValue;
				Green = maxValue - (((Iteration - 120) / 60) * maxValue);
			}
			else if (Iteration <= 199)
			{
				Red = maxValue;
				Blue = maxValue - (((Iteration - 60) / 60) * maxValue);
			}
			else
			{
				Red = 0;
				Green = 0;
				Blue = 0;
			}
			// Write the pixel
			//change the right-hand side of these three lines to write the desired pixel colour value
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
	//image.save_bmp("mandelbrot.bmp");
	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}
    return 0;
}

