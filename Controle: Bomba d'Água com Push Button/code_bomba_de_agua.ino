int bomba = 2; //Bomba no pino 2
int botao = 3; //Botão para acionar a bomba no pino 3

void setup() {
  pinMode(bomba, OUTPUT);
  pinMode(botao, INPUT);

}

void loop() {
  //Verifica se o botão foi pressionado
  int bton = digitalRead(botao);
  //Liga a bomba
  if(bton == HIGH){
    ligaBomba();
  }
  else{
  desligaBomba();
  
  }
}

void ligaBomba(){
  digitalWrite(bomba, HIGH);

  
}

void desligaBomba(){
  digitalWrite(bomba, LOW);

  
}
