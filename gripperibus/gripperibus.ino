#include <IBusBM.h>
#include <Servo.h>
int pwm1= 5;
int pwm2 = 6;
int dir1=7;
int dir2 =8;
IBusBM ibus;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  ibus.begin(Serial);
  Serial.begin(115200);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  ibus.begin(Serial);


}

int readchannell(int channel){
  int channelval = ibus.readChannel(channel);
  return map(channelval, 1000,2000, -255,255);
}


void loop() {
   int forback= readchannell(1);
   int lefright = readchannell(2);
   int motor1 = forback - lefright;
   int motor2 = forback + lefright;
   analogWrite(pwm1,motor1);
   analogWrite(pwm2,motor2);
   if (forback > 0){
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
   } else{
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
   } 
   
  delay(10);

  // put your main code here, to run repeatedly:

}
