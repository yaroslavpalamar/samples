#include <iostream>
#include <vector>

/*
 *
Start from pos P in the list,
Read value in the list and jump depends on value that you read ..
Go until the right border of the list.
In result return number of jumps
if list val=0 return -1
List size in range between [1, 1000]
Sample 1,4,6,7,3,6,3,6,7,2,3,4,5. return 1+6+4+end so the result is 4.
What size of value in the list? Is it number or string, if number what max/min size?
 *
 */

int jump_over_numbers(const std::vector<int>& list) {
    int result=0;
    try {
    	int listVal = 0;
    	for(std::vector<int>::const_iterator it = list.begin(); it != list.end(); it=it+*it) {
    		if (*it == 0)
    			return -1;
    		result++;
			listVal += *it;
			list.at(listVal);
		}
    } catch (const std::out_of_range& e) {
    	return result;
    }
    return result;
}

int jump_over_numbers2(const std::vector<int>& list) {
    int result=0;
    int listVal = 0;
    for(std::vector<int>::const_iterator it = list.begin(); it != list.end();) {
		listVal = *it;
		if (*it == 0)
    		return -1;
		result++;
		int skip = *it;
		//std::cout << skip << std::endl;
		for(int i = 0; i<skip;i++) {
			if (it++ == list.end()) {
				return result;
			}
		}
	}
    return result;
}

int main() {
	//std::vector<int> test = {1,4,6,7,3,6,3,6,7,2,3,4,5};
	std::vector<int> test = {1,4,6,7,3,6,3,6,7,2,3,4,5};
	//std::vector<int> test = {3};
	std::cout << "Solution 1 with result: ";
	std::cout << jump_over_numbers(test) << std::endl;

	std::cout << "Solution 2 with result: ";
	std::cout << jump_over_numbers2(test) << std::endl;
	return 0;
}
