
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>

#define BUFF 100  //Deklarerar konstanter, malloc() kunde också användas men detta var enklare och storleken på arrayerna antogs ej överstiga 100
#define NT 100


int i,n,bsize,tint,buffer[BUFF]; //Deklarerar variabler
int inde=0;
time_t t;
sem_t prodcount; // Datapaket producerade
sem_t remaining; // Kvarvarand utrymme i buffer
pthread_mutex_t mut;

void *p(void *a )  //Funktion för konsument
{
	printf("Hej jag är konsument id: %d \n",(int)pthread_self()); //Identifierar konsument

	while (1)
	{	
		sleep(tint+2);	
		int k=0;
		sem_getvalue(&prodcount,&k);     
		if (k>0){			// Stoppar konsumenten om ingen data finns
			
			pthread_mutex_lock(&mut);		// Låser bufferten 
			sem_wait(&prodcount); 														//Signalerar att antalet datapaket minskat
			printf("\nData: %d konsument id: %d\n",buffer[inde],(int)pthread_self()); //Skriver ut data och identifierar trådedn som gjorde det
			inde--;																		//Minskar positionen i buffer när ett datapaket tagits 
			sem_post(&remaining);                    //Signalerar att mer plats finns på bufferten
			pthread_mutex_unlock(&mut);				//Låser upp bufferten
			}

	}
}


void *p2(void *a) //Funktion för producent
{
	printf("\nHej jag är producent id: %d \n",(int)pthread_self()); //Identifierar producent

	while (1)
	{
		int k2=0;
		sem_getvalue(&remaining,&k2);
		
		if (k2>0){						// Stoppar producent om buffer full
			
			sem_wait(&remaining);		//Signalerar att mindre plats finns på bufferten
			pthread_mutex_lock(&mut);   // Låser bufferten 
			buffer[inde]=(rand()%6);
			inde++;
			pthread_mutex_unlock(&mut); // Låser upp bufferten 
			sem_post(&prodcount);       //Signalerar att antalet datapaket ökat
			sleep(tint);                //Väntar tid specifierad av användaren innan producenten fortsätter
		}
	}
	
	
}



int main()
{	
	srand(time(&t));  //Deklarerar variabler
	pthread_t tid[NT];
	printf("N: ");
	scanf("%d",&n);
	

	printf("\nBufffer: "); // Tar in data från användare
	scanf("%d",&bsize);
	
	memset(buffer,0,sizeof(int)*BUFF); //Tar bort skräp från buffern

	printf("\nInterval: ");
	scanf("%d",&tint);

	sem_init(&prodcount, 0, 0);  // Startar semaforer 
	sem_init(&remaining, 0, bsize);
	
	pthread_create(&tid[0],NULL,*p2,0); //Startar producent och konsumenter och lägger deras id i en array med producent först

	for (i=1;i<n+1;i++) pthread_create(&tid[i],NULL,*p,0); 

	for (i=0;i<n+1;i++) pthread_join(tid[i],NULL);  // Får programmet att vänta på alla trådar

	
	return 0;
}
