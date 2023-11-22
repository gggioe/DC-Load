#include <Wire.h>
#include <MCP342x.h>
#include "MCP_DAC.h"

MCP4821 DAC; //DAC init


uint8_t address = 0x6E;            //ADC init
MCP342x adc = MCP342x(address);

MCP342x::Config config(MCP342x::channel1, MCP342x::continuous,         //ADC config
		       MCP342x::resolution18, MCP342x::gain1);

MCP342x::Config status;



int main(){ 

  DAC.begin(PD0); //select pin (DAC)
  DAC.setGain(2); //gain (DAC)
  DAC.analogWrite(1024);  //write val to DAC

  Serial.begin(9600);
  Wire.begin();
  
  MCP342x::generalCallReset();    //Reset ADC
  delay(1);

 
  while(true){

    long value = 0;

    Serial.println("Convert");
    adc.convert(config);
    adc.read(value, status);

    
    Serial.print("Value: ");
    Serial.println(value);

  }//while end
}//main end





 

