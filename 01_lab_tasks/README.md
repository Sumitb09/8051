# 8051 Microcontroller Assembly Programs

This repository contains various 8051 microcontroller assembly programs demonstrating key concepts such as arithmetic operations, loops, interrupts, and interfacing peripherals.

---

### **1. Fibonacci Series Generation up to the 10th Term**

**Description:**  
Generates and stores the first 10 Fibonacci numbers starting at memory location `2000H`.

**Code:**
```assembly
MOV R1, #0AH       ; Load R1 with 10 (number of terms)
MOV R2, #00H       ; Clear R2
MOV A, #00H        ; First Fibonacci number (0)
MOV DPTR, #2000H   ; Data pointer to store the output
MOVX @DPTR, A      ; Store first term (0)
INC A              ; Second term (1)
INC DPTR
MOVX @DPTR, A      ; Store second term (1)
DEC R1             ; Decrease count (now 8 terms remaining)
DEC R1
INC DPTR
MOV A, #00H        ; Initialize for calculation
MOV B, #01H

LOOP: ADD A, B     ; A = A + B
      MOV R2, A    ; Store sum in R2
      MOVX @DPTR, A ; Store current Fibonacci term
      INC DPTR
      MOV A, B     ; Move previous B to A
      MOV B, R2    ; Move current sum to B
      DJNZ R1, LOOP ; Decrement and repeat
END
```
**Output Location:**  
View the result at `x:2000H`.

---

### **2. Count Odd and Even Numbers**

**Description:**  
Counts the number of odd and even numbers in an array of 5 elements starting at `20H`.

**Code:**
```assembly
ORG 00H
MOV R0, #20H       ; Address of the array
MOV R2, #05H       ; Number of elements in the array
MOV A, #00H        ; Initialize even count
MOV B, #00H        ; Initialize odd count
MOV R1, #00H       ; Temporary storage

UPPER_LOOP:
  MOV A, @R0       ; Load element from array
  ANL A, #01H      ; Check if it's odd
  JZ EVEN          ; Jump to EVEN if zero
  INC B            ; Increment odd count
  SJMP NEXT_ELEMENT

EVEN: 
  INC R1           ; Increment even count

NEXT_ELEMENT:
  INC R0           ; Move to the next element
  DJNZ R2, UPPER_LOOP ; Decrement and repeat

MOV 25H, R1        ; Store even count at 25H
MOV 26H, B         ; Store odd count at 26H
END
```

---

### **3. 2x2 Matrix Determinant Calculation**

**Description:**  
Calculates the determinant of a 2x2 matrix where elements are stored in `20H` - `23H`.

**Code:**
```assembly
ORG 0000H          
MOV A, 20H         ; Load 'a'
MOV R0, A          
MOV A, 21H         ; Load 'b'
MOV R1, A          
MOV A, 22H         ; Load 'c'
MOV R2, A          
MOV A, 23H         ; Load 'd'
MOV R3, A          

; Calculate a * d
MOV A, R0          
MOV B, R3          
MUL AB             
MOV 24H, A         
MOV 25H, B         

; Calculate b * c
MOV A, R1          
MOV B, R2          
MUL AB             
MOV 26H, A         
MOV 27H, B         

; Calculate (a * d) - (b * c)
MOV A, 24H         
CLR C              
SUBB A, 26H        
MOV 28H, A         

MOV A, 25H         
SUBB A, 27H        
MOV 29H, A         

END
```

---

### **4. Sort an Array in Ascending and Descending Order**

**Ascending Order:**
```assembly
ORG 0000H                  
MOV R4, #04H               
LOOP2: MOV R3, #04H        
MOV R0, #20H               
CLR C                      

LOOP1: MOV A, @R0          
MOV R1, A                  
INC R0                     
MOV A, @R0                 
SUBB A, R1                 
JNC SKIP                   

MOV A, @R0                 
DEC R0                     
MOV @R0, A                 
MOV A, R1                  
INC R0                     
MOV @R0, A                 

SKIP: DJNZ R3, LOOP1       
DJNZ R4, LOOP2             
END                        
```

**Descending Order:**
```assembly
ORG 0000H             
MOV R4, #04H          
LOOP2: MOV R3, #04H   
MOV R0, #20H          
CLR C                 

LOOP1: MOV A, @R0     
MOV R1, A             
INC R0                
MOV A, @R0            
SUBB A, R1            
JC SKIP               

MOV A, @R0            
DEC R0                
MOV @R0, A            
MOV A, R1             
INC R0                
MOV @R0, A            

SKIP: DJNZ R3, LOOP1  
DJNZ R4, LOOP2        
END                   
```

---

### **5. Factorial Calculation**

**Description:**  
Calculates the factorial of a number stored at `20H`.

**Code:**
```assembly
ORG 00H
MOV A, 20H        ; Load number
MOV R1, A         
MOV A, #01H       

FACTORIAL_LOOP:
MOV B, R1         
MUL AB            
DJNZ R1, FACTORIAL_LOOP 

MOV 21H, A        ; Store result at 21H
END
```

---

### **6. LED Blink Program with 50ms Delay**

**Description:**  
Blinks an LED connected to Port 1 with a 50ms delay.

**Code:**
```assembly
ORG 0000H
SJMP START
ORG 0030H
START: MOV P1, #00H
RPT: MOV A, #55H
 MOV P1, A
 ACALL Delay
 CPL A
 MOV P1, A
 ACALL Delay
 SJMP RPT

ORG 0100H
Delay: MOV R0, #0FFH
loop2: MOV R1, #0FFH
loop1: DJNZ R1, loop1
 DJNZ R0, loop2
 RET
END
```

---

### **7. Square Wave Generation with 1s Period Using Timer-1**

**Description:**  
Generates a square wave with a 1-second period on Port 1.

**Code:**
```assembly
ORG 0000H
SJMP MAIN
ORG 0030H
MAIN: MOV P1, #00H
MOV TMOD, #10H
AGAIN: CPL P1.0
MOV R0, #14H
RPT: MOV TH1, #3CH
MOV TL1, #0B0H
SETB TR1
CHECK: JNB TF1, CHECK
CLR TR1
CLR TF1
DJNZ R0, RPT
SJMP AGAIN
END
```

---

### **8. Servo Motor Control Program**

**Description:**  
Controls a servo motor to set angles at 0°, 90°, and 180° using delays for pulse width modulation (PWM).

```assembly
ORG 0000H
LJMP START

ORG 0100H
START: MOV P1, #00H        ; Initialize Port 1 to 0
       MOV TMOD, #11H       ; Timer 0 and Timer 1 in mode 1 (16-bit timer mode)

RPT:   ACALL ANG0           ; Call subroutine for 0 degrees (1ms high pulse)
       ACALL ANG90          ; Call subroutine for 90 degrees (1.5ms high pulse)
       ACALL ANG180         ; Call subroutine for 180 degrees (2ms high pulse)
       SJMP RPT             ; Repeat continuously

; Subroutine for 0 degrees
ORG 0200H
ANG0:  MOV P1, #0FFH        ; Set Port 1 high
       MOV TH0, #0FCH       ; Timer value for 1ms delay (high pulse)
       MOV TL0, #18H
       SETB TR0
CHECK1: JNB TF0, CHECK1
       CLR TR0
       CLR TF0

       MOV P1, #00H         ; Set Port 1 low
       MOV TH1, #0B5H       ; Timer value for 19ms delay (low pulse)
       MOV TL1, #0C8H
       SETB TR1
CHECK2: JNB TF1, CHECK2
       CLR TR1
       CLR TF1
       RET

; Subroutine for 90 degrees
ORG 0300H
ANG90: MOV P1, #0FFH        ; Set Port 1 high
       MOV TH0, #0FAH       ; Timer value for 1.5ms delay (high pulse)
       MOV TL0, #24H
       SETB TR0
CHECK3: JNB TF0, CHECK3
       CLR TR0
       CLR TF0

       MOV P1, #00H         ; Set Port 1 low
       MOV TH1, #0B7H       ; Timer value for 18.5ms delay (low pulse)
       MOV TL1, #0BCH
       SETB TR1
CHECK4: JNB TF1, CHECK4
       CLR TR1
       CLR TF1
       RET

; Subroutine for 180 degrees
ORG 0400H
ANG180: MOV P1, #0FFH       ; Set Port 1 high
        MOV TH0, #0F8H      ; Timer value for 2ms delay (high pulse)
        MOV TL0, #30H
        SETB TR0
CHECK5: JNB TF0, CHECK5
        CLR TR0
        CLR TF0

        MOV P1, #00H        ; Set Port 1 low
        MOV TH1, #0B9H      ; Timer value for 18ms delay (low pulse)
        MOV TL1, #0B0H
        SETB TR1
CHECK6: JNB TF1, CHECK6
        CLR TR1
        CLR TF1
        RET

END
```

### **9. Stopwatch Program**

**Description:**  
A simple stopwatch using push-buttons connected to Port 3 (`P3.0` for start, `P3.1` for stop, `P3.2` for reset). It increments a counter on Port 1 with each second.

**Code:**
```assembly
ORG 0000H
MOV P1, #00H            ; Initialize Port 1 to 0

MAIN: JB P3.0, START    ; Check if START button is pressed
      JB P3.1, STOP     ; Check if STOP button is pressed
      JB P3.2, RESET    ; Check if RESET button is pressed
      SJMP MAIN         ; Repeat the loop

START: ACALL DELAY_1_SEC  ; Call 1-second delay subroutine
       INC P1            ; Increment Port 1 to display count
       SJMP MAIN         ; Return to main loop

STOP:  SJMP MAIN         ; Stay in the loop until other buttons are pressed

RESET: MOV P1, #00H      ; Reset Port 1
       SJMP MAIN         ; Return to main loop

; 1-second delay subroutine
DELAY_1_SEC:
       MOV R1, #20       ; Outer loop count
       MOV R2, #250      ; Middle loop count
       MOV R3, #250      ; Inner loop count

DELAY_LOOP:
       DJNZ R3, DELAY_LOOP
       DJNZ R2, DELAY_LOOP
       DJNZ R1, DELAY_LOOP
       RET

END
```

---

### **10. Variable Square Wave Generation with 10ms High and 20ms Low Pulse Widths**

**Description:**  
Generates a square wave with a 10ms high pulse and a 20ms low pulse using Timers 0 and 1.

**Code:**
```assembly
ORG 0000H
LJMP START

ORG 0300H
START: MOV P1, #00H           ; Set Port 1 low
       MOV TMOD, #11H         ; Load TMOD for Timers 0 and 1 in mode 1

RPT:   MOV P1, #0FFH          ; Set Port 1 high
       ACALL DELAY1           ; Call 10ms delay for high pulse
       MOV P1, #00H           ; Set Port 1 low
       ACALL DELAY2           ; Call 20ms delay for low pulse
       SJMP RPT               ; Repeat the loop

; Delay for high pulse (10ms)
ORG 0030H
DELAY1: MOV TH0, #0D8H        ; Timer high byte for 10ms
        MOV TL0, #0F0H        ; Timer low byte for 10ms
        SETB TR0              ; Start Timer 0
CHECK1: JNB TF0, CHECK1       ; Wait until Timer 0 overflows
        CLR TR0               ; Stop Timer 0
        CLR TF0               ; Clear overflow flag
        RET

; Delay for low pulse (20ms)
ORG 00A0H
DELAY2: MOV TH1, #0B1H        ; Timer high byte for 20ms
        MOV TL1, #0E0H        ; Timer low byte for 20ms
        SETB TR1              ; Start Timer 1
CHECK2: JNB TF1, CHECK2       ; Wait until Timer 1 overflows
        CLR TR1               ; Stop Timer 1
        CLR TF1               ; Clear overflow flag
        RET

END
```

---

### **11. Square Wave Generation with 50% Duty Cycle and 1 kHz Frequency Using Timer-0**

**Description:**  
Generates a square wave on Port 1 with a 50% duty cycle and 1 kHz frequency using Timer-0 in mode-2.

**Code:**
```assembly
ORG 0000H
SJMP START

ORG 0030H
START: MOV P1, #00H           ; Initialize Port 1 low
       MOV TMOD, #02H         ; Set Timer-0 in mode-2 (8-bit auto-reload)
       MOV TH0, #00H          ; Load Timer high byte with 0

AGAIN: CPL P1.0               ; Toggle all bits of Port 1
       CPL P1.1
       CPL P1.2
       CPL P1.3
       CPL P1.4
       CPL P1.5
       CPL P1.6
       CPL P1.7

       MOV R0, #2             ; Outer loop for timing
RPT:   SETB TR0               ; Start Timer 0
CHECK: JNB TF0, CHECK         ; Wait for Timer overflow
       CLR TR0                ; Stop Timer 0
       CLR TF0                ; Clear overflow flag
       DJNZ R0, RPT           ; Decrement and repeat loop
       SJMP AGAIN             ; Repeat the waveform generation loop

END
```

---