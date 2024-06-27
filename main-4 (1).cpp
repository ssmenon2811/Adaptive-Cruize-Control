/*==============================================================================
                         ROBOTIC ARM


==============================================================================*/
#include "mbed.h"
#include "HCSR04.h" 


Serial pc(USBTX,USBRX);
Serial device(PTC17,NC);     
Serial UART(USBTX,USBRX);



int main()
{ 
    pc.baud(115200);// assigning the baud values for the setup.
    device.baud(115200);
    HCSR04 sensor(D8,D9);
     wait_ms(500);
       
    int objectDetectionRange =40; 

    
    
    while(1) 
    {      
 
                long a = sensor.distance(CM); // function call for calculating the  distance between the HCSR04 sensor and the near by object.
               
                    if(sensor.distance(CM)<=objectDetectionRange) // check if the blindstick is within the safe distance.
                    {  
                     
                    device.printf("1");  
                    pc.printf("Object range\r\n"); 
                    pc.printf("\n\r %ld",a );  
                    int val=1;
                    wait_ms(500);
                    UART.putc(val);

                    }
                    else
                    {
                    device.printf("0");
                    pc.printf("Not within the object range\r\n");
                    int val0=0;
                    wait_ms(500);
                    UART.putc(val0);
                    }
         
    }
    
        
    
} 

