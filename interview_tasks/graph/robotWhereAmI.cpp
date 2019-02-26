/*
	1. The robot is always dropped on an empty cell. 
		It has in its memory a map of the whole field but it does not know where it is on that map.
	2. However, it can scan the surroundings and try to map the view to a spot on the map.
	3. The robot has the goal to reach a given cell, which is always empty. 
	It needs to compute the length of the shortest path in terms of cells 
		(including the start and final ones) from its start cell to the final cell.
	4. It is possible that there are more than one cells on the map, which have the same surrounding as what the robot sees. 
		In such a case it should return the most pessimistic answer it can find.
	5. It is also possible that no cell on the map corresponds to what the robot sees. 
		In such cases it should return the number -1.
	6. If the robot matches one or more possible starting locations on the 
		map but from at least one of them there is no path to the final cell it must return -2.
	7. The surroundings that the robot sees will be presented as a smaller rectangle with empty and occupied cells.
	8. The field can be at most 1000 by 1000 cells big. 
		The surroundings rectangle's size will be at most 16 by 16 cells and it will never be bigger than the map.
	9. The input will be read from the standard input and will contain 4 numbers on the first line: N, M, P, Q, where:
N - number of rows in the map
M - number of columns in the map
P - number of rows in the surroundings
Q - number of columns in the surroundings
	10. The second line will contain two integers: X and Y, the row and column of the destination cell.
	11. Rows and columns are numbered starting from 1 at the top and at the left correspondingly.
SAMPLE INPUT

6 10 2 3
4 9
0100000000
1000000000
0000000000
0010000000
0000000000
0000000000
010
102
SAMPLE OUTPUT

8
*/