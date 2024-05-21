//Title: Smart shelf
//Description: This ESP code will be used in a loadcell based project to track items on a shelf with many features,
//             including calculating the centre of gravity, last known location, restocking mode and single item addition & removal.
//Author: David Wood
//Created: 13/2/2024
//Updated: 20/05/2024


#include "HX711.h"                                  // Include HX711 library for load cell amplifiers
#include <WiFi.h>                                   // Include Wifi library to connect to a wifi network
#include <WebServer.h>                              // Include Webserver to publish HTML webpage

//Wifi webpage setup
const char* ssid = "Davidiphone";                   // Network name declaration
const char* password = "12345678";                  // Network password declaration
WebServer server(80);                               // Initalise webserver to port 80

//initalise item count
int totalitem1 = 0;                                 // Define total item count for item one
int totalitem2 = 0;                                 // Define total item count for item two
int totalitem3 = 0;                                 // Define total item count for item three
int totalUnknown = 0;                               // Define total item count for uknown items
int totalitems = 0;                                 // Define total item count for total items
int previousItemTotal = 0;                          // Define total item count for previous total
bool itemchange = false;                            // Define boolean statement for change in items


//Weight limits
float item1_low = 0;                                // Define minimum for item one                              
float item1_high = 0;                               // Define maximum for item one
float item2_low = 0;                                // Define minimum for item two
float item2_high = 0;                               // Define maximum for item two 
float item3_low = 0;                                // Define minimum for item three
float item3_high = 0;                               // Define maximum for item three
float Unknown_weight = 0;                           // Define Uknown weight 
float Unknown_low = 0;                              // Define minimum for uknown item
float Unknown_high = 0;                             // Define maximum for unkown item 

//initalise function pins
const int GPRed_pin = 26;                           // Analog pin GP11 RED Button 1
const int GPOrange_pin = 27;                        // Analog pin GP12 Orange Button 2
const int GPGreen_pin = 14;                         // Analog pin GP13 Green Button 3
const int GPWhite_pin = 12;                         // Analog pin GP14 White Restock switch

//LoadCell pins 
const int LOADCELL_SCK_PIN = 19;                    // Define SCK pin for all load cells White
const int LOADCELL_DOUT_PIN1 = 18;                  // DOUT pin of HX711-1 connected to GPIO 18 Blue
const int LOADCELL_DOUT_PIN2 = 5;                   // DOUT pin of HX711-2 connected to GPIO 5 Orange
const int LOADCELL_DOUT_PIN3 = 17;                  // DOUT pin of HX711-3 connected to GPIO 17 Green
const int LOADCELL_DOUT_PIN4 = 16;                  // DOUT pin of HX711-4 connected to GPIO 16 Grey
float calibration_factor1 = 395;                    // Calibration factor for the first load cell
float calibration_factor2 = 407.5;                  // Calibration factor for the second load cell
float calibration_factor3 = 398.5;                  // Calibration factor for the Third load cell
float calibration_factor4 = 375.5;                  // Calibration factor for the Fourth load cell
HX711 scale1;                                       // Set scale for loadcell 1
HX711 scale2;                                       // Set scale for loadcell 2
HX711 scale3;                                       // Set scale for loadcell 3
HX711 scale4;                                       // Set scale for loadcell 4
int baseWeight = 0;                                 // Define baseweight 1
int _baseWeight = 0;                                // Define baseweight 2
float currentWeight1 = 0.0;                         // Initalise current weight for cell 1
float currentWeight2 = 0.0;                         // Initalise current weight for cell 2
float currentWeight3 = 0.0;                         // Initalise current weight for cell 3 
float currentWeight4 = 0.0;                         // Initalise current weight for cell 4
float previousWeight1 = 0;                          // Initalise previous weight for cell 1
float previousWeight2 = 0;                          // Initalise previous weight for cell 2
float previousWeight3 = 0;                          // Initalise previous weight for cell 3
float previousWeight4 = 0;                          // Initalise previous weight for cell 4
float totalWeight = 0.0;                            // Define total weight
float newTotalWeight = 0.0;                         // Define new total weight
float _weightDifference = totalWeight - _baseWeight;                          // Calculate weight difference one

//intalise Centre gravity location
const int cell1_x = 210;                            // Set x point for loadcell 1
const int cell1_y = 97.5;                           // Set y point for loadcell 1
const int cell2_x = 210;                            // Set x point for loadcell 2
const int cell2_y = -97.5;                          // Set y point for loadcell 2
const int cell3_x = -210;                           // Set x point for loadcell 3
const int cell3_y = -97.5;                          // Set y point for loadcell 3
const int cell4_x = -210;                           // Set x point for loadcell 4
const int cell4_y = 97.5;                           // Set y point for loadcell 4
float Xavg, Yavg;                                   // Define X and Y average
float X_loc, Y_loc;                                 // Define X and Y location

void setup() {
  Serial.begin(115200);                             // Begin serial port at 115200 baud rate

  pinMode(GPRed_pin, INPUT_PULLUP);                  // Set GP13_pin as input
  pinMode(GPOrange_pin, INPUT_PULLUP);                  // Set GP12_pin as input
  pinMode(GPGreen_pin, INPUT_PULLUP);                  // Set GP14_pin as input
  pinMode(GPWhite_pin, INPUT_PULLUP);
  
  loadcell_setup(calibration_factor1, calibration_factor2, calibration_factor3, calibration_factor4);           // Call setup of loadcells include calibration factors
  itemCali(totalWeight);                            // Call item calibration include totalweight

   // Connect to Wi-Fi
  Serial.println("Connecting to WiFi...");          // Prompt serial port connecting to wifi (sampled)
  WiFi.begin(ssid, password);                       // Connect to wifi using set SSID and pasword
  while (WiFi.status() != WL_CONNECTED) {           // While the wifi isnt connected
    delay(1000);                                    // Delay for 1 second
    Serial.println("Connecting to WiFi...");        // Print connecting to wifi
  }
  Serial.println("Connected to WiFi");              // Print connected to wifi

  // Print ESP32's IP address
  Serial.print("IP address: ");                     // Print the Ip address
  Serial.println(WiFi.localIP());                   // Displat IP address from wifi library local IP
  // Start server
  server.on("/", HTTP_GET, [](){                    // Start server
    String htmlResponse = "<h1>Smart shelf status</h1>";            // Print title of smart shelf
      htmlResponse += "<h3><b>Live data</b></h3>";                  // Print Live data subtitle
      htmlResponse += "<p>Current weight: ";                        // Print paragraph Current weight:
      htmlResponse += totalWeight;                                  // Display total weight
      htmlResponse += " grams</p>";                                 // end paragraph with grams.
      htmlResponse += "<h3><b>Items</b></h3>";                      // Print items subtitle
      htmlResponse += "<p>Number of item1: ";                       // Print paragraph number of item one:
      htmlResponse += totalitem1;                                   // Display total of item one
      htmlResponse += " </p>";                                      // End paragraph
      htmlResponse += "<p>Number of item2: ";                       // Print paragraph number of item two:
      htmlResponse += totalitem2;                                   // Display total of item two
      htmlResponse += " </p>";                                      // End paragraph
      htmlResponse += "<p>Number of item3: ";                       // Print paragraph number of item three:
      htmlResponse += totalitem3;                                   // Display total of item three
      htmlResponse += " </p>";                                      // End paragraph
      htmlResponse += "<h3><b>Location of items</b></h3>";          // Print heading in bold location of the items:
      htmlResponse += "<p>Center of gravity: ";                     // Begin paragraph with center of gravity
      htmlResponse += Xavg;                                         // Display X average
      htmlResponse += ", ";                                         // Print a comma
      htmlResponse += Yavg;                                         // Display Y average
      htmlResponse += "</p>";                                       // End paragraph
      htmlResponse += "<p>New item location: ";                     // Begin paragraph with new item location:
      htmlResponse += X_loc;                                        // Display X location
      htmlResponse += ", ";                                         // Print a comma 
      htmlResponse += Y_loc;                                        // Display Y location
      htmlResponse += "</p>";                                       // End paragraph
      htmlResponse += "<meta http-equiv=\"refresh\" content=\"1\">";                    // Refresh user page every 1 seconds
    
    server.send(200, "text/html", htmlResponse);                    // Send HTML response
  });
  server.begin();                                                   // Begin server
  Serial.println("HTTP server started");                            // Print in serial HTTP server has started
}

void loop() {
  checkWeight();                                                    // Check for weight change
  delay(1000);                                                      // Delay for 1 second to wait and see if the weight stabilizes
  server.handleClient();                                            // Run server procedure

  if (digitalRead(GPWhite_pin) == LOW) {                                 // If GPIO 14 is pulled low then
    restockmode(newTotalWeight);                                          // Enter restocking mode
    Serial.println("Restock mode");
  }
}

void checkWeight() {
    currentWeight1 = scale1.get_units();                            // Get weight from load cell 1
    currentWeight2 = scale2.get_units();                            // Get weight from load cell 2
    currentWeight3 = scale3.get_units();                            // Get weight from load cell 3
    currentWeight4 = scale4.get_units();                            // Get weight from load cell 4
    totalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;              // Calculate total weight
    _weightDifference = totalWeight - _baseWeight;                  // Update weight difference

    if (abs(_weightDifference) >= 10) {                             // Check if the absolute difference is greater than or equal to 10
        Serial.println("Settling..");                               // Print settling
        delay(1000);                                                // Delay for 1 second
        currentWeight1 = scale1.get_units();                        // Get weight from load cell 1
        currentWeight2 = scale2.get_units();                        // Get weight from load cell 2
        currentWeight3 = scale3.get_units();                        // Get weight from load cell 3
        currentWeight4 = scale4.get_units();                        // Get weight from load cell 4
        newTotalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;        // Calculate total weight
        Serial.print("Settled weight(grams): ");                    // Print settled weight 
        Serial.println(newTotalWeight);                             // Display settled weight
        _baseWeight = newTotalWeight;                               // Update baseweight
        checkForItem(newTotalWeight);                               // Call Check for new item
        calculateCenterOfGravity(Xavg, Yavg);                       // Call centre of gravity calculation
        previousItemTotal = totalitems;                             // Set total items to previous item total
    }
}

void loadcell_setup(float calibration_factor1, float calibration_factor2, float calibration_factor3, float calibration_factor4) {
  // Setup for load cell 1
  scale1.begin(LOADCELL_DOUT_PIN1, LOADCELL_SCK_PIN);                     // Begin scale 1 with Dout and SCK as I/O 
  scale1.set_scale();                                                     // Call set scale within HX711 library
  scale1.tare();                                                          // Reset the scale to 0
  scale1.set_scale(calibration_factor1);                                  // Set scale to multiply by calibration factor

  // Setup for load cell 2
  scale2.begin(LOADCELL_DOUT_PIN2, LOADCELL_SCK_PIN);                     // Begin scale 2 with Dout and SCK as I/O
  scale2.set_scale();                                                     // Call set scale within HX711 library
  scale2.tare();                                                          // Reset the scale to 0
  scale2.set_scale(calibration_factor2);                                  // Set scale to multiply by calibration factor

  // Setup for load cell 3
  scale3.begin(LOADCELL_DOUT_PIN3, LOADCELL_SCK_PIN);                     // Begin scale 3 with Dout and SCK as I/O
  scale3.set_scale();                                                     // Call set scale within HX711 library
  scale3.tare();                                                          // Reset the scale to 0
  scale3.set_scale(calibration_factor3);                                  // Set scale to multiply by calibration factor

  // Setup for load cell 4
  scale4.begin(LOADCELL_DOUT_PIN4, LOADCELL_SCK_PIN);                     // Begin scale 4 with Dout and SCK as I/O
  scale4.set_scale();                                                     // Call set scale within HX711 library
  scale4.tare();                                                          // Reset the scale to 0
  scale4.set_scale(calibration_factor4);                                  // Set scale to multiply by calibration factor

  Serial.println("Loadcells have been reset");                            // Print that the loadcells have been reset to 0
}

void displayTotalItems() {   // Display Item totals
  Serial.print("Total item1: ");                                          // Print Total for item one
  Serial.println(totalitem1);                                             // Display total for item one
  Serial.print(" Total item2: ");                                         // Print Total for item two
  Serial.println(totalitem2);                                             // Display total for item two 
  Serial.print(" Total item3: ");                                         // Print Total for item three
  Serial.println(totalitem3);                                             // Display total for item three
}

void checkForItem(float currentWeight) {
  float weightDifference = newTotalWeight - baseWeight;                   // Calculate weight two 
  itemchange = false;                                                     // Set boolean to false 
  if (digitalRead(GPWhite_pin) == LOW) {                                 // If GPIO 14 is pulled low then
    restockmode(newTotalWeight);                                          // Enter restocking mode
    Serial.println("Restock mode");
  }
  else{                                                                   // Else then 
   singleItems(newTotalWeight);                                           // Enter single item mode
  }
}
