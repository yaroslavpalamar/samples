/*
 * 1. Topological sorting is when every vertex have sequence from smaller to bigger. 
 * 2. We can run DFS on the graph and get !stack with verteces!.
 * 3. If we pop vertexes from stack and change every vertex from 
 * 	original value to sorted value
 * 	for example in stack was 1,4,3,2 and we change it to 1,2,3,4 
 * 	in resul new graph with updated values from 1,4,3,2 to 1,2,3,4 will be sorted.
 */
