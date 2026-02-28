#define IR_LEFT 10
#define IR_RIGHT 11

#define ENA 3
#define IN1 5
#define IN2 6

#define ENB 9
#define IN3 7
#define IN4 8

int baseSpeed = 80;

void setup() {
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, baseSpeed);
  analogWrite(ENB, baseSpeed);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, baseSpeed);
  analogWrite(ENB, baseSpeed);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, baseSpeed);
  analogWrite(ENB, baseSpeed);
}

void stopBot() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void loop() {

  int leftSensor = !digitalRead(IR_LEFT);
  int rightSensor = !digitalRead(IR_RIGHT);

  // If both detect line
  if (leftSensor == HIGH && rightSensor == HIGH) {
    forward();
  }
  // If left detects line → turn left
  else if (leftSensor == LOW && rightSensor == HIGH) {
    right();
  }
  // If right detects line → turn right
  else if (leftSensor == HIGH && rightSensor == LOW) {
    left();
  }
  // If no line detected
  else {
    stopBot();
  }
}
