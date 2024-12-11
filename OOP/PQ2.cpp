#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Student {
private:
    std::string name;
    int rollNumber;
    std::string className;
    std::string division;
    std::string dob; 
    std::string bloodGroup;
    std::string contactAddress;
    std::string telephoneNumber;
    std::string drivingLicenseNo;
    static int studentCount;

public:

    Student() 
        : name(""), rollNumber(0), className(""), division(""), dob(""), 
          bloodGroup(""), contactAddress(""), telephoneNumber(""), drivingLicenseNo("") {
        studentCount++;
    }


    Student(const std::string& n, int r, const std::string& c, const std::string& d,
            const std::string& b, const std::string& addr, const std::string& tel, 
            const std::string& dl)
        : name(n), rollNumber(r), className(c), division(d), dob(""), 
          bloodGroup(b), contactAddress(addr), telephoneNumber(tel), drivingLicenseNo(dl) {
        studentCount++;
    }


    Student(const Student& other)
        : name(other.name), rollNumber(other.rollNumber), className(other.className),
          division(other.division), dob(other.dob), bloodGroup(other.bloodGroup),
          contactAddress(other.contactAddress), telephoneNumber(other.telephoneNumber),
          drivingLicenseNo(other.drivingLicenseNo) {
        studentCount++;
    }


    ~Student() {
        studentCount--;
    }


    static int getStudentCount() {
        return studentCount;
    }


    void setDOB(const std::string& dateOfBirth) {
        dob = dateOfBirth;
    }


    friend std::ostream& operator<<(std::ostream& os, const Student& s);


    friend std::istream& operator>>(std::istream& is, Student& s);
};


int Student::studentCount = 0;


std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Name: " << s.name << "\n"
       << "Roll Number: " << s.rollNumber << "\n"
       << "Class: " << s.className << "\n"
       << "Division: " << s.division << "\n"
       << "Date of Birth: " << s.dob << "\n"
       << "Blood Group: " << s.bloodGroup << "\n"
       << "Contact Address: " << s.contactAddress << "\n"
       << "Telephone Number: " << s.telephoneNumber << "\n"
       << "Driving License No.: " << s.drivingLicenseNo << "\n";
    return os;
}


std::istream& operator>>(std::istream& is, Student& s) {
    cout << "Enter Name: ";
    std::getline(is, s.name);
    cout << "Enter Roll Number: ";
    is >> s.rollNumber;
    is.ignore(); 
    cout << "Enter Class: ";
    std::getline(is, s.className);
    cout << "Enter Division: ";
    std::getline(is, s.division);
    cout << "Enter Date of Birth (DD-MM-YYYY): ";
    std::getline(is, s.dob);
    cout << "Enter Blood Group: ";
    std::getline(is, s.bloodGroup);
    cout << "Enter Contact Address: ";
    std::getline(is, s.contactAddress);
    cout << "Enter Telephone Number: ";
    std::getline(is, s.telephoneNumber);
    cout << "Enter Driving License No.: ";
    std::getline(is, s.drivingLicenseNo);
    return is;
}

int main() {
    try {

        int numStudents;
        cout << "Enter number of students: ";
        std::cin >> numStudents;
        std::cin.ignore(); 

        if (numStudents <= 0) {
            throw std::invalid_argument("Number of students must be positive.");
        }

        Student* students = new Student[numStudents];

        for (int i = 0; i < numStudents; ++i) {
            cout << "Entering details for student " << (i + 1) << ":\n";
            std::cin >> students[i];
        }

        cout << "\nStudent Database:\n";
        for (int i = 0; i < numStudents; ++i) {
            cout << "\nStudent " << (i + 1) << ":\n" << students[i] << "\n";
        }

        cout << "Total students: " << Student::getStudentCount() << "\n";

        delete[] students;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << endl;
        return 1; 
    }

    return 0;
}
