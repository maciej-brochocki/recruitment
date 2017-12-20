#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

#include "findRegion.hpp"
#include "findPerimeter.hpp"
#include "findSmoothPerimeter.hpp"
#include "command.hpp"

void show_mat(const cv::Mat &image, std::string const &win_name);
void serialize(cv::Mat &mat);

void help() {
	printf("usage: gfx_api <Image_Path> [COMMAND]\n");
	printf(" supported COMMANDs:\n");
	printf("  R x y t        - FIND_REGION starting at (x,y) use t threshold for similarity\n");
	printf("  P              - FIND_PERIMETER\n");
	printf("  I              - DISPLAY_IMAGE\n");
	printf("  X              - DISPLAY_PIXELS\n");
	printf("  S <Image_Path> - SAVE_PIXELS\n");
	printf("  T              - TEXT_OUTPUT\n");
	printf("  O s            - FIND_SMOOTH_PERIMETER by dividing perimeter into s equal segments\n");
}

int main(int argc, char **argv) {
    if (argc < 3) {
        help();
        return -1;
    }

    Mat image;
    image = imread(argv[1], 1);

    if (!image.data) {
        printf("No image data (warning: OpenCV recognize files by extensions)\n");
        return -1;
    }

	Mat* pixels = new Mat;
	*pixels = Mat::zeros(image.rows, image.cols, CV_8U);
	Mat* pixels2;

/*	vector<Command*> commands;
	Command* c;

	for (int i = 2; i < argc; i++)
	{
		switch(argv[i][0])
		{
			case 'R':
				c = new FindRegionCommand();
				break;
			case 'P':
				c = new FindPerimeterCommand();
				break;
			case 'I':
				c = new DisplayImageCommand();
				break;
			case 'X':
				c = new DisplayPixelsCommand();
				break;
			case 'S':
				c = new SavePixelsCommand();
				break;
			case 'T':
				c = new TextOutputCommand();
				break;
			case 'O':
				c = new FindSmoothPerimeterCommand();
				break;
			default:
				help();
				return -1;
		}
		int params = c->parametersNeeded();
		if (params)
		{
			if (i+params >= argc)
			{
				help();
				return -1;
			}
			c->parseParameters(&argv[i+1]);
			i += params;
		}
		commands.push_back(c);
	}

	vector<Mat*> objects;
	objects.push_back(NULL);
	objects.push_back(&image);
	objects.push_back(pixels);

	vector<Command*>::iterator it;
	for (it = commands.begin(); it != commands.end(); it++)
	{
		if ((*it)->getInputType() == (*it)->getOutputType())
		{
			Mat* tmp = ;
		}
		else
		{
			(*it)->execute(objects[(*it)->getInputType()], objects[(*it)->getOutputType()]);
		}
	}*/

	int x, y, t, s;
	for (int i = 2; i < argc; i++)
	{
		switch(argv[i][0])
		{
			case 'R':
				if (i+3 >= argc)
				{
					help();
					return -1;
				}
				x = atoi(argv[++i]);
				y = atoi(argv[++i]);
				t = atoi(argv[++i]);
				delete pixels;
				pixels = findRegion(image, x, y, t);
				break;
			case 'P':
				pixels2 = pixels;
				pixels = findPerimeter(*pixels);
				delete pixels2;
				break;
			case 'I':
				show_mat(image, "Input");
				break;
			case 'X':
				show_mat(*pixels, "Output");
				break;
			case 'S':
				if (i+1 >= argc)
				{
					help();
					return -1;
				}
				imwrite(argv[++i], *pixels);
				break;
			case 'T':
				serialize(*pixels);
				break;
			case 'O':
				if (i+1 >= argc)
				{
					help();
					return -1;
				}
				s = atoi(argv[++i]);
				pixels2 = pixels;
				pixels = findSmoothPerimeter(*pixels, s);
				delete pixels2;
				break;
			default:
				help();
				return -1;
		}
	}

	return 0;
}

void show_mat(const cv::Mat &image, std::string const &win_name) {
    namedWindow(win_name, WINDOW_AUTOSIZE);
    imshow(win_name, image);
    waitKey(0);
}

void serialize(cv::Mat &mat) {
	int channels = mat.channels();

	if (channels != 1)
	{
		return;
	}

	int nRows = mat.rows;
	int nCols = mat.cols;

	int i, j;
	for (i = 0; i < nRows; ++i) {
		for (j = 0; j < nCols; ++j) {
			if (mat.ptr<uchar>(i)[j])
			{
				printf("%d,%d;", i, j);
			}
		}
	}
}

