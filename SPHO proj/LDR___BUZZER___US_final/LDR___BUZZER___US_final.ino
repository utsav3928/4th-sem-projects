int ldrPin = A0; // select the input pin for LDR11111110


int ldrValue = 0; // variable to store the value coming from the sensor
const int buzzer = 12;

const int trigPin = 3; //Trigger pin of 1st Sesnor
const int echoPin = 2; //Echo pin of 1st Sesnor
long duration;
int distance;


void setup() {
Serial.begin(9600); //sets serial port for communication
pinMode(buzzer, OUTPUT);

pinMode(A0, INPUT);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
}


void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if (distance<=100)
{
  tone(buzzer, 1000);

delay(100);


noTone(buzzer);
delay(100);
}


{
ldrValue = analogRead(ldrPin);// read the value from the sensor
Serial.println("light intensity =");
Serial.println(ldrValue);  //prints the values coming from the sensor on the screen
if (ldrValue <= 600)
{

tone(buzzer, 200);

delay(500);


noTone(buzzer);
delay(500);

}
}

}
