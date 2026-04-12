#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;


void PrintMainMenu(){
	cout << "***FFP Main Menu ***" << endl;
	cout << "[1] Load Starting Data" << endl;
	cout << "[2] Show All Member Accounts" << endl;
	cout << "[3] Open or Close Member Account" << endl;
	cout << "[4] Member Account Operations" << endl;
	cout << "[5] Generate Daily Statement" << endl;
	cout << "[6] Credits and Exit" << endl;
	cout << "********************************" << endl;
	cout << "Option (1 - 6) : ";
}

void R1_StartingData(){

	

}

int main() {

	int Option;

	PrintMainMenu();
	cin >> Option;

	switch (Option) {
	case 1: R1_StartingData();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default : 
	}

	return 0;
}
