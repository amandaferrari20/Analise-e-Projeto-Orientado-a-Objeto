#include "AmandaCalculator.h"
#include "CalculatorLucio.h"
#include <cstdlib>

void CalculatorAmanda::calculator(Cpu *cpu, Display *display, Keyboard *keyBoard){

  this->setCpu(cpu);
  this->setDisplay(display);
  this->setKeyboard(keyBoard);
  this->cpu->setDisplay(display);
  this->keyBoard->setCpu(cpu);
  // this->operationKeyBoard->setCpu(cpu);
}

//CalculatorAmanda::~CalculatorAmanda(){
//  delete this->cpu;
//  delete this->display;
//  delete this->numericKeyBoard;
//  delete this->operationKeyBoard;
//}

// void CalculatorAmanda::setKeyDigit(Keyboard *keyboard){
//   this->keyBoard = keyBoard;
// }

void CalculatorAmanda:: setKeyboard(Keyboard* key){
  this->keyBoard = key;
}

// void CalculatorAmanda::setKeyOperation(KeyOperation *operationKeyBoard){
//   this->operationKeyBoard = operationKeyBoard;
// }

// KeyDigit* CalculatorAmanda::getKeyDigit(){
//   return this->numericKeyBoard;
// }

// KeyOperation *CalculatorAmanda::getKeyOperation(){
//   return this->operationKeyBoard;
// }

void CalculatorAmanda::setDisplay(Display *display){
  this->display = display;
}

Display* CalculatorAmanda::getDisplay(){
  return this->display;
}

void CalculatorAmanda::setCpu(Cpu* cpu){
  this->cpu = cpu;
}

Cpu* CalculatorAmanda::getCpu(){
  return this->cpu;
  }

CalculatorAmanda::~CalculatorAmanda(){
  delete this->cpu;
  delete this->display;
  delete this->keyBoard;
}
