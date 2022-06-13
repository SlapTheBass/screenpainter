#include <iostream>
#include "colorFinder.h"


int main(int argc, char** argv)
{
	cv::Mat frame;
	cv::VideoCapture cap;
	colorFinder cFinder;
	std::vector<std::vector<int>> points;

	if (argc == 1)
		cap.open(0);
	else
		cap.open(argv[1]);

	if (!cap.isOpened())
	{
		std::cerr << "Failed to open the stream" << std::endl;
		return -1;
	}

	while (true)
	{
		cap.read(frame);
		cv::flip(frame, frame, +1);
		points = cFinder.findColour(frame);
		cFinder.drawOnCanvas(points, cFinder.getValues(), frame);
		cv::imshow("camera", frame);
		if (cv::waitKey(1) == 27)
			break;
	}
}

