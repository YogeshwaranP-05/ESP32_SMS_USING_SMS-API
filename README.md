### **📱 Sending SMS with ESP32 Using SMS API** 

---

### **🌡️ Project Overview**

This project demonstrates how to **send SMS alerts** using an **ESP32** and the **Circuit Digest Cloud SMS API** when the temperature, measured by a **DHT11 sensor**, exceeds a predefined threshold.

✅ **Key Features:**

* **Temperature Monitoring:** The ESP32 continuously reads temperature data from the **DHT11** sensor.

* **Threshold Alert:** When the temperature crosses the threshold, the ESP32 triggers an SMS alert.

* **SMS Delivery:** The ESP32 sends an **HTTP request** to the **Circuit Digest Cloud SMS API**.

* **Real-time Alerts:** Notify users instantly about temperature anomalies via SMS Alert.

---

### **🛠️ Components Required**

* ✅ **ESP32 Development Board** → Microcontroller for sensor data processing and SMS sending

* ✅ **DHT11 Sensor** → To measure temperature

* ✅ **Jumper Wires** → For electrical connections

* ✅ **Breadboard** → For prototyping

* ✅ **Power Supply (5V)** → To power the ESP32

---

### **🗂️ Project Structure**

**`/ESP32-SMS-Temperature-Alert`**    
**`├── /Code                  # ESP32 sketch (.ino)`**    
**`├── /Circuit-Diagram       # Circuit diagram and wiring illustrations`**    
**`├── /README.md              # Project documentation`**  

---

### **⚙️ Installation and Setup**

#### **1\. Clone the Repository**

**`git clone https://github.com/YogeshwaranP-05/ESP32_SMS_USING_SMS-API.git`**   
**`cd ESP32_SMS_USING_API`**

#### **2\. Connect the Components**

* **DHT11 Sensor:**

  * VCC → 5V (ESP32)

  * GND → GND (ESP32)

  * DATA → GPIO 23 (ESP32)

* **Power the System:**

  * Connect the ESP32 to a 5V power source or via USB.

#### **3\. API Configuration**

* Obtain the **Circuit Digest Cloud SMS API** link.

* Replace the placeholder in the code with your **API key** and **endpoint**.

* **Example API format:**

 **`https://www.circuitdigest.cloud/send_sms?api_key=YOUR_API_KEY&number=PHONE_NUMBER&message=YOUR_MESSAGE`**

#### **4\. Upload the Code**

* Open the **`.ino`** file in the **Arduino IDE**.

* Install the required **DHT sensor** and **WiFi** libraries.

* Select **ESP32 Dev Module** as the board.

* Choose the correct COM port.

* Upload the code to your ESP32.

#### **5\. Run the System**

* The ESP32 connects to the Wi-Fi network.

* It continuously reads temperature values from the **DHT11 sensor**.

* When the temperature exceeds the threshold, the ESP32 sends an SMS alert.

---

### **📝 Code Explanation**

✅ **Wi-Fi Connection:**

* The ESP32 connects to the local Wi-Fi network using the **SSID** and **password**.

✅ **Temperature Monitoring:**

* The **DHT11** sensor reads the temperature at regular intervals.

* The temperature is displayed on the **Serial Monitor**.

✅ **Threshold Detection and SMS Alert:**

* If the temperature exceeds the threshold, the ESP32:

  * Constructs the **API URL** with the temperature data.

  * Sends an **HTTP request** to the **Circuit Digest Cloud SMS API**.

  * Displays a confirmation message on the **Serial Monitor**.

---

### **🌐 API Usage Example**

**`String apiKey = "YOUR_API_KEY";`**  
**`String phoneNumber = "XXXXXXXXXX";`**  
**`String message = "Temperature Alert: " + String(temperature) + "°C";`**  
**`String apiUrl = "https://api.circuitdigest.com/sms?api_key=" + apiKey + "&number=" + phoneNumber + "&message=" + message;`**

---

### **🌐 Serial Monitor Output**

**`Connecting to Wi-Fi...`**  
**`Connected to Wi-Fi`**    
**`Temperature: 28.5°C`**    
**`Temperature: 30.2°C`**    
**`Threshold reached! Sending SMS...`**    
**`SMS Sent Successfully!`**  

---

### **🚀 Future Enhancements**

* ✅ Add **humidity monitoring** and trigger alerts for both temperature and humidity thresholds.

* ✅ Implement **email alerts** along with SMS notifications.

* ✅ Store historical data on a **cloud server**.

---

### **🤝 Contributing**

We welcome contributions\! 🎯  
 If you have ideas for improvement or want to add new features:

1. Fork the repository.

2. Make your changes.

3. Submit a pull request.

---

### **🛡️ License**

This project is licensed under the **GPL-V3 License**.  
 Refer to the **`LICENSE`** file for details.

---

### **📧 Contact**

For any queries or suggestions, reach out via:

 🌐 **Official Website:** [Circuit Digest](https://circuitdigest.com)

🚀 **Happy coding and SMS sending\!** 🌡️📱

