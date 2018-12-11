#include <iostream>
#include <string>
#include <iomanip>
#include <regex>

using namespace std;

struct Note {
	string full_name;
	string phone_number;
	int date_of_birth[3];
};

void AddNotes(Note *notes, const int kNumNotes);
void ConvertDate(string date, int *convert);
bool IsDate(string date);
bool IsPhoneNumber(string phone_number);
void PrintNotes(Note *notes, const int kNumNotes);
void SortNotes(Note *notes, const int kNumNotes);
void FindSurname(Note *notes, const int kNumNotes, string surname);

int main() {
	const int kNumNotes = 8;
	Note notes[kNumNotes];
	AddNotes(notes, kNumNotes);

	SortNotes(notes, kNumNotes);
	PrintNotes(notes, kNumNotes);

	string surname;
	cout << "Enter surname to find -> ";
	cin >> surname;
	cout << endl;
	FindSurname(notes, kNumNotes, surname);
	cout << endl;

	return 0;
}

void AddNotes(Note *notes, const int kNumNotes) {
	for (int i = 0; i < kNumNotes; i++) {
		cout << i + 1 << ". Enter full name (e.g., Ivan Ivanov): ";
		getline(cin, notes[i].full_name);

	wrong_number:
		cout << "Enter phone number (e.g., +79999999999): ";
		cin >> notes[i].phone_number;
		if (!IsPhoneNumber(notes[i].phone_number)) {
			cout << "Invalid phone number!\n";
			goto wrong_number;
		}

	wrong_date:
		string date_of_birth;
		cout << "Enter date of birth (e.g., 01.01.1999): ";
		cin >> date_of_birth;
		if (!IsDate(date_of_birth)) {
			cout << "Invalid date of birth!\n";
			goto wrong_date;
		}
		ConvertDate(date_of_birth, notes[i].date_of_birth);
		cout << endl;
		cin.ignore();
	}
}

bool IsPhoneNumber(string phone_number) {
	if (regex_match(phone_number, regex("\\+7[0-9]{10}")))
		return 1;
	else
		return 0;
}

bool IsDate(string date) {
	string rgx = "(0[1-9]|[1-2][0-9]|3[0-1]).(0[1-9]|1[0-2]).[0-9]{4}";
	if (regex_match(date, regex(rgx)))
		return 1;
	else
		return 0;
}

void ConvertDate(string date, int *convert) {
	convert[0] = stoi(date.substr(0, 2));
	convert[1] = stoi(date.substr(3, 2));
	convert[2] = stoi(date.substr(6, 4));
}

void PrintNotes(Note *notes, const int kNumNotes) {
	for (int i = 0; i < kNumNotes; i++) {
		cout << i + 1 << ". " << notes[i].full_name << endl;
		cout << notes[i].phone_number << endl;
		cout << notes[i].date_of_birth[0] << ".";
		cout << notes[i].date_of_birth[1] << ".";
		cout << notes[i].date_of_birth[2] << endl << endl;
	}
}

void SortNotes(Note *notes, const int kNumNotes) {
	for (int i = 0; i < kNumNotes - 1; i++)
		for (int j = 0; j < kNumNotes - i - 1; j++) {
			string phone1 = notes[j].phone_number.substr(0, 4);
			string phone2 = notes[j + 1].phone_number.substr(0, 4);
			if (phone1.compare(phone2) > 0)
				swap(notes[j], notes[j + 1]);
		}
}

void FindSurname(Note *notes, const int kNumNotes, string surname) {
	bool is_found = false;
	for (int i = 0; i < kNumNotes; i++) {
		if (notes[i].full_name.find(surname) != string::npos) {
			is_found = true;
			cout << notes[i].full_name << ", ";
			cout << notes[i].phone_number << ", ";
			cout << notes[i].date_of_birth[0] << ".";
			cout << notes[i].date_of_birth[1] << ".";
			cout << notes[i].date_of_birth[2];
		}
	}

	if (!is_found)
		cout << "There is no person with such surname!";
}