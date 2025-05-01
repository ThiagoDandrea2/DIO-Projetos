#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

const int relePin = 8; // Pino digital ligado ao módulo relé

void setup() {
  Serial.begin(9600);
  pinMode(relePin, OUTPUT);
  digitalWrite(relePin, LOW); // Desligado inicialmente

  if (!rtc.begin()) {
    Serial.println("Não foi possível encontrar o RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC perdeu a alimentação, ajustando horário...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now();

  int hora = now.hour();
  int minuto = now.minute();

  // Verifica se está dentro dos horários de irrigação
  if ((hora == 6 && minuto < 15) || (hora == 17 && minuto < 15)) {
    digitalWrite(relePin, HIGH); // Liga a irrigação
    Serial.println("Irrigação ATIVADA");
  } else {
    digitalWrite(relePin, LOW); // Desliga a irrigação
    Serial.println("Irrigação DESLIGADA");
  }

  delay(60000); // Aguarda 1 minuto entre checagens
}
