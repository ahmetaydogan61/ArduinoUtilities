#define ANODE // Comment this out, if your display is Common Cathode

//Define pins of the display
#define A 7
#define B 6
#define C 4
#define D 2
#define E 1
#define F 9
#define G 10
byte ssdPins[7];

//In anode the signal must be low, so we set the true state to low, in cathode it is the reverse way.
#ifdef ANODE
#define SSD_FALSE HIGH
#define SSD_TRUE LOW
#else
#define SSD_FALSE LOW
#define SSD_TRUE HIGH
#endif

namespace SSD
{
  void Init() //initialize the pins
  {
    pinMode(A, OUTPUT);
    digitalWrite(A, SSD_FALSE);
    ssdPins[6] = A;

    pinMode(B, OUTPUT);
    digitalWrite(B, SSD_FALSE);
    ssdPins[5] = B;

    pinMode(C, OUTPUT);
    digitalWrite(C, SSD_FALSE);
    ssdPins[4] = C;

    pinMode(D, OUTPUT);
    digitalWrite(D, SSD_FALSE);
    ssdPins[3] = D;

    pinMode(E, OUTPUT);
    digitalWrite(E, SSD_FALSE);
    ssdPins[2] = E;

    pinMode(F, OUTPUT);
    digitalWrite(F, SSD_FALSE);
    ssdPins[1] = F;

    pinMode(G, OUTPUT);
    digitalWrite(G, SSD_FALSE);
    ssdPins[0] = G;
  }

  void Sevensegment(const char* data)
  {
    for (int i = 0; i < 7; i++)
    {
      if (data[i] == '1')
        digitalWrite(ssdPins[i], SSD_TRUE);
      else
        digitalWrite(ssdPins[i], SSD_FALSE);
    }
  }

  void Clear()
  {
    Sevensegment("0000000");
  }
 
  void Write(const char data)
  {
    switch(data)
    {
      //Numeric
      case '0': Sevensegment("0111111"); break;
      case '1': Sevensegment("0000110"); break;
      case '2': Sevensegment("1011011"); break;
      case '3': Sevensegment("1001111"); break;
      case '4': Sevensegment("1100110"); break;
      case '5': Sevensegment("1101101"); break;
      case '6': Sevensegment("1111101"); break;
      case '7': Sevensegment("0000111"); break;
      case '8': Sevensegment("1111111"); break;
      case '9': Sevensegment("1101111"); break;
      //Upper Case
      case 'A': Sevensegment("1110111"); break;
      case 'C': Sevensegment("0111001"); break;
      case 'E': Sevensegment("1111001"); break;
      case 'F': Sevensegment("1110001"); break;
      case 'G': Sevensegment("1111101"); break;
      case 'H': Sevensegment("1110110"); break;
      case 'I': Sevensegment("0000110"); break;
      case 'J': Sevensegment("0001110"); break;
      case 'L': Sevensegment("0111000"); break;
      case 'O': Sevensegment("0111111"); break;
      case 'P': Sevensegment("1110011"); break;
      case 'S': Sevensegment("1101101"); break;
      case 'U': Sevensegment("0111110"); break;
      case 'Y': Sevensegment("1101110"); break;
      //Lower Case
      case 'b': Sevensegment("1111100"); break; 
      case 'c': Sevensegment("1011000"); break;
      case 'd': Sevensegment("1011110"); break;
      case 'n': Sevensegment("1010100"); break;
      case 'o': Sevensegment("1011100"); break;
      case 'r': Sevensegment("1010000"); break;
      case 't': Sevensegment("1111000"); break;
      case 'u': Sevensegment("0011100"); break;
    }
  }
  
  void Write(int data)
  {
    switch(data)
    {
      case 0: Sevensegment("0111111"); break;
      case 1: Sevensegment("0000110"); break;
      case 2: Sevensegment("1011011"); break;
      case 3: Sevensegment("1001111"); break;
      case 4: Sevensegment("1100110"); break;
      case 5: Sevensegment("1101101"); break;
      case 6: Sevensegment("1111101"); break;
      case 7: Sevensegment("0000111"); break;
      case 8: Sevensegment("1111111"); break;
      case 9: Sevensegment("1101111"); break;
    }
  }
}
