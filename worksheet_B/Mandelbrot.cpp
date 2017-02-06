// Mandelbrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

/*
Struct definitions and hsv2rgb() function below courtesy of 
http://stackoverflow.com/questions/3018313/algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-both
*/

typedef struct {
	double r;       // percent
	double g;       // percent
	double b;       // percent
} rgb;

typedef struct {
	double h;       // angle in degrees
	double s;       // percent
	double v;       // percent
} hsv;

static rgb   hsv2rgb(hsv in);

rgb hsv2rgb(hsv in)
{
	double      hh, p, q, t, ff;
	long        i;
	rgb         out;

	if (in.s <= 0.0) {       // < is bogus, just shuts up warnings
		out.r = in.v;
		out.g = in.v;
		out.b = in.v;
		return out;
	}
	hh = in.h;
	if (hh >= 360.0) hh = 0.0;
	hh /= 60.0;
	i = (long)hh;
	ff = hh - i;
	p = in.v * (1.0 - in.s);
	q = in.v * (1.0 - (in.s * ff));
	t = in.v * (1.0 - (in.s * (1.0 - ff)));

	switch (i) {
	case 0:
		out.r = in.v;
		out.g = t;
		out.b = p;
		break;
	case 1:
		out.r = q;
		out.g = in.v;
		out.b = p;
		break;
	case 2:
		out.r = p;
		out.g = in.v;
		out.b = t;
		break;

	case 3:
		out.r = p;
		out.g = q;
		out.b = in.v;
		break;
	case 4:
		out.r = t;
		out.g = p;
		out.b = in.v;
		break;
	case 5:
	default:
		out.r = in.v;
		out.g = p;
		out.b = q;
		break;
	}
	return out;
}

int main()
{
	// Initialise the image
	CImg<unsigned char> image(800, 800, 1, 3, 0);

	// Display the image
	CImgDisplay display(image, "Mandelbrot Set");

	// Minimum and maximum coordinates for the fractal
			double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;

	// Zooming variables
			bool zoomIn;
			bool recalculateBounds = false;
			double zoomMagnitude = 1.5;
			double currentSideLength = maxX - minX;
			const double originalSideLength = currentSideLength;

while (true)
	{

		// Requires holding the button down, odd event handling
		if (GetKeyState(VK_LBUTTON) < 0)
		{
			zoomIn = true;
			recalculateBounds = true;
		}
		else if (GetKeyState(VK_RBUTTON) < 0)
		{
			zoomIn = false;
			recalculateBounds = true;
		}

		if (recalculateBounds)
		{
			recalculateBounds = false;

			// Get mouse position
			POINT mousePosition;
			GetCursorPos(&mousePosition);

			// Get local in-window coordinates of mouse cursor for zoom target
			double localPositionX = mousePosition.x - display._window_x;
			double localPositionY = mousePosition.y - display._window_y;

			// Compare against window dimensions to determine mouse cursor position in terms of data bounds
			double ratioX = localPositionX / display._window_width;
			double dataRangeCursorPositionX = (ratioX * currentSideLength) + minX;

			double ratioY = localPositionY / display._window_height;
			double dataRangeCursorPositionY = (ratioY * currentSideLength) + minY;

			// Apply zoom modifier to alter currentSideLength
			if (zoomIn)
				currentSideLength /= zoomMagnitude;
			else
				currentSideLength *= zoomMagnitude;

			// Determine new minX, minY values for zoomed section with mouse cursor as new centre
			minX = dataRangeCursorPositionX - (currentSideLength / 2);
			minY = dataRangeCursorPositionY - (currentSideLength / 2);

			// Determine new maxX, maxY values
			maxX = minX + currentSideLength;
			maxY = minY + currentSideLength;

			// Display zoom level to console
			double zoomLevel = originalSideLength / currentSideLength;
			std::cout << "Zoom magnitude: " << zoomLevel << std::endl;
		}

			// Generate the image
		for (double pixelY = 0; pixelY < image.height(); pixelY++)
		{
			// Map the y coordinate into the range minY to maxY
			double y0 = (pixelY / image.height()) * (maxY - minY) + minY;

			for (double pixelX = 0; pixelX < image.width(); pixelX++)
			{
				// Map the x coordinate into the range minX to maxX
				double x0 = (pixelX / image.width()) * (maxX - minX) + minX;

				// Algorithm to colour a single pixel (x0, y0) of the Mandelbrot set fractal

				double x = 0;
				double y = 0;
				int i = 0;

				while (x*x + y*y < 4 && i < 200)
				{
					double xTemp = x*x - y*y + x0;
					y = (2.0 * x * y) + y0;
					x = xTemp;
					i++;
				}

				// Write the pixel
				rgb currentRGB;

				if (i >= 200)										// Upper limit of 200 to catch outliers
				{
					currentRGB = { 0.0, 0.0, 0.0 };					// Black specified for outlying values of i
				}
				else
				{
					hsv currentHSV = { i, 1.0, 1.0 };				// Magic numbers for saturation and value implicit in worksheet outline
					currentRGB = hsv2rgb(currentHSV);
				}

				image(pixelX, pixelY, 0, 0) = currentRGB.r * 255.0;	// Don't know why the hsv2rgb() function wouldn't do this?
				image(pixelX, pixelY, 0, 1) = currentRGB.g * 255.0;	// But it only returns a value in range 0.0-1.0
				image(pixelX, pixelY, 0, 2) = currentRGB.b * 255.0;	// *255.0 to modify to standard rgb scale
																	// Figured it out I think... It's because the given s, v = 1 == 100% should have entered 100 for a value of 1!

			}

			// Uncomment this line to redisplay the image after each row is generated
			display.display(image);
		}
		
		// Display the complete image
		// display.display(image);

		// Uncomment this line to save the image to disk
		//image.save_bmp("mandelbrot.bmp");

		// Wait for the window to be closed

/*
		// Left commented out to allow catching the mouse button down event
		while (!display.is_closed())
		{
			display.wait();
		}
*/

	}

	return 0;
}
