#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)//构造法 
{
	pinMode(pin,OUTPUT);//配置为输出 
	_pin=pin;//把pin传给_pin 
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(250);
	digitalWrite(_pin,LOW);
	delay(250);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(1000);
	digitalWrite(_pin,LOW);
	delay(250);
}
void Morse::c_space()//字符间隔 
{
	digitalWrite(_pin,LOW);
	delay(250*3);
}
void Morse::w_space()//单词间隔 
{
	digitalWrite(_pin,LOW);
	delay(250*7);
}
