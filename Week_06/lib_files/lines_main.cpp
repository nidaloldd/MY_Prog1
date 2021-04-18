/*
    g++ lines_main.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o lines_main `fltk-config --ldflags --use-images`
*/
#include "Lines_window.h"
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

struct Lines_window :: Window { 
		Lines_window(Point xy, int w, int h, const string& title); 
		Open_polyline lines; 
		Menu color_menu; 
		static void cb_red(Address, Address); //II callback for red button 
		static void cb_blue(Address, Address); //II callback for blue button 
		static void cb_black(Address, Address); //II cal lback for black button 
		// the actions: 
		void red_pressed() { change( Color:: red); } 
		void blue_pressed() { change(Color:: blue); } 
		void black_pressed() { change( Color::black); }
		void change(Color c) { lines.set_color(c); }
};

Lines_window:: Lines_window(Point xy, int w, int h, const string& title) 
:Window(xy,w,h,title),color_menu(Point(x_max()-70,40) ,70,20,Menu::vertical," color") 
{
	color_menu.attach(new Button(Point(O,O),O,O, "red" ,cb_red)); 
	color_menu.attach(new Button(Point(O,O),O,O, "blue" ,cb_blue)); 
	color_menu.attach(new Button(Point(O,O),O,O, "black" ,cb_black)); 
	attach( color_menu); 
}


struct Lines_window : Window { 
Lines_window(Point xy, int w, int h, const string& title ); 
private: 
Open_polyline lines; 
// widgets: 
Button next_button; //II add (next_x,next_y) to lines 
Button quit_button; //II end program 
ln_box next_x; 
ln_box next_y; 
Out_box xy_out; 
Menu color_menu; 
Button menu_button; 
void change(Color c) { lines.set_color(c); } 
void hide_menu() { color_menu.hide(); menu_button.show(); }
}; 


void red_pressed() { change(Color::red); hide_menu(); } 
void blue_pressed() { change(Color::blue); hide_menu(); } 
void black_pressed() { change(Color::black); hide_menu(); } 
void menu_pressed() { menu_button.hide(); color_menu.show(); } 
void next(); 
void quit(); 

static void cb_red(Address, Address); 
static void cb_blue(Address, Address); 
static void cb_black(Address, Address); 
static void cb_menu(Address, Address); 
static void cb_next(Address, Address); 
static void cb_quit(Address, Address); 
    


Lines_window:: Lines_window(Point xy, int w, int h, const string& title) 
: Window(xy, w, h, title), color _menu(Point(x_max()-70,30), 70,20,Menu::vertical, "color"), 
menu_button(Point(x_max()-80,30), 80, 20, "color menu", cb_menu), 
next_button(Point(x_max()-150,0), 70, 20, "Next point", cb_next), 
quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit), 
next_x(Point(x_max()-310,0), 50, 20, "next x:"), 
next_y(Point(x_max()-210,0), 50, 20, "next y: "), 
xy_out(Point(100,0), 100, 20, "current (x,y):") 
{
	attach(next_button); 
	attach(quit_button); 
	attach(next_x); 
	attach(next_y); 
	attach(xy_out); 
	xy_out.put("no point"); 
	color_menu.attach(new Button(Point(O,O),O,O, "red" ,cb_red)); 
	color_menu.attach(new Button(Point(O,O),O,O, "blue" ,cb_blue)); 
	color_menu.attach(new Button(Point(O,O),O,O, "black" ,cb_black)); 
	attach(color_menu); 
	color_menu.hide(); 
	aHach(menu_button); 
	attach(lines); 
}

int main()
{
	Lines_window win {Point{100, 100}, 600, 400, "lines"};
	return gui_main();
    
};



    

