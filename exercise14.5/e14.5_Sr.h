#ifndef SR
#define SR

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

#endif
