

//Name : Gaurish Bhatia
//STUDENT ID : 2110994762
//remarks: this is the code file for the transmitter.


#include <VirtualWire.h>
char t;// character for storing the data sent by the bluetooth module.

char *data;// character data for stroing the data that is needed to be sent to the receiver.

void setup() // setup
{
  pinMode(11, OUTPUT);  //left motors forward
  pinMode(12, OUTPUT);  //left motors reverse
  pinMode(13, OUTPUT);  //right motors forward
  pinMode(8, OUTPUT);  //right motors reverse
  Serial.begin(9600);

  vw_set_tx_pin(9);// setting the data transmit pin as the 9th digital pin on the arduino.

  vw_setup(2000);




}
void loop()// loop part.
{
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }
  if (t == 'F') // checking if the bluetooth has recieved forward.
  {
    data = "f";
    vw_send((uint8_t *)data, strlen(data));// sending the data.
    vw_wait_tx();
    forward();// calling the forward function.

  }
  else if (t == 'B') // checking if the bluetooth has recieved backward.
  {
    data = "b";
    vw_send((uint8_t *)data, strlen(data));// sending the data.
    vw_wait_tx();
    Back();// calling the back function.
  }

  else if (t == 'L') // checking if the bluetooth has recieved Left.
  {

    data = "l";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    Left();// calling the left function.

  }

  else if (t == 'R') // checking if the bluetooth has recieved Right.
  {

    data = "r";
    vw_send((uint8_t *)data, strlen(data));// sending the data.

    vw_wait_tx();
    Right();// calling the right function.

  }



  else if (t == 'S') // checking if the bluetooth has recieved Stop.
  {

    data = "s";
    vw_send((uint8_t *)data, strlen(data));// sending the data.

    vw_wait_tx();
    Stop();// calling the stop function.


  }
}


void forward()
{
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);

}
void Back()
{
  digitalWrite(12, HIGH);
  digitalWrite(8, HIGH);


}
void Left()
{
  digitalWrite(13, HIGH);

}

void Right()
{
  digitalWrite(11, HIGH);

}


void Stop()
{
  digitalWrite(8, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(11, LOW);
}
