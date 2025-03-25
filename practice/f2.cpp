#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class DocumentIndex {
private :
	unordered_map<string, vector<string>> Index;
public :
	void addDocument( const string & filename, const vector<string> &words) {
		for (const string &word: words)
			Index[word].push_back(filename);
        }

	vector<string> search(const string &word){
		return Index.count(word) ? Index[word] : vector<string> {};
	}

	void displayIndex(){
		for (auto &[word, files] : Index) {
			cout << word << " : " ;
			for (const string &file:files)
				cout << file << " " ;
			cout << endl;
		}
	}
};

int main() {
	DocumentIndex docIndex;

	docIndex.addDocument("file1.txt", {"hello","world","hashing"});
	docIndex.addDocument("file2.txt", {"hashing", "example", "world"});

	docIndex.displayIndex();
	vector<string> result = docIndex.search("hashing");

	cout << "Document containing 'hashing' : ";

	for (const string &file : result)
		cout << file << " ";
	cout << endl;

	return 0;
}
