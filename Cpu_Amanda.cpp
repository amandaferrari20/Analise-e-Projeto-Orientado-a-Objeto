#include "AmandaCalculator.h"
#include "CalculatorLucio.h"
// #include "cpuAmanda.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>

CpuAmanda::CpuAmanda(){
  this->operandOne = static_cast <Digit *>(calloc(maxDigits, sizeof(Digit)));
  this->operandOne = static_cast <Digit *>(calloc(maxDigits, sizeof(Digit)));
  this->operation = NONE;
  this->signal = POSITIVE;
}

// void CpuAmanda::receiveDigit(Digit digit){
//   try{
//     if(this->operandOneCounter >= this->maxDigits) throw;
//     if(this->operandTwoCounter >= this->maxDigits) throw;
    
//     this->display->add(digit);
    
//     if(this->operation == NONE){
//       this->operandOne[this->operandOneCounter] = digit;
//       this->operandOneCounter++;
//     }else{
//       this->operandTwo[this->operandTwoCounter] = digit;
//       this->operandTwoCounter++;
//     }
//   }catch(...){}
// }


void CpuAmanda::receiveDigit(Digit digit){

	if ((this->operandOneCounter < maxDigits))
	{
		this->operandOne[this->operandOneCounter++] = digit;
	}
	else if ((operandTwoCounter < maxDigits && this->operation != NONE))
	{
		this->operandTwo[this->operandTwoCounter++] = digit;
	}
}

void CpuAmanda::receiveOperation(Operation operation){
// operacao != de equal n aceita ppor ser do tipo control, revisar
  if(this->operation != NONE)
    this->calculate();
  
  this->display->clear();
  this->operation = operation;
}

//void Cpu::cancel(){
//  this->display->clear();

//  if(this->operation == NONE){
//    this->operandOneCounter = 0;
//  }else{
//    this->operandTwoCounter = 0;
//  }
//}

// void Cpu::reset(){
//   this->operandOneCounter = 0;
//   this->operandTwoCounter = 0;
//   this->operation = NONE;
//   this->signal = POSITIVE;
// }


// void CpuAmanda::setDisplay(DisplayAmanda *display){
//   this->display = display;
// }

Digit CpuAmanda::intToDigit(int number, int *digitLenght, Signal *signal){
  *digitLenght = 0;
  *signal = (number < 0) ? NEGATIVE : POSITIVE;

  while(number > 0){
    digit[(*digitLenght)++] = Digit(number % 10);
    number /= 10;
  }

  for(int i = 0; i < (*digitLenght)/2; i++){
    Digit temp = digit[i];
    digit[i] = digit[*digitLenght-i-1];
    digit[*digitLenght-i-1] = temp;
  }
  //rever o retorno
  return *digit;
}


int CpuAmanda::digitToInt(Digit *operand, int count){
  int result = 0;
  
  for(int i = 0; i < count; i++){
    result *= 10;
    result += operand[i];
  }

  return result;
}


Digit CpuAmanda::calculate(){
  int n1 = digitToInt(this->operandOne, this->operandOneCounter);
  int n2 = digitToInt(this->operandTwo, this->operandTwoCounter);
  Digit a = ZERO;

  switch (this->operation){
  case ADDITION:
    return this->intToDigit(n1+n2, &this->operandOneCounter+operandTwoCounter, &this->signal);
    break;
    
  case SUBTRACTION:
    return this->intToDigit(n1-n2, &this->operandOneCounter+operandTwoCounter, &this->signal);
    break;
    
  case DIVISION:
     return this->intToDigit(n1/n2, &this->operandOneCounter+operandTwoCounter, &this->signal);
    break;
    
  case MULTIPLICATION:
    return this->intToDigit(n1*n2, &this->operandOneCounter+operandTwoCounter, &this->signal);
    break;
  
  case SQUARE_ROOT:
    return this->intToDigit(sqrt(n1), &this->operandOneCounter+operandTwoCounter, &this->signal);
    break;

  case PERCENTAGE:
    return this->intToDigit((n1/n2)*100, &this->operandOneCounter+operandTwoCounter, &this->signal);
    break;

  //nao sei o que fazer no case NONE
  case NONE:
    break;
   }
   return a;
}

  void CpuAmanda::receiveControl(Control control){
    switch (this->control){
      case CLEAR:
        this->operandOne = 0;
        this->operandTwo = 0;
        this->operandOneCounter = 0;
        this->operandTwoCounter = 0;
        this->operation = NONE;
        this->signal = POSITIVE;
        this->countDigits = 0;
        //LIMPAR TUDO
        break;
      case RESET:
          this->operandOneCounter = 0;
          this->operandTwoCounter = 0;
          this->operation = NONE;
          this->signal = POSITIVE;
        break;
      case DECIMAL_SEPARATOR:
          //    
        break;
      case EQUAL:
        if(operation != NONE){
          result = this->calculate();
        }
        break;
      case MEMORY_READ_CLEAR: 
        memory = result;
        break;
      case MEMORY_ADDITION:
        result += memory;
        break;
      case MEMORY_SUBTRACTION: 
        result -= memory;
        break;
      }

  this->display->clear();
  this->display->setSignal(this->signal);
  for(int i = 0; i < this->operandOneCounter; i++){
    this->display->add(this->operandOne[i]);
  }

  this->operandOneCounter = 0;
}

