// declaro variable para guardar temp en celcius
float tempC;
//declaro variable para el PIN A0
int pinSensorT=0;
void setup() {
  Serial.begin(9600);
  

}

void loop() {
  
  tempC=analogRead(pinSensorT);
  tempC=(5.0*tempC*100)/1024.0;
  Serial.println(tempC);
  delay(2000);
}
