#include "gtest/gtest.h"

#include "../lib/lab06/inc/doubly_linked_list.h"
#include "../lib/lab08/inc/sorts.h"

class Lab8_Tests : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
        unsorted_numbers=std::vector<unsigned>({72, 96, 26, 94, 33,  2, 42,
                                                 89, 41, 36, 63, 65, 56, 16,
                                                 17, 59, 35, 39, 40,  1, 69});

        small_numbers=std::vector<unsigned>({5, 3, 4, 1, 2, 7, 6});

        Lposition = unsorted_numbers.begin();
        Rposition = unsorted_numbers.end();
        unsorted_list = new lab6::doubly_linked_list(unsorted_numbers);
        small_unsorted_list = new lab6::doubly_linked_list(small_numbers);
    }

public:
    Lab8_Tests() : Test() {
    }

    virtual ~Lab8_Tests() {

    }
    sorts sorting_machine;
    lab6::doubly_linked_list *unsorted_list, *small_unsorted_list;
    std::vector <unsigned> unsorted_numbers, small_numbers;
    std::vector<unsigned>::iterator Lposition, Rposition;
};


TEST_F(Lab8_Tests, insertion_sort) {
    std::string sorted0  = "72, 96, 26, 94, 33, 2, 42, 89, 41, 36, 63, 65, 56, 16, 17, 59, 35, 39, 40, 1, 69";
    std::string sorted1  = "72, 96, 26, 94, 33, 2, 42, 89, 41, 36, 63, 65, 56, 16, 17, 59, 35, 39, 40, 1, 69";
    std::string sorted5  = "2, 26, 33, 72, 94, 96, 42, 89, 41, 36, 63, 65, 56, 16, 17, 59, 35, 39, 40, 1, 69";
    std::string sorted10 = "2, 26, 33, 36, 41, 42, 63, 72, 89, 94, 96, 65, 56, 16, 17, 59, 35, 39, 40, 1, 69";
    std::string sorted15 = "2, 16, 17, 26, 33, 36, 41, 42, 56, 59, 63, 65, 72, 89, 94, 96, 35, 39, 40, 1, 69";
    std::string sorted20 = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";
    std::string sorted25 = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";

    EXPECT_EQ(sorted0,  sorting_machine.insertion_sort(*unsorted_list,  0).to_string());
    EXPECT_EQ(sorted1,  sorting_machine.insertion_sort(*unsorted_list,  1).to_string());
    EXPECT_EQ(sorted5,  sorting_machine.insertion_sort(*unsorted_list,  5).to_string());
    EXPECT_EQ(sorted10, sorting_machine.insertion_sort(*unsorted_list, 10).to_string());
    EXPECT_EQ(sorted15, sorting_machine.insertion_sort(*unsorted_list, 15).to_string());
    EXPECT_EQ(sorted20, sorting_machine.insertion_sort(*unsorted_list, 20).to_string());
    EXPECT_EQ(sorted25, sorting_machine.insertion_sort(*unsorted_list, 25).to_string());

    std::string small_sorted0 = "5, 3, 4, 1, 2, 7, 6";
    std::string small_sorted1 = "3, 5, 4, 1, 2, 7, 6";
    std::string small_sorted2 = "3, 4, 5, 1, 2, 7, 6";
    std::string small_sorted3 = "1, 3, 4, 5, 2, 7, 6";
    std::string small_sorted4 = "1, 2, 3, 4, 5, 7, 6";
    std::string small_sorted5 = "1, 2, 3, 4, 5, 7, 6";
    std::string small_sorted6 = "1, 2, 3, 4, 5, 6, 7";
    std::string small_sorted7 = "1, 2, 3, 4, 5, 6, 7";
    std::string small_sorted8 = "1, 2, 3, 4, 5, 6, 7";

    EXPECT_EQ(small_sorted0, sorting_machine.insertion_sort(*small_unsorted_list,0).to_string());
    EXPECT_EQ(small_sorted1, sorting_machine.insertion_sort(*small_unsorted_list,1).to_string());
    EXPECT_EQ(small_sorted2, sorting_machine.insertion_sort(*small_unsorted_list,2).to_string());
    EXPECT_EQ(small_sorted3, sorting_machine.insertion_sort(*small_unsorted_list,3).to_string());
    EXPECT_EQ(small_sorted4, sorting_machine.insertion_sort(*small_unsorted_list,4).to_string());
    EXPECT_EQ(small_sorted5, sorting_machine.insertion_sort(*small_unsorted_list,5).to_string());
    EXPECT_EQ(small_sorted6, sorting_machine.insertion_sort(*small_unsorted_list,6).to_string());
    EXPECT_EQ(small_sorted7, sorting_machine.insertion_sort(*small_unsorted_list,7).to_string());
    EXPECT_EQ(small_sorted8, sorting_machine.insertion_sort(*small_unsorted_list,8).to_string());
}

TEST_F(Lab8_Tests, selection_sort){
    std::string small_sorted0 = "5, 3, 4, 1, 2, 7, 6";
    std::string small_sorted1 = "1, 3, 4, 5, 2, 7, 6";
    std::string small_sorted2 = "1, 2, 4, 5, 3, 7, 6";
    std::string small_sorted3 = "1, 2, 3, 5, 4, 7, 6";
    std::string small_sorted4 = "1, 2, 3, 4, 5, 7, 6";
    std::string small_sorted5 = "1, 2, 3, 4, 5, 7, 6";
    std::string small_sorted6 = "1, 2, 3, 4, 5, 6, 7";
    std::string small_sorted7 = "1, 2, 3, 4, 5, 6, 7";
    std::string small_sorted8 = "1, 2, 3, 4, 5, 6, 7";

    EXPECT_EQ(small_sorted0, sorting_machine.selection_sort(*small_unsorted_list,0).to_string());
    EXPECT_EQ(small_sorted1, sorting_machine.selection_sort(*small_unsorted_list,1).to_string());
    EXPECT_EQ(small_sorted2, sorting_machine.selection_sort(*small_unsorted_list,2).to_string());
    EXPECT_EQ(small_sorted3, sorting_machine.selection_sort(*small_unsorted_list,3).to_string());
    EXPECT_EQ(small_sorted4, sorting_machine.selection_sort(*small_unsorted_list,4).to_string());
    EXPECT_EQ(small_sorted5, sorting_machine.selection_sort(*small_unsorted_list,5).to_string());
    EXPECT_EQ(small_sorted6, sorting_machine.selection_sort(*small_unsorted_list,6).to_string());
    EXPECT_EQ(small_sorted7, sorting_machine.selection_sort(*small_unsorted_list,7).to_string());
    EXPECT_EQ(small_sorted8, sorting_machine.selection_sort(*small_unsorted_list,8).to_string());

    std::string sorted0  = "72, 96, 26, 94, 33, 2, 42, 89, 41, 36, 63, 65, 56, 16, 17, 59, 35, 39, 40, 1, 69";
    std::string sorted1  = "1, 96, 26, 94, 33, 2, 42, 89, 41, 36, 63, 65, 56, 16, 17, 59, 35, 39, 40, 72, 69";
    std::string sorted5  = "1, 2, 16, 17, 26, 96, 42, 89, 41, 36, 63, 65, 56, 33, 94, 59, 35, 39, 40, 72, 69";
    std::string sorted10 = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 63, 65, 56, 96, 94, 59, 42, 41, 89, 72, 69";
    std::string sorted15 = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 96, 65, 94, 89, 72, 69";
    std::string sorted20 = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";
    std::string sorted25 = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";

    EXPECT_EQ(sorted0,  sorting_machine.selection_sort(*unsorted_list, 0).to_string());
    EXPECT_EQ(sorted1,  sorting_machine.selection_sort(*unsorted_list, 1).to_string());
    EXPECT_EQ(sorted5,  sorting_machine.selection_sort(*unsorted_list, 5).to_string());
    EXPECT_EQ(sorted10, sorting_machine.selection_sort(*unsorted_list,10).to_string());
    EXPECT_EQ(sorted15, sorting_machine.selection_sort(*unsorted_list,15).to_string());
    EXPECT_EQ(sorted20, sorting_machine.selection_sort(*unsorted_list,20).to_string());
    EXPECT_EQ(sorted25, sorting_machine.selection_sort(*unsorted_list,25).to_string());
}

TEST_F(Lab8_Tests, bubble_sort){
    std::string small_sorted0 = "5, 3, 4, 1, 2, 7, 6";
    std::string small_sorted1 = "3, 4, 1, 2, 5, 6, 7";
    std::string small_sorted2 = "3, 1, 2, 4, 5, 6, 7";
    std::string small_sorted3 = "1, 2, 3, 4, 5, 6, 7";
    std::string small_sorted4 = "1, 2, 3, 4, 5, 6, 7";

    EXPECT_EQ(small_sorted0, sorting_machine.bubble_sort(*small_unsorted_list,0).to_string());
    EXPECT_EQ(small_sorted1, sorting_machine.bubble_sort(*small_unsorted_list,1).to_string());
    EXPECT_EQ(small_sorted2, sorting_machine.bubble_sort(*small_unsorted_list,2).to_string());
    EXPECT_EQ(small_sorted3, sorting_machine.bubble_sort(*small_unsorted_list,3).to_string());
    EXPECT_EQ(small_sorted4, sorting_machine.bubble_sort(*small_unsorted_list,4).to_string());

    std::string sorted0  = "72, 96, 26, 94, 33, 2, 42, 89, 41, 36, 63, 65, 56, 16, 17, 59, 35, 39, 40, 1, 69";
    std::string sorted1  = "72, 26, 94, 33, 2, 42, 89, 41, 36, 63, 65, 56, 16, 17, 59, 35, 39, 40, 1, 69, 96";
    std::string sorted5  = "2, 26, 33, 41, 36, 42, 63, 56, 16, 17, 59, 35, 39, 40, 1, 65, 69, 72, 89, 94, 96";
    std::string sorted10 = "2, 26, 33, 16, 17, 36, 35, 39, 40, 1, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";
    std::string sorted15 = "2, 16, 17, 26, 1, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";
    std::string sorted20 = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";
    std::string sorted25 = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";

    EXPECT_EQ(sorted0,  sorting_machine.bubble_sort(*unsorted_list, 0).to_string());
    EXPECT_EQ(sorted1,  sorting_machine.bubble_sort(*unsorted_list, 1).to_string());
    EXPECT_EQ(sorted5,  sorting_machine.bubble_sort(*unsorted_list, 5).to_string());
    EXPECT_EQ(sorted10, sorting_machine.bubble_sort(*unsorted_list,10).to_string());
    EXPECT_EQ(sorted15, sorting_machine.bubble_sort(*unsorted_list,15).to_string());
    EXPECT_EQ(sorted20, sorting_machine.bubble_sort(*unsorted_list,20).to_string());
    EXPECT_EQ(sorted25, sorting_machine.bubble_sort(*unsorted_list,25).to_string());
}

TEST_F(Lab8_Tests, cocktail_sort){
    std::string small_sorted0 = "5, 3, 4, 1, 2, 7, 6";
    std::string small_sorted1 = "1, 3, 4, 2, 5, 6, 7";
    std::string small_sorted2 = "1, 2, 3, 4, 5, 6, 7";
    std::string small_sorted3 = "1, 2, 3, 4, 5, 6, 7";

    EXPECT_EQ(small_sorted0, sorting_machine.cocktail_sort(*small_unsorted_list,0).to_string());
    EXPECT_EQ(small_sorted1, sorting_machine.cocktail_sort(*small_unsorted_list,1).to_string());
    EXPECT_EQ(small_sorted2, sorting_machine.cocktail_sort(*small_unsorted_list,2).to_string());
    EXPECT_EQ(small_sorted3, sorting_machine.cocktail_sort(*small_unsorted_list,3).to_string());

    std::string sorted0  = "72, 96, 26, 94, 33, 2, 42, 89, 41, 36, 63, 65, 56, 16, 17, 59, 35, 39, 40, 1, 69";
    std::string sorted1  = "1, 72, 26, 94, 33, 2, 42, 89, 41, 36, 63, 65, 56, 16, 17, 59, 35, 39, 40, 69, 96";
    std::string sorted5  = "1, 2, 16, 17, 26, 33, 35, 36, 41, 39, 42, 63, 56, 40, 59, 65, 69, 72, 89, 94, 96";
    std::string sorted10 = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";
    std::string sorted15 = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";
    std::string sorted20 = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";
    std::string sorted25 = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";

    EXPECT_EQ(sorted0,  sorting_machine.cocktail_sort(*unsorted_list, 0).to_string());
    EXPECT_EQ(sorted1,  sorting_machine.cocktail_sort(*unsorted_list, 1).to_string());
    EXPECT_EQ(sorted5,  sorting_machine.cocktail_sort(*unsorted_list, 5).to_string());
    EXPECT_EQ(sorted10, sorting_machine.cocktail_sort(*unsorted_list,10).to_string());
    EXPECT_EQ(sorted15, sorting_machine.cocktail_sort(*unsorted_list,15).to_string());
    EXPECT_EQ(sorted20, sorting_machine.cocktail_sort(*unsorted_list,20).to_string());
    EXPECT_EQ(sorted25, sorting_machine.cocktail_sort(*unsorted_list,25).to_string());
}

TEST_F(Lab8_Tests, merge_sort){
    std::string small_sorted = "1, 2, 3, 4, 5, 6, 7";
    EXPECT_EQ(small_sorted, sorting_machine.merge_sort(*small_unsorted_list).to_string());

    std::string sorted = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";
    EXPECT_EQ(sorted, sorting_machine.merge_sort(*unsorted_list).to_string());
}

TEST_F(Lab8_Tests, quick_sort){
    std::string small_sorted = "1, 2, 3, 4, 5, 6, 7";
    EXPECT_EQ(small_sorted, sorting_machine.quick_sort(*small_unsorted_list).to_string());

    std::string sorted = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";
    EXPECT_EQ(sorted, sorting_machine.quick_sort(*unsorted_list).to_string());
}

TEST_F(Lab8_Tests, radix_sort){
    std::string small_sorted = "1, 2, 3, 4, 5, 6, 7";
    EXPECT_EQ(small_sorted, sorting_machine.radix_sort(*small_unsorted_list).to_string());

    std::string sorted = "1, 2, 16, 17, 26, 33, 35, 36, 39, 40, 41, 42, 56, 59, 63, 65, 69, 72, 89, 94, 96";
    EXPECT_EQ(sorted, sorting_machine.radix_sort(*unsorted_list).to_string());
}