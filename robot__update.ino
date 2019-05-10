
#include <Servo.h>

Servo myservo1, myservo2, myservo3, myservo4;

void setup()
{
myservo1.attach(5);
myservo2.attach(6);
myservo3.attach(9);
myservo4.attach(3);
Serial.begin(9600);  
}

void loop()
{
if (Serial.available() >= 2 )
{
unsigned int servopos = Serial.read(); 
unsigned int servopos1 = Serial.read(); 
unsigned int realservo = (servopos1 * 256) + servopos;  
int kd = 15;

if (realservo >= 500 && realservo <= 1135) // tut bırak
{
int servo1 = realservo;
servo1 = map(servo1, 500, 1135, 0, 135);
myservo1.write(servo1);
delay(kd);
}

if (realservo >= 2000 && realservo <= 2090) { // sağ sol

int servo2 = realservo;
servo2 = map(servo2, 2000, 2090, 180, 0);
myservo2.write(servo2);
delay(kd);
}

if (realservo >= 3000 && realservo <= 3280) { // yukarı aşağı
int servo3 = realservo;
servo3 = map(servo3, 3000, 3280, 60, 140);
myservo3.write(servo3);
delay(kd);
}

if (realservo >= 4000 && realservo <= 4120) { // ileri geri

int servo4 = realservo;
servo4 = map(servo4, 4000, 4120, 40, 150);
myservo4.write(servo4);
delay(kd);
}
}
}
