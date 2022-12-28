//
// Created by Hakim Bajim on 28.12.22.
//

#include <iomanip>
#include "partlist_t.h"

namespace partslists {

    part_t::part_t(const std::string &name) {
        this->name = name;
    }

    std::string part_t::get_name() const {
        return this->name;
    }

    bool part_t::equals(const part_t &part) const {
        return this->name == part.name;
    }


    composite_part_t::composite_part_t(const std::string &name) : part_t(name) {
        this->name = name;
    }

    void composite_part_t::add_part(part_t &part) {
        this->parts.push_back(&part);
    }

    std::vector<part_t *> composite_part_t::get_parts() {
        return this->parts;
    }

} // partslists

namespace formatter {

    void hierarchy_formatter::print_parts(partslists::part_t &part, std::ostream &out) {
        print_parts_rec(part, out, 1);
    }

    void hierarchy_formatter::print_parts_rec(partslists::part_t &part, std::ostream &out, int indent) {
        auto *comp = dynamic_cast<partslists::composite_part_t *>(&part);
        out << std::setw(indent*4) << part.get_name() << "\n";
        if(comp) {
            for(auto &i : comp->get_parts()) {
                print_parts_rec(*i, out, ++indent);
                --indent;
            }
        }
    }

    void set_formatter::print_parts(partslists::part_t &part, std::ostream &out) {
        std::map<std::string, int> m;
        fill_map(part, out, m);
        out << part.get_name() << "\n\t";
        for(const auto &i : m) {
            out << i.second << " " << i.first << "\n\t";
        }
        out << "\n";
    }

    void set_formatter::fill_map(partslists::part_t &part, std::ostream &out, std::map<std::string, int> &m) {
        auto * comp = dynamic_cast<partslists::composite_part_t*>(&part);
        if(comp) {
            if(!comp->get_parts().empty()) {
                for(auto &i : comp->get_parts()) {
                    fill_map(*i, out, m);
                }
            }
        } else {
            m.count(part.get_name())? m[part.get_name()]++ : m[part.get_name()] = 1;
        }
    }

} // formatter