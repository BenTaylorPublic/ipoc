# IPOC Core #

IPOC is a framework that provides tools for fast development.  
Some of it's functionality are listed below.

## Debugging ##
1. Log to a text file, or console
2. Crash reports and error codes (you can call a crash from anywhere)
3. Global getStatusString() logging, which you can use to get the state of every object and log it
4. Warnings based on the run speed of the computer (if it isn't capable of running X FPS)
5. Memory leak monitoring for every class

## Other cool features ##
1. Use pull notifications on an InputController, to receive user input, from the entire KeyBoard and mouse position, relative or absolute to the window.
2. Use a ThreadManager, to quickly start your custom threads
3. Using an OnscreenButtonManager, you can add a button in around 6 lines of code. Just choose how it triggers (TriggerOnDown, TriggerOnUp, TriggerOnHold) and add Drawables to it's up and down position, and add a hotbox and you're set.
4. Using a hidden ID system, you can easily add Buttons to be tracked, and Drawables to the frame, without having to store it separately (all hidden).
5. The frame uses a layering system, starting from 0, maxing at MAX_INT, which allows you to design your visuals from the ground up.


## SFML ##
Using SFML as a base, IPOC allows the user to quickly load textures, create sprites, and start animating in a tiny amount of lines.  
SFML is entirely wrapped, so the graphics library can be swapped out with ease, if a better choice comes along.

## Setting up ##
I might add this later, but not now, dbf