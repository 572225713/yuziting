//morse.h
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

//.cpp
#include "Arduino.h"
Morse::Morse(int pin)
{
pinMode(pin, OUTPUT);
_pin = pin;
}
void Morse::dot()//摩斯“.”
{
digitalWrite(_pin, HIGH);
delay(250);
digitalWrite(_pin, LOW);
delay(250);
}
void Morse::dash()//摩斯“-”
{
digitalWrite(_pin, HIGH);
delay(1000);
digitalWrite(_pin, LOW);
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
//.ino
#define SIZE 26
//定义摩尔斯电码表
String MORSE[SIZE] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",  //A - I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",//J - R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."        //S - Z 
};
Morse morse(6);

void setup() {
  Serial.begin(9600);//波特率

}

void loop() {
  String str = "";    //保存串口读到的字符串
  String output = "";  //转义后字符串
  int i, t , temp = 0;
  int n = 0;  //对传入字符的个数计数
  while (Serial.available() > 0) {
    temp = 1;  //看是否有数据传入
    str += char(Serial.read());  //将传入的数据保存在字符串中
    delay(1000);  //设定延迟确保传入正常
    n++;
  }

   //查询Morse电码表并进行转换
  if (temp) {
    for (i = 0; i < n; i++)
    {

        //判断是否为小写字母，如果是则转义
        if (str[i] >= 97 && str[i] <= 122)
        {
          output += String(MORSE[int(str[i] - 97)] );
        }
        else output += String(MORSE[int(str[i] - 65)] );

      
    }
    Serial.print(output);  //从串口传入
  }
    for(int j=0;j<output.length()-1;j++)
    {
        if(output[j]==46)
        {
         morse.dot();
       }
        if(output[j]==45)
        {
         morse.dash();
       }
      //morse.c_space();
    }
    delay(3000);
  
}
