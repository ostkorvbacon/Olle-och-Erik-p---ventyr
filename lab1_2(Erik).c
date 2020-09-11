#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>

#define NT 100
#define BUFF 100

int i,n,bsize,tint,buffer[BUFF];
int inde=0;

void *p(void *a ) {
	
	printf("Hej jag är konsument id: %d \n",(int)pthread_self());
	
	while (1) {	
		
		sleep(tint+5);
		if (0<=inde) {
			
				printf("Data: %d konsument id: %d\n",buffer[inde],(int)pthread_self());
				inde--;
				
			}
			
		else sleep(tint+1);
		
	}
		
	
	
	
	}
	
void *p2(void *a ) {
	
	printf("\nHej jag är producent id: %d \n",(int)pthread_self());
	while (1) {	
		
		if (inde<=bsize) {
				buffer[inde]=inde;
				inde++;
				sleep(tint);
			
			}
			
		else sleep(tint);
		
	}
	
	}

int main()

{
	pthread_t tid[NT];
	
	printf("N: ");
	scanf("%d",&n);
	
	printf("\nBufffer: ");
	scanf("%d",&bsize);
	
	printf("\nInterval: ");
	scanf("%d",&tint);
	
	pthread_create(&tid[0],NULL,*p2,0);
	
	for (i=1;i<n+1;i++) pthread_create(&tid[i],NULL,*p,0);
	
	for (i=0;i<n+1;i++) pthread_join(tid[i],NULL);
	
	

return 0;
}
