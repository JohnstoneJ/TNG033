
#include <iostream>
#include <string>
#include <fstream> // input/output file stream class 
#include <utility> //  pair 
#include <vector>  
#include <map>
#include <algorithm>
#include <iterator> 
#include <iomanip> 


bool sortByVal(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b); 
bool skipPunctuation(char c);
using myPair = std::pair<std::string, int>;

struct print {

	void operator() (myPair p) {

		std::cout << std::left << std::setw(15) << p.first << p.second << std::endl;
	}
};

int main() {

	//container- data structures for representing data collections
	std::map<std::string, int> map_table;
	std::pair<std::string, int> pairs; 

	std::string file_in = "/Users/juljo166/Desktop/Labb3.0/Labb3.0/uppgift1.txt"; 
	std::string file_out = "/Users/juljo166/Desktop/Labb3.0/Labb3.0/uppg_out.txt";

	std::ifstream in(file_in); 
	std::ofstream out(file_out); 

	//Reads in file
	if (!in) {

	std:: cout << "Could not find file...";
		return 0; 
	}

	int counter_tot = 0;
	
	std::string word = ""; 

	// Läser och lägger in ord i table. returerar int
	while (in >> word >> std::skipws) {

		transform(word.begin(), word.end(), word.begin(), [](char c) {
			return static_cast<char>(::tolower(c));
		}); // till lowercase
		
		std::string theWord; // skapar plats till "nya" ordet (lowercase)
		theWord.reserve(word.size()); 

		// Skiljetecken i slutet av ord tas bort 
		std::copy_if(word.begin(), word.end(), back_inserter(theWord), skipPunctuation);

		map_table[theWord]++; 

		counter_tot++; 
	}

	//Total words
	std::cout << "Number of words in the file = " << counter_tot << std::endl; 


	// Unique words
	int counter_uni = 0;
	counter_uni = distance(map_table.begin(), map_table.end()); //map_table.size();
	std::cout << "Number unique words in the file = " << counter_uni << std::endl;


	// Table sorted alphabetically
	std::cout << "Frequency table sorted alphabetically ... " << std::endl;

	std::for_each(map_table.begin(), map_table.end(), print{}); 
	std::cout<<"\n \n \n";

	// Table sorted by frequence 

	// create an empty vector of pairs. vector måste ha bestämd storlek -> vec(map_table.size());
	//std::vector<std::pair<std::string, int>> vec;

	// copy key-value pairs from the map to the vector
	//std::copy(map_table.begin(), map_table.end(), std::back_inserter(vec)); 

	std::vector<std::pair<std::string, int>> vec{ map_table.begin(), map_table.end() };
	//vec.assign(map_table.begin(), map_table.end());

	std::sort(vec.begin(), vec.end(), sortByVal);

	std::cout <<"Frequency table sorted by frequence ..." << std::endl;

	std::for_each(vec.begin(), vec.end(), print{});

	return 0;
}

// tar bort skiljetecken efter vissa ord
bool skipPunctuation (char c){

	std::string punctuation = ".,!?:\"();"; 

	std::string::iterator it;

	it = find(punctuation.begin(), punctuation.end(), c); 

	// om det INTE är ett skiljetecken
	if (it != punctuation.end()) {

		return false;
	}
	return true; 
}

// utility comparator function to pass to the sort() module
bool sortByVal(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
{
	return (a.second > b.second);
}