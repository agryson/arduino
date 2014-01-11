//Code from http://www.fiz-ix.com/2012/01/how-to-configure-arduino-timer-2-registers-to-drive-an-ultrasonic-transducer-with-a-square-wave/

void startTransducer()
{
  TCCR2A = _BV(COM2A0) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(WGM22) | _BV(CS20);
  OCR2A = B11000111; 
  	// 199, so timer2 counts from 0 to 199 (200 cycles at 16 MHz)
}

void stopTransducer()
{
TCCR2A = 0;
TCCR2B = 0; 
	// I think this is all that is needed since setting the CS bits to zero stops the timer.
}

void setup()
{
	pinMode(11, OUTPUT);
	pinMode(13, OUTPUT);
}

void loop()
{
	//digitalWrite(13, HIGH);
	startTransducer();
	//delay(500);
	//digitalWrite(13, LOW);
	//stopTransducer();
	//delay(500);
}