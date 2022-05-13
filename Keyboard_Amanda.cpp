#include "AmandaCalculator.h"

// void Keyboard::setCpu(Cpu *cpu){
//   this->cpu = cpu;
// }

// void Key::setReceiver(Receiver* receiver){
//   this->receiver = receiver;
// }

//void cancel();
//void KeyDigit::press(){ this->receiver->receiveDigit(this->digit);
//}



void KeyboardAmanda::addKey(Key* k){
  if(this->Keycount < 110){
    this->keys[this->Keycount++] = k;
		k->setReceiver(this);
  }
}

void KeyboardAmanda::receiveDigit(Digit d)
{
	this->cpu->receiveDigit(d);
}


void KeyboardAmanda::receiveOperation(Operation op)
{
	this->cpu->receiveOperation(op);
}


void KeyboardAmanda::receiveControl(Control c)
{
	this->cpu->receiveControl(c);
}