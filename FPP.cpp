#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <stdlib.h>
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

void printMainMenu(string op) {
    cout << "*** FFP Main Menu ***\n";
    cout << "[1] Load Starting Data\n";
    cout << "[2] Show All Member Accounts\n";
    cout << "[3] Open or Close Member Account\n";
    cout << "[4] Member Account Operations\n";
    cout << "[5] Generate Daily Statement\n";
    cout << "[6] Credits and Exit\n";
    cout << "*******************************\n";
    cout << "Option (1 - 6): " << op;
}

void Pauseline() {
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

class Member {
private:
    string memberNumber;
    string memberTier;
    string passportNumber;
    int MRZ;
    string memberName;
    int MPB;
    vector<int> recordAmounts;
    vector<string> recordDescriptions;

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

    string getMemberNumber() const { 
        return memberNumber; 
    }
    string getMemberTier() const { 
        return memberTier; 
    }
    string getMemberName() const { 
        return memberName; 
    }
    string getPassportNumber() const {
        return passportNumber;
    }
    int getMPB() const { 
        return MPB; 
    }
    int getMRZ() const { 
        return MRZ; 
    }
    void setMPB(int points) { 
        MPB = points; 
    }

    void addRecord(int amount, string description) {
        recordAmounts.push_back(amount);
        recordDescriptions.push_back(description);
    }
    int getAmount(int i) const {
        return recordAmounts[i];
    }
    string getDescriptions(int i) const {
        return recordDescriptions[i];
    }
    int getRecordCount() const {
        return recordAmounts.size();
    }
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
    m2.setMemberNumber("202333890");
    m2.setMemberTier("Green");
    m2.setPassportNumber("C78678908");
    m2.setMRZ(5);
    m2.setMemberName("MA Kathy");
    m2.setMPM(10000);
    members.push_back(m2);

    Member m3;
    m3.setMemberNumber("202067856");
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
    void setTransacRecord(int amount[]) {
        int *cost = amount;
    }


    string getMemberNumber() const { 
        return memberNumber; 
    }
    bool isUpdated() const { 
        return updated; 
    }
    string getDepartureDate() const { 
        return departureDate; 
    }
    string getOrigin() const {
        return origin;
    }
    string getDestination() const {
        return destination;
    }
    string getCabinClass() const {
        return cabinClass;
    }
    string getFlightNumber() const {
        return flightNumber;
    }
    
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
    f3.setMemberNumber("202333890");
    f3.setOrigin("London");
    f3.setDestination("Dubai");
    f3.setFlightNumber("CC61");
    f3.setCabinClass("Economy");
    f3.setDepartureDate("12-06-2025");
    f3.setCreationDate("10-06-2025");
    flights.push_back(f3);

    FlightRecord f4;
    f4.setMemberNumber("202067856");
    f4.setOrigin("Hong Kong");
    f4.setDestination("Dubai");
    f4.setFlightNumber("CC31");
    f4.setCabinClass("Business");
    f4.setDepartureDate("05-07-2025");
    f4.setCreationDate("20-06-2025");
    flights.push_back(f4);

    FlightRecord f5;
    f5.setMemberNumber("202067856");
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
    string op = "1";

    while (true) {
        cout << "\n*** Set System Date for updating Mileage Points ***\n";
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
                Pauseline();
                return date;
            }
        }

        invalidCount++;
        cout << "Invalid date format or out of range, please try again.\n";
        Pauseline();
        system("cls");
        welcome_message();
        printMainMenu(op);
        if (invalidCount >= 3) {
            cout << "\nToo many invalid attempts. Default date set to 30-06-2025.\n";
            Pauseline();
            return "30-06-2025";
        }
    }
}

void showAllMemberAccounts(const vector<Member>& members, const vector<FlightRecord>& flights) {
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
        if (!pending[i].isUpdated()) {
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
    Pauseline();
}

// R3=======================================================================================================
void openOrCloseMemberAccount(vector<Member>& members, vector<FlightRecord>& flights) {

    string memNo;
    string op = "3";
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
        char confirm;
        do {
            cout << "\nConfirm to CLOSE this account? (Y/N): ";
            cin >> confirm;
            if (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {
                cout << "Invalid input. Please enter 'Y' or 'N'.\n";
                Pauseline();
                system("cls");
                welcome_message();
                printMainMenu(op);
                cout << "\n\nEnter Member Number: " << memNo << endl;
                cout << "\nMember found: " << members[index].getMemberName() << endl;
            }
        } while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');
        if (confirm == 'Y' || confirm == 'y') {
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
            Pauseline();
        }
        else {
            cout << "Operation cancelled.\n";
            Pauseline();
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
                Pauseline();
                system("cls");
                welcome_message();
                printMainMenu(op);
                cout << endl;
            }
        }
        cout << "Too many invalid attempts. No member added.\n";
    }
}

void printR4table(string id, string op) {
    cout << "\nAction for Member Number: " << id << endl;
    cout << "***** Member Account Operations Menu\n";
    cout << "[1] Edit Member Information\n";
    cout << "[2] Update Mileage Points Balance according to Flight Records\n";
    cout << "[3] Create Flight Records\n";
    cout << "[4] Redeem Mileage Points for a Gift & Transfer\n";
    cout << "[5] Return to Main Menu\n";
    cout << "**************************************\n";
    cout << "Option (1-5): " << op;
}


void doR4_1(Member& m) {
    string name, passport, tier;
    bool validPassport = false;
    bool tiertrue = false;
    string op = "1";

    cout << "\n*** [1] Edit Member Information ***\n";
    cout << "Current Member Name: " << m.getMemberName() << endl;
    cout << "Current Passport Number: " << m.getPassportNumber() << endl;
    cout << "Current Member Tier: " << m.getMemberTier() << endl;


    cout << "\nEnter new Member Name: ";
    cin.ignore();
    getline(cin, name); 

    while (!validPassport) {
        cout << "Enter new Passport Number (1 uppercase letter + 8 digits): ";
        cin >> passport;

        if (passport.length() == 9 && isupper(passport[0])) {
            validPassport = true;
            for (int i = 1; i < 9; i++) {
                if (!isdigit(passport[i])) {
                    validPassport = false;
                    break;
                }
            }
        }

        if (!validPassport) {
            cout << "Invalid format! Passport must be 1 uppercase letter followed by 8 digits.\n"; 
            Pauseline();
            system("cls");
            welcome_message();
            printR4table(m.getMemberNumber(),op);
            cout << endl;
            cout << "\n*** [1] Edit Member Information ***\n";
            cout << "Current Member Name: " << m.getMemberName() << endl;
            cout << "Current Passport Number: " << m.getPassportNumber() << endl;
            cout << "Current Member Tier: " << m.getMemberTier() << endl;
            cout << "\nEnter new Member Name: ";
            cout << name;
            cout << endl;
        }
    }

    do {
        cout << "Enter new Member Tier (Green/Silver/Gold/Diamond): ";
        cin >> tier;
        if ((tier == "Green") || (tier == "Silver") || (tier == "Gold") || (tier == "Diamond")) {
            tiertrue = true;
        }
        else
        {
            cout << "Error: Invalid input.\n";
            Pauseline();
            system("cls");
            welcome_message();
            printR4table(m.getMemberNumber(),op);
            cout << endl;
            cout << "\n*** [1] Edit Member Information ***\n";
            cout << "Current Member Name: " << m.getMemberName() << endl;
            cout << "Current Passport Number: " << m.getPassportNumber() << endl;
            cout << "Current Member Tier: " << m.getMemberTier() << endl;
            cout << "\nEnter new Member Name: ";
            cout << name;
            cout << endl;
            cout << "Enter new Passport Number (1 uppercase letter + 8 digits): " << passport << endl;
        }
    } while (!tiertrue);



    char confirm;
    do {
        cout << "\nConfirm the changes? (Y/N): "; 
        cin >> confirm;
        if (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N'.\n";
            Pauseline();
            system("cls");
            welcome_message();
            printR4table(m.getMemberNumber(), op);
            cout << endl;
            cout << "\n*** [1] Edit Member Information ***\n";
            cout << "Current Member Name: " << m.getMemberName() << endl;
            cout << "Current Passport Number: " << m.getPassportNumber() << endl;
            cout << "Current Member Tier: " << m.getMemberTier() << endl;
            cout << "\nEnter new Member Name: ";
            cout << name;
            cout << endl;
            cout << "Enter new Passport Number (1 uppercase letter + 8 digits): " << passport << endl;
            cout << "Enter new Member Tier (Green/Silver/Gold/Diamond): " << tier << endl;
        }
    } while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');

    if (confirm == 'Y' || confirm == 'y') {
        m.setMemberName(name);
        m.setPassportNumber(passport); 
        m.setMemberTier(tier); 

        int total = 0;
        int weights[] = { 7, 3, 1, 7, 3, 1, 7, 3, 1 };
        for (int i = 0; i < 9; i++) {
            int val;
            if (i == 0) val = passport[i] - 'A' + 10; 
            else val = passport[i] - '0';

            total += val * weights[i]; 
        }
        m.setMRZ(total % 10); 
        cout << "Member information updated successfully. New MRZ: " << total % 10 << endl;
    }
    else {
        cout << "Update cancelled.\n";
    }
    Pauseline();
}

void doR4_2(Member& m, vector<FlightRecord>& flights, string systemDate) {
    int totalEarned = 0;
    auto dateToInt = [](string date) {
        return stoi(date.substr(6, 4) + date.substr(3, 2) + date.substr(0, 2));
        };

    int sysDateVal = dateToInt(systemDate);
    int totalPointsEarned = 0;
    bool foundAny = false;
    cout << "Updating points for flights before " << systemDate << "...\n";

    cout << left << setw(15) << "Member" << setw(10) << "Flight" << setw(15) << "Cabin"
        << setw(15) << "Departure" << setw(10) << "Updated" << endl;
    cout << left << setw(15) << "Number" << setw(10) << "Number" << setw(15) << "Class"
        << setw(15) << "Date" << setw(10) << "-------" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    for (int i = 0; i < flights.size(); i++) {
        if (flights[i].getMemberNumber() == m.getMemberNumber() &&
            !flights[i].isUpdated() &&
            dateToInt(flights[i].getDepartureDate()) < sysDateVal) {

            foundAny = true;
            cout << left << setw(15) << flights[i].getMemberNumber()
                << setw(10) << flights[i].getFlightNumber()
                << setw(15) << flights[i].getCabinClass()
                << setw(15) << flights[i].getDepartureDate()
                << setw(10) << "0" << endl;
        }
    }

    if (!foundAny) {
        cout << "\nNo pending flight records found preceding " << systemDate << ".\n";
        Pauseline();
        return;
    }
    for (int i = 0; i < flights.size(); i++) {
        if (flights[i].getMemberNumber() == m.getMemberNumber() && !flights[i].isUpdated()) {

            int baseMiles = 0;
            if (flights[i].getOrigin() == "Hong Kong" ) {
                if (flights[i].getDestination() == "London") {
                    if (flights[i].getCabinClass() == "First") {
                        baseMiles = 16000;
                    }
                    else if (flights[i].getCabinClass() == "Business") {
                        baseMiles = 8000;

                    }
                    else {
                        baseMiles = 4000;
                    }
                }
                else if (flights[i].getDestination() == "Dubai"){
                    if (flights[i].getCabinClass() == "First") {
                        baseMiles = 8000;
                    }
                    else if (flights[i].getCabinClass() == "Business") {
                        baseMiles = 4000;

                    }
                    else {
                        baseMiles = 2000;
                    }
                }
            }
            else if (flights[i].getOrigin() == "Dubai") {
                if (flights[i].getDestination() == "London") {
                    if (flights[i].getCabinClass() == "First") {
                        baseMiles = 8000;
                    }
                    else if (flights[i].getCabinClass() == "Business") {
                        baseMiles = 4000;

                    }
                    else {
                        baseMiles = 2000;
                    }
                }
                else if (flights[i].getDestination() == "Hong Kong") {
                    if (flights[i].getCabinClass() == "First") {
                        baseMiles = 8000;
                    }
                    else if (flights[i].getCabinClass() == "Business") {
                        baseMiles = 4000;

                    }
                    else {
                        baseMiles = 2000;
                    }
                }
            }
            else if (flights[i].getOrigin() == "London") {
                if (flights[i].getDestination() == "Hong Kong") {
                    if (flights[i].getCabinClass() == "First") {
                        baseMiles = 16000;
                    }
                    else if (flights[i].getCabinClass() == "Business") {
                        baseMiles = 8000;

                    }
                    else {
                        baseMiles = 4000;
                    }
                }
                else if (flights[i].getDestination() == "Dubai") {
                    if (flights[i].getCabinClass() == "First") {
                        baseMiles = 8000;
                    }
                    else if (flights[i].getCabinClass() == "Business") {
                        baseMiles = 4000;

                    }
                    else {
                        baseMiles = 2000;
                    }
                }
            }
            double bonus = 0; 
            if (m.getMemberTier() == "Silver") bonus = 0.02;
            else if (m.getMemberTier() == "Gold") bonus = 0.04;
            else if (m.getMemberTier() == "Diamond") bonus = 0.06;

            int flightTotal = baseMiles * (1 + bonus);
            m.addRecord(flightTotal, "Flight record");
            totalEarned += flightTotal;
            flights[i].setUpdated(true);
        }
    }
        m.setMPB(m.getMPB() + totalEarned);
        cout << "Total Points Earned: " << totalEarned << "\nNew Balance: " << m.getMPB() << endl;
        
        Pauseline();
}

void doR4_3(string mNum, vector<FlightRecord>& flights, string systemDate) {
    string fNum, cabin, departDate;
    string origin = "", destination = "";
    bool validFlight = false;
    bool cabintrue = false;
    bool dmytrue = false;
    string op = "3";

    cout << "Enter Flight Number (e.g., CC81): ";
    cin >> fNum;

    if (fNum == "CC81") { origin = "Hong Kong"; destination = "London"; validFlight = true; }
    else if (fNum == "CC82") { origin = "London"; destination = "Hong Kong"; validFlight = true; }
    else if (fNum == "CC31") { origin = "Hong Kong"; destination = "Dubai"; validFlight = true; }
    else if (fNum == "CC32") { origin = "Dubai"; destination = "Hong Kong"; validFlight = true; }
    else if (fNum == "CC61") { origin = "London"; destination = "Dubai"; validFlight = true; }
    else if (fNum == "CC62") { origin = "Dubai"; destination = "London"; validFlight = true; }

    if (!validFlight) {
        cout << "Error: Invalid Flight Number. Record not created.\n";
        Pauseline();
        system("cls");
        welcome_message();
        cout << endl;
        return;
    }

    cout << "Origin: " << origin << endl;
    cout << "Destination: " << destination << endl;

    
    cout << "Enter Cabin Class (First/Business/Economy): ";
    cin >> cabin;

           
    cout << "Enter Departure Date (DD-MM-YYYY): ";
    cin >> departDate;





    if ((cabin == "First") || (cabin == "Business") || (cabin == "Economy")) {
        cabintrue = true;
    }
    if (departDate.size() == 10 && departDate[2] == '-' && departDate[5] == '-') {
        string day = departDate.substr(0, 2);
        string month = departDate.substr(3, 2);
        string year = departDate.substr(6, 4);

        int d = stoi(day);
        int m = stoi(month);
        int y = stoi(year);
        if (y == 2025 && d >= 1 && d <= 31 && m >= 1 && m <= 12) {
            dmytrue = true;
        }
    }
    if (!cabintrue||!dmytrue) {
        cout << "Error: Invalid input.\n";
        Pauseline();
        system("cls");
        welcome_message();
        return;
    }


    char confirm;
    do {
        cout << "\nConfirm adding this flight record? (Y/N): ";
        cin >> confirm;
        if (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N'.\n";
            Pauseline();
            system("cls");
            welcome_message();
            printR4table(mNum,op);
            cout << "\nEnter Flight Number (e.g., CC81): " << fNum << endl;
            cout << "Origin: " << origin << endl;
            cout << "Destination: " << destination << endl;
            cout << "Enter Cabin Class (First/Business/Economy): " << cabin << endl;
            cout << "Enter Departure Date (DD-MM-YYYY): " << departDate << endl;
        }
    } while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');

    if (confirm == 'Y' || confirm == 'y') {
        FlightRecord newFlight;
        newFlight.setMemberNumber(mNum);
        newFlight.setFlightNumber(fNum);
        newFlight.setOrigin(origin);
        newFlight.setDestination(destination);
        newFlight.setCabinClass(cabin);
        newFlight.setDepartureDate(departDate);
        newFlight.setCreationDate(systemDate);
        newFlight.setUpdated(false);

        flights.push_back(newFlight);
        cout << "\nFlight entry added successfully.\n";

        
    }
    else {
        cout << "\nUpdate cancelled.\n";
    }
    Pauseline();
}

void doR4_4(Member& source, vector<Member>& allMembers, string systemDate) {
    int subOp;
    cout << "[1] Redeem Gift\n[2] Transfer Points\nOption: ";
    cin >> subOp;
    int cost;
    if (subOp == 1) { 
        string giftNum, giftName;
        bool giftNumtrue = false;
        do {
            cout << "Select Gift (1: Movie - 3000, 2: $100 Voucher - 4000, 3: Lounge - 6000): ";
            cin >> giftNum;
            if (giftNum == "1") {
                cost = 3000;
                giftNumtrue = true;
            }
            else if (giftNum == "2") {
                cost = 4000;
                giftNumtrue = true;
            }
            else if (giftNum == "3") {
                cost = 6000;
                giftNumtrue = true;
            }
            else {
                cout << "Error: Insufficient input.\n";
                
            }
        } while (!giftNumtrue);

        if (source.getMPB() >= cost) {
            source.setMPB(source.getMPB() - cost); 
            source.addRecord(-cost, "Gift# " + giftNum);
            cout << "Redemption successful!\n";
        }
        else {
            cout << "Error: Insufficient balance.\n"; 
        }
    }
    else if (subOp == 2) { 
        string targetID;
        int amount;
        cout << "Enter target Member Number: "; cin >> targetID;
        cout << "Enter amount: "; cin >> amount;

        for (auto& target : allMembers) {
            if (target.getMemberNumber() == targetID && amount > 0 && source.getMPB() >= amount) {
                source.setMPB(source.getMPB() - amount); 
                target.setMPB(target.getMPB() + amount);
                source.addRecord(-amount, "Transfer to " + targetID);
                target.addRecord(amount, "Received from " + source.getMemberNumber());
                cout << "Transfer to " << target.getMemberName() << " successful!\n";
                return;
            }
        }
        cout << "Transfer failed (Invalid ID or insufficient points).\n";
    }
}

void memberAccountOperations(vector<Member>& members, vector<FlightRecord>& flights, string& systemDate) {
    string searchID;
    string id;
    cout << "Enter Member Number: ";
    cin >> searchID;

    int memberIdx = -1;
    for (int i = 0; i < members.size(); i++) {
        if (members[i].getMemberNumber() == searchID) {
            memberIdx = i;
            break;
        }
    }

    if (memberIdx == -1) {
        cout << "Error: Member Number does not exist.\n";
        Pauseline();
        return;
    }
    id = members[memberIdx].getMemberNumber();
    system("cls");
    welcome_message();
    string op;
    do {
        system("cls");
        welcome_message();
        printR4table(id,"");
        cin >> op;

        if (op == "1") doR4_1(members[memberIdx]);
        else if (op == "2") doR4_2(members[memberIdx], flights, systemDate);
        else if (op == "3") doR4_3(members[memberIdx].getMemberNumber(), flights, systemDate);
        else if (op == "4") doR4_4(members[memberIdx], members, systemDate);

    } while (op != "5");
}

void gen(vector<Member>& members, vector<FlightRecord>& flights, string systemDate) {
    string input;                                                                //get input of mem num
    int index = -1;               
    int i = 0;//to find where is the required record
    cout << "Input a member number : ";
    cin >> input;
    for (int i = 0; i < members.size(); i++)                                     //loop to check until find that requied mem num
        if (input == members[i].getMemberNumber()) {
            index = i;
            break;
        }
    if (index == -1) {                                                           //error message for not found
        cout << "Such member number is not exist!" << endl;
        return;
    }
    Member m = members[index];                                                   //make new object m and store the mem num record in it
    cout << left;
    cout << "Member Name: " <<  m.getMemberName() << endl;
    cout << "Member Number: " <<  m.getMemberNumber() << endl;
    cout << "Statement Date: " << systemDate << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Transaction Summary:" << endl;
    cout << setw(18) << "Type" << setw(15) << "Mileage" << "Description" << endl;
    for (int i = 0; i < m.getRecordCount(); i++) {
        string type = (m.getAmount(i) < 0) ? "Redemption" : "Earned"; // Identify type by value
        cout << left<< setw(18) << type<< setw(15) << m.getAmount(i)<< m.getDescriptions(i) << endl;
    }                                                                    
    cout << "----------------------------------------------------------------" << endl;
    cout << "Upcoming Itinerary:" << endl;
    cout << setw(12) << "Origin" << setw(18) << "Destination" << setw(12) << "Flight" << setw(12) << "Cabin" << setw(10) << "Departure" << endl;
    cout << setw(30) << ""       << setw(12) << "Number" << setw(12) << "Class" << "Date" << endl;
    cout << "----------------------------------------------------------------" << endl;
    for (int i = 0; i < flights.size(); i++) {                                   //loop to look all flight record and show if it has same mem num as input
        if (input == flights[i].getMemberNumber()) {
            cout << setw(12) << flights[i].getOrigin() << setw(18) << flights[i].getDestination() << setw(12) << flights[i].getFlightNumber() << setw(12) << flights[i].getCabinClass() << setw(10) << flights[i].getDepartureDate() << endl;
            
        }
    }
    cout << "Member Account Summary:" << endl;
    cout << setw(48) << "Total Mileage Points Balance" << ": " << m.getMPB() << endl;
    cout << setw(48) << "Member Tier" << ": " << m.getMemberTier() << endl;
    cout << setw(48) << "Bonus Mileage Points" << ": ";
    string bouns = m.getMemberTier();
    if (bouns == "Green")
        cout << "0%";
    else if (bouns == "Silver")
        cout << "2%";
    else if (bouns == "Gold")
        cout << "4%";
    else if (bouns == "Diamond")
        cout << "6%";
    cout << endl;
    Pauseline();
}



int exit_message() {
    char confirm;
    string op = "6";
    do {
        cout << "\nAre you sure you want to quit (Y/N) : ";
        cin >> confirm;
        if (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N'.\n";
            Pauseline();
            system("cls");
            welcome_message();
            printMainMenu(op);
            cout << endl;
        }
    } while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');
    if (confirm == 'Y' || confirm == 'y') {
        cout << left;
        cout << "*************************************************************************" << endl;
        cout << setw(5) << " " << setw(19) << "Student ID" << setw(30) << "Name" << setw(19) << "Tutorial Group" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << setw(5) << " " << setw(19) << "25196230A" << setw(30) << "Chow Tsz Hin" << setw(19) << "B02C" << endl;
        cout << setw(5) << " " << setw(19) << "25108664A" << setw(30) << "Lam Chun Hei David" << setw(19) << "B02C" << endl;
        cout << setw(5) << " " << setw(19) << "25131157A" << setw(30) << "Leung Ka Yan" << setw(19) << "B02A" << endl;
        cout << setw(5) << " " << setw(19) << "25093449A" << setw(30) << "Lui Yik To" << setw(19) << "B02C" << endl;
        cout << setw(5) << " " << setw(19) << "25106498A" << setw(30) << "Zhang Hung Shing" << setw(19) << "B02C" << endl;
        cout << "*************************************************************************" << endl;
        cout << setw(16) << " " << setw(57) << "Thank You For Using The System! Bye Bye!" << endl;
        cout << "*************************************************************************" << endl;
        cout << right;
        return 6;//to left loop
    }
    else {
        cout << right;
        Pauseline();
        return 0;//to go back main meun
    }
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



    int option;
    do {
        system("cls");
        welcome_message();
        printMainMenu("");
        cin >> option;

        switch (option) {
        case 1:
            members = loadMembers();
            flights = loadFlights();
            systemDate = setSystemDate();
            dataLoaded = true;
            break;
        case 2:
            if (!dataLoaded) {
                cout << "Error: Load starting data first!\n";
                Pauseline();
            }
            else {
                showAllMemberAccounts(members, flights);
            }
            break;
        case 3:
            if (!dataLoaded) {
                cout << "Error: Load starting data first!\n";
                Pauseline();
            }
            else {
                openOrCloseMemberAccount(members, flights);
            }
            break;
        case 4:
            if (!dataLoaded) {
                cout << "Error: Load starting data first!\n";
                Pauseline();
            }
            else {
                memberAccountOperations(members, flights, systemDate);
            }
            break;
        case 5:
            if (!dataLoaded) {
                cout << "Error: Load starting data first!\n";
                Pauseline();
            }
            else {
                gen(members, flights, systemDate);
            }
            break;
        case 6:
            option = exit_message();
            break;
        default:
            cout << "\nInvalid option. Please enter 1-6.\n\n";
            Pauseline();
        }

    } while (option != 6);

    return 0;
}
