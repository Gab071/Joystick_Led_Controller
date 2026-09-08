#define LedRed 11
#define LedBlue 10
#define LedYellow 9
#define LedWhite 7
#define LedGreen 6
#define XPin A1
#define YPin A0
#define SW 2

void SetLedState(int coordinate, int neutral, int &led1, int &led2);

// variable is preventing Led's from flickering
// when joystick is in "resting" position (not moved)
const int deadZone = 20; 

void setup() 
{
  Serial.begin(9600); // for debugging purposes
  pinMode(SW, INPUT_PULLUP); // switch connected just in case

  pinMode(LedRed, OUTPUT);
  pinMode(LedBlue, OUTPUT);
  pinMode(LedYellow, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  pinMode(LedWhite, OUTPUT);
}

void loop() 
{
  // Variables are initialized with joystick's "resting" position (not moved)
  static const int neutralX = analogRead(XPin);
  static const int neutralY = analogRead(YPin);

  int X = analogRead(XPin);
  int Y = analogRead(YPin);
  int Switch = digitalRead(SW);

  // Variables that store LED's state 
  static int ledR = 0;
  static int ledB = 0;
  static int ledY = 0;
  static int ledG = 0;

  SetLedState(X, neutralX, ledG, ledR);
  SetLedState(Y, neutralY, ledY, ledB);

  (Switch == LOW) ? digitalWrite(LedWhite, HIGH) : digitalWrite(LedWhite, LOW);

  analogWrite(LedRed, ledR);
  analogWrite(LedBlue, ledB);
  analogWrite(LedGreen, ledG);
  analogWrite(LedYellow, ledY);
}

// Function assigns for the LED's corresponding states depending on joystick position
// led1 is the variable of the LED's state that gives bigger value when the joystick gives bigger value than neutral
// led2 is the variable of the LED's state that gives bigger value when the joystick gives lesser value than neutral
void SetLedState(int coordinate, int neutral, int &led1, int &led2)
{
  if(coordinate >= neutral + deadZone)
  {
    led2 = 0;
    led1 = map(coordinate, neutral, 1023, 0, 255);
  }
  else if(coordinate <= neutral - deadZone)
  {
    led1 = 0;
    led2 = map(coordinate, neutral, 0, 0, 255);
  }
  else
  {
    led1 = 0;
    led2 = 0;
  }
}
