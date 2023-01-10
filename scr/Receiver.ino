// Include library 
#include "nRF24L01.h" 
#include "RF24.h" 
#include "SPI.h" 
#include <Wire.h>
#include <LiquidCrystal_I2C.h> 

// Initialization of pin used
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD 16x2
int Message[1];
RF24 radio(9, 10); // NRF24L01 uses the SPI + pins 9 and 10 on the Arduino
const uint64_t pipe = 123456; // Use the same address between NRF modules
int LED1 = 5; 
int LED2 = 6; 
int LED3 = 7; 
int BUZZER = 3; 

void setup(void)
{
  // set LCD I2C
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2); 
  lcd.setCursor(0, 0);
  lcd.print(" WaterLevel ");
  lcd.setCursor(0, 1);
  lcd.print(" Control ");
  delay(1000);
  
  lcd.clear();
  
  Serial.begin(9600); // Menggunakan serial monitor pada 9600bps
  radio.begin(); // Mulai pembacaan module NRF24L01
  radio.openReadingPipe(1, pipe); // NRF24L01 siap untuk menerima data
  radio.startListening();
  pinMode(LED1, OUTPUT); // Deklarasi pin sebagai output
  pinMode(LED2, OUTPUT); // Deklarasi pin sebagai output
  pinMode(LED3, OUTPUT); // Deklarasi pin sebagai output
  pinMode(BUZZER, OUTPUT); // Deklarasi pin sebagai output
}

void loop(void)
{
  if (radio.available()) //Jika terbaca data di module NRF24L01
  {
    bool selesai = false;
    while (!selesai) { //perulangan apabila selesai = TRUE
      selesai = radio.read(Message, 1);
      Serial.println(Message[0]); //menuliskan informasi di serial monitor

      lcd.setCursor(0, 0);
      lcd.print("Jarak = ");
      lcd.print(Message[0]);
      lcd.print(" cm");
      lcd.setCursor(0, 1);
      lcd.print("Water Level");
      delay(250);
      if ( (Message[0] > 0) && (Message[0] < 10) ) // Jika jarak yang terbaca adalah dari 0 sampai 10 cm maka Buzzer dan LED 1 ON
      {
        delay(10);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3 , LOW);
        digitalWrite(BUZZER, HIGH);
      }
      else if ( (Message[0] > 10) && (Message[0] <= 30) ) // Jika jarak yang terbaca adalah lebih dari 10 sampai 30 cm maka LED 2 ON
      {
        delay(10);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3 , LOW);
        digitalWrite(BUZZER, LOW);
      }
      else if ( (Message[0] > 30) ) // Jika jarak yang terbaca adalah lebih dari 30 cm maka LED3 ON
      {
        delay(10);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3 , HIGH);
        digitalWrite(BUZZER, LOW);
      }
      delay(10);
    }

  } 
  // Nilai tunda untuk pembacaan data berikutnya
  else
  {
    Serial.println("No radio available");
    lcd.setCursor(0, 0);
    lcd.print("No Radio");
    lcd.setCursor(0, 1);
    lcd.print("Available");
    delay(200);
    lcd.clear();
  }
}
