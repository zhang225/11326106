#include <Servo.h>

const int trigPin = 3;          // 超音波感測器 Trig 腳位
const int echoPin = 4;          // 超音波感測器 Echo 腳位
const int ledPin = 13;          // LED 燈接到 D13
const int buzzerPin = 9;        // 蜂鳴器接到 D9
Servo myservo;                  // 伺服馬達物件

int melody[] = {262, 294, 330, 349, 392, 440, 494, 523}; // 簡單音階
int noteDurations[] = {4, 4, 4, 4, 4, 4, 4, 4};          // 每個音符的時長

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  myservo.attach(10); // 伺服馬達接到 D10
  Serial.begin(9600);
}

void loop() {
  long duration = getDistance();
  int distance = duration * 0.034 / 2; // 計算距離 (cm)

  if (distance > 0 && distance < 20) { // 當物體距離小於 20 cm
    digitalWrite(ledPin, HIGH); // LED 亮起
    playMelody();               // 播放音樂
    myservo.write(90);          // 伺服馬達轉到 90 度
    delay(500);
    myservo.write(0);           // 伺服馬達回到 0 度
  } else {
    digitalWrite(ledPin, LOW);  // LED 關閉
    noTone(buzzerPin);          // 停止蜂鳴器
  }
}

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH); // 讀取 Echo 時間
}

void playMelody() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);
    delay(noteDuration * 1.3); // 增加間隔時間
  }
}
