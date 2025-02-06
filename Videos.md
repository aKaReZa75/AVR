# Videos
In this document, you will find brief descriptions for each video.  
These summaries provide an overview of the topics covered in each video, allowing you to quickly and easily understand the content presented.  
The purpose of these short descriptions is to give a clear and concise understanding of each video's subject matter.

> [!IMPORTANT]
In this section, only AVR-related videos are available. These videos are generally divided into two main categories:
>
1. **General Concepts and Basics:**  
   This part includes videos that provide foundational knowledge and general principles of microcontrollers. Videos in this category typically begin with the word *`Microcontroller`*.
>
   - **Example:** In the video "*aKaReZa 45 - Microcontroller, Interrupts*", the overall functionality and applications of interrupts across different types of microcontrollers are explained. This helps build a solid understanding of the interrupt mechanism before diving into specific implementations.  
>    
2. **Microcontroller-Specific Implementations:**  
    "This part focuses on detailed setups, configurations, and practical demonstrations tailored to a specific microcontroller.  
    Videos in this category are identified by keywords related to specific microcontroller families such as *`AVR`*, *`STM32`*, *`STM8`*, *`ESP8266`*, *`ESP32`*, and *`PIC`*.
>
   - **Example for AVR:** In the video "*aKaReZa 55 - AVR, External Interrupts*", the setup and detailed explanation of external interrupts in `AVR` microcontrollers are provided, along with practical tests and real-world examples.  

> [!NOTE]
1. It is strongly advised to first watch the general concept videos (identified by the keyword *`Microcontroller`*) to build a solid theoretical foundation. 
2. Once you have a good understanding, proceed to the microcontroller-specific videos (identified by their respective keywords such as *`AVR`*, *`STM32`*, etc.) to see how these concepts are applied in practice.  

> [!TIP]  
- The prerequisites for each video are clearly mentioned at the beginning of the respective video.  
- For a complete and organized list of all fundamental topics along with their detailed explanations, visit: [Microcontroller Fundamental Videos](https://github.com/aKaReZa75/Microcontroller/Videos.md)


```plaintext
📁 AVR Microcontrollers
│
├── Fundamental
│   ├── [aKaReZa 6 - AVR, Introduction]
│   ├── [aKaReZa 22 - AVR, Programming]
│   └── [aKaReZa 12 - AVR, fuseBits]
│
├── GPIO (General Purpose Input Output)
│   ├── [aKaReZa 20 - AVR, GPIO - Part A]
│   └── [aKaReZa 23 - AVR, GPIO - Part B]
│
├── External Interrupts
│   └── [aKaReZa 55 - AVR, External Interrupts]
|
├── Display Interfaces
│   ├── 7-Segment Displays
│   │   ├── [aKaReZa 44 - AVR, 7Segment - Part A]
│   │   ├── [aKaReZa 47 - AVR, 7Segment - Part B]
│   │   └── [aKaReZa 53 - AVR, 7Segment - Part C]
│   └── Alphanumeric LCD
│       └── [aKaReZa 57 - AVR, Alphanumeric LCD]
|
├── Timers and Counters
│   └── Timer0
│       └── [aKaReZa 59 - AVR, Timer, Accurate Time, Mode 1]
│
├── Analog Peripherals
│   └── ADC (Analog-to-Digital Converter)
│       └── [aKaReZa 77 - AVR, Analog - ADC]
│
└──  Communication Protocols
    └── USART (Universal Synchronous/Asynchronous Receiver/Transmitter)
        ├── [aKaReZa 66 - AVR, Communication, USART - Part A]
        └── [aKaReZa 67 - AVR, Communication, USART - Part B]
```


- [aKaReZa 6 - AVR, Introduction](https://youtu.be/MzOPimZQYaU)  
    ---  
    Introduction to AVR microcontrollers, their families, ATMEGA328, and necessary hardware connections.

- [aKaReZa 12 - AVR, fuseBits](https://youtu.be/fGsOeDv1-gI)  
    ---  
    Introduction to fuse bits in AVR microcontrollers, including Extended, High, and Low fuse bits, as well as lock bits, clock synchronization issues, and how to use online fuse bit calculators.

- [aKaReZa 20 - AVR, GPIO - Part A](https://youtu.be/_0uQSh0qBBo)  
    ---  
    Introduction to AVR GPIO control registers, pin configuration, simulation in Proteus, coding in PaltformIO and VsCode, timing issues, and code readability improvements using macros.

- [aKaReZa 22 - AVR, Programming](https://youtu.be/Kn6aQvtuO08)  
    ---  
    Learn how to program AVR microcontrollers using various programmers and methods, including TNM2000+, USBasp, MKII, ZIF socket, OnBoard, and directly via VsCode's Upload button.

- [aKaReZa 23 - AVR, GPIO - PART B](https://youtu.be/xa3nRQx28Nw)  
    ---  
    Learn about AVR GPIO control registers, configuring pins as input, reading pin status, simulating AVR in Proteus, coding in PaltformIO and VsCode, using internal pull-up, and using if statements for input.

- [aKaReZa 44 - AVR, 7Segment - Part A](https://youtu.be/HGlJtcpjZ-E)  
    ---  
    Learn how to set up a common anode 7-segment display with an AVR microcontroller on a breadboard, and then multiplex a four-digit 7-segment display using a custom shield to improve code readability.

- [aKaReZa 47 - AVR, 7Segment - Part B](https://youtu.be/_pwxBJ06aMk)  
    ---  
    Continuation of setting up 7-segment displays, building a counter, adding button functionality, displaying digits, optimizing code, and adding macros.

- [aKaReZa 53 - AVR, 7Segment - Part C](https://youtu.be/5OG6KQWCLCA)  
    ---  
    Continuation of setting up 7-segment displays, addressing three software issues: modular code writing, display refresh during button press, and one-second counting.

- [aKaReZa 55 - AVR, External Interrupts](https://youtu.be/eGV7mYVpWX4)  
    ---  
    Learn how to set up and use external interrupts on AVR microcontrollers, specifically focusing on the ATMEGA328. Understand interrupt flags and when to manually clear them.
  
- [aKaReZa 57 - AVR, Alphanumeric LCD](https://youtu.be/hNRjyU02NoM)  
    ---  
    Learn how to set up an alphanumeric LCD with AVR microcontrollers, use library functions, display decimal numbers, create custom and Persian characters, and adjust the display contrast.

- [aKaReZa 59 - AVR, Timer, Accurate Time, Mode 1](https://youtu.be/J1_z-FngLbA)  
    ---  
    Learn about Timer-Counter 0 in AVR microcontrollers, Normal and CTC modes, Overflow and Compare Match interrupts, precise timing, function execution time calculation, and 7-segment display integration.

- [aKaReZa 66 - AVR, Communication, USART - Part A](https://youtu.be/TJEfbymLoTs)  
    ---  
    Learn about USART features and specifications in the ATMega328 microcontroller, including baud rate calculation, registers, single character and string transmission, escape sequences, data frames, and differences in simulation and practical testing.

- [aKaReZa 67 - AVR, Communication, USART - Part B](https://youtu.be/HWJqS9NjYIA)  
    ---  
    Continuation of USART communication, discussing escape sequences, byte reception, baud rate errors and solutions, double speed mode, data reception with interrupts, circular buffer, USART flags, debugging, and data frames.

- [aKaReZa 77 - AVR, Analog - ADC](https://youtu.be/SJJGwX5tNis)  
    ---  
    Learn about the features of the Analog-to-Digital Converter (ADC) in AVR microcontrollers, including block diagrams, control and data registers, voltage measurement, multi-channel measurement, analog temperature sensor connection, internal temperature sensor usage, and noise canceler capabilities.


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