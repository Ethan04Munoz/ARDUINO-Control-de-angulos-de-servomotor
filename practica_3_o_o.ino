#include <Servo.h>
#define pservo 2
Servo servo1;
int pulsemin=1000;
int pulsemax=2000;
char angle=200;
void setup() {
  servo1.attach(pservo);
  servo1.write(0);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()==0){
  }
  angle=Serial.read();
  Serial.println(angle);
  switch(angle){
    case '0':
    {
      servo1.write(0);
      break;
    }
    case '1':
    {
      servo1.write(20);
      break;
    }
    case '2':
    {
      servo1.write(40);
      break;
    }
    case '3':
    {
      servo1.write(60);
      break;
    }
    case '4':
    {
      servo1.write(80);
      break;
    }
    case '5':
    {
      servo1.write(100);
      break;
    }
    case '6':
    {
      servo1.write(120);
      break;
    }
    case '7':
    {
      servo1.write(140);
      break;
    }
    case '8':
    {
      servo1.write(160);
      break;
    }
    case '9':
    {
      servo1.write(180);
      break;
    }
  }
}
