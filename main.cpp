
#include <iostream>
#include <linked_list.h>
#include "doubly_linked_list.h"
#include "sorts.h"
using namespace std;
int main() {

   
    vector <unsigned> intArray = {5,3,4,1,2,7,6};
    lab6::doubly_linked_list test_list(intArray);
    sorts s1;
    lab6::doubly_linked_list t1;
    t1 = s1.radix_sort(test_list);
    t1.print();
    return 0;
}
