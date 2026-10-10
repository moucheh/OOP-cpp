#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Calculator.hpp"

const std::string input_prompt = "> ";
const std::string result_prompt = "= ";

void loop(Calculator& c);

int main(int argc, char* argv[]) {
  Calculator c;

  if (argc == 1) {
    loop(c);
  } else if (argc == 4) {
    if (strlen(argv[2]) == 1) {
      double op1, op2;
      try {
        op1 = std::stod(argv[1]);
        op2 = std::stod(argv[3]);
      } catch (const std::invalid_argument& err) {
        std::cout << "Invalid first or second operand, you have to enter real "
                     "numbers!"
                  << std::endl;
        exit(1);
      }

      c.set_values(op1, *argv[2], op2);
      c.handle_computation();
      c.print_result();
    }
  } else {
    c.print_help();
  }

  return 0;
}
