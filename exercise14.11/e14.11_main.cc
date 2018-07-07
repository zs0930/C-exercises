#include "Simple_window.h"
#include "Graph.h"
#include <vector>
#include "std_lib_facilities.h"
#include "e14.11_Bt.h"

	
int main()
{
	using namespace Graph_lib;

	Binary_tree test(6, 5, 600, 400);

	Simple_window win {{100,100},600,400,"Canvas"};

	win.attach(test);
	win.wait_for_button();
}


