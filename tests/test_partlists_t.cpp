//
// Created by Hakim Bajim on 28.12.22.
//

#include "../content/partlist/partlist_t.h"

void test_partlists_t() {
    partslists::part_t leg("leg");
    partslists::part_t sittingspace("sittingspace");
    partslists::composite_part_t stool("stool");
    stool.add_part(leg);
    stool.add_part(leg);
    stool.add_part(leg);
    stool.add_part(leg);
    stool.add_part(sittingspace);
    formatter::set_formatter s;
    s.print_parts(stool);
}