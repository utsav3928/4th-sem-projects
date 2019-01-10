int ldrPin = A0; // select the input pin for LDR

int ldrValue = 0; // variable to store the value coming from the sensor
const int buzzer = 12;
void setup() {
Serial.begin(9600); //sets serial port for communication
pinMode(buzzer, OUTPUT);
pinMode(A0, INPUT);
}
void loop() {
ldrValue = analogRead(ldrPin);// read the value from the sensor
Serial.println("light intensity =");
Serial.println(ldrValue);  //prints the values coming from the sensor on the screen
if (ldrValue <= 600) {

tone(buzzer, 200);

delay(200);


noTone(buzzer);
delay(200);




}}
