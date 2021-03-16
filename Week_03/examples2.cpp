//g++ -w -Wall -std=c++0x  ./lib_files/Graph.cpp ./lib_files/Window.cpp ./lib_files/GUI.cpp ./lib_files/Simple_window.cpp examples2.cpp `fltk-config --ldflags --use-images` -o a.out

#include "./lib_files/Simple_window.h"
#include "./lib_files/Graph.h"

int main()
try {
	using namespace Graph_lib;
	
	Point t1(200,50);
	Simple_window win(t1,800,600,"Labor 3");
	
	int x_size = win.x_max();
	int y_size = win.y_max();
	int x_grid = 80;
	int y_grid = 40;

	Lines grid;

	for (int x=x_grid ; x < x_size; x+=x_grid)
	{
		grid.add(Point(x,0),Point(x,y_size));
	}

	for (int y=y_grid ; y < y_size; y+=y_grid)
	{
		grid.add(Point(0,y),Point(x_size,y));
	}

	win.attach(grid);

	win.wait_for_button();

} catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
} catch (...) {
	cerr << "exception\n";
	keep_window_open();
}
