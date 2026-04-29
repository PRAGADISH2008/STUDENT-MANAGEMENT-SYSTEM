#include<iostream>
#include <fstream>
#include <string>
using namespace std;
class Student{
    public:
        string name;
        string rollno;
        int age;
        string course;
};
void addStudent(){
    Student s;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Roll No: ";
    cin >> s.rollno;
    cout << "Enter Age: ";
    cin >> s.age;
    cin.ignore();
    cout << "Enter Course: ";
    getline(cin, s.course);
    
    ofstream fout("studdata.txt", ios::app);
    fout<<s.rollno<<"|"<<s.name<<"|"<<s.age<<"|"<<s.course<<"\n";
    fout.close();
    cout << "Student record added successfully!\n";
}
void updateStudent(){
    string roll;
    cout << "Enter Roll No to update: ";
    cin >> roll;
    ifstream fin("studdata.txt");
    ofstream fout("temp.txt");
    int f=0;
    Student s;
    while(getline(fin,s.rollno,'|')){
        getline(fin,s.name,'|');
        fin>>s.age;
        fin.ignore();
        getline(fin,s.course);
        if(s.rollno == roll){
            cout << "Current details:\n";
            cout<<"ROLL NO : "<<s.rollno;
            cout<<"\nNAME : "<<s.name;
            cout<<"\nAGE : "<<s.age;
            cout<<"\nCOURSE : "<<s.course;
            
            cout<<"\nENTER NEW DETAILS : \n";
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, s.name);
            cout << "Enter Roll No: ";
            cin >> s.rollno;
            cout << "Enter Age: ";
            cin >> s.age;
            cin.ignore();
            cout << "Enter Course: ";
            getline(cin, s.course);
            
            fout<<s.rollno<<"|"<<s.name<<"|"<<s.age<<"|"<<s.course<<"\n";
            f=1;
        }
        else{
            fout<<s.rollno<<"|"<<s.name<<"|"<<s.age<<"|"<<s.course<<"\n";
        }
    }
    fin.close();
    fout.close();
    remove("studdata.txt");
    rename("temp.txt", "studdata.txt");
    if(f==0){
        cout << "Record not found!\n";
    }
    else{
        cout << "Record updated successfully!\n";
    }
}
void delStudent(){
    string roll;
    cout << "Enter Roll No to delete: ";
    cin >> roll;
    ifstream fin("studdata.txt");
    ofstream fout("temp.txt");
    int f=0;
    Student s;
    while(getline(fin,s.rollno,'|')){
        getline(fin,s.name,'|');
        fin>>s.age;
        fin.ignore();
        getline(fin,s.course);
        if(s.rollno != roll){
            fout<<s.rollno<<"|"<<s.name<<"|"<<s.age<<"|"<<s.course<<"\n";
        }
        else{
            f=1;
        }
    }
    fin.close();
    fout.close();
    remove("studdata.txt");
    rename("temp.txt", "studdata.txt");
    if(f==0){
        cout << "Record not found!\n";
    }
    else{
        cout << "Record deleted successfully!\n";
    }
}
void dispStudent(){
    ifstream fin("studdata.txt");
    Student s;
    while(getline(fin,s.rollno,'|')){
        getline(fin,s.name,'|');
        fin>>s.age;
        fin.ignore();
        getline(fin,s.course);
        
        cout<<"ROLL NO : "<<s.rollno;
        cout<<"\nNAME : "<<s.name;
        cout<<"\nAGE : "<<s.age;
        cout<<"\nCOURSE : "<<s.course;
        cout << "\n----------------------\n";
    }
}
int main(){
    int choice;
    while(true){
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Update Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                addStudent();
                break;
            case 2:
                updateStudent();
                break;
            case 3:
                delStudent();
                break;
            case 4:
                dispStudent();
                break;
            case 5:
                cout<<"Exiting Thank you....";
                return 0;
            default:
                cout<<"INVALID CHOICE!";
        }
    }
}
