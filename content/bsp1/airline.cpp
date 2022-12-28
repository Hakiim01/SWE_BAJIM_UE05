//
// Created by Hakim Bajim on 28.12.22.
//

#include "airline.h"

namespace airline {
    //person_t
    person_t::person_t(const std::string &firstname, const std::string &name, const char gender, const size_t age,
                       const std::string &address, const size_t creditcard) {
        set_name(name);
        set_firstname(firstname);
        set_address(address);
        set_age(age);
        set_creditcard(creditcard);
        set_gender(gender);
    }

    person_t::person_t(const person_t &person) {
        set_name(person._name);
        set_firstname(person._firstname);
        set_address(person._address);
        set_age(person._age);
        set_creditcard(person._creditcard);
        set_gender(person._gender);
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

    inline std::ostream &operator<<(std::ostream &lhs, const person_t &rhs) {
        lhs << rhs.get_firstname() << " " << rhs.get_name() << " (" << rhs.get_age() << rhs.get_gender() << ") "
        << rhs.get_address() << " " << rhs.get_creditcard();
        return lhs;
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

    inline std::ostream &operator<<(std::ostream &lhs, const airline_t &rhs) {
        lhs << "Flight<" << rhs.get_start() << " -> " << rhs.get_destination() << ": ";
        std::string temp;
        for (const auto &i: rhs.get_stopovers()) {
            temp += i + ", ";
        }
        lhs << temp.substr(0, temp.size() - 1);
        return lhs;
    }
} // airline