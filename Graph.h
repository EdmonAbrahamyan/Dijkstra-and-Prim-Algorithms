#pragma once
class Graph
{
public:
	Graph(int n);
	~Graph();
	void print()const;
	int**& getMatrix();
	int getn();
private:
	int**	matrix_;
	int		n_;
};
