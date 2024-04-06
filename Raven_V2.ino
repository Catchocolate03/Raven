#include<SoftwareSerial.h>;
int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;
char comando = 's';
const int pinoRX = 2;
const int pinoTX = 3;
SoftwareSerial bluetooth(pinoRX, pinoTX);

void motor1Frente(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void motor1Tras(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void motor1Parar(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void motor2Frente(){
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void motor2Tras(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void motor2Parar(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
  bluetooth.print("$"); 
  bluetooth.print("$"); 
  bluetooth.print("$");
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetooth.available()){
    comando = bluetooth.read();
    mover(comando);
    Serial.println(comando);
  }
}
void mover(char comando1){
  switch (comando1){
    case 'w':
      motor1Frente();
      break;
    case 'a':
      motor1Tras();
      break;
    case 's':
      motor2Frente();
      break;
    case 'd':
      motor2Tras();
      break;
    default:
      motor1Parar();
      motor2Parar();
      break;
  }
}
