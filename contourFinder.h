#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
class contourFinder
{
public:
	contourFinder();
	~contourFinder();

	cv::Point getContours(cv::Mat img_in, cv::Mat img_out);
	void setPoints(cv::Rect bound);

private:
	std::vector<std::vector<cv::Point >> contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::Point drawingPoint = { 0, 0 };
};

