#include "MultiPthread.h"




MultiPthread::MultiPthread(){

}
MultiPthread::~MultiPthread()
{
}
MultiPthread::MultiPthread(int threadnum, vector<SegColonParameter>parms, vector<pthread_t>threads)
{
	this->threadcount = threadnum;
	this->threads = threads;
	
	parms.resize(threadcount);
}
void *singlecColonSeg(void *para)
{
	SegColonParameter *pa = (SegColonParameter*)para;
	char *pt = "single_well";
	int l = 0, m = 0, n = 0, l1 = 0, l2 = 0, iter_outer = 10;
	RawImage test;
	char dirhead[200] = input2;  //K:\\sdf\\volume\\clean\\clean\\ep\\

	char dirbody[100];
	strcpy(dirbody, pa->dir.c_str());
	cout << "dirbody" << dirbody << endl;
	strcat(dirhead, dirbody);
	cout << "dirhead" << dirhead << endl;
	short * indata = test.readStream(dirhead, &l, &m, &n);
	Raw *initial = new Raw(l, m, n);
	float *inputo = new float[l*m*n];
	for (int i = 0; i < l*m*n; i++)
	{
		inputo[i] = (float)indata[i];
	}

	Raw *input = new Raw(l, m, n, inputo);
	Filter *f = new Filter();
	//input=f->guass3DFilter(input,3);
	RawImage *write = new RawImage();
	ThreeDim_LevelSet *ls = new ThreeDim_LevelSet();
	//20140405 delete because of the existance of 
	ls->initialg(*input);

	for (int i = 0; i<input->getXsize(); i++)
	{
		for (int j = 0; j<input->getYsize(); j++)
		{
			for (int k = 0; k<input->getZsize(); k++)
			{
				if (input->get(i, j, k) >= 1)
				{
					initial->put(i, j, k, -2);
				}
				else initial->put(i, j, k, 2);

			}
		}

	}

	*initial = ls->minimal_surface(*initial, *input, 5.0, 0.1, -3, 1.5, 1, iter_outer, pt);

	char *outname1 = "inner5-8_2.raw";
	char outdir[200] = output;

	strcat(outdir, dirbody);
	strcat(outdir, outname1);
	
	test.writeImageName(*initial, outdir);
	
	ls->outerwall(*initial, *input, 5, 0.1, -3, 1.5, 1, 10, pt);
	PIXTYPE *data = initial->getdata();

	int count = 0;

	char *outname2 = "outer5-8_2_20140405.raw";
	char outdir2[200] = output;
	strcat(outdir2, dirbody);
	strcat(outdir2, outname2);
	test.writeImageNameNoCircle(*initial, outdir2);
	evaluate(pa->dir, l, m, n);
	return NULL;
}

int MultiPthread::Createthreadi(int i,string dir)
{
	int ret;
	pthread_attr_t *attr;
	parms.resize(threadcount);
	parms[i] = SegColonParameter(dir);
	ret = pthread_create(&threads[i], NULL, singlecColonSeg, &parms[i]);

	return ret;
}