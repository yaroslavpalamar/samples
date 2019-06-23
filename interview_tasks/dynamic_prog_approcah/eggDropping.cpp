#include <iostream>
#include <limits.h>
using namespace std;

/*
 * Nubmer of Eggs is 2. 
 * 36 floors.
 * Need to find number for tries to check from which flog egg will be broken;
 */

int max(int a, int b)
{
	return (a>b) ? a : b;
}

int eggDropRecurs(int eggs, int floors) 
{
	if (floors == 1 || floors == 0)
		return floors;
	
	if (eggs == 1)
		return floors;

	int min = INT_MAX, x, res;

	for (x = 1; x<=floors; x++)
	{
		res = max(eggDropRecurs(eggs-1, x-1), eggDropRecurs(eggs, floors-x));
		if (res < min)
			min = res;
	}

	return min + 1;
}

class eggDrop {
	int eggs;
	int floors;
	int **eggFloor;
	eggDrop(const eggDrop& other) = delete;
	eggDrop& operator = (const eggDrop& other) = delete;
public:
	
	explicit eggDrop(int eggs, int floors) {
		this->eggs = eggs;
		this->floors = floors;
		eggFloor= new int*[eggs+1]();
		for (int i = 0; i < eggs+1; ++i) {
			eggFloor[i] = new int [floors]();
		}
		
	}
	~eggDrop() {
		for (int i = 0; i < eggs+1; ++i) {
			delete [] eggFloor[i];
		}
		delete [] eggFloor;
	}
	// dynamic programming slolution:
	int minNumEggDropTries()
	{
		int res;
		int x;
		for (int i = 0; i <= eggs; ++i) {
			eggFloor[i][1] = 1;
			eggFloor[i][0] = 0;
		}

		for (int j; j<=floors;++j)
			eggFloor[1][j]=j;
		
		for (int i = 2; i <=eggs; i++) {
			for (int j=2; j<=floors;j++) {
				eggFloor[i][j] = INT_MAX;
				for (x = 1; x <= j; x++) {
					res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
					if (res < eggFloor[i][j])
						eggFloor[i][j] = res;
				}
			}	
		}
		return eggFloor[eggs][floors];
	}
};

int
main(int argc, char** argv)
{
	int floors = 10;
	int eggs = 2;
	cout << "Minimum number of tries in worst case " << eggs << " eggs" << " and " << floors
		<< " floors is " << eggDropRecurs(eggs, floors) << " for recurs function call" << endl; 

	floors=100;
	eggs =2;
	eggDrop eD(eggs, floors);
	cout << "Minimum number of tries in worst case " << eggs << " eggs" << " and " << floors
                << " floors is " << eD.minNumEggDropTries() << " for dynamic programming solution" << endl;
	return 0;
}


