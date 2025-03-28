#include <WiFi.h>
#include <DHT.h>
#include <DHT_U.h>

#define Temp_SensorPin 23

DHT_Unified dht(Temp_SensorPin, DHT11);


// WiFi credentials
const char *ssid = "Semicon Media";   // Your network SSID (from arduino_secrets.h)
const char *password = "XXXXXXXXXXX";   // Your network password (from arduino_secrets.h)

// API credentials and SMS details
const char* apiKey = "xxxxxxxxxxxx";       // Replace with your generated API key from Circuit Digest Cloud Website  
const char* templateID = "102";           // Replace with your template ID
const char* mobileNumber = "91XXXXXXXXXXX"; // Replace with the recipient's mobile number with country code (eg : 91XXXXXXXXXX)
const char* var1 = "WAREHOUSE";         // Replace with your custom variable
const char* var2 = "30";                  // Replace with your custom variable


//used for storing the temperature data
float temperature = 0.0;


//Functiom to read the temperature data from the DHT11 sensor
void read_temperature(){
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    temperature = event.temperature;
    Serial.println(temperature);
}


void sendSMS() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client; // Initialize WiFi client
    
    String apiUrl = "/send_sms?ID=" + String(templateID);

    Serial.print("Connecting to server...");
    if (client.connect("www.circuitdigest.cloud", 80)) { // Connect to the server
      Serial.println("connected!");

      // Create the HTTP POST request
      String payload = "{\"mobiles\":\"" + String(mobileNumber) + 
                       "\",\"var1\":\"" + String(var1) + 
                       "\",\"var2\":\"" + String(var2) + "\"}";

      // Send HTTP request headers
      client.println("POST " + apiUrl + " HTTP/1.1");
      client.println("Host: www.circuitdigest.cloud");
      client.println("Authorization: " + String(apiKey));
      client.println("Content-Type: application/json");
      client.println("Content-Length: " + String(payload.length()));
      client.println(); // End of headers
      client.println(payload); // Send the JSON payload

      // Wait for the response
      int responseCode = -1; // Variable to store HTTP response code
      while (client.connected() || client.available()) {
        if (client.available()) {
          String line = client.readStringUntil('\n'); // Read a line from the response
          Serial.println(line); // Print the response line (for debugging)

          // Check for the HTTP response code
          if (line.startsWith("HTTP/")) {
            responseCode = line.substring(9, 12).toInt(); // Extract response code (e.g., 200, 404)
            Serial.print("HTTP Response Code: ");
            Serial.println(responseCode);
          }

          // Stop reading headers once we reach an empty line
          if (line == "\r") {
            break;
          }
        }
      }
      

      // Check response
      if (responseCode == 200) {
        Serial.println("SMS sent successfully!");
      } else {
        Serial.print("Failed to send SMS. Error code: ");
        Serial.println(responseCode);
      }
      
      
      client.stop(); // Disconnect from the server
    } else {
      Serial.println("Connection to server failed!");
    }
  } else {
    Serial.println("WiFi not connected!");
  }
}




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   // We start by connecting to a WiFi network

  Serial.println();
  Serial.println("******************************************************");
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  dht.begin();
}

void loop() {
  read_temperature();
  if(temperature >= 30.00){
    sendSMS();

    //Make it to stop sending further SMS alert until temperature get back to 28
    while(temperature > 28){
      read_temperature();
    }
  }
}
