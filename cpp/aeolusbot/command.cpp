#include <opencv2/opencv.hpp>
#include "command.hpp"

int Command::parametersNeeded()
{
	return 0;
}

//true on success
bool Command::parseParameters(char **argv)
{
	return true;
}

int Command::getInputType()
{
	return OBJECT_NONE;
}

int Command::getOutputType()
{
	return OBJECT_NONE;
}

//true on success
bool Command::execute(cv::Mat *in, cv::Mat *out)
{
	return true;
}

int DisplayImageCommand::getInputType()
{
	return OBJECT_IMAGE;
}

bool DisplayImageCommand::execute(cv::Mat *in, cv::Mat *out)
{
	//TBD
	return true;
}

int DisplayPixelsCommand::getInputType()
{
	return OBJECT_PIXELS;
}

bool DisplayPixelsCommand::execute(cv::Mat *in, cv::Mat *out)
{
	//TBD
	return true;
}

int SavePixelsCommand::parametersNeeded()
{
	return 1;
}

bool SavePixelsCommand::parseParameters(char **argv)
{
	//TBD
	return true;
}

int SavePixelsCommand::getInputType()
{
	return OBJECT_PIXELS;
}

bool SavePixelsCommand::execute(cv::Mat *in, cv::Mat *out)
{
	//TBD
	return true;
}

int TextOutputCommand::getInputType()
{
	return OBJECT_PIXELS;
}

bool TextOutputCommand::execute(cv::Mat *in, cv::Mat *out)
{
	//TBD
	return true;
}

int FindRegionCommand::parametersNeeded()
{
	return 3;
}

bool FindRegionCommand::parseParameters(char **argv)
{
	//TBD
	return true;
}

int FindRegionCommand::getInputType()
{
	return OBJECT_IMAGE;
}

int FindRegionCommand::getOutputType()
{
	return OBJECT_PIXELS;
}

bool FindRegionCommand::execute(cv::Mat *in, cv::Mat *out)
{
	//TBD
	return true;
}

int FindPerimeterCommand::getInputType()
{
	return OBJECT_PIXELS;
}

int FindPerimeterCommand::getOutputType()
{
	return OBJECT_PIXELS;
}

bool FindPerimeterCommand::execute(cv::Mat *in, cv::Mat *out)
{
	//TBD
	return true;
}

int FindSmoothPerimeterCommand::parametersNeeded()
{
	return 1;
}

bool FindSmoothPerimeterCommand::parseParameters(char **argv)
{
	//TBD
	return true;
}

int FindSmoothPerimeterCommand::getInputType()
{
	return OBJECT_PIXELS;
}

int FindSmoothPerimeterCommand::getOutputType()
{
	return OBJECT_PIXELS;
}

bool FindSmoothPerimeterCommand::execute(cv::Mat *in, cv::Mat *out)
{
	//TBD
	return true;
}

