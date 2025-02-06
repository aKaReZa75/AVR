# Bit Operation Macros for Microcontroller
In this document, we have macros that perform bitwise operations on registers.  
We define each macro and analyze how they work, including examples to demonstrate their functionality.

> [!NOTE]
> While the examples in this document are provided for the ATMEGA328 microcontroller, the concepts and macros can be similarly applied to other microcontrollers as well.

## 1. bitSet(_Reg, _Bit)
Sets the specified bit in the register.  
**Example:** To set bit 2 in PORTB (e.g., turning on an LED connected to PORTB2):
```c
bitSet(PORTB, 2);  // Equivalent to: PORTB |= (1 << 2);
```

## 2. bitClear(_Reg, _Bit)
Clears the specified bit in the register.  
**Example:** To clear bit 2 in PORTB (e.g., turning off an LED connected to PORTB2):
```c
bitClear(PORTB, 2);  // Equivalent to: PORTB &= ~(1 << 2);
```

## 3. bitToggle(_Reg, _Bit)
Toggles the specified bit in the register.  
**Example:** To toggle bit 2 in PORTB (e.g., blinking an LED connected to PORTB2):
```c
bitToggle(PORTB, 2);  // Equivalent to: PORTB ^= (1 << 2);
```

## 4. bitChange(_Reg, _Bit, Value)
Changes the specified bit in the register to 1 if Value is 1, or clears it if Value is 0.  
**Example:** To set or clear bit 4 in PORTC based on a given value:
```c
bitChange(PORTC, 4, 1);  // Sets bit 4
bitChange(PORTC, 4, 0);  // Clears bit 4
```

## 5. bitCheck(_Reg, _Bit)
Checks the status of the specified bit in the register and returns `1` if the bit is set (logic high) or `0` if cleared (logic low).  
This is particularly useful for reading the state of input pins, such as a button or a switch.

**Example:** Reading the state of a button connected to pin 3 of PORTB:
```c
if (bitCheck(PINB, 3)) /**< Read the button state */
{  
    /* Button is pressed (active High) */
} 
else 
{
    /* Button is not pressed */
}
```

## 6. bitCheckHigh(_Reg, _Bit)  
Checks if the specified bit in the register is high (`1`).   
It is essentially the same as `bitCheck()`, but explicitly named for clarity.  

**Example:** Check if button is pressed (active-high) and toggle LED:
```c
if (bitCheckHigh(PINB, 0)) /**< If button connected to PINB0 is HIGH (pressed) */
{  
    bitToggle(PORTB, 2);       /**< Toggle LED connected to PORTB2 */
}
```

### Explanation:
- `bitCheckHigh(PINB, 0)` checks if the button on `PINB0` is pressed (active-high).
- If pressed, it toggles an LED connected to `PORTB1`.

**Use case:** Used for buttons or signals where a logic high (`1`) represents an active state.

---

## 7. bitCheckLow(_Reg, _Bit)  
Checks if the specified bit in the register is low (`0`). It is a negated version of `bitCheck()` and helps in cases where an active-low signal needs to be checked.  

**Example:** Check if button is pressed (active-low) and toggle LED:
```c
if (bitCheckLow(PINB, 1)) /**< If button connected to PINB1 is LOW (pressed) */
{  
    bitToggle(PORTB, 2);       /**< Toggle LED connected to PORTB2 */
}
```

### Explanation:
- `bitCheckLow(PINB, 0)` checks if the button on `PINB0` is pressed (active-low).
- If pressed, it toggles an LED connected to `PORTB1`.

**Use case:** Used for buttons or signals where a logic low (`0`) represents an active state.

## 8. bitWaitHigh(_Reg, _Bit)
Waits (blocks execution) until the specified bit in the register becomes high (`1`).  
This is useful when waiting for hardware events, such as the completion of data reception in USART.

**Example:** Waiting for received data (RX Complete) in USART:
```c
// Wait until the RXC0 flag in UCSR0A is set (indicating data received)
bitWaitHigh(UCSR0A, RXC0);

// Read received data from UDR0
uint8_t receivedData = UDR0;
```

### Explanation:
- The `RXC0` bit in `UCSR0A` is set when a byte has been received.
- `bitWaitHigh(UCSR0A, RXC0);` ensures that execution halts until data is received.
- After the bit is set, the received data is read from `UDR0`.

## 9. bitWaitLow(_Reg, _Bit)
Waits (blocks execution) until the specified bit in the register becomes low (`0`).  
This is useful for ensuring an action is executed only after a button release.

**Example:** Detect button press and wait for release before executing an action:
```c
if (bitCheckLow(PINB, 1)) /**< Check if button (connected to PINB1) is pressed (active low) */
{  
    bitWaitLow(PINB, 1);   /**< Wait until the button is released (PINB1 becomes high) */
    bitToggle(PORTB, 2);       /**< Toggle LED connected to PORTB2 */
}
```

### Explanation:
- First, we use `bitCheck(PINB, 0)` to check if the button is pressed (active low).
- If the button is pressed (`0` detected), we use `bitWaitLow(PINB, 0);` to wait until it is released (`1` detected).
- Once released, an action (such as toggling an LED) is performed.

## 10. bitShiftLeft(_Reg, _Pos)
Shifts the bits in the register to the left by _Pos positions.  
**Example:** To shift the contents of PORTD left by 1 bit:
```c
bitShiftLeft(PORTD, 1);  // Equivalent to: PORTD = PORTD << 1;
```

## 11. bitShiftRight(_Reg, _Pos)
Shifts the bits in the register to the right by _Pos positions.  
**Example:** To shift the contents of PORTD right by 2 bits:
```c
bitShiftRight(PORTD, 2);  // Equivalent to: PORTD = PORTD >> 2;
```

## 12. Conv_16to8_MSB(_Value)  
Extracts the most significant 8 bits (MSB) from a 16-bit value.  
**Example:** Extracting the MSB of Timer1 (TCNT1) register 
```c
uint8_t timer1_msb = Conv_16to8_MSB(TCNT1);  /*< Extract the high byte of Timer1 */
```
### Explanation:
- TCNT1 is a 16-bit register storing the current value of Timer1.
- Conv_16to8_MSB(TCNT1) extracts the high byte (TCNT1H).

## 13. Conv_16to8_LSB(_Value)
Extracts the least significant 8 bits (LSB) from a 16-bit value.  
**Example:** Extracting the LSB of Timer1 (TCNT1) register
```c
uint8_t timer1_lsb = Conv_16to8_LSB(TCNT1);  /**< Extract the low byte of Timer1 */
```
### Explanation:
- TCNT1 is a 16-bit register storing the current value of Timer1.
- Conv_16to8_LSB(TCNT1) extracts the low byte (TCNT1L).

## 14. Combine_8to16(_valueHigh, _valueLow)
Combines two 8-bit values into a 16-bit value, using _valueHigh as the most significant byte.  
**Example:** Reconstructing Timer1 value from its high and low bytes
```c
uint16_t timer1_value = Combine_8to16(TCNT1H, TCNT1L);
```
### Explanation:
- TCNT1H holds the most significant 8 bits of Timer1.
- TCNT1L holds the least significant 8 bits of Timer1.
- Combine_8to16(TCNT1H, TCNT1L) reconstructs the full 16-bit Timer1 value.

## 15. GPIO_Config_OUTPUT(_Reg, _Bit)
These macros enhance code readability when configuring GPIO pins. Typically, setting a bit to 1 configures the pin as output, while clearing it (0) configures it as input.  
However, in some microcontrollers, this behavior might be reversed.

**Example:**
```c
// Set pin 0 of DDRB (Data Direction Register for PORTB) as output.
GPIO_Config_OUTPUT(DDRB, 0);
```

## 16. GPIO_Config_INPUT(_Reg, _Bit)
These macros enhance code readability when configuring GPIO pins. Typically, setting a bit to 1 configures the pin as output, while clearing it (0) configures it as input.  
However, in some microcontrollers, this behavior might be reversed.

**Example:**  
```c
// Set pin 0 of DDRB as input.
GPIO_Config_INPUT(DDRB, 0);
```

## 17. delay_ms(_delay_msValue)
Introduces a delay in milliseconds using the standard _delay_ms() function.  
**Example:**  
```c
// Delay for 500 milliseconds.
delay_ms(500);
```

## 18. globalInt_Enable
Enables global interrupts by setting the I-bit in the SREG register.  
**Example:**  
```c
// Enable global interrupts.
globalInt_Enable;
```

## 19. globalInt_Disable
Disables global interrupts by clearing the I-bit in the SREG register.  
**Example:**  
```c
// Disable global interrupts.
globalInt_Disable;
```

## 20. intFlag_clear(Reg, Bit)
Clears an interrupt flag (or any flag) in a given register by writing a logic one to that bit, which is the standard method in AVR.  
**Example:**  
```c
// Clear an interrupt flag in TIFR0, e.g., the Timer/Counter0 Overflow Flag (TOV0).
intFlag_clear(TIFR0, TOV0);
```

## 21. Initialize and deInitialize
These macros serve as boolean constants to improve readability when configuring peripherals.

- **Initialize** is defined as `true` and represents enabling a peripheral.
- **deInitialize** is defined as `false` and represents disabling a peripheral.

**Example:** Configuring USART using Initialize and deInitialize
```c
usart_Init(Initialize);   /**< Enable and configure USART */
// ... Perform USART operations ...
usart_Init(deInitialize); /**< Disable USART and reset configurations */
```

## 22. Math Constants
Provides useful mathematical constants for your calculations.
- **Math_Const_PI:** Represents π (pi), approximately 3.14159265358979.
- **MATH_Const_EXP:** Represents Euler's number (e), approximately 2.71828182845904.  
**Example:**
```c
double circumference = 2 * Math_Const_PI * radius;
double growthFactor = pow(MATH_Const_EXP, time);
```

# 🌟 Support Me
If you found this repository useful:
- Subscribe to my [YouTube Channel](https://www.youtube.com/@aKaReZa75).
- Share this repository with others.
- Give this repository and my other repositories a star.
- Follow my [GitHub account](https://github.com/aKaReZa75).

# ✉️ Contact Me
Feel free to reach out to me through any of the following platforms:
- 📧 [Email: aKaReZa75@gmail.com](mailto:aKaReZa75@gmail.com)
- 🎥 [YouTube: @aKaReZa75](https://www.youtube.com/@aKaReZa75)
- 💼 [LinkedIn: @akareza75](https://www.linkedin.com/in/akareza75)