#include "contourFinder.h"

contourFinder::contourFinder()
{
}

contourFinder::~contourFinder()
{
}

cv::Point contourFinder::getContours(cv::Mat img_in, cv::Mat img_out)
{
	cv::findContours(img_in, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	std::vector<std::vector<cv::Point>> conPoly(contours.size());
	std::vector<cv::Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		int area = cv::contourArea(contours[i]);

		if (area > 100)
		{
			float peri = cv::arcLength(contours[i], true);
			cv::approxPolyDP(contours[i], conPoly[i], 0.01 * peri, true);

			boundRect[i] = cv::boundingRect(conPoly[i]);

			cv::rectangle(img_out, boundRect[i].tl(), boundRect[i].br(), cv::Scalar(0, 255, 0), 3);
			setPoints(boundRect[i]);
			return drawingPoint;
		}
	}
}

void contourFinder::setPoints(cv::Rect bound)
{
	drawingPoint.x = bound.x + bound.width / 2;
	drawingPoint.y = bound.y;
}
