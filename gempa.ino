#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

const char* ssid     = "zhrr";
const char* password = "1212121212";

#define BOT_TOKEN "7516890013:AAF1Lhwgxp5CrCCtOCvDncp67vjH9XJleTs"
#define CHAT_ID   "6059176005"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

const int pinSensorDO = 27;
const int pinBuzzer   = 26;

bool lastState = false;

void setup() {
  Serial.begin(115200);
  pinMode(pinSensorDO, INPUT);
  pinMode(pinBuzzer, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Menghubungkan ke WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Terhubung");
  secured_client.setInsecure();

  bot.sendMessage(CHAT_ID, "✅ Alat Pendeteksi Getaran Aktif!", "");
}

void loop() {
  int getaran = digitalRead(pinSensorDO);

  if (getaran == HIGH) {
    digitalWrite(pinBuzzer, HIGH);
    if (!lastState) {
      bot.sendMessage(CHAT_ID, "⚠️ GEMPA TERDETEKSI!", "");
      Serial.println("⚠️ GEMPA TERDETEKSI!");
      lastState = true;
    }
  } else {
    digitalWrite(pinBuzzer, LOW);
    if (lastState) {
      bot.sendMessage(CHAT_ID, "✅ Kondisi Aman", "");
      Serial.println("✅ Kondisi Aman");
      lastState = false;
    }
  }

  delay(300);
}
