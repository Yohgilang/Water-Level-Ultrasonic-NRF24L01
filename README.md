# Water Level Controller with Data Telemetry
Ini adalah proyek telemetri untuk mengukur ketinggian air menggunakan sensor ultrasonik dan NRF24L01. Jenis module telemetri yang digunakan adalah NRF24L01+PA+LNA karena dengan adanya antena yang memanfaatkan gelombang frekuensi 2.4 GHz dapat saling berkomunikasi dalam jarak 1,1 km. 

Komponen:
- Module NRF24L01+PA+LNA
- Arduino Uno
- Ultrasonic HC-SR04
- LCD Crystal 16 x 2
- I2C LCD
 

Skematik:
- Transmitter

![transmitter](https://user-images.githubusercontent.com/93894711/211598306-cfd41c0f-b078-42e4-a554-88ac60bd38ed.png)

- Reciver

![receiver](https://user-images.githubusercontent.com/93894711/211598289-58671758-b9f0-4b00-aa82-464508d2d007.png)



Prinsip kerja:
Untuk pendeteksi ketinggian air digunakan sensor ultrasonik yang bekerja berdasarkan prinsip pantulan suatu gelombang suara. Sensor akan mendeteksi ketinggian air secara terus-menerus, kemudian data yang terbaca oleh sensor akan masuk ke mikrokontroler arduino sebagai pengolah data. Selanjutnya data akan dikirimkan oleh modul NRF24L01 memalui alat yang dituju (alamat transmitter dan receiver sama). Terdapat indikator yang digunakan pada receiver, yaitu LCD 16x2, 3 buah LED, dan buzzer. 

Hasil:

