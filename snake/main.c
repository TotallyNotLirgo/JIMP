#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#include <signal.h>

#define CLEAR_STRING "\e[1;1H\e[2J"
#define CLEAR_SCREEN() (printf(CLEAR_STRING))
#define WIDTH 40
#define HEIGHT 20
#define MAX_LENGTH WIDTH * HEIGHT
#define CLOCK_SPEED 200000

void quit(int sig)
{
	endwin();
	exit(0);
}

char get_last_char()
{
	int last_ch = -1;
	int c = -1;
	do
	{
		last_ch = c;
		c = getch();
	} while(c != -1);
	return last_ch;
}

void handle_input(char input, int *velocity_x, int *velocity_y)
{
	switch(input)
	{
		case 'w':
			*velocity_x = 0;
			*velocity_y = -1;
			break;
		case 's':
			*velocity_x = 0;
			*velocity_y = 1;
			break;
		case 'a':
			*velocity_x = -1;
			*velocity_y = 0;
			break;
		case 'd':
			*velocity_x = 1;
			*velocity_y = 0;
			break;
	}
}

void generate_food(int *food_x, int *food_y)
{
	*food_x = (double)rand() / RAND_MAX * WIDTH;	
	*food_y = (double)rand() / RAND_MAX * HEIGHT;	
}

void update_snake_position(int *snake_length, 
						   int x_positions[], 
						   int y_positions[], 
						   int velocity_x, 
						   int velocity_y,
						   int *food_x,
						   int *food_y)
{
	int i;
	if(x_positions[*snake_length-1] + velocity_x == *food_x && 
	   y_positions[*snake_length-1] + velocity_y == *food_y)
	{
		(*snake_length)++;
		x_positions[*snake_length - 1] = *food_x;
		y_positions[*snake_length - 1] = *food_y;
		generate_food(food_x, food_y);
	}
	else
	{
		for(i = 0; i < *snake_length - 1; i++)
		{
			x_positions[i] = x_positions[i + 1];	
			y_positions[i] = y_positions[i + 1];	
		}
		x_positions[*snake_length - 1] += velocity_x;
		y_positions[*snake_length - 1] += velocity_y;
		for(i = 0; i < *snake_length - 1; i++)
		{
			if (x_positions[*snake_length-1] == x_positions[i] && y_positions[*snake_length-1] == y_positions[i])
				quit(-1);
		}
		if(y_positions[*snake_length-1] < 0 || 
				y_positions[*snake_length-1] >= HEIGHT || 
				x_positions[*snake_length-1] < 0 || 
				x_positions[*snake_length-1] >= WIDTH)
			quit(-1);
	}
}

void display_board(int snake_length, int x_positions[], int y_positions[], int food_x, int food_y)
{
	int i, j, k, printed;
	for(i = 0; i < HEIGHT; i++)
	{
		for(j = 0; j < WIDTH; j++)
		{
			printed = 0;
			for(k = 0; k < snake_length; k++)
			{
				if (x_positions[k] == j && y_positions[k] == i)
				{
					printf("s");
					printed = 1;
				}
			}
			if(!printed)
			{
				if(food_x == j && food_y == i)
					printf("f");
				else
					printf(".");
			}
		}
		printf("\n\r");
	}
}

int main(void)
{
	int running = 1;
	int x_positions[MAX_LENGTH];
	int y_positions[MAX_LENGTH];
	int snake_length = 3;
	int food_position_x;
	int food_position_y;
	int velocity_x = 1;
	int velocity_y = 0;
	char buffer_char;
	initscr();
	cbreak();
	signal(SIGINT, quit);
	nodelay(stdscr, TRUE);
	noecho();
	srand(time(NULL));

	x_positions[0] = 20;
	x_positions[1] = 21;
	x_positions[2] = 22;
	y_positions[0] = 10;
	y_positions[1] = 10;
	y_positions[2] = 10;

	generate_food(&food_position_x, &food_position_y);
 	while(running)
	{
		int i, j, k;
		int printed;
		CLEAR_SCREEN();
		buffer_char = get_last_char();
		handle_input(buffer_char, &velocity_x, &velocity_y);
		update_snake_position(&snake_length, 
							  x_positions, 
							  y_positions, 
							  velocity_x, 
							  velocity_y, 
							  &food_position_x, 
							  &food_position_y);
		display_board(snake_length, x_positions, y_positions, food_position_x, food_position_y);

		usleep(CLOCK_SPEED);
		
	}
	return 0;
}
