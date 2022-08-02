#include <LiquidCrystal.h>				

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte degree[8] = {
  0b00000,
  0b01000,
  0b10100,
  0b01000,
  0b00000,
  0b00000,
  0b00000, 
  0b00000 
};

int button;
int var;
int varMaximum;
float tempMaximum;

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, degree);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, INPUT);
}

void loop() {
  var = analogRead(A0);
  button = digitalRead(10);
  
  float temp = (((analogRead(A1) * 5.0)/1024)-0.5)/0.01;

  if(var > varMaximum){
    varMaximum = var;
  } else if(temp > tempMaximum){
    tempMaximum = temp;
  }
  
  if(button == HIGH){
    varMaximum = var;
    tempMaximum = temp;
  }
  
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print(var);
  lcd.print("V");
  lcd.setCursor(0,1);
  lcd.print(varMaximum);
  lcd.print("V");	
  
  lcd.setCursor(9,0);	
  lcd.print(temp);
  lcd.write((byte)0);
  lcd.print("C");
  
  lcd.setCursor(9,1);
  lcd.print(tempMaximum);
  lcd.write((byte)0);
  lcd.print("C");
  
  delay(200);
  
}
 