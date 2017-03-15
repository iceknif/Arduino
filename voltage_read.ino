int voltage_detectPin = 0;
float voltage_analog = 0.00;
float voltage_actual = 0.00;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltage_analog = analogRead(voltage_detectPin);
  //Serial.print("The voltage_analog value is ");
  //Serial.println(voltage_analog);
  delay(500);
  voltage_actual = (voltage_analog / 1024.00) * 5.00;
  Serial.print("The actual voltage value is ");
  Serial.println(voltage_actual);
  delay(500);
}
