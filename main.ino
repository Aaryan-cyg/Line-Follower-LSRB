// Line Follower Bot(5 IR Sensors) 
// Arduino Uno + L298N Motor Driver


// --- Motor Pins ---
#define LEFT_MOTOR_FORWARD 5
#define LEFT_MOTOR_BACKWARD 6
#define RIGHT_MOTOR_FORWARD 9
#define RIGHT_MOTOR_BACKWARD 10


#define S1 A0  // Left-most
#define S2 A1  
#define S3 A2 
#define S4 A3  
#define S5 A4  // Right-most

int s1, s2, s3, s4, s5;
int lastDirection = 0; 


void setup() {
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  Serial.begin(9600);
}


void forward() {
  digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}

void left() {
  digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}

void right() {
  digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}

void stopBot() {
  digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}


void readSensors() {
  s1 = digitalRead(S1);
  s2 = digitalRead(S2);
  s3 = digitalRead(S3);
  s4 = digitalRead(S4);
  s5 = digitalRead(S5);

  Serial.print(s1);
  Serial.print(" ");
  Serial.print(s2);
  Serial.print(" ");
  Serial.print(s3);
  Serial.print(" ");
  Serial.print(s4);
  Serial.print(" ");
  Serial.println(s5);
}


void loop() {
  readSensors();



  if (s3 == 0 && s2 == 1 && s4 == 1 && s1 == 1 && s5 == 1) {
    forward();
    lastDirection = 0;
  }
  else if (s2 == 0 && s3 == 0) {
    left();
    lastDirection = 1;
  }
  else if (s4 == 0 && s3 == 0) {
    right();
    lastDirection = 2;
  }
  else if (s1 == 0 || (s1 == 0 && s2 == 0)) {
    left();
    lastDirection = 1;
  }
  else if (s5 == 0 || (s5 == 0 && s4 == 0)) {
    right();
    lastDirection = 2;
  }
  else if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0) {
    stopBot(); 
  }
  else if (s1 == 1 && s2 == 1 && s3 == 1 && s4 == 1 && s5 == 1) {

    if (lastDirection == 1) {
      left(); 
      delay(200);
    } else if (lastDirection == 2) {
      right();
      delay(200);
    } else {

      left();
      delay(150);
      right();
      delay(150);
    }
  }
  else {
    forward(); 
    lastDirection = 0;
  }

  delay(10); 
}
