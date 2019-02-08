#include <iostream>
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
				cout << adjMatrix[i][j];
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
	Graph c(5);
	
	Graph a = c;
	Graph g(10);
	g=a;
	
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.printAdjMatrix();	
	return 0;
}


