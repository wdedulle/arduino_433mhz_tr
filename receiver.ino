#include <VirtualWire.h>
  
char StringReceived[22]; 
  
void setup() {
    // VirtualWire 
    // Initialise the IO and ISR
    // Required for DR3100
  
    Serial.begin(9600);
    // Bits per sec
    vw_setup(2000);
    vw_set_rx_pin(11);  
    Serial.println("setup");  
    // Start the receiver PLL running
    vw_rx_start();       
  
} // END void setup
  
void loop(){
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    //Taking the data from the control base
    if (vw_get_message(buf, &buflen)) 
    {
      int i;
        // Message with a good checksum received, dump it. 
      for (i = 0; i < buflen; i++)
      {            
          // Fill Sensor1CharMsg Char array with corresponding 
          // chars from buffer.   
          StringReceived[i] = char(buf[i]);
      }
  
       Serial.println(StringReceived);
  }
  
  memset( StringReceived, 0, sizeof( StringReceived));// This line is for reset the StringReceived
}

