#define RX 2
#define TX 7
#define gas_value A0
#define OLED_RESET     4
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define LOGO_HEIGHT   128
#define LOGO_WIDTH    64
#define HEATTIME 5000
bool debug = true;

#include <Adafruit_SSD1306.h>
void(* reset) (void) = 0;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int stat = 0;
double heatTime = 0;
const unsigned char PROGMEM logo_bmp [] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x7f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x7f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0f, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1f, 0xf3, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x1f, 0xf3, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x3f, 0xe3, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x7f, 0xe1, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x7f, 0x89, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x7f, 0x19, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xfe, 0x33, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xfc, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xfc, 0xe6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x79, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x79, 0xc8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x79, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x39, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x39, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x19, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0d, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x04, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void printDisplay(String str){
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print((String)str +"\n" +stat);
  display.print(stat);
  display.display();
}
void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(gas_value, INPUT);
  pinMode(13, OUTPUT);
  heatTime = millis();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for (;;);
  }
  display.clearDisplay();
  display.drawBitmap(
    (display.width()  - 128 ) / 2,
    (display.height() - 32) / 2,
    logo_bmp, 128, 32, 1);
  display.setTextSize(1, 2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(33, 0);
  display.print("VITEBSK");
  display.setCursor(33, 16);
  display.print("    OBL");
  display.setTextSize(2, 4);
  display.setCursor(78, 1);
  display.print("GAS");
  display.display();
  delay(2000);
  printDisplay("BOOT\nGSM");
  digitalWrite(13,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  delay(2000);
  digitalWrite(11,HIGH);
  Serial.begin(115200);
  Serial.println("AT+IPR=9600");
  Serial.begin(9600);

}
String STAT[] = {"Not registed", "Prepare to connection", "Connection to server", "Create TCP connection", "Prepare to send mesg", "Send message", "Close connection"};
double beginConnection = 0;
double statPause = 0;
String gsmM = "";

void loop() {
  gsmM = Serial.readString();
  gsmM.replace("\r\n\r\n", "\r\n");

  if(stat == 0){
    Serial.println("AT+CREG?");
  }

  if(stat == 1){
    Serial.println("AT+CIPSTATUS?");
    stat = 2;
    statPause = millis();
  }

  if(stat == 2){
    if(millis()-statPause>5000){
      stat = 1;
    }
  }

  if(stat == 3){
    Serial.println("AT+CIPSTART=TCP,192.168.101.209,1020");
    stat = 4;
    statPause = millis();
  }

  if(stat == 4){
    delay(1000);
    Serial.println("AT+CIPSTATUS?");
    stat = 5;
    statPause = millis();
  }

  if(stat == 5){
    if(millis()-statPause>2000){
      stat = 4;
    }
  }

  if(stat == 6){
    int value = analogRead(A0);
    int lenght = 2;//длина числа измеренного
    if(value>99){
      lenght++;
    }
    String msg = ",GSM=NULL;IMEI=460001033113523;GAS=";
    lenght += msg.length() - 1;//длина сообщения - 1(запятая)
    Serial.print("AT+CIPSEND=");
    Serial.print(lenght);
    Serial.print(msg);
    Serial.println(value);
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print((String)stat+ "- send\n");
    display.display();
    delay(5000);
    Serial.println("AT+CIPSTATUS?");
  }

  if(gsmM.indexOf("CONNECT")>0){
    stat = 6;
  }

  if(gsmM.indexOf("+CIPSTATUS:0,IP INITIAL")>0){
    stat = 3;
  }

  if(gsmM.indexOf("+CME ERRO")>0){
    stat = 0;
  }

  if(gsmM.indexOf("+CREG: 1,1\r\n")>0){
    stat = 1;
  }

  if(gsmM.indexOf("CLOSED")>0){
    stat = 1;
  }
  display.clearDisplay();
  display.display();
  delay(100);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print((String)stat+ "-" +gsmM);
  display.display();
}
