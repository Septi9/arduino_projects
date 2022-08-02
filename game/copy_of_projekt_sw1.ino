#include <LiquidCrystal.h> 

//-----function for reading distance using an ultrasonic sensor-----

long readUltrasonicDistance(int triggerPin, int echoPin){ 
  pinMode(triggerPin, OUTPUT); 	
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);	
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//-----an array representing the player's symbol-----

byte ufo[8] = {
  0b00000,
  0b00100,
  0b01010,
  0b11111,
  0b11111,
  0b01010,
  0b00100,
  0b00000
};

//-----tan array representing the obstacle symbol-----

byte rock[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

//-----variables used in the program-----

int button;
int counterRock = 15;
int counterRock2 = 23;
int positionFinal;
int positionFinal2;
int counter = 0;

bool diode1;
bool diode2;
bool diode3;
bool diode4;

bool game = true;
bool lose = false;
int playerPosition = 1;

void setup() {
  
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);
  
  
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  
  lcd.createChar(0, ufo);
  lcd.createChar(1, rock);
  lcd.begin(16, 2);	
}

void loop() {
  
  button = digitalRead(9);
  
  //-----code to be executed during the game-----
  if(game){ 
  //-----checking if the calculated distance of the element from the sensor is within the given range-----  
  if(0.01723*readUltrasonicDistance(8,8)>150){ 
    	lcd.setCursor(0,1);
    	lcd.print(" ");
      lcd.setCursor(0,0);
    	lcd.write((byte)0);
      playerPosition = 0;
  }
  
  if(0.01723*readUltrasonicDistance(8,8)<150){
    	lcd.setCursor(0,0);
    	lcd.print(" ");
      	lcd.setCursor(0,1);
    	lcd.write((byte)0);
      	playerPosition = 1;
  } 
    
  int position = random(0,2);
  int position2 = random(0,2);
 

  if(counterRock == 15){
    positionFinal = position;
  }
  	lcd.setCursor(counterRock, positionFinal);
  	lcd.write((byte)1);	
  	lcd.setCursor(counterRock + 1, positionFinal);
  	lcd.print(" ");
  	counterRock--;
    
    if((counterRock == 0)&&((positionFinal) == (playerPosition))){ 
      lose = true;	
      game = false;
    }
  	
  if(counterRock == -2){
    counterRock = 15;
    counter++;
  }
  
   //------the same as before (for the second obstacle)-----
   if(counterRock2 == 15){		
    positionFinal2 = position2; 
  }
   
  	lcd.setCursor(counterRock2, positionFinal2);
  	lcd.write((byte)1);
  	lcd.setCursor(counterRock2 + 1, positionFinal2);
  	lcd.print(" ");
  	counterRock2--;
  
    if((counterRock2 == 0)&&((positionFinal2) == (playerPosition))){
      lose = true;
      game = false;
    }
        
  	delay(300);
  
    if(counterRock2 == -2){ 
    	counterRock2 = 15;
      	counter++;
  	}
    //--------------------------------------------------------------
    
    if(counter == 15){
      lcd.clear();a
      game = false;	
    }
  } else{
    if(lose == true){
      	lcd.setCursor(3,0);
      	lcd.print("GAME OVER!");
      
      	//----displaying the result in binary form by means of diodes----

      	diode4 = (counter % 2) == 1; 
      	diode3 = ((counter >> 1)%2) == 1;
      	diode2 = ((counter >> 2)%2) == 1;
      	diode1 = ((counter >> 3)%2) == 1;
      
      //----lighting of a specific LED----

      if(diode4 == true){ 
        digitalWrite(6, HIGH);
      }
      if(diode3 == true){
        digitalWrite(7, HIGH);
      }
      if(diode2 == true){
        digitalWrite(10, HIGH);
      }
      if(diode1 == true){
        digitalWrite(13, HIGH);
      }
      
    } else{
      	lcd.setCursor(5,0);
    	lcd.print("WINNER");
      
      //----all LEDs on (15 points scored)----

      	digitalWrite(6, HIGH); 
      	digitalWrite(7, HIGH);
      	digitalWrite(10, HIGH);
      	digitalWrite(13, HIGH);
    }
    
    if(button == HIGH){ 
      
      //-----reset of all settings (restart play)-----
      
      lcd.clear();
      game = true;
      lose = false;
      counter = 0;
      counterRock = 15;
      counterRock2 = 23;
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(10, LOW);
      digitalWrite(13, LOW);
    }
  }  
}



