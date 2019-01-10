const int trigger = 3; //Trigger pin of 1st Sesnor
const int echo = 2; //Echo pin of 1st Sesnor
const int Buzz = 12; //Echo pin of 1st Sesnor
long time_taken;
int dist;
int Signal;
int Intens;
int similar_count;


void setup() {
  // put your setup code here, to run once:


Serial.begin(9600); 
pinMode(Buzz,OUTPUT);
digitalWrite(Buzz,LOW);
pinMode(trigger, OUTPUT); 
pinMode(echo, INPUT); 

}

/*###Function to calculate distance###*/
void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>300)
dist=300;
}


void loop() {
  // put your main code here, to run repeatedly:

  if (dist<50)
{
  Serial.print(dist); Serial.println("Object Alert");
  
  digitalWrite(Buzz,HIGH);
  for (int i=dist; i>0; i--)
    delay(10);

  digitalWrite(Buzz,LOW);
  for (int i=dist; i>0; i--)
    delay(10);
  
}
}
