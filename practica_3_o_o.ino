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
byte pinesFilas[]  = {10,9,8,7};
byte pinesColumnas[] = {6,5,4,3};
char teclas[4][4] = {{'1','2','3','A'},
                     {'4','5','6','B'},
                     {'7','8','9','C'},
                     {'*','0','#','D'}};
Keypad teclado1 = Keypad( makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas); 

Servo servo1;
//char angle=200;
void setup() {
  servo1.attach(pservo);
  servo1.write(0);
  Serial.begin(9600);
  // Inicializar el LCD
  lcd.init();
  //Encender la luz de fondo.
  lcd.backlight();
}

void loop() {
  lcd.print("Ingresa el ang");
  lcd.setCursor(0,1);
  lcd.print("ulo: ");
  char angle = teclado1.getKey();
  while(angle == NO_KEY)
  {
    angle = teclado1.getKey();
    delay(100); 
  }
  lcd.print(angle);
  lcd.clear();
  switch(angle){
    case '0':
    {
      lcd.setCursor(0,0);
      lcd.print("Angulo 0: 0 grados");
      servo1.write(0);
      break;
    }
    case '1':
    {
      lcd.setCursor(0,0);
      lcd.print("Angulo 1: 20 grados");
      servo1.write(20);
      break;
    }
    case '2':
    {
      lcd.setCursor(0,0);
      lcd.print("Angulo 2: 40 grados");
      servo1.write(40);
      break;
    }
    case '3':
    {
      lcd.setCursor(0,0);
      lcd.print("Angulo 3: 60 grados");
      servo1.write(60);
      break;
    }
    case '4':
    {      
      lcd.setCursor(0,0);
      lcd.print("Angulo 4: 80 grados");
      servo1.write(80);
      break;
    }
    case '5':
    {      
      lcd.setCursor(0,0);
      lcd.print("Angulo 5: 100 grados");
      servo1.write(100);
      break;
    }
    case '6':
    {      
      lcd.setCursor(0,0);
      lcd.print("Angulo 6: 120 grados");
      servo1.write(120);
      break;
    }
    case '7':
    {
      lcd.setCursor(0,0);
      lcd.print("Angulo 7: 140 grados");
      servo1.write(140);
      break;
    }
    case '8':
    {      
      lcd.setCursor(0,0);
      lcd.print("Angulo 8: 160 grados");
      servo1.write(160);
      break;
    }
    case '9':
    {
      lcd.setCursor(0,0);
      lcd.print("Angulo 9: 180 grados");
      servo1.write(180);
      break;
    }
    
  }
  delay(3500);
  lcd.clear();
  lcd.setCursor(0,0);
}
