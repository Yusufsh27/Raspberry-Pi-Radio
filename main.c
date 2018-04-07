#include <wiringPi.h>
#include <stdio.h>
#include<stdlib.h>
// First we stated all the Libraries we are going to use throughout the Lab. We mention the wiringPi Library which correlates to the PinMode and other GPIO  commands
// Then we mention stdio which is the simple library for basic if, while and print statements.

#define pin1 6
#define pin4 5
#define pin5 1
#define pin6 4
// We defined a couple of variables at this point. We did not necessarily need to do this however it felt to us as it would become easier to us when  we
// go to complicated parts and there would be just random  numbers written at points than  "pin1". However later realizing the numbers were not correlating with
// the definitions we just changed the numbers and left the name the same. Saving us time however looking disorganized.

int main (void)
{
  int state = 0;
  wiringPiSetup();
  pinMode(1,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
// Finally we get to the start of the program. We start it of the main function, then define an integer state that will tell us the current state of the program 
// whether it is playing music of is stopped. Then we set 4 pinModes that tells us that those buttons are assigned to a certain GPIO from the RPI which provide us
// with an input and we can correlate those to a command.

  for(;;)
  {
// This for loop is just for the program to continue forever at least until the exit command is called.

        if (digitalRead(pin1) == LOW)
        {

              delay(500);

                if (state == 0)
                {

                  system("mpc play");
                  state = 1;

                }

        }
//This first "if statement" is there  to show once the music is off and the first button (pin1) is  pushed it will prompt the RPI to start eh command  MPC play.
// MPC is a software we received from the internet which lets us play internet radio from any station that provides us with a direct server link. and the 
// play option lets us play the music.

        if (digitalRead(pin5) == LOW)
        {

                delay(500);
                if(state == 1)
                {

                  system("mpc stop");
                  state = 0;

                }
        }
// We then get into the second "if" which lets  the user prompt the second button (pin5) the stop the occurring music playing. We did this by setting a state of the
// RPI which shows weather the RPI is playing music or not at the current moment. If it is then the Stop command will be available if not, then it won't be.

        if (digitalRead(pin4) == LOW)
        {

                delay (500);

                if(state == 1)
                {

                system("mpc next");

                }

        }
// The third if statement  is for the next station. We have incorporated three stations from the internet which then lets us play music. SO by pressing the next 
// button (pin4) it allows us to change to the next station on the playlist

        if (digitalRead(pin6) == LOW)
        {
                delay (500);

                if(state == 1)
                {

                system("mpc prev");

                }
        }
// Finally the last if statement is there to go the previous station. We tried to create a MP3 like project. In which we run multiple playlist servers then 
// we could go to the next station and previous station by pressing different buttons. The button you would have to press would be the last one (pin6).

  }
  return 0;
}
