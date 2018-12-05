#include <iostream>

using namespace std;

int findMinLength(string* arr, int n)
{
	int min = arr[0].length(); 

	for (int i=1; i<n; i++) 
		if (arr[i].length() < min) 
			min = arr[i].length();
	return(min);
}

string commonPrefix(string* arr, int n) 
{ 
	int minLen = findMinLength(arr, n); 
	string result;
	char current;  // The current character 
	for (int i=0; i<minLen; ++i) {
		current = arr[0][i]; 
  
		for (int j=1 ; j<n; j++) 
			if (arr[j][i] != current) 
				return result;

		result.push_back(current);
	}
	return result;
}

int main(int argc, char** argv)
{
	string arr[] = {"beef up", "beef stew", "beef steak"}; 
	int n = sizeof (arr) / sizeof (arr[0]); 

	string ans = commonPrefix (arr, n); 
	if (ans.length()) 
		cout << "The longest common prefix is: \n"<< ans; 
	else
		cout << "There is no common prefix"; 
	return 0;
}

