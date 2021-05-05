#include "lib_files/Simple_window.h"
#include "lib_files/Graph.h"

//g++ Drill15.cpp lib_files/Graph.cpp lib_files/Window.cpp lib_files/GUI.cpp lib_files/Simple_window.cpp -o main `fltk-config --ldflags --use-images`


double one (double d) {return 1;}
double slope( double x) { return x/2; }
double square(double x) { return x*x; }
double slope_cos(double x) { return cos(x)+slope(x);}

int main()
{
	using namespace Graph_lib;

	int xmax = 600;
	int ymax = 600;

	int x_orig = xmax/2;
	int y_orig = ymax/2;

	int rmin = -10;
	int rmax = 10;

	int n_points = 400;

	Simple_window win {Point{100,100},xmax,ymax,"Function graphs"};


	Point origo {x_orig,y_orig};

	int xlenght = xmax -40;
	int ylenght = ymax -40;

	int xscale = 20,yscale =20;

	Function s(one,rmin,rmax,origo, n_points,xscale,yscale);
	
	Function s2(slope,rmin,rmax,origo, n_points,xscale,yscale);
	Text tx (Point(x_orig-200,y_orig+120),"x/2");
	tx.set_font_size(20);
	
	Function s3(square,rmin,rmax,origo, n_points,xscale,yscale);
	Function s4([](double x){return sin(x);},rmin,rmax,origo, n_points,xscale,yscale);
	s4.set_color(Color::blue);

	Function s5(slope_cos,rmin,rmax,origo, n_points,xscale,yscale);


	Axis x {Axis::x , Point{x_orig-400/2,y_orig} ,400,20,"X"};
	x.set_color(Color::red);

	Axis y {Axis::y , Point{x_orig,y_orig+400/2} ,400,20,"Y"};
	y.set_color(Color::red);


	win.attach(x);
	win.attach(y);

	win.attach(s);
	win.attach(s2);
	win.attach(tx);
	win.attach(s3);
	win.attach(s4);
	win.attach(s5);

	win.wait_for_button();

}