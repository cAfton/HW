#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Students
{
private:
	string FirstName;
	string LastName;
	string ThirdName;
	int Age;
	vector<int> Marks;
public:

	string GetLastName() const
	{
		return LastName;
	}

	Students(string firstName, string lastName, string thirdName, int age) : FirstName(firstName), LastName(lastName), ThirdName(thirdName), Age(age), Marks() {};

	void AddMark(int a)
	{
		if (a <= 12 and a > 0)
		{
			Marks.push_back(a);
		}
		else
		{
			throw invalid_argument("error, you're gay");
		}
	}

	void DeleteMark(int a)
	{
		Marks.erase(Marks.begin() + a);
	}

	int NewYear()
	{
		Age = Age + 1;
		return Age;
	}

	friend ostream& operator<<(ostream& out, Students& studenti)
	{
		out << studenti.FirstName << ", " << studenti.LastName << ", " << studenti.ThirdName << ", " << studenti.Age << ", ";
		for_each(studenti.Marks.begin(), studenti.Marks.end(), [&out](int a) {out << a << ", "; });
		return out;
	}
	friend istream& operator>>(istream& in, Students& studenti)
	{
		cout << "Введіть Данні студента: " << endl;
		in >> studenti.FirstName >> studenti.LastName >> studenti.ThirdName >> studenti.Age;
		return in;
	}

	~Students();

};

enum Subject { cpp, html, python, java, Csharp };

class Group
{
private:
	string name;
	string Teacher;
	vector<Students> Studenti;
	Subject CurrentSubject;
	int Auditori;
public:
	Group(string name, string teacher, vector<Students> studenti, Subject currentSubject, int auditori) : Teacher(teacher),
		Studenti(studenti), CurrentSubject(currentSubject), Auditori(auditori), name(name) {};

	string GetName() const {
		return this->name;
	}

	void AddStudent(Students a)
	{
		Studenti.push_back(a);
	}

	void DeleteStudent(string LastName)
	{
		Studenti.erase(remove_if(Studenti.begin(), Studenti.end(), [&LastName](const Students& student) {return student.GetLastName() == LastName; }), Studenti.end());
	}

	void ReplaceTeacher()
	{
		string teacher;
		cout << "What teacher you want to replace? ";
		cin >> teacher;
		Teacher = teacher;
	}

	void ReplaceSubject()
	{
		int choice;
		cout << "Доступні предмети:" << endl;
		cout << "0 - C++" << endl;
		cout << "1 - HTML" << endl;
		cout << "2 - Python" << endl;
		cout << "3 - Java" << endl;
		cout << "4 - C#" << endl;
		cin >> choice;
		if (choice <= 4 && choice >= 0)
		{
			switch (choice) {
			case 0:
				CurrentSubject = cpp;
				break;
			case 1:
				CurrentSubject = html;
				break;
			case 2:
				CurrentSubject = python;
				break;
			case 3:
				CurrentSubject = java;
				break;
			case 4:
				CurrentSubject = Csharp;
				break;
			}
		}
		else
		{
			throw invalid_argument("error, wrong choice");
		}
	}

	void ReplaceAuditory()
	{
		int newAuditory;
		cout << "enter new Auditory: ";
		cin >> newAuditory;
		Auditori = newAuditory;
	}

	void DisplayAllStudents(ostream& out)
	{
		for_each(this->Studenti.begin(), this->Studenti.end(), [&out](Students misha) {out << misha << ", "; });
	}

	friend ostream& operator<<(ostream& out, Group& group)
	{
		out << "Teacher: " << group.Teacher << endl;
		out << "Students: ";
		group.DisplayAllStudents(out);
		out << "CurrentSubject: " << group.CurrentSubject << endl;
		out << "Auditory: " << group.Auditori << endl;
		return out;
	}


};

class Academia
{
private:
	string Name;
	string Adress;
	string Director;
	vector<int> Auditories;
	vector<Group> Groups;
public:
	Academia(string name, string adress, string director, vector<Group> groups, vector<int> auditories) :Name(name),
		Adress(adress), Director(director), Auditories(auditories), Groups(groups) {}

	void AddNewGroup(string name, string teacher, vector<Students> studenti, Subject currentSubject, int auditori) {
		Group tmp(name, teacher, studenti, currentSubject, auditori);
		this->Groups.push_back(tmp);
	}
	void AddGroup(Group tmp) {
		Groups.push_back(tmp);
	}

	void DeleteStudent(string Name)
	{
		Groups.erase(remove_if(Groups.begin(), Groups.end(), [&Name](const Group& Group) {return Group.GetName() == Name; }), Groups.end());
	}

	void ReplaceDirector()
	{
		string Director;
		cout << "What director you want to replace? ";
		cin >> Director;
		this->Director = Director;
	}

	void DisplayAllStudents(ostream& out)
	{
		for_each(this->Groups.begin(), this->Groups.end(), [&out](Group elem) {out << elem << "\n\t"; });
	}

	void DisplayAcademia() {
		cout << "Name: " << this->Name; cout << "\nAdress: " << this->Adress << "\nDirector: " << this->Director << "\nAuditories: " << this->Auditories << "\nGroups: " << 
	}

};