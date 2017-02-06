// Mandelbrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
const double width = 800.0, height = 800.0;
// Took the code from the second comment on http://stackoverflow.com/questions/3018313/algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-both
typedef struct RgbColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RgbColor;

typedef struct HsvColor
{
	unsigned char h;
	unsigned char s;
	unsigned char v;
} HsvColor;

RgbColor HsvToRgb(HsvColor hsv)
{
	RgbColor rgb;
	unsigned char region, remainder, p, q, t;

	if (hsv.s == 0)
	{
		rgb.r = hsv.v;
		rgb.g = hsv.v;
		rgb.b = hsv.v;
		return rgb;
	}

	region = hsv.h / 43;
	remainder = (hsv.h - (region * 43)) * 6;

	p = (hsv.v * (255 - hsv.s)) >> 8;
	q = (hsv.v * (255 - ((hsv.s * remainder) >> 8))) >> 8;
	t = (hsv.v * (255 - ((hsv.s * (255 - remainder)) >> 8))) >> 8;

	switch (region)
	{
	case 0:
		rgb.r = hsv.v; rgb.g = t; rgb.b = p;
		break;
	case 1:
		rgb.r = q; rgb.g = hsv.v; rgb.b = p;
		break;
	case 2:
		rgb.r = p; rgb.g = hsv.v; rgb.b = t;
		break;
	case 3:
		rgb.r = p; rgb.g = q; rgb.b = hsv.v;
		break;
	case 4:
		rgb.r = t; rgb.g = p; rgb.b = hsv.v;
		break;
	default:
		rgb.r = hsv.v; rgb.g = p; rgb.b = q;
		break;
	}

	return rgb;
}

HsvColor RgbToHsv(RgbColor rgb)
{
	HsvColor hsv;
	unsigned char rgbMin, rgbMax;

	rgbMin = rgb.r < rgb.g ? (rgb.r < rgb.b ? rgb.r : rgb.b) : (rgb.g < rgb.b ? rgb.g : rgb.b);
	rgbMax = rgb.r > rgb.g ? (rgb.r > rgb.b ? rgb.r : rgb.b) : (rgb.g > rgb.b ? rgb.g : rgb.b);

	hsv.v = rgbMax;
	if (hsv.v == 0)
	{
		hsv.h = 0;
		hsv.s = 0;
		return hsv;
	}

	hsv.s = 255 * long(rgbMax - rgbMin) / hsv.v;
	if (hsv.s == 0)
	{
		hsv.h = 0;
		return hsv;
	}

	if (rgbMax == rgb.r)
		hsv.h = 0 + 43 * (rgb.g - rgb.b) / (rgbMax - rgbMin);
	else if (rgbMax == rgb.g)
		hsv.h = 85 + 43 * (rgb.b - rgb.r) / (rgbMax - rgbMin);
	else
		hsv.h = 171 + 43 * (rgb.r - rgb.g) / (rgbMax - rgbMin);

	return hsv;
}
// Initialise the image
CImg<unsigned char> image(width, height, 1, 3, 0);

// Display the image
CImgDisplay display(image, "Mandelbrot Set");

// Minimum and maximum coordinates for the fractal
double minX = -2, maxX = 1, minY = -1.5, maxY = 1.5;

// The sum of the X coordinates the result will be 3;
double maxXSum = maxX + minX * -1;

// The amount to move one pixel on any axis because it is a 3x3 square Divide it by the amount of pixels which is 800
double onePix = maxXSum / width;

// Calculate the X an Y coordinate of the center of the screen Starting is currentXc=0.5, currentYc=0.0
double currentXc = minX + width/2 * onePix;
double currentYc = maxY - width/2 * onePix;

// To have a referance of how many time I have zoomed in
int zoomLevel = 0;

// I put the image generation inside a function so I could run the function on mouse click.
// Zoom is the level of zoom we want to divide by, mouseX and mouseY is the mouse position of the click or the center of the screen
void generateImg(double zoom, double mouseX, double mouseY){
	// divide by zoom to make the coordinates smaller
	maxXSum = maxXSum/zoom;
	
	// Keep the coordinates of the initial click. I couldn't find a way to recalculate the coordinates after every click, because it would not center the next calculation
	if (zoomLevel < 2) {
		currentXc = minX + mouseX * onePix;
		currentYc = minY + mouseY * onePix;
	}
	// Half of the maxSum to know how much to set min and max coordinates based on the currentXc and currentYc coordinates
	double zoomOffsetSum = maxXSum / 2;
	// Recalculate the X and Y coordinates
	double minX = currentXc - zoomOffsetSum;
	double maxX = currentXc + zoomOffsetSum;
	double minY = currentYc - zoomOffsetSum;
	double maxY = currentYc + zoomOffsetSum;


	for (int pixelY = 0; pixelY < image.height(); pixelY++)
	{
		// Map the y coordinate into the range minY to maxY

		double y0 = (pixelY / height * (maxY - minY) + minY);

		
		for (int pixelX = 0; pixelX < image.width(); pixelX++)
		{
			// Map the x coordinate into the range minX to maxX
			double x0 = (pixelX / width * (maxX - minX) + minX);

			
			// Set the temp coordinate to x0 and y0
			double xi = x0;
			double yi = y0;
			// Save the iteration outside of the loop
			int i = 0;
			// Iterate for 200 if it is within the mandle brot set
			for (i = 0; i < 200 && xi*xi + yi*yi <= 4; i++)
			{
				// Calculate the next Coordinate
				double xcalc = xi * xi - yi * yi + x0;
				double ycalc = 2 * xi*yi + y0;
				// Set the current coordinate
				xi = xcalc;
				yi = ycalc;

			}
			// Convert the hsv to rgb
			HsvColor Color = {};
			Color.h = i;
			Color.s = 255;
			Color.v = 255;
			RgbColor RGBcolor = HsvToRgb(Color);
			// If it reaches 200 color the pixel black
			if (i >= 199) {
				image(pixelX, pixelY, 0, 0) = 0; // red component
				image(pixelX, pixelY, 0, 1) = 0; // green component
				image(pixelX, pixelY, 0, 2) = 0; // blue component
			}
			// Else do the hsv color.
			else {
				image(pixelX, pixelY, 0, 0) = RGBcolor.r; // red component
				image(pixelX, pixelY, 0, 1) = RGBcolor.g; // green component
				image(pixelX, pixelY, 0, 2) = RGBcolor.b; // blue component

			}


		}

		// Uncomment this line to redisplay the image after each row is generated
		// Useful if your program is slow and you want to verify that it is actually doing something
		//display.display(image);
	}

// Display the complete image
display.display(image);
}
int main()
{
	// Generate the first image with no zoom and set the center of the image
	generateImg(1, 400, 400);
	
	
	

	// Uncomment this line to save the image to disk
	//image.save_bmp("mandelbrot1.bmp");
	
	//Zoom variable
	double zoom = 2;

	// Wait for the window to be closed
	while (!display.is_closed())
	{
		// If left mouse button is clicked
		if (display.button() & 1) {
			// Set the mouse position during the click
			double mouseY = display.mouse_y();
			double mouseX = display.mouse_x();
			// Iterate the zoom Level
			zoomLevel++;
			// Generate the image with zoom and with the mouse click position in the center.
			generateImg(zoom, mouseX, mouseY);
			
		}
		display.wait();
	}

	return 0;
}
