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
    string getName() {
        return this->Name;
    }
    string getSurname() const {
        return this->Surname;
    }
    string getFather() {
        return this->Father;
    }
    int getAge() {
        return this->Age;
    }
    vector<int>& getMarks(){
        return this->Marks;
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

    string getTeacher() {
        return this->Teacher;
    }
    Subject getSubjectInLearning() {
        return this->SubjectInLearning;
    }
    int getAuditorium() {
        return this->Auditorium;
    }

    void addStudent(Student newStudent) {
        this->Students.push_back(newStudent);
    }

    void deleteStudent(string Surname) {
         Students.erase(remove_if(Students.begin(), Students.end(), [&Surname](const Student& student) {return student.getSurname() == Surname; }), Students.end());
    }

    vector<Student>& getStudents() {
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
        cin >> userChose;
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
        cin >> userChose;
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
                this->Auditoriumes.push_back(newAud);
                itStrBegin = itStdEnd + 1;
            }

            auto itGroupsStart = find(line.begin(), line.end(), '<');
            auto itGroupsEnd = find(line.begin(), line.end(), '>');
            string groups = string(itGroupsStart, itGroupsEnd);
            //cout << groups << endl;
            itBegin = groups.begin();
            auto itEndAll = groups.begin();


            while (itEndAll != groups.end() - 1) {
                itBegin = itEndAll + 1;

                auto itBeginGroup = find(itBegin, groups.end(), '[');
                auto itEndGroup = find(itBegin, groups.end(), ']');
                string group = string(itBeginGroup + 1, itEndGroup);
                //cout << group << endl;
                itEndAll = itEndGroup;


                auto itVarBegin = group.begin();
                auto itVarEnd = find(itVarBegin, group.end(), ';');
                string saveNameGroup = string(itVarBegin, itVarEnd);
                
                itVarBegin = itVarEnd + 1;
                itVarEnd = find(itVarBegin, group.end(), ';');
                string saveTeacherGroup = string(itVarBegin, itVarEnd);
                
                itVarBegin = itVarEnd + 1;
                itVarEnd = find(itVarBegin, group.end(), ';');
                int saveSubjectGroup = stoi(string(itVarBegin, itVarEnd));
                
                itVarBegin = itVarEnd + 1;
                itVarEnd = find(itVarBegin, group.end(), '{');
                int saveAuditGroup = stoi(string(itVarBegin, itVarEnd));
                if (!this->isInAuds(saveAuditGroup))
                {
                    throw invalid_argument("");
                }
                

                Subject sub;
                switch (saveSubjectGroup)
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

                Group newGroup(saveNameGroup, saveTeacherGroup, sub, saveAuditGroup);

                auto itBeginStudents = find(itBegin, groups.end(), '{');
                auto itEndStudents = find(itBegin, groups.end(), '}');

                string students = string(itBeginStudents, itEndStudents);
                //cout << students << endl;
                auto itEndStudent = group.begin();
                auto itStudentsEnd = students.begin();
                while (itStudentsEnd != students.end() - 1) {
                    itBegin = itStudentsEnd + 1; 
                    itStudentsEnd = find(itBegin, students.end(), ')');
                    string student = string(itBegin, itStudentsEnd + 1);
                    //cout << "--- " << student << endl;

                    itVarBegin = student.begin();
                    itVarEnd = find(student.begin(), student.end(), ';');
                    string saveName = string(itVarBegin, itVarEnd);

                    itVarBegin = itVarEnd + 1;
                    itVarEnd = find(itVarBegin, student.end(), ';');
                    string saveSurname = string(itVarBegin, itVarEnd);

                    itVarBegin = itVarEnd + 1;
                    itVarEnd = find(itVarBegin, student.end(), ';');
                    string saveFather = string(itVarBegin, itVarEnd);

                    itVarBegin = itVarEnd + 1;
                    itVarEnd = find(itVarBegin, student.end(), '(');
                    int saveAge = stoi(string(itVarBegin, itVarEnd));

                    Student newStudent(saveName, saveSurname, saveFather, saveAge);

                    auto itMarksBegin = itVarEnd;
                    auto itMarksEnd = find(student.begin(), student.end(), ')');
                    itBegin = itMarksEnd + 1;
                    string marks = string(itMarksBegin, itMarksEnd);
                    itMarksEnd = marks.begin();
                    itVarEnd = marks.begin();
                    while (itVarEnd != marks.end() - 1) {
                        itVarBegin = itVarEnd + 1;
                        itVarEnd = find(itVarBegin, marks.end(), ',');
                        int saveMark = stoi(string(itVarBegin, itVarEnd));
                        newStudent.addMark(saveMark);
                    }

                    newGroup.addStudent(newStudent);
                }
                this->Groupes.push_back(newGroup);
                
            }

        }
    }

    Academy(){}

    void save(string path) {
        ofstream file;
        file.open(path, 'w');
        if (file.is_open())
        {
            string line;
            line = this->Name + ";" + this->Adress + ";" + this->Director + "[";
            for_each(this->Auditoriumes.begin(), this->Auditoriumes.end(), [&line](int num) {line += to_string(num) + ","; });
            line += "]<";
            for_each(this->Groupes.begin(), this->Groupes.end(), [&line](Group& group) {
                line += "[" + group.getName() + ";" + group.getTeacher() + ";" + to_string(group.getSubjectInLearning()) + ";" + to_string(group.getAuditorium()) + "{";
                for_each(group.getStudents().begin(), group.getStudents().end(), [&line](Student& student) {
                    
                    line += student.getName() + ";" + student.getSurname() + ";" + student.getFather() + ";" + to_string(student.getAge()) + "(";
                    for_each(student.getMarks().begin(), student.getMarks().end(), [&line](int mark) {
                        line += to_string(mark) + ",";
                        });
                    line += ")";
                    });
                line += "}]";
                });
            line += ">";

            file << line;
        }
    }

    void addGroup(Group newGroup) {
        this->Groupes.push_back(newGroup);
    }

    vector<Group>& getGroupes(){
        return this->Groupes;
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

    void printOnlyGroupName() {
        for_each(this->Groupes.begin(), this->Groupes.end(), [](Group group) {cout << group.getName() << endl; });
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

    Academy ITStep("text.txt");
    int userChoise;

    do
    {
        system("cls");
        cout << "|1 - add new group         |" << endl;
        cout << "|2 - add new student       |" << endl;
        cout << "|3 - delete group          |" << endl;
        cout << "|4 - delete student        |" << endl;
        cout << "|5 - view academy          |" << endl;
        cout << "|6 - view groups           |" << endl;
        cout << "|7 - view students         |" << endl;
        cout << "|8 - add mark              |" << endl;
        cout << "|9 - delete mark           |" << endl;
        cout << "|10 - add age              |" << endl;
        cout << "|11 - change teacher       |" << endl;
        cout << "|12 - change subject       |" << endl;
        cout << "|13 - change auditorium    |" << endl;
        cout << "|14 - change director      |" << endl;
        cout << "|15 - save                 |" << endl;
        cout << "\n|0 - exit                  |" << endl;
        cin >> userChoise;
        string userCh, studentName;
        system("cls");
        switch (userChoise)
        {
        case 1: {

            Group group;
            cin >> group;
            ITStep.addGroup(group);
            break;
        }
        case 2: {
            ITStep.printOnlyGroupName();
            cout << "print group will be added: ";
            cin >> userCh;
            Student newStudent("", "", "", 1);
            cin >> newStudent;

           for_each(ITStep.getGroupes().begin(), ITStep.getGroupes().end(), [&userCh, newStudent](Group& group) {
               if (userCh == group.getName())
               {
                   group.addStudent(newStudent);
               }
               });
                
            
            break;
        }
        case 3: {
            ITStep.printOnlyGroupName();
            cout << "\n\nwrite name to delete: ";
            cin >> userCh;
            ITStep.deleteGroup(userCh);
            break;
        }
        case 4: {
            cout << "Enter group name: ";
            cin >> userCh;
            cout << "Enter student surname to delete: ";
            cin >> studentName;

            for_each(ITStep.getGroupes().begin(), ITStep.getGroupes().end(), [userCh, studentName](Group& group) {
                if (group.getName() == userCh) {
                    group.deleteStudent(studentName);
                }
                });
            break;
        }
        case 5: {
            cout << ITStep << endl;
            system("pause");
            break;
        }
        case 6: {
            ITStep.printAllGroups();
            system("pause");
            break;
        }
        case 7: {
            for_each(ITStep.getGroupes().begin(), ITStep.getGroupes().end(), [](Group group) {cout << group << endl; });
            system("pause");
            break;
        }
        case 8: {
            int mark;
            cout << "Enter group name: ";
            cin >> userCh;
            cout << "Enter student surname: ";
            cin >> studentName;
            cout << "Enter mark to add: ";
            cin >> mark;

            for_each(ITStep.getGroupes().begin(), ITStep.getGroupes().end(), [userCh, studentName, mark](Group& group) {
                if (group.getName() == userCh) {
                    for_each(group.getStudents().begin(), group.getStudents().end(), [userCh, studentName, mark](Student& student) {
                        if (student.getSurname() == studentName) {
                            student.addMark(mark);
                        }
                        });
                }
                });
            break;
        }
        case 9: {
            int mark;
            cout << "Enter group name: ";
            cin >> userCh;
            cout << "Enter student surname: ";
            cin >> studentName;
            for_each(ITStep.getGroupes().begin(), ITStep.getGroupes().end(), [userCh, studentName, mark](Group& group) {
                if (group.getName() == userCh) {
                    for_each(group.getStudents().begin(), group.getStudents().end(), [userCh, studentName, mark](Student& student) {
                        if (student.getSurname() == studentName) {
                            for_each(student.getMarks().begin(), student.getMarks().begin(), [](int m) {cout << m << endl; });
                        }
                        });
                }
                });

            cout << "Enter mark to delete: ";
            cin >> mark;

            for_each(ITStep.getGroupes().begin(), ITStep.getGroupes().end(), [userCh, studentName, mark](Group& group) {
                if (group.getName() == userCh) {
                    for_each(group.getStudents().begin(), group.getStudents().end(), [userCh, studentName, mark](Student student) {
                        if (student.getName() == studentName) {
                            student.deleteMark(mark);
                        }
                        });
                }
                });
            break;
        }
        case 10: {
            int age;
            cout << "Enter group name: ";
            cin >> userCh;
            cout << "Enter student surname: ";
            cin >> studentName;

            for_each(ITStep.getGroupes().begin(), ITStep.getGroupes().end(), [userCh, studentName](Group& group) {
                if (group.getName() == userCh) {
                    for_each(group.getStudents().begin(), group.getStudents().end(), [userCh, studentName](Student student) {
                        if (student.getSurname() == studentName) {
                            student.newYear();
                        }
                        });
                }
                });
            break;
        }
        case 11: {
            cout << "Enter group name: ";
            cin >> userCh;
            cout << "Enter new teacher's name: ";
            string newTeacher;
            cin >> newTeacher;

            for_each(ITStep.getGroupes().begin(), ITStep.getGroupes().end(), [userCh, newTeacher](Group group) {
                if (group.getName() == userCh) {
                    group.changeTeacher(newTeacher);
                }
                });
            break;
        }
        case 12: {
            cout << "Enter group name: ";
            cin >> userCh;

            for_each(ITStep.getGroupes().begin(), ITStep.getGroupes().end(), [userCh](Group group) {
                if (group.getName() == userCh) {
                    group.changeSubject();
                }
                });
            break;
        }
        case 13: {
            cout << "Enter group name: ";
            cin >> userCh;
            int auditor;
            do
            {
                cout << "Enter correct new auditorium: ";
                cin >> auditor;
            } while (!ITStep.isInAuds(auditor));


            for_each(ITStep.getGroupes().begin(), ITStep.getGroupes().end(), [userCh, auditor](Group group) {
                if (group.getName() == userCh) {
                    group.changeAuditorium(auditor);
                }
                });
            break;
        }
        case 14: {
            cout << "print new director: ";
            cin >> userCh;
            ITStep.changeDirector(userCh);
            break;
        }
        case 15: {
            ITStep.save("text.txt");
            break;
        }
        case 0: {
            ITStep.save("text.txt");
            break;
        }
        default:
            break;
        }
    } while (userChoise != 0);

}