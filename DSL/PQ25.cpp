#include <iostream>
#include <stack>
#include <cctype> // For isalpha and tolower
#include <string>
using namespace std;

// Function to clean up the string: remove non-alphanumeric characters and convert to lowercase
string cleanString(const string& str) {
    string cleaned;
    for (char ch : str) {
        if (isalnum(ch)) { // Check if the character is alphanumeric
            cleaned += tolower(ch); // Convert to lowercase
        }
    }
    return cleaned;
}

// Function to print the original and reversed strings using a stack
void printOriginalAndReversed(const string& str) {
    stack<char> s;
    string cleaned = cleanString(str);

    // Push each character of the cleaned string onto the stack
    for (char ch : cleaned) {
        s.push(ch);
    }

    // Print the original cleaned string
    cout << "Original (cleaned) string: " << cleaned << endl;

    // Pop characters to form the reversed string
    string reversed;
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    // Print the reversed string
    cout << "Reversed string: " << reversed << endl;
}

// Function to check if the string is a palindrome
bool isPalindrome(const string& str) {
    stack<char> s;
    string cleaned = cleanString(str);

    // Push each character of the cleaned string onto the stack
    for (char ch : cleaned) {
        s.push(ch);
    }

    // Check if the cleaned string is equal to its reversed version
    for (char ch : cleaned) {
        if (ch != s.top()) { // Compare each character with the stack's top
            return false;
        }
        s.pop();
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    // Print original and reversed strings
    printOriginalAndReversed(input);

    // Check if the input is a palindrome
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
