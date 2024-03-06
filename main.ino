#define trigPin 13
#define echoPin 12
#define buzzer 6
#define led 5
#define switch_1 8
#define switch_2 7

void setup()
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

pinMode(switch_1, INPUT);
pinMode(switch_2, INPUT);

pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);
}
void loop()
{  
long duration, distance, dis;
bool write_enable;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH); // thoi gian LoW hoac HIGH // thoi gian tu phat den luc nhan
distance = (duration/2) / 28.02;
dis = 25;
if(digitalRead(switch_1) == 0  && digitalRead(switch_2) == 1 ){ dis = 25; write_enable = 1;}
else if(digitalRead(switch_1) == 1  && digitalRead(switch_2) == 0 ){ dis = 50; write_enable = 1;}
else if(digitalRead(switch_1) == 0  && digitalRead(switch_2) == 0 ){ dis = 75; write_enable = 1;}
else write_enable = 0;
if(write_enable == 1){
if (distance < dis ) // Checking the distance, you can change the value
    {
     // When the the distance below 25 cm
        digitalWrite(buzzer, HIGH);
        digitalWrite(led, HIGH);
    }
else
    {
    // when greater than 25 cm
        digitalWrite(buzzer,LOW);
        digitalWrite(led,LOW);
    }
}
 delay(500);

}



  
