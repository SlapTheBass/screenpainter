#include "colorFinder.h"

colorFinder::colorFinder()
{
}

colorFinder::~colorFinder()
{
}


std::vector<std::vector<int>> colorFinder::findColour(cv::Mat img)
{
	cv::Mat imgHSV;
	cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);

	for (int i = 0; i < colors.size(); i++)
	{
		cv::Scalar lowerLim(colors[i][0], colors[i][2], colors[i][4]); //remember to do this scalars in the loop
		cv::Scalar upperLim(colors[i][1], colors[i][3], colors[i][5]); //so values from trackbars will be updated
		cv::Mat mask;
		cv::inRange(imgHSV, lowerLim, upperLim, mask);

		drawingPoint = contours.getContours(mask, img);

		if (drawingPoint.x != 0 && drawingPoint.y !=0)
			points.push_back({ drawingPoint.x, drawingPoint.y, i });		
	}
	return points;
}

void colorFinder::drawOnCanvas(std::vector<std::vector<int>> points, std::vector<cv::Scalar> colorValues, cv::Mat img)
{
	for (int i = 0; i < points.size(); i++)
	{
		cv::circle(img, cv::Point((points[i][0]), (points[i][1])), 4, colorValues[points[i][2]], cv::FILLED);
	}
}


std::vector<cv::Scalar> colorFinder::getValues()
{
	return colorValues;
}