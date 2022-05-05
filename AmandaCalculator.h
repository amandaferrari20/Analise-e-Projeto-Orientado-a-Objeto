#include "CalculatorLucio.h"
#ifndef CALCULATOR_H
#define CALCULATOR_H

// enum Digit {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
// enum Operation {ADDITION, SUBTRACTION, DIVISION, MULTIPLICATION, SQUARE_ROOT, PERCENTAGE, NONE};
// enum Control {CLEAR, RESET, DECIMAL_SEPARATOR, MEMORY_READ_CLEAR, MEMORY_ADDITION, MEMORY_SUBTRACTION, EQUAL};
// enum Signal {POSITIVE, NEGATIVE};

class DisplayAmanda : public Display{
   public:
     void add(Digit);
     virtual void addDigit(Digit ) = 0;
     virtual void setDecimalSeparator() = 0;
     virtual void setSignal(Signal ) = 0;
     virtual void setError() = 0;
     virtual void clear() = 0;
};

class ReceiverAmanda: Receiver{
  public:
     virtual void receiveDigit(Digit ) = 0;
     virtual void receiveOperation(Operation ) = 0;
     virtual void receiveControl(Control ) = 0;

};

class CpuAmanda: public Cpu{
  DisplayAmanda* display;
  Digit *operandOne;
  Digit *operandTwo;
  int operandOneCounter;
  int operandTwoCounter;
  int maxDigits = 9;
  Control control;

  int result;

  int memory;

  Signal signal;

  Operation* receive_operation;

  int countDigits = 0;
  Operation operation; 

  public:
  CpuAmanda();
  Digit intToDigit(int number, Digit *digit, int *digitLenght, Signal *signal);
  void cancel();
  void reset();
  int calculate();
  int digitToInt(Digit *digit,  int count);
  void setDisplay(DisplayAmanda*);
  void receiveDigit(Digit );
  virtual void receiveOperation(Operation ) = 0;
  virtual void receiveControl(Control ) = 0;
};

class KeyAmanda; 

class KeyboardAmanda: public Keyboard{
  CpuAmanda* cpu;
  KeyAmanda* keys[110];
  int Keycount = 0;
  public:
  void setCpu(CpuAmanda* );
  virtual void addKey(KeyAmanda* ) = 0;
  virtual void receiveDigit(Digit ) = 0;
  virtual void receiveOperation(Operation ) = 0;
  virtual void receiveControl(Control ) = 0;
};

class KeyAmanda : Key{
   protected:
     ReceiverAmanda* receiver;
   public:
     void setReceiver(ReceiverAmanda* );
      virtual void press() = 0;
};

class KeyDigitAmanda: public KeyDigit{
     Digit digit;
   public:
//O CONTRUTOR TEM Q TER MESMO NOME DA CXLASSE
      KeyDigitAmanda(Digit );
      void press();
      void setCpu(Cpu* cpu);
};

class KeyOperationAmanda: public KeyOperation{
   public:
      Operation operation;
      KeyOperationAmanda(Operation );
      void press();
      void setCpu(Cpu* cpu);
};

class KeyControlAmanda: public KeyControl{
     Control control;
  public:
      KeyControlAmanda(Control );
      void press();
};

class CalculatorAmanda : public Calculator{
  CpuAmanda* cpu;
  KeyDigitAmanda *numericKeyBoard;
  KeyOperationAmanda *operationKeyBoard; 
  DisplayAmanda *display;
  public:
  void calculator(CpuAmanda *cpu, DisplayAmanda *display, KeyDigitAmanda     *numericKeyBoard, KeyOperationAmanda *operationKeyBoard);

   void setKeyDigit(KeyDigitAmanda* numericKeyBoard);

    virtual KeyDigitAmanda* getKeyDigit();
    
    void setKeyOperation(KeyOperationAmanda* operationKeyBoard);

    virtual KeyOperationAmanda* getKeyOperation() = 0;

    void setDisplay(DisplayAmanda* display);
    virtual DisplayAmanda* getDisplay() = 0;

    void setCpu(CpuAmanda* cpu);
//implementar
    virtual CpuAmanda* getCpu() = 0;

CalculatorAmanda(CpuAmanda *cpu, DisplayAmanda *display, KeyDigitAmanda *numericKeyBoard, KeyOperationAmanda *operationKeyBoard){};

~CalculatorAmanda();
};     


#endif