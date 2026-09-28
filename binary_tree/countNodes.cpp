#include<iostream>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;





  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


//this is my soln 

//but not knowing it it was 0(n) as the miss travers the whole array in the worst case

#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    void getPersonData() {
        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;
    }
};

// Derived class
class Student : public Person {
private:
    int rollNo;
    string department;
    int semester;

public:
    void getStudentData() {
        getPersonData();

        cout << "Enter roll number: ";
        cin >> rollNo;

        cin.ignore(); // clear newline

        cout << "Enter department: ";
        getline(cin, department);

        cout << "Enter semester: ";
        cin >> semester;
    }

    void display() {
        cout << "\n--- Student Information ---\n";
        cout << "Name       : " << name << endl;
        cout << "Age        : " << age << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Department : " << department << endl;
        cout << "Semester   : " << semester << endl;
    }
};

int main() {
    Student s;

    s.getStudentData();
    s.display();

    return 0;
}