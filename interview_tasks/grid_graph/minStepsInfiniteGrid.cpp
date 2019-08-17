#include <iostream>
#include <vector>

using namespace std;

/*
 * 1. You are in an infinite 2D grid where you can move in any of the 8 directions
 * 2. You are given a sequence of points and the order in which you need to cover the points. 
	Give the minimum number of steps in which you can achieve it. You start from the first point.
   3. Input: Given two integer arrays A and B, 
	where A[i] is x coordinate and B[i] is y coordinate of ith point respectively.
   4. Output: Return an Integer, i.e minimum number of steps.
	Input : [(0, 0), (1, 1), (1, 2)]
	Output : 2
	Explanation: It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).
 */

/* input:
 *  start->1 0 0
 *         0 1 0
 *  	   0 0 1->finish 
 figuring out the way to calculate the distance between 2 points (A, B) and (C, D).
 X = abs(A-C) and Y = abs(B-D)
 While X and Y are positive, you will move along the diagonal and X and Y would both reduce by 1. 
 When one of them becomes 0, you would move so that in each step the remaining number reduces by 1.
 In other words, the total number of steps would correspond to max(X, Y).
 */
 
 
class Solution {
    public:
        int coverPoints(vector<int> x, vector<int> y) {
            if (x.size() <= 1) return 0;
            //assert(x.size() == y.size());
            int ans = 0;
            for (int i = 1; i < x.size(); i++) {
                ans += max(abs(x[i] - x[i-1]), abs(y[i] - y[i-1]));
            }
            return ans;
        }
};

int main() {
	vector<int> x = {0,1,1};
	vector<int> y = {0,1,2};
	
	Solution s;
	cout << s.coverPoints(x,y) << endl;

	return 0;
}
