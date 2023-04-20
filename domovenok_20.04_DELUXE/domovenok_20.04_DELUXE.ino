#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
//#include <SoftwareSerial.h>
 // Создать объект программного последовательного порта для связи с SIM900
// Tx и Rx SIM900 подключены к выводам 7 и 8 Arduino
SoftwareSerial mySerial(7, 11);

#define PIN_TRIG 8
#define PIN_ECHO 6
 
long duration, cm;
 
//SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
SoftwareSerial mySoftwareSerial(9, 10); // RX, TX
 
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);
int SEC = 0;
int MIN = 0;
boolean x = true;
boolean y = true;
boolean z = true;
unsigned long timer;
unsigned long timer2;
void setup() {

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

    mySerial.println("  AT+GSN ");
  updateSerial();
  
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
 pinMode(5, INPUT);
  pinMode(7, INPUT);
    pinMode(12, OUTPUT);
    pinMode(14, OUTPUT);
 
Serial.begin(9600);
   timer = millis();
 
      mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
      myDFPlayer.volume(30);  // Установка громкости от 0 до 30
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
 
}
 
  Serial.println(F("DFPlayer Mini online."));
 
}
void loop() {
 
 // Сначала генерируем короткий импульс длительностью 2-5 микросекунд.
 
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);
 
  // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц.
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
 
  //  Время задержки акустического сигнала на эхолокаторе.
  duration = pulseIn(PIN_ECHO, HIGH);
 
  // Теперь осталось преобразовать время в расстояние
  cm = (duration / 2) / 29.1;
 
  Serial.print("Расстояние до объекта: ");
  Serial.print(cm);
  Serial.println(" см.");
   // Задержка между измерениями для корректной работы скеча
  delay(250);
 
   // если прошло 1000 мс - прибавляем одну секунду к переменной SEC
 //  Serial.println(digitalRead(3));
   //delay(50);
 
// delay(2000);
   if (millis() - timer > 1000 && cm > 150 && cm < 650 ) {
      timer = millis();
 
   while(x == true){
 
           myDFPlayer.play(5);
        delay(4000);
        x = false; 
 
           }
         
      
      SEC = SEC + 1;
      if (SEC > 4) { SEC = 0; MIN = MIN + 1; }
      // выводим текущий счетчик времени на монитор порта
      Serial.println(String(MIN) + " : " + String(SEC));
      if (MIN % 3 == 0 && MIN != 0){
              Serial.print("MIN % 3 = " );
              Serial.println(MIN % 3);
 
    //  w = true;
       while(y == true){
           myDFPlayer.play(5);
        delay(4000);
        y = false;      
           }
         }
 
      if (MIN % 6 == 0 && MIN != 0){
          while(z == true){
           myDFPlayer.play(5);
        delay(4000);
        z = false;      
           }
          digitalWrite(14,1);  // выполнить действие 2
          delay(3000);
               //     digitalWrite(14,0);  // выполнить действие 2

          digitalWrite(12,1);  // выполнить действие 2
  Serial.println("Klapan OFF");
                      Serial.print("MIN % 6 = " );
              Serial.println(MIN % 6);
   updateSerial();
  // замените ZZ кодом страны, а xxxxxxxxxxx номером телефона для отправки sms
  mySerial.println("AT+CMGS=\"+375295390886\"");
  updateSerial();
  // текстовый контент
  mySerial.print("STOVE UNATTENDED!!!");
  updateSerial();
  mySerial.write(26);
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
