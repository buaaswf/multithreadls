



#include"MultiPthread.h"


int main(int argc,char **argv)
{

	string dir2(input2);
	vector<string> files2;
	GetFileNameFromDir(dir2,files2);
	vector<string>::iterator iterFile2;
	int i = 0;
	int threadnum = 4;
	
	vector<SegColonParameter>parms; parms.resize(threadnum);
	vector<pthread_t>threads; threads.resize(threadnum);
	for (iterFile2 = files2.begin()+1; iterFile2 != files2.end(); iterFile2++)
	{

		for (size_t i = 0; i < threadnum; i++, iterFile2++)
		{
			iterFile2->assign(iterFile2->substr(dir2.size() + 1));
			cout << *iterFile2 << endl;
			MultiPthread *multi = new MultiPthread(threadnum, parms, threads);
			multi->Createthreadi(i, *iterFile2);
			i++;
		   
		}

		for (int i = 0; i<threadnum; i++)
		{
			pthread_join(threads[i], NULL);
		}																			
		
	}


	system("pause");
	return 0;
}
