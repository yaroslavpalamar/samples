#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 1. worker has a set of N tasks to complete The number of tasks N is in the range [1, 10,000]
 * 2. The total time T is in the range [0, 200,000,000]
 * 3. Every task have different time. The task difficulties are integers in range [1, 10,000]
 * 4. when switching from one task to another with difficulties D1 and D2,
 * 		the worker needs |D1 - D2| minutes to prepare for working on the next task.
 * 5. Need calculate max number of tasks for range T.
 * 6. Function return integer (max num of tasks that can be completed in time T)
 * Example input N=5, T=65, D1..D5 = 24 23 22 10 20, result 3
 * */

int maximum_completed_tasks(int n, int t, const vector<int>& task_difficulties) {
	int result=0;
	long long countTime=0;
	vector<int> s(task_difficulties);
	sort(s.begin(), s.end());
	// check first element
	countTime = s[0];
	if (countTime>t)
		return result;
	result++;

	for (int i = 1; i<n;i++) {
		countTime += 2 * s[i] - s[i-1];
		if (countTime > t)
			break;
		result++;
	}
	return result;
}

int main() {
	int N=5;
	int T=65;
	vector<int>D={24,23,22,10,20};
	cout << maximum_completed_tasks(N, T, D) << endl;
	return 0;
}
