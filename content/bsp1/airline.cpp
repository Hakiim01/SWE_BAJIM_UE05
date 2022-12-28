//
// Created by Hakim Bajim on 28.12.22.
//

#include "airline.h"

namespace airline {
    person_t::person_t(const std::string &firstname, const std::string &name, const char gender, const size_t age,
                       const std::string &address, const size_t creditcard) {
        this->firstname = firstname;
        this->name = name;
        this->gender = gender;
        this->age = age;
        this->address = address;
        this->creditcard = creditcard;
    }

    person_t::person_t(const person_t &person) {
        this->firstname = person.firstname;
        this->name = person.name;
        this->age = person.age;
        this->address = person.address;
        this->creditcard = person.creditcard;
        this->gender = person.gender;
    }

    std::string person_t::get_firstname() const {
        return this->firstname;
    }

    std::string person_t::get_name() const {
        return this->name;
    }

    char person_t::get_gender() const {
        return this->gender;
    }

    size_t person_t::get_age() const {
        return this->age;
    }

    std::string person_t::get_address() const {
        return this->address;
    }

    size_t person_t::get_creditcard() const {
        return this->creditcard;
    }

    void person_t::set_firstname(const std::string &firstname) {
        this->firstname = firstname;
    }

    void person_t::set_name(const std::string name) {
        this->name = name;
    }

    void person_t::set_gender(const char gender) {
        this->gender = gender;
    }

    void person_t::set_age(const size_t age) {
        this->age = age;
    }

    void person_t::set_address(const std::string address) {
        this->address = address;
    }

    void person_t::set_creditcard(const size_t creditcard) {
        this->creditcard = creditcard;
    }


} // airline