#include "Calculator.hpp"

#include <cmath>
#include <iostream>

Calculator::Calculator() :
    invalid{ false } {}

void Calculator::reset() {
  invalid = false;
  operation = -1;
}

void Calculator::handle_operand_input(std::istringstream& is, bool first) {
  if (first)
    is >> operand1;
  else
    is >> operand2;
  if (!is)
    invalid = true;
}

void Calculator::handle_operation_input(std::istringstream& is) {
  do {
    is >> operation;
  } while (operation == ' ' || operation == '\t');
}

void Calculator::handle_computation() {
  switch (operation) {
    case '+':
      result = operand1 + operand2;
      break;
    case '-':
      result = operand1 - operand2;
      break;
    case '*':
      result = operand1 * operand2;
      break;
    case '/':
      if (operand2 == 0.0)
        invalid = true;
      else
        result = operand1 / operand2;
      break;
    case '^':
      if (operand1 == 0.0 && operand2 == 0.0)
        invalid = true;
      else
        result = std::pow(operand1, operand2);
      break;
    default:
      invalid = true;
      break;
  }
}

void Calculator::print_result() const {
  if (invalid)
    std::cout << "Invalid operation!" << std::endl;
  else {
    std::cout << result_prompt << result << std::endl;
  }
}

void Calculator::print_help() const {
  std::cout << "Usage: write <num1> <op> <num2> in a single line\n"
            << "or run as command: ./calculator <num1> <op> <num2>\n"
            << "num1 and num2 are real number values\n"
            << "op is +, -, *, / or ^\n"
            << "*help* prints this menu\n"
            << "*clear* clears the screen\n"
            << std::endl;
}

void Calculator::set_values(double op1, char op, double op2) {
  operand1 = op1;
  operand2 = op2;
  operation = op;
}

void loop(Calculator& c) {
  std::string input;

  while (std::cin) {
    c.reset();
    std::cout << input_prompt;
    std::getline(std::cin, input, '\n');

    if (input.empty())
      continue;

    if (input == "help") {
      c.print_help();
      continue;
    }

    if (input == "clear") {
      std::cout << "\033[2J\033[1;1H";
      continue;
    }

    if (input == "exit" || input == "quit") {
      break;
    }

    std::istringstream is(input);

    c.handle_operand_input(is);

    c.handle_operation_input(is);

    c.handle_operand_input(is, false);

    c.handle_computation();

    c.print_result();
  }

  std::cout << "Exited!" << std::endl;
}
