const int trigPin = 12; //sends signal
const int echoPin = 13; //reads duration
const double threshold = 7; //7 cm threshold
int score = 0; //keeps track of score

const int buzzerPin = 6; // ADDED: pin for buzzer

void setup() {
  Serial.begin(9600); //speed of communication between arduino and computer

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(buzzerPin, OUTPUT); // ADDED: set buzzer pin as output
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

  if (detectShot())
  {
    Serial.print("Basketball Detected");
    score += 1;

    digitalWrite(buzzerPin, HIGH); // ADDED: turn buzzer on when shot detected
    delay(300);                    // ADDED: short beep duration (0.3 sec)
    digitalWrite(buzzerPin, LOW);  // ADDED: turn buzzer off

    delay(1000); // pause 1 second before next detection
  }

}
