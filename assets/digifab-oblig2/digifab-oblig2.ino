//Representerer pins som deres responderende led lys
int ledRed = 10;
int ledYellow = 9;
int ledGreen = 8;
//Setter knappen til en pin
int btn = 12;

void setup() {
  //Erklerer lysene som outputs
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  //Erklerer knappen som en input
  pinMode(btn, INPUT);
  //lyset skal starte grønt
  digitalWrite(ledGreen, HIGH);
}

//Delay kan ikke bli avbrutt, så laget min egen funksjon
void myDelay(unsigned int dly) {
  while (dly --) {
    delay(1);
    if (digitalRead (btn) == HIGH) {
      break;
    }
  }
}

void loop() {
  
  if (digitalRead(btn) == LOW){
    changeLights();
  } else if (digitalRead (btn) == HIGH){
      delay(15);
      changeLights();
      delay(10000);
  }
}

void changeLights(){
  //Skru av grønn, skru på gul i 3 sek
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, HIGH);
  //Hvis en fotgjenger trykker på knappen blir det grønt, og jeg antar alle kræsjer og dør.
  myDelay(3000);

  //Skru av gul, skru på rød i 2 sek
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, HIGH);
  //Hvis en fotgjenger trykker på knappen blir det grønt, og jeg antar alle kræsjer og dør.
  myDelay(2000);

  //rød er fremdeles på, ha også på gul i 2 sek
  digitalWrite(ledYellow, HIGH);
  //Hvis en fotgjenger trykker på knappen blir det grønt, og jeg antar alle kræsjer og dør.
  myDelay(2000);

  //Skru av gul og rød, sett på grønn i 3 sek
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
  //Hvis en fotgjenger trykker på knappen blir det grønt, og jeg antar alle kræsjer og dør.
  myDelay(3000);
}