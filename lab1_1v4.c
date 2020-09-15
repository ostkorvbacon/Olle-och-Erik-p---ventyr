#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>

#define PA1 1000
#define WINP 4
#define STOK 4

int PA;
int pid;
pid_t p[PA1];
int i;

void pri()
{
	for (i=0;i<PA;i++) kill(p[i],SIGTERM);
	sleep(1);
	exit(0);
}

void pri2()
{
	printf("\nPlayer %d eliminerad\n",pid);
	exit(0);
}

int main()
{
	printf("Antal: ");
	scanf("%d",&PA);
	printf("\n");

	if (PA==1)
	{
		printf("Endast 1 spelare => Player 0 vinner\n");
		exit(0);
	}
	sem_t semph[PA];
	int token;
	int k=1;
	int j;
	int points = 0;

	for (j=0;j<PA;j++)
  {
    p[j] = 0;
  }
  pid = -1; // -1 är parent
  int pipes[PA][2];

  for(i=0; i<PA; i++)
	{
    if(pipe(pipes[i])<0)
		{
      printf("Pipe failiure");
		}
		sem_init(&semph[i],1,1000);
	}
  p[0] = fork();
	if (p[0] == -1)
	{
		fprintf(stderr, "Fork failure");
		exit(EXIT_FAILURE);
	}
  if(p[0] != 0)
  {
    for(i=0; i<(PA-1); i++)
    {
      if(p[i] != 0)
      {
        p[i+1] = fork();

				if (p[i+1] == -1)
				{
					fprintf(stderr, "Fork failure");
					exit(EXIT_FAILURE);
				}
				if (p[i+1]==0)
				{
			  	pid=i+1;
			  	printf("Player %d startat",pid);
		  	}
      }
    }
  }
  else
	{
		pid=0;
		printf("player 0 startat");
	}
	if (pid==-1)
	{
		(void) signal(SIGTERM,pri);
		int t=STOK;
		write(pipes[0][1],&t,sizeof(int));
		sem_post(&semph[0]);
	}
	while (k==1)
	{
		if (pid==-1)
		{}
    else if (pid==0)
		{
			(void) signal(SIGTERM,pri2);
			sem_wait(&semph[0]);
			read(pipes[0][0],&token,sizeof(int));

			if (token==0)
			{
				points++;
				printf("\n Player %d, Received: %d, Sent: %d ,Points: %d \n",pid,token,STOK,points);
				token=STOK;

				if (points==WINP)
				{
					printf("\nPlayer %d vinner\n",pid);
					kill(getppid(),SIGTERM);
					sleep(1);
				}
			}
			else
			{
				token--;
				printf("\n Player %d, Received: %d, Sent: %d ,Points: %d \n",pid,token+1,token,points);
			}
			write(pipes[1][1],&token,sizeof(int));
			sem_post(&semph[1]);
		}
		else if (pid<PA-1)
		{
			(void) signal(SIGTERM,pri2);
			sem_wait(&semph[pid]);
			read(pipes[pid][0],&token,sizeof(int));

			if (token==0)
			{
				points++;
				printf("\n Player %d, Received: %d, Sent: %d ,Points: %d \n",pid,token,STOK,points);
				token=STOK;

				if (points==WINP)
				{
					printf("\nPlayer %d vinner\n",pid);
					kill(getppid(),SIGTERM);
					sleep(1);
				}
			}
			else
			{
				token--;
				printf("\n Player %d, Received: %d, Sent: %d ,Points: %d \n",pid,token+1,token,points);
			}
			write(pipes[pid+1][1],&token,sizeof(int));
			sem_post(&semph[pid+1]);
		}
		else
		{
			(void) signal(SIGTERM,pri2);
			sem_wait(&semph[pid]);
			read(pipes[pid][0],&token,sizeof(int));

			if (token==0)
			{
				points++;
				printf("\n Player %d, Received: %d, Sent: %d ,Points: %d \n",pid,token,STOK,points);
				token=STOK;

				if (points==WINP)
				{
					printf("\nPlayer %d vinner\n",pid);
					kill(getppid(),SIGTERM);
					sleep(1);
				}
			}
			else
			{
				token--;
				printf("\n Player %d, Received: %d, Sent: %d ,Points: %d  \n",pid,token+1,token,points);
			}
			write(pipes[0][1],&token,sizeof(int));
			sem_post(&semph[0]);
		}
	}
	for (j=0;j<PA;j++)  wait(NULL);

  return 0;
}
