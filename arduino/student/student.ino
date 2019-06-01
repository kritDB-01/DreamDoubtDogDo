#include <TridentTD_LineNotify.h>
#include <ESP8266WiFi.h> 

#define LINE_TOKEN "od6awxYIZdAgGy6kY0mFt1fXd3d9vFUco20q1oepNU9"

#include <SoftwareSerial.h> // lib for readSerial
SoftwareSerial NodeSerial(D2, D3); // RX | TX

#include <FirebaseArduino.h> //Library สำหรับเชื่อมต่อ Firebase
#include <ESP8266WiFi.h> //Library สำหรับการใช้งาน ESP8266 กับ WiFi
  
#define WIFI_SSID "Room334" //SSID ของ WiFi ห้อง 334
#define WIFI_PASSWORD "334334334" //รหัสผ่าน WiFi ห้อง 334
  
#define FIREBASE_HOST "namiixz.firebaseio.com"
#define FIREBASE_AUTH "9dbEhDSy3J0evvEXsT25aumMLp0s5Bz5ldnrFh8Z"
/* Keypad
การต่อขาใน keypad
ขาในบอร์ด    D0 D1 D4 D5 D6 D7 D8
ขาใน Keypad 7  6  5  4  3  2  1
*/
#include <Keypad.h>

const byte ROWS = 4; //4 แถว
const byte COLS = 3; //3 หลัก
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {D0, D1, D4, D5}; //เชื่อมต่อแถว ขาที่จะส่งค่าไปยัง keypad
byte colPins[COLS] = {D8, D7, D6}; //เชื่อมต่อหลัก ขาที่จะส่งค่าไปยัง keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  pinMode(D0, INPUT);
  pinMode(D1, OUTPUT);

  Serial.println("ต่อเเล้วนะจ้ะ");
  LINE.setToken(LINE_TOKEN);  // กำหนด Line Token
  LINE.notify(2342);
  
  NodeSerial.begin(4800);
  Serial.begin(9600); //เริ่ม Serial Monitor ที่ 115200 baud
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //เริ่มเชื่อมต่อ WiFi ด้วยค่าที่กำหนดไว้ที่บรรทัดที่ 4 และ 5
  Serial.print("Connecting"); //บอกสถานะว่ากำลังเชื่อมต่ออยู่

  while(WiFi.status() != WL_CONNECTED){ //ทำการวนรอบจนกว่า WiFi จะเชื่อมต่อได้
      Serial.print(".");
      delay(500);
      
  }
  //เมื่อเชื่อมต่อได้แล้วแสดงที่อยู่ IP ที่เชื่อมต่อ
  Serial.println();
  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
String lastkey = "";
int state = 0;
int mybool = 1;
void loop(){
  char key = keypad.getKey();
  String mykey = "";
  mykey += (char)key;
  if (key && state == 0){
    
    String mykey = "";
    mykey += (char)key;
    if(lastkey == mykey && mykey != "7" && mykey != "9" || mykey == "*" || mykey == "#" || mykey == "0"){
      return;
    }
    Serial.println(mykey);
    NodeSerial.print(mykey);
    NodeSerial.print("\n");
    if(mykey != "7" && mykey != "9"){
      Firebase.pushString("text", mykey);
    }
  if(mykey == "1"){
    LINE.notify("ไม่เข้าใจเรยนะอาจารย์");
  }
  if(mykey == "2"){
    LINE.notify("เบาไปแล้วค้าบบ");
  }
  if(mykey == "3"){
    LINE.notify("ซิ่งไปคับจารย์");
  }
  if(mykey == "4"){
    LINE.notify("Time up now");
  }
  if(mykey == "5"){
    LINE.notify("เล็กไปค้าบบางที..ตัวหนังสือนะ");
  }
  if(mykey == "6"){
    LINE.notify("ลื่นจริงๆวันนี้");
  }
  if(mykey == "7"){
    if (mybool == 1) {
      Firebase.setInt("student/1",0);
      mybool = 0;
      int num = Firebase.getInt("fine");
      num--;
      Firebase.setInt("fine", num);
      num = Firebase.getInt("help");
      num++;
      Firebase.setInt("help", num);
    }
    else {
      Firebase.setInt("student/1",1);
      mybool = 1;
      int num = Firebase.getInt("fine");
      num++;
      Firebase.setInt("fine", num);
      num = Firebase.getInt("help");
      num--;
      Firebase.setInt("help", num);
    }
  }
  if(mykey == "8"){
    LINE.notifyPicture("https://f.ptcdn.info/622/051/000/or0jqp403aNhjIuJ4Tc-o.jpg");
  }
  if(mykey == "9"){
    state = 1;
  }
  
   lastkey = mykey;
  }


  else if (state == 1 && key){
    state = 0;
    if(mykey == "9"){
      return;  
    }
    if(mykey != "7" && mykey != "8"){
    Firebase.setString("score/1", mykey);
    }
    delay(500);
  }
}
