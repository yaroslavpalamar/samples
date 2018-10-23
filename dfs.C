#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

/* DFS implementation 
 *
 * Part of code to display graph represented by adjacency list 
 * and Depth First Search algorithm to traverse the graph. 
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
	void DFS (int startVert) {
		// vector for marking visited vertices
		// on the begining they are all marked as not visited
		vector<bool> visited(vertexNum, false);

		stack<int> stack;
		// start traversal by pushing node to the stack
		stack.push(startVert);
		while (!stack.empty()) {
			// pop vertex from the stack and change startVert value.
			int startVert = stack.top();
			stack.pop();

			// If vertex not visited we print the popped items.
			if (!visited[startVert]) 
			{ 
				cout << startVert << " "; 
				visited[startVert] = true; 
			}
			// Go through vertex represented by adjacency list 
			// and put not visited vertex to stack. 
			for (list<int>::iterator i = adjLst[startVert].begin(); i!=adjLst[startVert].end();i++) {
				if(!visited[*i]) {
					stack.push(*i);
				}
			}
		}

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
	
	cout << "\nDFS print:" << endl;
	g.DFS(0);

	return 0;
}

