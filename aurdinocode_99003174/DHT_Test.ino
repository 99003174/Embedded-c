#include<SPI.h>
volatile boolean recvd;
volatile uint16_t  slaverec1, slaverec2;

void setup()
{
  Serial.begin(9600);
  pinMode(MISO,OUTPUT);                   
  pinMode(10,INPUT);
  digitalWrite(10,LOW);
  SPCR |= _BV(SPE);                       
  recvd = false;
  SPI.attachInterrupt(); 
  Serial.print("SYSTEM BOOTING>...........\n");
  delay(2000);
  Serial.print("SYSTEM READY\n");                 
}


ISR (SPI_STC_vect)                        
{
    slaverec1 = SPDR;            
    recvd = true;
}

 

void loop()
{
  if(recvd)                           
  {  
      if(slaverec1 != 0)
      {
        recvd = false;    
        Serial.print("Temperature is  ");
        float c= slaverec1;
        float d= c/10;
        Serial.println(d);
      
        delay(100);
      }
      
  
  
  }
 
}
