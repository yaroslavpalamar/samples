#include <iostream>
#include <vector>
#include <list>
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

	1. Graph class contain **adjMatrix, V=size                  	
	2. Constructor init all matrix values to 0 for(){adjMatrix[i]=new int [V]}
	3. addEdge() adjMatrix[src][dest]=1;                                                                                                                         
	4. destructor call freeMatrix for every element for(){adjMatrix[i]=delete int [V]}
	5. vector<int> visited(V, false); 
	6. create queue<int> and push_back first element
	7. while() {queue<int>not empty start.vert = queue.front()
		startVert = queue.front();
		queue.pop_front();
			for (int i=0; i <V; ++i) { 
				if (visited[i]==false && adjMatrix[startVert][i]==1) {
					queue.push_back(i); visited[startVert]=true;}}

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
	
	void BFS(int startVert)
	{
		vector<int> visited(V, false);
		
		list<int> queue;
		queue.push_back(startVert);
		while(!queue.empty()) {
			startVert = queue.front();
			queue.pop_front();
			cout << startVert << " ";
			for (int i=0; i <V; ++i) {
				if (visited[i]==false && adjMatrix[startVert][i]==1) {
					queue.push_back(i);
					visited[startVert]=true;
				}
			}
			
		}
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
	
	cout << "\nBFS print:" << endl;
	cout <<"\ntest 1: start from 0:" <<endl;
	cout << "iterative output:";
	g.BFS(0);
	cout << endl;

        cout <<"\ntest 2: start from 2:" <<endl;
        cout << "iterative output:";
        g.BFS(2);
        cout << endl;

        cout <<"\ntest 3: start from 3:" << endl;
        cout << "iterative output:";
        g.BFS(3);
        cout << endl;

        cout <<"\ntest 4: start from 4:" << endl;
        cout << "iterative output:";
        g.BFS(4);
        cout << endl;

	
	return 0;
}


