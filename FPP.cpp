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
    Member(string number, string tier, string passport, int mrz, string name, int points) {
        memberNumber = number;
        memberTier = tier;
        passportNumber = passport;
        MRZ = mrz;
        memberName = name;
        MPB = points;

    }

    string getMemberNumber() const { 
        return memberNumber; 
    }
    string getMemberTier() const { 
        return memberTier; 
    }
    string getPassportNumber() const { 
        return passportNumber; 
    }
    int getMRZ() const { 
        return MRZ; 
    }
    string getMemberName() const { 
        return memberName; 
    }
    int getMPB() const { 
        return MPB; 
    }

    void addMileagePoints(int points) {
        if (points > 0) MPB += points;
    }
};

vector<Member> loadMembers() {
    vector<Member> members = {
        {"202456734", "Gold",   "A56678990", 4, "WONG Claire",   45000},
        {"203233890", "Green",  "C78678908", 5, "MA Kathy",      10000},
        {"20067856",  "Silver", "E38578900", 1, "CHAN Peter",    53200},
        {"202211843", "Gold",   "E38900708", 7, "CHEUNG Alice",  30000}
    };

    cout << "\nStarting data loaded successfully! (" << members.size() << " members)\n";
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
    bool updated = false;     // default value in declaration

public:
    // Constructor
    FlightRecord(string memNum, string orig, string dest, string flightNum, string cabin, string depDate, string createDate){
        memberNumber = memNum;
        origin = orig;
        destination = dest;
        flightNumber = flightNum;
        cabinClass = cabin;
        departureDate = depDate;
        creationDate = createDate;
    }

    // Getters
    string getMemberNumber() const { 
        return memberNumber; 
    }
    string getOrigin() const { 
        return origin; 
    }
    string getDestination() const { 
        return destination; 
    }
    string getFlightNumber() const { 
        return flightNumber; 
    }
    string getCabinClass() const { 
        return cabinClass; 
    }
    string getDepartureDate() const { 
        return departureDate; 
    }
    string getCreationDate() const { 
        return creationDate; 
    }
};

vector<FlightRecord> loadFlights() {
    vector<FlightRecord> flights = {
        {"202211843", "Hong Kong", "London",  "CC51", "First",    "23-05-2025", "01-05-2025"},
        {"202211843", "London",    "Hong Kong","CC82", "First",    "10-06-2025", "01-05-2025"},
        {"203233890", "London",    "Dubai",   "CC61", "Economy",  "12-06-2025", "10-06-2025"},
        {"20067856",  "Hong Kong", "Dubai",   "CC31", "Business", "05-07-2025", "20-06-2025"},
        {"20067856",  "Dubai",     "London",  "CC62", "Business", "08-07-2025", "20-06-2025"},
        {"202456734", "Dubai",     "Hong Kong","CC32", "Business", "05-08-2025", "02-08-2025"}
    };

    cout << "Flight records loaded successfully! (" << flights.size() << " flights)\n";
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
            break;
        case 6:
            break;
        default:
            cout << "\nInvalid option. Please enter 1-6.\n\n";
        }

    } while (option != 6);

    return 0;
}
