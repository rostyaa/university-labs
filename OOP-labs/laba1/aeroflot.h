#pragma once
#ifndef _AEROFLOT_H_
#define _AEROFLOT_H_

#include <string>
#include <iostream>

namespace NAeroflot {
    struct Aeroflot {
        std::string destination;
        int flightNumber;
        std::string planeType;
    };

    std::ostream& operator<<(std::ostream& out, const Aeroflot& flight);
    std::istream& operator>>(std::istream& in, Aeroflot& flight);
    void input(Aeroflot* flights, int n, std::istream& in);
    void output(const Aeroflot* flights, int n, std::ostream& out);
    void sortByDestination(Aeroflot* flights, int n);
    void printByPlaneType(const Aeroflot* flights, int n, std::string planeType, std::ostream& out);
    void searchByDestinationInitials(const Aeroflot* flights, int n, std::string initials);
}

#endif
