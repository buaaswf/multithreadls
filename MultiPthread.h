#ifndef SWF_MULTIPTHREAD_H
#define SWF_MULTIPTHREAD_H
#include"pthread.h"
#include<string>
#include<vector>
#include "vol_math_LevelSet.h"
#include "statistics.h"
#include "test.h"
#include "ProcessDirty.h"
#include"initial.h"
using namespace std;
struct SegColonParameter
{
	string dir;
	SegColonParameter()
	{
		
	}
	SegColonParameter(string dir)
	{
		this->dir = dir;
	}
};
class MultiPthread
{
public:
	vector<pthread_t>threads;
	int threadcount;
	std::vector<int>pids; 
	std::vector<int> res; 
	vector<SegColonParameter> parms;	
	
	
	MultiPthread();
	MultiPthread(int, vector<SegColonParameter>parms, vector<pthread_t>threads);
	/*
		create the no. i thread
	*/
	int Createthreadi(int i,string dir);
	~MultiPthread();

};

#endif