#include "AmandaCalculator.h"
#include <iostream>
#include "mainCalculator.h"

int main(){
  Cpu *cpu1 = new CpuAmanda;
  Display *display1 = new DisplayAmanda;
  Keyboard *k1 = new KeyboardAmanda; 
  Calculator *calc1 = new CalculatorAmanda(cpu1, display1, k1);
  KeyDigit key0(ZERO), key1(ONE), key2(TWO);

  KeyOperation keyAdd(ADDITION), keySub(SUBTRACTION);

  KeyControl keyClear(CLEAR), keyReset(RESET), keyDecSep(DECIMAL_SEPARATOR), keyEqual(EQUAL);

  // Test Display
  display1->setSignal(NEGATIVE);
  display1->add(ONE);
  display1->add(TWO);
  display1->add(THREE);
  display1->add(FOUR);
  display1->add(FIVE);
  display1->setDecimalSeparator();
  display1->add(SIX);
  display1->add(SEVEN);
  display1->add(EIGHT);
  display1->add(NINE);
  display1->add(ZERO);
  display1->clear();
  display1->clear();
  display1->clear();

  return 0; //<===== Até aqui tudo testado

  // Polimorfismo
  k1->addKey(&key0);
  k1->addKey(&key1);
  k1->addKey(&key2);

  k1->addKey(&keyClear);
  k1->addKey(&keyReset);
  k1->addKey(&keyDecSep);

  key1.press();
  key1.press();
  key1.press();
  key0.press();
  keyAdd.press();
  key1.press();
  keyEqual.press();
  
  return 1;
}
