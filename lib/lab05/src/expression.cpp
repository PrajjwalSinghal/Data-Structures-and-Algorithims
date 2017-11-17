#include "../inc/expression.h"
namespace lab5 {
    /****Auxillary Function prototypes ****/
    bool is_number(std::string input_string);

    bool is_operator(std::string input_string);

    int get_number(std::string input_string);

    std::string get_operator(std::string input_string);

    int operator_priority(std::string operator_in);

    /****end function prototypes****/


    expression::expression() {

    }

    expression::expression(std::string &input_expression) {

    }

    void expression::convert_to_postfix(std::string &input_expression) {

    }

    void expression::parse_to_infix(std::string &input_expression) {

    }

    int expression::calculate_postfix() {
        return 0;
    }

    void expression::print_infix() {

    }

    void expression::print_postfix() {

    }

    std::istream &operator>>(std::istream &steam, expression &RHS) {
//    return <#initializer#>;
    }


//auxillary functions

    bool is_number(std::string input_string) {

    }

    bool is_operator(std::string input_string) {

    }

    int get_number(std::string input_string) {

    }

    std::string get_operator(std::string input_string) {

    }

    int operator_priority(std::string operator_in) {

    }
}