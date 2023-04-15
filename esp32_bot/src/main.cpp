#include <Arduino.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
// motor pins
#define motorRa 14
#define motorRb 27
#define motorLa 26
#define motorLb 25
#define Rpwm    12
#define Lpwm    33

//PWM setup
const int channel_R      = 0;                          //PWM setup
const int channel_L      = 1;
void setup_motors();
void process_input(String input);
void go_backward(int pwm);
void turn_right(int pwm);
void turn_left(int pwm);
void stop();
void forward(int pwm);

BluetoothSerial SerialBT;
void setup()
{
  Serial.begin(115200);
    SerialBT.begin("ESP32_BT");
  setup_motors();
}

void loop()
{
  if (SerialBT.available()) {
    String input = SerialBT.readStringUntil('\n');
    Serial.println(input);
    process_input(input);
  }
}

void setup_motors(){
  // pwm setup variables
  const int freq = 5000;
  const int res = 8;

  // direction for motor pinout defination
  pinMode(motorLa, OUTPUT);
  pinMode(motorLb, OUTPUT);
  pinMode(motorRa, OUTPUT);
  pinMode(motorRb, OUTPUT);
  // Pwm functionality setup
  ledcSetup(channel_R ,freq , res);
  ledcSetup(channel_L ,freq , res);
  ledcAttachPin(Rpwm,channel_R);
  ledcAttachPin(Lpwm,channel_L);
}



void process_input(String input) {
  char command = input.charAt(0);
  int fixed_pwm = 150;

  if (command == 'r') {
    turn_right(fixed_pwm);
  } else if (command == 'f') {
    forward(fixed_pwm);
  }else if (command == 'l') {
    turn_left(fixed_pwm);
  } else if (command == 'b') {
    go_backward(fixed_pwm);
  }else if (command == 's') {
    stop();
  } else {
    Serial.println("Invalid input");
  }
}

void turn_right(int pwm) {
  // Left motor forward
  ledcWrite(channel_L, pwm);
  digitalWrite(motorLa, HIGH);
  digitalWrite(motorLb, LOW);

  // Right motor backward
  ledcWrite(channel_R, pwm);
  digitalWrite(motorRa, LOW);
  digitalWrite(motorRb, HIGH);
}

void turn_left(int pwm) {
  // Left motor backward
  ledcWrite(channel_L, pwm);
  digitalWrite(motorLa, LOW);
  digitalWrite(motorLb, HIGH);

  // Right motor forward
  ledcWrite(channel_R, pwm);
  digitalWrite(motorRa, HIGH);
  digitalWrite(motorRb, LOW);
}

void go_backward(int pwm) {
  // Left motor backward
  ledcWrite(channel_L, pwm);
  digitalWrite(motorLa, LOW);
  digitalWrite(motorLb, HIGH);

  // Right motor backward
  ledcWrite(channel_R, pwm);
  digitalWrite(motorRa, LOW);
  digitalWrite(motorRb, HIGH);
}
void stop(){
  // Left motor stop
  ledcWrite(channel_L, 0);
  digitalWrite(motorLa, LOW);
  digitalWrite(motorLb, LOW);

  // Right motor stop
  ledcWrite(channel_R, 0);
  digitalWrite(motorRa, LOW);
  digitalWrite(motorRb, LOW);
}

void forward(int pwm){
  // Left motor forward
  ledcWrite(channel_L, pwm);
  digitalWrite(motorLa, HIGH);
  digitalWrite(motorLb, LOW);

  // Right motor forward
  ledcWrite(channel_R, pwm);
  digitalWrite(motorRa, HIGH);
  digitalWrite(motorRb, LOW);
}
