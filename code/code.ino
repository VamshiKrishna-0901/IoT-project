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

int red_timer = 4;
int yellow_timer = 2;
int green_timer = 7;

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
  red_timer = 4;
  yellow_timer = 2;
  green_timer = 7;
  no_traffic_rules();
  if_traffic();
}

void no_traffic_rules() {
  set_lane_lights(left_red, left_yellow, left_green);
  set_lane_lights(down_red, down_yellow, down_green);
  set_lane_lights(right_red, right_yellow, right_green);
  set_lane_lights(up_red, up_yellow, up_green);
}

void if_traffic() {
  traffic_on_one_or_more_lanes();
  traffic_on_all_lanes();
}

void traffic_on_one_or_more_lanes() {
  if (digitalRead(left_ir)) {
    set_lane_lights(left_red, left_yellow, left_green, 3, 2, 10);
    set_lane_lights(down_red, down_yellow, down_green);
    set_lane_lights(right_red, right_yellow, right_green);
    set_lane_lights(up_red, up_yellow, up_green);
  } 
  
  if (digitalRead(right_ir)) {
    set_lane_lights(left_red, left_yellow, left_green);
    set_lane_lights(down_red, down_yellow, down_green);
    set_lane_lights(right_red, right_yellow, right_green, 3, 2, 10);
    set_lane_lights(up_red, up_yellow, up_green);
  }
  
  if (digitalRead(up_ir)) {
    set_lane_lights(left_red, left_yellow, left_green);
    set_lane_lights(down_red, down_yellow, down_green);
    set_lane_lights(right_red, right_yellow, right_green);
    set_lane_lights(up_red, up_yellow, up_green, 3, 2, 10);
  }
  
  if (digitalRead(down_ir)) {
    set_lane_lights(left_red, left_yellow, left_green);
    set_lane_lights(down_red, down_yellow, down_green, 3, 2, 10);
    set_lane_lights(right_red, right_yellow, right_green);
    set_lane_lights(up_red, up_yellow, up_green);
  }
}

void traffic_on_all_lanes() {
  red_timer = 3;
  green_timer = 10;
  no_traffic_rules();
}

void set_lane_lights(int red, int yellow, int green) {
  delay(1000);
  digitalWrite(red, HIGH);
  delay(red_timer);
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  delay(yellow_timer);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(green_timer);
  digitalWrite(green, LOW);
}

void set_lane_lights(int red, int yellow, int green, int first_timer, int second_timer, int third_timer) {
  delay(1000);
  digitalWrite(red, HIGH);
  delay(first_timer);
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  delay(second_timer);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(third_timer);
  digitalWrite(green, LOW);
}

