#define _POSIX_C_SOURCE 199309L
#include "analyze.h"
#include "algorithm.h"
/*#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>*/


#define NUMBEL 10
#define REP 5
#define KEY 6
#define NOTKEY 7

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
			
			if (a==bubble_sort_t){

				if ( c==average_t) for (i=0;i<size;i++) {
					
					
					arr[i]=rand()%100;
					
					
					}
				
				else if (c==best_t) for (i=0;i<size;i++) arr[i]=i;
				
				else for (i=0;i<size;i++) {arr[i]=size-i;}
				
				/*printf("\n");
				for (i=0;i<size;i++) printf(" %d",arr[i]);
				printf("\n");*/
				
				start=clock();
				
				//Stuff
				bubble_sort(arr,size);

				//end of Stuff
				stop=clock();
				
				/*printf("\n");
				for (i=0;i<size;i++) printf(" %d",arr[i]);
				printf("\n");*/
			}
			
			else if (a==insertion_sort_t){

				if ( c==average_t) for (i=0;i<size;i++) arr[i]=rand()%size;
				
				else if (c==best_t) for (i=0;i<size;i++) arr[i]=i;
				
				else for (i=0;i<size;i++) {arr[i]=size-i;}
				
				
				start=clock();
				//Stuff
				insertion_sort(arr,size);

				//end of Stuff
				stop=clock();
			}
			else if (a==quick_sort_t){

				if ( c==average_t) for (i=0;i<size;i++) arr[i]=rand()%size;
				
				else if (c==best_t) for (i=0;i<size;i++) arr[i]=i; //ej bäst fixa
				
				else for (i=0;i<size;i++) {arr[i]=1;}
				
				
				start=clock();
				//Stuff
				quick_sort(arr,size);

				//end of Stuff
				stop=clock();
			}
			
			else if (a==linear_search_t){

				if ( c==average_t) for (i=0;i<size;i++) arr[i]=rand()%size;
				
				else if (c==best_t) arr[0]=KEY; 
				
				else 				for (i=0;i<size;i++) arr[i]=NOTKEY;
				
				
				start=clock();
				//Stuff
				linear_search(arr,size,KEY);

				//end of Stuff
				stop=clock();
			}
			else {

				if ( c==average_t) for (i=0;i<size;i++) {
					
					arr[i]=rand()%size; 
					quick_sort(arr,size);
					
					
				}
				
				else if (c==best_t) arr[(size-1)/2]=KEY; 
				
				else 	for (i=0;i<size;i++) arr[i]=NOTKEY;
				
				
				start=clock();
				//Stuff
				binary_search(arr,size,KEY);

				//end of Stuff
				stop=clock();
			}
			
			
				times=(stop-start)/((double)CLOCKS_PER_SEC);
				
				bursttime=bursttime+times;
				//printf("times=%f \n",times);
			
		}
		bursttime=bursttime/REP;
		buf[j].time=bursttime;
		buf[j].size=size;
	
	}
	

	
}
