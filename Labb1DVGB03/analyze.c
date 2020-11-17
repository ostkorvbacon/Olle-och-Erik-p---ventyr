#define _POSIX_C_SOURCE 199309L
#include "analyze.h"
#include "algorithm.h"
/*#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>*/


#define NUMBEL 512
#define REP 5
//
// Private
//


//
// Public
//
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{	
	double bursttime=0,times;
	int size;
	int arr[NUMBEL*((int)pow(2,n))];
	int i,k;
	time_t t;
	clock_t start,stop;
	
	srand((unsigned) time(&t));
	
	for (int j=0;j<n;j++){
		bursttime=0;
		size=NUMBEL*((int)pow(2,j));
		
		for (k=0;k<REP;k++){
			

			if ( c==average_t) for (i=0;i<size;i++) arr[i]=rand()%size;
			
			else if (c==best_t) for (i=0;i<size;i++) arr[i]=i;
			
			else for (i=0;i<size;i++) {arr[i]=size-i;}
			
			
			start=clock();
			//Stuff
			bubble_sort(arr,size);

			//end of Stuff
			stop=clock();
		
			times=(stop-start)/((double)CLOCKS_PER_SEC);
			
			bursttime=bursttime+times;
			//printf("times=%f \n",times);
			
		}
		bursttime=bursttime/REP;
		buf[j].time=bursttime;
		buf[j].size=size;
	
	}
	

	
}
