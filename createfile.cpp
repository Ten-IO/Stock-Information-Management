#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void createCSV(const string& filename, const vector<string>& header, const vector <vector<string>>& data ){
	ofstream file(filename);
	
	if (!file.is_open()){
		cerr << "Can't open file" << endl;
		return;
	}
	
	// header
	
	for (size_t i = 0; i< header.size(); i++){
		file << header[i];
		if (i < header.size() - 1) {
		
			file << ",";
		}
	}
	file << "\n";
	
	// row for data
	
	for (size_t j = 0; j < data.size(); j++ ){
		const vector<string> row = data[j];
		for (size_t k = 0; k < row.size(); k++){
			file << row[k];
			if (k < row.size() -1){
				file << ",";
			}
		}
		file << "\n";
	}
	
	file.close();
	cout << "File '" << filename << "' created successfully.\n";
}

// test 

int main (){
	
	vector <string> h1 = {"A", "B", "C"};
	vector <vector<string>> d1 = {{"Aly", "fuka", "Miya"}, {"18", "28", "22"}};
	createCSV ("abc.txt", h1, d1);
	return 0;
}
