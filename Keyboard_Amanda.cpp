#include "AmandaCalculator.h"

void KeyboardAmanda::setCpu(CpuAmanda *cpu){
  this->cpu = cpu;
}

void KeyAmanda::setReceiver(ReceiverAmanda* receiver){
  this->receiver = receiver;
}

//void cancel();
//void KeyDigit::press(){ this->receiver->receiveDigit(this->digit);
//}

void KeyControlAmanda::press(){ this->receiver->receiveControl(this->control);
}

void KeyboardAmanda::addKey(KeyAmanda* k){
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