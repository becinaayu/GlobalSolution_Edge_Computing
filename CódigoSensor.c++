#include <LiquidCrystal.h>

int pot = 0;
int vermelho = 7;
int amarelo = 6;
int verde = 5;
float tensao = 0, temp = 0;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
}

void loop()
{
  lcd.clear();
  lcd.print("Temp: ");

  pot = analogRead(A0);
  tensao = pot * (5.0 / 1024);
  temp = (tensao - 0.5) / 0.01;

  lcd.print(int(temp));  
  lcd.print(" oC");

  if (temp < 35)
  {
    digitalWrite(vermelho, LOW);
    digitalWrite(amarelo, HIGH);
    digitalWrite(verde, LOW);
  }
  else if (temp < 38) 
  {
    digitalWrite(vermelho, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(verde, HIGH);
  }
  else
  {
    digitalWrite(vermelho, HIGH);
    digitalWrite(amarelo, LOW);
    digitalWrite(verde, LOW);
  }

  delay(1000);
}
