#include <iostream>
#include <string>
#include <fstream> 
#include <utility>
#include <vector> 
#include <map>
#include <algorithm>
#include <iterator> 
#include <iomanip>

/*
struct print {

	void operator() (myPair p) {

		std::cout << std::left << std::setw(15) << p.first << p.second << std::endl;
	}
};

*/

/*
std::vector<std::string>anagrams;
std::vector<std::string>anagrams;


std::pair<std::string,anagrams> pairs;
*/


int main() {

std::string file_in = "/Users/juljo166/Desktop/Labb3.0/Labb3.0/uppgift2_kort.txt";
std::string file_out = "/Users/juljo166/Desktop/Labb3.0/Labb3.0/uppg2_kort_out.txt";

std::ifstream in(file_in); 
std::ofstream out(file_out);


//Reads in file
if (!in) {

	std::cout << "Could not find file...";
	return 0;
}
int counter = 0;
std::vector<std::string> words;

//modifiera words, ett exempel. anagram
auto addWord = [&](std::string s) { 
	
	words.push_back(s); 

	counter++; 

};




std::istream_iterator<std::string> begin(in);
std::istream_iterator<std::string> end;
std::for_each(begin, end, addWord);

std::cout << "Number of words = " << counter << std::endl; 

std::cout << "\n \n";

std::cout << "--ANAGRAMS--" << std::endl; 

	return 0;

}


/*
// function to check whether two strings are anagram of each other 
bool areAnagram(std::string w1, std::string w2) {

	// Get lengths of both strings 
	int n1 = w1.length();
	int n2 = w2.length();

	// If length of both strings is not same, then they cannot be anagram 
	if (n1 != n2)
		return false;

	// Sort both the strings 
	sort(w1.begin(), w1.end());
	sort(w2.begin(), w2.end());



	// Compare sorted strings
	for (int i = 0; i < n1; i++)
		if (str1[i] != str2[i])
			return false;

	return true;
}


*/ 






//geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/