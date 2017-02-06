// Mandelbrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

int colourChoose(double iteration, int colourBeingPicked)
{
	int colour;

	//Picks the shade of the colour based on the number of iterations that were perfomed. 
	//colour =  colourBeingPicked - (255 / 1 / (iteration / (iteration + 1) - (iteration + 1) / (iteration + 2)));

	if (iteration > 200)
	{
		colour = colourBeingPicked / 10;
	}
	else
	{
		colour = colourBeingPicked;
	}

	return colour;
}

int main()
{
	// Initialise the image
	CImg<unsigned char> image(800, 800, 1, 3, 0);

	// Display the image
	CImgDisplay display(image, "Mandelbrot Set");

	// Minimum and maximum coordinates for the fractal
	const double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;

	//Uses the width of the image to generate the y0 and the x0.
	float widthOfImage = image.width();
	//Used to give a base colour to draw the mendelbrot fractal.
	int red = 128;
	int green = 0;
	int blue = 128;

	// Generate the image
	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		double y0 = (pixelY / widthOfImage) * (maxY - minY) + minY;

		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			double x0 = (pixelX / widthOfImage) * (maxX - minX) + minX;
			
			double x = 0.0;
			double y = 0.0;
			double iteration = 0;
			int MaxIteration = 255;

			//The "Escapte time" algorithm. 
			while ((x*x + y*y < 2 * 2) && (iteration < MaxIteration))
			{
				double xTemp = x*x - y*y + x0;
				y = 2 * x*y + y0;
				x = xTemp;
				iteration++;
			}
			
			
			image(pixelX, pixelY, 0, 0) = colourChoose(iteration, red); // red component
			image(pixelX, pixelY, 0, 1) = colourChoose(iteration, green); // green component
			image(pixelX, pixelY, 0, 2) = colourChoose(iteration ,blue); // blue component
			
		}

	}

	// Display the complete image
	display.display(image);

	
	image.save_bmp("mandelbrot.bmp");

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		display.wait();
	}

	return 0;
}
