#include <iostream>
#include "../headers/citymap.h"

int main() {
    Citymap map;
    map.addIntersection("Berceni");
    map.addIntersection("Colentina");
    map.addIntersection("Dorobanti");
    map.addIntersection("Floresti");
    map.addIntersection("Gardului");

    map.addStreet("Berceni", "Colentina");
    map.addStreet("Colentina", "Dorobanti");
    map.addStreet("Dorobanti", "Floresti");

    map.printMap();

    std::cout << map.routeExist("Berceni", "Colentina") << "\n";
    std::cout << map.routeExist("Berceni", "Floresti") << "\n";
    std::cout << map.routeExist("Berc", "Colentina") << "\n";
    std::cout << map.routeExist("Berceni", "Berceni") << "\n";

    std::cout << map.routeLength("Berceni", "Floresti") << "\n";
    std::cout << map.routeLength("Berceni", "Dorobanti") << "\n";
    std::cout << map.routeLength("Floresti", "Floresti") << "\n";
    std::cout << map.routeLength("Floresti", "Berceni") << "\n";
}