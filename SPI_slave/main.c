//komunikacja SPI - urzadzenie slave
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void spi_slave_init()
{
	DDRB |= (1 << PB6);	//wyjscia MISO
	SPCR |= (1 << SPE);	//wlaczenie SPI
}

ISP (SPI_STC_vect)
{
	char bajt = SPDR;
	PORTD = bajt;
}

int main()
{
	
	DDRD = 0xFF;	//wszystkie piny PORTD jako wyjscia
	spi_slave_init();	//inicjacja SPI jako slave
	sei();
	//char bajt=0;	

	for(;;)

	return 0;
}
