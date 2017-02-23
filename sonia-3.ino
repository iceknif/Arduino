/* This sketch file is to add distance judgement and light the 
   LED when the distance is lower than 30cm */
/* Add the function of adjusting the led blink frequence 
   base on distance change */

long duration,cm;
const int echo = 12;
int frequence;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  //Read the time of high pulse of sonia
  
  duration = pulseIn(echo, HIGH);

  cm = duration * 0.1;     //EZ Series accuracy is 1 us/mm.

  Serial.print(cm);
  Serial.println("cm");
  delay(100); 

  frequence = cm * 3;      //the distance longer, the led blink slower

  ledblink(frequence);
}

void ledblink(int frequence){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(frequence);
  digitalWrite(LED_BUILTIN, LOW);
  delay(frequence);
}

