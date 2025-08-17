// with toggle
int switchState;
int toggleState = LOW;
bool hasTriggered = false; // memory cell for latch logic gate

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  Serial.begin(9600); // debugging with serial
}

void loop() {
  switchState = digitalRead(2);
  if (switchState == HIGH and !hasTriggered) {
    if (toggleState == LOW) {
      toggleState = HIGH;
      Serial.println("toggleSate is high");
    }
    else {
      toggleState = LOW;
      Serial.println("toggleSate is low");
    }
    Serial.println("hasTriggered is true");
    hasTriggered = true;
  }
  if (switchState == LOW and hasTriggered) {
    Serial.println("hasTriggered is false");
    hasTriggered = false;
  }

  if (toggleState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else {
    digitalWrite(3, LOW);

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);

    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(250);
  }
}
