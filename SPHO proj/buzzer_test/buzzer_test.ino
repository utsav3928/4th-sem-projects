const int buzzer = 12;
const int ldr = A1;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzzer,OUTPUT);
pinMode(ldr,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int ldrstatus = analogRead(ldr);
if(ldrstatus<800)
{
  tone(buzzer,100);
  delay(100);
  noTone(buzzer);
  delay(100);
}
else{
  noTone(buzzer);
}
}

