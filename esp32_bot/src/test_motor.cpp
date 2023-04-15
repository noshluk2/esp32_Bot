// #include <Arduino.h>

// // motor pins
// #define motorRa 27
// #define motorRb 14
// #define motorLa 25
// #define motorLb 26
// #define Rpwm    12
// #define Lpwm    33

// //PWM setup
// const int channel_R      = 0;                          //PWM setup
// const int channel_L      = 1;
// void setup_motors();
// void process_input(String input);
// void run_motor_R(int pwm);
// void run_motor_L(int pwm);
// void setup()
// {
//   Serial.begin(115200);
//   setup_motors();
// }

// void loop()
// {
//   if (Serial.available() > 0) {
//     String input = Serial.readStringUntil('\n');
//     process_input(input);
//   }
// }

// void setup_motors(){
//   // pwm setup variables
//   const int freq = 5000;
//   const int res = 8;

//   // direction for motor pinout defination
//   pinMode(motorLa, OUTPUT);
//   pinMode(motorLb, OUTPUT);
//   pinMode(motorRa, OUTPUT);
//   pinMode(motorRb, OUTPUT);
//   // Pwm functionality setup
//   ledcSetup(channel_R ,freq , res);
//   ledcSetup(channel_L ,freq , res);
//   ledcAttachPin(Rpwm,channel_R);
//   ledcAttachPin(Lpwm,channel_L);
// }

// void process_input(String input) {
//   char motor = input.charAt(0);
//   int pwm = input.substring(1).toInt();

//   if (motor == 'r') {
//     run_motor_R(pwm);
//   } else if (motor == 'l') {
//     run_motor_L(pwm);
//   } else {
//     Serial.println("Invalid input");
//   }
// }

// void run_motor_R(int pwm) {
//   ledcWrite(channel_R, pwm);
//   digitalWrite(motorRa, HIGH);
//   digitalWrite(motorRb, LOW);
// }

// void run_motor_L(int pwm) {
//   ledcWrite(channel_L, pwm);
//   digitalWrite(motorLa, HIGH);
//   digitalWrite(motorLb, LOW);
// }
