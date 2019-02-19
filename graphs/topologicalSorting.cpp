#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

/*
 * 1. Topological sorting is when every vertex have sequence from smaller to bigger. 
 * 2. We can run DFS on the graph and get !stack with verteces!.
 * 3. If we pop vertexes from stack and change every vertex from 
 * 	original value to sorted value
 * 	for example in stack was 1,4,3,2 and we change it to 1,2,3,4 
 * 	in result new graph with updated values from 1,4,3,2 to 1,2,3,4 will be sorted.
 */

/* DFS implementation 
 *
 * Part of code to display graph represented by adjacency list 
 * 1. topologicalSort() {create stack<int> stack(); mark every vertext of vector as false
	in for loop if vertex[]==false{call topologicalSortUtil(int v, bool visited[],stack<int> &Stack)
		vertex[v]=true}
		for(it=begin(); it != end(); it++)
			if !visited
				topologicalSortUtil(*i, visited, Stack);
		stack.push(i)}
   2. In while loop print all vertexes in stack
 *
 * */

class Graph {
	int vertexNum;
	// pointer to adjacency list
	list <int>*adjLst;
	// A function used by topologicalSort 
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
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
	void printAdjLists(int vertexNum);

	// prints a Topological Sort of the complete graph 
	void topologicalSort();
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

// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(int v, bool visited[],stack<int> &Stack) 
{ 
	// Mark the current node as visited. 
	visited[v] = true; 
  
	// Recur for all the vertices adjacent to this vertex 
	list<int>::iterator i; 
	for (i = adjLst[v].begin(); i != adjLst[v].end(); ++i) 
		if (!visited[*i]) 
			topologicalSortUtil(*i, visited, Stack); 
  
	// Push current vertex to stack which stores result 
	Stack.push(v); 
} 

// The function to do Topological Sort. It uses recursive  
// topologicalSortUtil() 
void 
Graph::topologicalSort() 
{ 
	stack<int> Stack; 
  
	// Mark all the vertices as not visited 
	bool *visited = new bool[vertexNum]; 
	for (int i = 0; i < vertexNum; i++) 
		visited[i] = false; 
  
	// Call the recursive helper function to store Topological 
	// Sort starting from all vertices one by one 
	for (int i = 0; i < vertexNum; i++) 
		if (visited[i] == false) 
			topologicalSortUtil(i, visited, Stack); 
  
	// Print contents of stack 
	while (Stack.empty() == false) { 
		cout << Stack.top() << " "; 
		Stack.pop();
	} 
}

int
main (int argc, char** argv)
{
        const int VERT_NUM = 6;
        Graph g(VERT_NUM);
        g.addEdge(5, 2); 
		g.addEdge(5, 0); 
		g.addEdge(4, 0); 
		g.addEdge(4, 1); 
		g.addEdge(2, 3); 
		g.addEdge(3, 1); 

		g.printAdjLists(VERT_NUM);
		
		cout << "Following is a Topological Sort of the given graph \n"; 
		g.topologicalSort();	
        return 0;
}

