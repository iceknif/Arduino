long duration,cm;
const int echo = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  duration = pulseIn(echo, HIGH);

  cm = duration * 0.1;

  Serial.print(cm);
  Serial.println("cm");

  delay(100); 
}
