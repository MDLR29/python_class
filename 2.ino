char opcion='1';
int ledrojo=13;
void setup() { Serial.begin(9600);
pinMode(ledrojo,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {if(Serial.available()>0);
{
  opcion=Serial.read();
  if(opcion=='0')
  {Serial.println("menu");
  Serial.println("1.encender led rojo");
  Serial.println("2.apagar led rojo");
    }
    if(opcion=='1')
    {digitalWrite(ledrojo,HIGH);
    }else{
      if(opcion=='2')
      {digitalWrite(ledrojo,LOW);
    }else{
      Serial.println("opcion incorrecta");
    }
    }
}

  // put your main code here, to run repeatedly:
}
