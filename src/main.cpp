#include <main.h>
#define uS_TO_S_FACTOR 1000000ULL /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  30          /* Time ESP32 will go to sleep (in seconds) */

RTC_DATA_ATTR int bootCount = 0;

void print_wakeup_reason() {
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch (wakeup_reason) {
    case ESP_SLEEP_WAKEUP_EXT0:     Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case ESP_SLEEP_WAKEUP_EXT1:     Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case ESP_SLEEP_WAKEUP_TIMER:    Serial.println("Wakeup caused by timer"); break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD: Serial.println("Wakeup caused by touchpad"); break;
    case ESP_SLEEP_WAKEUP_ULP:      Serial.println("Wakeup caused by ULP program"); break;
    default:                        Serial.printf("Wakeup was not caused by deep sleep: %d\n", wakeup_reason); break;
  }
}

simcom sim(&SerialGSM, GSMPWR_PIN);
uint32_t last_time = 0;

void setup() {
  esp_sleep_disable_wakeup_source(ESP_SLEEP_WAKEUP_ALL);
  Serial.begin(115200);
  SerialRSX.begin(9600);
  sim.begin();
  sensor.begin();
  sensor.setResolution(10);
  print_wakeup_reason();
  pinMode(GSMPWR_PIN, OUTPUT);
  pinMode(USXEN_PIN, OUTPUT);
  digitalWrite(GSMPWR_PIN, 1);
  delay(10000);
  digitalWrite(GSMPWR_PIN, 0);
  pinMode(USXRX_PIN, OUTPUT);
  pinMode(USXTX_PIN, OUTPUT);
  digitalWrite(USXEN_PIN, 0);
  delay(10000);
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) + " Seconds");
  Serial.println("Going to sleep now");
  Serial.flush();
  esp_deep_sleep_start();
  Serial.println("This will never be printed");
}


void loop() {
  if (millis() - last_time > 1000) 
  {
    last_time = millis();
    sensor.requestTemperatures();
    while (!sensor.isConversionComplete()) {
      delay(10);
    }
    Serial.printf("Temperature: %.2f\n", sensor.getTempC());
  }
}