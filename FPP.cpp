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

class Member {
private:
    string memberNumber;
    string memberTier;
    string passportNumber;
    int MRZ;
    string memberName;
    int MPB;

public:
    Member() : MRZ(0), MPB(0) {}

    // Setters
    void setMemberNumber(string number) { memberNumber = number; }
    void setMemberTier(string tier) { memberTier = tier; }
    void setPassportNumber(string passport) { passportNumber = passport; }
    void setMRZ(int mrz) { MRZ = mrz; }
    void setMemberName(string name) { memberName = name; }
    void setMPM(int mpb) { MPB = mpb; }

 
};

// Function to load starting data
vector<Member> loadMembers() {
    vector<Member> members;

    Member m1;
    m1.setMemberNumber("202456734");
    m1.setMemberTier("Gold");
    m1.setPassportNumber("A56678990");
    m1.setMRZ(4);
    m1.setMemberName("WONG Claire");
    m1.setMPM(45000);
    members.push_back(m1);

    Member m2;
    m2.setMemberNumber("203233890");
    m2.setMemberTier("Green");
    m2.setPassportNumber("C78678908");
    m2.setMRZ(5);
    m2.setMemberName("MA Kathy");
    m2.setMPM(10000);
    members.push_back(m2);

    Member m3;
    m3.setMemberNumber("20067856");
    m3.setMemberTier("Silver");
    m3.setPassportNumber("E38578900");
    m3.setMRZ(1);
    m3.setMemberName("CHAN Peter");
    m3.setMPM(53200);
    members.push_back(m3);

    Member m4;
    m4.setMemberNumber("202211843");
    m4.setMemberTier("Gold");
    m4.setPassportNumber("E38900708");
    m4.setMRZ(7);
    m4.setMemberName("CHEUNG Alice");
    m4.setMPM(30000);
    members.push_back(m4);

    cout << "\nStarting data loaded successfully!\n";
    return members;
}

// Validate system date input
string setSystemDate() {
    string date;
    int invalidCount = 0;

    cout << "\n*** Set System Date for updating Mileage Points ***\n";

    while (true) {
        cout << "Please enter system date (DD-MM-YYYY): ";
        cin >> date;

        if (date.size() == 10 && date[2] == '-' && date[5] == '-') {
            string day = date.substr(0, 2);
            string month = date.substr(3, 2);
            string year = date.substr(6, 4);

            int d = stoi(day);
            int m = stoi(month);
            int y = stoi(year);

            if (y == 2025 && d >= 1 && d <= 31 && m >= 1 && m <= 12) {
                cout << "System date set successfully: " << date << "\n";
                return date;
            }
        }

        invalidCount++;
        cout << "Invalid date format or out of range.\n";

        if (invalidCount >= 3) {
            cout << "Too many invalid attempts. Default date set to 30-06-2025.\n";
            return "30-06-2025";
        }
    }
}

void printMainMenu() {
    cout << "*** FFP Main Menu ***\n";
    cout << "[1] Load Starting Data\n";
    cout << "[2] Show All Member Accounts\n";
    cout << "[3] Open or Close Member Account\n";
    cout << "[4] Member Account Operations\n";
    cout << "[5] Generate Daily Statement\n";
    cout << "[6] Credits and Exit\n";
    cout << "*******************************\n";
    cout << "Option (1 - 6): ";
}

int main() {
    vector<Member> members;
    bool dataLoaded = false;
    string systemDate;

    welcome_message();

    int option;
    do {
        printMainMenu();
        cin >> option;

        switch (option) {
        case 1:
            members = loadMembers();
            systemDate = setSystemDate();
            dataLoaded = true;
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
        default:
            cout << "\nInvalid option. Please enter 1-6.\n\n";
        }

    } while (option != 6);

    return 0;
}
