#include <iostream>
#include <list>
#include <vector>

using namespace std;

/* Dijkstra algorithm implementation 
 *
 * Part of code to display graph represented by adjacency list 
 * and Dijkstra algorithm based on priority queue to traverse the graph and search for shortest path. 
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
	void dijkstraShortPath (int startVert) {
		// vector for marking visited vertices
		// on the begining they are all marked as not visited
		vector<int>visited(vertexNum,false);

		list<int> queue;
		visited[startVert]=true;
		queue.push_back(startVert);
		
		while(!queue.empty()) {
			// get vertex from queue and print it
			startVert = queue.front();
			cout << startVert << " ";
			queue.pop_front();

			for (list<int>::iterator i = adjLst[startVert].begin(); i != adjLst[startVert].end(); ++i) {
				if (!visited[*i]){
					queue.push_back(*i);
					visited[*i] = true;
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
	const int VERT_NUM = 9;
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
/*	
	cout << "\nDijkstra Shortest path print:" << endl;
	cout <<"\ntest 1: start from 0:" <<endl;
	g.dijkstraShortPath(0);
	cout <<"\ntest 2: start from 2:" <<endl;
	g.dijkstraShortPath(2);
	cout <<"\ntest 3: start from 3:" <<endl;
	g.dijkstraShortPath(3);
	cout <<"\ntest 4: start from 4:" <<endl;
	g.dijkstraShortPath(4);
*/
	return 0;
}

