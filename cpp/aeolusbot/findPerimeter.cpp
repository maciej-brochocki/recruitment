#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

void perimeterWalk(cv::Mat* perimeter, int i, int j, vector<cv::Point>& points, int nRows, int nCols)
{
	points.push_back(cv::Point(i,j));
	perimeter->ptr<uchar>(i)[j] = 0;

	if (j<nCols-1)
	{
 		if (perimeter->ptr<uchar>(i)[j+1])
		{
			perimeterWalk(perimeter, i, j+1, points, nRows, nCols);
		}
	}
	if ((i<nRows-1) && (j<nCols-1))
	{
 		if (perimeter->ptr<uchar>(i+1)[j+1])
		{
			perimeterWalk(perimeter, i+1, j, points, nRows, nCols);
		}
	}
	if (i<nRows-1)
	{
 		if (perimeter->ptr<uchar>(i+1)[j])
		{
			perimeterWalk(perimeter, i+1, j, points, nRows, nCols);
		}
	}
	if ((i<nRows-1) && (j>0))
	{
 		if (perimeter->ptr<uchar>(i+1)[j-1])
		{
			perimeterWalk(perimeter, i+1, j-1, points, nRows, nCols);
		}
	}
	if (j>0)
	{
 		if (perimeter->ptr<uchar>(i)[j-1])
		{
			perimeterWalk(perimeter, i, j-1, points, nRows, nCols);
		}
	}
	if ((i>0) && (j>0))
	{
 		if (perimeter->ptr<uchar>(i-1)[j-1])
		{
			perimeterWalk(perimeter, i-1, j-1, points, nRows, nCols);
		}
	}
	if (i>0)
	{
 		if (perimeter->ptr<uchar>(i-1)[j])
		{
			perimeterWalk(perimeter, i-1, j, points, nRows, nCols);
		}
	}
	if ((i>0) && (j<nCols-1))
	{
 		if (perimeter->ptr<uchar>(i-1)[j+1])
		{
			perimeterWalk(perimeter, i-1, j+1, points, nRows, nCols);
		}
	}
}

cv::Mat* findPerimeter(cv::Mat &mat) {
	int channels = mat.channels();

	int nRows = mat.rows;
	int nCols = mat.cols;

	Mat* perimeter = new Mat;
	*perimeter = Mat::zeros(nRows, nCols, CV_8U);

	if (channels != 1)
	{
		return perimeter;
	}

	int i, j;
	for (i = 0; i < nRows; ++i) {
		for (j = 0; j < nCols; ++j) {
			if (mat.ptr<uchar>(i)[j])
			{
				if ((i==0) || (j==0) || (i==nRows-1) || (j==nCols-1))
				{
					perimeter->ptr<uchar>(i)[j] = 255;
				}
				else
				{
					if (!(mat.ptr<uchar>(i+1)[j] && mat.ptr<uchar>(i-1)[j] && mat.ptr<uchar>(i)[j+1] && mat.ptr<uchar>(i)[j-1]))
					{
						perimeter->ptr<uchar>(i)[j] = 255;
					}
				}
			}
		}
	}

	vector<cv::Point> points;

	for (i = 0; i < nRows; ++i) {
		for (j = 0; j < nCols; ++j) {
			if (perimeter->ptr<uchar>(i)[j]) //first point found
			{
				perimeterWalk(perimeter, i, j, points, nRows, nCols);

				*perimeter = Mat::zeros(nRows, nCols, CV_8U);
				vector<cv::Point>::iterator it;
				for (it = points.begin(); it != points.end(); it++)
				{
					perimeter->ptr<uchar>(it->x)[it->y] = 255;
				}

				return perimeter;
			}
		}
	}

	return perimeter;
}

