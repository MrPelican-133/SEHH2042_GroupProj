#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <cctype>   
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


void printMainMenu(string op) {        // printing the main menu
    cout << "*** FFP Main Menu ***\n";
    cout << "[1] Load Starting Data\n";
    cout << "[2] Show All Member Accounts\n";
    cout << "[3] Open or Close Member Account\n";
    cout << "[4] Member Account Operations\n";
    cout << "[5] Generate Daily Statement\n";
    cout << "[6] Credits and Exit\n";
    cout << "*******************************\n";
    cout << "Option (1 - 6): " << op;             // op is the option that user currently chose
}

void Pauseline() {                               // function that assists the clear screen function
    cin.clear();
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Press Enter to continue...";        // to stop the program until user presses enter
    string dummy;
    getline(cin, dummy);
}

bool isValidDateFormat(const string& date) {            
    // Check basic length and structure (DD-MM-YYYY)
    if (date.length() != 10 || date[2] != '-' || date[5] != '-') return false;

    // Ensure remaining characters are digits
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit(date[i])) return false;
    }

    // Basic range check for Day and Month
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    if (month < 1 || month > 12 || day < 1 || day > 31) return false;

    return true;
}

bool checkDataLoaded(bool dataloaded) {
    if (!dataloaded) {
        cout << "Error: Load starting data first!\n";
        Pauseline();
        return false;
    }
}

int dateToInteger(string date) {
    // date[0-1] is DD, date[3-4] is MM, date[6-9] is YYYY
    int d = stoi(date.substr(0, 2));
    int m = stoi(date.substr(3, 2));
    int y = stoi(date.substr(6, 4));
    return y * 10000 + m * 100 + d;
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

    string getMemberNumber() const {  // getter
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
    int getMRZ() const {        // getter
        return MRZ; 
    }
    void setMPB(int points) { 
        MPB = points; 
    }

    void addRecord(int amount, string description) {        // add the record of doing transaction by user (earn point or redeem point)
        recordAmounts.push_back(amount);                    // record how much they user for all users
        recordDescriptions.push_back(description);          // reocrd what usage are the users use it for 
    }
    int getAmount(int i) const {                            // getter
        return recordAmounts[i];
    }   
    string getDescriptions(int i) const {                   // getter
        return recordDescriptions[i];
    }
    int getRecordCount() const {                            //length of the record
        return recordAmounts.size();
    }
};

vector<Member> loadMembers() {
    vector<Member> members;

    Member m1;
    m1.setMemberNumber("202456734");
    m1.setMemberTier("Gold");
    m1.setPassportNumber("A56677890");
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
    m3.setPassportNumber("E38876890");
    m3.setMRZ(1);
    m3.setMemberName("CHAN Peter");
    m3.setMPM(53200);
    members.push_back(m3);

    Member m4;
    m4.setMemberNumber("202211843");
    m4.setMemberTier("Gold");
    m4.setPassportNumber("E38900078");
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
    string getCreationDate() const {
        return creationDate;
    }
    
};

vector<FlightRecord> loadFlights() {
    vector<FlightRecord> flights;

    FlightRecord f1;
    f1.setMemberNumber("202211843");
    f1.setOrigin("Hong Kong");
    f1.setDestination("London");
    f1.setFlightNumber("CC81");
    f1.setCabinClass("First");
    f1.setDepartureDate("28-05-2025");
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
//===========================================R1===================================================//
string setSystemDate() {                        // set the system date 
    string date;
    int invalidCount = 0;
    string op = "1";

    cout << "\nSystem Date Setting...\n";
    Pauseline();
    system("cls");
    welcome_message();
    printMainMenu(op);
    while (true) {
        cout << "\n\n*** Set System Date for updating Mileage Points ***\n";
        cout << "Please enter system date (DD-MM-YYYY): ";
        cin >> date;

        if (isValidDateFormat(date)) {
            int year = stoi(date.substr(6, 4));
            if (year <= 2025) {                         // check to ensure the year of system date shouldn't be larger than 2025
                cout << "System date set successfully: " << date << "\n";
                Pauseline();
                return date;
            }
        }
        invalidCount++;
        cout << "Invalid date format or out of range, please try again.\n";   
        Pauseline();
        system("cls");                                      // clear the screen at ever transition to make sure the console is clear enough to read
        welcome_message();                                  // print the welcome message and Main menu again to keep the consistency
        printMainMenu(op);                                          
        if (invalidCount >= 3) {                            // get default date while user enter wrong in system date more than three times
            cout << "\n\nToo many invalid attempts. Default date set to 30-06-2025.\n";
            Pauseline();
            return "30-06-2025";
        }
    }
}
//===========================================R2===================================================//
void showAllMemberAccounts(const vector<Member>& members, const vector<FlightRecord>& flights) {
    cout << "\n=== Member Account Records ===\n";
    cout << left
        << setw(13) << "Member No"
        << setw(10) << "Tier"
        << setw(15) << "Passport"
        << setw(6) << "MRZ"
        << setw(35) << "Member Name"
        << setw(10) << "Points" << endl;
    cout << string(85, '-') << endl;

    // Sort Member: Asscending by Member Name
    vector<Member> sortedMembers = members;
    sort(sortedMembers.begin(), sortedMembers.end(),
        [](const Member& a, const Member& b) {
            return a.getMemberName() < b.getMemberName(); // '<' for A to Z
        });

    for (int i = 0; i < sortedMembers.size(); i++) {
        cout << left
            << setw(13) << sortedMembers[i].getMemberNumber()
            << setw(10) << sortedMembers[i].getMemberTier()
            << setw(15) << sortedMembers[i].getPassportNumber()
            << setw(6) << sortedMembers[i].getMRZ()
            << setw(35) << sortedMembers[i].getMemberName()
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
        << setw(15) << "Creation Date"
        << setw(8) << "Updated" << endl;
    cout << string(95, '-') << endl;

    // Sort Flights: Descending by Departure Date
    vector<FlightRecord> pending = flights;
    sort(pending.begin(), pending.end(),
        [](const FlightRecord& a, const FlightRecord& b) {
            // '>' ensures the largest numeric date (latest) comes first
            return dateToInteger(a.getDepartureDate()) > dateToInteger(b.getDepartureDate());
        });

    bool hasRecord = false;
    for (int i = 0; i < pending.size(); i++) {
        // Only show flights where Updated status is false (0)
        if (!pending[i].isUpdated()) {
            cout << left
                << setw(13) << pending[i].getMemberNumber()
                << setw(12) << pending[i].getOrigin()
                << setw(12) << pending[i].getDestination()
                << setw(10) << pending[i].getFlightNumber()
                << setw(12) << pending[i].getCabinClass()
                << setw(15) << pending[i].getDepartureDate()
                << setw(15) << pending[i].getCreationDate()
                << setw(10) << "0" << endl;
            hasRecord = true;
        }
    }
    if (!hasRecord) {
        cout << "No pending flight records.\n";
        
    }
    cout << endl;
    Pauseline();
}

//===========================================R3===================================================//
void openOrCloseMemberAccount(vector<Member>& members, vector<FlightRecord>& flights, string systemDate) {

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
        cout << "\nMember found: " << endl;
        cout << left << setw(13) << "Member No"<< setw(10) << "Tier"<< setw(15) << "Passport"<< setw(6) << "MRZ"<< setw(35) << "Member Name"<< setw(10) << "Points" << endl;
        cout << string(85, '-') << endl;
        cout << left<< setw(13) << members[index].getMemberNumber()<< setw(10) << members[index].getMemberTier()<< setw(15) << members[index].getPassportNumber()<< setw(6) << members[index].getMRZ()<< setw(35) << members[index].getMemberName()<< setw(10) << members[index].getMPB() << endl << endl;
        char confirm;
        do {
            cout << "\nConfirm to CLOSE this account? (Y/N): ";                                                 // both 'Y' and 'y' are accepted to represent 'Yes'
            cin >> confirm;
            if (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n') {                         // only 'N' and 'n' are outputing cancelling for the action 
                cout << "Invalid input. Please enter 'Y' or 'N'.\n";                                            // other characters are not accepted and require the user to enter again
                Pauseline();
                system("cls");
                welcome_message();
                printMainMenu(op);
                cout << "\n\nEnter Member Number: " << memNo << endl;
                cout << "\nMember found: " << endl;
                cout << left << setw(13) << "Member No" << setw(10) << "Tier" << setw(15) << "Passport" << setw(6) << "MRZ" << setw(35) << "Member Name" << setw(10) << "Points" << endl;
                cout << string(85, '-') << endl;
                cout << left << setw(13) << members[index].getMemberNumber() << setw(10) << members[index].getMemberTier() << setw(15) << members[index].getPassportNumber() << setw(6) << members[index].getMRZ() << setw(35) << members[index].getMemberName() << setw(10) << members[index].getMPB() << endl << endl;
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
        cout << "\nMember not found. Opening new account...\n";                                         // jumping to the next page for creating new account
        Pauseline();
        cin.clear();
        system("cls");
        welcome_message();
        printMainMenu(op);
        cout << endl;
        Member newM;
        string name, passport, tier;
        int retry = 0;
        bool validPassport = false;
        bool nameofr = false;

        while (retry < 3) {
            bool isNotValidName = false;
            cout << "\nEnter new Member Name (Surname GivenName)(max 30 chars): ";

            if (cin.peek() == '\n') {
                cin.ignore();
            }
            // Read the full name including spaces
            getline(cin, name);
            //Optional: Validate length (Requirement: at most 30 characters)
            // Check every character in the string
            for (char c : name) {
                // If it's not a letter AND not a space, it's "not a standard name string"
                if (!isalpha(c) && !isspace(c)) {
                    isNotValidName = true;
                    break;
                }
            }
            // Locate the first space to identify the surname
            size_t firstSpace = name.find(' ');
            if (firstSpace == string::npos) {
                // Error: No space found (only one name entered)
                isNotValidName = true;
            }
            else if (firstSpace == 0 || firstSpace == name.length() - 1) {
                // Error: Space is at the very start or very end
                isNotValidName = true;
            }
            if (!isNotValidName) {
                if (name.length() > 30) {
                    name = name.substr(0, 30); // Truncate to 30 characters
                    cout << "System Notice: Name truncated to 30 characters.\n";
                }

                // 3. Format the surname to ALL CAPS
                // If no space is found, the entire string is treated as the surname
                size_t endOfSurname = (firstSpace == string::npos) ? name.length() : firstSpace;

                for (size_t i = 0; i < endOfSurname; i++) {
                    name[i] = toupper(name[i]);
                }
                if (firstSpace != string::npos) {
                    for (size_t j = firstSpace + 1; j < name.length(); j++) {
                        name[j] = tolower(name[j]);
                    }
                }
            }
  
            cout << "Enter Passport Number: ";
            cin >> passport;
            cout << "Enter Tier (Green/Silver/Gold/Diamond): ";
            cin >> tier;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (passport.length() == 9 && isupper(passport[0])) {
                validPassport = true;
                for (int i = 1; i < 9; i++) {
                    if (!isdigit(passport[i])) {
                        validPassport = false;
                        break;
                    }
                }
            }

            if ((!isNotValidName)&&(validPassport)&&((tier == "Green") || (tier == "Silver") || (tier == "Gold") || (tier == "Diamond"))) {
                string yearPrefix = systemDate.substr(6, 4);
                // Generate 5 random digits
                string randomSuffix = to_string(rand() % 90000 + 10000);
                //Combine them to form the unique Member Number
                string generatedMemNo = yearPrefix + randomSuffix;
                newM.setMemberNumber(generatedMemNo);
                newM.setMemberName(name);
                newM.setPassportNumber(passport);
                int total = 0;
                int weights[] = { 7, 3, 1, 7, 3, 1, 7, 3, 1 };                      // calculate the MRZ when new passport number is inserted
                for (int i = 0; i < 9; i++) {
                    int val;
                    if (i == 0) val = passport[i] - 'A' + 10;
                    else val = passport[i] - '0';

                    total += val * weights[i];
                }
                newM.setMRZ(total % 10);
                newM.setMemberTier(tier);
                newM.setMPM(0);

                members.push_back(newM);
                cout << "New member created successfully! Member Number: " << newM.getMemberNumber() << endl;
                Pauseline();
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
        cout << "\nToo many invalid attempts. No member added.\n";
        Pauseline();    
        cin.clear();
    }
}
//===========================================R4 table==============================================//
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

//===========================================R4.1=================================================//
void doR4_1(Member& m) {
    string name, passport, tier;
    bool validPassport = false;
    bool tiertrue = false;
    bool isNotValidName;
    string op = "1";

    cout << "\n*** [1] Edit Member Information ***\n";
    cout << "Current Member Name: " << m.getMemberName() << endl;
    cout << "Current Passport Number: " << m.getPassportNumber() << endl;
    cout << "Current Member Tier: " << m.getMemberTier() << endl;

    do {
        isNotValidName = false;
        cout << "\nEnter new Member Name (Surname GivenName)(max 30 chars): ";
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        getline(cin, name);
        for (char c : name) {
            if (!isalpha(c) && !isspace(c)) {
                isNotValidName = true;
                break;
            }
        }
        size_t firstSpace = name.find(' ');
        if (firstSpace == string::npos) {
            isNotValidName = true;
        }
        else if (firstSpace == 0 || firstSpace == name.length() - 1) {
            isNotValidName = true;
        }
        if (isNotValidName == true) {
            cout << "Invalid format! Name must be string with Surename and Givenname.\n";
            Pauseline();
            system("cls");
            welcome_message();
            printR4table(m.getMemberNumber(), op);
            cout << endl;
            cout << "\n*** [1] Edit Member Information ***\n";
            cout << "Current Member Name: " << m.getMemberName() << endl;
            cout << "Current Passport Number: " << m.getPassportNumber() << endl;
            cout << "Current Member Tier: " << m.getMemberTier() << endl;
        }
    } while (isNotValidName);
    size_t firstSpace = name.find(' ');
    if (name.length() > 30) {
        name = name.substr(0, 30); 
        cout << "System Notice: Name truncated to 30 characters.\n";
    }

    size_t endOfSurname = (firstSpace == string::npos) ? name.length() : firstSpace;

    for (size_t i = 0; i < endOfSurname; i++) {
        name[i] = toupper(name[i]);
    }
    if (firstSpace != string::npos) {
        for (size_t j = firstSpace + 1; j < name.length(); j++) {
            name[j] = tolower(name[j]);
        }
    }
    


    while (!validPassport) {
        cout << "Enter new Passport Number (1 uppercase letter + 8 digits): ";
        cin >> passport;

        if (passport.length() == 9 && isupper(passport[0])) {       // make sure passport number must be (A-Z)+8*(0-9) format
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
            cout << "\nEnter new Member Name (Surname GivenName)(max 30 chars): ";
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
            cout << "Error: Invalid input.\n";                              // make sure users enter the correct one
            Pauseline();
            system("cls");
            welcome_message();
            printR4table(m.getMemberNumber(),op);
            cout << endl;
            cout << "\n*** [1] Edit Member Information ***\n";
            cout << "Current Member Name: " << m.getMemberName() << endl;
            cout << "Current Passport Number: " << m.getPassportNumber() << endl;
            cout << "Current Member Tier: " << m.getMemberTier() << endl;
            cout << "\nEnter new Member Name (Surname GivenName)(max 30 chars): ";
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
            cout << "\nEnter new Member Name (Surname GivenName)(max 30 chars): ";
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
            if (i == 0) val = passport[i] - 'A' + 10;                       // calculate the MRZ when new passport number is inserted
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
//===========================================R4.2=================================================//
void doR4_2(Member& m, vector<FlightRecord>& flights, string systemDate) {
    int totalEarned = 0;
    auto dateToInt = [](string date) {
        return stoi(date.substr(6, 4) + date.substr(3, 2) + date.substr(0, 2));
        };

    int sysDateVal = dateToInt(systemDate);
    int totalPointsEarned = 0;
    bool foundAny = false;
    cout << "Updating points for flights before " << systemDate << "...\n";                 //only print the un updated record

    cout << left << setw(15) << "Member" << setw(10) << "Flight" << setw(15) << "Cabin"
        << setw(15) << "Departure" << setw(10) << "Updated" << endl;
    cout << left << setw(15) << "Number" << setw(10) << "Number" << setw(15) << "Class"
        << setw(15) << "Date" << setw(10) << "-------" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    for (int i = 0; i < flights.size(); i++) {
        if (!flights[i].isUpdated() && dateToInt(flights[i].getDepartureDate()) < sysDateVal) {

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
    for (int i = 0; i < flights.size(); i++) {                                              // check the origin and destination to calculate the point
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
            m.addRecord(flightTotal, "Flight record");                          // call addRecord function to save the record whenever the point is changing (earn/redeem)
            totalEarned += flightTotal;
            flights[i].setUpdated(true);
        }
    }
        m.setMPB(m.getMPB() + totalEarned);
        cout << "Total Points Earned: " << totalEarned << "\nNew Balance: " << m.getMPB() << endl;
        
        Pauseline();
}

//===========================================R4.3=================================================//
void doR4_3(string mNum, vector<FlightRecord>& flights, string systemDate) {
    string fNum, cabin, departDate;
    string origin = "", destination = "";
    bool validFlight = false;
    bool cabintrue = false;
    bool dmytrue = false;
    string op = "3";
    auto dateToVal = [](string d) {                                         //small function that split the Date from (DD-MM-YYYY) to (YYYYMMDD) for better comparison
        return stoi(d.substr(6, 4) + d.substr(3, 2) + d.substr(0, 2));
        };


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

    do {
        cout << "Enter Cabin Class (First/Business/Economy): ";
        cin >> cabin;

        if ((cabin == "First") || (cabin == "Business") || (cabin == "Economy")) {
            cabintrue = true;
        }
        else
        {
            cout << "Error: Invalid input.\n";
            Pauseline();
            system("cls");
            welcome_message();
            printR4table(mNum, op);
            cout << "\nEnter Flight Number (e.g., CC81): " << fNum << endl;
            cout << "Origin: " << origin << endl;
            cout << "Destination: " << destination << endl;
        }
    } while (!cabintrue);
           
    do
    {
        cout << "Enter Departure Date (DD-MM-YYYY): ";
        cin >> departDate;

        if (!isValidDateFormat(departDate)) {                                               // check if the Date entered is in correct format or not 
            cout << "Error: Incorrect format. Use DD-MM-YYYY.\n";                           // e.g. both (11-22-3333) and (aa-aa-aaaa) is not accepted
            
        }
        else
        {
            if (dateToVal(departDate) > dateToVal(systemDate)) {                            // check if the new created date is after the System date
                break;
            }
            else {
                cout << "Error: Departure date must be after system date (" << systemDate << ").\n";
            }
        }
        Pauseline();
        system("cls");
        welcome_message();
        printR4table(mNum, op);
        cout << "\nEnter Flight Number (e.g., CC81): " << fNum << endl;
        cout << "Origin: " << origin << endl;
        cout << "Destination: " << destination << endl;
        cout << "Enter Cabin Class (First/Business/Economy): " << cabin << endl;
        
    } while (!dmytrue);



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
//===========================================R4.4=================================================//
void doR4_4(Member& source, vector<Member>& allMembers, string systemDate) {
    if (source.getMPB() == 0) {
        cout << "Error: Member account does not have any mileage points.\n"; //
        Pauseline();
        return;
    }
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
        int targetIndex = -1;
        string targetID;
        int amount;
        string op = "4";

        cout << "Enter target Member Number: ";
        cin >> targetID;

        // Requirement: Check if the target member account exists in the system

        for (int i = 0; i < allMembers.size(); i++) {
            if (allMembers[i].getMemberNumber() == targetID) {
                // Self-transfer check (to avoid logic errors)
                if (allMembers[i].getMemberNumber() == source.getMemberNumber()) {
                    cout << "Error: You cannot transfer points to your own account.\n";
                    cout << "Operation absorted.\n"; //aborts the operation.
                    Pauseline();
                    return;
                }
                targetIndex = i;
                break;
            }
        }

        if (targetIndex == -1 && targetID != source.getMemberNumber()) {
            cout << "Error: Target member account does not exist.\n"; //
            cout << "Operation absorted.\n"; //aborts the operation.
            Pauseline();
            return;
        }

        cout << "Enter amount of mileage points to transfer: ";
        cin >> amount;

        // Requirement: Transfer mileage point must be positive and not exceed source balance
        if (amount <= 0) {
            cout << "Error: Transfer amount must be positive.\n"; //
            cout << "Operation absorted.\n"; //aborts the operation.
            Pauseline();
            return;
                
        }else if (amount > source.getMPB()) {
            cout << "Error: Insufficient balance (Current balance: " << source.getMPB() << ").\n"; //
            cout << "Operation absorted.\n"; //aborts the operation.
            Pauseline();
            return;
        }

        do {
            // Requirement: Show target member's name and ask for confirmation
            char confirm;
            cout << "\nTarget Member: " << allMembers[targetIndex].getMemberName() << endl;
            cout << "Transfer Amount: " << amount << " points" << endl;
            cout << "Confirm transfer? (Y/N): ";
            cin >> confirm;

            if (confirm == 'Y' || confirm == 'y') {
                // Requirement: Execute transfer by deducting from source and adding to target
                source.setMPB(source.getMPB() - amount);
                allMembers[targetIndex].setMPB(allMembers[targetIndex].getMPB() + amount);

                // Record transactions for both parties
                source.addRecord(-amount, "Transfer to " + targetID);
                allMembers[targetIndex].addRecord(amount, "Received from " + source.getMemberNumber());

                // Requirement: Show the changes
                cout << "\n--- Transfer Successful ---\n";
                cout << "New Balance: " << source.getMPB() << " points\n";
                Pauseline();
                break;
            }
            else if (confirm == 'N' || confirm == 'n') {
                cout << "Transfer operation aborted.\n"; //
                Pauseline();
                break;
            }
            else {
                cout << "Invalid input. Please enter 'Y' or 'N'.\n";
                Pauseline();
                system("cls");
                welcome_message();
                printR4table(source.getMemberNumber(), op);
                cout << "\n[1] Redeem Gift\n[2] Transfer Points\nOption: " << subOp;
                cout << endl;
                cout << "Enter target Member Number: " << targetID << endl;
                cout << "Enter amount of mileage points to transfer: " << amount << endl;
            }
        } while (true);
    }
}

//===========================================R4===================================================//
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
//===========================================R5===================================================//
void gen(vector<Member>& members, vector<FlightRecord>& flights, string systemDate) {
    string input;                                                                //get input of mem num
    int index = -1;               
    int i = 0;                                                          //to find where is the required record
    cout << "Input a member number : ";
    cin >> input;
    for (int i = 0; i < members.size(); i++){                                     //loop to check until find that requied mem num
        if (input == members[i].getMemberNumber()) {
            index = i;
            break;
        }
    }
    if (index == -1) {                                                           //error message for not found
        cout << "Such member number is not exist!" << endl;
        Pauseline();
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
    

    vector<FlightRecord> memberFlights;
    for (int i = 0; i < flights.size(); i++) {
        // Collect only the flights belonging to this member
        if (input == flights[i].getMemberNumber()) {
            memberFlights.push_back(flights[i]);
        }
    }
    sort(memberFlights.begin(), memberFlights.end(), [](const FlightRecord& a, const FlightRecord& b) {
        return dateToInteger(a.getDepartureDate()) < dateToInteger(b.getDepartureDate());
        });
    for (int i = 0; i < memberFlights.size(); i++) {                                    //loop to look all flight record and show if it has same mem num as input
        cout << left << setw(12) << memberFlights[i].getOrigin()
            << setw(18) << memberFlights[i].getDestination()
            << setw(12) << memberFlights[i].getFlightNumber()
            << setw(12) << memberFlights[i].getCabinClass()
            << setw(10) << memberFlights[i].getDepartureDate()  << endl;
    }
    cout << "----------------------------------------------------------------" << endl;
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


//===========================================R6===================================================//
int exit_message(bool &run) {
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
        run = false;
        Pauseline();
        return run;//to left loop
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



    string option;
    bool run = true;
    do {
        system("cls");
        welcome_message();
        printMainMenu("");
        cin >> option;

        if (option == "1") {                                // use if function with string instead of switch function with integer to prevent users enter a string or character to cause the bug
            members = loadMembers();
            flights = loadFlights();
            systemDate = setSystemDate();
            dataLoaded = true;
        }
        else if (option == "2") {
            if (checkDataLoaded(dataLoaded)) {
                showAllMemberAccounts(members, flights);
            }
        }
        else if (option == "3") {
            if (checkDataLoaded(dataLoaded)) {
                openOrCloseMemberAccount(members, flights, systemDate);
            }
        }
        else if (option == "4") {
            if (checkDataLoaded(dataLoaded)) {
                memberAccountOperations(members, flights, systemDate);
            }
        }
        else if (option == "5") {
            if (checkDataLoaded(dataLoaded)) {
                gen(members, flights, systemDate);
            }
        }
        else if (option == "6") {
            option = exit_message(run);
        }
        else {
            cout << "\nInvalid option. Please enter 1-6.\n\n";
            Pauseline();
        }

    } while (run);

    return 0;
}
