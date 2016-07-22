#ifndef _FEATURE_CALC_H_
#define _FEATURE_CALC_H_

#include "header.h"

class Feature
{
public:
	Feature();
	~Feature();

	/* ȫ������*/
	void featureExtract(std::vector<CvPoint>&points, int* feature, int m);

	/* feature_angle ���������۵����ҽǣ��촽��6���н�*/
	void calc_angle_features(std::vector<CvPoint>&points, double* feature_angle);

	/* feature_eyebrow ����üë��10������ü��֮�����*/
	void calc_eyebrow_feature(std::vector<CvPoint>&points, double* feature_eyeborw);

	/* feature_base ��Ҫ��������������������̬����б���������Աȶȵȣ�*/
	void calc_base_feature(dlib::full_object_detection src_shape /*У��֮ǰ�Ĺؼ����λ��*/, double* basefeature);

	/* draw line �������������������е������ */
	void drawLines(dlib::full_object_detection shap, IplImage* dst_image);

	void drawFullPoint(dlib::full_object_detection shap, IplImage* dst_image);

private:
	int index;
	int feature_global[54];
	double basefeature[2];
	double feature_angle[10];
	double feature_eyebrowe[10];

	bool operator <   (const Feature& rhs)   const //��������ʱ����д�ĺ���
	{
		return index < rhs.index;
	}
};

Feature::Feature()
{
	for (unsigned int i = 0; i < 54; i++)
	{
		feature_global[i] = 0;
	}
}

Feature::~Feature()
{
}

#endif 