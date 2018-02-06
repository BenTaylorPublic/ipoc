# BOSS SIM #

It's a gam

# IPOC #

IPOC is a framework that provides tools for fast development.  
Some of it's functionality are listed below.

## Debugging ##
1. Log to a text file, or console
2. Crash reports and error codes (you can call a crash from anywhere) (error logging to server coming soon tm)
3. Warnings based on the run speed of the computer (if it isn't capable of running X FPS)
4. Memory leak monitoring for every class

## Other cool features ##
1. Use pull notifications on an InputController, to receive user input, from the entire KeyBoard and mouse position, relative or absolute to the window.
2. Use a ThreadManager, to quickly start your custom threads
3. Using an InputController, you can add an onscreen button in around 6 lines of code. Just choose how it triggers (TriggerOnDown, TriggerOnUp, TriggerOnHold) and add Drawables to it's up and down position, and add a hitbox and you're set.
4. Using a hidden ID system, you can easily add Buttons to be tracked, and Drawables to the frame, without having to store it separately (all hidden).
5. The frame uses a layering system, starting from 0, maxing at MAX_INT, which allows you to design your visuals from the ground up.

## Deployment ##
Currently, with a small test app, the whole directory is ~4mb.
All you should need to do is send a .zip file to the recipient and it should work.

## Program Specific Code ##
Code for a specific program should be limited to:
1. ProcessController.process()
2. ProcessController.load()
3. Storage
4. ThreadManager
And any other objects which can be made and added to the project

## SFML ##
Using SFML as a base, IPOC allows the user to quickly load textures, create sprites, and start animating in a tiny amount of lines.

## Setting up ##
### MAC ###
1. Get the NetBeans 8.2
2. Get HomeBrew (command: /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" )
3. command: brew install sfml
4. Build and run, and let it error
5. Copy the files next to the executable, from an existing working repo
6. Build and run, Done!
### Windows ###
Not sure yet. I'll be doing this again soon though.