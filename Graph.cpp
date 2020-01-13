#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph(int n) : n_(n), matrix_(new int*[n])
{
	int i, j;
	for (i = 0; i < n; i++) {
		matrix_[i] = new int[n];
		for (j = 0; j < n; j++)
			matrix_[i][j] = 0;
	}
}

Graph::~Graph()
{
	for (int i = 0; i < n_; i++)
		delete[] matrix_[i];
	delete[]matrix_;
}

int**&
Graph::getMatrix()
{
	return matrix_;
}

void
Graph::print()const
{
	cout << "[adjacency matrix]" << endl;
	int i, j;
	for (i = 0; i < n_; i++) {
		for (j = 0; j < n_; j++)
			cout << matrix_[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
int 
Graph::getn() {
	return n_;
}
