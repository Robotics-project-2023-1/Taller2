String inputString = "";      // Cadena para guardar el comando recibido
bool stringComplete = false;  // Bandera boleana que nos indica cuando el comando fue recibido y podemos compararlo con los 2 comandos válidos
int comando;
const int pinENA1 = 13;
const int pinIN1 = 12;
const int pinIN2 = 14;

const int pinENA2 = 27;
const int pinIN3 = 26;
const int pinIN4 = 25;


const int LED = 27;

const int speed = 230;      //velocidad de giro 80% (200/255)

void setup()
{
   pinMode(pinIN1, OUTPUT);
   pinMode(pinIN2, OUTPUT);
   pinMode(pinENA1, OUTPUT);
   pinMode(pinIN3, OUTPUT);
   pinMode(pinIN4, OUTPUT);
   pinMode(pinENA2, OUTPUT);
   pinMode(LED, OUTPUT);
   digitalWrite(LED,HIGH);
   delay(2000);
   digitalWrite(LED,LOW);
   Serial.begin(9600);
   //inputString.reserve(200);
}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming string
    String integer_string = Serial.readStringUntil('\n');
    // Convert the string to an integer array
    int integer_array[2];
    int i = 0;
    char* token = strtok((char*)integer_string.c_str(), ",");
    while (token != NULL && i<2) {
      integer_array[i] = atoi(token);
      i++;
      token = strtok(NULL, ",");
    }
    
   if (integer_array[0] == 0 ){
    digitalWrite(pinIN1, LOW);
    digitalWrite(pinIN2, LOW);
    analogWrite(pinENA1, 0);
    digitalWrite(pinIN3, LOW);
    digitalWrite(pinIN4, LOW);
    analogWrite(pinENA2, 0);

    }
    else if (integer_array[0] < 0 ){//Si el comando es "on"
      digitalWrite(pinIN1, LOW);
      digitalWrite(pinIN2, HIGH);
      analogWrite(pinENA1, 200);
      digitalWrite(pinIN3, LOW);
      digitalWrite(pinIN4, HIGH);
      analogWrite(pinENA2, 200);
    }
    else if (integer_array[0] > 0 ){
      digitalWrite(pinIN1, HIGH);
      digitalWrite(pinIN2, LOW);
      analogWrite(pinENA1, 200);
      digitalWrite(pinIN3, HIGH);
      digitalWrite(pinIN4, LOW);
      analogWrite(pinENA2, 200);
    }
    //else if (integer_array[1] => 0 ){
      //int b = 1;
    //}
    
    i = 0;

  }
  delay(100);
   

  }

