// Mandelbrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int ZoomValue = 100;

int main()
{
	// Initialise the image
	CImg<unsigned char> image(800, 800, 1, 3, 0);

	// Display the image
	CImgDisplay display(image, "Mandelbrot Set");

	// Minimum and maximum coordinates for the fractal
	double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;
	bool Render = true;

	// Main loop
	while (true)
	{
		while (Render)
		{
			// Generate the image
			for (int pixelY = 0; pixelY < image.height(); pixelY++)
			{
				// Maps the y coordinate into the range minY to maxY
				double y0 = (pixelY / 800.0) * (maxY - minY) + minY;
				for (int pixelX = 0; pixelX < image.width(); pixelX++)
				{
					// Maps the x coordinate into the range minX to maxX
					double x0 = (pixelX / 800.0) * (maxX - minX) + minX;

					// Creates the Mandelbrot set fractal
					double xI = 0;
					double yI = 0;
					int iteration = 0;
					int max_iteration = 200;

					while (iteration < max_iteration && xI * xI + yI * yI < 4)			
					{
						double xtemp = xI * xI - yI * yI + x0;
						yI = 2 * xI * yI + y0;
						xI = xtemp;
						iteration++;
					}


					// HSV to RGB Converter
					double RedValue = 0;
					double GreenValue = 0;
					double BlueValue = 0;

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
					// Sets the pixel colour
					image(pixelX, pixelY, 0, 0) = RedValue; // red component
					image(pixelX, pixelY, 0, 1) = GreenValue; // green component
					image(pixelX, pixelY, 0, 2) = BlueValue; // blue component
				}

				// Uncomment this line to redisplay the image after each row is generated
				// Useful if your program is slow and you want to verify that it is actually doing something
				//display.display(image);
			}

			// Display the complete image
			display.display(image);

			// Uncomment this line to save the image to disk
			//image.save_bmp("mandelbrot.bmp");


			Render = false;
		}
			if (display.button() & 1) { // Left button clicked.

				// Gets the position of the mouse
				int MousePositionX = display.mouse_x();
				int MousePositionY = display.mouse_y();

				// Gets the current range and changes it depending on the zoom value
				double FractalRange = maxX - minX;
				double RangeChange = FractalRange / ZoomValue;

				// Uses the mouse position to create a center point for the new fractal
				double XPoint = minX + ((FractalRange / image.height()) * MousePositionX);
				double YPoint = minY + ((FractalRange / image.height()) * MousePositionY);

				// Changes the min and max values to generate a new fractal
				minX = XPoint - RangeChange;
				maxX = XPoint + RangeChange;

				minY = YPoint - RangeChange;
				maxY = YPoint + RangeChange;

				Render = true;
			}
		
		//return 0;
	}
}


