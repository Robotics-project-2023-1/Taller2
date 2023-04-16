unsigned long TiempoInicial = 0;
unsigned long TiempoFinal = 0;
const int pinENA1 = 13; //13
const int pinIN1 = 12;  //12
const int pinIN2 = 11;  //11
const int pinENA2 = 8; //8
const int pinIN3 = 10; //10
const int pinIN4 = 9; //9

#define Encoder1_output_A 2 // 2NARANJA
#define Encoder1_output_B 4 // 4VERDE
#define Encoder2_output_A 3 // 3NARANJA
#define Encoder2_output_B 5 // 5VERDE

float Count1_pulses = 0;
float Count2_pulses = 0;
float Grados1_anteriores = 0;
float Grados2_anteriores = 0;
float Grados1_actuales = 0;
float Grados2_actuales = 0;
float pulsos1 = 0;
float pulsos2 = 0;
int i = 0;
int pwm = 0;      //velocidad de giro 80% (200/255)
bool imprimir = false;
int anular = 0;


// Ec vel lineal en centimetros vel = 0.24pwm + 16.82
// pwm = (vel - 16.82)/0.24

// Regla de 3 vel angular, con pwm = 150, hace 1 vuelta en 1.9s. Es decir, 360/1.9 = 189grad/s

// Vel lineal max y min = [50,80]
// Vel angular max y min = [180,305]
void setup()
{
  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinENA1, OUTPUT);
  pinMode(pinIN3, OUTPUT);
  pinMode(pinIN4, OUTPUT);
  pinMode(pinENA2, OUTPUT);
  Serial.begin(115200);
  pinMode(Encoder1_output_A, INPUT); // sets the Encoder_output_A pin as the input
  pinMode(Encoder1_output_B, INPUT); // sets the Encoder_output_B pin as the input
  attachInterrupt(digitalPinToInterrupt(Encoder1_output_A), DC_Motor_Encoder1, RISING);
  pinMode(Encoder2_output_A, INPUT); // sets the Encoder_output_A pin as the input
  pinMode(Encoder2_output_B, INPUT); // sets the Encoder_output_B pin as the input
  attachInterrupt(digitalPinToInterrupt(Encoder2_output_A), DC_Motor_Encoder2, RISING);
}

void loop() {

  if (Serial.available() > 0) {
    // Read the incoming string
    String integer_string = Serial.readStringUntil('\n');
    // Convert the string to an integer array
    int integer_array[2];
    int i = 0;
    char* token = strtok((char*)integer_string.c_str(), ",");
    while (token != NULL && i < 2) {
      integer_array[i] = atoi(token);
      i++;
      token = strtok(NULL, ",");
    }
    if ((integer_array[0] == 0) && (integer_array[1] == 0 )) {
       //Serial.println(anular);
      if (anular == 1) {Count2_pulses = 0;}
      else if (anular == 2) {Count1_pulses = 0;}
      TiempoFinal = millis();
      digitalWrite(pinIN1, LOW);
      digitalWrite(pinIN2, LOW);
      analogWrite(pinENA1, 0);
      digitalWrite(pinIN3, LOW);
      digitalWrite(pinIN4, LOW);
      analogWrite(pinENA2, 0);
      pulsos1 = Count1_pulses;
      pulsos2 = Count2_pulses;
      //Serial.println(pulsos1);
      //Serial.println(pulsos2);      
      Grados1_actuales = pulsos1 * 360.0 / 77.0;
      Grados2_actuales = pulsos2 * 360.0 / 77.0;
      imprimir = true;
      anular = 0;

    }
    else if (integer_array[0] > 0 ) { //Si el comando es "on"
      TiempoInicial = millis();
      pwm = (integer_array[0] - 16.82) / 0.24;
      //Serial.println("1");
      digitalWrite(pinIN1, LOW);
      digitalWrite(pinIN2, HIGH);
      analogWrite(pinENA1, 200);
      digitalWrite(pinIN3, LOW);
      digitalWrite(pinIN4, HIGH);
      analogWrite(pinENA2, 200);
    }
    else if (integer_array[0] < 0 ) {
      TiempoInicial = millis();
      pwm = (abs(integer_array[0]) - 16.82) / 0.24;
      //Serial.println("2");
      digitalWrite(pinIN1, HIGH);
      digitalWrite(pinIN2, LOW);
      analogWrite(pinENA1, 200);
      digitalWrite(pinIN3, HIGH);
      digitalWrite(pinIN4, LOW);
      analogWrite(pinENA2, 200);

    }
    else if (integer_array[1] > 0 ) { // Funciona
      anular = 2;
      TiempoInicial = millis();
      //pwm = (150*integer_array[1])/189;
      //Serial.println("3");
      digitalWrite(pinIN1, LOW);
      digitalWrite(pinIN2, LOW);
      analogWrite(pinENA1, 0);
      digitalWrite(pinIN3, LOW);
      digitalWrite(pinIN4, HIGH);
      analogWrite(pinENA2, 200);
    }
    else if (integer_array[1] < 0 ) {
      TiempoInicial = millis();
      anular = 1;
      //pwm = (150*abs(integer_array[1]))/189;
      digitalWrite(pinIN1, LOW);
      digitalWrite(pinIN2, HIGH);
      analogWrite(pinENA1, 200);
      digitalWrite(pinIN3, LOW);
      digitalWrite(pinIN4, LOW);
      analogWrite(pinENA2, 0);

    }

    i = 0;

  }
        Serial.print(String(Grados1_actuales));
        Serial.print(",");
        Serial.print(String(Grados2_actuales));
        Serial.print(",");
        Serial.println(String(TiempoFinal - TiempoInicial));

   if (imprimir == true){
        Count1_pulses = 0;
        Count2_pulses = 0;
        imprimir = false;
        TiempoInicial = 0;
        TiempoFinal = 0;
        Grados1_actuales = 0;
        Grados2_actuales = 0;
  } 
  
  delay(50);
}

void DC_Motor_Encoder1() {
  int b1 = digitalRead(Encoder1_output_B);
  if (b1 > 0) {
    Count1_pulses++;
  }
  else {
    Count1_pulses--;
  }
}

void DC_Motor_Encoder2() {
  int b2 = digitalRead(Encoder2_output_B);
  if (b2 > 0) {
    Count2_pulses++;
  }
  else {
    Count2_pulses--;
  }
}
