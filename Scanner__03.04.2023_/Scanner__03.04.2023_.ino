#include <Adafruit_Fingerprint.h>                             // Подключение библиотеки Adafruit Fingerprint
 
/*
volatile int finger_status = -1;
SoftwareSerial mySerial(2, 3);  
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
void setup()  

цуууууууууууууууууууууууууууууууууууууууу

*/
volatile int finger_status = -1;
SoftwareSerial mySerial(2, 3);  
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
void setup()  
{

  pinMode(13, OUTPUT);
   pinMode(7, OUTPUT);

  Serial.begin(9600);
  while (!Serial); 
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");
 
  
  finger.begin(57600);                                       // Установите скорость передачи данных для последовательного порта датчика
  
/*
 if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
*/

  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
 
  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
}
 
void loop()                    
{
  finger_status = getFingerprintIDez();
  if (finger_status!=-1 and finger_status!=-2){
    Serial.print("Match");
  } else{
    if (finger_status==-2){
      for (int ii=0;ii<5;ii++){
        Serial.print("Not Match");
           digitalWrite(7,1);
    delay(3000);      
      }
    }
  }
  delay(50);     

/*
int  fingerprintID = getFingerprintIDez();
  delay(50);
  if(fingerprintID == 0 || fingerprintID == 1){
     digitalWrite(7,1);
    delay(3000);         
  }  
 
*/
}
 
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p!=2){
    Serial.println(p);
  }
  if (p != FINGERPRINT_OK)  return -1;
  
  p = finger.image2Tz();
  if (p!=2){
    Serial.println(p);
  }
  if (p != FINGERPRINT_OK)  return -1;
 
  p = finger.fingerFastSearch();
 // if (p != FINGERPRINT_OK)  return -2;
 if (p != FINGERPRINT_OK)  return -1;
digitalWrite(13,HIGH);
  delay(3000);
  digitalWrite(13,LOW);
 
 
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
 
}
