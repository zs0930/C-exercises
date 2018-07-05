#ifndef BOX
#define BOX

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

#endif
