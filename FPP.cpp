#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

void welcome_message() {
	cout << "*************************************************************************\n";
	cout << "*                                                                       *\n";
	cout << "*   **    **  *****  **       ******   *****      *     *     ******    *\n";
	cout << "*   ** ** **  **     **      **       *     *    * *   * *    **        *\n";
	cout << "*   ** ** **  *****  **     **       *       *  *   * *   *   *****     *\n";
	cout << "*   ** ** **  **     **      **       *     *  *     *     *  **        *\n";
	cout << "*    ******   *****  *******  ******   *****  *             * ******    *\n";
	cout << "*                                                                       *\n";
	cout << "*************************************************************************\n\n";
}

void PrintMainMenu() {
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

class Member {
private:
	string memberNumber;
	string memberTier;
	string passportNumber;
	int MRZ;
	string memberName;
	int MPB;   

public:
	
	Member() {
		memberNumber = "";
		memberTier = "";
		passportNumber = "";
		MRZ = 0;
		memberName = "";
		MPB = 0;
	}

	void setMemberNumber(string number){memberNumber = number; }
	void setMemberTier(string tier) { memberTier = tier; }
	void setPassportNumber(string passport) { passportNumber = passport; }
	void setMRZ(int mrz) { MRZ = mrz; }
	void setMemberName(string name) { memberName = name; }
	void setMPM(int millageP) { MPB = millageP; }
	
};

class Flight {
private:

public:


};

int main() {
	welcome_message();
	PrintMainMenu();
	int Option;
	cin >> Option;

	switch (Option) {
	case 1:
	{
		Member m1, m2, m3, m4;
		string date;

		m1.setMemberNumber("202456734");
		m1.setMemberTier("Gold");
		m1.setPassportNumber("A56677890");
		m1.setMRZ(4);
		m1.setMemberName("WONG Claire");
		m1.setMPM(45000);

		m2.setMemberNumber("202333890");
		m2.setMemberTier("Green");
		m2.setPassportNumber("C78678908");
		m2.setMRZ(5);
		m2.setMemberName("MA Kathy");
		m2.setMPM(10000);

		m3.setMemberNumber("202067856");
		m3.setMemberTier("Silver");
		m3.setPassportNumber("E38876890");
		m3.setMRZ(1);
		m3.setMemberName("CHAN Peter");
		m3.setMPM(53200);

		m4.setMemberNumber("202211843");
		m4.setMemberTier("Gold");
		m4.setPassportNumber("E38900078");
		m4.setMRZ(7);
		m4.setMemberName("CHEUNG Alice");
		m4.setMPM(30000);

		cout << "Starting data loaded successfully! " << endl;
		cout << " ***Set System Date for updating Mileage Points*** "<< endl;
		cout << "Please enter system date(DD - MM - YYYY) : ";
		cin >> date;

		break;
	}
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: break;
	case 6: break;
	default: break;
	}
	return 0;
}
