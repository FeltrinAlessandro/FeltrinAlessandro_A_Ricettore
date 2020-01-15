String caratteri = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.";
String codiceMorse[] = {"._","_...","_._.","_..",".",".._.","__.","....","..",".___","_._","._..","__","_.","___",".__.","__._","._.","...","_",".._","..._",".__","_.._","_.__","__..","._._._"};
int luminosita;
int pinSensore;
int tempoIniziale;
int tempoFinale;
int tempo;
String morse; 
void setup() {
  // put your setup code here, to run once:
  pinSensore = A5;
  pinMode(pinSensore,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  luminosita = analogRead(pinSensore);
  if(luminosita>=400)
  {
    tempoIniziale = millis();
    while(luminosita>=400)
    {
      luminosita = analogRead(pinSensore);
    }
    tempoFinale = millis();
    tempo = tempoFinale - tempoIniziale;

    if(tempo>=400 && tempo<=600)
    {
      
    }
  }
}
