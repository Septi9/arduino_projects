// function for reading distances with an ultrasonic sensor

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

void setup()
{
  pinMode(11, INPUT);	
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  
  pinMode(2, OUTPUT);	
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  pinMode(A0, OUTPUT);
}

// checking if the calculated distance of the element from the sensor is within the given range
void loop()
{	
  if((0.01723 * readUltrasonicDistance(11,11) > 250)||
     (0.01723 * readUltrasonicDistance(12,12) > 250)||
     (0.01723 * readUltrasonicDistance(13,13) > 250)) {
    	digitalWrite(6, HIGH);
    	tone(A0, 800, 100);
  } else {
      	digitalWrite(6, LOW);
    }
  
// checking if the calculated distance of the element from the sensor is within the given range
   if(((0.01723 * readUltrasonicDistance(11,11) < 250)||
      (0.01723 * readUltrasonicDistance(12,12) < 250)||
      (0.01723 * readUltrasonicDistance(13,13) < 250))&&
      ((0.01723 * readUltrasonicDistance(11,11) > 200)||
      (0.01723 * readUltrasonicDistance(12,12) > 200)||
      (0.01723 * readUltrasonicDistance(13,13) > 200))) {
     
    	digitalWrite(5, HIGH);
     	tone(A0, 800, 30);
  } else {
      	digitalWrite(5, LOW);
    }
  
// checking if the calculated distance of the element from the sensor is within the given range
   if(((0.01723 * readUltrasonicDistance(11,11) < 200)||
      (0.01723 * readUltrasonicDistance(12,12) < 200)||
      (0.01723 * readUltrasonicDistance(13,13) < 200))&& 
      ((0.01723 * readUltrasonicDistance(11,11) > 100)||
      (0.01723 * readUltrasonicDistance(12,12) > 100)||
      (0.01723 * readUltrasonicDistance(13,13) > 100))){
     
    	digitalWrite(4, HIGH);
     	tone(A0, 800, 20);
  } else {
      	digitalWrite(4, LOW);
    }
  
// checking if the calculated distance of the element from the sensor is within the given range
   if(((0.01723 * readUltrasonicDistance(11,11) < 100)||
      (0.01723 * readUltrasonicDistance(12,12) < 100)||
      (0.01723 * readUltrasonicDistance(13,13) < 100))&&
     ((0.01723 * readUltrasonicDistance(11,11) > 50)||
      (0.01723 * readUltrasonicDistance(12,12) > 50)||
      (0.01723 * readUltrasonicDistance(13,13) > 50))){
     
    	digitalWrite(3, HIGH);
     	tone(A0, 800, 10);
  } else {
      	digitalWrite(3, LOW);
    }
  
// checking if the calculated distance of the element from the sensor is within the given range
   if((0.01723 * readUltrasonicDistance(11,11) < 50)||
      (0.01723 * readUltrasonicDistance(12,12) < 50)||
      (0.01723 * readUltrasonicDistance(13,13) < 50)) {
    	digitalWrite(2, HIGH);
     	tone(A0, 800, 0);
  } else {
      	digitalWrite(2, LOW);
    }
  }
