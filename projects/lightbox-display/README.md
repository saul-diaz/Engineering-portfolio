# Personalized Lightbox Display 

## Technologies Used
- **Microcontroller:** Arduino Mega
- **Programming Language:** C++
- **Peripherals:** LED Matrix, PS2 Keyboard
- **Libraries:** 'PS2Keyboard.h', 'RGBmatrixPanel.h'


## Project Overview
This project implements a **real-time LED matrix display system** controlled via a **PS2 Keyboard**. It allows users to **input custom text, animations, and lighting effects**, providing an interactive user experience.

## Features
✔ **Customizable LED colors & flashing patterns**  
✔ **Real-time text input processing** via PS2 Keyboard  
✔ **Geometric shape rendering & dynamic animations**  
✔ **Efficient memory usage for smooth performance**  



## Code
- **Main Logic:** [main.ino](main.ino)
- **Circuit Schematic:** [schematic.pdf](schematic.pdf)

## Challenges & Solutions
| Challenge | Solution |
|-----------|----------|
| Managing real-time user input | Optimized **interrupt handling** for PS2 keyboard |
| Improving LED refresh rate | Used **RGBmatrixPanel** for efficient rendering |
| Handling memory constraints | Implemented **buffered updates** to prevent flickering |
