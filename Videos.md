# Videos
In this document, you will find brief descriptions for each video.  
These summaries provide an overview of the topics covered in each video, allowing you to quickly and easily understand the content presented.  
The purpose of these short descriptions is to give a clear and concise understanding of each video's subject matter.

> [!IMPORTANT]
In this section, only **AVR**-related videos are available. These videos are generally divided into two main categories:
>
> 1. **General Concepts and Basics:**  
   This part includes videos that provide foundational knowledge and general principles of microcontrollers. Videos in this category typically begin with the word *`Microcontroller`*.
>      - **Example:** In the video "*aKaReZa 45 - Microcontroller, Interrupts*", the overall functionality and applications of interrupts across different types of microcontrollers are explained. This helps build a solid understanding of the interrupt mechanism before diving into specific implementations.  
>    
> 2. **Microcontroller-Specific Implementations:**  
    "This part focuses on detailed setups, configurations, and practical demonstrations tailored to a specific microcontroller.  
    Videos in this category are identified by keywords related to specific microcontroller families such as *`AVR`*, *`STM32`*, *`STM8`*, *`ESP8266`*, *`ESP32`*, and *`PIC`*.
>      - **Example for AVR:** In the video "*aKaReZa 55 - AVR, External Interrupts*", the setup and detailed explanation of external interrupts in `AVR` microcontrollers are provided, along with practical tests and real-world examples.  

> [!NOTE]
> 1. It is strongly advised to first watch the general concept videos (identified by the keyword *`Microcontroller`*) to build a solid theoretical foundation. 
> 2. Once you have a good understanding, proceed to the microcontroller-specific videos (identified by their respective keywords such as *`AVR`*, *`STM32`*, etc.) to see how these concepts are applied in practice.  

> [!TIP]  
> - The prerequisites for each video are clearly mentioned at the beginning of the respective video.  
> - For a complete and organized list of all fundamental topics along with their detailed explanations, visit:  
>    -  [Microcontroller Fundamental Videos](https://github.com/aKaReZa75/Microcontroller/Videos.md)


```plaintext
📁 AVR Microcontrollers
├── Fundamental
│   ├── [aKaReZa 6 - AVR, Introduction]
│   │   ├─ MCU Families — Overview and ATMEGA328 specs.
│   │   ├─ Clocking — Choosing clock sources.
│   │   └─ Power Up — Minimum hardware requirements.
│   │
│   ├── [aKaReZa 22 - AVR, Programming]
│   │   ├─ Tools — TNM2000+, USBasp, MKII, VsCode Upload.
│   │   └─ Methods — ZIF socket and onboard programming.
│   │
│   └── [aKaReZa 12 - AVR, fuseBits]
│       ├─ Fuse Bytes — Extended, High, Low config.
│       ├─ Lock Bits — Prevention and bit calculation.
│       └─ Tools — Online calculator + sync troubleshooting.
│
├── GPIO (General Purpose Input Output)
│   ├── [aKaReZa 20 - AVR, GPIO - Part A]
│   │   ├─ Output — Register config + LED control.
│   │   ├─ Simulation — Proteus + VsCode + PlatformIO.
│   │   └─ Optimization — Macros and timing sync.
│   │
│   ├── [aKaReZa 23 - AVR, GPIO - Part B]
│   │   ├─ Input — Pin setup + internal Pull-Up.
│   │   ├─ Simulation — Input handling code.
│   │   └─ Logic — `if` statements and decision-making.
│   │
│   └── External Interrupts
│       └── [aKaReZa 55 - AVR, External Interrupts]
│           ├─ INT0/INT1 — Setup and configuration.
│           ├─ Pin Change — Monitoring and control.
│           ├─ Flags — Manual clearing and management.
│           └─ Code — Using `eInterrupt.h` + performance tips.
│ 
├── Display Interfaces
│   ├── 7-Segment Displays
│   │   ├── [aKaReZa 44 - AVR, 7Segment - Part A]
│   │   │   ├─ Basics — Driving common anode + 4-digit multiplexing.
│   │   │   └─ Optimization — Readability and maintainability.
│   │   │
│   │   ├── [aKaReZa 47 - AVR, 7Segment - Part B]
│   │   │   ├─ Control — Button interaction and counter logic.
│   │   │   └─ Efficiency — Digit splitting + macro usage.
│   │   │
│   │   └── [aKaReZa 53 - AVR, 7Segment - Part C]
│   │       ├─ Modularity — Functions, headers, code structure.
│   │       ├─ Refresh — Button-hold bug fix via software.
│   │       └─ Timing — 1-second counter implementation.
│   │
│   └── Alphanumeric LCD
│        ├── [aKaReZa 57 - AVR, Alphanumeric LCD]
│        │   ├─ Setup — LCD connection using AVR microcontrollers.
│        │   ├─ Library — alcd functions and text display.
│        │   ├─ Custom Characters — Including Farsi text creation.
│        │   └─ Display Tuning — Decimal display and contrast adjustment.
│        │
│        ├── [aKaReZa 127 - AVR, Alphanumeric LCD - PART B]
│        │   ├─ Overview — Structure and operation of character LCDs.
│        │   ├─ Project — Creating a new project for LCD initialization.
│        │   ├─ Init — Configuring the LCD using alcd_init().
│        │   ├─ Write — Sending data and commands with alcd_write().
│        │   ├─ Mode — Understanding and using the 8-bit mode.
│        │   ├─ Putc — Displaying single characters with alcd_putc().
│        │   ├─ Puts — Displaying strings with alcd_puts().
│        │   └─ Positioning — Using alcd_gotoxy() to place characters.
│        │
│        └── [aKaReZa 129 - AVR, Alphanumeric LCD - PART C]
│            ├─ Clear — Resetting the display with alcd_clear().
│            ├─ Cursor — Managing cursor visibility via alcd_cursor().
│            ├─ Display — Controlling screen visibility using alcd_display().
│            ├─ Backlight — Enabling/disabling with alcd_backlight().
│            ├─ Custom — Defining characters using alcd_customChar().
│            ├─ Mode — Configuring LCD in 4-bit mode.
│            └─ Optimization — Pin-saving and efficiency tips.
|
├── Timers
│   ├── [aKaReZa 59 - Accurate Time - Mode 1]
│   │   ├─ Modes — Normal vs CTC explained.
│   │   ├─ Interrupts — Overflow vs Compare Match usage.
│   │   ├─ Timing — Execution time, intervals, exact delays.
│   │   └─ Display — 7-segment output + digit splitting.
│   │
│   ├── [aKaReZa 105 - PWM - Mode 2]
│   │   ├─ Modes — Fast PWM vs Phase Correct + TOP options.
│   │   ├─ Signals — OCR update, waveform control.
│   │   ├─ Techniques — Dual Slope PWM + Dead Time logic.
│   │   └─ Applications — Motor control, power conversion, LEDs.
│   │
│   ├── [aKaReZa 122 - Millis - Mode 7]
│   │   ├─ Tasks — Defining multiple independent routines.
│   │   ├─ Function — Building a `millis()` timer in AVR.
│   │   ├─ Multitasking — Cooperative scheduling without RTOS.
│   │   ├─ Tips — Effective use of non-blocking delays.
│   │   └─ Structure — Internal logic and timing components.
│   │
│   ├── [aKaReZa 136 - AVR, Timer, Counter - Mode 3]
│   │   ├─ Concept — Frequency measurement principles.
│   │   ├─ Timer1 — Full review and counter‑mode config.
│   │   ├─ Project — Frequency measurement project setup.
│   │   ├─ Timer2 — Review and timer‑mode with external clock.
│   │   ├─ High Freq — Methods for measuring high frequencies.
│   │   ├─ Accuracy — Error calculation and hardware limits.
│   │   └─ Range — Maximum measurable frequency analysis.
│   │
│   └── [aKaReZa 138 - AVR, Timer, Capture - Mode 4]
│       ├─ Techniques — Measuring signal period with timers + EXTI.
│       ├─ Project — Creating a Capture‑mode measurement project.
│       ├─ Prescaler — Choosing the right prescaler for accuracy.
│       ├─ Calculations — Period, frequency, duty cycle formulas.
│       ├─ Capture Unit — Full review and advantages.
│       ├─ Events — Computing parameters from Capture events.
│       ├─ Error Case — Identifying and analyzing measurement errors.
│       ├─ Noise Canceller — Introduction and practical usage.
│       └─ Long Intervals — Techniques for measuring long periods.
|
├── Analog Peripherals
│   └── ADC (Analog-to-Digital Converter)
│       └── [aKaReZa 77 - Analog - ADC]
│           ├─ Structure — Block diagram + registers.
│           ├─ Functions — Configuration + raw value reading.
│           ├─ Measurement — Voltage, multi-channel, temperature sensors.
│           ├─ Internals — MCU’s temp sensor + noise canceller feature.
│           └─ Accuracy — Clean signal acquisition strategies.
│
├── Communication Protocols
│   ├── USART (Universal Synchronous/Asynchronous Receiver/Transmitter)
│   │   ├── [aKaReZa 66 - Part A]
│   │   │   ├─ Intro — Features, block diagram, BaudRate calc.
│   │   │   ├─ Registers — Access and control setup.
│   │   │   ├─ Data Tx — Characters, strings, escape sequences.
│   │   │   └─ Testing — Simulation vs real-world comparison.
│   │   │
│   │   ├── [aKaReZa 67 - Part B]
│   │   │   ├─ Data Rx — Receiving, interrupts, buffering.
│   │   │   ├─ Reliability — Baud errors, flags, circular buffer.
│   │   │   ├─ Debug — Plotting and signal validation.
│   │   │   └─ Logic — Frame structure + escape sequence control.
│   │   │
│   │   └── [aKaReZa 112 - Part C]
│   │       ├─ Challenge — Frame termination issues with CR/LF.
│   │       ├─ Solution — Idle Detection strategy.
│   │       ├─ Timer2 — Structure, registers, configuration.
│   │       ├─ Implementation — Detecting end of transmission.
│   │       └─ Testing — Timing analysis and validation.
│   |
│   └── I2C (Inter-Integrated Circuit)
│       └── [aKaReZa 114 - PART A]
│           ├─ Intro — Protocol overview and use cases.
│           ├─ Registers — Block diagram and bit-level control.
│           ├─ Safety — Atomic operations for reliable comms.
│           └─ Functions — Init, Start, Write, Read, Sequential ops.
│
├── Motors
│   └── [aKaReZa 108 - Servo Motor]
│       ├─ Timer0 — 50Hz PWM base signal generation.
│       ├─ Timer1 — Mode 14 (Fast PWM), Mode 10 (Phase Correct).
│       ├─ Precision — Servo angle control and fine-tuning.
│       └─ Comparison — Output signals and mode differences.
│
├── Memory
│   └── EEPROM
│       ├── [aKaReZa 131 - AVR, EEPROM - PART A]
│       │   ├─ Concept — AVR internal EEPROM structure and use cases.
│       │   ├─ Registers — EEAR, EEDR, EECR bit-by-bit review.
│       │   ├─ Functions — uint8_write(), uint16_write(), uint32_write().
│       │   ├─ Endianness — Storage order considerations.
│       │   ├─ Type Punning — Advantages and safe usage.
│       │   └─ Project — Building and testing EEPROM write routines.
│       │
│       └── [aKaReZa 134 - AVR, EEPROM - PART B]
│           ├─ Float — Implementing float_Write() for floating‑point storage.
│           ├─ Block — Writing arrays and strings with block_Write().
│           ├─ Read — Functions for reading multiple data types.
│           ├─ Update — Smart update functions to reduce wear and speed up execution.
│           ├─ Timing — Execution‑time analysis and Update vs Write comparison.
│           ├─ Signed — Write/Read/Update for signed data types.
│           └─ Format — Erasing the entire EEPROM memory.
└── Modules
    └── GSM
        ├── [aKaReZa 113 - Quectel M66 - PART A]
        │     ├─ Setup — New GSM project and module configuration.
        │     ├─ AT Commands — Review and usage.
        │     ├─ Functions — `M66_Init()`, `M66_SendSMS()`, `M66_SendAtCmd()`.
        │     ├─ SMS — Sending messages to specified numbers.
        │     └─ Debugging — Common issues and fixes.
        │
        ├── [aKaReZa 116 - Quectel M66 - PART B]
        │     ├─ Response — Parsing AT command replies.
        │     ├─ Startup — `M66_startUp()` function design.
        │     ├─ Timeout — Managing delays and avoiding lockups.
        │     ├─ Errors — GSM-specific issues and fixes.
        │     └─ Reliability — Clean code for stable communication.
        │
        └── [aKaReZa 117 - Quectel M66 - PART C]
              ├─ SMS Rx — Detecting incoming messages via +CMTI.
              ├─ Parsing — Using `sscanf()` and scansets for data extraction.
              ├─ Function — `M66_CheckSMS()` implementation.
              ├─ Execution — Testing on RCS-AVR board.
              └─ Control — Relay activation based on SMS content.
```

<table style="border-collapse: collapse;">
  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/MzOPimZQYaU">aKaReZa 6 – AVR, Introduction</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Introduction to AVR microcontrollers, their families, ATMEGA328, and necessary hardware connections.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/MzOPimZQYaU">
        <img src="https://img.youtube.com/vi/MzOPimZQYaU/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 6 – AVR, Introduction Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/fGsOeDv1-gI">aKaReZa 12 – AVR, fuseBits</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Introduction to fuse bits in AVR microcontrollers, including Extended, High, and Low fuse bits, as well as lock bits, clock synchronization issues, and how to use online fuse bit calculators.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/fGsOeDv1-gI">
        <img src="https://img.youtube.com/vi/fGsOeDv1-gI/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 12 – AVR, fuseBits Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/_0uQSh0qBBo">aKaReZa 20 – AVR, GPIO - Part A</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Introduction to AVR GPIO control registers, pin configuration, simulation in Proteus, coding in PlatformIO and VsCode, timing issues, and code readability improvements using macros.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/_0uQSh0qBBo">
        <img src="https://img.youtube.com/vi/_0uQSh0qBBo/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 20 – AVR, GPIO - Part A Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/Kn6aQvtuO08">aKaReZa 22 – AVR, Programming</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn how to program AVR microcontrollers using various programmers and methods, including TNM2000+, USBasp, MKII, ZIF socket, OnBoard, and directly via VsCode's Upload button.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/Kn6aQvtuO08">
        <img src="https://img.youtube.com/vi/Kn6aQvtuO08/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 22 – AVR, Programming Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/xa3nRQx28Nw">aKaReZa 23 – AVR, GPIO - PART B</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn about AVR GPIO control registers, configuring pins as input, reading pin status, simulating AVR in Proteus, coding in PlatformIO and VsCode, using internal pull-up, and using if statements for input.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/xa3nRQx28Nw">
        <img src="https://img.youtube.com/vi/xa3nRQx28Nw/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 23 – AVR, GPIO - PART B Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/HGlJtcpjZ-E">aKaReZa 44 – AVR, 7Segment - Part A</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn how to set up a common anode 7-segment display with an AVR microcontroller on a breadboard, and then multiplex a four-digit 7-segment display using a custom shield to improve code readability.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/HGlJtcpjZ-E">
        <img src="https://img.youtube.com/vi/HGlJtcpjZ-E/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 44 – AVR, 7Segment - Part A Thumbnail"/>
      </a>
    </td>
  </tr>
  
  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/_pwxBJ06aMk">aKaReZa 47 – AVR, 7Segment - Part B</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Continuation of setting up 7-segment displays, building a counter, adding button functionality, displaying digits, optimizing code, and adding macros.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/_pwxBJ06aMk">
        <img src="https://img.youtube.com/vi/_pwxBJ06aMk/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 47 – AVR, 7Segment - Part B Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/5OG6KQWCLCA">aKaReZa 53 – AVR, 7Segment - Part C</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Continuation of setting up 7-segment displays, addressing three software issues: modular code writing, display refresh during button press, and one-second counting.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/5OG6KQWCLCA">
        <img src="https://img.youtube.com/vi/5OG6KQWCLCA/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 53 – AVR, 7Segment - Part C Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/eGV7mYVpWX4">aKaReZa 55 – AVR, External Interrupts</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn how to set up and use external interrupts on AVR microcontrollers, specifically focusing on the ATMEGA328. Understand interrupt flags and when to manually clear them.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/eGV7mYVpWX4">
        <img src="https://img.youtube.com/vi/eGV7mYVpWX4/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 55 – AVR, External Interrupts Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/hNRjyU02NoM">aKaReZa 57 – AVR, Alphanumeric LCD</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn how to set up an alphanumeric LCD with AVR microcontrollers, use library functions, display decimal numbers, create custom and Persian characters, and adjust the display contrast.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/hNRjyU02NoM">
        <img src="https://img.youtube.com/vi/hNRjyU02NoM/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 57 – AVR, Alphanumeric LCD Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/J1_z-FngLbA">aKaReZa 59 – AVR, Timer, Accurate Time - Mode 1</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn about Timer-Counter 0 in AVR microcontrollers, Normal and CTC modes, Overflow and Compare Match interrupts, precise timing, function execution time calculation, and 7-segment display integration.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/J1_z-FngLbA">
        <img src="https://img.youtube.com/vi/J1_z-FngLbA/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 59 – AVR, Timer, Accurate Time, Mode 1 Thumbnail"/>
      </a>
    </td>
  </tr>
  
  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/TJEfbymLoTs">aKaReZa 66 – AVR, Communication, USART - Part A</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn about USART features and specifications in the ATMega328 microcontroller, including baud rate calculation, registers, single character and string transmission, escape sequences, data frames, and differences in simulation and practical testing.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/TJEfbymLoTs">
        <img src="https://img.youtube.com/vi/TJEfbymLoTs/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 66 – AVR, Communication, USART - Part A Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/HWJqS9NjYIA">aKaReZa 67 – AVR, Communication, USART - Part B</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Continuation of USART communication, discussing escape sequences, byte reception, baud rate errors and solutions, double speed mode, data reception with interrupts, circular buffer, USART flags, debugging, and data frames.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/HWJqS9NjYIA">
        <img src="https://img.youtube.com/vi/HWJqS9NjYIA/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 67 – AVR, Communication, USART - Part B Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/SJJGwX5tNis">aKaReZa 77 – AVR, Analog - ADC</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn about the features of the Analog-to-Digital Converter (ADC) in AVR microcontrollers, including block diagrams, control and data registers, voltage measurement, multi-channel measurement, analog temperature sensor connection, internal temperature sensor usage, and noise canceler capabilities.
      </p>
    </td>
    <td width="360" valign="top" style="padding: 0;">
      <a href="https://youtu.be/SJJGwX5tNis">
        <img src="https://img.youtube.com/vi/SJJGwX5tNis/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 77 – AVR, Analog - ADC Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/1GhoYor4q6M">aKaReZa 105 – AVR, Timer, PWM - Mode 2</a>
      </h3>
      <p style="margin: 8px 0 0;">
        A deep dive into PWM modes in AVR microcontrollers, covering Fast and Phase Correct PWM, dual slope advantages, Dead Time, and real-world applications in motors, converters, and LED drivers. Ideal for mastering PWM in practical engineering contexts.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/1GhoYor4q6M">
        <img src="https://img.youtube.com/vi/1GhoYor4q6M/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 105 – AVR, Timer, PWM - Mode 2 Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/_RbzWU-bHc4">aKaReZa 108 – AVR, Servo Motor</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn how to control a servo motor using AVR timers by generating precise 50Hz PWM signals. This video covers Timer0 basics, advanced Timer1 modes (Mode 14 and Mode 10), and high-precision angle control—perfect for mastering servo control in embedded systems.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/_RbzWU-bHc4">
        <img src="https://img.youtube.com/vi/_RbzWU-bHc4/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 108 – AVR, Servo Motor Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/4s5p9rwfgto">aKaReZa 112 – AVR, Communication, USART - Part C</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Master USART frame detection in AVR microcontrollers using Idle Detection instead of CR/LF terminators. This video introduces Timer 2 configuration, timing analysis, and real-world testing—essential for reliable serial communication.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/4s5p9rwfgto">
        <img src="https://img.youtube.com/vi/4s5p9rwfgto/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 112 – AVR, Communication, USART - Part C Thumbnail"/>
      </a>
    </td>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/1ndIc5NdtNg">aKaReZa 113 – AVR, Quectel M66 - PART A</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn how to program the Quectel M66 GSM module using AVR microcontrollers. This video walks through project setup, AT command handling, and writing practical functions like <code>M66_Init()</code> and <code>M66_SendSMS()</code> for real-world GSM communication.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/1ndIc5NdtNg">
        <img src="https://img.youtube.com/vi/1ndIc5NdtNg/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 113 – AVR, Quectel M66 - PART A Thumbnail"/>
      </a>
    </td>
  </tr>  

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/KScXumQBRfo">aKaReZa 114 – AVR, I2C - PART A</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn I2C communication in AVR microcontrollers from the ground up. This video covers protocol fundamentals, register-level analysis, atomic operations, and implementation of key functions like <code>i2c_Init()</code>, <code>i2c_Start()</code>, <code>i2c_Write()</code>, and more—perfect for building reliable sensor and module interfaces.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/KScXumQBRfo">
        <img src="https://img.youtube.com/vi/KScXumQBRfo/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 114 – AVR, I2C - PART A Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/Sg0c39_p_TM">aKaReZa 116 – AVR, Quectel M66 - PART B</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Strengthen GSM communication with AVR by handling AT command responses, building a reliable startup routine, and implementing timeout management. This video ensures stable interaction with the Quectel M66 module—ideal for debugging and professionalizing real-world GSM projects.</a>.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/Sg0c39_p_TM">
        <img src="https://img.youtube.com/vi/Sg0c39_p_TM/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 116 – AVR, Quectel M66 - PART B Thumbnail"/>
      </a>
    </td>
  </tr>
 
  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/M1o16PILNKs">aKaReZa 117 – AVR, Quectel M66 - PART C</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Take your GSM integration to the next level by learning how to receive and parse SMS messages using AVR and the Quectel M66 module. This video walks through project setup, <code>+CMTI</code> message detection, <code>sscanf()</code> parsing, and relay control based on SMS content. It’s a practical blueprint for building SMS-driven control systems.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/M1o16PILNKs">
        <img src="https://img.youtube.com/vi/M1o16PILNKs/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 117 – AVR, Quectel M66 - PART C Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/Jw2_HUWW0NI">aKaReZa 122 – AVR, Timer, Millis - Mode 7</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn how to implement the <code>millis()</code> concept in AVR microcontrollers for non-blocking delays and multitasking without an RTOS. This video walks through project setup, task scheduling, timer configuration, and internal logic analysis—perfect for building responsive embedded systems with clean timing control.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/Jw2_HUWW0NI">
        <img src="https://img.youtube.com/vi/Jw2_HUWW0NI/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 122 – AVR, Timer, Millis - Mode 7 Thumbnail"/>
      </a>
    </td>
  </tr>


  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/dNaj5lWs40A">aKaReZa 127 – AVR, Alphanumeric LCD - PART B</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Continue mastering character LCDs with AVR in this second phase tutorial. You’ll learn the <strong>structure and operation of alphanumeric LCDs</strong>, set up a new project, and configure the display using <code>alcd_init()</code>. The episode also covers <strong>sending data and commands with alcd_write()</strong>, working in <strong>8-bit mode</strong>, and displaying output with <code>alcd_putc()</code> and <code>alcd_puts()</code>. Finally, you’ll practice <strong>positioning characters using alcd_gotoxy()</strong>—a complete hands-on guide for building reliable LCD interfaces in embedded projects.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/dNaj5lWs40A">
        <img src="https://img.youtube.com/vi/dNaj5lWs40A/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 127 – AVR, Alphanumeric LCD - PART B Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/1IQTeyUsbYI">aKaReZa 129 – AVR, Alphanumeric LCD - PART C</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Unlock advanced features of AVR character LCDs in this third tutorial. You’ll learn how to <strong>clear the display with alcd_clear</strong>, manage the <strong>cursor using alcd_cursor</strong>, and control visibility with <strong>alcd_display</strong>. The episode also covers <strong>backlight management via alcd_backlight</strong>, creating <strong>custom characters with alcd_customChar</strong>, and configuring the LCD in <strong>4-bit mode</strong> to save pins and optimize resources. It wraps up with <strong>final optimization tips</strong> for efficient LCD usage—perfect for building polished and professional embedded interfaces.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/1IQTeyUsbYI">
        <img src="https://img.youtube.com/vi/1IQTeyUsbYI/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 129 – AVR, Alphanumeric LCD - PART C Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr style="background-color: #f9f9f9;">
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/62rkm0YjG4s">aKaReZa 131 – AVR, EEPROM - PART A</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Explore the <strong>internal EEPROM of AVR microcontrollers</strong>—a powerful feature for permanent data storage across resets and power cycles. This tutorial provides a <strong>bit-by-bit review of EEAR, EEDR, and EECR registers</strong>, and guides you through writing functions like <code>uint8_write()</code>, <code>uint16_write()</code>, and <code>uint32_write()</code>. Along the way, you’ll learn about <strong>Endianness in data storage</strong> and the advantages of <strong>Type Punning</strong>, making this episode essential for building projects with user settings, calibration data, counters, or simple data loggers.
      </p>
    </td>
    <td width="360" valign="center">
      <a href="https://youtu.be/62rkm0YjG4s">
        <img src="https://img.youtube.com/vi/62rkm0YjG4s/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 131 – AVR, EEPROM - PART A Thumbnail"/>
      </a>
    </td>
  </tr>


  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/d8H9xRyfYPI">aKaReZa 134 – AVR, EEPROM – PART B</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Continue exploring advanced <strong>EEPROM data storage</strong> on AVR. This episode covers writing floats and arrays, reading multiple data types, implementing smart <strong>Update</strong> functions to reduce wear, analyzing execution time, and adding full‑memory formatting. A solid foundation for building efficient and reliable data‑persistence systems in embedded projects.
      </p>
    </td>
    <td width="360" valign="center">
      <a href="https://youtu.be/d8H9xRyfYPI">
        <img src="https://img.youtube.com/vi/d8H9xRyfYPI/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 134 – AVR, EEPROM – PART B Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/RCxOpa2WsnI">aKaReZa 136 – AVR, Timer, Counter – Mode 3</a>
      </h3>
      <p style="margin: 8px 0 0;">
        Learn how to measure <strong>frequency</strong> using AVR timers in <strong>Counter Mode (Mode 3)</strong>. This episode explains the fundamentals of frequency measurement, full configuration of <strong>Timer1</strong> and <strong>Timer2</strong>, creating a practical measurement project, analyzing accuracy and limitations, and exploring techniques to reach the maximum measurable frequency range. A key lesson for mastering signal measurement in embedded systems.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/RCxOpa2WsnI">
        <img src="https://img.youtube.com/vi/RCxOpa2WsnI/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 136 – AVR, Timer, Counter – Mode 3 Thumbnail"/>
      </a>
    </td>
  </tr>

  <tr>
    <td valign="top" style="padding: 0 10px;">
      <h3 style="margin: 0;">
        <a href="https://youtu.be/gUYuW_KnFkM">aKaReZa 138 – AVR, Timer, Capture – Mode 4</a>
      </h3>
      <p style="margin: 8px 0 0;">
        A deep, practical introduction to <strong>Capture mode</strong> in AVR timers — the most accurate method for measuring period, frequency, and duty cycle. This episode covers prescaler selection, Capture unit behavior, interrupt handling, error analysis, long‑interval measurement techniques, and the use of the <strong>Input Noise Canceller</strong> for clean, reliable signal processing in high‑speed or noisy environments.
      </p>
    </td>
    <td width="360" valign="top">
      <a href="https://youtu.be/gUYuW_KnFkM">
        <img src="https://img.youtube.com/vi/gUYuW_KnFkM/maxresdefault.jpg"
             width="360"
             alt="aKaReZa 138 – AVR, Timer, Capture – Mode 4 Thumbnail"/>
      </a>
    </td>
  </tr>

</table>

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
