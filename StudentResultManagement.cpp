// Student Result Management System
// Object-Oriented Programming Using C++ Lab - Task 2
// Name: Gurteg Singh Setia | USN: NB25ECE064 | Section: SEC A

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Base class: holds the basic details of a student
class Student {
protected:
    int rollNo;
    string name;

public:
    Student(int r = 0, string n = "") : rollNo(r), name(n) {}

    // Virtual function: allows runtime polymorphism
    virtual void display() const {
        cout << "Roll: " << rollNo << " | Name: " << name;
    }

    virtual ~Student() {}
};

// Derived class: adds marks and the pass/fail result
class Result : public Student {
public:
    float marks;

    Result(int r = 0, string n = "", float m = 0) : Student(r, n) {
        if (m < 0 || m > 100)
            throw invalid_argument("Marks must be 0-100");
        marks = m;
    }

    // Overrides the base class display()
    void display() const override {
        Student::display();
        cout << " | Marks: " << marks << " | " << (marks >= 40 ? "PASS" : "FAIL") << endl;
    }

    // Operator overloading: writes a record to a file stream
    friend ofstream& operator<<(ofstream& out, const Result& s) {
        out << s.rollNo << " " << s.name << " " << s.marks << endl;
        return out;
    }
};

int main() {
    vector<Result> records;

    // 1. Add records with exception handling
    try {
        records.emplace_back(101, "Alice", 85.5);
        records.emplace_back(102, "Bob", 35.0);
        records.emplace_back(103, "Charlie", 92.0);
        records.emplace_back(104, "Invalid", 150.0); // Triggers exception
    } catch (const exception& e) {
        cout << "Exception Caught: " << e.what() << "\n\n";
    }

    // 2. Display all records using runtime polymorphism
    cout << "--- All Student Results ---\n";
    for (const auto& r : records) {
        const Student* ptr = &r;   // base class pointer to derived object
        ptr->display();            // calls Result::display() at runtime
    }

    // 3. Save to file and retrieve
    ofstream out("results.txt");
    for (const auto& r : records) out << r;
    out.close();

    cout << "\n--- Retrieved from File ---\n";
    ifstream in("results.txt");
    int r;
    string n;
    float m;
    while (in >> r >> n >> m) {
        Result temp(r, n, m);
        temp.display();
    }
    in.close();

    // 4. Filter using STL algorithm and lambda expression
    float cutoff = 80.0;
    cout << "\n--- Students Scoring Above " << cutoff << " ---\n";
    for_each(records.begin(), records.end(), [cutoff](const Result& s) {
        if (s.marks > cutoff) s.display();
    });

    return 0;
}
