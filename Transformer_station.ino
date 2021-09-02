/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
const int touchPin1 = 2;     // the number of the pushbutton pin
const int ledPin1 =  15;      // the number of the LED pin
const int touchPin2 = 7;     // the number of the pushbutton pin
const int ledPin2 =  16;      // the number of the LED pin
const int touchPin3 = 8;     // the number of the pushbutton pin
const int ledPin3 =  17;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

unsigned int maybe = 0;
unsigned int count_on1 =0;
unsigned int irandomness = 30;
unsigned int spark_on1 = 0;

unsigned int count_on2 =0;
unsigned int spark_on2 = 0;
unsigned int count_on3 =0;
unsigned int spark_on3 = 0;

unsigned int counter = 0;

void sparklight1(bool start) {
  if (start == true || count_on1 > 0 ) {
      if (start == true) {  
          count_on1 =  1000 +random(2000);
      }

      // Count_on will be always > 0 at this point
      count_on1--;
      if (count_on1 == 0) {
        digitalWrite(ledPin1, LOW);
        spark_on1 = 0;
        return;
      }
      
      int spark = random(15);
      if (spark > 12 && spark_on1 < 3) {
        digitalWrite(ledPin1, HIGH);        
        spark_on1++;
      } else {
        digitalWrite(ledPin1, LOW);        
        spark_on1 = 0;
      } 
  }    
}

void sparklight2(bool start) {
  if (start == true || count_on2 > 0 ) {
      if (start == true) {  
          count_on2 =  1000 +random(2000);
      }

      // Count_on will be always > 0 at this point
      count_on2--;
      if (count_on2 == 0) {
        digitalWrite(ledPin2, LOW);
        spark_on2 = 0;
        return;
      }
      
      int spark = random(15);
      if (spark > 12 && spark_on2 < 3) {
        digitalWrite(ledPin2, HIGH);        
        spark_on2++;
      } else {
        digitalWrite(ledPin2, LOW);        
        spark_on2 = 0;
      } 
  }    
}

void sparklight3(bool start) {
  if (start == true || count_on3 > 0 ) {
      if (start == true) {  
          count_on3 =  1000 +random(2000);
      }

      // Count_on will be always > 0 at this point
      count_on3--;
      if (count_on3 == 0) {
        digitalWrite(ledPin3, LOW);
        spark_on3 = 0;
        return;
      }
      
      int spark = random(15);
      if (spark > 12 && spark_on3 < 3) {
        digitalWrite(ledPin3, HIGH);        
        spark_on3++;
      } else {
        digitalWrite(ledPin3, LOW);        
        spark_on3 = 0;
      } 
  }    
}

void sparklights(bool start, bool all) {
  if (start == true || count_on1 > 0  || count_on2 > 0   || count_on3 > 0 ) {
      bool start_rand = (all || (start && (random(15) > 10)) );
      sparklight1(start_rand);
      start_rand = (all || (start && (random(15) > 10)) );
      sparklight2(start_rand);
      start_rand = (all || (start && (random(15) > 10)) );
      sparklight3(start_rand);
  }    
}

void setup() {
  randomSeed(analogRead(0));
  
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(touchPin1, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(touchPin2, INPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(touchPin3, INPUT);

  sparklights(true, true);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(touchPin1);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    sparklight1(true);
  }

  buttonState = digitalRead(touchPin2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    sparklight2(true);
  }

  buttonState = digitalRead(touchPin3);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    sparklight3(true);
  }    

  // Random start the effect
  if (counter++ == 4096) {
    counter = 0;      
    maybe = random(1024);      
  }
  
  sparklights( (maybe == irandomness), false );
  maybe = 0;
}
