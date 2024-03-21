#include "Aeroflot.h"
#include <iomanip>

namespace NAeroflot {

    std::ostream& stringManip(std::ostream& ost) {
        ost << std::setw(15) << std::setfill('.') << std::left;
        return ost;
    }

    std::ostream& operator<<(std::ostream& out, const Aeroflot& flight) {
        out << stringManip << flight.destination
            << std::setw(15) << std::setfill(' ') << std::right << stringManip << flight.flightNumber
            << stringManip << flight.planeType;
        return out;
    }

    std::istream& operator>>(std::istream& in, Aeroflot& flight) {
        in >> flight.destination >> flight.flightNumber >> flight.planeType;
        return in;
    }

    void input(Aeroflot* flights, int n, std::istream& in) {
        for (int i = 0; i < n && in; ++i) {
            in >> flights[i];
        }
    }

    void output(const Aeroflot* flights, int n, std::ostream& out) {
        for (int i = 0; i < n; ++i) {
            out << flights[i] << std::endl;
        }
    }

    void sortByDestination(Aeroflot* flights, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (flights[j].destination > flights[j + 1].destination) {
                    Aeroflot temp = flights[j];
                    flights[j] = flights[j + 1];
                    flights[j + 1] = temp;
                }
            }
        }
    }

    void printByPlaneType(const Aeroflot* flights, int n, std::string planeType, std::ostream& out) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (flights[i].planeType == planeType) {
                out << flights[i] << std::endl;
                found = true;
            }
        }
        if (!found) {
            out << "No flights found with plane type: " << planeType << std::endl;
        }
    }

    void searchByDestinationInitials(const Aeroflot* flights, int n, std::string initials) {
        for (int i = 0; i < n; ++i) {
            if (flights[i].destination.substr(0, initials.size()) == initials) {
                std::cout << flights[i] << std::endl;
            }
        }
    }
}
