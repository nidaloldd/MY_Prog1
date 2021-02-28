/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	Point t1 {100,100};
	Simple_window win {t1,600,400,"Canvas"};

	Polygon poly;

	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	win.attach(poly);

	win.wait_for_button();
}