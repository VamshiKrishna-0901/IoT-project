# define left_ir 13
# define down_ir 12
# define right_ir 11
# define up_ir 10

# define left_red 9 
# define left_yellow 8
# define left_green 7

# define down_red 6
# define down_yellow 5
# define down_green 4

# define right_red 3
# define right_yellow 2
# define right_green 1

# define up_red A1
# define up_yellow A2
# define up_green A3

# define stoppingTime 4
# define waitingTime 2
# define goTime 7

void setup() {
  pinMode(left_ir, INPUT);
  pinMode(down_ir, INPUT);
  pinMode(right_ir, INPUT);
  pinMode(up_ir, INPUT);

  pinMode(left_red, OUTPUT);
  pinMode(left_yellow, OUTPUT);
  pinMode(left_green, OUTPUT);

  pinMode(down_red, OUTPUT);
  pinMode(down_yellow, OUTPUT);
  pinMode(down_green, OUTPUT);

  pinMode(right_red, OUTPUT);
  pinMode(right_yellow, OUTPUT);
  pinMode(right_green, OUTPUT);

  pinMode(up_red, OUTPUT);
  pinMode(up_yellow, OUTPUT);
  pinMode(up_green, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  non_traffic_rule();
  ifTraffic();
}

void non_traffic_rule() {
  delay(1000);
  digitalWrite(left_red, HIGH);
    delay(stoppingTime);
  digitalWrite(left_red, LOW);
  digitalWrite(left_yellow, HIGH);
    delay(waitingTime);
  digialWrite(left_yellow, LOW);
  digitalWrite(left_green, HIGH);
    delay(goTime);

  digitalWrite(left_green, LOW);
  digitalWrite(down_red, HIGH);
    delay(stoppingTime);
  digitalWrite(down_red, LOW);
  digitalWrite(down_yellow, HIGH);
    delay(waitingTime);
  digitalWrite(down_yellow, LOW);
  digitalWrite(down_green, HIGH);
    delay(goTime);

  digitalWrite(down_green, LOW;
  digitalWrite(right_red, HIGH);
    delay(stoppingTime);
  digitalWrite(right_red, LOW);
  digitalWrite(right_yellow, HIGH);
    delay(waitingTime);
  digitalWrite(right_yellow, LOW);
  digitalWrite(right_green, HIGH);
    delay(goTime);

  digitalWrite(right_green, LOW);
  digitalWrite(up_red, HIGH);
    delay(stoppingTime);
  digitalWrite(up_red, LOW);
  digitalWrite(up_yellow, HIGH);
    delay(waitingTime);
  digitalWrite(up_yellow, LOW);
  digitalWrite(up_green, HIGH);
    delay(goTime);
  digitalWrite(up_green, LOW);
}

void ifTraffic() {
  ifonlyOneLane();
  ifBothLanes();
  ifTripleLanes();
  totalTraffic();
}