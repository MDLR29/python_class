int motor=10;
int ledrojo=2;
int ledamarillo=4;
int ledverde=7;
void setup() { pinMode(ledrojo,OUTPUT); pinMode(ledamarillo,OUTPUT); pinMode(ledverde,OUTPUT); pinMode(motor,OUTPUT); 
  // put your setup code here, to run once:

}

void loop() {digitalWrite(ledrojo,HIGH);
delay(500); //tiempo de espera
digitalWrite(ledrojo,LOW);
delay(300);
digitalWrite(ledamarillo,HIGH);
delay(500); //tiempo de espera
digitalWrite(ledamarillo,LOW);
delay(300);
digitalWrite(ledverde,HIGH);
delay(500); //tiempo de espera
digitalWrite(ledverde,LOW);
delay(300);
digitalWrite(motor,HIGH);
  // put your main code here, to run repeatedly:

}
