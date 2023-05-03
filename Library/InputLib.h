// Call Update() before Events() in the main loop
namespace Input
{
	//Key definitions
	char key_event = 0;
	#define KEY_1 input_c(0) //Can be definened as -> digitalRead(PIN) == HIGH.
	#define KEY_2 input_c(1) //So this can be defined as -> digitalRead(A1) == HIGH
	#define KEY_3 input_c(2)
	const int keyCount = 3;  //Number of keys 

	//For update and events
	char keys[keyCount];
	char lastKeys[keyCount];

	void Init()
	{
		TRISC(0, 0);
		TRISC(1, 0);
		TRISC(2, 0);
	}

	void Update()
	{
		for (int i = 0; i < keyCount; i++)
			lastKeys[i] = keys[i];
	}

	void Events()
	{
		if (KEY_1)
		{
			keys[0] = 1;
			key_event = 1;
		}
		else
			keys[0] = 0;

		if (KEY_2)
		{
			keys[1] = 1;
			key_event = 1;
		}
		else
			keys[1] = 0;

		if (KEY_3)
		{
			keys[2] = 1;
			key_event = 1;
		}
		else
			keys[2] = 0;
	}

	char KeyDown(int key)
	{
		return keys[key];
	}

	char KeyUp(int key)
	{
		return !keys[key];
	}

	char KeyPressed(int key)
	{
		return keys[key] && !lastKeys[key];
	}

	char KeyReleased(int key)
	{
		return !keys[key] && lastKeys[key];
	}
}

/* Example Code
#include "FasterLib.h"
#include "InputLib.h"

int main()
{
  Input::Init(); //Initialize the input pins
  TRISD(3, 1); //Makes the PD3 pin 'Output';
  TRISD(4, 1); //Makes the PD4 pin 'Output';
  while(true)
  {
    static unsigned char pressed = false;

    //Update and set key values
    Input::Update();
    Input::Events();
    
    if(Input::KeyDown(0)) //Check if key '0' is being hold
      PD(3, 1); //Writes high to the PD3 pin
    else
      PD(3, 0); //Writes low to the PD3 pin

    if(Input::KeyPressed(1)) //Checks if key '1' is pressed once
      pressed = !pressed;

    if(pressed)
      PD(4, 1);
    else
      PD(4, 0);
  }
} 
 */
