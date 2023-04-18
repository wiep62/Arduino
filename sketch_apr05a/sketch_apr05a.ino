int ledPin = 10;      // светодиод подключен к цифровому контакту 9
int analogPin = A1;  // потенциометр подключен к аналоговому контакту 3
int val = 0;         // переменная для хранения прочитанного значения
void setup()
{
  pinMode(ledPin, OUTPUT);   // объявляем  вывод ШИМ как выход:
  pinMode(12, OUTPUT);   // объявляем  вывод ШИМ как выход:

}
void loop()
{
  val = analogRead(analogPin); // чтения значения от потенциометра
  analogWrite(ledPin, val / 4);// Значения AnalogRead варьируются от 0 до 1023, значения AnalogWrite от 0 до 255.
  analogWrite(12, 1);// Значения AnalogRead варьируются от 0 до 1023, значения AnalogWrite от 0 до 255.
}
