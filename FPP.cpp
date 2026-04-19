#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
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

    Member() {
        MRZ = 0;
        MPB = 0;
    }
    void setMemberNumber(string number) {
        memberNumber = number;
    }
    void setMemberTier(string tier) {
        memberTier = tier;
    }
    void setPassportNumber(string passport) {
        passportNumber = passport;
    }
    void setMRZ(int mrz) {
        MRZ = mrz;
    }
    void setMemberName(string name) {
        memberName = name;
    }
    void setMPM(int mpb) {
        MPB = mpb;
    }

    string getMemberNumber() const { return memberNumber; }

    string getMemberTier() const { return memberTier; }

    string getPassportNumber() const { return passportNumber; }

    int getMRZ() const { return MRZ; }

    string getMemberName() const { return memberName; }

    int getMPB() const { return MPB; }
};

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

class FlightRecord {
private:
    string memberNumber;
    string origin;
    string destination;
    string flightNumber;
    string cabinClass;
    string departureDate;
    string creationDate;
    bool updated;

public:
    FlightRecord() {
        updated = false;
    }

    void setMemberNumber(string number) {
        memberNumber = number;
    }
    void setOrigin(string orig) {
        origin = orig;
    }
    void setDestination(string destin) {
        destination = destin;
    }
    void setFlightNumber(string flightNum) {
        flightNumber = flightNum;
    }
    void setCabinClass(string CabinC) {
        cabinClass = CabinC;
    }
    void setDepartureDate(string DepartD) {
        departureDate = DepartD;
    }
    void setCreationDate(string CreateD) {
        creationDate = CreateD;
    }
    void setUpdated(bool UpD) {
        updated = UpD;
    }

    string getMemberNumber() const { return memberNumber; }

    string getOrigin() const { return origin; }

    string getDestination() const { return destination; }

    string getFlightNumber() const { return flightNumber; }

    string getCabinClass() const { return cabinClass; }

    string getDepartureDate() const { return departureDate; }

    string getCreationDate() const { return creationDate; }

    bool getUpdated() const { return updated; }
};

vector<FlightRecord> loadFlights() {
    vector<FlightRecord> flights;

    FlightRecord f1;
    f1.setMemberNumber("202211843");
    f1.setOrigin("Hong Kong");
    f1.setDestination("London");
    f1.setFlightNumber("CC51");
    f1.setCabinClass("First");
    f1.setDepartureDate("23-05-2025");
    f1.setCreationDate("01-05-2025");
    flights.push_back(f1);

    FlightRecord f2;
    f2.setMemberNumber("202211843");
    f2.setOrigin("London");
    f2.setDestination("Hong Kong");
    f2.setFlightNumber("CC82");
    f2.setCabinClass("First");
    f2.setDepartureDate("10-06-2025");
    f2.setCreationDate("01-05-2025");
    flights.push_back(f2);

    FlightRecord f3;
    f3.setMemberNumber("203233890");
    f3.setOrigin("London");
    f3.setDestination("Dubai");
    f3.setFlightNumber("CC61");
    f3.setCabinClass("Economy");
    f3.setDepartureDate("12-06-2025");
    f3.setCreationDate("10-06-2025");
    flights.push_back(f3);

    FlightRecord f4;
    f4.setMemberNumber("20067856");
    f4.setOrigin("Hong Kong");
    f4.setDestination("Dubai");
    f4.setFlightNumber("CC31");
    f4.setCabinClass("Business");
    f4.setDepartureDate("05-07-2025");
    f4.setCreationDate("20-06-2025");
    flights.push_back(f4);

    FlightRecord f5;
    f5.setMemberNumber("20067856");
    f5.setOrigin("Dubai");
    f5.setDestination("London");
    f5.setFlightNumber("CC62");
    f5.setCabinClass("Business");
    f5.setDepartureDate("08-07-2025");
    f5.setCreationDate("20-06-2025");
    flights.push_back(f5);

    FlightRecord f6;
    f6.setMemberNumber("202456734");
    f6.setOrigin("Dubai");
    f6.setDestination("Hong Kong");
    f6.setFlightNumber("CC32");
    f6.setCabinClass("Business");
    f6.setDepartureDate("05-08-2025");
    f6.setCreationDate("02-08-2025");
    flights.push_back(f6);

    return flights;
}

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
        cout << "Invalid date format or out of range, please try again.\n";

        if (invalidCount >= 3) {
            cout << "Too many invalid attempts. Default date set to 30-06-2025.\n";
            return "30-06-2025";
        }
    }
}

// R2==============================================================================================================
void showAllMemberAccounts(const vector<Member>& members, const vector<FlightRecord>& flights, bool dataLoaded) {
    if (!dataLoaded) {
        cout << "\nError: Please load starting data first (Option 1)!\n\n";
        return;
    }

    cout << "\n=== Member Account Records ===\n";
    cout << left
        << setw(13) << "Member No"
        << setw(10) << "Tier"
        << setw(15) << "Passport"
        << setw(6) << "MRZ"
        << setw(28) << "Member Name"
        << setw(10) << "Points" << endl;
    cout << string(85, '-') << endl;

    vector<Member> sortedMembers = members;
    sort(sortedMembers.begin(), sortedMembers.end(),
        [](const Member& a, const Member& b) {
            return a.getMemberName() < b.getMemberName();
        });

    for (int i = 0; i < sortedMembers.size(); i++) {
        cout << left
            << setw(13) << sortedMembers[i].getMemberNumber()
            << setw(10) << sortedMembers[i].getMemberTier()
            << setw(15) << sortedMembers[i].getPassportNumber()
            << setw(6) << sortedMembers[i].getMRZ()
            << setw(28) << sortedMembers[i].getMemberName()
            << setw(10) << sortedMembers[i].getMPB() << endl;
    }

    cout << "\n=== Flight Records (Not Updated) ===\n";
    cout << left
        << setw(13) << "Member No"
        << setw(12) << "Origin"
        << setw(12) << "Destination"
        << setw(10) << "Flight"
        << setw(12) << "Cabin"
        << setw(15) << "Dep Date"
        << setw(8) << "Updated" << endl;
    cout << string(85, '-') << endl;

    vector<FlightRecord> pending = flights;
    sort(pending.begin(), pending.end(),
        [](const FlightRecord& a, const FlightRecord& b) {
            return a.getDepartureDate() > b.getDepartureDate();
        });

    bool hasRecord = false;
    for (int i = 0; i < pending.size(); i++) {
        if (!pending[i].getUpdated()) {
            cout << left
                << setw(13) << pending[i].getMemberNumber()
                << setw(12) << pending[i].getOrigin()
                << setw(12) << pending[i].getDestination()
                << setw(10) << pending[i].getFlightNumber()
                << setw(12) << pending[i].getCabinClass()
                << setw(15) << pending[i].getDepartureDate()
                << setw(8) << "0" << endl;
            hasRecord = true;
        }
    }
    if (!hasRecord) {
        cout << "No pending flight records.\n";
    }
    cout << endl;
}

// R3=======================================================================================================
void openOrCloseMemberAccount(vector<Member>& members, vector<FlightRecord>& flights, bool& dataLoaded) {
    if (!dataLoaded) {
        cout << "\nError: Please load starting data first (Option 1)!\n\n";
        return;
    }

    string memNo;
    cout << "\nEnter Member Number: ";
    cin >> memNo;

    int index = -1;
    for (int i = 0; i < members.size(); i++) {
        if (members[i].getMemberNumber() == memNo) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Close Account
        cout << "\nMember found: " << members[index].getMemberName() << endl;
        cout << "Confirm to CLOSE this account? (Y/N): ";
        char c;
        cin >> c;

        if (toupper(c) == 'Y') {
            string delNo = members[index].getMemberNumber();
            members.erase(members.begin() + index);

            for (size_t i = 0; i < flights.size(); ) {
                if (flights[i].getMemberNumber() == delNo) {
                    flights.erase(flights.begin() + i);
                }
                else {
                    i++;
                }
            }
            cout << "Account and related flight records deleted successfully.\n";
        }
        else {
            cout << "Operation cancelled.\n";
        }
    }
    else {
        // Open New Account
        cout << "\nMember not found. Opening new account...\n";

        Member newM;
        string name, passport, tier;
        int retry = 0;

        while (retry < 3) {
            cout << "Enter Member Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Passport Number: ";
            cin >> passport;
            cout << "Enter Tier: ";
            cin >> tier;

            if (passport.length() == 9 && isupper(passport[0])) {
                newM.setMemberNumber("202" + to_string(rand() % 90000 + 10000));
                newM.setMemberName(name);
                newM.setPassportNumber(passport);
                newM.setMRZ(0);
                newM.setMemberTier(tier);
                newM.setMPM(0);

                members.push_back(newM);
                cout << "New member created successfully! Member Number: " << newM.getMemberNumber() << endl;
                return;
            }
            else {
                retry++;
                cout << "Invalid input. " << (3 - retry) << " attempts left.\n";
            }
        }
        cout << "Too many invalid attempts. No member added.\n";
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
    vector<FlightRecord> flights;
    bool dataLoaded = false;
    string systemDate;
    // R1.3
    /*if (!dataLoaded) {
        cout << "\nError: Please load starting data first (Option 1).\n\n";}
    else {
        cout << "\nFeature not implemented yet (R2-R5).\n\n";
    }*/

    welcome_message();

    int option;
    do {
        printMainMenu();
        cin >> option;

        switch (option) {
        case 1:
            members = loadMembers();
            flights = loadFlights();
            systemDate = setSystemDate();
            dataLoaded = true;
            break;
        case 2:
            showAllMemberAccounts(members, flights, dataLoaded);
            break;
        case 3:
            openOrCloseMemberAccount(members, flights, dataLoaded);
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