# Microdebugs_hackelite2.0
Glance X the smart glass
### Hardware Setup

1. **Connect the OLED Display**  
   - **Arduino (Uno/Nano/Pro Mini):**  
     - SDA → **A4**  
     - SCL → **A5**  
   - **ESP32:**  
     - SDA → **GPIO 21**  
     - SCL → **GPIO 22**  

2. **Connect the Push Buttons**  
   - Button 1 → **GPIO 2** → GND  
   - Button 2 → **GPIO 3** → GND  
   - Button 3 → **GPIO 4** → GND  

3. **Upload the Code**  
   - Open the provided sketch in the Arduino IDE.  
   - Select the correct board (Arduino or ESP32).  
   - Compile and upload the code.
