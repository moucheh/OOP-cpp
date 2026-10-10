#pragma once
#include <sstream>
#include <string>

extern const std::string input_prompt;
extern const std::string result_prompt;

class Calculator {
public:
  Calculator();

  void reset();
  void handle_operand_input(std::istringstream& is, bool first = true);
  void handle_operation_input(std::istringstream& is);
  void handle_computation();
  void print_result() const;
  void print_help() const;
  void set_values(double op1, char op, double op2);

private:
  char operation;
  double operand1;
  double operand2;
  double result;
  bool invalid = false;
};
