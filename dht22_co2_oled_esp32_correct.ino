#include <SoftwareSerial.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHT_PIN 4       // Pin where the DHT22 is connected
#define DHT_TYPE DHT22
#define pwmPin 14
SoftwareSerial mySerial(5, 18); // RX, TX pins for SoftwareSerial

DHT dht(DHT_PIN, DHT_TYPE);

#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels

// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  dht.begin();
  mySerial.begin(9600);
  pinMode(pwmPin, INPUT);

  // initialize OLED display with I2C address 0x3C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }

  delay(2000);         // wait two seconds for initializing
  oled.clearDisplay(); // clear display

}

void loop() {
  //delay(5000);
  // Read CO2 concentration via SoftwareSerial
  byte cmd[9] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
  unsigned char response[9];
  mySerial.write(cmd, 9);
  mySerial.readBytes(response, 9);
  unsigned int responseHigh = (unsigned int)response[2];
  unsigned int responseLow = (unsigned int)response[3];
  unsigned int ppm = (256 * responseHigh) + responseLow;
  //Serial.print("CO2 Concentration via SoftwareSerial: ");
  //Serial.println(ppm);

  // Read CO2 concentration via PWM
  unsigned long th, tl, ppm2, ppm3 = 0;
  do {
    th = pulseIn(pwmPin, HIGH, 1004000) / 1000;
    tl = 1004 - th;
    ppm2 = 2000 * (th - 2) / (th + tl - 4);
    ppm3 = 5000 * (th - 2) / (th + tl - 4);
  } while (th == 0);

  Serial.print("CO2 Concentration via PWM: ");
  Serial.println(ppm2);

  //Serial.print("CO2 Concentration via PWM (Alternate calculation): ");
  //Serial.println(ppm3);
  //delay(2000);
  //Serial.println("-----------");
  //delay(1500);
  delay(200);

  delay(2000);  // Delay for 2 seconds

  float temperature = dht.readTemperature();    // Read temperature in Celsius
  float humidity = dht.readHumidity();          // Read humidity in percentage

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read data from DHT sensor");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  oled.setTextSize(1);         // set text size
  oled.setTextColor(WHITE);    // set text color
  oled.setCursor(0, 0);       // set position to display (x,y)
  oled.print("Tempe: ");
  oled.print(temperature); // set text
  oled.println(" °C ");
  oled.display(); 

  oled.setCursor(0, 16); 
  oled.print("Humidity: ");
  oled.print(humidity); // set text
  oled.println(" % ");
  oled.display(); 

  oled.setCursor(0, 32); 
  oled.print("CO2: ");
  oled.print(ppm2); // set text
  oled.println(" ppm"); // set text

  oled.display(); 
  delay(1000);
  /*display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" °C");

  display.setCursor(0, 16);
  display.print("Humidity: ");
  display.print(humidity);
  display.println(" %");

  display.display();*/
  oled.clearDisplay(); // clear display

}
