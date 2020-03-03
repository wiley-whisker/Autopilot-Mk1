#include <SPI.h>

void setup() {
  Serial.begin(115200);
  // have to send on master in, *slave out*
  pinMode(SCK, INPUT);
  pinMode(MOSI, INPUT);
  pinMode(MISO, OUTPUT);

   // turn on SPI in slave mode
 SPCR |= _BV(SPE);
 
 // turn on interrupts
 SPCR |= _BV(SPIE);
}

// SPI interrupt routine
ISR (SPI_STC_vect)
{
  byte c = SPDR;
  byte t = c + 10;

  SPDR = t;
}  // end of interrupt service routine (ISR) for SPI

void loop () { }
