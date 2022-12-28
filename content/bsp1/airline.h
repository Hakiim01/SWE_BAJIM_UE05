//
// Created by Hakim Bajim on 28.12.22.
//

#ifndef SWE_BAJIM_UE05_AIRLINE_H
#define SWE_BAJIM_UE05_AIRLINE_H

#include <vector>
#include <string>

namespace airline {

    class airline_t {
    private:
        std::string start = "No start";
        std::string destination = "No destination";
        std::vector<std::string> stopovers = {};

    public:
        //constructors
        airline_t() = default;

        airline_t(const airline_t &airline);

        airline_t(const std::string &start, const std::string &destination, const std::vector<std::string> &stopovers);

        ~airline_t() = default;

        //gets
        std::string get_start() const;

        std::string get_destination() const;

        std::vector<std::string> get_stopovers() const;

        //sets
        void set_start(const std::string &start);

        void set_destination(const std::string &destination);

        void set_stopovers(const std::vector<std::string> stopovers);


    };

    class flight_t : protected airline_t {


    };

    class person_t {
    private:
        std::string firstname = "No firstname";
        std::string name = "No name";
        char gender = 'N';
        size_t age = 0;
        std::string address = "No address";
        size_t creditcard = 0000000000000000;
    public:
        //constructors
        person_t() = default;

        person_t(const std::string &firstname, const std::string &name, const char gender,
                 const size_t age, const std::string &address, const size_t creditcard);

        person_t(const person_t &person);

        ~person_t() = default;

        //gets
        std::string get_firstname() const;

        std::string get_name() const;

        char get_gender() const;

        size_t get_age() const;

        std::string get_address() const;

        size_t get_creditcard() const;

        //sets
        void set_firstname(const std::string &firstname);

        void set_name(const std::string name);

        void set_gender(const char gender);

        void set_age(const size_t age);

        void set_address(const std::string address);

        void set_creditcard(const size_t creditcard);
    };

} // airline

#endif //SWE_BAJIM_UE05_AIRLINE_H
