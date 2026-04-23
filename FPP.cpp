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
    void setMPM(int mpb){ 
        MPB = mpb;
    }
	string getMemberNumber(){ 
        return memberNumber; 
    }
    string getMemberTier(){
        return memberTier;
    }
    string getPassportNumber(){
        return passportNumber; 
    }
    int getMRZ(){
        return MRZ; 
    }
    string getMemberName() {
        return memberName;
    }
    int getMPM(){ 
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
	string getMemberNumber(){
		return memberNumber;
	}
	string getOrigin(){
		return origin;
	}
	string getDestination(){ 
        return destination; 
    }
    string getFlightNumber(){ 
        return flightNumber; 
    }
    string getCabinClass(){ 
        return cabinClass; 
    }
    string getDepartureDate(){ 
        return departureDate; 
    }
    string getCreationDate(){ 
        return creationDate; 
    }
    bool getUpdated(){ 
        return updated; 
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

void gen(vector<Member>& members, vector<FlightRecord>& flights, string systemDate) {
    string input;//get input of mem num
    int index = -1;//to find where is the required record
    cout << "Input a member number : ";
    cin >> input;
    for (int i = 0; i < members.size(); i++)  //loop to check until find that requied mem num
        if (input == members[i].getMemberNumber()) {
            index = i;
            break;
        }
    if (index == -1) { //error message for not found
        cout << "Such member number is not exist!" << endl;
        return;
    }
    Member m = members[index]; //make new object m and store the mem num record in it
    cout << left;
    cout << setw(13) << "Member Name: " << setw(51) << m.getMemberName() << endl;
    cout << setw(15) << "Member Number: " << setw(49) << m.getMemberNumber() << endl;
    cout << setw(17) << "Statement Date: " << setw(47) << systemDate << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Transaction Summary:" << endl;
    cout << setw(18) << "Type" << setw(12) << "Mileage" << setw(34) << "Description" << endl;
    cout << "Redemption -4000 Gift# 2" << endl; //don't know where to get the record yet
    cout << "----------------------------------------------------------------" << endl;
    cout << "Upcoming Itinerary:" << endl;
    cout << setw(12) << "Origin" << setw(18) << "Destination" << setw(12) << "Flight" << setw(12) << "Cabin" << setw(10) << "Departure" << endl;
    cout << setw(30) << " " << setw(12) << "Number" << setw(12) << "Class" << setw(10) << "Date" << endl;
    vector<FlightRecord> upcomingFlights;//storing matched flight record
    for (int i = 0; i < flights.size(); i++) {//loop to look all flight record and show if it has same mem num as input
        string s = flights[i].getDepartureDate();//reform the date in yyyymmdd to compare
        string sdate = systemDate.substr(6, 4) + systemDate.substr(3, 2) + systemDate.substr(0, 2);
        string date = s.substr(6, 4) + s.substr(3, 2) + s.substr(0, 2);
        if (input == flights[i].getMemberNumber() && date > sdate)
            upcomingFlights.push_back(flights[i]);
    }
    for (int i = 0; i < upcomingFlights.size() - 1; i++) {  //sorting by moving the largest to the end
        for (int j = 0; j < upcomingFlights.size() - i - 1; j++) {
            string date1 = upcomingFlights[j].getDepartureDate(); //reform into yyyymmdd to compare
            string y1 = date1.substr(6, 4) + date1.substr(3, 2) + date1.substr(0, 2);
            string date2 = upcomingFlights[j + 1].getDepartureDate();
            string y2 = date2.substr(6, 4) + date2.substr(3, 2) + date2.substr(0, 2);
            if (y1 > y2) { //swap if font one larger
                FlightRecord temp = upcomingFlights[j];
                upcomingFlights[j] = upcomingFlights[j + 1];
                upcomingFlights[j + 1] = temp;
            }
        }
        for (int i = 0; i < upcomingFlights.size(); i++)
            cout << setw(12) << upcomingFlights[i].getOrigin() << setw(18) << upcomingFlights[i].getDestination() << setw(12) << upcomingFlights[i].getFlightNumber() << setw(12) << upcomingFlights[i].getCabinClass() << setw(10) << upcomingFlights[i].getDepartureDate() << endl;
        cout << "----------------------------------------------------------------" << endl;
        cout << "Member Account Summary:" << endl;
        cout << setw(48) << "Total Mileage Points Balance" << ":" << m.getMPM() << endl;
        cout << setw(48) << "Member Tier" << ":" << m.getMemberTier() << endl;
        cout << setw(48) << "Bonus Mileage Points" << ":";
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
    }
}

int exit_message() {
    string quit;
    cout << "Are you sure you want to quit (Y/N) : ";
    cin >> quit;
    while (quit != "Y" && quit != "y" && quit != "N" && quit != "n") {//only accept YyNn
        cout << "Please enter Y or y for Yes and N or n for No!" << endl;
        cout << "Are you sure you want to quit (Y/N) : ";
        cin >> quit;
    }
    if (quit == "Y" || quit == "y") {
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
        return 0;//to go back main meun
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
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
			gen(members,flights,systemDate);
            break;
        case 6:
			option=exit_message();
            break;
        default:
            cout << "\nInvalid option. Please enter 1-6.\n\n";
        }

    } while (option != 6);

    return 0;
}
