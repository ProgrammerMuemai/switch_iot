
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "" 
#define BLYNK_DEVICE_NAME "" 

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

#include <Servo.h>
Servo myservo;
BlynkTimer timer;

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
  myservo.attach(D9);
  myservo.write(90);
}

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  //Serial.print("V1 value is: ");
  //Serial.println(pinValue);
  if (pinValue == 1) {
    myservo.write(180);
    timer.setTimeout(500L, Action90);
  }
  if (pinValue == 0) {
    myservo.write(0);
    timer.setTimeout(500L, Action90);
  }
}

void Action90()
{
  myservo.write(90);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}
