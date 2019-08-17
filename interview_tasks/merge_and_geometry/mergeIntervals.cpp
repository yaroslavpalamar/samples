#include <iostream>
#include <vector>
#include <algorithm>

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
 
 /*
	How to solve it:
	1 Given all the intervals, you need to figure out the sequence of intervals which intersect with the given newInterval.
	Lets see how we check if interval 1 (a,b) intersects with interval 2 (c,d):
	2 Overlap case :
    a---------------------b                      OR       a------b
                c-------------------d                c------------------d
				
	3 Non overlap case :
    a--------------------b   c------------------d
	
	4 Note that if max(a,c) > min(b,d), then the intervals do not overlap. Otherwise, they overlap.
	5 Once we figure out the intervals ( interval[i] to interval[j] ) which overlap with newInterval, 
		note that we can replace all the overlapping intervals with one interval which would be
		(min(interval[i].start, newInterval.start), max(interval[j].end, newInterval.end)).
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
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
	bool cmp(Interval a,Interval b)
	{
		return a.start<=b.start;
	}
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		int i,j,n=intervals.size();
		int b=newInterval.start;
		int e=newInterval.end;
		intervals.push_back(newInterval);
		sort(intervals.begin(),intervals.end(),cmp);
		//now merge
		i=1,j=0;
		while(i<intervals.size())
		{
			if(intervals[j].end>=intervals[i].start)
			{
				//merge
				intervals[j].end=max(intervals[i].end,intervals[j].end);
			}
			else
			{
				j++;
				intervals[j]=intervals[i];
			}
			i++;
		}
		intervals.erase(intervals.begin()+j+1,intervals.end());
		return intervals;
	}
};

int main() {
	vector<int> x = {0,1,1};
	vector<int> y = {0,1,2};
	
	Solution s;

	return 0;
}
