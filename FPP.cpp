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

    Member(){
        MRZ = 0;
        MPB = 0;
    }
    void setMemberNumber(string number){ 
        memberNumber = number; 
    }
    void setMemberTier(string tier){
        memberTier = tier;
    }
    void setPassportNumber(string passport){
        passportNumber = passport; 
    }
    void setMRZ(int mrz){
        MRZ = mrz; 
    }
    void setMemberName(string name) {
        memberName = name;
    }
    void setMPB(int mpb){ 
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

};

vector<Member> loadMembers() {
    vector<Member> members;

    Member m1;
    m1.setMemberNumber("202456734");
    m1.setMemberTier("Gold");
    m1.setPassportNumber("A56678990");
    m1.setMRZ(4);
    m1.setMemberName("WONG Claire");
    m1.setMPB(45000);
    members.push_back(m1);

    Member m2;
    m2.setMemberNumber("203233890");
    m2.setMemberTier("Green");
    m2.setPassportNumber("C78678908");
    m2.setMRZ(5);
    m2.setMemberName("MA Kathy");
    m2.setMPB(10000);
    members.push_back(m2);

    Member m3;
    m3.setMemberNumber("20067856");
    m3.setMemberTier("Silver");
    m3.setPassportNumber("E38578900");
    m3.setMRZ(1);
    m3.setMemberName("CHAN Peter");
    m3.setMPB(53200);
    members.push_back(m3);

    Member m4;
    m4.setMemberNumber("202211843");
    m4.setMemberTier("Gold");
    m4.setPassportNumber("E38900708");
    m4.setMRZ(7);
    m4.setMemberName("CHEUNG Alice");
    m4.setMPB(30000);
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

    void setMemberNumber(string number){ 
        memberNumber = number; 
    }
    void setOrigin(string orig){ 
        origin = orig;
    }
    void setDestination(string destin){ 
        destination = destin; 
    }
    void setFlightNumber(string flightNum){ 
        flightNumber = flightNum; 
    }
    void setCabinClass(string CabinC){ 
        cabinClass = CabinC; 
    }
    void setDepartureDate(string DepartD){ 
        departureDate = DepartD; 
    }
    void setCreationDate(string CreateD){ 
        creationDate = CreateD; 
    }
    void setUpdated(bool UpD){ 
        updated = UpD; 
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

void doR4_1(Member& m) {
    string name, passport, tier;
    bool validPassport = false;
    bool tiertrue = false;

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
        }
    } while (!tiertrue);



    char confirm;
    do {
        cout << "\nConfirm the changes? (Y/N): "; 
        cin >> confirm;
        if (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N'.\n";
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
            totalEarned += flightTotal;
            flights[i].setUpdated(true);
        }
    }
        m.setMPB(m.getMPB() + totalEarned);
        cout << "Total Points Earned: " << totalEarned << "\nNew Balance: " << m.getMPB() << endl;
}

void doR4_3(string mNum, vector<FlightRecord>& flights, string systemDate) {
    string fNum, cabin, departDate;
    string origin = "", destination = "";
    bool validFlight = false;
    bool cabintrue = false;

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
        return;
    }

    cout << "Origin: " << origin << endl;
    cout << "Destination: " << destination << endl;

    do {
        cout << "Enter Cabin Class (First/Business/Economy): ";
        cin >> cabin;
        if ((cabin == "First") || (cabin == "Business") || (cabin == "Economy")) {
            cabintrue = true;
        }
        else
        {
            cout << "Error: Invalid cabin.\n";
        }
    } while (!cabintrue);


    while (true) {
        cout << "Enter Departure Date (DD-MM-YYYY): ";
        cin >> departDate;

        if (departDate.size() == 10 && departDate[2] == '-' && departDate[5] == '-') {
            string day = departDate.substr(0, 2);
            string month = departDate.substr(3, 2);
            string year = departDate.substr(6, 4);

            int d = stoi(day);
            int m = stoi(month);
            int y = stoi(year);

            if (y == 2025 && d >= 1 && d <= 31 && m >= 1 && m <= 12) {
                break;
                
            }
        }

        cout << "Invalid date format or out of range, please try again.\n";

    }

    char confirm;
    do {
        cout << "Confirm adding this flight record? (Y/N): ";
        cin >> confirm;
        if (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N'.\n";
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
        cout << "\nOperation aborted.\n";
    }
}

void doR4_4(Member& source, vector<Member>& allMembers, string systemDate) {
    int subOp;
    cout << "[1] Redeem Gift\n[2] Transfer Points\nOption: ";
    cin >> subOp;
    int cost;
    if (subOp == 1) { 
        string giftNum;
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
                cout << "Transfer to " << target.getMemberName() << " successful!\n";
                return;
            }
        }
        cout << "Transfer failed (Invalid ID or insufficient points).\n";
    }
}

void memberAccountOperations(vector<Member>& members, vector<FlightRecord>& flights, string& systemDate) {
    string searchID;
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
        return;
    }

    int op;
    do {
        cout << "\nAction for Member Number: " << members[memberIdx].getMemberNumber() << endl;
        cout << "***** Member Account Operations Menu\n";
        cout << "[1] Edit Member Information\n";
        cout << "[2] Update Mileage Points Balance according to Flight Records\n";
        cout << "[3] Create Flight Records\n";
        cout << "[4] Redeem Mileage Points for a Gift & Transfer\n";
        cout << "[5] Return to Main Menu\n";
        cout << "**************************************\n";
        cout << "Option (1-5): ";
        cin >> op;

        if (op == 1) doR4_1(members[memberIdx]);
        else if (op == 2) doR4_2(members[memberIdx], flights, systemDate);
        else if (op == 3) doR4_3(members[memberIdx].getMemberNumber(), flights, systemDate);
        else if (op == 4) doR4_4(members[memberIdx], members, systemDate);

    } while (op != 5);
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
            break;
        case 3:
            break;
        case 4:
			if (!dataLoaded) {
                cout << "Error: Load starting data first!\n";
            }
            else {
                memberAccountOperations(members, flights, systemDate);
            }
            break;
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
