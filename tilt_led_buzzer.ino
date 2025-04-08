const int mercurySwitchPin = 2; // 水銀開關接到 D2
const int ledPin = 13;          // LED 燈接到 D13
const int buzzerPin = 9;        // 蜂鳴器接到 D9

void setup() {
  pinMode(mercurySwitchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int tiltState = digitalRead(mercurySwitchPin);

  if (tiltState == HIGH) { // 偵測到傾斜
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000); // 蜂鳴器發出 1000Hz 聲音
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin); // 停止蜂鳴器
  }
}
