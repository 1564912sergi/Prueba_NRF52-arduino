#include <Arduino.h>
// Import libraries (BLEPeripheral depends on SPI)
#include <SPI.h>
#include <BLEPeripheral.h>


//definition of the BLEPeripheral Object
BLEPeripheral blePeripheral = BLEPeripheral();

// create service with a random generated UUID
BLEService Service = BLEService("2959a35e-cfb5-4f52-a028-531856a2547d");

// create switch characteristic with the Notify characteristic
BLEIntCharacteristic bleCharacteristic = BLEIntCharacteristic("c1534b39-34b4-4bcd-99d8-b3e2a9b34902", BLERead | BLEWrite | BLENotify);

BLEDescriptor bleDescriptor = BLEDescriptor("8ee70684-3017-4f4f-aa42-3ad0370c816f", "652223");

//send data medicines
void dataSender(int codebar_medicine){
  //update value sent to central
  bleCharacteristic.setValue(codebar_medicine);

  Serial.print(F("Medicine "));
  Serial.println(codebar_medicine);
  //send information every 3 seconds
  delay(3000);
}


//setup the bluetooth service
void setup() {
  Serial.begin(9600);
#if defined (__AVR_ATmega32U4__)
  delay(5000);  //5 seconds delay for enabling to see the start up comments on the serial board
#endif


  // set service UUID
  blePeripheral.setAdvertisedServiceUuid(Service.uuid());
  
  // add service, characteristic and descriptor
  blePeripheral.addAttribute(Service);
  blePeripheral.addAttribute(bleCharacteristic);
  blePeripheral.addAttribute(bleDescriptor);
  
  //set name to the device
  blePeripheral.setLocalName("CodeBar Reader");

  dataSender(727085); //send the code 727085 to the edge

  blePeripheral.begin();
}


void loop() {
  BLECentral central = blePeripheral.central();

  if (central) {
    
    Serial.print(F("Connected to central: "));
    Serial.println(central.address());

    while (central.connected()) {
      //generate random codebars to send to the central
      Serial.print("Running...");
      //dataSender(rand() % 10000 + 10000);
      
    }
    Serial.print(F("Disconnect from central: "));
    Serial.println(central.address());
  }
}
