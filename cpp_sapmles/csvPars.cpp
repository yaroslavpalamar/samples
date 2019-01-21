#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

/*
	1. firstly create the file use fstream fout.open
	2. Read file with ifstream and use function getline(file, line) to parse the file and then function
		while (getline(buf, token, ',')) to parse the line (buf type is istringstream)
	3. For deletion you can create two files and copy everything from one file to another without deleted rows.
		After that remove old file and rename new file to old one.
	4. Append dtata useing ofstream and operator << outfile << "Data"; 
*/

const string FILENAME = "test.csv";

void create()
{
	fstream fout;
	fout.open(FILENAME, ios::out | ios::app); 
  
	cout << "Enter the details of 5 items separated by space:"
		<< " id name item1 item2 item3 item4" << endl; 
	
	struct userData {
		int id;
		string name; 
		int item1; 
		int item2; 
		int item3; 
		int item4;
	} user;

	// Read the input 
	for (int i = 0; i < 5; i++) { 
		cin  >> user.id 
			>> user.name 
			>> user.item1 
			>> user.item2 
			>> user.item3 
			>> user.item4; 
  
		// Insert the data to file 
		fout << user.id << ","
			<< user.name << ","
			<< user.item1 << ","
			<< user.item2 << ","
			<< user.item3 << ","
			<< user.item4 
			<< "\n"; 
	}
}

void readRecord()
{
	ifstream fin(FILENAME);
	int enteredId = 0;
	
	cout << "Enter id to display details: ";
	cin >> enteredId;

	// Read data from file as string vector
	vector <string> row;
	string line;

	while(getline(fin, line)) {
		istringstream buf(line);
		string token;
		// read column and store it in a string variable
		while (getline(buf, token, ',')) {
			// add all column data of row to a vector
			row.push_back(token);
		}
		if (stoi(row[0]) == enteredId) {
			cout << "Id:" << row[0] << "\n";
			cout << "Name: " << row[1] << "\n"; 
			cout << "Item1: " << row[2] << "\n"; 
			cout << "Item2: " << row[3] << "\n"; 
			cout << "Item3: " << row[4] << "\n"; 
			cout << "Item4: " << row[5] << "\n"; 
			break; 
		}
		row.clear();
	}
	if (row.empty())
		cout << "Record not found" << endl;
}

bool isFileExist(const string& name) {
    ifstream f(name.c_str());
    return f.good();
}


int main (int argc, char** argv)
{
	if (!isFileExist(FILENAME))
		create();
	readRecord();
	return 0;
}

