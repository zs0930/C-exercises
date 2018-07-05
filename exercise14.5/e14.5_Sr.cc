#include "Graph.h"
#include "Simple_window.h"
#include "e14.5_Sr.h"

//to draw a rectangle filled with lines as pattern

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


