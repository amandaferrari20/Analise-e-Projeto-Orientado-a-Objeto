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
     void setDecimalSeparator();
     void setSignal(Signal );
     void clear();
};

class ReceiverAmanda: Receiver{
  public:
     void receiveDigit(Digit );
     void receiveOperation(Operation );
     void receiveControl(Control );

};

class CpuAmanda: public Cpu{
  DisplayAmanda* display;
  Digit *operandOne;
  Digit *digit;
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
  Digit intToDigit(int number, int *digitLenght, Signal *signal);
  void cancel();
  void reset();
  Digit calculate();
  int digitToInt(Digit *digit,  int count);
  void setDisplay(DisplayAmanda*);
  void receiveDigit(Digit );
   void receiveOperation(Operation );
   void receiveControl(Control );
};

// class Key; 

class KeyboardAmanda: public Keyboard{
  Cpu* cpu;
  Key* keys[110];
  int Keycount = 0;
  public:
  void setCpu(Cpu* );
  void addKey(Key* );
  void receiveDigit(Digit );
  void receiveOperation(Operation );
  void receiveControl(Control );
};

// class Key{
//    protected:
//      Receiver* receiver;
//    public:
//     //  void setReceiver(Receiver* );
//        void press();
// };

// class KeyDigit: public Key{
//      Digit digit;
//    public:
//       // KeyDigit(Digit );
//       void press();
//       // void setCpu(Cpu* cpu);
// };

// class KeyOperation{
//    public:
//       Operation operation;
//       // KeyOperation(Operation );
//       void press();
//       // void setCpu(Cpu* cpu);
// };

// class KeyControlAmanda: public KeyControl{
//      Control control;
//   public:
//       // KeyControlAmanda(Control );
//       void press();
// };

class CalculatorAmanda : public Calculator{
  Cpu* cpu;
  // KeyDigit *KeyBoard;
  // KeyOperation *operationKeyBoard; 
  Display *display;
  Keyboard* keyBoard;

  public:
  // void calculator(Cpu *cpu, Display *display, Keyboard *keyBoard);
  CalculatorAmanda(Cpu *cpu, Display *display, Keyboard *keyBoard);
  //  void setKeyDigit(KeyDigit* numericKeyBoard);

    KeyDigit* getKeyDigit();
    
    // void setKeyOperation(KeyOperation* operationKeyBoard);
    // KeyOperation* getKeyOperation();

    void setDisplay(Display* display);
    Display* getDisplay();

    void setCpu(Cpu* cpu);

    Cpu* getCpu();

    void setKeyboard(Keyboard* );

// estava dando erro CalculatorAmanda(Cpu *cpu, Display *display, KeyDigit *keydigit, KeyOperation *operationKeyBoard){};

~CalculatorAmanda();
};     


#endif