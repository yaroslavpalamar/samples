#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

/* DFS implementation 
 *
 * Part of code to display graph represented by adjacency list 
 * and Depth First Search algorithm to traverse the graph. 
 * 1. Create graph obj wiht size of vertexes passed to constructor and allocate mem to adj list
 * 2. Add Methods DFS(startVert) and addEdge(v, w)
 * 3. Inside DFS create vector with visited nodes and stack for iterative solution
 * 4. Put first vertex in stack (call recursively function or push in stack)
 * 5. Inside recurs util or in while untill stack not empty check if node not visited mark it and print it\
 * 6. After that in for() loop for all vertexes push values in stack (or call recurs function) if vertex not visited.
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
	void DFSrecUtil (int startVert, vector<bool>& visited)
	{	
		// If vertex not visited we print the popped items.
                if (!visited[startVert]) {
                	cout << startVert << " ";
                	visited[startVert] = true;
                }
                // Go through vertex represented by adjacency list 
                // and put not visited vertex to stack. 
                for (list<int>::iterator i = adjLst[startVert].begin(); i!=adjLst[startVert].end();i++) {
                	if(!visited[*i]) {
						DFSrecUtil(*i, visited);
                	}
                }
	}
	void recursDFS (int startVert){
		vector<bool> visited(vertexNum, false);
		DFSrecUtil (startVert, visited);
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
        const int VERT_NUM = 8;
        Graph g(VERT_NUM);
        g.addEdge(0, 7);
        g.addEdge(1, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(1, 6);
        g.addEdge(2, 3);
        g.addEdge(3, 2);
        g.addEdge(4, 3);
	g.addEdge(4, 5);

        g.printAdjLists(VERT_NUM);

        cout << "\nDFS print:" << endl;
        cout <<"\ntest 1: start from 0:" <<endl;
        cout << "iterative output:";
	g.DFS(0);
	cout << endl;
	cout <<"recurs output: ";
	g.recursDFS(0);
	cout << endl;

        cout <<"\ntest 2: start from 2:" <<endl;
        cout << "iterative output:";
	g.DFS(2);
	cout << endl;
	cout <<"recurs output:"; 
	g.recursDFS(2); 
	cout << endl;

        cout <<"\ntest 3: start from 3:" << endl;
        cout << "iterative output:"; 
	g.DFS(3);
	cout << endl;

        cout <<"\ntest 4: start from 4:" << endl;
        cout << "iterative output:"; 
	g.DFS(4);
	cout << endl;

        return 0;

}

