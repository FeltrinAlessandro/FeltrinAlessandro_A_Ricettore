#include <stdio.h>
#include <stdlib.h>
String caratteri = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.";
String codiceMorse[] = {"._","_...","_._.","_..",".",".._.","__.","....","..",".___","_._","._..","__","_.","___",".__.","__._","._.","...","_",".._","..._",".__","_.._","_.__","__..","._._._"};
int luminosita;
int pinSensore;
int tempoIniziale;
int tempoFinale;
int tempo;
String morse; 

typedef struct nodo{
  char lettera; 
  struct nodo* next;
  }Lista;
  
  Lista* listaChar = NULL;
  
void setup() {
  // put your setup code here, to run once:
  pinSensore = A5;
  pinMode(pinSensore,INPUT);
  Serial.begin(9600);
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
      morse = morse + ".";
    }
    else if(tempo>=900 && tempo<=1100)
    {
      morse = morse + "_";
    }
    else if(tempo>=1900 && tempo <= 2100)
    {
      char c = traduciCodice(morse);
      listaChar = aggiungiCarattere(listaChar,c);
      if(c== '.')
      {
        print_list(listaChar);
      }
      morse = ""; 
    }
  }
}

char traduciCodice(String s)//metodo che trasforma un segnale morse in char
{
  int indice = trovaIndice(s);
  return caratteri[indice];
}

int trovaIndice(String s)//metodo che trova l'indice della string s nella Lista codiceMorse
{
  int contatore = 0;
  while(contatore < 27)
  {
    if(codiceMorse[contatore]==s)
    {
      return contatore;
    }
    contatore++;
  }
}

Lista* creaNodo(char s)//metodo che crea un nodo di tipo Lista
{
  Lista* n = (Lista*) malloc(sizeof(Lista));
  n-> lettera = s;
  n-> next = NULL;
  return n;
}

Lista* aggiungiCarattere(Lista* l, char s)//metodo che aggiunge un carattere alla Lista l 
{
  if(l==NULL)
  {
    Lista* n = creaNodo(s);
    return n;  
  }
  else
  {
    l -> next = aggiungiCarattere(l -> next, s);
    return l;
  }
}

void print_list(Lista* l)//metodo che fa il print di tutta la Lista l
{
  Lista* current = l;
  char c;

  while(current!=NULL)
  {
    c = current->lettera;
    Serial.print(c);
    current = current->next; 
  }
  listaChar = NULL;
}
