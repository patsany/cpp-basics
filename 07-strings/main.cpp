#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string DigitToWord(char s) {
	string translated_digit = "";
	switch (s) {
	case '0':
		translated_digit = "zero";
		break;
	case '1':
		translated_digit = "one";
		break;
	case '2':
		translated_digit = "two";
		break;
	case '3':
		translated_digit = "three";
		break;
	case '4':
		translated_digit = "four";
		break;
	case '5':
		translated_digit = "five";
		break;
	case '6':
		translated_digit = "six";
		break;
	case '7':
		translated_digit = "seven";
		break;
	case '8':
		translated_digit = "eight";
		break;
	case '9':
		translated_digit = "nine";
		break;
	}
	return translated_digit;
}

int main() {
	string file_name;
	cout << "Write file name -> ";
	cin >> file_name;
	ifstream fin(file_name);
	if (!fin.is_open()) {
		cout << "can't open file!\n";
		return 1;
	}

	string word;
	while (fin >> word) {
		unsigned int word_len = word.length();
		for (unsigned int i = 0; i < word_len; i++) {
			if (isdigit(word[i]))
				cout << DigitToWord(word[i]);
			else
				cout << word[i];
		}

		if (word[word_len - 1] == '.' ||
			word[word_len - 1] == '!' ||
			word[word_len - 1] == '?')
			cout << endl;
		else
			cout << " ";
	}
	fin.close();
	return 0;
}