void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
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
  Serial.println(income,DEC);
  pinMode(8, LOW);
  pinMode(9, LOW);
  pinMode(10, LOW);
  pinMode(11, LOW);
  delay(10);
  digitalWrite(2,income&0x1?HIGH:LOW);
  digitalWrite(3,(income>>1)&0x1?HIGH:LOW);
  digitalWrite(4,(income>>2)&0x1?HIGH:LOW);
  digitalWrite(5,(income>>3)&0x1?HIGH:LOW);
  Serial.println(income&0x1);
  delay(1000);
  pinMode(8, HIGH);
  pinMode(9, HIGH);
  pinMode(10, HIGH);
  pinMode(11, HIGH);
  delay(10);
 }
