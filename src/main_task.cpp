#include "main_task.h"

using namespace std;


bool Main::init_task()
{
	return true;
}

/*
   @function: do task
   @Param string in the path of the input image
   @out null
*/

void Main::run_task( string in)
{
	image_in = cvLoadImage(in.c_str(), 1);

	if (!image_in){
		cout << "no image" << endl;
		return;
	}
	array2d<rgb_pixel> img;
	load_image(img, in.c_str());


	image_show = cvCreateImage(cvGetSize(image_in), image_in->depth, image_in->nChannels);
	image_rota = cvCreateImage(cvGetSize(image_in), 8, 1);

	cvCopy(image_in, image_show);

	FaceDetector fd;
	fd.initFaceDetector(image_in);
	fd.runFaceDetector();

	if (fd.getDetectFaceCount() == 0){
		cout << "no face detected .." << endl;
		cvReleaseImage(&image_show);
		fd.releaseFaceDetector();
		return;
	}

	fd.getBigestFacePos(pos);
	cvRectangle(image_show, cvPoint(pos[0], pos[1]), cvPoint(pos[2], pos[3]), cvScalar(255, 0, 0), 1, 8, 0);
	cvSaveImage("SHOW", image_show);
	return;
	
}


