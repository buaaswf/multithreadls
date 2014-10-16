#ifndef SWF_STATISTICS_H
#define SWF_STATISTICS_H

#include "vol_math_LevelSet.h"
#include <queue>
#include "test.h"
#include "DivideRegion.h"
#include <iostream>
#include <crtdbg.h> 
#include "CImg.h" 
#include "ThreeDim_LevelSet.h"
#include "Filter.h"
#include "WipeNioisePde.h"
#include "string.h"
#include <fstream>
#include <vector>
#include <string>
#ifdef _WIN32
#include <Windows.h>
#include <strsafe.h>
#else
#include <dirent.h>
#endif
//#define output "D:\\sdfdata\\" 
//#define output "J:\\20140414\\" 
#define output "D:\\swfdata20140420res\\"
//#define input1  "L:\\sdfdata2\\edt\\"	//thickness uint8	//edt		//float
//#define input1  "L:\\sdfdata2\\inner\\"
#define input1 "F:\\colonData\\Seg with Drawing\\clean2\\"
//#define input2   "K:\\sdf\\volume\\clean\\clean\\ep\\20140414\\"
//#define input2 "D:\\good\\"
//#define  input2 "K:\\sdf\\volume\\clean\\clean\\ep\\clean\\"
#define input2 "F:\\colonData\\Seg with Drawing\\clean\\"
//#define input2 "F:\\colonData\\Seg with Drawing\\clean\\"
//"D:\\20140511aotuo\\"
//#define input2 "D:\\swfdata20140420\\"
//#define input2	"K:\\sdf\\volume\\clean\\clean\\3041P\\" //		//short
#define input3  "K:\\skeleton\\"  //skeleton uint8 //unsigned char
//#define input1  "F:\\data\\skeleton-edt\\"				//float
//#define input2	"E:\\volume\\skeletono\\"		//short
//#define input3 "F:\\data\\skeleton-s\\"   //unsigned char

using namespace cimg_library;
using namespace std;
//////////////////////////////////////////////////////////////////////////
//��ȡָ��Ŀ¼�������ļ����ļ������������ļ��У���GetFileFromDir��ʹ��
//strDir: ���룬Ŀ¼·��
//vFileDirList�� ������ļ�·���б�
//���أ���
//////////////////////////////////////////////////////////////////////////
void GetFileNameFromDir(string strDir, vector<string>& vFileDirList);


void rocwayinner2people(string dir1, string dir2);

void evaluate(string dir, int l, int m, int n);


void pvalue(string dir1, string dir2, string dir22);

void ddcircle(string dir);

void roc();


void roc3();

void float2uchar(int l, int m, int n, string dir);

void thincknessstd(string dir);


void thincknessstdv2(string dir);

void testcolonway2(int argc, string dir);


void threshold();

bool sign(PIXTYPE data);

PIXTYPE  biglittleedian(PIXTYPE  val);
void rocwayinner2people(string dir1, string dir2);

Raw* thicknessequalHU(Raw *origion, Raw *thickness);

void HUandThickness();

#endif