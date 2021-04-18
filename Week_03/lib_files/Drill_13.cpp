#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	
	Point t1(200,50);
	Simple_window win(t1,800,1000,"Drill_3");

	Lines grid;

	int x_size = win.x_max();
	int y_size = win.y_max();
	int grid_size=100;

	for (int x = grid_size; x < x_size; x+=grid_size)
	{
		grid.add(Point(x,0),Point(x,y_size));
	}
	
	for (int y = grid_size; y < y_size; y+=grid_size)
	{
		grid.add(Point(0,y),Point(x_size,y));
	}
	win.attach(grid);

	//Vector_ref<Rectangle> rec;

	Vector_ref <Rectangle> rc;
	for (int i = 0; i < 8; ++i)
	{
		rc.push_back( new Rectangle (Point(i*100,i*100),100,100));
		rc[i].set_color(Color::red);
		win.attach(rc[i]);

	}

	Image im1 (Point(200,0),"badge.jpg");
	Image im2 (Point(400,200),"badge.jpg");
	Image im3 (Point(600,400),"badge.jpg");


	win.wait_for_button();
	win.attach(im1);
	win.attach(im2);
	win.attach(im3);
	
	Image random (Point(-100,0),"index.jpeg");
	random.set_mask(Point(120,50),100,100);
	
	for (int j = 0; j < 8; ++j)
	{
		for (int i = 0; i < 8; ++i)
		{
			random.move(100,0);
			win.attach(random);
			win.wait_for_button();
		}	
		random.move(-800,100);
		win.attach(random);
	}		


	//win.detach(grid);


	win.wait_for_button();

}	