
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
   if (millis() - timer > 1000) {
      timer = millis();
      SEC = SEC + 1;
      if (SEC > 59) { SEC = 0; MIN = MIN + 1; }
      // выводим текущий счетчик времени на монитор порта
      Serial.println(String(MIN) + " : " + String(SEC));
   }

}
