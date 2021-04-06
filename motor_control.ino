
// Testing motor control using H-bridge


// H-Bridge connections to Arduino Pins
int IN1 = 19;
int IN2 = 18;
int IN3 = 5;
int IN4 = 17;
float t = 4000; //time motor is on. Maybe improve by making it a function of weight
float dt = 4000;
int button = 2; 
int buttonpress = 0; //0 means button will cause upward movement, 1 means button will cause downward movement

void setup() { //setting the pins as output pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  pinMode(button, INPUT); //
  Serial.begin(115200); //serial monitor intialization, baud rate of 115200Hz
}

void MoveUp(){ // 
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);

}

void MoveDown(){ // 
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);

}

void loop() {
  //
// Rotate Motor clockwise = move waste bag up
//digitalWrite(IN1, HIGH);
//digitalWrite(IN2, LOW);
//digitalWrite(IN3, LOW);
//digitalWrite(IN4, LOW);

//Rotate Motor clockwise = move waste bag down
//digitalWrite(IN1, LOW);
//digitalWrite(IN2, LOW);
//digitalWrite(IN3, HIGH);
//digitalWrite(IN4, LOW);
while (button == HIGH){
  if (buttonpress = 0){ //Motor turns clockwise, bag moves up for time t
    MoveUp();
    delay(t);
    buttonpress = 1;} //Set buttonpress=1 so next press will move bag downwards
   else { //Motor turns counterclockwise, bag moves down for time dt
    MoveDown();
    delay(dt);
    buttonpress = 0;} //set buttonpress = 0 so next press will move it upwards
  }
}
