#include "../inc/expression.h"

#include<iostream>
#include<stdlib.h>
using namespace std;
namespace lab5 {
    //
// Created by Bryan on 9/30/2017.
//


/****Auxillary Function prototypes ****/
    bool is_number(std::string input_string);
    bool is_operator(char input_char);
    bool is_operator(std::string input_string);
    int get_number(string num1,string temp_operator,string num2);
    std::string get_operator(std::string input_string);
    int operator_priority(std::string operator_in);
/****end function prototypes****/
    bool is_operator(std::string input_string)
    {
        if(input_string=="+" || input_string=="-" || input_string=="*" || input_string=="/"||input_string=="("||input_string==")")
            return true;
        else
            return false;
    }
    bool is_operator(char input_char)
    {
        if(input_char=='+' || input_char=='-' || input_char=='*' || input_char=='/'||input_char=='('||input_char==')')
            return true;
        else
            return false;
    }
    expression::expression() {

    }

    expression::expression(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(input_expression);
    }

    void expression::convert_to_postfix(std::string &input_expression) {
        stack temp_stack;
        queue temp_queue;
        temp_queue = infix;
        while(!temp_queue.isEmpty())
        {
            std::string temp_string="";
            temp_string = temp_queue.top();
            temp_queue.dequeue();
            if(!is_operator(temp_string))
                postfix.enqueue(temp_string);
            else
            {
                if(temp_stack.isEmpty())
                    temp_stack.push(temp_string);
                else
                {

                    if(temp_string=="(")
                        temp_stack.push(temp_string);
                    else if(temp_string==")")
                    {
                        while(temp_stack.top()!="(")
                        {
                            string temp1=temp_stack.top();
                            postfix.enqueue(temp1);
                            temp_stack.pop();
                        }
                        temp_stack.pop();
                    }
                    else if(operator_priority(temp_stack.top())>=operator_priority(temp_string))
                    {
                        while(!temp_stack.isEmpty() &&
                                operator_priority(temp_stack.top())>=operator_priority(temp_string))
                        {
                            string temp1=temp_stack.top();
                            postfix.enqueue(temp1);
                            temp_stack.pop();
                        }
                        temp_stack.push(temp_string);
                    }
                    else
                    {
                        temp_stack.push(temp_string);
                    }
                }
            }

        }
        while(!temp_stack.isEmpty())
        {
            string temp1=temp_stack.top();
            postfix.enqueue(temp1);
            temp_stack.pop();
        }


    }

    void expression::parse_to_infix(std::string &input_expression) {

        std::string temp_number="",temp_operator="";
        for(int i=0;input_expression[i]!='\0';i++)
        {

            if(input_expression[i]==' ')
            {}
            else if(!is_operator(input_expression[i]))
            {
                temp_number+=input_expression[i];

            }
            else
            {
                if(temp_number!="")
                    infix.enqueue(temp_number);
                temp_operator += input_expression[i];
                infix.enqueue(temp_operator);
                temp_number="";
                temp_operator="";
            }
            if(input_expression[i+1]=='\0'&&temp_number!="")
            {
                infix.enqueue(temp_number);
                temp_number="";
            }
        }
    }


    int expression::calculate_postfix() {
        stack result;
        //queue temp;
        //cout<<postfix.queueSize();
        //cout<<temp.queueSize();
        //temp = postfix;
        queue temp2;
        temp2=postfix;
        string final_answer;

        while(!temp2.isEmpty())
        {
            string temp_element="";
            temp_element = temp2.top();
            temp2.dequeue();
            if(!is_operator(temp_element))
            {
                result.push(temp_element);
            }
            else
            {   //stringstream geek(s);
                int answer=0;
                string upper="",lower="";
                upper = result.top();
                result.pop();
                lower = result.top();
                result.pop();
                answer = get_number(upper,temp_element,lower);
                temp_element = to_string(answer);
                result.push(temp_element);
            }
        }
        final_answer = result.top();
        result.pop();
        //stringstream geek(final_answer);
        int answer=0;
        //geek>>answer;
        answer = atoi(final_answer.c_str());
        return answer;
    }

    void expression::print_infix() {
        //queue temp = infix;
        while(!infix.isEmpty())
        {
            std::cout<<infix.top();
            infix.dequeue();
            if(!infix.isEmpty())
                std::cout<<" ";

        }
    }

    void expression::print_postfix() {
        queue temp2;
        temp2=postfix;
        while(!temp2.isEmpty())
        {
            std::cout<<temp2.top();
            temp2.dequeue();
            if(!temp2.isEmpty())
                std::cout<<" ";
        }

    }

    std::istream &operator>>(std::istream &steam, expression &RHS) {
        string x;
        steam>>x;
        RHS.parse_to_infix(x);
        RHS.convert_to_postfix(x);

        return steam;
    }


//auxillary functions

    bool is_number(std::string input_string){

    }


    int get_number(string num1, string temp_operator, string num2){

        int answer;
        int first_number=stoi(num2);
        int second_number=stoi(num1);
        if(temp_operator=="+")
            answer= first_number+second_number ;
        else if(temp_operator=="-")
            answer = first_number - second_number;
        else if(temp_operator=="*")
            answer = first_number * second_number;
        else if(temp_operator == "/")
            answer = first_number/second_number;
        else
        {
            cout<<temp_operator<<"::is not a valid operator";
            exit(1);
        }
        return answer;
    }

    std::string get_operator(std::string input_string){

    }

    int operator_priority(std::string operator_in){
        if(operator_in=="+"||operator_in=="-")
            return 1;
        else if(operator_in=="*" || operator_in=="/")
            return 2;
        else if(operator_in=="("||operator_in==")")
            return 0;

    }
}