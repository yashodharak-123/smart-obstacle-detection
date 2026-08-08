//================ PIN DEFINITIONS =================

// Left Sensor
#define TRIG_LEFT 5
#define ECHO_LEFT 18

// Front Sensor
#define TRIG_FRONT 17
#define ECHO_FRONT 16

// Right Sensor
#define TRIG_RIGHT 4
#define ECHO_RIGHT 2

// Buzzer
#define BUZZER 15

// LEDs
#define RED_LED 25
#define GREEN_LED 26
#define BLUE_LED 27

//==================================================
float getDistance(int trigPin, int echoPin);
void getDirection(float left, float front, float right);
void setAlert(int mode);
void setup()
{
  Serial.begin(115200);
  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);
  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_FRONT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  ledcAttach(BUZZER, 2000, 8);
  Serial.println("Obstacle Detection System Started...");
}
void loop()
{
  float left = getDistance(TRIG_LEFT, ECHO_LEFT);
  float front = getDistance(TRIG_FRONT, ECHO_FRONT);
  float right = getDistance(TRIG_RIGHT, ECHO_RIGHT);
  Serial.print("Left: ");
  Serial.print(left);
  Serial.print(" cm   Front: ");
  Serial.print(front);
  Serial.print(" cm   Right: ");
  Serial.print(right);
  Serial.println(" cm");
  getDirection(left, front, right);
  delay(100);
}
//==================================================
float getDistance(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000);
  if(duration == 0)
      return 400;
  return duration * 0.0343 / 2;
}
//==================================================
void getDirection(float left, float front, float right)
{
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  ledcWriteTone(BUZZER,0);
  // Emergency: Obstacles on all three sides
if(left < 50 && front < 50 && right < 50)
{
    Serial.println("!!! EMERGENCY - OBSTACLES ALL AROUND !!!");
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);
    policeSiren();
    return;
}
  if(front <= left && front <= right && front < 50)
  {
      Serial.println(">>> FRONT OBSTACLE <<<");
      setAlert(1);
  }
  else if(left <= front && left <= right && left < 50)
  {
      Serial.println(">>> LEFT OBSTACLE <<<");
      setAlert(2);
  }
  else if(right <= front && right <= left && right < 50)
  {
      Serial.println(">>> RIGHT OBSTACLE <<<");
      setAlert(3);
  }
}
//==================================================
void setAlert(int mode)
{
  switch(mode)
  {
      case 1:
          digitalWrite(RED_LED,HIGH);
          ledcWriteTone(BUZZER,4000);
          delay(200);
          noTone(BUZZER);
          delay(200);
          break;
      case 2:
          digitalWrite(GREEN_LED,HIGH);
          ledcWriteTone(BUZZER,3500);
          delay(200);
          noTone(BUZZER);
          delay(200);
          break;
      case 3:
          digitalWrite(BLUE_LED,HIGH);

          ledcWriteTone(BUZZER,6000);
          delay(200);
          noTone(BUZZER);
          delay(200);
          break;
  }
}
void policeSiren()
{
  for(int i = 0; i < 6; i++)
  {
    ledcWriteTone(BUZZER, 1000);
    delay(150);

    ledcWriteTone(BUZZER, 3000);
    delay(150);
  }
  ledcWriteTone(BUZZER, 0);
}