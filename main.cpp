
#include <iostream>
#include "doubly_linked_list.h"
using namespace std;
int main() {

    std::vector<unsigned> test_numbers=std::vector<unsigned>({0,1,2,3,4,5,6,7,8,9});
    lab6::doubly_linked_list list3(test_numbers);
    lab6::doubly_linked_list temp_list;
    temp_list = list3.split_before(7);
    std::cout<<temp_list.get_data(0)<<"= 7 "<<endl;
    std::cout<<list3.get_data(0)<<"= 0 "<<endl;
    temp_list = list3.split_after(5);
    std::cout<<temp_list.get_data(0)<<"= 6 "<<endl;
    std::cout<<list3.get_data(0)<<"= 0 "<<endl;
    temp_list = list3.split_set(2,3);
    std::cout<<temp_list.get_data(0)<<"= 2 "<<endl;
    std::cout<<list3.get_data(0)<<"= 0 "<<endl;
    

    return 0;
}
