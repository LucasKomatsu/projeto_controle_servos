#include <Servo.h>

// Define os pinos dos módulos joysticks
const int JoyStick1_X = A4; // Pino analógico do joystick 1 - eixo X
const int JoyStick1_Y = A5; // Pino analógico do joystick 1 - eixo Y
const int JoyStick2_X = A2; // Pino analógico do joystick 2 - eixo X
const int JoyStick2_Y = A3; // Pino analógico do joystick 2 - eixo Y

// Define os pinos dos servomotores
const int servoPin1 = 3; // Pino de controle do servomotor garra
const int servoPin2 = 5; // Pino de controle do servomotor 2
const int servoPin3 = 6; // Pino de controle do servomotor 3
const int servoPin4 = 9; // Pino de controle do servomotor 4

const int botao = 4;
const int led = 10;
Servo servo_garra;
Servo servo_base;
Servo servo_altura;
Servo servo_inclinacao;

void setup() {
  // Inicializa os servomotores
  pinMode(JoyStick1_X, INPUT); // Configura o pino do joystick como entrada
  pinMode(JoyStick1_Y, INPUT);
  pinMode(JoyStick2_X, INPUT);
  pinMode(JoyStick2_Y, INPUT);
  servo_garra.attach(servoPin1);
  servo_base.attach(servoPin2);
  servo_altura.attach(servoPin3);
  servo_inclinacao.attach(servoPin4);
  
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);

  servo_inclinacao.write(90);
  servo_altura.write(135);
  servo_garra.write(90);
  servo_base.write(90);
  

  Serial.begin(9600);
}

void loop() {

  int estado_botao = digitalRead(botao);

  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      sendServoPositions();
    }
  }

  if (estado_botao == HIGH) {
    
    sendServoPositions(); // Liga o LED
  }

  // Lê os valores dos joysticks
  int JoyStick1_X_val = analogRead(JoyStick1_X);
  int JoyStick1_Y_val = analogRead(JoyStick1_Y);
  int JoyStick2_X_val = analogRead(JoyStick2_X);
  int JoyStick2_Y_val = analogRead(JoyStick2_Y);

  

  // Controla o servomotor 1 com o joystick 1
  if (JoyStick2_X_val < 300 && servo_garra.read() < 112) {
    servo_garra.write(servo_garra.read() + 1);
  } else if (JoyStick2_X_val > 700 && servo_garra.read() > 64) {
    servo_garra.write(servo_garra.read() - 1);
  }

  // Controla o servomotor 2 com o joystick 1
  if (JoyStick1_Y_val >700 && servo_base.read() < 175) {
    servo_base.write(servo_base.read() + 1);
  } else if (JoyStick1_Y_val < 300 && servo_base.read() > 20) {
    servo_base.write(servo_base.read() - 1);
  }

  // Controla o servomotor 3 com o joystick 2
  if (JoyStick1_X_val > 700  && servo_altura.read() < 175) {
    servo_altura.write(servo_altura.read() + 1);
  } else if (JoyStick1_X_val < 300 && servo_altura.read() > 90) {
    servo_altura.write(servo_altura.read() - 1);
  }

  // Controla o servomotor 4 com o joystick 2
  if (JoyStick2_Y_val < 300 && servo_inclinacao.read() < 175) {
    servo_inclinacao.write(servo_inclinacao.read() + 1);
  } else if (JoyStick2_Y_val > 700 && servo_inclinacao.read() > 90) {
    servo_inclinacao.write(servo_inclinacao.read() - 1);
  }

  // Aguarda um curto intervalo antes de ler novamente os joysticks
  delay(20);
  

}

void sendServoPositions() {
  digitalWrite(led, HIGH); // Liga o LED
  servo_garra.write(65);
  delay(20);
  servo_base.write(90);
  delay(20);
  servo_altura.write(135);
  delay(20);
  servo_inclinacao.write(90);

  //pegou
  delay(1000);
  for(int i = 90; i < 114; i++){
  servo_base.write(i);
  delay(50);
  }
  for(int i = 135; i > 123; i--){
  servo_altura.write(i);
  delay(50);
  }
  for(int i = 90; i < 111; i++){
  servo_inclinacao.write(i);
  delay(50);
  }
  for(int i = 65; i < 112; i++){
  servo_garra.write(i);
  delay(50);
  }

  //deixou
  for(int i = 112; i > 70; i--){
  servo_base.write(i);
  delay(50);
  }

  for(int i = 125; i > 110; i--){
  servo_altura.write(i);
  delay(50);
  }

  for(int i = 110; i < 127; i++){
  servo_inclinacao.write(i);
  delay(50);
  }
  for(int i = 110; i > 65; i--){
  servo_garra.write(i);
  delay(50);
  }


  //segundo
  for(int i = 110; i < 120; i++){
  servo_altura.write(i);
  delay(50);
  }

  for(int i = 127; i > 116; i--){
  servo_inclinacao.write(i);
  delay(50);
  }

  for(int i = 70; i < 114; i++){
  servo_base.write(i);
  delay(50);
  }

  for(int i = 65; i < 114; i++){
  servo_garra.write(i);
  delay(50);
  }

  //deixou segundo
  for(int i = 112; i > 71; i--){
  servo_base.write(i);
  delay(50);
  }

  for(int i = 120; i > 116; i--){
  servo_altura.write(i);
  delay(50);
  }

  for(int i = 116; i < 124; i++){
  servo_inclinacao.write(i);
  delay(50);
  }

  for(int i = 110; i > 64; i--){
  servo_garra.write(i);
  delay(50);
  }
  
  //pegou terceiro

  for(int i = 70; i < 114; i++){
  servo_base.write(i);
  delay(50);
  }

  for(int i = 110; i < 116; i++){
  servo_altura.write(i);
  delay(50);
  }

  for(int i = 127; i > 123; i--){
  servo_inclinacao.write(i);
  delay(50);
  }
  for(int i = 65; i < 110; i++){
  servo_garra.write(i);
  delay(50);
  }

  //deixou terceiro
  for(int i = 114; i < 125; i++){
  servo_altura.write(i);
  delay(50);
  }

  for(int i = 121; i > 115; i--){
  servo_inclinacao.write(i);
  delay(50);
  }
  
  for(int i = 112; i > 71; i--){
  servo_base.write(i);
  delay(50);
  }

  for(int i = 110; i > 64; i--){
  servo_garra.write(i);
  delay(50);
  }

//voltou
  for(int i = 71; i < 91; i++){
  servo_base.write(i);
  delay(30);
  }
  for(int i = 125; i < 135; i++){
  servo_altura.write(i);
  delay(30);
  }
  for(int i = 115; i > 90; i--){
  servo_inclinacao.write(i);
  delay(30);
  }
  digitalWrite(led, LOW);


}