#include <Fl/Fl.h>
#include <Fl/Fl_Box.h>
#include <Fl/Fl_Window.h>

int main()
{
	Fl_Window window (200,200,"Window title");
	Fl_Box box (0,0,200,200,"Hey,I mean, hello world!");
	window.show();
	return Fl::run();
}
