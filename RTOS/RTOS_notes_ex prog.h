/* RTOS notes
we use Object oriented approach to create a blinky LED. The LED is connected to portb 
and 5th pin of the microcontroller. Hence an object is created for it and that is used 
to control the LED. 


*/

#include <cstdint>
#include ""

class led{
	const pot_type port;						//default private members of class LED
	const bval_type bval;
	
	typedef std::uint8_t port_type;
	typedef std::uint8_t bval_type;
	
	led(const port_type p, const bval_type b): port(p), bval(b)
	{
		
	}
};