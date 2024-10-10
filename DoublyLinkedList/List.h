#include "Node.h"
#pragma once
class List{
	public:
		virtual void addBetween(int num, Node* pred, Node* succ) = 0;
		virtual void add(int num) = 0;
		virtual void print() = 0;
};
