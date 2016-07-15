#include <stdlib.h>
#include <unistd.h>
#include <libfb.h>

Point ball;

void update_ball(Point, int, int, Color);

int main()
{
	lfb_init();
	
	ball.x = 10; ball.y = 10;
	
	while(1){
		lfb.fillscr(BLACK);
	
		lfb.drawline((Point){lfb.width/2, 0}, (Point){lfb.width/2, lfb.height}, 1, WHITE);
		
		lfb.fillbox(50,200,50,200,WHITE);

		lfb.fillbox(700,200,50,200,WHITE);
	
	//	lfb.fillbox(100,100,300,200,YELLOW);
		
	
		update_ball(ball, 10,10,WHITE);
		//lfb.fillbox(ball.x - 5, ball.y - 5, 10, 10, WHITE);
		ball.x++; ball.y++;
		
/*		int i;
		for(i = 10; i < 590; i++){
		lfb.drawline((Point){0, i}, (Point){800, i}, 1, GREEN);
		usleep(10000);
		lfb.drawline((Point){0, i - 1}, (Point){800, i - 1}, 1, BLACK); 
		}
*/		
		if(ball.y == 600 - 5) break;
		lfb.refresh();
		usleep(30000);
	}

	return EXIT_SUCCESS;
}

void update_ball(Point ball, int w, int h, Color color)
{
	lfb.fillbox(ball.x, ball.y, w, h, color);
}
