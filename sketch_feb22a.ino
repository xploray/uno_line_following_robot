#define IR_LEFT 10
#define IR_RIGHT 11

#define ENA 3
#define IN1 5
#define IN2 6

#define ENB 9
#define IN3 7
#define IN4 8

int baseSpeed = 170;
int turnDelay = 700;

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
  // Left motor backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, baseSpeed);
  analogWrite(ENB, baseSpeed);
    delay(turnDelay);
}

void right() {
  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, baseSpeed);
  analogWrite(ENB, baseSpeed);
    delay(turnDelay);
}

void stopBot() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay(1000);
}

void loop() {

  int leftSensor = !digitalRead(IR_LEFT);
  int rightSensor = !digitalRead(IR_RIGHT);

  if (leftSensor == HIGH && rightSensor == HIGH) {
    forward();
  }
  else if (leftSensor == HIGH && rightSensor == LOW) {
    stopBot();
    left();
  }
  else if (leftSensor == LOW && rightSensor == HIGH) {
    stopBot();
    right();
  }
  else {
    stopBot();
  }
}
