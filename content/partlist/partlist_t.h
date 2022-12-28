//
// Created by Hakim Bajim on 28.12.22.
//

#ifndef SWE_BAJIM_UE05_PARTLIST_T_H
#define SWE_BAJIM_UE05_PARTLIST_T_H

#include <iostream>
#include <string>
#include <vector>

namespace partslists {

    class part_t {
    protected:
        std::string name;

    public:
        explicit part_t(const std::string &name);

        virtual ~part_t() = default;

        [[nodiscard]] std::string get_name() const;

        [[nodiscard]] bool equals(const part_t &part) const;
    };

    class composite_part_t : public part_t{
    protected:
        std::vector<part_t*> parts = {};

    public:
        explicit composite_part_t(const std::string &name);

        void add_part(part_t &part);

        std::vector<part_t*> get_parts();
    };

} // partslists

namespace formatter{
    class formatter_t {
    public:
        virtual void print_parts(partslists::part_t &part, std::ostream &out = std::cout) = 0;
    };

    class set_formatter : public formatter_t {
    private:
        void fill_map(partslists::part_t &part, std::ostream &out, std::map<std::string, int> &m);
    public:
        void print_parts(partslists::part_t &part, std::ostream &out = std::cout) override;
    };

    class hierarchy_formatter : public formatter_t {
    private:
        void print_parts_rec(partslists::part_t &part, std::ostream &out = std::cout, int indent = 1);
    public:
        void print_parts(partslists::part_t &part, std::ostream &out = std::cout) override;
    };
} // formatter

#endif //SWE_BAJIM_UE05_PARTLIST_T_H
