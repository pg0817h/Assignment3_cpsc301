#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Person.h"
using namespace std;

void ReadDate(vector<Person> &a) {
	ifstream read("input.txt");
	Person first;
	Person last;
	Person id;
	Person company;
	Person hour;
	Person payr;
	int size = 16;
	string firstN, lastN;
	float payR;
	float hours;
	int ID;
	string CompanyN;
	for (int i = 0; i < size; i++) {
		read >> firstN >> lastN >> ID >> CompanyN >> hours >> payR;

		a.push_back(first);
		a[i].setFirstName(firstN);
		a.push_back(last);
		a[i].setLastName(lastN);
		a.push_back(id);
		a[i].setEmployeeId(ID);
		a.push_back(company);
		a[i].setCompanyName(CompanyN);
		a.push_back(hour);
		a[i].setHoursWorked(hours);
		a.push_back(payr);
		a[i].setPayRate(payR);

	}


}

void getCompanies(vector<Person> &e, vector<string> &c) {
	int size = 16;

	for (int i = 0; i < size; i++) {
		c.push_back(e[i].getCompanyName());

	}



}

void PrintHighestPaid(vector<Person> &e) {
	int size = 15;
	string employee;
	int id;
	string employer;
	float total;
	float max = e[0].totalPay();
	for (int i = 0; i < size; i++) {
		if (max < e[i + 1].totalPay()) {
			max = e[i + 1].totalPay();
			employee = e[i + 1].getFirstName();
			id = e[i + 1].getEmployeeId();
			employer = e[i + 1].getCompanyName();
			total = e[i + 1].totalPay();

		}
	}
	cout << "Highest paid: " << employee << endl;
	cout << "Employee ID:" << id << endl;
	cout << "Employer:" << employer <<endl;
	cout << "Total Pay:" << "$" << total << endl;
}

void separateAndSave(vector<Person> &e,vector<string> &c) {
	float totalIntel = 0;
	float totalBoeing = 0;
	float totalDouglas = 0;
	float totalRaytheon = 0;
	float totalHealthTech = 0;
	ofstream ouput;
	ouput.open("Intel.txt");

	output << "Intel.txt" << endl;
	output << "_______________________________________________________________" << endl;
	for (int i = 0; i < 16; i++) {
		if ("Intel" == c[i]) {
			output << e[i].fullName() << " "<< e[i].getEmployeeId() << " "<< c[i] << " "<< e[i].totalPay() << endl;

			totalIntel += e[i].totalPay();

		}

	}

	output << "Total" << "$" << totalIntel << endl;
	output.close();
	output.open("Boeing.txt");
	output << "Boeing.txt" << endl;
	output << "_______________________________________________________________" << endl;
	for (int i = 0; i < 16; i++) {
		if ("Boeing" == c[i]) {

			output << e[i].fullName() << " " << e[i].getEmployeeId() << " " << c[i] << " " << e[i].totalPay() << endl;


			totalBoeing += e[i].totalPay();

		}


	}
	output << "Total" << "$" << totalBoeing << endl;
	output.close();
	output.open("Douglas.txt");
	output << "Douglas.txt" << endl;
	output << "_______________________________________________________________" << endl;
	for (int i = 0; i < 16; i++) {
		if ("Douglas" == c[i]) {
			output << e[i].fullName() << " " << e[i].getEmployeeId() << " " << c[i] << " " << e[i].totalPay() <<endl;
			totalDouglas += e[i].totalPay();

		}

	}
	output << "Total" << "$" << totalDouglas << endl;
	output.close();
	output.open("Raytheon.txt");
	output << "Raytheon.txt" << endl;
	output << "_______________________________________________________________" << endl;
	for (int i = 0; i < 16; i++) {
		if ("Raytheon" == c[i]) {
			output << e[i].fullName()<< " " << e[i].getEmployeeId() << " " << c[i] << " " << e[i].totalPay() << endl;

			totalRaytheon += e[i].totalPay();
		}

	}
	output << "Total" << "$" << totalRaytheon << endl;
	output.close();
	output.open("HealthTech.txt");
	output << "HealthTech.txt" << endl;
	output << "_______________________________________________________________" << endl;
	for (int i = 0; i < 16; i++) {
		if ("HealthTech" == c[i]) {
			output << e[i].fullName() << " " << e[i].getEmployeeId() << " " << c[i] << " " << e[i].totalPay();
			cout << endl;
			totalHealthTech += e[i].totalPay();

		}

	}
	output << "Total" << "$" << totalHealthTech << endl;
	output.close();
}
int main() {


	vector<Person> employees;
	vector<string> companyNames;


	ReadDate(employees);
	getCompanies(employees,companyNames);
	PrintHighestPaid(employees);
	cout << endl;
	separateAndSave(employees,companyNames);

	system("pause");
}
