char domotica;
#include <Servo.h>
          Servo servoGaraje;//entrada del garaje
#include <LiquidCrystal.h>
          const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
        LiquidCrystal lcd(rs, en, d4, d5, d6, d7);//configuracion de puertos de la pantalla

float tempC;
float tempF;

//asignacion de pines y led`s
int luzCocina = 40;
int luzHabitacion = 32;
int luzEscalera = 30;
int luzGaraje = 42;
int LedRojo = 44;
int LedVerde = 46;
int temperatura = A1;
int luz_disco1 = 38;
int luz_disco2 = 36;
int luzLetrero = 48;
int luzSala = 34;
int Cocina_on=0;
int habitacion_on=0;
int escalera_on=0;
int garaje_on=0;
int todo_on=0;
int servo_on=0;
int letrero_on=0;
int pinServo = 0;
int valorServo =0;
int disco_on=0;


void setup() {
  Serial.begin(9600);//comunicacion serial recibe datos

  //configuracion de pantalla led
  //Definir las dimensiones del LCD (16x2)
  lcd.begin(16,2);


  //configuramos los pines de los led`s, lcd y sensores
  pinMode(LedRojo,OUTPUT);//sensor
  pinMode(LedVerde,OUTPUT);//sensor
  pinMode(luzCocina, OUTPUT);
  pinMode(luzHabitacion, OUTPUT);
  pinMode(luzEscalera, OUTPUT);
  pinMode(luzGaraje, OUTPUT);
  pinMode(luzLetrero,OUTPUT);
  pinMode(luz_disco1,OUTPUT);
  pinMode(luz_disco1,OUTPUT);
  pinMode(luzSala,OUTPUT);
  pinMode(temperatura, INPUT);

// Iniciamos el servo para que empiece a trabajar con el pin 9
  servoGaraje.attach(9);
  servoGaraje.write (0); //posicion abrir
  servoGaraje.write (90); // posicion cerrar
}
 
void loop() {
    //Servo Fotocelda####################
    servoGaraje.write (90);
    valorServo=analogRead (pinServo);
    Serial.println(valorServo);
    digitalWrite (LedRojo,HIGH);
    digitalWrite (LedVerde,LOW);
    if(valorServo < 20){
      servoGaraje.write (0);
      delay(100);
      digitalWrite (LedVerde,HIGH);
      digitalWrite (LedRojo,LOW);
       lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
       lcd.print("puerta del garaje"); //mensaje superior
       lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
       lcd.print (" ABIERTA =0 "); //mensaje inferior }
       {delay(5000);
          lcd.clear();}}
    
    //Temperatura ########################
    tempC = analogRead (A1);
    tempC = (5.0 * tempC * 100) / 1024.0;
    Serial.println (tempC);
    tempF = (tempC * 1.8) + 32;
    lcd.setCursor(2, 0);
    lcd.print("Temperatura");

    lcd.setCursor(0, 1);
    lcd.print(tempC);   //Muestra en la pantalla la temperatura en grados Centígrados
    lcd.print(" C  ");
    lcd.print(tempF);    //Muestra en la pantalla la temperatura en grados Fahrenheit
    lcd.print(" F  ");
    delay (1000);

    //####################################
  
  if(Serial.available()>0) 
   {
    domotica=Serial.read();
    Serial.print(domotica);    
      if (domotica == '1')
      { if(Cocina_on==0)
        { digitalWrite(luzCocina, HIGH);
          lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
          lcd.print("luz de la Cocina"); //mensaje superior
          lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
          lcd.print (" encendida =) "); //mensaje inferior
          {delay(5000);
          lcd.clear();}
          Cocina_on=1;
        }else
        { digitalWrite(luzCocina, LOW);
          lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
          lcd.print("luz de la Cocina"); //mensaje superior
          lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
          lcd.print (" apagada =( "); //mensaje inferior
          {delay(5000);
          lcd.clear();}
          Cocina_on=0;}
      }else{
            if (domotica == '2')
               { if (habitacion_on==0)
                {digitalWrite(luzHabitacion, HIGH);
                 lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                 lcd.print("luz de la Habitacion"); //mensaje superior
                 lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                 lcd.print (" encendida =) "); //mensaje inferior
                 {delay(5000);
                  lcd.clear();}
                 habitacion_on=1;
                }else
                {digitalWrite(luzHabitacion, LOW);
                 lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                 lcd.print("luz de la Habitacion"); //mensaje superior
                 lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                 lcd.print (" apagada =( "); //mensaje inferior
                 {delay(5000);
                  lcd.clear();}
                 habitacion_on=0;
                 }
        }else{ 
              if (domotica == '3')
                 {if (escalera_on==0)
                     {digitalWrite(luzEscalera, HIGH);
                      lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                      lcd.print("luz de la escalera"); //mensaje superior
                      lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                      lcd.print (" encendida =) "); //mensaje inferior
                      {delay(5000);
                       lcd.clear();}
                      escalera_on=1;
                     }else
                     {digitalWrite(luzEscalera, LOW);
                      lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                      lcd.print("luz de la escalera"); //mensaje superior
                      lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                      lcd.print (" apagada =( "); //mensaje inferior
                      {delay(5000);
                       lcd.clear();}
                      escalera_on=0;
                     }
           }else{
               if (domotica == '4')
                  {if(garaje_on==0)
                      {digitalWrite(luzGaraje, HIGH);
                       lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                       lcd.print("luz del Garaje"); //mensaje superior
                       lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                       lcd.print (" encendida =) "); //mensaje inferior
                       {delay(5000);
                        lcd.clear();}
                       garaje_on=1;
                       }else
                       {digitalWrite(luzGaraje, LOW);
                        lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                        lcd.print("luz del Garaje"); //mensaje superior
                        lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                        lcd.print (" apagada =( "); //mensaje inferior
                        {delay(5000);
                         lcd.clear();}
                        garaje_on=0;
                       }
           }else{
                  if (domotica == '5')
                    {if(disco_on==0)
                         {digitalWrite(luz_disco1,HIGH);
                          digitalWrite(luz_disco2,HIGH);
                          lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                          lcd.print("luz de la disco"); //mensaje superior
                          lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                          lcd.print (" encendida =) "); //mensaje inferior
                          {delay(5000);
                          lcd.clear();}
                          disco_on=1;
                          }else
                          {digitalWrite(luz_disco1,LOW);
                          digitalWrite(luz_disco2,LOW);
                          lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                          lcd.print("luz de la disco"); //mensaje superior
                          lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                          lcd.print (" apagada =( "); //mensaje inferior
                          {delay(5000);
                          lcd.clear();}
                          disco_on=0;
                       }
           }else{
               if (domotica == '6')
                  {if(letrero_on==0)
                      {digitalWrite(luzLetrero, HIGH);
                       lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                       lcd.print("  luz Letrero  "); //mensaje superior
                       lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                       lcd.print (" encendida =) "); //mensaje inferior
                       {delay(5000);
                        lcd.clear();}
                       letrero_on=1;
                       }else
                       {digitalWrite(luzLetrero, LOW);
                        lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                        lcd.print("luz Letrero"); //mensaje superior
                        lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                        lcd.print (" apagada =( "); //mensaje inferior
                        {delay(5000);
                        lcd.clear();}
                        letrero_on=0;
                       }
         }else{
              if (domotica == '7')
                 {if(todo_on==0)
                    {digitalWrite(luzCocina,HIGH);
                     digitalWrite(luzHabitacion,HIGH);
                     digitalWrite(luzEscalera,HIGH);
                     digitalWrite(luzGaraje,HIGH);
                     digitalWrite(luzLetrero,HIGH);
                     digitalWrite(luz_disco1,HIGH);
                     digitalWrite(luz_disco2,HIGH);
                     digitalWrite(luzSala,HIGH);
                     lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                     lcd.print("    luces   "); //mensaje superior
                     lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                     lcd.print ("ENCENDIDAS =) "); //mensaje inferior
                     {delay(5000);
                     lcd.clear();}
                     todo_on=1;
                     }else
                     {digitalWrite(luzCocina,LOW);
                      digitalWrite(luzHabitacion,LOW);
                      digitalWrite(luzEscalera,LOW);
                      digitalWrite(luzGaraje,LOW);
                      digitalWrite(luzLetrero,LOW);
                      digitalWrite(luz_disco1,LOW);
                      digitalWrite(luz_disco2,LOW);
                      digitalWrite(luzSala,LOW);
                      lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                      lcd.print("    luces   "); //mensaje superior
                      lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                      lcd.print ("APAGADAS =( "); //mensaje inferior
                      {delay(5000);
                       lcd.clear();}
                      todo_on=0;
                      }
         }else{ 
               if (domotica == '8')
                  {if(servo_on==0)//servo garaje abrir
                      {servoGaraje.write (0);//posicion de servo en abrir
                       lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                       lcd.print("puerta del garaje"); //mensaje superior
                       lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                       lcd.print (" ABIERTA =0 "); //mensaje inferior 
                       digitalWrite (LedVerde,HIGH);
                       digitalWrite (LedRojo,LOW);
                       {delay(5000);
                        lcd.clear();}
                       servo_on=1;
                      }else //servo garaje cerrar
                      {servoGaraje.write (90); // posicion de servo en cerrar
                       lcd.setCursor (0,0);//ubicacion del mensaje en la parte superior
                       lcd.print("Puerta del Garaje"); //mensaje superior
                       lcd.setCursor (0,1);//ubicacion del mensaje en la parte inferior
                       lcd.print (" CERRADA =0 "); //mensaje inferior
                       digitalWrite (LedRojo,HIGH);
                       digitalWrite (LedVerde,LOW);
                       {delay(5000);
                        lcd.clear();}
                       servo_on=0;
                      }
                  }
         }
         }
           }
           }
           }
        }
      }
   }
}
