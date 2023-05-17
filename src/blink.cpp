#include "blink.h"

blink::blink(int pin)
{
	this->pin=pin;
	init();
}

void blink::init()
{
	pinMode(pin,OUTPUT);
}


void blink::update(unsigned long interval, bool calibrating)
{
  static int cuentaParpadeo = 0;
  static unsigned long previousMillis = 0;        // will store last time LED was updated
	//const long interval = 1000;           // interval at which to blink (milliseconds)
	unsigned long currentMillis = millis();
	static bool estadoPin=false;
	
    if(currentMillis - previousMillis > interval)  
	  {
      previousMillis = currentMillis;
      // Rutina para Calibración:
      if(calibrating)
      {
        estadoPin==false? estadoPin=true : estadoPin=false;
		    digitalWrite(pin, estadoPin);

      }
      else
      {
        if(cuentaParpadeo < 2)
        {
          estadoPin==false? estadoPin=true : estadoPin=false;
		      digitalWrite(pin, estadoPin);
        }
        else
        {
          digitalWrite(pin,LOW);
        }
        cuentaParpadeo == 8? cuentaParpadeo = 0: cuentaParpadeo ++;
      }
      
    }
    
}

void blink::on(){
  digitalWrite(pin, HIGH);
}

void blink::off(){
  digitalWrite(pin, LOW);
}