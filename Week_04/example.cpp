#include "./lib_files/Simple_window.h"
#include "./lib_files/Graph.h"

int main()
{

	using namespace Graph_lib;

	Point t1 (200,50);
	Simple_window win(t1,800,1000,"labor4");

	Smiley s1(Point(600,400),50);
	s1.set_fill_color(Color::yellow);
	win.attach(s1);

	Smiley_with_hat s2(Point(600,200),50);
	s2.set_fill_color(Color::green);
	win.attach(s2);

	Smiley_with_hat s3 (Point(200,400),50);
	s3.set_fill_color(Color::yellow);
	win.attach(s3);

	Frowny s4(Point(200,200),50);
	s4.set_fill_color(Color::red);
	win.attach(s4);


	Frowny_with_hat s5(Point(300,200),50);
	s5.set_fill_color(Color::yellow);
	win.attach(s5);

	Binary_tree tr (Point(400,50),5,"v");
	
	win.attach(tr);


	win.wait_for_button();

}