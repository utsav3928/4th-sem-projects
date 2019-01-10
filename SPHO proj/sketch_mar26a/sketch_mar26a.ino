const int trigger = 3; 
const int echo = 2; 
const int Buzz = 12; 
const int Light = A1;

long time_taken;
int dist;
int Signal;
int Intens;
int similar_count;

void setup()
{
Serial.begin(9600); 
pinMode(Buzz,OUTPUT);
pinMode(trigger,OUTPUT); 
pinMode(echo, INPUT);
}

void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
}

void loop() {
  calculate_distance(trigger,echo);

Intens = analogRead(Light);

  //If very dark
if (Intens<700)
{
  Serial.print(Intens); Serial.println("Bright Light");
  digitalWrite(Buzz,HIGH);delay(200);digitalWrite(Buzz,LOW);delay(200);digitalWrite(Buzz,HIGH);delay(200);

  digitalWrite(Buzz,LOW);delay(200);
  delay(500);
}

//If very bright
if (Intens>800)
{
  Serial.print(Intens); Serial.println("Low Light");
  digitalWrite(Buzz,HIGH);
  delay(500);
  digitalWrite(Buzz,LOW);
  delay(500);
  digitalWrite(Buzz,HIGH);
  delay(500);
  digitalWrite(Buzz,LOW);
  delay(500);
}

if(dist<50)
{
  Serial.print(dist);
  Serial.println("Object Alert");
  digitalWrite(Buzz,HIGH);
  for (int i=dist; i>0; i--)
    delay(10);

  digitalWrite(Buzz,LOW);
  for (int i=dist; i>0; i--)
    delay(10);
    
}
}
