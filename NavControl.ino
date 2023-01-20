#include <BleKeyboard.h>

BleKeyboard bleKeyboard("MyNav", "MyComp", 100);
const int volUpButtonPin = 0;
const int volDnButtonPin = 1;
const int trNxtButtonPin = 3;
const int trPrvButtonPin = 4;
const int ledPin = 2;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  pinMode(ledPin, OUTPUT);
  pinMode(volUpButtonPin, INPUT_PULLDOWN);
  pinMode(volDnButtonPin, INPUT_PULLDOWN);
  pinMode(trNxtButtonPin, INPUT_PULLDOWN);
  pinMode(trPrvButtonPin, INPUT_PULLDOWN);
  digitalWrite(ledPin, HIGH);
  bleKeyboard.begin();
}

void loop() {
  if(bleKeyboard.isConnected()) {
    bool alreadyPressed = false;
    if(digitalRead(volUpButtonPin) == HIGH){
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP); // odo up
      Serial.println("Volume up");
      alreadyPressed = true;
      delay(200);
    }
    if(!alreadyPressed && digitalRead(volDnButtonPin) == HIGH){
      bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN); // odo down
      Serial.println("Volume down");
      alreadyPressed = true;
      delay(200);
    }
    if(!alreadyPressed && digitalRead(trNxtButtonPin) == HIGH){
      bleKeyboard.write(KEY_MEDIA_NEXT_TRACK); // scroll up
      Serial.println("Next track");
      alreadyPressed = true;
      delay(200);
    }
    if(!alreadyPressed && digitalRead(trPrvButtonPin) == HIGH){
      bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK); // scroll down
      Serial.println("Prev track");
      alreadyPressed = true;
      delay(200);
    } 
  }
  
  delay(10);
}
