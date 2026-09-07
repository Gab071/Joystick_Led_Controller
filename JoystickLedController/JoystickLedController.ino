#define LedRed 11
#define LedBlue 10
#define LedYellow 9
#define LedGreen 6
#define XPin A1
#define YPin A0
#define SW 2

int ledR = 0;
int ledB = 0;
int ledY = 0;
int ledG = 0;
int neutralX = 0;
int neutralY = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SW, INPUT);
  pinMode(LedRed, OUTPUT);
  pinMode(LedBlue, OUTPUT);
  pinMode(LedYellow, OUTPUT);
  pinMode(LedGreen, OUTPUT);

  neutralX = analogRead(XPin);
  neutralY = analogRead(YPin);
}

void loop() {
  int X = analogRead(XPin);
  int Y = analogRead(YPin);

  SetLedState(X, neutralX, ledG, ledR);
  SetLedState(Y, neutralY, ledY, ledB);

  analogWrite(LedRed, ledR);
  analogWrite(LedBlue, ledB);
  analogWrite(LedGreen, ledG);
  analogWrite(LedYellow, ledY);
}

void SetLedState(int coordinate, int neutral, int &led1, int &led2)
{
  if(coordinate >= neutral)
  {
    led2 = 0;
    led1 = map(coordinate, neutral, 1023, 0, 255);
  }
  else
  {
    led1 = 0;
    led2 = map(coordinate, neutral, 0, 0, 255);
  }
}
