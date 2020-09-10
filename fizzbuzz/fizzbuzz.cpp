
#include <iostream>
#include <iomanip>

int main(int argc, char ** argv){

  // get input
  //if ( argc < 1 ) {
  //  std::cout << "The user should provide a
  //}
  //
  // check input and print
  for ( int number = 1; number <=100; number++) {
    std::cout << std::setw(3) << number << " ";
    if ( number % 3 == 0  && number % 5 == 0) {
      std::cout << "FizzBuzz";
    } else if ( number % 3 == 0 ) {
      std::cout << "Fizz";
    } else if ( number % 5 == 0 ) {
      std::cout << "Buzz";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  for ( int number = 1; number <=100; number++) {
    std::cout << number << " ";
    bool remainder3 = (number % 3) == 0;
    bool remainder5 = (number % 5) == 0;
    enum { CONGRUENT_3 = 0, CONGRUENT_5 = 1};
    int remainders_3_5 = remainder3 ? (remainder5 ? 2 : 0 ) : 1;
    switch ( remainders_3_5 ) {
      case CONGRUENT_3:
        std::cout << "Fizz";
      case CONGRUENT_5:
        std::cout << "Buzz";
    }
    std::cout << std::endl;
  }

}
