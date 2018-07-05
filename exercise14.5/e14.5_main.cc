#include "Graph.h"
#include "Simple_window.h"
#include "e14.5_Sr.h"

//to draw a rectangle filled with lines as pattern

	
int main()
{
	using namespace Graph_lib;

	Striped_rectangle test({100,50},300,200,20);

	Simple_window win {{100,100},600,400,"Canvas"};

	win.attach(test);
	win.wait_for_button();
}

