/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Simple_window win (Point{100,100},600,400,"Canvas");

    Axis x (Axis::x,Point(20,300),400,10,"x");
    Axis y (Axis::y,Point(200,400+20),600,10,"y");
    x.set_color(Color::red);
    y.set_color(Color::red);

    Polygon poly;
    poly.add(Point(300,200));
    poly.add(Point(350,100));
    poly.add(Point(400,200));
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);

    Function sine (sin,0,100,Point(20,150),1000,50,50);

    Rectangle r (Point(200,200),100,50);
    Closed_polyline poly_rect;
    poly_rect.add(Point(100,100));
    poly_rect.add(Point(200,100));
    poly_rect.add(Point(300,150));
    poly_rect.add(Point(200,200));
    poly_rect.add(Point(100,200));
    //poly_rect.set_color(Color::blue);
    poly_rect.set_fill_color(Color::yellow);

    Text t(Point(150,150),"HELLO,GRAPHICAL WORD!");
    t.set_font_size(20);

    Image ii (Point(100,50),"badge.jpg");

    Circle c (Point(100,200),50);
   // Ellipse e(Point(100,200),75,25);
    Mark m (Point(100,200),'x');

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
    	<< ";window size: " << win.x_max() << "*" << win.y_max();
    Text sized(Point(100,20),oss.str());	

    win.attach(c);
    win.attach(m);
  //  win.attach(e);
    win.attach(sized);

/*
    win.attach(ii);
    win.attach(poly_rect);
    win.attach(sine);
    win.attach(poly);
    win.attach(x);
    win.attach(y);
    win.attach(r);
    win.attach(t);
 */ 

    

    win.wait_for_button();

}
