//Function Definitions
// '*' is the port you choose, for example C for port PORTC, DDRD is TRISD.

//TRIS*(x, y) Set the pin mode to output or input for a specific pin.
//x: the number of the port. For example if you want to output the PC1 pin -> TRISC(1, 0) or TRISC(PC1, 0).
//y: 0 for input, 1 for output
#define TRISB(x, y) y ? DDRB |= 1 << (x) : DDRB &= ~(1 << (x))
#define TRISC(x, y) y ? DDRC |= 1 << (x) : DDRC &= ~(1 << (x))
#define TRISD(x, y) y ? DDRD |= 1 << (x) : DDRD &= ~(1 << (x))

//P*(x, y) Write signal to a specific pin.
//x: the number of the port (for example if you want to use the PD3 and set the value to high -> PORTD(3, 1) or PORTD(PD3, 1).
//y: the value of the signal, 1 for high, 0 for low
#define PB(x, y)  y ? PORTB |= 1 << (x) : PORTB &= ~(1 << (x))
#define PC(x, y)  y ? PORTC |= 1 << (x) : PORTC &= ~(1 << (x))
#define PD(x, y)  y ? PORTD |= 1 << (x) : PORTD &= ~(1 << (x))

//input_*(x) Read digital signal from a specific pin.
//In a if statement, if the pin is high, it returns 1.
//x: the pin of the port you want to read. (for example for reading the value of PB2 -> input_b(2) or input_b(PB2).
#define input_b(x) ((PINB & 1 << (x)) == 1 << (x))
#define input_c(x) ((PINC & 1 << (x)) == 1 << (x))
#define input_d(x) ((PIND & 1 << (x)) == 1 << (x))

//PIN definitions
#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5

#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7

#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6

/*Example Code
int main()
{
  TRISC(0, 0); //Makes the PD2 pin 'Input';
  TRISD(3, 1); //Makes the PD3 pin 'Output';
  while(true)
  {
    if(input_c(0)) //Check if there is a input signal in PC0
      PD(3, 1); //Writes high to the PD3 pin
    else
      PD(3, 0); //Writes low to the PD3 pin
  }
}
*/