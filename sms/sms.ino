/**
#include <SoftwareSerial.h>

// Создать объект программного последовательного порта для связи с SIM900
// Tx и Rx SIM900 подключены к выводам 7 и 8 Arduino
SoftwareSerial mySerial(7, 8);


*/


void setup()
/* proverka raboty
{
  // Начать последовательную связь Arduino и Arduino IDE (монитор последовательного порта)
  Serial.begin(9600);
  
  // Начать последовательную связь Arduino и SIM900
  mySerial.begin(9600);

  Serial.println("Initializing...");
  delay(1000);

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
}
*/

void loop()
{
}

void updateSerial()
{
  delay(500);

  while (Serial.available()) ABABA
>>>>>>> b3c7f5f32192cd81fcacee71fa6f258f7b980cfc
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
