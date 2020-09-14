#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>

#define NT 100
#define BUFF 4


int i,n,bsize,tint,buffer[BUFF];
int inde=1;
pthread_mutex_t lock;

void *p(void *a )
{
	printf("Hej jag är konsument id: %d \n",(int)pthread_self());

	while (1)
	{


		if (0<inde)
		{	for (i=0;i<bsize;i++) printf(" %d \n",buffer[i]);
			pthread_mutex_lock(&lock);
			printf("Data: %d konsument id: %d\n",buffer[inde],(int)pthread_self());

			if (0<inde) inde--;
			pthread_mutex_unlock(&lock);
		}
		else {


		}

	}
}

void *p2(void *a)
{
	printf("\nHej jag är producent id: %d \n",(int)pthread_self());

	while (1)
	{



	if (inde<bsize)	{


			pthread_mutex_lock(&lock);
			buffer[inde]=inde;
			inde++;
			pthread_mutex_unlock(&lock);
			sleep(tint);


		}



		else sleep(1);
	}
}

int main()
{
	pthread_t tid[NT];
	pthread_mutex_init(&lock,NULL);
	printf("N: ");
	scanf("%d",&n);

	printf("\nBufffer: ");
	scanf("%d",&bsize);

	printf("\nInterval: ");
	scanf("%d",&tint);
for (i=0;i<bsize+2;i++) printf(" %d \n",buffer[i]);
	/*pthread_create(&tid[0],NULL,*p2,0);

	for (i=1;i<n+1;i++) pthread_create(&tid[i],NULL,*p,0);

	for (i=0;i<n+1;i++) pthread_join(tid[i],NULL);
*/
	return 0;
}
