#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PersonalRecord {
public:
    string name;
    string dob;  // Date of birth in "DD-MM-YYYY" format
    string telephone;

    PersonalRecord(string n, string d, string t) : name(n), dob(d), telephone(t) {}

    // Display function
    void display() const {
        cout << "Name: " << name << ", DOB: " << dob << ", Telephone: " << telephone << endl;
    }
};

// Function to compare records by Name (for sorting)
bool compareByName(const PersonalRecord &a, const PersonalRecord &b) {
    return a.name < b.name;  // Lexicographical comparison
}

// Function to search a record by name
int searchByName(const vector<PersonalRecord>& records, const string& name) {
    for (size_t i = 0; i < records.size(); ++i) {
        if (records[i].name == name) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
}

int main() {
    vector<PersonalRecord> records;
    records.push_back(PersonalRecord("John Doe", "12-04-1990", "123-456-7890"));
    records.push_back(PersonalRecord("Jane Smith", "22-11-1985", "987-654-3210"));
    records.push_back(PersonalRecord("Alice Brown", "15-08-1992", "555-123-4567"));
    records.push_back(PersonalRecord("Bob White", "01-01-1988", "777-888-9999"));

    // Sorting records by Name
    sort(records.begin(), records.end(), compareByName);

    // Displaying sorted records
    cout << "Sorted Records by Name:" << endl;
    for (const auto& record : records) {
        record.display();
    }

    // Searching for a specific record by name
    string nameToSearch;
    cout << "\nEnter name to search: ";
    getline(cin, nameToSearch);

    int index = searchByName(records, nameToSearch);
    if (index != -1) {
        cout << "\nRecord Found: ";
        records[index].display();
    } else {
        cout << "\nRecord not found!" << endl;
    }

    return 0;
}
