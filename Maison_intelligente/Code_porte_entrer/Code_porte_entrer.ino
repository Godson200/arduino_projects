/*
 * --------------------------------------------------------------------------------------------------------------------
 * Example sketch/program showing how to read data from a PICC to serial.
 * --------------------------------------------------------------------------------------------------------------------
 * This is a MFRC522 library example; for further details and other examples see: https://github.com/miguelbalboa/rfid
 * 
 * Example sketch/program showing how to read data from a PICC (that is: a RFID Tag or Card) using a MFRC522 based RFID
 * Reader on the Arduino SPI interface.
 * 
 * When the Arduino and the MFRC522 module are connected (see the pin layout below), load this sketch into Arduino IDE
 * then verify/compile and upload it. To see the output: use Tools, Serial Monitor of the IDE (hit Ctrl+Shft+M). When
 * you present a PICC (that is: a RFID Tag or Card) at reading distance of the MFRC522 Reader/PCD, the serial output
 * will show the ID/UID, type and any data blocks it can read. Note: you may see "Timeout in communication" messages
 * when removing the PICC from reading distance too early.
 * 
 * If your reader supports it, this sketch/program will read all the PICCs presented (that is: multiple tag reading).
 * So if you stack two or more PICCs on top of each other and present them to the reader, it will first output all
 * details of the first and then the next PICC. Note that this may take some time as all data blocks are dumped, so
 * keep the PICCs at reading distance until complete.
 * 
 * @license Released into the public domain.
 * 
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 *
 * More pin layouts for other boards can be found here: https://github.com/miguelbalboa/rfid#pin-layout
 */

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
LiquidCrystal_I2C lcd(0x27,16,2);
Servo servo;
int buzzer=8;
int ledV=4;
int ledR=3;
void setup() {
  Serial.begin(9600);    // Initialize serial communications with the PC
  // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Inserer ");
  lcd.setCursor(2,1);
  lcd.print("une carte");
  pinMode(buzzer,OUTPUT);
  pinMode(ledR,OUTPUT);
  pinMode(ledV,OUTPUT);
  servo.attach(6);
   SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();    // Init MFRC522
  delay(4);        // Optional delay. Some boards do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  /*Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));*/
}

void loop() {
  lcd.setCursor(3,0);
  lcd.print("Inserer ");
  lcd.setCursor(2,1);
  lcd.print("une carte");
  digitalWrite(buzzer,LOW);
  digitalWrite(ledV,LOW);
  digitalWrite(ledR,LOW);
  servo.write(0);
  
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.

  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Dump debug info about the card; PICC_HaltA() is automatically called
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  
  // Read the UID and convert to string
  String UID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    UID.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    UID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  UID.toUpperCase();
  Serial.println(UID.substring(1));

if(UID.substring(1) == "03 FF A7 A9")
{ lcd.clear();
  lcd.setCursor(0,0);
lcd.print("Ouverture...");
servo.write(90);
digitalWrite(ledV,HIGH);
delay(5000);
 lcd.clear();
}
else 
{ lcd.clear();
  lcd.setCursor(0,0);
lcd.print("Acces Refuser");
digitalWrite(buzzer,HIGH);
digitalWrite(ledR,HIGH);
servo.write(0);
delay(5000);
 lcd.clear();
}
}
