#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

enum Subject {
    CPP = 1,
    CSh,
    Python, 
    CSS,
    Unity,
    Java
};

class Student {
    string Surname;
    string Name;
    string Father;
    int Age;
    vector<int> Marks;
public:
    Student(string name, string surname, string father, int age): Surname(surname), Name(name), Father(father), Age(age), Marks(){}

    Student() {}

    void addMark(int mark) {
        if (mark <= 12 && mark >= 1) {
            this->Marks.push_back(mark);
            return;
        }
    }

    string getSurname() const {
        return this->Surname;
    }

    void deleteMark(int index) {
        this->Marks.erase(Marks.begin() + index);
    }

    int newYear() {
        this->Age++;
        return this->Age;
    }

    friend ostream& operator<<(ostream& out, const Student& student) {
        out << "Surname: " << student.Surname << "\nName: " << student.Name << "\nFather: " << student.Father << "\nAge: " << student.Age << endl << endl;
        out << "Marsk: " << endl;
        for_each(student.Marks.begin(), student.Marks.end(), [&out](int mark) {out << mark << endl; });
        return out;
    }


    friend istream& operator>>(istream& in, Student& student) {
        cout << "Surname: ";
        in >> student.Surname;
        cout << "\nName: ";
        in >> student.Name;
        cout << "\nFather: ";
        in >> student.Father;
        cout << "\nAge: ";
        in >> student.Age;
        return in;
    }
};

class Group
{
    string GroupName;
    string Teacher;
    vector<Student> Students;
    Subject SubjectInLearning;
    int Auditorium;
public:
    Group(string groupName, string teacher, Subject subject, int auditorium): GroupName(groupName), Teacher(teacher), SubjectInLearning(subject), Auditorium(auditorium){}

    Group(){}

    void addStudent(Student newStudent) {
        this->Students.push_back(newStudent);
    }

    void deleteStudent(string Surname) {
         Students.erase(remove_if(Students.begin(), Students.end(), [&Surname](const Student& student) {return student.getSurname() == Surname; }), Students.end());
    }

    vector<Student> getStudents() {
        return this->Students;
    }

    string getName() const {
        return this->GroupName;
    }

    void changeTeacher(string newTeacher) {
        this->Teacher = newTeacher;
    }
    void changeSubject() {
        cout << "Chose subject: " << endl;
        cout << "1. CPP\n2. CSh\n3. Python\n4. CSS\n5. Unity\n6. Java\n\n";
        int userChose;
        switch (userChose)
        {
        case 1:
            this->SubjectInLearning = CPP;
            break;
        case 2:
            this->SubjectInLearning = CSh;
            break;
        case 3:
            this->SubjectInLearning = Python;
            break;
        case 4:
            this->SubjectInLearning = CSS;
            break;
        case 5:
            this->SubjectInLearning = Unity;
            break;
        case 6:
            this->SubjectInLearning = Java;
            break;
        default:
            throw invalid_argument("");
        }
    }

    void changeAuditorium(int auditorium) {
        this->Auditorium = auditorium;
    }

    void printAllStudents() const {
        for_each(this->Students.begin(), this->Students.end(), [](Student student) {cout << student << endl; });
    }

    friend ostream& operator<<(ostream& out, const Group& group) {
        out << "Group name: " << group.GroupName << "\nTeacher: " << group.Teacher << "\nAuditorium: " << group.Auditorium << "\nSubject In Learning: ";
        switch (group.SubjectInLearning)
        {
        case 1:
            out << "CPP";
                break;
        case 2:
            out << "CSh";
            break;
        case 3:
            out << "Python";
            break;
        case 4:
            out << "CSS";
            break;
        case 5:
            out << "Unity";
            break;
        case 6:
            out << "Java";
            break;
        }
        out << "\n\n\nStudents: \n";
        group.printAllStudents();
        return out;
    }

    friend istream& operator>>(istream& in, Group& group) {
        cout << "Group name: ";
        in >> group.GroupName;
        cout << "\nTeacher: ";
        in >> group.Teacher;
        cout << "\nAuditorium: ";
        in >> group.Auditorium;
        cout << "\n\nChose subject: " << endl;
        cout << "1. CPP\n2. CSh\n3. Python\n4. CSS\n5. Unity\n6. Java\n\n";
        int userChose;
        switch (userChose)
        {
        case 1:
            group.SubjectInLearning = CPP;
            break;
        case 2:
            group.SubjectInLearning = CSh;
            break;
        case 3:
            group.SubjectInLearning = Python;
            break;
        case 4:
            group.SubjectInLearning = CSS;
            break;
        case 5:
            group.SubjectInLearning = Unity;
            break;
        case 6:
            group.SubjectInLearning = Java;
            break;
        default:
            throw invalid_argument("");
        }
        return in;
    }
};

class Academy {
    string Name;
    string Adress;
    string Director;
    vector<int> Auditoriumes;
    vector<Group> Groupes;
public:
    Academy(string name, string adress, string director, int numOfAu) : Name(name), Adress(adress), Director(director) {}

    bool isInAuds(int aud) {
        auto ret = find(this->Auditoriumes.begin(), this->Auditoriumes.end(), aud);
        if (ret != Auditoriumes.end())
        {
            return true;
        }
        else return false;
    }

    Academy(string path) {
        ifstream file;
        string line;
        file.open(path);
        if (file.is_open())
        {
            getline(file, line);
            auto itEnd = find(line.begin(), line.end(), ';');//Academy Name
            auto itBegin = line.begin();
            this->Name = string(itBegin, itEnd);

            itBegin = itEnd;
            itBegin++;
            itEnd = find(itBegin, line.end(), ';');//Adress
            this->Adress = string(itBegin, itEnd);

            itBegin = itEnd;
            itBegin++;
            itEnd = find(itBegin, line.end(), '[');//Director
            this->Director = string(itBegin, itEnd);


            itBegin = itEnd + 1;
            auto EndAuds = find(itBegin, line.end(), ']');  //auditoriums
            string auds = string(itBegin, EndAuds);

            auto itStdEnd = find(auds.begin(), auds.end(), ',');
            auto itStrBegin = auds.begin();

            while (itStrBegin != auds.end())
            {
                itStdEnd = find(itStrBegin, auds.end(), ',');
                int newAud = stoi(string(itStrBegin, itStdEnd));
                itStrBegin = itStdEnd + 1;
            }

            itEnd = find(itBegin, line.end(), ']');
            string nameS, surname, father;
            int age, auditorium, subject;
            string nameG, teacher;
            int isGroup = 0;
            while (itEnd != line.end())//group
            {
                itBegin = itEnd;
                itBegin++;
                itEnd = find(itBegin, line.end(), ';');//Group name
                nameG = string(itBegin, itEnd);

                itBegin = itEnd;
                itBegin++;
                itEnd = find(itBegin, line.end(), ';');//teacher
                teacher = string(itBegin, itEnd);

                itBegin = itEnd;
                itBegin++;
                itEnd = find(itBegin, line.end(), ';');//Subject
                subject = stoi(string(itBegin, itEnd));

                itBegin = itEnd;
                itBegin++;
                itEnd = find(itBegin, line.end(), '{');//auditorium
                auditorium = stoi(string(itBegin, itEnd));
                if (this->isInAuds(auditorium))
                {
                    this->Auditoriumes.push_back(auditorium);
                }

                Subject sub;
                switch (subject)
                {
                case 1:
                    sub = CPP;
                    break;
                case 2:
                    sub = CSh;
                    break;
                case 3:
                    sub = Python;
                    break;
                case 4:
                    sub = CSS;
                    break;
                case 5:
                    sub = Unity;
                    break;
                case 6:
                    sub = Java;
                    break;
                }

                Group newGroup(nameG, teacher, sub, auditorium);


                auto itEndOFStudents = find(itBegin, line.end(), '}');
                int isStudent = 0;
                //auto itGroupes = find();//line with groupes as in mark and students
                while (itEnd + 1 != itEndOFStudents)//students
                {
                    itBegin = itEnd;
                    itBegin++;
                    itEnd = find(itBegin, line.end(), ';');//name
                    nameS = string(itBegin, itEnd);

                    itBegin = itEnd;
                    itBegin++;
                    itEnd = find(itBegin, line.end(), ';');//surname
                    surname = string(itBegin, itEnd);

                    itBegin = itEnd;
                    itBegin++;
                    itEnd = find(itBegin, line.end(), ';');//father
                    father = string(itBegin, itEnd);

                    itBegin = itEnd;
                    itBegin++;
                    itEnd = find(itBegin, line.end(), '(');//age
                    age = stoi(string(itBegin, itEnd));

                    Student student(nameS, surname, father, age);
                    itBegin = itEnd + 1;
                    newGroup.addStudent(student);
                    auto itEndOFMarks = find(itBegin, line.end(), ')');
                   

                    string marks = string(itBegin, itEndOFMarks);
                    auto itMarksBegin = marks.begin();
                    auto itMarksEnd = marks.end();

                    while (itMarksBegin != marks.end())
                    {
                        itMarksEnd = find(itMarksBegin, marks.end(), ',');
                        int newMark = stoi(string(itMarksBegin, itMarksEnd));
                        isGroup;
                        isStudent;
                        newGroup.getStudents()[isStudent].addMark(newMark);
                        itMarksBegin = itMarksEnd + 1;
                    }

                    itEnd = find(itBegin, line.end(), ')');
                    isStudent++;

                }
                this->Groupes.push_back(newGroup);
                isGroup++;
            }


        }
    }


    Academy(){}

    void addGroup(Group newGroup) {
        this->Groupes.push_back(newGroup);
    }

    void deleteGroup(string groupName) {
        Groupes.erase(remove_if(Groupes.begin(), Groupes.end(), [&groupName](const Group& group) {return group.getName() == groupName; }), Groupes.end());
    }

    void changeDirector(string newDirector) {
        this->Director = newDirector;
    }

    void printAllGroups() const {
        for_each(this->Groupes.begin(), this->Groupes.end(), [](Group group) {cout << group << endl; });
    }

    friend ostream& operator<<(ostream& out, Academy& academy) {
        out << "Academy name: " << academy.Name << "\nDirector: " << academy.Director << "\nAdress: " << academy.Adress;
        out << endl;
        out << "\nAuditoriums: \n";
        for_each(academy.Auditoriumes.begin(), academy.Auditoriumes.end(), [](int a) {cout << a << endl; });
        out << endl;
        out << endl;
        academy.printAllGroups();
        return out;
    }

    friend istream& operator>>(istream& in, Academy& academy) {
        cout << "Academy name: ";
        getline(in, academy.Name);
        cout << "\nDirector: ";
        getline(in, academy.Director);
        cout << "\nAdress: ";
        getline(in, academy.Adress);
        return in;
    }


};

int main()
{
    /*Academy ITStep("IT Step", "vulitsa", "Director1", 425);
    Group p34("p34", "Yura", CPP, 312);
    Group p35("p35", "TeacherXZ", CSh, 417);
    Group p36("p36", "Teacher1", Python, 210);
    Student student1("Name1", "Surname1", "Father1", 16);
    Student student2("Name2", "Surname2", "Father2", 17);
    Student student3("Name3", "Surname3", "Father3", 14);

    Student student4("Name4", "Surname4", "Father4", 18);
    Student student5("Name5", "Surname5", "Father5", 14);
    Student student6("Name6", "Surname6", "Father6", 16);

    Student student7("Name7", "Surname7", "Father7", 17);
    Student student8("Name8", "Surname8", "Father8", 16);
    Student student9("Name9", "Surname9", "Father9", 15);*/

    Academy ITStep("text.txt");

    cout << ITStep << endl;


}