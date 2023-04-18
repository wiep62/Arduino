
int SEC = 0;
int MIN = 0;
unsigned long timer;
void setup() {

    pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);

Serial.begin(9600);
   timer = millis();

}

void loop() {
   // если прошло 1000 мс - прибавляем одну секунду к переменной SEC
 //  Serial.println(digitalRead(3));
   //delay(50);
   if (millis() - timer > 1000 && digitalRead(3) == 1 ) {
      timer = millis();
      SEC = SEC + 1;
      if (SEC > 9) { SEC = 0; MIN = MIN + 1; }
      // выводим текущий счетчик времени на монитор порта
      Serial.println(String(MIN) + " : " + String(SEC));

      if (MIN % 3 == 0 && MIN != 0){
              Serial.print("MIN % 3 = " );
              Serial.println(MIN % 3);

        digitalWrite(13,1);
      }else{
        digitalWrite(13,0);
      }

      if (MIN % 6 == 0 && MIN != 0){
        digitalWrite(2, 1);
                      Serial.print("MIN % 6 = " );
              Serial.println(MIN % 6);

      }
   }

}
