//int income=0;
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
 
/*  digitalWrite(4,LOW);
  delay(10);
  digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  delay(10);
  digitalWrite(4,HIGH);
  delay(10);*/
}

void loop()
  {
  int income=0;
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  if(Serial.available()>0)
  {
    delay(10);
    income=Serial.read();
  }
  //income=income-'0';
  Serial.println(income,DEC);
  digitalWrite(6,LOW);
  delay(10);
  digitalWrite(2,income&0x1?HIGH:LOW);
  digitalWrite(3,(income>>1)&0x1?HIGH:LOW);
  digitalWrite(4,(income>>2)&0x1?HIGH:LOW);
  digitalWrite(5,(income>>3)&0x1?HIGH:LOW);
  Serial.println(income&0x1);
  delay(1000);
  digitalWrite(6,HIGH);
  delay(10);
 }
