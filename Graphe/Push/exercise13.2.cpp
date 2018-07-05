#include "Graph.h"
#include "Simple_window.h"

//to draw a box with rounded corner

class Box:public Shape {

	public:
	Box(Point p, int s, int r);
	void draw_lines() const;
	int radius() const {return r_;}
	int side() const {return s_;}

	private:
	int r_;  //radius of the rounded corners
	int s_;  //distance between two parallel sides
};

Box::Box(Point p, int s, int r)
	:r_{r}, s_{s}
{
	if(r_<0||s_<=0) error("Bad box: non-positive side or negtive radius");
	if(2*r_>=s) error("Bad box: no straight side part");
	add(p);

	add({point(0).x,point(0).y+s_-2*r_});
	add({point(0).x+s_-2*r_,point(0).y+s_-2*r_});
	add({point(0).x+s_-2*r_,point(0).y});
	
	add({point(0).x+r_,point(0).y});
	add({point(0).x+s_-r_,point(0).y});
	add({point(3).x+2*r_,point(3).y+r_});
        add({point(2).x+2*r_,point(2).y+r_});
        add({point(2).x+r_,point(2).y+2*r_});
        add({point(1).x+r_,point(1).y+2*r_});
        add({point(1).x,point(1).y+r_});
        add({point(0).x,point(0).y+r_});
}

void Box::draw_lines() const
{       
	const int num_center_point=4;
	const int num_edge_point=8;

	for (int i=0;i<num_center_point;i++)
		fl_arc(point(i).x, point(i).y, 2*r_, 2*r_, 90*(i+1), 90*(i+2));

	for (int i=0;i<num_edge_point;i=i+2)
		fl_line(point(i+4).x,point(i+4).y,point(i+5).x,point(i+5).y);
}

	
int main()
{
	using namespace Graph_lib;

	Box test({100,50},300,80);

	Simple_window win {{100,100},600,400,"Canvas"};

	win.attach(test);
	win.wait_for_button();
}

