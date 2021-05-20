const int EchoPin = 5;
const int TriggerPin = 6;
const int EchoPin2 = 2;
const int TriggerPin2 = 3;

void setup() {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   pinMode(TriggerPin2, OUTPUT);
   pinMode(EchoPin2, INPUT);
}

void loop() {
   int cm = ping(TriggerPin, EchoPin);
   int cm2 = ping(TriggerPin2, EchoPin2);
   Serial.print("A");
   Serial.println(cm);
   Serial.print("B");
   Serial.println(cm2);
   delay(200);
}

int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}
int ping2(int TriggerPin2, int EchoPin2) {
   long duration2, distanceCm2;
   
   digitalWrite(TriggerPin2, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin2, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin2, LOW);
   
   duration2 = pulseIn(EchoPin2, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm2 = duration2 * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm2;
}
