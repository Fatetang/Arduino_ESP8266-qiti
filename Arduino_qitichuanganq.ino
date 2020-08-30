#include <SoftwareSerial.h>

int red_led_pin = 9;
int green_led_pin = 8;
int buzzer_pin = 10;
int smoke_sensor_pin = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(red_led_pin, OUTPUT);
  pinMode(green_led_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(smoke_sensor_pin, INPUT);
}
void loop()
{
  int analogSensor = analogRead(smoke_sensor_pin);
  if (analogSensor > 300)
  {
    digitalWrite(red_led_pin, HIGH);
    digitalWrite(green_led_pin, LOW);
    tone(buzzer_pin, 1000, 200);
  }
  else
  {
    digitalWrite(red_led_pin, LOW);
    digitalWrite(green_led_pin, HIGH);
    noTone(buzzer_pin);
  }
}
