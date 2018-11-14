char serialData;
int pinLed = 13;

void setup(){
  pinMode(pinLed,OUTPUT);
  Serial.begin(9600);
}
void loop() {
 if(Serial.available()>0){
  serialData = Serial.read();
  Serial.print(serialData);

  if(serialData =='1'){
    digitalWrite(pinLed,HIGH);
  } else{
    if(serialData =='0'){
      digitalWrite(pinLed,LOW);
    }
   }
  }
}
