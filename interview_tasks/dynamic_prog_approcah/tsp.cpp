#include <iostream>
#include <vector>
using namespace std;

/*
	Traveling Salesman Problem (TSP) Implementation:
	1. First define starting and endig point in the graph
	2. Generate all (n-1)! permutations of cities.
	3. Calculate cost of every permutation and keep track for minimum cost
	4. Return minimum cost

	sample:
		int graph[][V] = { { 0, 10, 15, 20 }, 
                       { 10, 0, 35, 25 }, 
                       { 15, 35, 0, 30 }, 
                       { 20, 25, 30, 0 } }; 
		((1))
		 
	    /    20|   \

	10/     ((4))    \15

        /   /25     \30    \
      ((2))-------35-------((3))
minimum weight Hamiltonian Cycle : 10 + 20 + 30 + 15 = 80
*/

#define V 4

int TSP(int graph[][V], int s)
{
	// store all vertex to vector
	vector <int> vertex;
	for (int i = 0; i < V; i++) {
		if (i != s)
			vertex.push_back(i);
	}
	// store minimum weight Hamiltonian Cycle.
	int minPath = INT_MAX;
	
	do {
		// store current path weight 
		int currentPathWeight = 0;
	
		// compute current path waight
		int k = s;

		for (int i = 0; i < vertex.size(); i++) {
			currentPathWeight += graph[k][vertex[i]];
			k = vertex[i];
		}
		currentPathWeight += graph[k][s];

		// update minimum
		minPath = min(minPath, currentPathWeight);
	} while (next_permutation(vertex.begin(), vertex.end()));
	return minPath;
}

int
main ()
{
	int graph[][V] = { { 0, 10, 15, 20 }, 
                       { 10, 0, 35, 25 }, 
                       { 15, 35, 0, 30 }, 
                       { 20, 25, 30, 0 } }; 
	int s = 0; 
	cout << TSP(graph, s) << endl;
	
	return 0;
}

