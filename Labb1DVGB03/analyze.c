#define _POSIX_C_SOURCE 199309L
#include "analyze.h"
#include "algorithm.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//
// Private
//

//
// Public
//
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{	
	double bursttime=0;
	
	for (int j=0;j<n;j++){
		
		struct timespec start,stop;
		clock_gettime(CLOCK_REALTIME,&start);
		
		//Stuff
		
		int arr[10];
		int i;
		time_t t;
		srand((unsigned) time(&t));
		for (i=9;i>-1;i--) arr[i]=rand()%21;
		insertion_sort(arr,10);

		//end of Stuff
		
		clock_gettime(CLOCK_REALTIME,&stop);
		bursttime=(double)stop.tv_nsec-start.tv_nsec;
printf("1Time: %f bTime: %f ",buf[j].time,bursttime);
		buf[i].time=bursttime;
printf("2Time: %f bTime: %f\n",buf[j].time,bursttime);
	
	}
	//for (int i=0;i<n;i++) printf("Time: %f bTime: %f",buf[i].time,bursttime);

	
}
