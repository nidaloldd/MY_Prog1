/*
    g++ Drill16.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "GUI.h"
#include "Window.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;


struct Lines_window : Window { 
Lines_window(Point xy, int w, int h, const string& title); 

private: 

Open_polyline lines; 
void change_c(Color c) { lines.set_color(c); } 
void change_s(Line_style s) { lines.set_style(s); } 
void hide_c_menu() { color_menu.hide(); menu_c_button.show(); } 
void hide_s_menu() { style_menu.hide(); menu_s_button.show(); } 

// widgets: 
Button next_button; // add (next_x,next_y) to lines 
Button quit_button; // end program 
Button menu_c_button; 
Button menu_s_button; 
Menu color_menu; 
Menu style_menu; 
In_box next_x; 
In_box next_y; 
Out_box xy_out; 


// actions invoked by cal lbacks: 
void red_pressed() { change_c(Color::red); hide_c_menu(); } 
void blue_pressed() { change_c(Color::blue); hide_c_menu(); } 
void black_pressed() { change_c(Color::black); hide_c_menu(); } 
void dot_pressed() { change_s(Line_style::dot); hide_s_menu(); } 
void dash_pressed() { change_s(Line_style::dash); hide_s_menu(); } 
void solid_pressed() { change_s(Line_style::solid); hide_s_menu(); }
void menu_c_pressed() { menu_c_button.hide(); color_menu.show(); } 
void menu_s_pressed() { menu_s_button.hide(); style_menu.show(); } 
void next(); 
void quit(); 
// callback functions: 
/*
static void cb_red(Address, Address); 
static void cb_blue(Address, Address); 
static void cb_black(Address, Address); 
static void cb_menu(Address, Address); 
static void cb_next(Address, Address); 
static void cb_quit(Address, Address); 
*/
};

Lines_window:: Lines_window(Point xy, int w, int h, const string& title) 
: Window(xy, w, h, title), 
color_menu{Point(x_max()-70,30), 70,20,Menu::vertical, "color"}, 
style_menu{Point(0,30), 70,20,Menu::vertical, "style"}, 
menu_c_button{Point(x_max()-80,30), 80, 20, "color menu", [](Address, Address pw) {reference_to<Lines_window>(pw).menu_c_pressed();}},
menu_s_button{Point(0,30), 80, 20, "style_menu", [](Address, Address pw) {reference_to<Lines_window>(pw).menu_s_pressed();}}, 
next_button{Point(x_max()-150,0), 70, 20, "Next point", [](Address, Address pw) {reference_to<Lines_window>(pw).next();}}, 
quit_button{Point(x_max()-70,0), 70, 20, "Quit", [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}}, 
next_x{Point(x_max()-310,0), 50, 20, "next x:"}, 
next_y{Point(x_max()-210,0), 50, 20, "next y:"}, 
xy_out{Point(100,0), 60, 20, "current (x,y):"} 
{
attach(next_button); 
attach(quit_button); 
attach(next_x); 
attach(next_y); 
attach(xy_out); 
xy_out.put("no point"); 
color_menu.attach(new Button(Point(0,0),0,0, "red" ,[](Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();})); 
color_menu.attach(new Button(Point(0,0),0,0, "blue" ,[](Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();})); 
color_menu.attach(new Button(Point(0,0),0,0, "black" ,[](Address, Address pw) {reference_to<Lines_window>(pw).black_pressed();})); 

style_menu.attach(new Button(Point(0,0),0,0, "dot" ,[](Address, Address pw) {reference_to<Lines_window>(pw).dot_pressed();})); 
style_menu.attach(new Button(Point(0,0),0,0, "dash" ,[](Address, Address pw) {reference_to<Lines_window>(pw).dash_pressed();})); 
style_menu.attach(new Button(Point(0,0),0,0, "solid" ,[](Address, Address pw) {reference_to<Lines_window>(pw).solid_pressed();})); 


attach(color_menu); 
attach(style_menu); 
color_menu.hide(); 
style_menu.hide(); 
attach(menu_c_button); 
attach(menu_s_button); 
attach(lines); 
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

int main()
{
    Lines_window win {Point{100,100}, 600, 500, "Drill16"};
    
    return gui_main();
}
