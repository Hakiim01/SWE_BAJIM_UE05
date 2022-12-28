//
// Created by Hakim Bajim on 28.12.22.
//

#include <iostream>
#include "../content/airline/airline.h"

void test_airline_t_basic_creations() {
    std::cout << "test_airline_t_basic_creations: \n";
    airline::airline_t a("Linz", "Vienna");
    std::cout << "Creation of an airline route: " << a << "\n\n";

    airline::flight_t f(5001, "Linz", "Vienna" ,"Vienna Airline", 800, 830);
    std::cout << "Creation of a flight: " << f << "\n\n";

    airline::flight_t f1(a, 5001, "Vienna Airline", 800, 830);
    std::cout << "Creation of a flight using an airline: " << f1 << "\n\n";

    airline::person_t p("Aang", "The Last Airbender", 'm', 15, "Waternation 1", 1234123412341234, {&f, &f1});
    std::cout << "Creation of a person: " << p;
}

void test_airline_t() {
    test_airline_t_basic_creations();
}