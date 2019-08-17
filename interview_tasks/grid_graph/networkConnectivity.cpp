

/*
	1. The computers in one company's head quarters are connected by a local area network. 
	2. However, due to various restrictions not all computers may be reachable from all 
		other computers in the building.
	3. The system administrators of the building have a list of all connections between nodes 
		on the network (computers and network devices). 
		The list consists of pairs of numbers where each number is the assigned ID of 
		a node on the network.
	4. Your task is to write a program, which can be used to determine how many network 
		nodes are reachable from a given node with ID S.
	5. The network has N nodes where 1 <= N <= 512.
	6. The input is read from the standard input. On the first line there will be three integers 
N - the number of nodes, 
M - the number of connected pairs of nodes and 
S - the ID of the node which we are asking the question for. 
Then M lines will follow each containing two integers - IDs of network nodes. 
The IDs will be in the range [1, N].

The output is written to the standard output. 
It must contain only one integer - the number of network nodes reachable from the node with ID S.
SAMPLE INPUT

7 8 2
1 2
1 4
4 2
4 3
3 1
5 6
5 7
7 6
SAMPLE OUTPUT

3
The nodes reachable from the node with ID 2 are 1, 3, 4. 
The other nodes are not connected in any way to the node with ID 2.

*/

// Read input from stdin, write output to stdout
#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<vector<int> > &g, vector<int> &used, int &cnt) {
    if (used[v]) {
        return;
    }
    used[v] = 1;
    cnt++;
    for (auto u: g[v]) {
        dfs(u, g, used, cnt);
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int> > g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int cnt = 0;
    vector<int> used(n + 1);
    dfs(s, g, used, cnt);
    cout << cnt - 1;
}



