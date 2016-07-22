#ifndef _MAIN_TASK_H_
#define _MAIN_TASK_H_

#include "detect_face.h"
#include "detect_points.h"


#include <iostream>
#include <vector>


class Main
{
public:
	Main();
	~Main();
	bool init_task();
	void run_task();


private:
	IplImage* image_in;
	IplImage* image_show;
	IplImage* image_rota;
	IplImage* image_resize;
	IplImage* image_clip;

	int pos[4];
};

Main::Main()
{
}

Main::~Main()
{
}

#endif