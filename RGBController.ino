#include <SoftwareSerial.h>
#define ledPinR 5
#define ledPinG 6
#define ledPinB 9
SoftwareSerial myBluetooth (2,3); // RX, TX
String value = "0:0:0:0";
String red = "";
String green = "";
String blue = "";
String mode = "";
int dotIndex;

void setup () {
myBluetooth.begin(9600);
pinMode(ledPinR, OUTPUT);
pinMode(ledPinG, OUTPUT);
pinMode(ledPinB, OUTPUT);
digitalWrite(ledPinR, LOW);
digitalWrite(ledPinG, LOW);
digitalWrite(ledPinB, LOW);
}

void loop() {

if(myBluetooth.available())
{
value = myBluetooth.readString();
}

dotIndex = value.indexOf(':');
red = value.substring(0, dotIndex);
value = value.substring(dotIndex + 1);

dotIndex = value.indexOf(':');
green = value.substring(0, dotIndex);
value = value.substring(dotIndex+1);

dotIndex = value.indexOf(':');
blue = value.substring(0, dotIndex);
value = value.substring(dotIndex+1, dotIndex+2);

mode = value;

if(mode == "0")
{
analogWrite(ledPinR, red.toInt());
analogWrite(ledPinG, green.toInt());
analogWrite(ledPinB, blue.toInt());
}
else if(mode == "1")
{
analogWrite(ledPinR, red.toInt());
analogWrite(ledPinG, green.toInt());
analogWrite(ledPinB, blue.toInt());
delay(1000);
digitalWrite(ledPinR, LOW);
digitalWrite(ledPinG, LOW);
digitalWrite(ledPinB, LOW);
delay(1000);
}
else{
analogWrite(ledPinR, red.toInt());
digitalWrite(ledPinG, LOW);
digitalWrite(ledPinB, LOW);
delay(1000);
digitalWrite(ledPinR, LOW);
analogWrite(ledPinG, green.toInt());
delay(1000);
digitalWrite(ledPinG, LOW);
analogWrite(ledPinB, blue.toInt());
delay(1000);
}
}