/* This sketch file is to add distance judgement and light the 
   LED when the distance is lower than 30cm */

long duration,cm;
const int echo = 12;
//const int LED = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  duration = pulseIn(echo, HIGH);

  cm = duration * 0.1;

  Serial.print(cm);
  Serial.println("cm");
  delay(100); 

  if (cm <= 30){
    ledblink();

  }
}

void ledblink(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

