#include <Servo.h>

Servo myservo;
const int buttonPin = 2; // 按鈕連接到 D2
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  myservo.attach(9);  // 伺服馬達接在9號腳位
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0)); // 使用未連接的類比腳位作為隨機種子
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    int randomAngle = random(0, 181); // 產生0到180之間的隨機角度
    myservo.write(randomAngle);
    Serial.print("隨機角度：");
    Serial.println(randomAngle);
    delay(200); // 按鍵消抖動
  }
  
  lastButtonState = buttonState;
}
