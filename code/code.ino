# define led 13
# define left_ir 3 

void setup() {
  pinMode(led, OUTPUT);
  pinMode(left_ir, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(3) == LOW) {
    digitalWrite(13, HIGH);
    delay(100);
  } else {
    digitalWrite(13, LOW);
    delay(100);
  }
}
