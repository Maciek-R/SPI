//komunikacja SPI - urzadzenie master
#include <avr/io.h>
#include <util/delay.h>

void spi_master_init()
{
	DDRB |= (1 << PB5) | (1 << PB7) | (1 << PB4);	//wyjscia MOSI, SCK, SS
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0);	//wlaczenie SPI, uklad master, minimalna czestotliwosc sck fosc/128
}

void wyslij_spi(char bajt)
{
	SPDR = bajt;	//wysylanie danych
	while(!(SPSR & (1 << SPIF)));	//oczekujemy na zakonczenie transmisji
}

int main()
{
	char bajt = 0;
	spi_master_init();

	while(1)
	{
		wyslij_spi(bajt);
		_delay_ms(1000);
		bajt++;
	}

	return 0;
}
