#include <Servo.h>

#define ANGULO_INICIAL_MOTOR 90

// --- Mapeamento dos Joysticks ---
#define joystick1X A0
#define joystick1Y A1
#define joystick2X A2
#define joystick2Y A3

// --- Mapeamento dos Servos ---
Servo motorBase;
Servo motorBraco1;
Servo motorBraco2;
Servo motorGarra;

void setup() {
  mapearPinosDosMotores();
  inicializarAngulosDosMotores();
  mapearJoysticksComoInput();

  Serial.begin(9600);
}

void loop() {
  moverBase();
  moverBraco1();
  moverBraco2();
  moverGarra();

  int x, y;
  int x2, y2;

  x = analogRead(joystick1X);
  y = analogRead(joystick1Y);
  x2 = analogRead(joystick2X);
  y2 = analogRead(joystick2Y);

  //Serial.print("x1: ");
  //Serial.print(x);
  //Serial.print(" y1: ");
  //Serial.println(y);

  //Serial.println("");

  //Serial.print("x2: ");
  //Serial.print(x2);
  //Serial.print(" y2: ");
  //Serial.println(y2);

  delay(200);
}

void mapearPinosDosMotores() {
  motorBase.attach(5);
  motorBraco1.attach(6);
  motorBraco2.attach(9);
  motorGarra.attach(10);
}

void inicializarAngulosDosMotores() {
  motorBase.write(ANGULO_INICIAL_MOTOR);
  motorBraco1.write(ANGULO_INICIAL_MOTOR);
  motorBraco2.write(ANGULO_INICIAL_MOTOR);
  motorGarra.write(180);
}


void mapearJoysticksComoInput() {
  pinMode(joystick1X, INPUT);
  pinMode(joystick1Y, INPUT);
  pinMode(joystick2X, INPUT);
  pinMode(joystick2Y, INPUT);
}

void moverBase() {
  int posX = analogRead(joystick1X);
  posX = map(posX, 0, 1023, 0, 180);
  motorBase.write(posX);

  //Serial.println("");
  //Serial.print("posição motor base: ");
  //Serial.print(posX);
}

void moverBraco1() {
  int posY = analogRead(joystick1Y);
  posY = map(posY, 0, 1023, 45, 135);
  motorBraco1.write(posY);

  //Serial.println("");
  //Serial.print("posição motor braço 1: ");
  //Serial.print(posY);
}

void moverBraco2() {
  int posX = analogRead(joystick2X);
  posX = map(posX, 0, 1023, 50, 120);
  motorBraco2.write(posX);

  Serial.println("");
  Serial.print("posição motor braço 2: ");
  Serial.print(posX);
}

void moverGarra() {
  int posY = analogRead(joystick2Y);
  posY = map(posY, 0, 1023, 90, 130);
  motorGarra.write(posY);

  Serial.println("");
  Serial.print("posição motor GARRA: ");
  Serial.print(posY);
}