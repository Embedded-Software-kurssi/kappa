

 #define BIT8 128
 #define BIT7 64
 #define BIT6 32
 #define BIT5 16
 #define BIT4 8
 #define BIT3 4
 #define BIT2 2
 #define BIT1 1


 unsigned char numbers[10] = {
   254, // 0
   176, // 1
   237, // 2
   249, // 3
   179, // 4
   219, // 5
   159, // 6
   240, // 7
   255, // 8
   243, // 9
 };
 
int joyStickX = A0;
int joyStickY = A1;
int joyStickZ = 3;
int motorPin = 11;

int redLed = 13;
int greenLed = 12;
int blueLed = 11;

int blueSection = 20;
int greenSection = 100;
int redSection = 255;

int xZero = 517;
int xRatio = 517/256;
int yZero = 508;

void setup() {
  pinMode (joyStickX, INPUT);
  pinMode (joyStickY, INPUT);
  pinMode (joyStickZ, INPUT_PULLUP);
  pinMode(motorPin, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  Serial.begin (9600); // 9600 bps
} 

void loop() {
  int x, y, z;
  x = analogRead(joyStickX);
  y = analogRead(joyStickY);
  z = digitalRead(joyStickZ);
  int speed = (abs(x-xZero)+4)/xRatio;
  if (speed > 255) speed = 255;
  float s = speed*9/255;l

  showNumber(s);

  if (speed < blueSection) {
    digitalWrite(blueLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
  } else if (speed < 255) {
    digitalWrite(blueLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);   
  } else {
    digitalWrite(blueLed, LOW);
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);      
  }
  

  delay(100);
}

void showNumber(char c) {
     bitAction(BIT7 & numbers[c], 4);
     bitAction(BIT6 & numbers[c], 5);
     bitAction(BIT5 & numbers[c], 6);
     bitAction(BIT4 & numbers[c], 7);
     bitAction(BIT3 & numbers[c], 8);
     bitAction(BIT2 & numbers[c], 9);
     bitAction(BIT1 & numbers[c], 10);
}

 void bitAction(char b, char pin) {
   if (!b) {
     digitalWrite(pin, HIGH);
   }
   else {
     digitalWrite(pin, LOW);
   }
 }
