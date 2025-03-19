# 8051 Microcontroller Programs and Tutorials

Welcome to my 8051 microcontroller repository! This collection contains various programs and projects developed during the **Embedded System Design Lab (ECL-322)**, along with additional ones for hands-on learning. The code covers fundamental concepts and practical implementations in both Assembly and Embedded C, offering a valuable resource for exploring 8051 microcontroller programming.

---

## 🛠️ **Tools and Software Used**
- **Keil μVision:** For writing, simulating, and debugging code.
- **Proteus:** For circuit simulation and hardware validation.
- **Flash Magic:** For burning hex files onto the 8051 microcontroller.

---

## 📂 **Repository Structure**

### **1. Lab Tasks (ECL-322)**
These tasks cover essential concepts in embedded system development, completed as part of the **Embedded System Design Lab (ECL-322)**.

#### `01_lab_tasks/`
- **exp1-6.pdf:** Documentation for experiments 1 to 6.
- **exp7-9.pdf:** Documentation for experiments 7 to 9.

---

### **2. Additional Projects**
These projects extend beyond basic lab tasks, focusing on real-world applications and practical learning.

#### **Directories:**

- ### **adc/**
  - **Description:** Demonstrates Analog-to-Digital Conversion (ADC).
  - **Includes:** Assembly and Embedded C code, Proteus simulation files.

- ### **blink_led/**
  - **Description:** Basic LED blinking program.
  - **Includes:** Code in Assembly and Embedded C.

- ### **counter/**
  - **Description:** Implements a counter (00 to 99) displayed on an LCD.
  - **Includes:** Counter code in Assembly and Embedded C.

- ### **hc05/**
  - **Description:** Bluetooth communication using the HC-05 module.
  - **Includes:** Example code for interfacing and communication.

- ### **interrupts/**
  - **Description:** Demonstrates handling interrupts in 8051.
  - **Includes:** Examples for edge-triggered and level-triggered interrupts.

- ### **lcd_interfacing/**
  - **Description:** Interfacing a 16x2 LCD with 8051.
  - **Includes:** Code in both Assembly and Embedded C.

- ### **pwm/**
  - **Description:** Pulse Width Modulation (PWM) implementation.
  - **Includes:** Source code, startup file, and simulation files.

- ### **serial/**
  - **Description:** Serial communication (UART) implementation.
  - **Includes:** Code for transmitting and receiving data.

- ### **seven_segment_display/**
  - **Description:** Displays numbers on a 7-segment display.
  - **Includes:** Code for interfacing 7-segment displays.

- ### **simple_actuators/**
  - **Description:** Control simple actuators like buzzers, motors, and relays.
  - **Includes:** Separate subdirectories for each actuator.

- ### **stepper_motor/**
  - **Description:** Stepper motor control with different driving techniques.
  - **Includes:** Full-step, half-step, and wave-step control code.

---

## 📘 **Getting Started**

### **Clone the Repository:**
```bash
git clone https://github.com/Sumitb09/8051.git
cd 8051
```

### **Open Projects in Keil μVision:**
1. Import the `.c` or `.asm` files into Keil μVision.
2. Compile and build the project to generate the hex file.

### **Simulate Using Proteus:**
1. Load the `.DSN` file into Proteus.
2. Link the generated hex file from Keil to the 8051 microcontroller component.

### **Upload to Hardware:**
Use Flash Magic to burn the hex file onto your 8051 microcontroller.

---

If you find this repo helpful, do leave it with a ⭐.
