#include <LiquidCrystal.h>
const int rs = 12, e = 11, d4 = 4, d5 = 5, d6 =6, d7 =7;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
int temp;
int fan= 2;
int led= 1;
int sensorpin= A5;
int min_temp= 20;

void setup(){
  lcd.begin(16, 2);
  pinMode(fan, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop(){
  temp= analogRead(sensorpin);
  temp= temp*0.4883;
  if(temp < min_temp){
    digitalWrite(fan, LOW);
    lcd.print("FAN OFF. LED ON");
  }

if(temp >= min_temp){
  digitalWrite(fan, HIGH);
  digitalWrite(led, LOW);
  lcd.print("FAN ON, LED OFF");
}
else{
  digitalWrite(fan, LOW);
  digitalWrite(led, HIGH);
}
 lcd.setCursor(0, 1);  // pindahkan kursor ke baris berikutnya
  lcd.print("SUHU RUANGAN:");
  lcd.print(temp);
  lcd.print("C");

  delay(3000);

  lcd.clear();

  lcd.setCursor(0, 0);  // pindahkan kursor ke baris pertama
  lcd.print("KELOMPOK SATU");
  lcd.setCursor(0, 1);  // pindahkan kursor ke baris kedua
  lcd.print("MEKATRONIKA");

  delay(3000);  // Tunggu 5 detik sebelum mengganti teks

  lcd.clear();
}
