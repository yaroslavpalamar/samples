#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

/* BFS implementation 
 *
 * Part of code to display graph represented by adjacency list 
 * and Breadth First Search algorithm to traverse the graph. 
 *
 * */

class Graph {
	int vertexNum;
	// pointer to adjacency list
	list <int>*adjLst;
public:
	Graph(int vertNum) 
	{ 
		this->vertexNum = vertNum; 
		adjLst = new list<int>[vertNum]; 
	} 
	void addEdge(int v, int w)
	{
		adjLst[v].push_back(w);
	}
	void BFS (int startVert) {
	}
	void printAdjLists(int vertexNum);
};

// print adjacency list representation of Graph
void
Graph::printAdjLists(int vertexNum) 
{
	for (int v = 0; v < vertexNum; ++v) 
	{ 
		cout << "\n Adjacency list of: (head " << v << ")"; 
		for (int node : adjLst[v]) {
			cout << "->" << node; 
		}
		cout<<endl; 
	}
}

int
main (int argc, char** argv)
{
	const int VERT_NUM = 5;
	Graph g(VERT_NUM);
	g.addEdge(0, 1); 
	g.addEdge(0, 4); 
	g.addEdge(1, 2);
	g.addEdge(1, 3); 
	g.addEdge(1, 4); 
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	g.printAdjLists(VERT_NUM);	
	
	cout << "\nBFS print:" << endl;
	//g.BFS(0);

	return 0;
}

