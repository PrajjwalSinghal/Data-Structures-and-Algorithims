#include "gtest/gtest.h"

#include "../lib/lab05/inc/expression.h"
#include "../lib/lab05/inc/stack.h"
#include "../lib/lab05/inc/queue.h"

class Lab05_Fixture : public ::testing::Test {
public:
    lab5::expression *test_expression;
    lab5::stack *test_stack;
    lab5::queue * test_queue;
};

TEST_F(Lab05_Fixture, Pop_Push_Test) {
    test_stack=new lab5::stack;
    EXPECT_EQ(true,test_stack->isEmpty());
    std::string sample_string;

    sample_string="12";
    test_stack->push(sample_string);
    EXPECT_EQ(1,test_stack->stackSize());
    EXPECT_EQ(sample_string,test_stack->top());

    sample_string="abcd";
    test_stack->push(sample_string);
    EXPECT_EQ(2,test_stack->stackSize());
    EXPECT_EQ(sample_string,test_stack->top());

    sample_string = "sample text";
    test_stack->push(sample_string);
    EXPECT_EQ(3,test_stack->stackSize());
    EXPECT_EQ(sample_string,test_stack->top());

    EXPECT_EQ(false,test_stack->isEmpty());

    sample_string="abcd";
    test_stack->pop();
    EXPECT_EQ(2,test_stack->stackSize());
    EXPECT_EQ(sample_string,test_stack->top());

    sample_string="12";
    test_stack->pop();
    EXPECT_EQ(1,test_stack->stackSize());
    EXPECT_EQ(sample_string,test_stack->top());

    test_stack->pop();
    EXPECT_EQ(0,test_stack->stackSize());
    EXPECT_EQ(true,test_stack->isEmpty());
}

TEST_F(Lab05_Fixture, queue_enqueue_test) {
    test_queue=new lab5::queue;
    EXPECT_EQ(true,test_queue->isEmpty());
    std::string sample_string,front_string;

    front_string=sample_string="12";
    test_queue->enqueue(sample_string);
    EXPECT_EQ(1,test_queue->queueSize());
    EXPECT_EQ(front_string,test_queue->top());

    sample_string="abcd";
    test_queue->enqueue(sample_string);
    EXPECT_EQ(2,test_queue->queueSize());
    EXPECT_EQ(front_string,test_queue->top());

    sample_string = "sample text";
    test_queue->enqueue(sample_string);
    EXPECT_EQ(3,test_queue->queueSize());
    EXPECT_EQ(front_string,test_queue->top());

    EXPECT_EQ(false,test_queue->isEmpty());

    front_string="abcd";
    test_queue->dequeue();
    EXPECT_EQ(2,test_queue->queueSize());
    EXPECT_EQ(front_string,test_queue->top());

    front_string="sample text";
    test_queue->dequeue();
    EXPECT_EQ(1,test_queue->queueSize());
    EXPECT_EQ(front_string,test_queue->top());

    test_queue->dequeue();
    EXPECT_EQ(0,test_queue->queueSize());
    EXPECT_EQ(true,test_queue->isEmpty());
}

TEST_F(Lab05_Fixture, Infix_Postfix_Parsing_Print_Test) {
    std::string output;
    std::string sample_text="1+2+3";
    test_expression = new lab5::expression(sample_text);

    testing::internal::CaptureStdout();
    test_expression->print_infix();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("1 + 2 + 3",output);

    testing::internal::CaptureStdout();
    test_expression->print_postfix();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("1 2 + 3 +",output);

    delete test_expression;
    sample_text = "1+   2/3 *(2-1)";

    test_expression = new lab5::expression(sample_text);

    testing::internal::CaptureStdout();
    test_expression->print_infix();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("1 + 2 / 3 * ( 2 - 1 )",output);

    testing::internal::CaptureStdout();
    test_expression->print_postfix();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("1 2 3 / 2 1 - * +",output );

    delete test_expression;
    sample_text = "12+   2234/23 *(212-13)";

    test_expression = new lab5::expression(sample_text);

    testing::internal::CaptureStdout();
    test_expression->print_infix();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ( "12 + 2234 / 23 * ( 212 - 13 )",output);

    testing::internal::CaptureStdout();
    test_expression->print_postfix();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("12 2234 23 / 212 13 - * +",output);
}


TEST_F(Lab05_Fixture, istream_test) {
    test_expression = new lab5::expression;
    std::istringstream sample_stream ("1+2-3");
    std::string output;

    sample_stream >> *test_expression;

    testing::internal::CaptureStdout();
    test_expression->print_infix();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("1 + 2 - 3", output);
}

TEST_F(Lab05_Fixture, simple_calc_test) {
    std::string sample_string="1+2+3";
    test_expression = new lab5::expression(sample_string);

    EXPECT_EQ(6,test_expression->calculate_postfix());

    delete test_expression;
    sample_string ="2*3+4";
    test_expression=new lab5::expression(sample_string);

    EXPECT_EQ(10,test_expression->calculate_postfix());

    delete test_expression;
    sample_string ="6/2-2";
    test_expression=new lab5::expression(sample_string);

    EXPECT_EQ(1,test_expression->calculate_postfix());

    delete test_expression;
    sample_string ="2*3+4+3";
    test_expression=new lab5::expression(sample_string);

    EXPECT_EQ(13,test_expression->calculate_postfix());

    delete test_expression;
    sample_string ="9/3+4";
    test_expression=new lab5::expression(sample_string);

    EXPECT_EQ(7,test_expression->calculate_postfix());
}

TEST_F(Lab05_Fixture, calculate_test) {
    std::string sample_string="32*45-(2+17)";
    test_expression = new lab5::expression(sample_string);

    EXPECT_EQ(1421,test_expression->calculate_postfix());

    delete test_expression;
    sample_string ="52+(27+(39*(23-(3+14))+18)/6)";
    test_expression=new lab5::expression(sample_string);

    EXPECT_EQ(121,test_expression->calculate_postfix());

    delete test_expression;
    sample_string ="(24+0-4*(9-3))*2";
    test_expression=new lab5::expression(sample_string);

    EXPECT_EQ(0,test_expression->calculate_postfix());
}
