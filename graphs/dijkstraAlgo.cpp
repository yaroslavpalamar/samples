#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

/* Dijkstra algorithm implementation 
 *
 * Part of code to display graph represented by adjacency list 
 * and Dijkstra algorithm based on priority queue to traverse the graph and search for shortest path. 
 * Complexity O(ElogV)) because O(E) vertices in priority_queue and O(log E) is same as O(log V)
 *	1. class Graph with int VertexNum and list<pair<int,int>>*adjList; 
	2. constructor init adjList allocate memory and init vertexNum;
	3. addEdge(int v1, int v2, int w) init pair adjLst[v1].push_back(make_pair(v2, w));
	4. dijkstraShortPath (int startVert) {
		priority_queue<pair, vector<pair<int,int>>, greater<pair<..>> pq;
		const int INF=0xfffffff; vector<int> dist(vertexNum, INF) init vector by infinity
		pq.push(make_pair(0,startVert))
		dist[startVert] = 0; // dist to first element init to 0
		while(!pq.empty()) {
			// Go to the next element in adj list.
			int next = pq.top().second; 
			pq.pop();
			for (list<pair<int, int>>::iterator i = adjLst[next].begin(); i != adjLst[next].end(); ++i) {
				int vert = (*i).first;
				int weight = (*i).second;
				// if path is shorter to vert throuhg "next"
				if (dist[vert] > dist[next] + weight) {
					// update distance to vertex
					dist[vert] = dist[next] + weight;
					pq.push(make_pair(dist[vert],vert));
			}}}}}
		// Print distance from->to...
		for (int i = 0; i < vertexNum; ++i) {
			cout << i << "=" << dist[i] << endl;
		}	
* */

class Graph {
	int vertexNum;
	// pointer to adjacency list
	list <pair<int, int>>*adjLst;
public:
	Graph(int vertNum) 
	{ 
		this->vertexNum = vertNum; 
		adjLst = new list<pair<int, int>>[vertNum]; 
	} 
	void addEdge(int v1, int v2, int w)
	{
		adjLst[v1].push_back(make_pair(v2, w));
		// for creation unordered graph
		adjLst[v2].push_back(make_pair(v1, w));
	}
	void dijkstraShortPath (int startVert) {
		// priority queue for storing preporcessed vertices.
		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
		// vector initialized by INFINITY for distances
		const int INF=0xfffffff;
		vector<int> dist(vertexNum, INF);
		
		// put first element to the priority queue
		pq.push(make_pair(0, startVert));
		// distance to first element initialized as 0.
		dist[startVert] = 0;
		
		// Go through priority queue untill queue become empty 
		// or all distances will be passed
		while(!pq.empty()) {
			// Go to the next element in adj list.
			int next = pq.top().second; 
			pq.pop();
			for (list<pair<int, int>>::iterator i = adjLst[next].begin(); i != adjLst[next].end();
				   ++i) {
				int vert = (*i).first;
				int weight = (*i).second;

				// if path is shourter to vert throuhg "next"
				if (dist[vert] > dist[next] + weight) {
					// update distance to vertex
					dist[vert] = dist[next] + weight;
					pq.push(make_pair(dist[vert],vert));
				}
			}
		}
		
		cout <<"Distances from " << startVert << " to: " << endl;
		for (int i = 0; i < vertexNum; ++i) {
			cout << i << "=" << dist[i] << endl;
		}
		
	}

	void printAdjLists(int vertexNum);
};

// print adjacency list representation of Graph
void
Graph::printAdjLists(int vertexNum) 
{
	cout << "\nAdjacency list:\n";
	for (int v = 0; v < vertexNum; ++v) 
	{ 
		cout << "Head:" << v << ": "; 
		int head = v;
		for (pair<int, int> node : adjLst[v]) {
			cout << v;
			cout << "->" << node.first << "=" << node.second <<"; "; 
		}
		cout<<endl; 
	}
}

int
main (int argc, char** argv)
{
	const int VERT_NUM = 7;
	Graph g(VERT_NUM);
	g.addEdge(0, 1, 7);
	g.addEdge(0, 3, 5);
	g.addEdge(1, 3, 9);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 4, 7);
	g.addEdge(3, 4, 15);
	g.addEdge(3, 5, 6);
	g.addEdge(5, 4, 8);
	g.addEdge(5, 6, 11);
	g.addEdge(4, 6, 9);

	g.printAdjLists(VERT_NUM);	
	
	cout << "\nDijkstra Shortest path print:";
	cout <<"\nTest 1:" <<endl;
	g.dijkstraShortPath(0);
	cout <<"\nTest 2:" <<endl;
	g.dijkstraShortPath(2);
	cout <<"\nTest 3:" <<endl;
	g.dijkstraShortPath(3);
	cout <<"\nTest 4:" <<endl;
	g.dijkstraShortPath(4);

	return 0;
}

