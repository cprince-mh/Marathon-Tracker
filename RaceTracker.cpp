#include <iostream>
#include <vector>
using namespace std;

// Making a database that allows runners to sign up for a marathon
// Keeps track of how many marathons they've run as well as their mileage and stats

struct Runner {
    string name;
    int races;
    int mileage;
};

// Function prototypes
string getName();
bool decision();
int getRaces();

int main() {
    vector<Runner> runners;
    bool addMore = true;

    cout << "Welcome to the Marathon" << endl;

    while (addMore) {
        Runner newRunner;
        newRunner.name = getName();
        newRunner.races = getRaces();
        newRunner.mileage = newRunner.races * 23;

        // Add the new runner to the list
        runners.push_back(newRunner);

        addMore = decision();
    }

    // Display the list of runners
    cout << "\nList of Runners:" << endl;
    for (const auto& runner : runners) {
        cout << "Runner: " << runner.name 
             << " , Races: " << runner.races 
             << " , Miles: " << runner.mileage << endl;
    }

    return 0;
}

string getName() {
    string userName;
    cout << "Enter your name: ";
    cin >> userName;
    return userName;
}

bool decision() {
    char decide;
    cout << "Do you want to add another runner? (Y/N): ";
    cin >> decide;

    if (decide == 'y' || decide == 'Y') {
        return true;
    }
    return false;
}

// Gathers the number of races a runner has run
int getRaces() {
    int numOfRaces;
    while (true) {
        cout << "How many races? ";
        cin >> numOfRaces;

        // Check for valid input
        if (cin.fail() || numOfRaces < 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
            cout << "Invalid input. Please enter a valid number of races." << endl;
        } else {
            return numOfRaces;
        }
    }
}
