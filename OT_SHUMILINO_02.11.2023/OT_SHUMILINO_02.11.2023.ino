#include <SoftwareSerial.h>

// Создать объект программного последовательного порта для связи с SIM900
// Tx и Rx SIM900 подключены к выводам 7 и 8 Arduino
SoftwareSerial mySerial(7, 8);
int SEC = 0;
int MIN = 0;
unsigned long timer; 

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

}

void loop()
{

  if (millis() - timer > 1000) {
      timer = millis();
      SEC = SEC + 1;
    //  if (SEC > 5) { SEC = 0; MIN = MIN + 1; }
      // выводим текущий счетчик времени на монитор порта
   //   Serial.println(String(MIN) + " : " + String(SEC));

  }

        Serial.println(digitalRead(4));
   
        if(digitalRead(4)==1){
           SEC = 0;
 
     if  (SEC <= 4){
            
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
  mySerial.print("Last Minute Engineers | lastminuteengineers.com");
  updateSerial();
  mySerial.write(26); 

 //digitalWrite(3, 0);
  }
      }    
      
 // digitalWrite(3, 0);
    
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