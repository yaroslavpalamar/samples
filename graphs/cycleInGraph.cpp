#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

/*
	1. With DFS we cah check whether graph cyclic 
	2. Inside function isCyclic() will add vector<bool> recToParent(vertexNum,false)
		inside while(!stack.empty) {if(!visited[startVert]){recToParent[startVert]=true; vis..[st..]=true}}
		inside for(it=begin;it!=end;it++){if(recToParent[it]==true) return true}
 */

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
	bool isCyclic () {
		// vector for marking visited vertices
		// on the begining they are all marked as not visited
		vector<bool> visited(vertexNum, false);
		vector<bool> recToParent(vertexNum, false);
		
		stack<int> stack;
		// start traversal by pushing node to the stack
		int startVert=0;
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
				recToParent[startVert] = true; 
			}
			// Go through vertex represented by adjacency list 
			// and put not visited vertex to stack. 
			for (list<int>::iterator i = adjLst[startVert].begin(); i!=adjLst[startVert].end();i++) {
				if(!visited[*i]) {
					stack.push(*i);
				} 
				if (recToParent[*i]) {
					return true;
				}
			}
		}
		return false;

	}
	bool isCyclicRecUtil (int startVert, vector<bool>& visited, vector<bool>& recToParent)
	{	
		// If vertex not visited we print the popped items.
                if (!visited[startVert]) {
                	cout << startVert << " ";
                	visited[startVert] = true;
			recToParent[startVert] = true;
                }
                // Go through vertex represented by adjacency list 
                // and put not visited vertex to stack. 
                for (list<int>::iterator i = adjLst[startVert].begin(); i!=adjLst[startVert].end();i++) {
                	if(!visited[*i]) {
				if (isCyclicRecUtil(*i, visited, recToParent))
					return true;
                	} else if (recToParent[*i])
				return true;
                }
		return false;
	}	
	bool isCyclicRecurs (){
		vector<bool> visited(vertexNum, false);
		vector<bool> recToParent(vertexNum, false);
		if (isCyclicRecUtil (0, visited, recToParent))
			return true;
		return false;
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
        const int VERT_NUM = 4;
        Graph g(VERT_NUM);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        g.printAdjLists(VERT_NUM);

        cout << "iterative output:";
	if (g.isCyclic())
		cout << "Graph contains cycle" << endl;
	else 
		cout << "Graph does't contain cycle" << endl;
	cout << endl;
	cout <<"recurs output: ";
	if (g.isCyclicRecurs())
		cout << "Graph contains cycle" << endl;
        else
                cout << "Graph does't contain cycle" << endl;
	cout << endl;

        return 0;
}

