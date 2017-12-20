class Command
{
public:
	static const int OBJECT_NONE = 0;
	static const int OBJECT_IMAGE = 1;
	static const int OBJECT_PIXELS = 2;

	virtual int parametersNeeded();

	//true on success
	virtual bool parseParameters(char **argv);

	virtual int getInputType();

	virtual int getOutputType();

	//true on success
	virtual bool execute(cv::Mat *in, cv::Mat *out);
};

class DisplayImageCommand : public Command
{
	int getInputType();
	bool execute(cv::Mat *in, cv::Mat *out);
};

class DisplayPixelsCommand : public Command
{
	int getInputType();
	bool execute(cv::Mat *in, cv::Mat *out);
};

class SavePixelsCommand : public Command
{
	int parametersNeeded();
	bool parseParameters(char **argv);
	int getInputType();
	bool execute(cv::Mat *in, cv::Mat *out);
};

class TextOutputCommand : public Command
{
	int getInputType();
	bool execute(cv::Mat *in, cv::Mat *out);
};

class FindRegionCommand : public Command
{
	int parametersNeeded();
	bool parseParameters(char **argv);
	int getInputType();
	int getOutputType();
	bool execute(cv::Mat *in, cv::Mat *out);
};

class FindPerimeterCommand : public Command
{
	int getInputType();
	int getOutputType();
	bool execute(cv::Mat *in, cv::Mat *out);
};

class FindSmoothPerimeterCommand : public Command
{
	int parametersNeeded();
	bool parseParameters(char **argv);
	int getInputType();
	int getOutputType();
	bool execute(cv::Mat *in, cv::Mat *out);
};

