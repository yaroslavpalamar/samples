#include <iostream>
#include <fstream>
using namespace std;

void create()
{
	fstream fout;
	fout.open("test.csv", ios::out | ios::app); 
  
	cout << "Enter the details of 5 items separated by space:"
		<< " id name item1 item2 item3 item4" 
		<< endl; 
	
	int i, id, item1, item2, item3, item4; 
	string name;

	// Read the input 
	for (i = 0; i < 5; i++) { 
		cin >> id 
			>> name 
			>> item1 
			>> item2 
			>> item3 
			>> item4; 
  
		// Insert the data to file 
		fout << id << ", "
			<< name << ", "
			<< item1 << ", "
			<< item2 << ", "
			<< item3 << ", "
			<< item4 
			<< "\n"; 
	}
}

int main (int argc, char** argv)
{
	create();
	return 0;
}
