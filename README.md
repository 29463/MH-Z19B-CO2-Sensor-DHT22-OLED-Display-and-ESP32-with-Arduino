# MH-Z19B-CO2-Sensor-DHT22-OLED-Display-and-ESP32-with-ESP32



Using MH-Z19B CO2 Sensor, DHT22, OLED Display, and ESP32 with Arduino
This project combines the MH-Z19B CO2 sensor, DHT22 temperature and humidity sensor, and an OLED display with the ESP32 to measure CO2 concentration, temperature, and humidity and display the data in real time.
________________________________________
Features of the Components
MH-Z19B CO2 Sensor
1.	Key Features:
o	Measures CO2 concentration in the air.
o	Uses non-dispersive infrared (NDIR) technology for accuracy.
o	Provides UART and PWM interfaces for communication.
2.	Specifications:
o	CO2 Measurement Range: 0–5000 ppm.
o	Accuracy: ±50 ppm + 3%.
o	Operating Voltage: 4.5V–5.5V.
o	Power Consumption: <150 mA.
o	Warm-Up Time: <3 minutes.
DHT22 Sensor
1.	Key Features:
o	Measures temperature and humidity with higher accuracy compared to DHT11.
o	Outputs a calibrated digital signal.
o	Suitable for precise environmental monitoring.
2.	Specifications:
o	Temperature Range: -40°C to 80°C (±0.5°C accuracy).
o	Humidity Range: 0%–100% RH (±2% accuracy).
o	Operating Voltage: 3.3V–6V.
o	Sampling Rate: 0.5 Hz.
OLED Display
1.	Key Features:
o	Compact screen for visual output.
o	Low power consumption.
o	Supports I2C or SPI communication.
2.	Specifications:
o	Resolution: 128x64 pixels.
o	Operating Voltage: 3.3V–5V.
o	Interface: I2C (SDA and SCL pins).
________________________________________
Applications
1.	Indoor Air Quality Monitoring:
o	Track CO2 levels and environmental conditions in homes and offices.
2.	Greenhouses:
o	Ensure optimal CO2 levels and temperature for plant growth.
3.	Educational Projects:
o	Demonstrate sensor integration and IoT concepts.
4.	Industrial Monitoring:
o	Monitor environmental conditions in sensitive areas.
________________________________________
How the System Works
1.	The MH-Z19B sensor measures CO2 concentration.
2.	The DHT22 sensor measures temperature and humidity.
3.	The ESP32 reads the sensor data and displays it on the OLED screen.
4.	Optionally, data can be sent to a cloud platform like ThingSpeak or Firebase.
________________________________________
Components Required
1.	ESP32 development board.
2.	MH-Z19B CO2 sensor.
3.	DHT22 temperature and humidity sensor.
4.	OLED display (128x64).
5.	Resistors and jumper wires.
6.	Breadboard.
________________________________________
Pin Description and Connections
MH-Z19B CO2 Sensor
MH-Z19B Pin	Description	ESP32 Pin
VCC	Power (4.5V–5.5V).	VIN
GND	Ground.	GND
TXD	Data output (UART).	GPIO16
RXD	Data input (UART).	GPIO17
DHT22 Sensor
DHT22 Pin	Description	ESP32 Pin
VCC	Power supply (3.3V/5V).	3.3V
GND	Ground.	GND
OUT	Data signal.	GPIO4
OLED Display
OLED Pin	Description	ESP32 Pin
VCC	Power (3.3V/5V).	3.3V
GND	Ground.	GND
SCL	Clock signal (I2C).	GPIO22
SDA	Data signal (I2C).	GPIO21
________________________________________
Circuit Diagram
1.	Connect the MH-Z19B VCC to VIN and GND to GND.
2.	Connect the TXD and RXD pins of the MH-Z19B to GPIO16 and GPIO17 respectively.
3.	Connect the DHT22 VCC to 3.3V, GND to GND, and OUT to GPIO4.
4.	Connect the OLED VCC to 3.3V, GND to GND, SCL to GPIO22, and SDA to GPIO21.
How the Code Works
1.	DHT22 Readings:
o	The ESP32 retrieves temperature and humidity readings using the DHT library.
2.	MH-Z19B CO2 Data:
o	The ESP32 sends a command to the MH-Z19B via UART and processes the response to calculate CO2 concentration.
3.	OLED Display:
o	Sensor readings are displayed on the OLED using the Adafruit_SSD1306 library.
________________________________________

Testing and Troubleshooting
1.	Sensor Calibration:
o	Allow the MH-Z19B sensor a warm-up time of 3 minutes for accurate readings.
2.	No Data on OLED:
o	Check the I2C connections and address (default: 0x3C).
3.	Incorrect Sensor Readings:
o	Verify wiring and ensure the sensors are within their operational ranges.
________________________________________
This detailed guide integrates multiple sensors and an OLED display with the ESP32, enabling a robust environmental monitoring system.


