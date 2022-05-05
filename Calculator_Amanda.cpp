#include "AmandaCalculator.h"
#include <cstdlib>

void CalculatorAmanda::calculator(CpuAmanda *cpu, DisplayAmanda *display, KeyDigitAmanda *numericKeyBoard, KeyOperationAmanda *operationKeyBoard){
    
  this->setCpu(cpu);
  this->setDisplay(display);
  this->setKeyDigit(numericKeyBoard);
  this->setKeyOperation(operationKeyBoard);
  this->cpu->setDisplay(display);
  this->numericKeyBoard->setCpu(cpu);
  this->operationKeyBoard->setCpu(cpu);
}

//CalculatorAmanda::~CalculatorAmanda(){
//  delete this->cpu;
//  delete this->display;
//  delete this->numericKeyBoard;
//  delete this->operationKeyBoard;
//}

void CalculatorAmanda::setKeyDigit(KeyDigitAmanda *numericKeyBoard){
  this->numericKeyBoard = numericKeyBoard;
}

void CalculatorAmanda::setKeyOperation(KeyOperationAmanda *operationKeyBoard){
  this->operationKeyBoard = operationKeyBoard;
}

KeyDigitAmanda* CalculatorAmanda::getKeyDigit(){
  return this->numericKeyBoard;
}

KeyOperationAmanda *CalculatorAmanda::getKeyOperation(){
  return this->operationKeyBoard;
}

void CalculatorAmanda::setDisplay(DisplayAmanda *display){
  this->display = display;
}

DisplayAmanda* CalculatorAmanda::getDisplay(){
  return this->display;
}

void CalculatorAmanda::setCpu(CpuAmanda* cpu){
  this->cpu = cpu;
}

CpuAmanda* CalculatorAmanda::getCpu(){
  return this->cpu;
  }

CalculatorAmanda::~CalculatorAmanda(){
  delete this->cpu;
  delete this->display;
  delete this->numericKeyBoard;
  delete this->operationKeyBoard;
}
