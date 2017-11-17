#ifndef CMPE126F17_LABS_LIB_LAB05_INC_EXPRESSION_H
#define CMPE126F17_LABS_LIB_LAB05_INC_EXPRESSION_H

#include "queue.h"
#include "stack.h"

namespace lab5 {
    class expression {
        queue infix;
        queue postfix;

        void convert_to_postfix(std::string &input_expression);
        void parse_to_infix(std::string &input_expression);
    public:
        expression();
        expression(std::string& input_expression);

        int calculate_postfix();
        void print_infix();
        void print_postfix();
        friend std::istream& operator>>(std::istream& steam, expression& RHS);
    };
}

#endif //CMPE126F17_LABS_LIB_LAB05_INC_EXPRESSION_H
