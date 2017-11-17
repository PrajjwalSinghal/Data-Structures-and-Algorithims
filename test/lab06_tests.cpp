//
// Created by gokay on 10/5/17.
//

#include "gtest/gtest.h"

#include "../lib/lab06/inc/doubly_linked_list.h"

class Lab06_Fixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        test_num=1;
        test_numbers=std::vector<unsigned>({0,1,2,3,4,5,6,7,8,9});
        Lposition = test_numbers.begin();
        Rposition = test_numbers.end();
        list1 =new lab6::doubly_linked_list;
        list2 =new lab6::doubly_linked_list(test_num);
        list3 = new lab6::doubly_linked_list(test_numbers);
        list4= new lab6::doubly_linked_list(*list3);
    }

public:
    lab6::doubly_linked_list * list1, *list2, *list3, *list4;
    std::vector <unsigned> test_numbers;
    unsigned test_num;
    std::vector<unsigned>::iterator Lposition, Rposition;
};
TEST_F(Lab06_Fixture, construct_with_check_size) {
    EXPECT_EQ(0, list1->get_size());
    EXPECT_EQ(true, list1->is_empty());
    EXPECT_EQ(1, list2->get_size());
    EXPECT_EQ(test_numbers.size(),list3->get_size());
    EXPECT_EQ(list3->get_size(),list4->get_size());
}

//unsure how to test destructor

TEST_F(Lab06_Fixture, getters){
    //EXPECT_EQ(list1,); need exception handling: ASSERT_THROW()?
    EXPECT_EQ(test_num,list2->get_data(0));
    EXPECT_EQ(test_numbers[4],list3->get_data(4));//could check list in a loop
    EXPECT_EQ(std::vector<unsigned>(Lposition+2,Lposition+6),list3->get_set(2,5));
}

TEST_F(Lab06_Fixture, node_adding_removing){
    list1->append(12);
    EXPECT_EQ(12,list1->get_data(list1->get_size()-1));
    int end = list3->get_size();
    list3->merge(*list3);
    EXPECT_EQ(list3->get_data(end + 2),list3->get_data(2));
    list3->insert_before(4,0);
    EXPECT_EQ(list3->get_data(4),0);
    list3->insert_after(4,4);
    EXPECT_EQ(list3->get_data(5),4);
    list3->remove(4);
    EXPECT_EQ(list3->get_data(4),4);
}


TEST_F(Lab06_Fixture, Split) {
    lab6::doubly_linked_list temp_list;
    temp_list = list3->split_before(7);
    EXPECT_EQ(temp_list.get_data(0), 7);
    EXPECT_EQ(list3->get_data(0), 0);
    temp_list = list3->split_after(5);
    EXPECT_EQ(temp_list.get_data(0), 6);
    EXPECT_EQ(list3->get_data(0), 0);
    temp_list = list3->split_set(2, 3);
    EXPECT_EQ(temp_list.get_data(0), 2);
    EXPECT_EQ(list3->get_data(0), 0);
}

TEST_F(Lab06_Fixture, Swap) {
    list3->swap(3,6);
    EXPECT_EQ(list3->get_data(3),6);
    EXPECT_EQ(list3->get_data(6),3);
    list3->swap_set(0,2,4,5);
    EXPECT_EQ(list3->get_data(0),4);
    EXPECT_EQ(list3->get_data(4),1);
}


TEST_F(Lab06_Fixture, overload) {
    lab6::doubly_linked_list double_list(*list3+*list3);
    for (int i=0; i<20; ++i){
        EXPECT_EQ(double_list.get_data(i),i%10);
    }
    *list3=double_list;
    for (int i=0; i<20; ++i){
        EXPECT_EQ(list3->get_data(i),i%10);
    }
    *list3 += *list3;
    for (int i=0; i<40; ++i){
        EXPECT_EQ(list3->get_data(i),i%10);
    }
}
