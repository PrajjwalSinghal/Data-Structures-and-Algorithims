#ifndef CMPE126F17_LABS_SORTS_H
#define CMPE126F17_LABS_SORTS_H

#include "doubly_linked_list.h"

class sorts{
public:
    lab6::doubly_linked_list insertion_sort(lab6::doubly_linked_list input, int iterations);
    lab6::doubly_linked_list selection_sort(lab6::doubly_linked_list input, int iterations);
    lab6::doubly_linked_list bubble_sort(lab6::doubly_linked_list input, int iterations);
    lab6::doubly_linked_list cocktail_sort(lab6::doubly_linked_list input, int iterations);

    lab6::doubly_linked_list quick_sort(lab6::doubly_linked_list input);
    lab6::doubly_linked_list merge_sort(lab6::doubly_linked_list input);
    lab6::doubly_linked_list radix_sort(lab6::doubly_linked_list input);
};

#endif //CMPE126F17_LABS_SORTS_H
