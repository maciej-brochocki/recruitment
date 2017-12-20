#include <opencv2/opencv.hpp>
using namespace cv;

int similar(Vec3b ref, Vec3b p, int thr)
{
	return (!((ref[0]-thr > p[0]) || (p[0] > ref[0]+thr) || 
		(ref[1]-thr > p[1]) || (p[1] > ref[1]+thr) ||
		(ref[2]-thr > p[2]) || (p[2] > ref[2]+thr)));
}

void walk(cv::Mat &A, cv::Mat* walked, int i, int j, int M, int N, Vec3b ref, int thr) {
	Vec3b *a = A.ptr<Vec3b>(i);
	uchar *w = walked->ptr<uchar>(i);

	if (i < M - 1)
	{
		Vec3b *ap1 = A.ptr<Vec3b>(i+1);
		uchar *wp1 = walked->ptr<uchar>(i+1);
		if ((wp1[j] == 0) && similar(ref, ap1[j], thr))
		{
			wp1[j] = 255;
			walk(A, walked, i + 1, j, M, N, ref, thr);
		}
	}
	if (i > 0)
	{
		Vec3b *am1 = A.ptr<Vec3b>(i-1);
		uchar *wm1 = walked->ptr<uchar>(i-1);
		if ((wm1[j] == 0) && similar(ref, am1[j], thr))
		{
			wm1[j] = 255;
			walk(A, walked, i - 1, j, M, N, ref, thr);
		}
	}
	if (j < N - 1)
	{
		if ((w[j + 1] == 0) && similar(ref, a[j+1], thr))
		{
			w[j + 1] = 255;
			walk(A, walked, i, j + 1, M, N, ref, thr);
		}
	}
	if (j > 0)
	{
		if ((w[j - 1] == 0) && similar(ref, a[j-1], thr))
		{
			w[j - 1] = 255;
			walk(A, walked, i, j - 1, M, N, ref, thr);
		}
	}
}

cv::Mat* findRegion(cv::Mat &mat, int x, int y, int thr) {
	int channels = mat.channels();

	int nRows = mat.rows;
	int nCols = mat.cols;

	Mat* region = new Mat;
	*region = Mat::zeros(nRows, nCols, CV_8U);

	if ((channels != 3) || (x >= nRows) || (y >= nCols))
	{
		return region;
	}

	uchar *p = region->ptr<uchar>(x);
	p[y] = 255;
	Vec3b ref = mat.ptr<Vec3b>(x)[y];
	walk(mat, region, x, y, nRows, nCols, ref, thr);

	return region;
}

