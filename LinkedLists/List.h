class List{
	public:	
		virtual void addNum(int num) = 0;
		virtual int removeHead() = 0;
		virtual int removeTail() = 0;
		virtual int removeNum(int num) = 0;
		virtual void addAt(int num, int pos) = 0;
		virtual int removeAtPos(int pos) = 0;
		virtual int getNumAtPos(int pos) = 0;
		virtual void removeAll() = 0;
		virtual void printList() = 0;
};
