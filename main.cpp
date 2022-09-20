#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

struct Division {
	string name;
	double quarterSales[4] = {0,0,0,0};
	double yearlySales = 0;
};

int* corSalesQuarter(vector<Division*> visions) {
	int* p = new int[2];
	p[0] = 0;
	p[1] = 10000000000000;

	for (int i = 0;i < 4;i++) { //Each quarter
		double total = 0;
		for (int j = 0;j < 4;j++) { //Each division
			total += visions.at(j)->quarterSales[i];
		}
		if (total > p[0]) {
			p[0] = total;
		}
		if(total < p[1]) {
			p[1] = total;
		}
		cout << "\nTotal coporate sales for quarter " << i + 1 << ": " << total << endl;
	}

	return p;
}

void yearlySalesDiv(vector<Division*> visions) {
	for (int i = 0;i < 4;i++) {
		cout << "\nDivision " << visions.at(i)->name << " yearly sales: " << visions.at(i)->yearlySales << endl;
	}
}

void totalCorYearly(vector<Division*> visions) {
	double total = 0;
	for (int i = 0;i < 4;i++) {
		total += visions.at(i)->yearlySales;
	}
	cout << "\nTotal yearly coporate sales " << total << endl;
}

void avgQuarDiv(vector<Division*> visions) {
	double avg = 0;
	for (int i = 0;i < 4;i++) {//Each division
		cout << "\nAverage quarterly sales for the divisons: " << visions.at(i)->yearlySales / 4 << endl;
	}
}

int main()
{
	ifstream in;
	in.open("D:\\CodingProjects\\text\\test.txt"); //Opens this file

	vector<Division*> visions;
	string temp;

	while (getline(in,temp)) { //While getting each line
		Division* p = new Division; //Creates a pointer and a new divisiom

		istringstream ins;
		ins.str(temp);

		string division;
		double quarterSal[4];

		//Storing everything

		ins >> division;
		for (int i = 0;i < 4;i++) {
			ins >> quarterSal[i];
			p->quarterSales[i] = quarterSal[i];
			p->yearlySales += p->quarterSales[i];
		}

		p->name = division;
		visions.push_back(p);
	}

	int* hlow = corSalesQuarter(visions);
	yearlySalesDiv(visions);
	totalCorYearly(visions);
	avgQuarDiv(visions);
	cout << "Highest: " << hlow[0] << "\nLowest: " << hlow[1] << endl;
}
