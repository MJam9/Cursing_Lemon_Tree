#include <Arduino.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

const int feuchteBool = 18;  // Digitaler Ausgang an GPIO 18
const int bewegungsPin = 36; // Input von Bewegungssensor

int feuchteStatus = HIGH;
bool soundPlayed = false;


// DFPlayer Mini
HardwareSerial mySerial(2); 
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(bewegungsPin, INPUT); //Bewegungssensor
  pinMode(feuchteBool, INPUT); //Bodenfeuchtesensor

  // DFPlayer Mini Setup
  mySerial.begin(9600, SERIAL_8N1, 16, 17);  // RX=16, TX=17

  if (!myDFPlayer.begin(mySerial)) {
    esp_deep_sleep_start();  // Bei Fehler sofort in Deep Sleep
  }
  myDFPlayer.volume(25);  

  // Wakeup durch Bewegungssensor
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_36, 1);  // HIGH = Bewegung
}

void loop() {
 // Bodenfeuchte digital auslesen
  feuchteStatus = digitalRead(feuchteBool);

  if (feuchteStatus == HIGH) {  // Boden ist trocken
    myDFPlayer.play(random(1,5));  // Zufälliger Sound
    delay(3500);  // Warte auf Soundende
  }

  myDFPlayer.stop();  // Stoppe Wiedergabe
  delay(200);
  
  esp_deep_sleep_start();
}