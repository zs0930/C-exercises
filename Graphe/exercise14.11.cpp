#include "Simple_window.h"
#include "Graph.h"
#include <vector>
#include "std_lib_facilities.h"

class Binary_tree : public Shape {
	
	public:
		Binary_tree (int level, int r, int x_max, int y_max_);
		void draw_lines() const;
		int level() const {return level_;}
		int x_max() const {return x_max_;}
		int y_max() const {return y_max_;}
		int r() const {return r_;}

	private:
		int level_;
		vector<Point> eclv_;
		vector<vector<Point>> totlv_;
		int x_max_;
		int y_max_;
		int r_;
};


Binary_tree::Binary_tree(int level, int r, int x_max, int y_max)
	:level_{level}, r_{r}, x_max_{x_max}, y_max_{y_max}
{
	if (level_>0){

		int max_elem = pow(2,level_-1);
		int d = x_max_/(2*(max_elem+1));

		for (int i=1;i<=level_;i++)
		{
			int lv_elem = pow(2,i-1);
			eclv_ = {};

			for (int j=1;j<=lv_elem;j++)
				eclv_.push_back({(pow(2,level_-i)*d+d+pow(2,level_-i+1)*d*(j-1)), i*y_max_/(level_+1)});

			totlv_.push_back(eclv_);
		}
	}
}

void Binary_tree::draw_lines() const 
{
	if(level_>0) fl_arc(totlv_.at(0).at(0).x-r_, totlv_.at(0).at(0).y-r_, 2*r_, 2*r_, 0, 360);

	for (int i=1;i<level_;i++)
	{
		for (int j=0;j<totlv_.at(i-1).size();j++)
		{
			fl_line(totlv_.at(i-1).at(j).x, totlv_.at(i-1).at(j).y, totlv_.at(i).at(2*j).x, totlv_.at(i).at(2*j).y);
			fl_line(totlv_.at(i-1).at(j).x, totlv_.at(i-1).at(j).y, totlv_.at(i).at(2*j+1).x, totlv_.at(i).at(2*j+1).y);
			fl_arc(totlv_.at(i).at(2*j).x-r_, totlv_.at(i).at(2*j).y-r_, 2*r_, 2*r_, 0, 360);
			fl_arc(totlv_.at(i).at(2*j+1).x-r_, totlv_.at(i).at(2*j+1).y-r_, 2*r_, 2*r_, 0, 360);
		}
	}
}


	
int main()
{
	using namespace Graph_lib;

	Binary_tree test(6, 5, 600, 400);

	Simple_window win {{100,100},600,400,"Canvas"};

	win.attach(test);
	win.wait_for_button();
}









