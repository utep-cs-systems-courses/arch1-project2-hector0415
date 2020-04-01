# Blinky Buzzy Toy
## Files
- There are two sub directories.
1. src
2. timelib
## How to install the program
1. Run the following command in the project sub directory.
> make install
2. After running that command, the libraries for the timer are created as well 
as the .elf file in the src subdirectory. To load the program onto the msp430, 
run the following command
> make load
## Cleaning up the src sub directory
To remove .o and the .elf files from the sub directory, run the following command.
> make clean
## What the program does
When the program is initially loaded into the msp430, the LED's are turned off
and the buzzer is not buzzing.
### Pressing SW1
Pressing SW1 will case the **RED** LED to light up and a tone to play continuously.
### Pressing SW2
Pressing SW2 will cause a tune to play continuously wich changes the tone of the buzzer and flashes the LED's/
### Pressing SW3
Pressing SW3 will cause both lights to shine dim and a continuous tone to play.
### Pressing SW4
Pressing SW4 will cause both lights to shine bright and a continuous tone to play which is higher pitched compared to the tone played by SW3.
