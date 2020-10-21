#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char**argv)
{
  int a[256];
  int size = 0;
  int i, j, k = 0, test = 0;
  char *arg = NULL;
  int frames = 0;
  char *doc = NULL;

  arg = argv[1];
  frames = atoi(argv[2]);
  doc = argv[3];
  printf(" Frames: %d\n",frames);

	FILE *infil;

	infil = fopen(doc,"r");
	if(!infil) printf("%p",infil);

	while(fscanf(infil, "%d", &a[size]) != EOF) size++;

	//for (int i=0;i<size;i++) printf(" Adress: %d\n",a[i]);

	int *vmem = calloc(frames, sizeof(int));

	if(strcmp(arg,"FIFO") == 0)
  {
		for(i=0; i<size; i++)
    {
			test = 1;
			for (j = 0; j<frames; j++)
      {
				if(a[i] == vmem[j])
        {
					printf(" Adress: %d Page hit\n", a[i]);
					test = 0;
					break;
				}
			}
  		if(test == 1)
      {
    		vmem[k] = a[i];
    		if(k >= frames-1) k = 0;
    		else k++;
    		printf(" Adress: %d Page miss\n", a[i]);
  		}
		}
	}

	else if(strcmp(arg,"Optimal") == 0)
  {


	}

	else if(strcmp(arg,"LRU") == 0)
  {


	}
	else printf("Ogiltig algoritm");

	free(vmem);
	return 0;
}
