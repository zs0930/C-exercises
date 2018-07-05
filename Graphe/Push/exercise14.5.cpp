#include "Graph.h"
#include "Simple_window.h"

//to draw a rectangle filled with lines as pattern


class Striped_rectangle :public Shape {

	public:

	Striped_rectangle(Point p, int w, int h, int ls);

	void draw_lines() const;

	int height() const { return h_; }
	int width() const { return w_; }

	private:

	int h_;			// height
	int w_;			// width
	int ls_;                // line spacing
};


Striped_rectangle::Striped_rectangle(Point p, int w, int h, int ls) 
	:w_{ w }, h_{ h }, ls_{ ls }
	{
		if (h<=0 || w<=0) error("Bad rectangle: non-positive side");
		add(p);
	}

void Striped_rectangle::draw_lines() const
{

	if (color().visibility()) {	
		fl_color(color().as_int());
		fl_rect(point(0).x,point(0).y,w_,h_);
	}
	
	fl_line_style(1,2,0);

	for(int i=ls_;i<w_;i=i+ls_)
		fl_line(point(0).x+i, point(0).y, point(0).x+i, point(0).y+h_);
}

	
int main()
{
	using namespace Graph_lib;

	Striped_rectangle test({100,50},300,200,20);

	Simple_window win {{100,100},600,400,"Canvas"};

	win.attach(test);
	win.wait_for_button();
}

