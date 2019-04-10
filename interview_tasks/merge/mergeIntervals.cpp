#include <iostream>
#include <vector>

using namespace std;

/*
	1. Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
	2. You may assume that the intervals were initially sorted according to their start times.
	3. Example 1:
		Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].
		Example 2:
		Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
		This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]
 */
 
 
 
 
class Solution {
public:
	/**
	 * Definition for an interval.*/
	struct Interval {
	    int start;
	    int end;
	    Interval() : start(0), end(0) {}
	    Interval(int s, int e) : start(s), end(e) {}
	};
	/**/
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		// Do not write main() function.
		// Do not read input, instead use the arguments to the function.
		// Do not print the output, instead return values as specified
		// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	}
};

int main() {
	vector<int> x = {0,1,1};
	vector<int> y = {0,1,2};
	
	Solution s;

	return 0;
}
