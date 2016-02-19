int Trig = 8;
int Echo = 9;
int Duration;
float Distance;//筒先から水までの距離
float Waterlevel;//水位

void setup() {
  Serial.begin(9600);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
}

void loop() {
  digitalWrite(Trig,LOW);
  delayMicroseconds(1);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(11);
  digitalWrite(Trig,LOW);
  Duration = pulseIn(Echo,HIGH);
  if (Duration>0) {
    Distance = Duration/2;
    //筒の先から水までの距離の
    Distance = Distance*340*100/1000000;// 超音波の速度は340m/s = 34000cm/計算s = 0.034cm/us
    Waterlevel = 50-Distance;//水位の計算 土から筒先までの長さ-Distance
    Serial.print(Duration);
    Serial.print(" us ");
    Serial.print(Distance);
    Serial.println(" cm");
    Serial.print(Waterlevel);
    Serial.println("cm");
  }
  delay(500);
}
