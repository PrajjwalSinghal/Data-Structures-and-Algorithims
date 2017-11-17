
#include <iostream>

#include "doubly_linked_list.h"
using namespace std;
int main() {

    vector <unsigned> values(5);
    values[0] = 4;
    values[1] = 4;
    values[2] = 6;
    values[3] = 6;
    values[4] = 6;
    lab6::doubly_linked_list d1(values);
    cout<<d1.get_size();
    d1.print();
    return 0;
}
