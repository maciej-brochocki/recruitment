#include <opencv2/opencv.hpp>
#include <vector>
#include <math.h>

using namespace cv;
using namespace std;

#include "findPerimeter.hpp"

void drawSegment(Mat* perimeter, cv::Point P0, cv::Point P1, cv::Point P2, cv::Point P3)
{
	double t0 = 0;
	double t1 = sqrt(sqrt((P1.x-P0.x)*(P1.x-P0.x) + (P1.y-P0.y)*(P1.y-P0.y))) + t0;
	double t2 = sqrt(sqrt((P2.x-P1.x)*(P2.x-P1.x) + (P2.y-P1.y)*(P2.y-P1.y))) + t1;
	double t3 = sqrt(sqrt((P3.x-P2.x)*(P3.x-P2.x) + (P3.y-P2.y)*(P3.y-P2.y))) + t2;
	double t, m1, m2;
	double A1_x, A1_y, A2_x, A2_y, A3_x, A3_y, B1_x, B1_y, B2_x, B2_y, C_x, C_y;

	int samples = (abs(P2.x-P1.x) + abs(P2.y-P1.y)) * 2; //worst case times 2 (from nyquist)

	perimeter->ptr<uchar>(P1.x)[P1.y] = 255;
	for (int i=0; i<samples; i++)
	{
		t = t1 + (t2-t1)*i/samples;

		m1 = (t1-t)/(t1-t0); m2 = (t-t0)/(t1-t0);
		A1_x = m1*P0.x + m2*P1.x; A1_y = m1*P0.y + m2*P1.y;

		m1 = (t2-t)/(t2-t1); m2 = (t-t1)/(t2-t1);
		A2_x = m1*P1.x + m2*P2.x; A2_y = m1*P1.y + m2*P2.y;

		m1 = (t3-t)/(t3-t2); m2 = (t-t2)/(t3-t2);
		A3_x = m1*P2.x + m2*P3.x; A3_y = m1*P2.y + m2*P3.y;

		m1 = (t2-t)/(t2-t0); m2 = (t-t0)/(t2-t0);
		B1_x = m1*A1_x + m2*A2_x; B1_y = m1*A1_y + m2*A2_y;

		m1 = (t3-t)/(t3-t1); m2 = (t-t1)/(t3-t1);
		B2_x = m1*A2_x + m2*A3_x; B2_y = m1*A2_y + m2*A3_y;

		m1 = (t2-t)/(t2-t1); m2 = (t-t1)/(t2-t1);
		C_x  = m1*B1_x + m2*B2_x; C_y  = m1*B1_y + m2*B2_y;

		perimeter->ptr<uchar>((int)C_x)[(int)C_y] = 255;
	}	
	perimeter->ptr<uchar>(P2.x)[P2.y] = 255;
}

void CatmullRom(Mat* perimeter, vector<cv::Point>& controlPoints)
{
	int s = controlPoints.size();
	for (int i=0; i<s; i++)
	{
		drawSegment(perimeter, controlPoints[i], controlPoints[(i+1)%s], controlPoints[(i+2)%s], controlPoints[(i+3)%s]);
	}
}

cv::Mat* findSmoothPerimeter(cv::Mat &mat, int segments) {
	int channels = mat.channels();

	int nRows = mat.rows;
	int nCols = mat.cols;

	Mat* perimeter = findPerimeter(mat);

	if ((channels != 1) || (segments < 4))
	{
		return perimeter;
	}

	vector<cv::Point> points;
	vector<cv::Point> controlPoints;

	//restore perimeter as a vector
	int i, j;
	for (i = 0; i < nRows; ++i) {
		for (j = 0; j < nCols; ++j) {
			if (perimeter->ptr<uchar>(i)[j]) //first point found
			{
				perimeterWalk(perimeter, i, j, points, nRows, nCols);

				*perimeter = Mat::zeros(nRows, nCols, CV_8U);

				//divide perimeter into segments
				for (int k=0; k<segments; k++)
				{
					int idx = points.size()*k/segments;
					controlPoints.push_back(points[idx]);
				}
				
				CatmullRom(perimeter, controlPoints);

				return perimeter;
			}
		}
	}

	return perimeter;
}

