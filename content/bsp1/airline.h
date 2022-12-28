//
// Created by Hakim Bajim on 28.12.22.
//

#ifndef SWE_BAJIM_UE05_AIRLINE_H
#define SWE_BAJIM_UE05_AIRLINE_H

#include <ostream>
#include <vector>
#include <string>

namespace airline {

    class airline_t {
    protected:
        std::string _start = "No _start";
        std::string _destination = "No _destination";
        std::vector<std::string> _stopovers = {};

        friend inline std::ostream &operator<<(std::ostream &lhs, const airline_t &rhs);

    public:
        //constructors
        airline_t() = default;

        airline_t(const airline_t &airline);

        airline_t(const std::string &start, const std::string &destination, const std::vector<std::string> &stopovers);

        ~airline_t() = default;

        //gets
        [[nodiscard]] std::string get_start() const;

        [[nodiscard]] std::string get_destination() const;

        [[nodiscard]] std::vector<std::string> get_stopovers() const;

        //sets
        void set_start(const std::string &start);

        void set_destination(const std::string &destination);

        void set_stopovers(const std::vector<std::string> &stopovers);


    };

    class flight_t : private airline_t {
    private:
        size_t _flightnumber = 0;
        std::string _company = "";
        int _takeofftime = 0000;
        int _arrivingtime = 0000;
        int _flightduration = _arrivingtime - _takeofftime;
        friend inline std::ostream &operator<<(std::ostream &lhs, const flight_t &rhs);
    public:
        //constructor
        flight_t() = default;

        [[maybe_unused]] flight_t(const size_t flightnumber, const std::string &company, const int takeofftime, const int arrivingtime, const int flightduration);

        ~flight_t() = default;

        //gets
        [[nodiscard]] size_t get_flightnumber() const;

        [[nodiscard]] std::string get_company() const;

        [[nodiscard]] int get_takeofftime() const;

        [[nodiscard]] int get_arrivingtime() const;

        [[nodiscard]] int get_flightduration() const;

        //sets
        void set_flightnumber(const size_t flightnumber);

        void set_company(const std::string &company);

        void set_takeofftime(const int takeofftime);

        void set_arrivingtime(const int arrivingtime);

        //no need to set duration, because that will be calculated

    };

    class person_t {
    private:
        std::string _firstname = "No _firstname";
        std::string _name = "No _name";
        char _gender = 'N';
        size_t _age = 0;
        std::string _address = "No _address";
        size_t _creditcard = 0000000000000000;

        friend inline std::ostream &operator<<(std::ostream &lhs, const person_t &rhs);

    public:
        //constructors
        person_t() = default;

        person_t(const std::string &firstname, const std::string &name, const char gender,
                 const size_t age, const std::string &address, const size_t creditcard);

        person_t(const person_t &person);

        ~person_t() = default;

        //gets
        [[nodiscard]] std::string get_firstname() const;

        [[nodiscard]] std::string get_name() const;

        [[nodiscard]] char get_gender() const;

        [[nodiscard]] size_t get_age() const;

        [[nodiscard]] std::string get_address() const;

        [[nodiscard]] size_t get_creditcard() const;

        //sets
        void set_firstname(const std::string &firstname);

        void set_name(const std::string &name);

        void set_gender(char gender);

        void set_age(const size_t age);

        void set_address(const std::string &address);

        void set_creditcard(const size_t creditcard);
    };


} // airline

#endif //SWE_BAJIM_UE05_AIRLINE_H
