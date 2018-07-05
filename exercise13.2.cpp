#include "Graph.h"
#include "Simple_window.h"

class Box:Shape {

Public:
	Box(Point p, int s, int r);
	void draw_lines() const;
	int radius() const {return r_;}
	int side() const {return s_;}

P
	//Polygon poly;

	//poly.add(Point{300,200});
	//poly.add(Point{350,100});
	//poly.add(Point{400,200});

	//poly.set_color(Color::red);

	//win.attach(poly);rivate:
	int r_;  //radius of the rounded corners
	int s_;  //distance between two parallel sides
};

Box::Box(Point p, int s, int r)
	:r_{r}, s_{s}
{
	if(r_<0||s_<=0) error("Bad box: non-positive side or negtive radius");
	if(2*r_>=s) error("Bad box: no straight side part");
	add(p);
}

void Box::draw_lines() const
{
	add({point.at(0).x+r_,point.at(0).y+r_});
	add({point.at(0).x+r_,point.at(0).y+s_-r_});
	add({point.at(0).x+s_-r_,point.at(0).y+s_-r_});
	add({point.at(0).x+s_-r_,point.at(0).y+r_});
	
	add({point.at(1).x,point.at(1).y-r_});
	add({point.at(4).x,point.at(4).y-r_});
	add({point.at(4).x+r_,point.at(4).y});
        add({point.at(3).x+r_,point.at(3).y});
        add({point.at(3).x,point.at(3).y+r_});
        add({point.at(2).x,point.at(2).y+r_});
        add({point.at(2).x-r_,point.at(2).y});
        add({point.at(1).x-r_,point.at(1).y});
        
	const int num_center_point=4;
	const int num_edge_point=8;

	for (int i=1;i<=num_center_point;i++)
		fl_arc(point.at(i).x, point.at(i).y, r_, 90*i, 90+90*i);

	for (int i=1;i<=num_edge_point;i=i+2)
		fl_line(point.at(i+4).x,point.at(i+4).y,point.at(i+5).x,point.at(i+5).y);
}

	
int main()
{
	using namespace Graph_lib;

	Box test({100,100},200,50);

	Simple_window win {{100,100},600,400,"Canvas"};

	win.attach(test);
	win.wait_for_button();
}

