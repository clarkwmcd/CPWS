
int moisturePin = A1; //pin A1 that reads moisture sensor
int moisturePower = 4; //pin D7 that turns on the moisture sensor
int moistureValue = 0; //variable for moisture value

void setup() {
  Serial.begin(9600); //open serial over USB
  pinMode(moisturePower, OUTPUT); //set sensor power pin as an output
  digitalWrite(moisturePower, LOW); //set to LOW so sensor is not powered on start up
}

void loop() {
  Serial.print("Soil Moisture = ");
  Serial.println(readMoisture()); //get soil moisture value from the function and print it
  delay(1000); //take a reading every second
}

int readMoisture() {
  digitalWrite(moisturePower, HIGH); //turn sensor ON
  delay(1000); //wait one second
  moistureValue = analogRead(moisturePin); //Read the SIG (signal) value from the sensor
  digitalWrite(moisturePower, LOW); //turn sensor OFF
  return moistureValue; //send current moisture value
}
