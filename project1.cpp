
#include<fstream>
#include<iostream>
#include<iomanip>
#include <string>
#include <sstream>
using namespace std;

class StudentInfo {
public:
	void SetFirstName(string firstNameVal) {firstName = firstNameVal; }
	void SetLastName(string lastNameVal) { lastName = lastNameVal; }
	void SetTest1(double test1Val) { test1 = test1Val; }
	void SetTest2(double test2Val) { test2 = test2Val; }
	void SetTest3(double test3Val) { test3 = test3Val; }
	void SetTest4(double test4Val) { test4 = test4Val; }
	void SetFinal(double finalVal) { finalScore = finalVal; }
	void SetAverage(double averlVal) { average = averlVal; }
	void Print();

	string GetFirstName() const { return firstName; }
	string GetLastName() const { return lastName; }
	double GetTest1() const { return test1; }
	double GetTest2() const { return test2; }
	double GetTest3() const { return test3; }
	double GetTest4() const { return test4; }
	double GetFinal() const { return finalScore; }
	double GetAverage() const { return average; }
	//int GetAverage() const;

private:
	string firstName;
	string lastName;
	double test1;
	double test2;
	double test3;
	double test4;
	double finalScore;
	double average;
};
void StudentInfo::Print() {
	// write to file gradereport.txt
	cout << firstName << " " << lastName << " " << test1 << " " << test2 << " " << test3 << " " << test4 << " " << finalScore << " " << average <<endl;
}

int main()
{
	StudentInfo studentData[30];
	string data;
	int i = 0;
	ifstream infile;
	infile.open("CIT1325.txt");
	while (!infile.eof()) // To get you all the lines.
	{
		//studentData[i] = new StudentInfo();
		getline(infile, data); // Saves the line in STRING.
		stringstream ss(data);
		double sum = 0;
		for (int n = 0; n < 7; n++)
		{
			string val;

			ss >> val;
		//	cout << val << "\n";
			
			if (n == 0) { studentData[i].SetFirstName(val); }
			if (n == 1) { studentData[i].SetLastName(val); }
			if (n == 2) {
				studentData[i].SetTest1(atof(val.c_str())); sum += atof(val.c_str());
			}
			if (n == 3) { 
				studentData[i].SetTest2(atof(val.c_str())); sum += atof(val.c_str());
			}
			if (n == 4) { 
				studentData[i].SetTest3(atof(val.c_str())); sum += atof(val.c_str());
			}
			if (n == 5) { 
				studentData[i].SetTest4(atof(val.c_str())); sum += atof(val.c_str());
			}

			if (n == 6) { 
				studentData[i].SetFinal(atof(val.c_str())); sum += atof(val.c_str()) * 2;
			}
			
		}
		studentData[i].SetAverage(sum / 6);
		i++;
	}
	infile.close();
	double maxScore = 0;
	int positionOfMaxScore=0;
	for (int loop = 0; loop < i; loop++) {
		studentData[loop].Print();
		if (studentData[loop].GetAverage() > maxScore)
		{
			maxScore = studentData[loop].GetAverage();
			positionOfMaxScore = loop;
		}

	}
	cout << " Student has Max Score \n ";
	studentData[positionOfMaxScore].Print();
	

}
