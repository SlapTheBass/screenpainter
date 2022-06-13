#pragma once
#include "contourFinder.h"
class colorFinder
{
public:
	colorFinder();
	~colorFinder();

	std::vector<std::vector<int>> findColour(cv::Mat img);
	std::vector<cv::Scalar> getValues();
	void drawOnCanvas(std::vector<std::vector<int>> points, std::vector<cv::Scalar> colorValues, cv::Mat img);
private:
	std::vector<std::vector<int>> colors{ {145,179,154,255,113,255}, //red
										  {47,102,123,255,69,163},   //green
									      {61,130,134,255,113,198} };//blue

	contourFinder contours;
	cv::Point drawingPoint = { 0,0 };

	std::vector<std::vector<int>> points;

	std::vector<cv::Scalar> colorValues{ {0,0,255},  //red
										 {0,255,0},  //green
									     {255,0,0} };//blue
};

