#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* Graph example:
 * 
 * (0)->(1)-->(4)
 *  |  \   \   |	
 * \|/ _\| _\|\|/
 * (2)->(    3   )
 *
 *
 * Adg matrix:
 *
 *     0 1 2 3 4 
 *    __________ 
 * 0 | 0 1 1 1 0
 * 1 | 0 0 0 1 1
 * 2 | 0 0 0 1 0
 * 3 | 0 0 0 0 1
 * 4 | 0 0 0 0 0
 */

class Graph
{
	int V;
	int **adjMatrix;
	void freeMatrix(int** arr, const int size)
	{
		for (int i = 0; i < size; ++i) {
                        delete [] arr[i];
                }
                delete [] arr;
	}
public:
	explicit Graph(int vertSize)
	{
		this->V=vertSize;
		adjMatrix = new int*[V];
		for(int i=0; i < V; ++i) {
			adjMatrix[i] = new int [V];
			for (int j=0; j < V; ++j)
				adjMatrix[i][j]=0;
		}
	}
	
	void DFS(int startVert)
	{
		vector<int> visited(V, false);
		
		stack<int> stack;
		stack.push(startVert);
		while(!stack.empty()) {
			int startVert = stack.top();
			stack.pop();
			
			if (!visited[startVert]) {
				cout << startVert << " ";
				visited[startVert]=true;
			}
			for (int i=0; i <V; ++i) {
				if (visited[i]==false && adjMatrix[startVert][i]==1) {
					stack.push(i);
				}
			}
			
		}
	}
	
	void recursUtilDFS (int startVert, vector<int>&visited) {
		if (!visited[startVert]) {
			cout << startVert << " ";
			visited[startVert]=true;
		}
		for (int i=0; i< V; ++i ) {
                        if (visited[i]==false && adjMatrix[startVert][i]==1) {
                                recursUtilDFS(i, visited);
                        }
                }

	}	
	void recursDFS(int startVert)
	{	
		vector<int> visited(V, false);
		recursUtilDFS(startVert, visited);
	}
	
	Graph (const Graph& other) 
	{
		this->V= other.V;
		this->adjMatrix = new int*[V];
		for (int i=0; i < V; ++i) {
			this->adjMatrix[i] = new int[V];
			for (int j=0; j < V; ++j) {
				adjMatrix[i][j]=other.adjMatrix[i][j];
			}
		}
	}
	
	Graph& operator = (const Graph& other) 
	{
		if(&other==this)
			return *this;
		freeMatrix(adjMatrix, this->V);
		this->V=other.V;
		this->adjMatrix = new int*[V];
                for (int i=0; i < V; ++i) {
                        this->adjMatrix[i] = new int[V];
                        for (int j=0; j < V; ++j) {
                                adjMatrix[i][j]=other.adjMatrix[i][j];
                        }
                }
		return *this;
	}

	void addEdge(const int src, const int dest)
	{
		adjMatrix[src][dest]=1;
	}

	void printAdjMatrix() const
	{
		for (int i = 0; i< V; i++) {
			for(int j = 0; j < V; j++) {
				cout << adjMatrix[i][j]<<" ";
			}
			cout << endl;
		}
	}
	~Graph()
	{
		freeMatrix(adjMatrix, V);
	}
};


int 
main(int argc, char** argv)
{
	// Graph c=5; // explicit don't let me create object like this
	Graph c(8);
	
	Graph a = c;
	Graph g(10);
	g=a;
	
	g.addEdge(0,7);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(1,6);
	g.addEdge(2,3);
	g.addEdge(3,2);
	g.addEdge(4,3);
	g.addEdge(4,5);
	g.printAdjMatrix();
	
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
	cout <<"recurs output:";
	g.recursDFS(4);
	cout << endl;

	
	return 0;
}


