#include<SoftwareSerial.h>;
int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;
char comando = 's';
const int pinoRX = 2;
const int pinoTX = 3;
SoftwareSerial bluetooth(pinoRX, pinoTX);

void moverFrente(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moverTras(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void moverEsquerda(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void moverDireita(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void moverParar(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
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
