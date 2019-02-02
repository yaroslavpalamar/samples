#include <iostream>
#include <vector>

using namespace std;

/*
 * 1. Given grid of cells with size = N, rows size = M
 * 2. Robot position row N-1, column 0)
 * 3. It can move from cell to cell but only to the right and to the top.
 * 4. Some cells with obstacles.
 * 5. robot cannot go outside the grid boundaries.
 * 6. The robot has a goal to reach top-right cell (row 0, column M-1).
 * 7. Both the start and end cells are always empty.
 * 8. You need to compute the number of different paths that the robot can take from start to end.
 * 9. N and M will be numbers in the range [1, 512].
 * 10. Write Method, which accepts the grid as an argument.
 * 11. Return the total number of different paths (return int)
 *     that the robot can take from the start to the end cell, MODULO 1,000,003
 * 12. The input grid will contain N strings with M characters
 *     each - either '0' or '1', with '0' meaning an empty cell
 *     and '1' meaning an occupied cell.
 *     Each of these strings corresponds to a row in the grid.
 *
 *        1 0 0->finish
 *        0 0 0         N=3, M=3 looks like result is 4.
 * start->0 0 1
 *
 * The main in this algorithm is to create vector<vector<int>> res
 * res is vector of strings the same size as input vector of str and save number of paths to every cell in
 * this res vector.
 *
 */

/* input:
 *         1 0 0->finish
 *         0 0 0
  *  start->0 0 1*/

/* res:
 *         0 0 0  * 0 0  * 2 0  * 2 4
 *         2 3 0  1 0 0  1 2 2  1 2 2
 *  start->1 1 0  1 1 *  1 1 *  1 1 * */

int count_the_paths(vector<string> grid) {
	const int MOD = 1000003;
	int colSize = grid.at(0).size();
	int rowSize = grid.size();

	if (colSize == 0 || rowSize == 0)
		return 0;

	int rowStart = rowSize-1;
	int colStart = 0;
	int rowEnd = 0;
	int colEnd = colSize-1;

	vector<vector<int>> res(rowSize, vector<int>(colSize, 0));
	res[rowStart][0] = 1;

	for (size_t i = rowStart; i < rowSize; --i) {
		for (size_t j = colStart; j < colSize; ++j) {
			if (grid[i][j] != '1') {
				if (i + 1 < rowSize) {
					res[i][j] += res[i + 1][j];
				}
				if (j > 0) {
					res[i][j] += res[i][j - 1];
				}
				//cout << res[i][j] << endl;
				res[i][j] = res[i][j] % MOD;
			}
		}
	}

	return res[0][colEnd];
}

int main() {
	vector<string> test;
	test.push_back("100");
	test.push_back("000");
	test.push_back("001");

	cout << count_the_paths(test) << endl;

	return 0;
}
