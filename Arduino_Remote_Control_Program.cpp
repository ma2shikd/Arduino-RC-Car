const int PBA =8;

const int PBB =9;

const int PBC =4;

const int PBD =7;

const int LEDRED = 13;

void setup() {

  Serial.begin(9600); 

  pinMode(PBA, INPUT); 

  pinMode(PBB,INPUT);

  pinMode(PBC,INPUT);

  pinMode(PBD,INPUT);

  pinMode(LEDRED,OUTPUT);

}



void loop() {

  if (digitalRead(PBB) == HIGH) {

    Serial.write('J');

    digitalWrite(LEDRED,HIGH);

    delay(200); 

  }

  if (digitalRead(PBA) == HIGH) {

    digitalWrite(LEDRED,HIGH);

    Serial.write('H');

    delay(200); 

  }


  if (digitalRead(PBC) == HIGH) {

    digitalWrite(LEDRED,HIGH);

    Serial.write('G');

    delay(200); 

  }

  if (digitalRead(PBD) == HIGH) {

    digitalWrite(LEDRED,HIGH);

    Serial.write('F');

    delay(200);

  }

  

    

   else if (digitalRead(PBB)== LOW && digitalRead(PBA)==LOW && digitalRead(PBC) == LOW && digitalRead(PBD)== LOW) {

    digitalWrite(LEDRED,LOW);

    Serial.write('L'); 

    delay(200);       

  }

}