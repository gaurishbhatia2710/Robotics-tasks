// Name : Gaurish Bhatia
//Student ID : 2110994762.
// remarks: this is the code file for the reciever.


#include <VirtualWire.h>

void setup()// setup
{

  pinMode(10, OUTPUT);  //left motors forward
  pinMode(11, OUTPUT);  //left motors reverse
  pinMode(12, OUTPUT);  //right motors forward
  pinMode(13, OUTPUT);  //right motors reverse
  Serial.begin(9600);

  vw_set_rx_pin(9);// setting the data pin as 9th digital pin.

  vw_setup(2000);


  vw_rx_start();// start recieving.
}

void loop()
{
  uint8_t data[VW_MAX_MESSAGE_LEN];// data in the 8 bit format.
  uint8_t datalen = VW_MAX_MESSAGE_LEN;//length of the data.

  if (vw_get_message(data, &datalen))// checking for data recieved.
  {
    // different if else conditions for the data recieved.
    if (data[0] == 'f')
    {
      forward();// calling the forward function

    }
    else if (data[0] == 'b')
    {
      back();// calling the back function
    }

    else if (data[0] == 'l')
    {
      left();// calling the left function

    }

    else if (data[0] == 'r')
    {
      right();// calling the right function.
    }

    else if (data[0] == 's')
    {
      stopp();// calling the stop function
    }
  }

}

void forward()// forward function
{
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
}

void back()// backward function
{
  digitalWrite(12, HIGH);
  digitalWrite(10, HIGH);
}

void left()// left function
{
  digitalWrite(13, HIGH);
}

void right()// right function.
{
  digitalWrite(11, HIGH);
}

void stopp()// stopp function
{
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
}
