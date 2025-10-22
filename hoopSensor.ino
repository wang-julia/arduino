
const int trigPin = 12; //sends signal
const int echoPin = 13; //reads duration
const double threshold = 7; //7 cm threshold
int score = 0; //keeps track of score


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //speed of communication between arduino and computer

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 

}

double distance()
{
  double duration = 0; 
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(50);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  return (duration/2) / 29.1; //distance in cm
}

boolean detectShot()
{
  return distance() <= threshold; 
}

void loop() {
  // put your main code here, to run repeatedly:

  if (detectShot())
  {
    Serial.print("Basketball Detected");
    score += 1;
    delay(1000); // 1 second
  }
  

}

