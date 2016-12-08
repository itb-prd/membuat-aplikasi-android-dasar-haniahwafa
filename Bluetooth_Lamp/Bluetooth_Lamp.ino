byte serialA;
int ledlevel=0;
void setup() {
  pinMode (8,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available ()>0) {
    serialA = Serial.read();
    Serial.println(serialA);
  }
  switch (serialA) {
    case 1: digitalWrite (8,1);
            ledlevel=255;
            break;
    case 2: digitalWrite (8,0);
            break;
    case 3: ledlevel=ledlevel+51;
            if(ledlevel>255) ledlevel=0;
            digitalWrite (8,ledlevel);
            break;
    default: break;
  }
}
