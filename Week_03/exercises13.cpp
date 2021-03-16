#include "./lib_files/Simple_window.h"
#include "./lib_files/Graph.h"

int main()
try{
	using namespace Graph_lib;
	
	Point t1(200,50);
	Simple_window win(t1,800,1000,"exercises 13");

//01

	Arc arc1(Point(150,100),100,50,45,175);
	win.attach(arc1);

	win.wait_for_button();
//02
	Box box1(Point(300,100),100,80);
	win.attach(box1);
	win.wait_for_button();

	Box box2 (Point(450,100),200,100,30);
	win.attach(box2);
	win.wait_for_button();
//3
	Arrow arrow1 (Point(100,500),Point(400,450));
	win.attach(arrow1);
	win.wait_for_button();

	Arrow arrow2 (Point(500,500),Point(750,50));
	win.attach(arrow2);
	arrow2.set_color(Color::red);
	win.wait_for_button();
//04
	Graph_lib::Rectangle rect1(Point(500,150),150,150);
	win.attach(rect1);
	Arrow nwr(nw(rect1), Point(nw(rect1).x-30, nw(rect1).y-30));
	win.attach(nwr);
	Arrow nr(n(rect1), Point(n(rect1).x, n(rect1).y-30));
	win.attach(nr);
	
	Arrow ner(ne(rect1), Point(ne(rect1).x+30, ne(rect1).y-30));
	win.attach(ner);
	Arrow er(e(rect1), Point(e(rect1).x+30, e(rect1).y));
	win.attach(er);
	Arrow ser(se(rect1), Point(se(rect1).x+30, se(rect1).y+30));
	win.attach(ser);
	Arrow sr(s(rect1), Point(s(rect1).x, s(rect1).y+30));
	win.attach(sr);
	Arrow wr(w(rect1),Point(w(rect1).x-30,w(rect1).y));
	win.attach(wr);
	Arrow swr(sw(rect1),Point(sw(rect1).x-30,sw(rect1).y+30));
	win.attach(swr);
	Arrow cenr(center(rect1),Point(center(rect1).x+30,center(rect1).y+30));
	win.attach(cenr);

	win.wait_for_button();	


//5	
	Graph_lib::Circle cir1(Point(500,500),150);
	win.attach(cir1);
	Arrow nwr2(nw(cir1), Point(nw(cir1).x-30, nw(cir1).y-30));
	win.attach(nwr2);
	Arrow nr2(n(cir1), Point(n(cir1).x, n(cir1).y-30));
	win.attach(nr2);
	
	Arrow ner2(ne(cir1), Point(ne(cir1).x+30, ne(cir1).y-30));
	win.attach(ner2);
	Arrow er2(e(cir1), Point(e(cir1).x+30, e(cir1).y));
	win.attach(er2);
	Arrow ser2(se(cir1), Point(se(cir1).x+30, se(cir1).y+30));
	win.attach(ser2);
	Arrow sr2(s(cir1), Point(s(cir1).x, s(cir1).y+30));
	win.attach(sr2);
	Arrow w2(w(cir1), Point(w(cir1).x-30, w(cir1).y));
	win.attach(w2);
	Arrow sw2(sw(cir1), Point(sw(cir1).x-30, sw(cir1).y+30));
	win.attach(sw2);
	Arrow cenr2(center(cir1), Point(center(cir1).x+30, center(cir1).y+30));
	win.attach(cenr2);
//6




	win.wait_for_button();	

	
}catch(exception& e){
	cerr << 'exception: ' << e.what()<<endl;
	keep_window_open();
}catch(...){
	cerr << "exception\n";
	keep_window_open();
}