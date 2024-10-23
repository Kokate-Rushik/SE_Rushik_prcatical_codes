//Code by Kokate Rushik

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeToFile() {
    ofstream outFile("output.txt", ios::app);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    string inputLine;
    char choice;

    do {
        cout << "\nEnter a line to write in the file: ";
        getline(cin, inputLine);
        outFile << inputLine << endl;
        cout << "Line written to the file successfully." << endl;

        cout << "Do you want to write another line? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    outFile.close();
}

void readFromFile() {
    ifstream inFile("output.txt");
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    inFile.seekg(0, ios::end);
    if (inFile.tellg() == 0) {
        cout << "File is empty." << endl;
        inFile.close();
        return;
    }

    inFile.seekg(0, ios::beg);

    string line;
    cout << "\nFile contents:" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

void clearFile() {
    ofstream outFile("output.txt", ios::trunc);
    if (!outFile) {
        cout << "Error opening file for clearing!" << endl;
        return;
    }

    cout << "File cleared successfully." << endl;
    outFile.close();
}

int main() {
    int choice;

    do {
        cout << "\nWhat do you want to do?" << endl;
        cout << "1. Write in the file" << endl;
        cout << "2. Read the file" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                writeToFile();
                break;
            case 2:
                readFromFile();
                break;
            case 3:
                cout << "Exiting the program." << endl;
                break;
            case 00:
                clearFile();
                break;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    } while (choice != 3);

    return 0;
}
