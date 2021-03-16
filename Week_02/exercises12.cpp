/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
// ex1

    using namespace Graph_lib;

    //Simple_window win(Point{100,100},2000,2000,"big");
    Simple_window win (Point{100,100},600,400,"a random Picture ");

    Rectangle r (Point(100,100),100,50);
    r.set_color(Color::blue);

    Polygon poly_r;
    poly_r.add(Point(200,200));
    poly_r.add(Point(300,200));
    poly_r.add(Point(300,250));
    poly_r.add(Point(200,250));
    poly_r.set_color(Color::red);

    win.attach(r);
    win.attach(poly_r);

    win.wait_for_button();

//ex2
    Rectangle r2 (Point(300,300),100,30);
    Text t2(Point(315,315),"Howdy!");

    win.attach(r2);
    win.attach(t2);
    win.wait_for_button();

//ex3    
    Text k1(Point(150,150),"K");
    Text k2(Point(200,150),"K");

    k1.set_color(Color::red);
    k1.set_font_size(50);
   // k1.set_font(Font::arial);
    win.attach(k1);
    
    k2.set_color(Color::green);
	k2.set_font_size(50);
	//k2.set_font(Font::arial);
	win.attach(k2);
	win.wait_for_button();
	

//ext4	
Vector_ref<Rectangle> rv;
int startx = 100;
int starty = 100;
int i =0;
for (int oszlop = 0; oszlop < 8; ++oszlop)
{
	for (int sor = 0; sor < 8; ++sor)
	{
		//Rectangle b1 (Point(startx+i*20,starty+j*20),20,20);
		rv.push_back(new Rectangle(Point(startx+sor*20,starty+oszlop*20),20,20));

		if(oszlop%2==0)
		{
			if(sor%2==0){	rv[i].set_fill_color(Color::red);}
			else{rv[i].set_fill_color(Color::white); }
		}
		else
		{
			if(sor%2==0){	rv[i].set_fill_color(Color::white);}
			else{rv[i].set_fill_color(Color::red); }
		}
		
		win.attach(rv[i]);
		i++;
	}
}
	win.wait_for_button();
	
//ex5

Rectangle rec (Point(150,150),x_max()*2/3,y_max()*3/4);
rec.set_style(Line_style(Line_style::solid,8));
rec.set_color(Color::black);

//win.attach(rec);
//win.wait_for_button();

//ex7

Rectangle alap (Point(200,200),200,200);
alap.set_fill_color(Color::white);

Rectangle ablak1 (Point(225,225),50,50);
ablak1.set_fill_color(Color::yellow);

Rectangle ablak2 (Point(325,225),50,50);
ablak2.set_fill_color(Color::yellow);

Rectangle ajto (Point(275,325),50,75);
ajto.set_fill_color(Color::green);

Polygon teto;

teto.add(Point(200,200));
teto.add(Point(400,200));
teto.add(Point(300,100));
teto.set_fill_color(Color::red);

Polygon kemeny;

kemeny.add(Point(250,150));
kemeny.add(Point(275,125));
kemeny.add(Point(275,100));
kemeny.add(Point(250,100));
kemeny.set_fill_color(Color::red);

Rectangle kemeny_up (Point(237.5,87.5),50,12.5);
kemeny_up.set_fill_color(Color::red);

Vector_ref <Circle> cv; 

for (int i = 0; i < 10; ++i)
{
	cv.push_back(new Circle (Point(265,60-i*2),20-i));
	cv[i].set_fill_color(Color::white);
	win.attach(cv[i]);
}

win.attach(kemeny);
win.attach(kemeny_up);
win.attach(alap);
win.attach(ablak1);
win.attach(ablak2);
win.attach(ajto);
win.attach(teto);

win.wait_for_button();

//ex8

Circle c1 (Point(100,300),50);
c1.set_color(Color::blue);
win.attach(c1);

Circle c2 (Point(200,300),50);
c2.set_color(Color::black);
win.attach(c2);

Circle c3 (Point(300,300),50);
c3.set_color(Color::red);
win.attach(c3);

Circle c4 (Point(150,350),50);
c4.set_color(Color::yellow);
win.attach(c4);

Circle c5 (Point(250,350),50);
c5.set_color(Color::green);
win.attach(c5);

win.wait_for_button();

//ex9

 Image random (Point(100,50),"random.jpg");
  ostringstream oss;
    oss << "a random Picture ";
    Text text(Point(100,20),oss.str());

   win.attach(random) ;
   win.attach(text);
win.wait_for_button();

}   
