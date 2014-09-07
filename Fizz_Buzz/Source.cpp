#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::stoi;

// Checks whether numbers are divisible by a, b, or both and prints F, B, or FB accordingling. If neither, then function prints number that wasn't divisible
void fizz_buzz(const unsigned int &a, const unsigned int &b, const unsigned int &n)
{
	for (size_t i = 1; i <= n; i++)
	{
		if (i % a == 0 && i % b == 0)
		{
			cout << "FB ";
		}
		else if (i % a == 0)
		{
			cout << "F ";
		}
		else if (i % b == 0)
		{
			cout << "B ";
		}
		else
		{
			cout << i << " ";
		}
	}
}

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	// Read each line of input file
	string line;
	while (getline(ifs, line))
	{
		// Retrieve divisors and number of elements from line
		istringstream iss(line);
		string temp;
		getline(iss, temp, ' ');
		unsigned int a = stoi(temp);
		getline(iss, temp, ' ');
		unsigned int b = stoi(temp);
		getline(iss, temp, ' ');
		unsigned int n = stoi(temp);

		// Call fizz buzz
		fizz_buzz(a, b, n);
		cout << endl;
	}

	return 0;
}