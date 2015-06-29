const int PI_PIN = 0;
int val;
long last = 0;
int stat = LOW;
int stat2;
int contar = 0;

int sens = 2;  // this value indicates the limit reading between dark and light,
              // it has to be tested as it may change acording on the 
              // distance the leds are placed.
int nPalas = 18; // the number of blades of the propeller

int milisegundos = 10; // the time it takes each reading

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  val = map(analogRead(PI_PIN), 0, 1023, 0, 100);
  stat = val < sens? LOW : HIGH;
  digitalWrite(13,stat);
  
  if(stat2!=stat) {
     contar++;
     stat2=stat;
  }
  
  if(millis() - last >= milisegundos) {
     double rps= ((double) contar / nPalas) / 2.0 * 1000.0 / milisegundos;
     double rpm = ((double) contar / nPalas) / 2.0 * 60000.0 / milisegundos;
     Serial.print(contar / 2.0);
     Serial.print("  RPS ");
     Serial.print(rps);
     Serial.print(" RPM");
     Serial.print(rpm);
     Serial.print("  VAL ");
     Serial.println(val);
     contar = 0;
     last = millis();
   }
}
