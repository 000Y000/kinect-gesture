#pragma once
#include <Kinect.h>
#include "cv.h"
#include "MFC_DEMO01Dlg.h"

// Safe release for interfaces
template<class Interface>
inline void SafeRelease(Interface *& pInterfaceToRelease)
{
	if (pInterfaceToRelease != NULL)
	{
		pInterfaceToRelease->Release();
		pInterfaceToRelease = NULL;
	}
}

class CBodyBasics
{
	//kinect 2.0 ����ȿռ�ĸ�*���� 424 * 512���ڹ�������˵��
	static const int        cDepthWidth = 512;
	static const int        cDepthHeight = 424;

public:
	CBodyBasics();
	~CBodyBasics();
	friend class CMFC_DEMO01Dlg;
	void                    Update();//��ùǼܡ�������ֵͼ�������Ϣ
	HRESULT                 InitializeDefaultSensor();//���ڳ�ʼ��kinect
	//�������ͼ��
	void SaveDepthImg();
	//�������ͼ 
	void SaveSkeletonImg();
	//ͨ����õ�����Ϣ���ѹǼܺͱ�����ֵͼ������
	void                    ProcessBody(int nBodyCount, IBody** ppBodies);
	 
private:
	IKinectSensor*          m_pKinectSensor;//kinectԴ
	ICoordinateMapper*      m_pCoordinateMapper;//��������任
	IBodyFrameReader*       m_pBodyFrameReader;//���ڹǼ����ݶ�ȡ
	IDepthFrameReader*      m_pDepthFrameReader;//����������ݶ�ȡ
	IBodyIndexFrameReader*  m_pBodyIndexFrameReader;//���ڱ�����ֵͼ��ȡ

	
	//���Ǽܺ���
	void DrawBone(const Joint* pJoints, const DepthSpacePoint* depthSpacePosition, JointType joint0, JointType joint1);
	//���ֵ�״̬����
	void DrawHandState(const DepthSpacePoint depthSpacePosition, HandState handState);
	void Detection(Joint joints[]);
	double  Distance(Joint p1, Joint p2);
	//��ʾͼ���Mat
	 cv::Mat skeletonImg;		//����ͼ
	  cv::Mat depthImg;			//���ͼ
	
};

