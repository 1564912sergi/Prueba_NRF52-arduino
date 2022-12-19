# Prueba_NRF52-arduino
In this repository we find the code that we have installed on the NRF52-DK motherboard.

All the code we have done is found in the main.cpp file, which we find in the src folder.

In this code we create a service, a characteristic and a descriptor to which we assign a UUID code to identify them.

We find a function called setup() in which we initialize the motherboard with the service, feature and descriptor. We also add an identifying name.
In this function we also call a function called sendData(). We have created this function to send the barcode to the Edge.

In the loop() function we do not perform any functionality.
