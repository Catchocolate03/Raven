#include<SoftwareSerial.h>;
int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;
int enA = 8;
int enB = 9;
char comando = 's';
const int pinoRX = 2;
const int pinoTX = 3;
SoftwareSerial bluetooth(pinoRX, pinoTX);

void acelerar(){
  for(int i = 0; i < 256; i = i + 50){
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(30);
  }
}
void moverFrente(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  acelerar();
}

void moverTras(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  acelerar();
}

void moverEsquerda(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void moverDireita(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}
void moverParar(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  for(int i = 255; i >= 0; i = i - 10){
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(30);
  }
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
void mover(char comando){
  switch (comando){
    case 'w':
      moverFrente();
      break;
    case 'a':
      moverEsquerda();
      break;
    case 's':
      moverTras();
      break;
    case 'd':
      moverDireita();
      break;
    default:
      moverParar();
      break;
  }
}
