#include <SoftwareSerial.h>
SoftwareSerial ArduinoSerial(3, 2); // RX, TX

#define A 4
#define B 5
#define C 8
#define D 7
#define E 6
#define F 9
#define G 10

void setup() {
  ArduinoSerial.begin(4800); 
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  while (ArduinoSerial.available() > 0) {
    int val = ArduinoSerial.parseInt();
    if (ArduinoSerial.read() == '\n') {
      Serial.println(val);
       
  
  // ส่วนนี้จะเป็นส่วนของการเช็คเงื่อนไขโดยเช็คจากค่า val ที่เรากำหนดไว้ก่อนหน้านั้น
  // หมายเหตุ :
  Serial.print("VAL : ");
  Serial.println(val);
  // digitalWrite(ขา Pin ที่เราจะใช้, ค่าสถานะของการทำงาน โดยที่ค่า HIGH คือเปิดไฟ ส่วน LOW คือปิดไฟ)
  // เมื่อเรากำหนดค่า val = 0 ผลลัพธ์ที่ได้จะแสดงไฟบน 7-Segment คือเลข 0
String wow = String(val);
  if(wow == "0") {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
  }

  // เมื่อเรากำหนดค่า wow = 1 ผลลัพธ์ที่ได้จะแสดงไฟบน 7-Segment คือเลข 1
  else if(wow == "1") {
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  }
  // เมื่อเรากำหนดค่า wow = 2 ผลลัพธ์ที่ได้จะแสดงไฟบน 7-Segment คือเลข 2
  else if(wow == "2") {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
  }

  // เมื่อเรากำหนดค่า wow = 3 ผลลัพธ์ที่ได้จะแสดงไฟบน 7-Segment คือเลข 3
  else if(wow == "3") {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
  }
  // เมื่อเรากำหนดค่า wow = 4 ผลลัพธ์ที่ได้จะแสดงไฟบน 7-Segment คือเลข 4
  else if(wow == "4") {
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  }

  //Code here
  else if(wow == "5") {
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  }
  else if(wow == "6") {
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  }
  else if(wow == "7") {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
  }
  else if(wow == "8") {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  }
  else if(wow == "9") {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  }
  else if(wow == "11") {
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  }
  else if(wow == "10") {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
  }
    }
  }
  delay(100); 

}
