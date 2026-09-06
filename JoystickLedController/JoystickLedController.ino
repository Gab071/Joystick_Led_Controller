#define LedRed 11
#define LedBlue 10
#define LedYellow 9
#define LedGreen
#define X_Pin A1
#define Y_Pin A0
#define SW 2

void setup() {
  Serial.begin(9600);
  pinMode(SW, INPUT);
}

void loop() {
  Serial.print("X:  ");
  Serial.print(analogRead(X_Pin));
  Serial.print("  Y:  ");
  Serial.println(analogRead(Y_Pin));
  delay(250);

}
