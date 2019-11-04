int trigPin = 8;
int echoPin = 9;
int buzzer = 10;

long duration;
float distanceCm;
int timer;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  /* By keeping the trigger on for 10 microseconds, 8 40khz square waves will be sent automatically, this will detect the object by the echo pin */

  duration = pulseIn(echoPin, HIGH);
  
  distanceCm = duration * (0.033/2);    // Calculates distance in Centimeters

  digitalWrite(buzzer, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);

  timer = distanceCm * 10;

  delay(timer);
}
