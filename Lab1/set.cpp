#include "set.hpp"

// Default constructor inom klass Set 
// Skapar head
Set::Set() : head{ new Node(0, nullptr) } //MARTIN. OBS! BRA KOD!!
{
}
// skapar en nod utifrån givna värden
// Insert a new node after node pointed by p
// the new node should store value
void Set::insert(Node* p, int value) const
{

	p->next = new Node(value, p->next);
}

// lägger till en ny nod i ett set
void Set::insert(int value) const
{

	Node* ptr = head;

	//sorterar
	while ((ptr->next != nullptr) && (ptr->next->value < value)) {
		ptr = ptr->next;
	}

	if (ptr->next == nullptr || ptr->next->value != value) {

		insert(ptr, value);
	}
}

// Remove the node pointed by p
void Set::remove(Node* p)
{
	delete p;
}

// Constructor for creating a set from an int
Set::Set(int v) : Set()
{
	//head = new Node(0, nullptr); MARTIN
	insert(head, v); // head finns i default constructorn Set()
}

// Constructor creating a set
// a non-sorted array of n intgers
Set::Set(const int a[], int n)
	: Set()
{
	for (int i = 0; i < n; i++) {
		insert(a[i]);
	}
}

// copy constructor
//make a copy of the dynamically allocated memory.
Set::Set(const Set& source)
	: Set() 
{
	Node* p = source.head->next;
	Node* copy = head;

	while (p != nullptr) {
		insert(copy, p->value);
		copy = copy->next;
		p = p->next;
	}
}

// Destructor: deallocate all nodes
Set::~Set()
{

	Node* current = head;
	//Node* next; MARTIN 

	while (current != NULL) {
		Node* next = current->next; // MARTIN 
		remove(current);
		current = next;
	}
}

// Test if set is empty
bool Set::empty() const
{
	return (head->next == nullptr);
}

// Return number of elements in the set
int Set::cardinality() const
{
	int howMany = 0;
	Node* p = head->next;

	while (p != nullptr) {
		p = p->next;
		howMany++;
	}
	return howMany;
}

// Test if x is an element of the set
bool Set::member(int x) const
{
	Node* p = head->next;

	while ((p != nullptr) && (p->value != x)) {
		p = p->next;
	}

	if (p == nullptr) {
		return false; // "Not found!!"
	}
	else {

		return true;
	}
}

//overloaded assignment operators: to make a copy of the dynamically allocated memory

// Assignment operator
// shallow copy, kopierar bara värdena, member field values 
Set& Set::operator=(Set s)
{
	//Set temp(s); // MARTIN - Felet: Vi kopierade en kopia som redan fanns 
	std::swap(head, s.head);

	return *this;
}
//S<=R returns true if S is a subset of R. 
bool Set::operator<=(const Set& b) const
{
	Set set1 = b;
	Node* p = head->next;

	while (p != nullptr) {
		if (!set1.member(p->value)) {

			return false;
		}

		p = p->next;
	}

	return true; 
}

//R == S returns true if R is a subset of S and S is a subset of R 
bool Set::operator==(const Set& b) const
{
	// MARTIN. OBS! Tänk bool- if-sats ej nödvändigt! 
	Set temp = *this;

	return (temp <= b && b <= temp);
}

bool Set::operator!=(const Set& b) const
{
	return !(*this == b);
}

//S < R returns true if S is a proper subset of R
bool Set::operator<(const Set& b) const
{
	Set temp = *this;
	
	if (temp <= b) {
		return (temp != b);
	}
	return false;
}

// Set union
// Repeated values are not allowed
Set Set::operator+(const Set& b) const
{
	// "set1 + set2 = set3" och sortering sker

	Set set3 = Set();
	Set set1 = b;

	Node* p1 = set1.head->next;
	Node* p3 = head->next;

	while (p1 != nullptr) {

		set3.insert(p1->value);
		p1 = p1->next;
	}

	while (p3 != nullptr) {

		set3.insert(p3->value);
		p3 = p3->next;
	}

	return set3;
}

// Set intersection
Set Set::operator*(const Set& b) const
{
	// Det gemensamma i set1 resp set2 läggs i set3
	Set set3 = Set();
	Set set1 = *this;

	Node* p = b.head->next;

	while (p != nullptr) {
		if (set1.member(p->value)) {
			set3.insert(p->value);
		}

		p = p->next;
	}

	return set3; 
}

// Set difference
Set Set::operator-(const Set& b) const
{
	Set set3 = Set();

	Set set1 = b;

	Node* p = head->next;

	while (p != nullptr) {
		if (!set1.member(p->value)) {
			set3.insert(p->value);
		}
		p = p->next;
	}
	return set3;
}

// Set union with set {x}
Set Set::operator+(int x) const
{
	// Värde 999
	Set set2{ x };

	Set set3 = *this + set2;

	return set3;
}

// Set difference with set {x}
Set Set::operator-(int x) const
{
	// Värde 11
	Set set2{ x };

	Set set3 = *this - set2;

	return set3;
}

std::ostream& operator<<(std::ostream& os, const Set& theSet)
{
	if (theSet.empty()) {
		os << "Set is empty!";
	}
	else {
		Set::Node* temp = theSet.head->next;
		os << "{ ";

		while (temp) {
			os << temp->value << " ";
			temp = temp->next;
		}
		os << "}";
	}

	return os;
}