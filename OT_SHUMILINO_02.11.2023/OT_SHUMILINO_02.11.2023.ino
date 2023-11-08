#include <SoftwareSerial.h>

// Создать объект программного последовательного порта для связи с SIM900
// Tx и Rx SIM900 подключены к выводам 7 и 8 Arduino
SoftwareSerial mySerial(7, 8);
int SEC = 0;
int MIN = 0;
unsigned long timer; 
/////////УСТАНОВКА ФЛАГОВ:
boolean x = true;
boolean y = true;
boolean z = true;
boolean xx = true;
boolean yy = true;
boolean zz = true;
boolean xxx = true;
boolean yyy = true;

void setup()
{
  // Начать последовательную связь Arduino и Arduino IDE (монитор последовательного порта)
  Serial.begin(9600);
  
  // Начать последовательную связь Arduino и SIM900
  mySerial.begin(9600);

  Serial.println("Initializing...");
  delay(1000);

  pinMode(4, INPUT);

  pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
 digitalWrite(3, 1);
}

void loop()
{
      Serial.println("========================");

    Serial.println(analogRead(0));
        Serial.println(analogRead(1));
    Serial.println(analogRead(2));
    Serial.println(analogRead(3));
    Serial.println(analogRead(4));
    Serial.println(analogRead(5));
    Serial.println(analogRead(6));
    Serial.println(analogRead(7));
delay(1000);

  if (millis() - timer > 1000) {
      timer = millis();
      SEC = SEC + 1;
    //  if (SEC > 5) { SEC = 0; MIN = MIN + 1; }
      // выводим текущий счетчик времени на монитор порта
   //   Serial.println(String(MIN) + " : " + String(SEC));

  }

        Serial.println(digitalRead(4));
   
      
 

  if(analogRead(0) > 300){
           SEC = 0;

     if  (SEC <= 4 && x == true){
            
     digitalWrite(3, 1);
    Serial.println(String(SEC));

    digitalWrite(2, 1);
    // Рукопожатие с SIM900
  mySerial.println("AT");
  updateSerial();
  // Настройка текствого режима
  mySerial.println("AT+CMGF=1");
  updateSerial();
  // замените ZZ кодом страны, а xxxxxxxxxxx номером телефона для отправки sms
  mySerial.println("AT+CMGS=\"+375295390886\"");
  updateSerial();
  // текстовый контент
  mySerial.print("analogRead(0) > 300");
  updateSerial();
  mySerial.write(26); 
x = false;
 //digitalWrite(3, 0);
  }
  }

  
      

        if(analogRead(1) > 300){
           SEC = 0;
 

     if  (SEC <= 4 && y == true){
            
     digitalWrite(3, 1);
    Serial.println(String(SEC));

    digitalWrite(2, 1);
    // Рукопожатие с SIM900
  mySerial.println("AT");
  updateSerial();
  // Настройка текствого режима
  mySerial.println("AT+CMGF=1");
  updateSerial();
  // замените ZZ кодом страны, а xxxxxxxxxxx номером телефона для отправки sms
  mySerial.println("AT+CMGS=\"+375295390886\"");
  updateSerial();
  // текстовый контент
  mySerial.print("analogRead(1) > 300");
  updateSerial();
  mySerial.write(26); 
y = false;

 //digitalWrite(3, 0);
  }
  
      }
   
        if(analogRead(2) > 300){
           SEC = 0;
 

     if  (SEC <= 4 && z == true){
            
     digitalWrite(3, 1);
    Serial.println(String(SEC));

    digitalWrite(2, 1);
    // Рукопожатие с SIM900
  mySerial.println("AT");
  updateSerial();
  // Настройка текствого режима
  mySerial.println("AT+CMGF=1");
  updateSerial();
  // замените ZZ кодом страны, а xxxxxxxxxxx номером телефона для отправки sms
  mySerial.println("AT+CMGS=\"+375295390886\"");
  updateSerial();
  // текстовый контент
  mySerial.print("analogRead(2) > 300");
  updateSerial();
  mySerial.write(26); 
z = false;

 //digitalWrite(3, 0);
  }
  
      }


        if(analogRead(3) > 300){ //////////////
           SEC = 0;
 

     if  (SEC <= 4 && yyy == true){
            
     digitalWrite(3, 1);
    Serial.println(String(SEC));

    digitalWrite(2, 1);
    // Рукопожатие с SIM900
  mySerial.println("AT");
  updateSerial();
  // Настройка текствого режима
  mySerial.println("AT+CMGF=1");
  updateSerial();
  // замените ZZ кодом страны, а xxxxxxxxxxx номером телефона для отправки sms
  mySerial.println("AT+CMGS=\"+375295390886\"");
  updateSerial();
  // текстовый контент
  mySerial.print("analogRead(3) > 300");
  updateSerial();
  mySerial.write(26); 
yyy = false;

 //digitalWrite(3, 0);
  }
  
      }

          
      if(analogRead(4) > 300){
           SEC = 0;
 

     if  (SEC <= 4 && xx == true){
            
     digitalWrite(3, 1);
    Serial.println(String(SEC));

    digitalWrite(2, 1);
    // Рукопожатие с SIM900
  mySerial.println("AT");
  updateSerial();
  // Настройка текствого режима
  mySerial.println("AT+CMGF=1");
  updateSerial();
  // замените ZZ кодом страны, а xxxxxxxxxxx номером телефона для отправки sms
  mySerial.println("AT+CMGS=\"+375295390886\"");
  updateSerial();
  // текстовый контент
  mySerial.print("analogRead(4) > 300");
  updateSerial();
  mySerial.write(26); 
xx = false;

 //digitalWrite(3, 0);
  }
  
      }    

    if(analogRead(5) > 300){
           SEC = 0;
 

     if  (SEC <= 4 && yy == true){
            
     digitalWrite(3, 1);
    Serial.println(String(SEC));

    digitalWrite(2, 1);
    // Рукопожатие с SIM900
  mySerial.println("AT");
  updateSerial();
  // Настройка текствого режима
  mySerial.println("AT+CMGF=1");
  updateSerial();
  // замените ZZ кодом страны, а xxxxxxxxxxx номером телефона для отправки sms
  mySerial.println("AT+CMGS=\"+375295390886\"");
  updateSerial();
  // текстовый контент
  mySerial.print("analogRead(5) > 300");
  updateSerial();
  mySerial.write(26); 
yy = false;

 //digitalWrite(3, 0);
  }
  
      }

              if(analogRead(6) > 300){
           SEC = 0;
 

     if  (SEC <= 4 && zz == true){
            
     digitalWrite(3, 1);
    Serial.println(String(SEC));

    digitalWrite(2, 1);
    // Рукопожатие с SIM900
  mySerial.println("AT");
  updateSerial();
  // Настройка текствого режима
  mySerial.println("AT+CMGF=1");
  updateSerial();
  // замените ZZ кодом страны, а xxxxxxxxxxx номером телефона для отправки sms
  mySerial.println("AT+CMGS=\"+375295390886\"");
  updateSerial();
  // текстовый контент
  mySerial.print("analogRead(6) > 300");
  updateSerial();
  mySerial.write(26); 
zz = false;

 //digitalWrite(3, 0);
  }
  
      }

    if(analogRead(7) > 300){
           SEC = 0;
 

     if  (SEC <= 4 && xxx == true){
            
     digitalWrite(3, 1);
    Serial.println(String(SEC));

    digitalWrite(2, 1);
    // Рукопожатие с SIM900
  mySerial.println("AT");
  updateSerial();
  // Настройка текствого режима
  mySerial.println("AT+CMGF=1");
  updateSerial();
  // замените ZZ кодом страны, а xxxxxxxxxxx номером телефона для отправки sms
  mySerial.println("AT+CMGS=\"+375295390886\"");
  updateSerial();
  // текстовый контент
  mySerial.print("analogRead(7) > 300");
  updateSerial();
  mySerial.write(26); 
xxx = false;

 //digitalWrite(3, 0);
  }
  
      }




}



void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    // Пересылка того, что было получено с аппаратного последовательного порта, 
    // на программный последовательный порт
    mySerial.write(Serial.read());
  }
  while(mySerial.available()) 
  {
    // Пересылка того, что было получено с программного последовательного порта, 
    // на аппаратный последовательный порт
    Serial.write(mySerial.read());
  }
}
