#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <fstream>
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

	friend ofstream& operator<<(ofstream& file, Students& studenti) {
		file << studenti.FirstName << ',' << studenti.LastName << ',' << studenti.ThirdName << ',' << studenti.Age << ',';
		file << '[';
		for_each(studenti.Marks.begin(), studenti.Marks.end(), [&file](int a) {file << a << ','; });
		file << ']';
		return file;
	}

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
		for_each(this->Studenti.begin(), this->Studenti.end(), [&out](Students& misha) {out << misha << ", "; });
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

	void writeToFileStudenti(ofstream& file) {
		file << '[';
		for_each(this->Studenti.begin(), this->Studenti.end(), [&file](Students& misha) {file << misha << ':'; });
		file << ']';
	}

	friend ofstream& operator<<(ofstream& file, Group& group) {
		file << '[';
		file << group.name << ',';
		file << group.Teacher << ',';
		group.writeToFileStudenti(file);
		file << ',';
		switch (group.CurrentSubject) //enum Subject { cpp, html, python, java, Csharp };
		{
		case cpp:
			file << "cpp";
			break;
		case html:
			file << "html";
			break;
		case python:
			file << "python";
			break;
		case java:
			file << "java";
			break;
		case Csharp:
			file << "Csharp";
			break;
		default:
			break;
		}
		file << ',';
		file << group.Auditori;
		return file;
	}

	void reatFromFileGroup(string& line) {
		string tmp;

		auto Bracket = line.find(']');
		auto Coma = line.find(':');

		while (Bracket < Coma) {
			tmp = line.substr(0, Coma + 1);
			//Student << 
			line.erase(0, Coma + 1);
		}
		line.erase(0, Bracket + 3);

	}

	friend ifstream& operator>>(string& line, Group& group) {

		auto tmp = line.find(','); group.name = line.substr(0, tmp); line.erase(0, tmp + 1);
		tmp = line.find(','); group.Teacher = line.substr(0, tmp); line.erase(0, tmp + 2);

		group.reatFromFileGroup(line);



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

    void DisplayAllGroups(ostream& out)
	{
		for_each(this->Groups.begin(), this->Groups.end(), [&out](Group elem) {out << elem << "\n\t"; });
	}

	void DisplayAllAuditories(ostream& out) {
		for_each(this->Auditories.begin(), this->Auditories.end(), [&out](int elem) {out << elem << "; "; });
	}

	friend ostream& operator<<(ostream& out, Academia& auditories) {
		out << "Name: " << auditories.Name; 
		out << "\nAdress: " << auditories.Adress;
		out << "\nDirector: " << auditories.Director;
		out << "\nAuditories: "; auditories.DisplayAllAuditories(out);
		out << "\nGroups: "; auditories.DisplayAllGroups(out);
		return out;
	}

	void writeToFileAcademia(ofstream& file) {
		file << '[';
		for_each(this->Auditories.begin(), this->Auditories.end(), [&file](int elem) {file << elem << ','; });
		file << ']';
	}

	friend ofstream& operator<<(ofstream& file, Academia& academia) {
		file << academia.Name << ',' << academia.Adress << ',' << academia.Director << ',';
		academia.writeToFileAcademia(file);
		file << ',';
		for_each(academia.Groups.begin(), academia.Groups.end(), [&file](Group elem) {file << elem << ';'; });
		file << ']';
		file << endl;
		return file;
	}

	void reatFromFileAcademia(string& line) {
		auto tmp = line.find(','); 
		this->Auditories.push_back(stoi(line.substr(0, tmp)));
		line.erase(0, tmp + 1);

		auto Bracket = line.find(']');
		auto Coma = line.find(',');

		while (Bracket > Coma) {
			tmp = line.find(',');
			this->Auditories.push_back(stoi(line.substr(0, tmp)));
			line.erase(0, tmp + 1);
			Coma = line.find(',');
		}
		line.erase(0, Bracket + 3);


	}

	friend ifstream& operator>>(ifstream& file, Academia& academia) {
		string line;
		getline(file, line);
		auto tmp = line.find(','); academia.Name = line.substr(0, tmp); line.erase(0, tmp + 1);
		tmp = line.find(','); academia.Adress = line.substr(0, tmp); line.erase(0, tmp + 1);
		tmp = line.find(','); academia.Director = line.substr(0, tmp); line.erase(0, tmp + 2);
		academia.reatFromFileAcademia(line);


	}


};



int main() {
	string filepath = "text.txt";
	
	//Academia fromFile();

	Students studenchiki("Olecsiy", "Autist", "Someone", 16);
	Students studenchiki1("John", "Smith", "Michaelson", 20);
	Students studenchiki2("Emily", "Johnson", "Edwardson", 19);
	Students studenchiki3("Michael", "Brown", "Williamson", 22);
	Students studenchiki4("Sophia", "Taylor", "Jameson", 21);
	Students studenchiki5("Daniel", "Anderson", "Robertson", 23);
	Students studenchiki6("Olivia", "Thomas", "Benjaminson", 18);
	Students studenchiki7("Ethan", "Jackson", "Christopheron", 20);
	Students studenchiki8("Isabella", "White", "Davidson", 19);
	Students studenchiki9("Liam", "Harris", "Andrewson", 22);
	Students studenchiki10("Emma", "Martin", "Charleson", 21);
	Students studenchiki11("James", "Clark", "Anthonyson", 24);
	Students studenchiki12("Mia", "Lewis", "Jonathanson", 18);
	Students studenchiki13("Alexander", "Walker", "Harrisonson", 23);
	Students studenchiki14("Charlotte", "Hall", "Eliason", 20);
	Students studenchiki15("Benjamin", "Allen", "Matthewson", 21);
	Students studenchiki16("Amelia", "Young", "Samuelson", 19);
	Students studenchiki17("Lucas", "King", "Nicholson", 22);
	Students studenchiki18("Grace", "Scott", "Jeffersonson", 20);
	Students studenchiki19("Henry", "Green", "Jacksonson", 23);
	Students studenchiki20("Ava", "Baker", "Franklinson", 18);

	vector<Students> Studenchikies{ studenchiki ,studenchiki1,studenchiki2,studenchiki3};


	Group P34("p34", "Ura", Studenchikies, cpp, 213);
	Group P1881("p35", "Did", Studenchikies, cpp, 215);

	vector<Group> G{ P34 , P1881 };

	vector<int> N{ 213,234,325,142 };

	Academia step("Ww", "WwW", "someone", G, N);

	cout << step;
	

	
	ofstream file(filepath);
	file << step;

}


//Academia1,Adress,Director,[125,314,],[name,Teacher,[name,lastname,thirdName,age,[1,2,3,];name2,lastname2,thirdName2,age2,[1,2,3,];],cpp,314;name1,T2,[],cpp,125;]