/* This is one EZ Series sonia program.
 * This is my first time to do the sonia program.
 * This is the list for this program update.
 * 2017-02-21 This sketch file is to add distance judgement and light the LED when the distance is lower than 30cm
 * 2017-02-22 Add the function of adjusting the led blink frequence base on distance change
 * 2017-02-23 Add distance adjustment to show different result   
*/

long duration,cm;
const int echo = 12;
const int trigger = 8;
int frequence;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  //Read the time of high pulse of sonia

   duration = pulseIn(echo, HIGH);

  //Caculate the centimeter

   cm = duration * 0.1;     //EZ Series accuracy is 1 us/mm.

   frequence = cm * 3;      //the distance longer, the led blink slower

   if(cm > 0 && cm <= 150){

     Serial.print(cm);          //Print cm value on the interface
     Serial.println("cm");
     delay(100); 
    
     ledblink(frequence);  
        }
   else{
     Serial.println("The robot is on safety area!");
     //Serial.print(cm);
     //Serial.println("cm");
     delay(100);
        }
  
}

void ledblink(int frequence){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(frequence);
  digitalWrite(LED_BUILTIN, LOW);
  delay(frequence);
}

