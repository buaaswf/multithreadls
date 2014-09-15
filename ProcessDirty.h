#pragma once
#include "vol_math_Raw3D_Independt.h"
#include "vol_math_RawImage.h"
#include<iostream>
#include <queue>
#include <vector>
#include <queue>
void processDirty(Raw *dirty);


//void test()
//{
//	int l = 0, m = 0, n = 0;
//	RawImage test;
//	short*orgiondata=test.readStream("F:\\data\\dirty\\WIS_5431_2_P.raw",&l,&m,&n);
//	PIXTYPE *indata=new PIXTYPE[l*m*n];
//	for (int i=0;i< l*m*n ;i++)
//	{
//		indata[i]=(PIXTYPE)orgiondata[i];
//	}
//	delete [] orgiondata;
//	Raw * dirty =new Raw(l,m,n,indata);
//	processDirty(dirty);
//	test.writenormal(*dirty,"F:\\data\\dirty\\testdata2.raw");
//}