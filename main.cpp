#include "AmandaCalculator.h"
#include <iostream>
#include "mainCalculator.h"

int mainCalculator(){
  CalculatorAmanda calc1;
  CpuAmanda cpu1;
  DisplayAmanda display1;
  KeyboardAmanda k1; 
  KeyDigit key0(ZERO), key1(ONE), key2(TWO);

  KeyOperation keyAdd(ADDITION), keySub(SUBTRACTION);

  KeyControl keyClear(CLEAR), keyReset(RESET), keyDecSep(DECIMAL_SEPARATOR), keyEqual(EQUAL);

  // Polimorfismo
  k1.addKey(&key0);
  k1.addKey(&key1);
  k1.addKey(&key2);

  k1.addKey(&keyClear);
  k1.addKey(&keyReset);
  k1.addKey(&keyDecSep);

  key1.press();
  key1.press();
  key1.press();
  key0.press();
  keyAdd.press();
  key1.press();
  keyEqual.press();
  
  return 1;
}
