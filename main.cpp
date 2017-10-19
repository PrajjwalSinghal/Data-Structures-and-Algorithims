#include "lib/lab06/inc/deck.h"
#include "doubly_linked_list.h"
using namespace std;
int main() {
    //deck newdeck;
    vector <unsigned> values(5);
    values[0] = 4;
    values[1] = 4;
    values[2] = 6;
    values[3] = 6;
    values[4] = 6;
    doubly_linked_list d1(values);
    //cout<<d1.get_size();
    doubly_linked_list d2(d1);
    d2.print();
    return 0;
}
