#include "AmandaCalculator.h"
#include "CalculatorLucio.h"
#include <iostream>

void DisplayAmanda::add(Digit number){
  switch (number){
  case ZERO:
    std::cout << "0";
    break;
  case ONE:
    std::cout << "1";
    break;
  case TWO:
    std::cout << "2";
    break;
  case THREE:
    std::cout << "3";
    break;
  case FOUR:
    std::cout << "4";
    break;
  case FIVE:
    std::cout << "5";
    break;
  case SIX:
    std::cout << "6";
    break;
  case SEVEN:
    std::cout << "7";
    break;
  case EIGHT:
    std::cout << "8";
    break;
  case NINE:
    std::cout << "9";
    break;
  }
};


void DisplayAmanda::setDecimalSeparator(){
  std::cout << ".";
}

void DisplayAmanda::setSignal(Signal signal){
  switch(signal){
    case POSITIVE:
      std::cout <<"" ;
      break;
    case NEGATIVE:
      std::cout << "-";
      break;
  };
}

void DisplayAmanda::clear(){
  std::cout << "\n";  
};