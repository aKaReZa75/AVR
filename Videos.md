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
│
├── Fundamental
│   ├── [aKaReZa 6 - AVR, Introduction]
│   ├── [aKaReZa 22 - AVR, Programming]
│   └── [aKaReZa 12 - AVR, fuseBits]
│
├── GPIO (General Purpose Input Output)
│   ├── [aKaReZa 20 - AVR, GPIO - Part A]
│   ├── [aKaReZa 23 - AVR, GPIO - Part B]
│   └── External Interrupts
│       └──[aKaReZa 55 - AVR, External Interrupts]
│
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
│       ├── [aKaReZa 59 - AVR, Timer, Accurate Time - Mode 1]
│       └── [aKaReZa 105 - AVR, Timer, PWM - Mode 2]
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
