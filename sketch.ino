#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>
#define echoPin 6
#define trigPin 9
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
unsigned long pres_len = 0, rel_time, pres_time = 0, old_time_len = 0, old_pres = 0, space = 0;

LiquidCrystal_I2C lcd(0x27,16,2);

int min_delay = 10;

int sensor = 1;
int state = LOW;
int val = 0;

unsigned long signal_len,t1,t2;
int inputPin = 7;
int ledPin = 10;
int led_Pin = 12;
String code = ""; 
String CODE = "";

Servo myservo;
int pos = 180;
long duration;
int distance;

void setup() {
 lcd.init();
 lcd.backlight();
   pinMode(sensor, INPUT);
  myservo.attach(8);
    lcd.begin(16, 2);
  Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(ledPin,OUTPUT);
  }

void ServoOpen()
{
  for (pos = 180; pos >= 0; pos -= 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void ServoClose()
{
  for (pos = 0; pos <= 180; pos += 5) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}



void loop()
{
  UL :
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance = duration * 0.034 / 2;

if(distance <= 30)
  { lcd.setCursor(3,0);
  lcd.print("WELCOME");
  delay(1000);
  lcd.setCursor(3,0);
  lcd.print("ENTER YOUR");
  lcd.setCursor (5,1);
lcd.print("C O D E");
delay(1000);
lcd.clear();
  }
  else{
    goto UL;
  }
NextDotDash:
  while (digitalRead(inputPin) == HIGH) {}
  t1 = millis();                            //time at button press
  digitalWrite(ledPin, HIGH);               //LED on while button pressed
  while (digitalRead(inputPin) == LOW) {}
  t2 = millis();                            //time at button release
  digitalWrite(ledPin, LOW);                //LED off on button release
  signal_len = t2 - t1;                    //time for which button is pressed
  
  if (signal_len > 50 && distance <= 30)                      //to account for switch debouncing
  {  
    
    code += readio_1();                     //function to read dot or dash
    
  }
  
  CODE = "---.--..-."; //"---.--..-."; // O P E N
  
  while ((millis() - t2) < 500)    //if time between button press greater than 0.5sec, skip loop
  {     
    if (digitalRead(inputPin) == LOW)
    {
      goto NextDotDash;
     
    }
  }
  CODER();
                            
}

String readio_1()
{
  if (signal_len < 600 && signal_len > 50)
  {
   lcd.print(".");
    return ".";                        //if button press less than 0.6sec, it is a dot  
  }
  else if (signal_len > 600)
  {
   lcd.print("-");
    return "-";                       //if button press more than 0.6sec, it is a dash
}
    }

void CODER()
{
 
  int i = 0;
readio_1();
 val = digitalRead(sensor);
 if (code == CODE)          // The declared code =  ---.--..-. - OPEN
 { 
  digitalWrite(led_Pin, HIGH);
  delay(100);
  digitalWrite(led_Pin, LOW);
 lcd.clear();
 lcd.setCursor(6,1);
           lcd.print("OPENED");
           delay(1000);
            lcd.setCursor(5,0);
            lcd.print("WELCOME");
             delay(1000);
               ServoOpen();
         lcd.clear();
       
         delay(1000);
            val = digitalRead(sensor);
            AGAIN :
           if(val = digitalRead(sensor),val == HIGH){
             lcd.print("DETECTED");
             delay(1000);
             lcd.clear();
             delay(2000);
             RECHECK :
             if(val = digitalRead(sensor), val == HIGH){
               lcd.print("WAITING TO CLOSE");
               delay(1000);
               lcd.clear();
               delay(3000);
               goto RECHECK;
             }
             lcd.print("CLOSING");
             delay(1000);
              ServoClose();
               lcd.clear();
       }
       else{
goto AGAIN;
       }   
 }
 
else
{
  lcd.setCursor(3,1);
  lcd.print("WRONG CODE");
  delay(100);
  lcd.clear();
  delay(50);
  lcd.setCursor(3,0);
  lcd.print("TRY AGAIN");
  delay(300);
  lcd.clear();
}
code = "";    
}