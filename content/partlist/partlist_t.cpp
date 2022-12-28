//
// Created by Hakim Bajim on 28.12.22.
//

#include <map>
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
        out << part.get_name();
    }

    void set_formatter::print_parts(partslists::part_t &part, std::ostream &out) {
        std::map<std::string, int> m;
        fill_map(part, out, m);
        out << part.get_name() << "\n\t";
        for(auto &i : m) {
            out << i.second << " " << i.first << "\n";
        }
    }

    void set_formatter::fill_map(partslists::part_t &part, std::ostream &out, std::map<std::string, int> &m) {
        auto *comp = dynamic_cast<partslists::composite_part_t *>(&part);
        if(comp->get_parts().size() > 0) {
            for(auto &i : comp->get_parts()) {
                fill_map(*i, out, m);
            }
        } else {
            m.contains(comp->get_name()) ? ++m[comp->get_name()] : m[comp->get_name()] = 1;
        }
    }

} // formatter