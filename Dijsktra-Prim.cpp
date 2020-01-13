// Prim_Dijkstra.cpp : Defines the entry point for the console application.
//

#include "Graph.h"
#include <iostream>
using namespace std;

Graph*
createPrimsInstance() {
	int n = 6;
	Graph* result = new Graph(n);
	int**& matrix = result->getMatrix();
	matrix[0][1] = 4; matrix[0][3] = 3; matrix[0][4] = 1;
	matrix[1][0] = 4; matrix[1][2] = 3; matrix[1][5] = 4;
	matrix[2][1] = 3; matrix[2][3] = 2;
	matrix[3][0] = 3; matrix[3][2] = 2; matrix[3][4] = 4;
	matrix[4][0] = 1; matrix[4][3] = 4; matrix[4][5] = 2;
	matrix[5][1] = 4; matrix[5][4] = 2;
	return result;
}

Graph*
createDijkstrasInstance() {
	int n = 6;
	Graph* result = new Graph(n);
	int**& matrix = result->getMatrix();
	matrix[0][1] = 9; matrix[0][3] = 8; matrix[0][4] = 1;
	matrix[1][2] = 4;
	matrix[3][2] = 1;
	matrix[4][3] = 5; matrix[4][5] = 2;
	matrix[5][1] = 3;
	return result;
}
int minKey(int x, int key[], char status[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < x; v++) {
		if (status[v] == 'q' && key[v] < min)
			min = key[v], min_index = v;
	}
	return min_index;
}
 //Prim algorithm realization
Graph*
primsMST(Graph* graph)
{
	int n = graph->getn();
	int* parent = new int[n];
	char* status = new char[n];
	int * key = new int[n];
	for (int i = 0; i < n; ++i)
	{
		status[i] = 'q';
		key[i] = INT_MAX;
	}
	key[0] = 0;
	parent[0] = -1;

	Graph* primgraph = new Graph(n);
	int **& primmatrix = primgraph->getMatrix();

	for (int i = 0; i < n - 1; i++)
	{
		int u = minKey(n, key, status);
		status[u] = 't';
		for (int v = 0; v < n; v++) {
			if (graph->getMatrix()[u][v] && status[v] == 'q' && graph->getMatrix()[u][v] < key[v])
				parent[v] = u, key[v] = graph->getMatrix()[u][v];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (parent[j] == i)
				primmatrix[i][j] = key[j];
		}
		primmatrix[i][parent[i]] = key[i];
	}
	return primgraph;
}

int minDistance(int x, int dist[], char status[])
{
	int min = INT_MAX, index;

	for (int v = 0; v < x; v++)
		if (status[v] == 'q' && dist[v] <= min)
			min = dist[v], index = v;

	return index;
}
// Dijkstra algorithm realization 
Graph*
dijkstrasSSSP(Graph* graph)
{
	int n = graph->getn();
	int* pred = new int[n];
	char* status = new char[n];
	int* dist = new int[n];
	for (int i = 0; i < n; ++i)
	{
		status[i] = 'q';
		dist[i] = INT_MAX;
	}
	pred[0] = -1;
	dist[0] = 0;


	for (int i = 0; i < n - 1; i++) {
		int u = minDistance(n, dist, status);
		status[u] = 't';
		for (int v = 0; v < n; v++)
		{

			if (status[v] != 't' && graph->getMatrix()[u][v] && dist[u] != INT_MAX && dist[u] + graph->getMatrix()[u][v] < dist[v])
			{
				dist[v] = dist[u] + graph->getMatrix()[u][v]; pred[v] = u;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << dist[i] << "   " << status[i] << "   " << pred[i] << endl;
	}
	Graph* dijgraph = new Graph(n);
	int **& dijmatrix = dijgraph->getMatrix();

	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k)
		{
			if (pred[k] == i)
			{
				dijmatrix[i][k] = dist[k];
			}
		}
	}

	return dijgraph;
}

int main()
{
	Graph* primsInstance = createPrimsInstance();
	cout << "***** PRIMS INSTANCE *****" << endl;
	primsInstance->print();
	cout << "- - - PRIMS MST - - -" << endl;
	Graph* MST = primsMST(primsInstance);
	MST->print();

	Graph* dijkstrasInstance = createDijkstrasInstance();
	cout << endl << "***** DIJKSTRAS INSTANCE ******" << endl;
	dijkstrasInstance->print();
	cout << "- - - DIJKSTRAS SSSP - - -" << endl;
	Graph* SSSP = dijkstrasSSSP(dijkstrasInstance);
	SSSP->print();
	system("pause");
	return 0;
}
