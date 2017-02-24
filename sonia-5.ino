// Use AN to detect the distance Method 2

// Connect pin3(Analog Voltage Output) to A5

int voltage_value_read;
float voltage_value_actual,cm;
const int vcc = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // Get the analog value on A05:
  voltage_value_read = analogRead(5);
  //Serial.print("The read value is ");
  //Serial.println(voltage_value_read);
  //delay(500);

  //Get the actual value of voltage on A05
  voltage_value_actual = (vcc / 1024.00000) * voltage_value_read;
  Serial.print("The actual voltage is ");
  Serial.print(voltage_value_actual);
  Serial.println("V");
  delay(500);

  //Caculate the distance
  //For users of this output that desire to work in voltage, a 5V power supply yields~4.88mV per 5 mm. Output voltage range
  //when powered with 5V is 293mV for 300-mm, and 4.885V for 5000-mm.
  cm = ((5 * voltage_value_actual) / 4.88) * 100;
  Serial.print("The distance is ");
  Serial.print(cm);
  Serial.println("cm");
  delay(500);
}
