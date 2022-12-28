//
// Created by Hakim Bajim on 28.12.22.
//

#include "../content/partlist/partlist_t.h"

void test_partlists_t_creation_of_combined_part() {
    std::cout << "\ntest_partlists_t_creation_of_combined_part: \n";
    partslists::composite_part_t chair("chair");
    partslists::part_t leg("leg");
    partslists::part_t sittingspace("sittingspace");
    chair.add_part(leg);
    chair.add_part(leg);
    chair.add_part(leg);
    chair.add_part(leg);
    chair.add_part(sittingspace);
    formatter::set_formatter s;
    s.print_parts(chair);
    formatter::hierarchy_formatter h;
    h.print_parts(chair);
}

void test_partlists_t_creation_of_part() {
    std::cout << "\ntest_partlists_t_creation_of_part: \n";
    partslists::part_t leg("leg");
    partslists::part_t sittingspace("sittingspace");
    formatter::set_formatter s;
    s.print_parts(leg);
    formatter::hierarchy_formatter h;
    h.print_parts(leg);
}

void test_partlists_t() {
    test_partlists_t_creation_of_part();
    test_partlists_t_creation_of_combined_part();
}