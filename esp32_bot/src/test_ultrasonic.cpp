// #include <Arduino.h>

// // motor pins
// #define motorRa 27
// #define motorRb 14
// #define motorLa 25
// #define motorLb 26
// #define Rpwm    12
// #define Lpwm    33

// // ultrasonic sensor pins
// #define triggerPin 18
// #define echoPin 5

// //PWM setup
// const int channel_R      = 0;                          //PWM setup
// const int channel_L      = 1;
// const unsigned long print_interval = 1000;
// void setup_motors();
// void process_input(String input);
// void run_motor_R(int pwm);
// void run_motor_L(int pwm);
// void stop_motor_R();
// void stop_motor_L();
// void stop_motors();
// void setup_ultrasonic_sensor();
// float read_ultrasonic_distance();


// void setup()
// {
//   Serial.begin(115200);
//   setup_motors();
//   setup_ultrasonic_sensor();
// }

// void loop()
// {
//   static unsigned long last_print_time = 0;

//   if (Serial.available() > 0) {
//     String input = Serial.readStringUntil('\n');
//     process_input(input);
//   }

//   unsigned long current_time = millis();
//   if (current_time - last_print_time >= print_interval) {
//     last_print_time = current_time;
//     float distance = read_ultrasonic_distance();
//     Serial.print("Distance: ");
//     Serial.print(distance);
//     Serial.println(" cm");
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

// void setup_ultrasonic_sensor() {
//   pinMode(triggerPin, OUTPUT);
//   pinMode(echoPin, INPUT);
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

// float read_ultrasonic_distance() {
//   digitalWrite(triggerPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(triggerPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(triggerPin, LOW);

//   float duration = pulseIn(echoPin, HIGH);
//   float distance = duration * 0.0344 / 2;

//   return distance;
// }
