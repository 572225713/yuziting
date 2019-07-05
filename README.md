# yuziting
>learn arduino
>17050180012 于子婷
---|---|---
1|2019/7/2|yu
2|2019/7/3|yu

## 第一天 入门介绍
- 为什么要学习开源硬件
- 如何学习开源硬件
- 几个常用软件
#### arduino
![](7shumaguan/7.png)
#### fritzing
![](img/frizting.png)
#### proccessing
![](img/processing.png)
- 几个常用网站
## 第二天 软件操作
- Arduino安装
- Arduino文档
- Arduino基本操作
- Arduino类库操作
- 实例：morse代码
'''c
//.cpp
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
'''

.h
'''c
#ifndef _MORSE_H//预编译 
#define _MORSE_H
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
    void c_space();
    void w_space();
  private:
    int _pin;
};
#endif /*_MORSE_H*/
'''
## 第三天 元器件及电路图
- 使用在线模拟网站
- 小车电路图及代码
- 7位译码器使用
- CD4511IC使用
## 第四天 总结
