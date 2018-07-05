#include "Graph.h"
#include "Simple_window.h"
#include "e13.2_Box.h"

//to draw a box with rounded corner

int main()
{
	using namespace Graph_lib;

	Box test({100,50},300,80);

	Simple_window win {{100,100},600,400,"Canvas"};

	win.attach(test);
	win.wait_for_button();
}

