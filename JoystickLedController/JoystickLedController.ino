#define LedLeft 11
#define LedUpper 10
#define LedLower 9
#define LedSw 7
#define ledLeftight 6
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

  pinMode(LedLeft, OUTPUT);
  pinMode(ledUplue, OUTPUT);
  pinMode(LedLower, OUTPUT);
  pinMode(ledLeftight, OUTPUT);
  pinMode(LedSw, OUTPUT);
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
  static int ledLeft = 0;
  static int ledUp = 0;
  static int ledLow = 0;
  static int ledRight = 0;

  SetLedState(X, neutralX, ledRight, ledLeft);
  SetLedState(Y, neutralY, ledLow, ledUp);

  (Switch == LOW) ? digitalWrite(LedSw, HIGH) : digitalWrite(LedSw, LOW);

  analogWrite(LedLeft, ledLeft);
  analogWrite(ledUplue, ledUp);
  analogWrite(ledLeftight, ledRight);
  analogWrite(LedLower, ledLow);
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
