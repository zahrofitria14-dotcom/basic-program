// === Pin Sensor (ubah sesuai wiring kamu) ===
#define sensorPower 25      // GPIO25 untuk memberi tegangan ke sensor
#define sensorPin 34        // GPIO34 input analog dari sensor

// Variabel untuk simpan data
int val = 0;

void setup() {
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW); // default OFF

  Serial.begin(115200);
  delay(1000);
  Serial.println("Water Level Sensor ESP32 Ready...");
}

void loop() {
  // Hidupkan sensor
  digitalWrite(sensorPower, HIGH);
  delay(10);   // tunggu sebentar agar stabil

  // Baca analog (0 - 4095)
  val = analogRead(sensorPin);

  // Matikan sensor (hemat daya & biar gak korosi)
  digitalWrite(sensorPower, LOW);

  // Tampilkan hasil
  Serial.print("Water Level (ADC 0-4095): ");
  Serial.println(val);

  // Tambahan interpretasi ketinggian air
  if (val < 1000) {
    Serial.println("Status: Kering");
  } else if (val < 2000) {
    Serial.println("Status: Air Rendah");
  } else if (val < 3000) {
    Serial.println("Status: Air Sedang");
  } else {
    Serial.println("Status: Air Tinggi");
  }

  Serial.println("-------------------------");
  delay(2000);  // baca tiap 2 detik
}
