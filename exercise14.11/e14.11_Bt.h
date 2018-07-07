#ifndef BINARY_TREE
#define BINARY_TREE

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

#endif
