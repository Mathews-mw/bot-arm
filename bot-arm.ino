#include <Servo.h>
#define ANGULO_INICIAL_MOTOR 90

// Mapeamento dos joysticks
#define joystick1X A0
#define joystick1Y A1
#define joystick2X A2
#define joystick2Y A3

// Mapeamento dos servos
Servo motorBase;
Servo motorBracoEsq;
Servo motorBracoDir;
Servo motorGarra;

void setup() {
  mapearPinosMotores();
  mapearJoystickInputs();
  inicializacaoAngulosMotores();
}

void loop() {
  

  delay(100);

}

void mapearPinosMotores() {
  motorBase.attach(5);
  motorBracoEsq.attach(6);
  motorBracoDir.attach(9);
  motorGarra.attach(10);
}

void inicializacaoAngulosMotores() {
  motorBase.write(ANGULO_INICIAL_MOTOR);
  motorBracoEsq.write(ANGULO_INICIAL_MOTOR);
  motorBracoDir.write(ANGULO_INICIAL_MOTOR);
  motorGarra.write(ANGULO_INICIAL_MOTOR);
}

void mapearJoystickInputs() {
  pinMode(joystick1X, INPUT);
  pinMode(joystick1Y, INPUT);
  pinMode(joystick2X, INPUT);
  pinMode(joystick2Y, INPUT);
}

void moverBase() {
  int posX1 = analogRead(joystick1X);
  posX1 = map(posX1, 0, 1023, 0, 180);
  motorBase.write(posX1);
}

void moverBracoEsq() {
  int posY1 = analogRead(joystick1Y);
  posY1 = map(posY1, 0, 1023, 45, 135);
  motorBracoEsq.write(posY1);
}

void moverBracoDir() {
  int posY2 = analogRead(joystick2Y);
  posY2 = map(posY2, 0, 1023, 50, 90);
  motorBracoDir.write(posY2);
}

void moverGarra() {
  int posX2 = analogRead(joystick2X);
  posX2 = map(posX2, 0, 1023, 90, 130);
  motorGarra.write(posX2);
}
