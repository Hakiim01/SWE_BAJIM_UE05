//
// Created by Hakim Bajim on 28.12.22.
//

#include "airline.h"

namespace airline {
    //person_t
    person_t::person_t(const std::string &firstname, const std::string &name, const char gender, const size_t age,
                       const std::string &address, const size_t creditcard, const std::vector<flight_t *> &flights) {
        set_name(name);
        set_firstname(firstname);
        set_address(address);
        set_age(age);
        set_creditcard(creditcard);
        set_gender(gender);
        for(auto &i: flights) {
            add_flights(*i);
        }

    }

    person_t::person_t(const person_t &person) {
        set_name(person._name);
        set_firstname(person._firstname);
        set_address(person._address);
        set_age(person._age);
        set_creditcard(person._creditcard);
        set_gender(person._gender);
        for(auto &i: person.get_flights()) {
            add_flights(*i);
        }
    }

    std::string person_t::get_firstname() const {
        return this->_firstname;
    }

    std::string person_t::get_name() const {
        return this->_name;
    }

    char person_t::get_gender() const {
        return this->_gender;
    }

    size_t person_t::get_age() const {
        return this->_age;
    }

    std::string person_t::get_address() const {
        return this->_address;
    }

    size_t person_t::get_creditcard() const {
        return this->_creditcard;
    }

    void person_t::set_firstname(const std::string &firstname) {
        this->_firstname = firstname;
    }

    void person_t::set_name(const std::string &name) {
        this->_name = name;
    }

    void person_t::set_gender(const char gender) {
        this->_gender = gender;
    }

    void person_t::set_age(const size_t age) {
        this->_age = age;
    }

    void person_t::set_address(const std::string &address) {
        this->_address = address;
    }

    void person_t::set_creditcard(const size_t creditcard) {
        this->_creditcard = creditcard;
    }

    std::ostream &operator<<(std::ostream &lhs, const person_t &rhs) {
        lhs << rhs.get_firstname() << " " << rhs.get_name() << " (" << rhs.get_age() << rhs.get_gender() << ") "
            << rhs.get_address() << " " << rhs.get_creditcard() << " ";
        for(auto &i : rhs.get_flights()) {
            lhs << *i << " ";
        }
        return lhs;
    }

    void person_t::add_flights(flight_t &flight) {
        this->flights.push_back(&flight);
    }

    std::vector<flight_t *> person_t::get_flights() const {
        return this->flights;
    }

    //airline_t
    airline_t::airline_t(const airline_t &airline) {
        set_destination(airline._destination);
        set_start(airline._start);
        set_stopovers(airline._stopovers);
    }

    airline_t::airline_t(const std::string &start, const std::string &destination,
                         const std::vector<std::string> &stopovers) {
        set_destination(destination);
        set_start(start);
        set_stopovers(stopovers);
    }

    std::string airline_t::get_start() const {
        return this->_start;
    }

    std::string airline_t::get_destination() const {
        return this->_destination;
    }

    std::vector<std::string> airline_t::get_stopovers() const {
        return this->_stopovers;
    }

    void airline_t::set_start(const std::string &start) {
        this->_start = start;
    }

    void airline_t::set_destination(const std::string &destination) {
        this->_destination = destination;
    }

    void airline_t::set_stopovers(const std::vector<std::string> &stopovers) {
        this->_stopovers = stopovers;
    }

    std::ostream &operator<<(std::ostream &lhs, const airline_t &rhs) {
        lhs << "Flight<" << rhs.get_start() << " -> " << rhs.get_destination() << ": ";
        std::string temp;
        for (const auto &i: rhs.get_stopovers()) {
            temp += i + ", ";
        }
        lhs << temp.substr(0, temp.size() - 2) << ">";
        return lhs;
    }

    [[maybe_unused]] flight_t::flight_t(const size_t flightnumber, const std::string &start,
                                        const std::string &destination, const std::string &company,
                                        const int takeofftime, const int arrivingtime, const
                                        std::vector<std::string> stopovers) {
        set_flightnumber(flightnumber);
        set_arrivingtime(arrivingtime);
        set_company(company);
        set_takeofftime(takeofftime);
        set_start(start);
        set_destination(destination);
        set_stopovers(stopovers);
        this->_flightduration = arrivingtime - takeofftime;

    }

    size_t flight_t::get_flightnumber() const {
        return this->_flightnumber;
    }

    std::string flight_t::get_company() const {
        return this->_company;
    }

    int flight_t::get_takeofftime() const {
        return this->_takeofftime;
    }

    int flight_t::get_arrivingtime() const {
        return this->_arrivingtime;
    }

    int flight_t::get_flightduration() const {
        return this->_flightduration;
    }

    void flight_t::set_flightnumber(const size_t flightnumber) {
        this->_flightnumber = flightnumber;
    }

    void flight_t::set_company(const std::string &company) {
        this->_company = company;
    }

    void flight_t::set_takeofftime(const int takeofftime) {
        this->_takeofftime = takeofftime;
    }

    void flight_t::set_arrivingtime(const int arrivingtime) {
        this->_arrivingtime = arrivingtime;
    }

    std::ostream &operator<<(std::ostream &lhs, const flight_t &rhs) {
        lhs << "Flight: " << rhs.get_flightnumber() << " from " << rhs.get_start() << " at " << rhs.get_takeofftime()
            << " to " << rhs.get_destination() << " at " << rhs.get_arrivingtime() << " over: ";
        std::string temp;
        for (const auto &i: rhs.get_stopovers()) {
            temp += i + ", ";
        }
        lhs << temp.substr(0, temp.size() - 2);
        lhs << " Duration: " << rhs.get_flightduration() << " Flightcompany: " << rhs.get_company();
        return lhs;
    }

    flight_t::flight_t(const airline_t &airline, const size_t flightnumber, const std::string &company,
                       const int takeofftime, const int arrivingtime) {
        set_flightnumber(flightnumber);
        set_arrivingtime(arrivingtime);
        set_company(company);
        set_takeofftime(takeofftime);
        set_start(airline.get_start());
        set_destination(airline.get_destination());
        set_stopovers(airline.get_stopovers());
        this->_flightduration = arrivingtime - takeofftime;
    }


} // airline