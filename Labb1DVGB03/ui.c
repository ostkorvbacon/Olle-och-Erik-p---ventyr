#include "ui.h"
#include "io.h"
#include "analyze.h"

#include <stdbool.h>
#include <stdio.h>

//
// Private
//
static void ui_invalid_input()
{
	printf("info> bad input\n");
}

static void ui_exit()
{
	printf("info> bye\n");
}

static char ui_get_choice()
{
	char buf[3];

	printf("input> ");
	return read_line(buf, 3) ? buf[0] : 0;
}

static void ui_line(char c, int n)
{
	while (n-- > 0) {
		putchar(c);
	}
	putchar('\n');
}

static void ui_menu_options(const char *options[], int num_options)
{
	int i;

	for (i=0; i<num_options; i++) {
		printf("    %c) %s\n", 'a'+i, options[i]);
	}
}

void printres(result_t *result) {
	
		
	for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));
	
}

static void ui_menu()
{
	const char *options[] = {
		"Menu",
		"Exit\n",
		"Bubble sort best case",
		"Bubble sort worst case",
		"Bubble sort avarege case\n",
		"Inertion sort best case",
		"Inertion sort worst case",
		"Inertion sort avarege case\n",
		"Quick sort best case",
		"Quick sort worst case",
		"Quick sort avarege case\n",
		"Linear search best case",
		"Linear search worst case",
		"Linear search avarege case\n",
		"Binary search best case",
		"Binary search worst case",
		"Binary search avarege case",
		
	
	};

	ui_line('=', MENU_WIDTH);
	ui_menu_options(options, sizeof(options) / sizeof(char *));
	ui_line('-', MENU_WIDTH);
}

//
// Public
//
void ui_run()
{
	bool running, show_menu;
	result_t result[RESULT_ROWS];
	
	show_menu = true;
	running = true;
	while (running) {
		if (show_menu) {
			show_menu = false;
			ui_menu();
		}
		switch (ui_get_choice()) {
			// House keeping
			case 'a':
				show_menu = true;
				break;
			case 'b':
				running = false;
				break;
				
				
			// Bubble sort best
			case 'c':

				benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
				printres(result);

				break;
				
				//bubble worst 
			case 'd':
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				break;
				
				//bubble average 	
			case 'e':
			
				benchmark(bubble_sort_t,average_t, result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %f  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				
				break;
				
				
				//insertion best
			case 'f':
				benchmark(insertion_sort_t,best_t,result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				break;
				
				//insertion worst
			case 'g':
				benchmark(insertion_sort_t,worst_t,result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				break;
				
				//insertion average
			case 'h':
				benchmark(insertion_sort_t,average_t,result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				break;
				
				
				//quick best
			case 'i':
				benchmark(quick_sort_t,best_t,result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				break;
				
				//quick worst
			case 'j':
				benchmark(quick_sort_t,worst_t,result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				
				break;
				
				//quick average
			case 'k':
				benchmark(quick_sort_t,average_t,result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				
				break;
				
				
				
				//linear best
			case 'l':
				benchmark(linear_search_t,best_t,result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				break;
				
				//linear worst
			case 'm':
				benchmark(linear_search_t,worst_t,result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				break;
				
				//linear average
			case 'n':
				benchmark(linear_search_t,average_t,result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				break;
				
				
				
				//binary best
			case 'o':
				benchmark(binary_search_t,best_t,result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				break;
				
				//binary worst
			case 'p':
				benchmark(binary_search_t,worst_t,result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				break;
				
				//binary average
			case 'q':
				benchmark(binary_search_t,average_t,result, RESULT_ROWS);
				
				for (int i=0;i<RESULT_ROWS;i++) printf("Size: %d  Time: %e  T/n: %e  T/n^2 %e  T/n^2 %e  T/log(n) %e  T/nlog(n) %e\n\n",result[i].size,result[i].time,result[i].time/result[i].size,result[i].time/pow(result[i].size,2),result[i].time/pow(result[i].size,3),result[i].time/log(result[i].size),result[i].time/(result[i].size*log(result[i].size)));

				
				break;
				

			// Invalid input
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		
				
		}
	}
	ui_exit();
}
