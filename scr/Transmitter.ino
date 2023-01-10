
/* Cara Program NRF24L01 Untuk Water Level Arduino
  Dev: teknisibali // Date: 11/11/2019 // www.teknisibali.com

   Cara Program NRF24L01 Untuk Water Level Arduino - Coding Transmitter Menggunakan Arduino UNO
*/

// Include needed Libraries at beginning

#include "nRF24L01.h" //Penyertaan library header nRF24L01
#include "RF24.h"  //Penyertaan library header RF24
#include "SPI.h" //Penyertaan library header penggunaan interface SPI

#define trigpin 4  //Pin Trigger Ultrasonic
#define echopin 2 //Pin Echo Ultrasonic 

int SentMessage[1];

RF24 radio(9, 10); // NRF24L01 menggunakan pin SPI + Pin 9 dan 10 pada Arduino

const uint64_t pipe = 123456; // Perlu alamat yang sama untuk berkomunikasi antara 2 buah NRF24L01


void setup(void)
{
  Serial.begin(9600); // Menggunakan serial monitor pada 9600bps

  pinMode(trigpin, OUTPUT); // Deklarasi pin sebagai output
  pinMode(echopin, INPUT);  // Deklarasi pin sebagai input

  radio.begin(); // Mulai membaca modul NRF24L01
  radio.openWritingPipe(pipe); // NRF24L01 siap untuk mengirim data
}

void loop(void)
{
  long duration, distance;  //Varibel durasi dan jarak
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  distance = ( duration / 2) / 29; //Perhitungan untuk pembacaan jarak

  Serial.println(distance);
  Serial.print("cm:");


  SentMessage[0] = (distance);
  radio.write(SentMessage, 1); // Kirim nilai melalui NRF24L01

}
