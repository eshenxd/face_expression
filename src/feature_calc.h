#ifndef _FEATURE_CALC_H_
#define _FEATURE_CALC_H_

#include "header.h"

class Feature
{
public:
	Feature();
	~Feature();

	/* 全局特征*/
	void featureExtract(std::vector<CvPoint>&points, int* feature, int m);

	/* feature_angle 包含左右眼的左右角，嘴唇的6个夹角*/
	void calc_angle_features(std::vector<CvPoint>&points, double* feature_angle);

	/* feature_eyebrow 包含眉毛上10个点与眉心之间距离*/
	void calc_eyebrow_feature(std::vector<CvPoint>&points, double* feature_eyeborw);

	/* feature_base 主要描述的是整个脸部的姿态（倾斜，左右脸对比度等）*/
	void calc_base_feature(dlib::full_object_detection src_shape /*校正之前的关键点的位置*/, double* basefeature);

	/* draw line 变出参与特征计算的所有点的连线 */
	void drawLines(dlib::full_object_detection shap, IplImage* dst_image);

	void drawFullPoint(dlib::full_object_detection shap, IplImage* dst_image);

private:
	int index;
	int feature_global[54];
	double basefeature[2];
	double feature_angle[10];
	double feature_eyebrowe[10];

	bool operator <   (const Feature& rhs)   const //升序排序时必须写的函数
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