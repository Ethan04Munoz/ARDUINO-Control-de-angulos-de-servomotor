//Servo
#include <Servo.h>
#define pservo 2

//LCD
#include <LiquidCrystal_I2C.h>
//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);  //

//Teclado
#include <Keypad.h>
const byte filas = 4; 
const byte columnas = 4;
byte pinesFilas[]  = {9,8,7,6};
byte pinesColumnas[] = {5,4,3,2};
char teclas[4][4] = {{'1','2','3','A'},
                     {'4','5','6','B'},
                     {'7','8','9','C'},
                     {'*','0','#','D'}};
Keypad teclado1 = Keypad( makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas); 

Servo servo1;
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
