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

  if(X >= neutralX)
  {
    ledR = 0;
    ledG = map(X, neutralX, 1023, 0, 255);
  }
  else
  {
    ledG = 0;
    ledR = map(X, neutralX, 0, 0, 255);
  }

  if(Y >= neutralY)
  {
    ledB = 0;
    ledY = map(Y, neutralY, 1023, 0, 255);
  }
  else
  {
    ledY = 0;
    ledB = map(Y, neutralY, 0, 0, 255);
  }

  analogWrite(LedRed, ledR);
  analogWrite(LedBlue, ledB);
  analogWrite(LedGreen, ledG);
  analogWrite(LedYellow, ledY);
}
