/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://goo.gl/jtiYJy
*/

const int flexPinT = A0;
const float resistanceT = 47000.0;
const float minimumBendingT = 23000.0;
const float maximumBendingT = 36000.0;
int angleDegreesT;
float flexionT;
String resultSerialT;

void setup() {
  Serial.begin(9600);
  pinMode(flexPinT, INPUT);
}

void loop() {
  flexionT = resistanceT * (5.0 / (analogRead(flexPinT) * 5.0 / 1023.0) - 1.0);
  angleDegreesT = map(flexionT, minimumBendingT, maximumBendingT, 0, 90);
  angleDegreesT = constrain(angleDegreesT, 0, 90);
  resultSerialT = "Sensor a: " + String(angleDegreesT) + " grados";
  Serial.println(resultSerialT);
  delay(300);
}
