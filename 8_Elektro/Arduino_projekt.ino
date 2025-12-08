int xPin = A0;
int yPin = A1;
int buttonPin = 2;

int yVal;
int xVal;
int buttonState;

int upLed = 10;
int downLed = 9;
int leftLed = 11;
int rightLed = 6;
int upBrightness = 0;
int downBrightness = 0;
int leftBrightness = 0;
int rightBrightness = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(upLed, OUTPUT);
  pinMode(downLed, OUTPUT);
  pinMode(leftLed, OUTPUT);
  pinMode(rightLed, OUTPUT); 
}

void loop() {
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  buttonState = digitalRead(buttonPin);

  upBrightness = map(yVal, 506, 0, 0, 255);
  downBrightness = map(yVal, 506, 1023, 0, 255);
  leftBrightness = map(xVal, 508, 0, 0, 255);
  rightBrightness = map(xVal, 508, 1023, 0, 255);

  if (yVal <= 506){
    analogWrite(upLed, upBrightness);
  }

  if (yVal >= 506){
    analogWrite(downLed, downBrightness);
  }

  if (xVal <= 508){
    analogWrite(leftLed, leftBrightness);
  }

  if (xVal >= 508){
    analogWrite(rightLed, rightBrightness);
  }

  if (buttonState == LOW) {
    digitalWrite(upLed, HIGH);
    digitalWrite(downLed, HIGH);
    digitalWrite(leftLed, HIGH);
    digitalWrite(rightLed, HIGH);
  }
  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" | Y: ");
  Serial.print(yVal);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

  delay(100);
}
