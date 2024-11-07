class List{
	public:
		virtual node* addRoot(int num) = 0;
		virtual node* addLeft(node* n, int num) = 0;
		virtual node* addRight(node* n, int num) = 0;
		virtual node* remove(node* n) = 0;
		virtual node* sibling(node* n) = 0;
		virtual node* left(node* n) = 0;
		virtual node* right(node* n) = 0;
		virtual void print() = 0;
};
