# arduino_projects
Project shows three programs.

<h2>1. Game</h2

The program allows you to play the game on 16x2 LCD display. The control is via an ultrasonic distance sensor.
Depending on whether you are at a distance greater than 150 cm (upward movement) or less than 150 cm (downward movement).
The rules of the game are as follows:
- To win the game you must avoid obstacles by moving up or down
- A maximum of 15 points can be scored
- When you touch the obstacle, the game ends and the number of points scored is displayed.

The result is displayed by 4 LEDs in a binary system. After the game is over, you can play again by pressing the button.

<h2>2. Parking sensor</h2>

The program uses three ultrasonic sensors to warn of approaching obstacles. It is happening in two ways - visually,
through LEDs, and audibly, through a sound signal generator. Take into account of the warning system, the element
closest to the sensors is taken into account.

<h2>3. A program that uses a photoresistor and a temperature sensor</h2>

The program, using a temperature sensor and a photoresistor, records the measurements and saves them on the display.
The actual and the largest measurements are displayed. After pressing the button, the highest measurements remain
deleted.
