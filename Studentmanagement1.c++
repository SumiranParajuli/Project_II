

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
struct Details {
    string name;
    int gender = 0;
    int age = 0;
    string phone;
    string email;
    float marks ;
    float percentage ;
    float fees ;
    string attendance;
    int id;
};

class Student
{
  public:
    void registerAdmin()
    {
        Details d;
        cout << "Enter phone number: ";
        cin >> d.phone;
        cout << "Enter email: ";
        cin >> d.email;
        cout << "Enter ID: ";
        cin >> d.id;

        ofstream out("student.txt", ios::app);
        out << "ID: " << d.id << endl;
        out << "Phone: " << d.phone << endl;
        out << "Email: " << d.email << endl;
        out.close();
        cout << "Registration successful." << endl;
    }

    void registerStudent()
    {
        Details d;
        cout << "Enter ID: ";
        cin >> d.id;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, d.name);
        cout << "Enter gender (1 male, 2 female): ";
        cin >> d.gender;
        cout << "Enter age: ";
        cin >> d.age;

        ofstream out("student.txt", ios::app);
        out << "ID: " << d.id << endl;
        out << "Name: " << d.name << endl;
        out << "Gender: " << d.gender << endl;
        out << "Age: " << d.age << endl;
        out.close();
        cout << "Student details saved." << endl;
    }

    bool idExists(int searchId)
    {
        ifstream in("student.txt");
        if (!in) return false;
        string label;
        while (in >> label)
        {
            if (label == "ID:")
            {
                int id;
                in >> id;
                if (id == searchId)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void loginAdmin()
    {
        int enteredId;
        cout << "Enter admin ID: ";
        cin >> enteredId;
        if (!idExists(enteredId)) {
            cout << "Invalid ID, login failed." << endl;
            return;
        }

        cout << "Login successful." << endl;
        cout << "1) Enter Student Details\n2) Enter Student Marks\n3) Enter Student Attendance\n4) Enter Student Fees\n5) Exit" << endl;
        cout << "Enter your choice: ";
        int choice; cin >> choice;
        switch (choice)
        {
        case 1: enterDetails(); break;
        case 2: enterMarks(); break;
        case 3: enterAttendance(); break;
        case 4: enterFees(); break;
        case 5: cout << "Exiting menu." << endl; break;
        default: cout << "Invalid choice." << endl; break;
        }
    }

    void loginStudent()
    {

        int enteredId;
        cout << "Enter student ID: ";
        cin >> enteredId;
        if (!idExists(enteredId)) {
            cout << "Invalid ID, login failed." << endl;
            return;
        }
        cout << "Login successful. You may view your details in the file." << endl;
       
    }

    void enterDetails()
    {
        Details d;
        cout << "Enter ID: "; cin >> d.id;
        cin.ignore();
        cout << "Enter name: "; getline(cin, d.name);
        cout << "Enter gender: "; cin >> d.gender;
        cout << "Enter age: "; cin >> d.age;
        ofstream out("student.txt", ios::app);
        out << "ID: " << d.id << endl;
        out << "Name: " << d.name << endl;
        out << "Gender: " << d.gender << endl;
        out << "Age: " << d.age << endl;
        out.close();
        cout << "Details saved." << endl;
    }

    void enterMarks()
    {
        Details d;
        cout << "Enter ID: "; cin >> d.id;
        cout << "Enter marks (out of 500): "; cin >> d.marks;
        d.percentage = (d.marks / 500.0f) * 100.0f;
        ofstream out("student.txt", ios::app);
        out << "ID: " << d.id << endl;
        out << "Marks: " << d.marks << endl;
        out << "Percentage: " << d.percentage << endl;
        out.close();
        cout << "Marks saved." << endl;
    }

    void enterAttendance()
    {
        Details d;
        cout << "Enter ID: "; cin >> d.id;
        cout << "Enter attendance (e.g. 80%): "; cin >> d.attendance;
        ofstream out("student.txt", ios::app);
        out << "ID: " << d.id << endl;
        out << "Attendance: " << d.attendance << endl;
        out.close();
        cout << "Attendance saved." << endl;
    }

    void enterFees()
    {
        Details d;
        cout << "Enter ID: "; cin >> d.id;
        cout << "Enter fees paid: "; cin >> d.fees;
        ofstream out("student.txt", ios::app);
        out << "ID: " << d.id << endl;
        out << "Fees: " << d.fees << endl;
        out.close();
        cout << "Fees saved." << endl;
    }
};

int main()
{
    Student s;
    int choice;
    cout << "-----------------------------------" << endl;
    cout << "1) Register Admin" << endl;
    cout << "2) Login as Admin" << endl;
    cout << "3) Register Student" << endl;
    cout << "4) Login as Student" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1: s.registerAdmin(); break;
    case 2: s.loginAdmin(); break;
    case 3: s.registerStudent(); break;
    case 4: s.loginStudent(); break;
    default: cout << "Invalid choice" << endl; break;
    }
    return 0;
}