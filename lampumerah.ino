// === Pin Traffic Light Jalur A ===
#define A_MERAH   15
#define A_KUNING  2
#define A_HIJAU   21   // pindah dari GPIO4 ke GPIO21 (lebih aman)

// === Pin Traffic Light Jalur B ===
#define B_MERAH   5
#define B_KUNING  18
#define B_HIJAU   19

// === Waktu (ms) ===
int waktuHijau  = 5000;  // 5 detik hijau
int waktuKuning = 2000;  // 2 detik kuning
int waktuMerah  = 1000;  // 1 detik all-red (transisi aman)

void setup() {
  // Atur semua pin sebagai output
  pinMode(A_MERAH, OUTPUT);
  pinMode(A_KUNING, OUTPUT);
  pinMode(A_HIJAU, OUTPUT);

  pinMode(B_MERAH, OUTPUT);
  pinMode(B_KUNING, OUTPUT);
  pinMode(B_HIJAU, OUTPUT);

  matikanSemua();
}

void loop() {
  // === Fase 1: Jalur A Hijau, Jalur B Merah ===
  matikanSemua();
  digitalWrite(A_HIJAU, HIGH);
  digitalWrite(B_MERAH, HIGH);
  delay(waktuHijau);

  // === Transisi Jalur A Kuning ===
  digitalWrite(A_HIJAU, LOW);
  digitalWrite(A_KUNING, HIGH);
  delay(waktuKuning);

  // === All-Red Sebentar ===
  matikanSemua();
  digitalWrite(A_MERAH, HIGH);
  digitalWrite(B_MERAH, HIGH);
  delay(waktuMerah);

  // === Fase 2: Jalur B Hijau, Jalur A Merah ===
  matikanSemua();
  digitalWrite(B_HIJAU, HIGH);
  digitalWrite(A_MERAH, HIGH);
  delay(waktuHijau);

  // === Transisi Jalur B Kuning ===
  digitalWrite(B_HIJAU, LOW);
  digitalWrite(B_KUNING, HIGH);
  delay(waktuKuning);

  // === All-Red Sebentar ===
  matikanSemua();
  digitalWrite(A_MERAH, HIGH);
  digitalWrite(B_MERAH, HIGH);
  delay(waktuMerah);
}

// === Fungsi Matikan Semua Lampu ===
void matikanSemua() {
  digitalWrite(A_MERAH, LOW);
  digitalWrite(A_KUNING, LOW);
  digitalWrite(A_HIJAU, LOW);

  digitalWrite(B_MERAH, LOW);
  digitalWrite(B_KUNING, LOW);
  digitalWrite(B_HIJAU, LOW);
}
