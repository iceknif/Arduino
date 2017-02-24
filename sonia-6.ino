// Use AN to detect the distance Method 1

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

  //Get the actual value of voltage on A05
  //Method 1
  //This pin outputs an analog voltage scaled representation of the distance with a scale factor of (Vcc/1024) per 5-mm.
  //Using a 10bit analog to digital convertor, one can read the analog voltage bits (i.e. 0 to 1023) directly and just multiply the
  //number of bits in the value by 5 to yield the range in mm. For example, 60 bits corresponds to 300-mm (where 60 * 5 =
  //300), and 1000 bits corresponds to 5000-mm (where 1000 * 5 = 5000-mm).
  
  cm = voltage_value_read * 5 * 0.1;

  Serial.print("The distance is ");
  Serial.print(cm);
  Serial.println("cm");
  delay(500);
}
