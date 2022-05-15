#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::cerr;
using std::stringstream ;
using std::string;
using std::ostream;


unsigned long long int Fibonacci(unsigned int n);
void PrintReverseString(const string& str, ostream& output = cout);
// You may change the parameters of these functions
size_t MinimumPosition(const int array[], size_t size, size_t pos);
void SelectionSort(int array[], size_t size, size_t minPos);


int main() {
	const size_t ELEMENTS = 7;
	const size_t TESTS = 3;
	int data[][ELEMENTS] = {
			{7, 5, 4, 1, 3, 0, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{8, 5, 4, 1, 3, 4, 0}};

	int minimumSolutions[] = {5, 0, 6};
	int sortedArrays[][7] = {
			{0, 1, 3, 4, 5, 7, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{0, 1, 3, 4, 4, 5, 8}};

	unsigned long long int fibonacciSequence[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

	string strings[] = {"hello", "aardvark", "reviver"};
	string reverses[] = {"olleh", "kravdraa", "reviver"};
	size_t passed = 0;
	int minimumResponses[TESTS];
	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = -1;
	}

	cout << "Testing Fibonacci" << endl;
	for (int i = 0; i < 10; ++i) {
		unsigned long long int fibonacci = Fibonacci(i);
		if (fibonacci == fibonacciSequence[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}


	cout << "Testing Minimum Position Finding" << endl;
	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = MinimumPosition(data[i], ELEMENTS, 0);
		if (minimumResponses[i] == minimumSolutions[i]){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}
	cout << "Testing Sorting" << endl;
	bool equal;
	for (int i = 0; i < TESTS; ++i) {
		SelectionSort(data[i], ELEMENTS, 0);
		equal = true;
		for (int j = 0; j < ELEMENTS; ++j) {
			if (data[i][j] != sortedArrays[i][j]){
				equal = false;
				cerr << "Test " << i << " position " << j << " values: ";
				cerr << data[i][j] << " " << sortedArrays[i][j] << endl;
				break;
			}
		}
		if (equal){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}
	cout << "Testing Reverse Strings" << endl;
	stringstream out;
	for (int i = 0; i < TESTS; ++i) {
		out.clear();
		out.str("") ;
		PrintReverseString(strings[i], out);
		if (out.str() == reverses[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}

	return 0;
}

unsigned long long int Fibonacci(unsigned int n){
    // base case
    if(n == 0 || n == 1) {
        return n;
    }

    // recursive case
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void PrintReverseString(const string& str, ostream& output){
    // base case
    // if the string is empty, stop the recurison
    if(str.empty()) {
        return;
    }else{
        // recursive case
        // move the string up by 1 and output the first char of the current string
        output << str[str.size() - 1];
        PrintReverseString(str.substr(0, str.size() - 1));
    }

}

// You may change the parameters of these functions
size_t MinimumPosition(const int array[], size_t size, size_t pos){
	// base case
    if(size == 0) {
        return pos;
    }else{
        // recursive case
        if(array[size] < array[size - 1]) {
            pos = size;
        }

        return MinimumPosition(array, size - 1, pos);
    }

}

void SelectionSort(int array[], size_t size, size_t minPos){
    // base case
    if(size == minPos) {
        return;
    }else{
        // recursive case
        size_t min = array[minPos];
        size_t max = array[size - 1];
        if(max < min) {
            array[minPos] = max;
            array[size - 1] = min;
        }

        SelectionSort(array, size - 1, minPos + 1);
    }

}
