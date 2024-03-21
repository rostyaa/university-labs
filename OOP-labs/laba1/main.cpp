#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Aeroflot.h"

using namespace std;
using namespace NAeroflot;

int main() {
    Aeroflot flights[] = {
        {"Kyiv", 101, "A320"},
        {"Lviv", 102, "Boeing737"},
        {"Odesa", 103, "A320"}
    };
    int n = sizeof(flights) / sizeof(flights[0]);

    sortByDestination(flights, n);

    cout << "Sorted flights by destination:" << endl;
    output(flights, n, cout);

    cout << "Enter destination to filter by: ";
    string destination;
    cin >> destination;

    ofstream fout("FilteredFlightsByDestination.txt");
    if (!fout) {
        cerr << "Failed to open file for writing." << endl;
        return 1;
    }

    bool found = false;
    string searchPattern = destination.substr(0, 2);

    for (int i = 0; i < n; ++i) {
        if (flights[i].destination.substr(0, 2) == searchPattern) {
            fout << flights[i] << endl;
            cout << flights[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No flights found to " << destination.substr(0, 2) << endl;
        fout << "No flights found to " << destination.substr(0, 2) << endl;
    }

    fout.close();

    return 0;
}
