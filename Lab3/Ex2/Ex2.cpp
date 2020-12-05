#include <algorithm>  //std::copy
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <utility>  //std::pair
#include <cmath> //std::hypot
#include <set>

//pairing a string with a set OF strings
using my_pair = std::pair<std::string, std::set<std::string>>;

//print all the anagrams
void print_anagram(std::string s) {
	std::cout << s << " ";
}

//as long as there is more than one word in the set, keep printing the anagrams and the amount of words
struct print {
	void operator() (my_pair p) {
		if (p.second.size() > 1){
			std::for_each(p.second.begin(), p.second.end(), print_anagram);
			std::cout << " --> " << p.second.size() << " words. \n";
		}
	}
};

int main() {

	//loading file
	std::ifstream in_file("uppgift2_kort.txt");

	if (!in_file) {
		std::cout << "Could not open file!\n";
		return 0;
	}

	//empty vector
	std::vector<std::string> mywords;

	 // create stream iterators operating on the file
	//iterator points to an element within a range
	auto interatorIn = std::istream_iterator<std::string>{ in_file };
	auto interatorInEnd = std::istream_iterator<std::string>{};  

	//copying all the words from the file into the vector
	std::copy(interatorIn, interatorInEnd, back_inserter(mywords));
	
	std::cout << "Number of words =  " << mywords.size() << "\n\n\n";

	//creating the word table to print
	std::map<std::string, std::set<std::string>> wordtable;

	//lambda expression, checks which subject a word belongs to and inserts it in the subject 
	auto anagrams = [&wordtable](const std::string &word) {
		std::string subject = word;
		std::sort(subject.begin(), subject.end());
		wordtable[subject].insert(word);
	};
	
	//loop that stores the anagrams correctly in wordtable
	std::for_each(mywords.begin(), mywords.end(), anagrams);

	std::cout << " -- ANAGRAMS  -- \n";
	std::for_each(wordtable.begin(), wordtable.end(), print{});

		return 0;
}