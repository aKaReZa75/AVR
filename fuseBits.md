# ATmega328 Fuse Bits Guide
This document provides a thorough explanation of the **fuse bits** in the **ATmega328** microcontroller, including their purpose, how to configure them, and how they affect your system's behavior.    
Understanding and setting the fuse bits correctly is critical for configuring features such as clock sources, bootloader settings, and protection mechanisms for your microcontroller.

# What Are Fuse Bits?
Fuse bits are special configuration bits in microcontrollers that control various hardware settings. In the **ATmega328** (and similar AVR microcontrollers), these fuse bits define the operating parameters such as:

- **Clock source and prescalers**
- **Reset behavior**
- **Bootloader settings**
- **Watchdog timer configuration**
- **Memory protection (Lock bits)**

Incorrectly setting fuse bits can result in undesirable behavior, such as failure to start the microcontroller, a locked device (unable to reprogram), or incorrect clock timing. Therefore, it's essential to configure them carefully according to your project requirements.

# Types of Fuse Bits in ATmega328
The ATmega328 has three main categories of fuse bits:

1. **Low Fuse Bits**
2. **High Fuse Bits**
3. **Extended Fuse Bits**
4. **Lock Bits**

Each of these categories serves specific purposes and can affect different aspects of the microcontroller's behavior.

# 1. **Low Fuse Bits**
The low fuse bits control settings such as the clock source, startup time, and watchdog timer.

| **Fuse**              | **Description**                                                                                          | **Default Value** |
|-----------------------|----------------------------------------------------------------------------------------------------------|-------------------|
| `CKSEL[3:0]`          | Selects the clock source.                                                                                 | `0x02` (internal 8 MHz RC oscillator) |
| `SUT[1:0]`            | Selects the start-up time of the clock.                                                                   | `0x01` (6 CK + 65 ms) |
| `CKDIV8`              | Disables clock division by 8. This setting determines if the system clock is divided by 8.               | `0` (disabled)     |
| `WDTON`               | Enables or disables the watchdog timer on reset.                                                         | `0` (disabled)     |
| `BODLEVEL[2:0]`       | Defines the Brown-Out Detector (BOD) level. It controls the voltage threshold at which the microcontroller will reset. | `0x03` (4.3V)      |

**Key Notes:**
- The clock source can be set to **external crystal**, **internal oscillator**, or **external clock**, depending on the CKSEL configuration.
- If you want to use an external crystal oscillator, make sure to configure **CKSEL** accordingly.
- The **Brown-Out Detector** can be used to reset the microcontroller if the voltage drops below a specified threshold.

### **CKSEL[3:0] - Clock Source Selection**

| **Value** | **Clock Source**                           | **Description**                                                        |
|-----------|--------------------------------------------|------------------------------------------------------------------------|
| `0x00`    | External Crystal/Resonator, 6-8 MHz       | Selects an external crystal or resonator with a frequency between 6 and 8 MHz. |
| `0x01`    | External Crystal/Resonator, 8-16 MHz      | Selects an external crystal or resonator with a frequency between 8 and 16 MHz. |
| `0x02`    | Internal 8 MHz RC Oscillator              | Default setting; uses the internal 8 MHz RC oscillator.                |
| `0x03`    | External Clock Input                      | Selects an external clock signal for the system clock.                 |
| `0x04`    | External Crystal, 16-18 MHz               | Selects an external crystal with a frequency between 16 and 18 MHz.    |
| `0x05`    | External Crystal, 18-20 MHz               | Selects an external crystal with a frequency between 18 and 20 MHz.    |
| `0x06`    | External Oscillator, 20 MHz+              | Selects an external oscillator with a frequency greater than 20 MHz.   |
> [!CAUTION]
If the clock source is set to an external crystal or external clock input (such as 0x00, 0x01, 0x03, 0x04, 0x05, or 0x06), and the external source is not connected or not functioning, the microcontroller will fail to operate properly.   
Always ensure that the selected clock source is available and properly connected to avoid system failure or malfunction.

### **SUT[1:0] - Start-Up Time Selection**

| **Value** | **Start-Up Time**                  | **Description**                                                        |
|-----------|-------------------------------------|------------------------------------------------------------------------|
| `0x00`    | 4 CK + 0 ms                         | Quick start-up time with 4 clock cycles and no delay (fastest option). |
| `0x01`    | 6 CK + 65 ms                        | Default setting; 6 clock cycles plus a 65 ms delay for a reliable startup. |
| `0x02`    | 6 CK + 4.1 ms                       | 6 clock cycles plus a shorter 4.1 ms delay, useful for quicker start-up when timing is critical. |
| `0x03`    | 8 CK + 64 ms                        | 8 clock cycles plus a 64 ms delay, for a more stable and reliable startup, but slower. |

### **CKDIV8 - Clock Division by 8**

| **Value** | **Description**                                  |
|-----------|--------------------------------------------------|
| `0`       | Disabled (clock is not divided by 8, default).   |
| `1`       | Enabled (system clock is divided by 8, reducing speed and power consumption). |

> [!CAUTION]
Ensure that the CKDIV8 bit is set to 0 for proper operation.   
If the clock is divided by 8 (i.e., CKDIV8 is set to 1), the system clock will be slower, which could lead to incorrect timing or instability in time-sensitive applications.   
For most projects, the clock should not be divided, so it is important to keep this bit disabled (set to 0) for optimal performance.

### **WDTON - Watchdog Timer Enable**

| **Value** | **Description**                                  |
|-----------|--------------------------------------------------|
| `0`       | Disabled (watchdog timer is turned off, default).|
| `1`       | Enabled (watchdog timer is turned on, will reset the system if it becomes unresponsive). |

### **BODLEVEL[2:0] - Brown-Out Detection Level**

| **Value** | **Brown-Out Reset Voltage** | **Description**                                                        |
|-----------|------------------------------|------------------------------------------------------------------------|
| `0x00`    | 4.3V                         | Resets the microcontroller if voltage drops below 4.3V.                |
| `0x01`    | 2.7V                         | Resets the microcontroller if voltage drops below 2.7V.                |
| `0x02`    | 4.0V                         | Resets the microcontroller if voltage drops below 4.0V.                |
| `0x03`    | 4.3V                         | Default setting; same as 0x00 for 4.3V threshold.                       |
| `0x04`    | 2.8V                         | Resets the microcontroller if voltage drops below 2.8V.                |
| `0x05`    | 4.5V                         | Resets the microcontroller if voltage drops below 4.5V.                |
| `0x06`    | 4.8V                         | Resets the microcontroller if voltage drops below 4.8V.                |
| `0x07`    | 5.0V                         | Resets the microcontroller if voltage drops below 5.0V.                |

> [!CAUTION]
If your microcontroller is powered by 3.3V, it is crucial that you set the BODLEVEL fuse to either 2.8V (0x04) or 2.7V (0x01).   
Choosing a higher threshold (such as 4.0V or 4.3V) may cause the system to reset unnecessarily when the supply voltage drops even slightly, affecting the stability of your application.

# 2. **High Fuse Bits**
The **High Fuse Bits** control important settings for the **ATmega328**, including bootloader size, EEPROM preservation, watchdog timer behavior, and the configuration of the SPI interface during reset.

| **Fuse**              | **Description**                                                                                          | **Default Value** | **Available Options**                                                                                   |
|-----------------------|----------------------------------------------------------------------------------------------------------|-------------------|---------------------------------------------------------------------------------------------------------|
| `BOOTRST`             | Determines whether the reset vector points to the application code or the bootloader.                   | `1` (reset to bootloader) | - `0`: Reset to the application code (no bootloader).<br> - `1`: Reset to the bootloader (default). |
| `BOOTSZ[2:0]`         | Defines the size of the bootloader section. The size of the bootloader affects the amount of flash memory available for your application code. | `0x03` (4096 bytes) | - `0x00`: 256 bytes<br> - `0x01`: 512 bytes<br> - `0x02`: 1024 bytes<br> - `0x03`: 4096 bytes (default) |
| `EESAVE`              | Determines whether EEPROM contents are preserved during a chip erase. If set to `1`, the EEPROM data is retained when a chip erase is performed. | `1` (EEPROM is preserved) | - `0`: EEPROM contents are erased during chip erase.<br> - `1`: EEPROM contents are preserved during chip erase (default). |
| `WDTON`               | Enables or disables the watchdog timer. If enabled, the watchdog timer will reset the microcontroller if the program becomes unresponsive. | `0` (disabled)     | - `0`: Disabled (default).<br> - `1`: Enabled (watchdog timer will reset the device). |
| `SPIEN`               | Determines if the SPI interface is enabled during reset. This allows the microcontroller to use SPI for communication with external devices like sensors or peripherals. | `1` (enabled)      | - `0`: SPI is disabled during reset.<br> - `1`: SPI is enabled during reset (default). |

> [!NOTE]
If you plan on using a bootloader, set **BOOTRST** to 0 and choose the appropriate **BOOTSZ** setting based on the bootloader size.

> [!CAUTION]
If you accidentally disable the SPIEN bit (set it to 0), the microcontroller will no longer be able to communicate using the SPI interface. This will prevent programming the microcontroller via standard methods (like using a USBasp or other ISP programmers) since the SPI interface is required for programming.   
Always ensure that SPIEN is set to 1 unless you are using an alternative programming method that does not rely on SPI.

# 3. **Extended Fuse Bits**
The **Extended Fuse Bits** provide additional configuration options for controlling features such as the **external oscillator startup time** and the **output of the clock signal** on the **CLKO pin**. These bits help optimize the microcontroller's behavior depending on your project's specific needs.

| **Fuse**              | **Description**                                                                                          | **Default Value** | **Available Options**                                                                                   |
|-----------------------|----------------------------------------------------------------------------------------------------------|-------------------|---------------------------------------------------------------------------------------------------------|
| `CKOUT`               | Enables or disables the output of the clock signal on the **CLKO pin**. This allows you to use the system clock as an external clock for other components. | `0` (disabled)    | - `0`: Clock output is disabled (default).<br> - `1`: Clock output is enabled. |
| `SUT[3:0]`            | Defines the startup time for the external crystal oscillator. This setting ensures the oscillator is stable before use. | `0x00` (default)  | - `0x00`: Start-up time of 0 ms (fastest).<br> - `0x01`: 64 ms.<br> - `0x02`: 128 ms.<br> - `0x03`: 256 ms.<br> - `0x04`: 512 ms.<br> - `0x05`: 1024 ms.<br> - `0x06`: 2048 ms.<br> - `0x07`: 4096 ms. |

# 4. **Lock Bits**
Lock bits protect the flash memory from being read or written, which is useful for security purposes.

| **Fuse**              | **Description**                                                                                          | **Default Value** |
|-----------------------|----------------------------------------------------------------------------------------------------------|-------------------|
| `LOCKBIT`             | Lock bit to prevent reading or writing the flash memory.                                                  | `0xFF` (unlocked) |

**Key Notes:**
- Once the **lock bit** is set, it can prevent reading or writing to the flash memory, making it difficult to recover or modify the program.

# Important Considerations
- **Fuses are one-time programmable**: Be cautious when setting fuse bits. Once set, certain fuse bits (like the lock bits) cannot be changed easily.
- **Backup your fuses**: Before programming the fuses, it is a good practice to back them up so you can restore them if needed.
- **Use appropriate programmers**: Not all programmers support fuse bit manipulation. Ensure you are using a programmer that can handle fuse bit operations.

# **Online Fuse Bit Calculator**
For an easier and faster way to calculate the correct fuse bits for your microcontroller, you can use the **[Engbedded Fuse Calculator](https://www.engbedded.com/fusecalc/)**. This online tool simplifies the process of setting the fuse bits by providing a graphical interface where you can select different options for your microcontroller and immediately see the corresponding fuse bit values.

### **Features of the Engbedded Fuse Calculator**:
- **Easy-to-use interface**: Select clock sources, startup times, fuse bit settings, and more.
- **Instant results**: The tool generates the fuse values based on your selections and shows them in hexadecimal format.
- **Compatibility**: It supports many AVR microcontrollers, including the ATmega328.
- **Visual representation**: You can see the impact of each setting and get a clear view of the fuse bit configuration.

### **How to Use the Fuse Calculator**:
1. **Select your microcontroller**: Choose the ATmega328 or any other AVR microcontroller you're using.
2. **Configure your settings**: Select options for clock source, brown-out detection, watchdog timer, and more.
3. **Copy the fuse values**: The calculator will display the fuse bit values you need, which you can then apply to your microcontroller using tools like **avrdude** or **PlatformIO**.

For more detailed and accurate fuse bit configurations, the **Engbedded Fuse Calculator** is an excellent resource to streamline the process.


# **Default Fuse Bit Settings for Arduino Uno (ATmega328)**:

| **Fuse**               | **Description**                                                           | **Value**  |
|------------------------|---------------------------------------------------------------------------|-----------|
| `Low Fuse (LFUSE)`      | **Clock source**: Internal 8 MHz RC oscillator, **Start-up time**: 6 CK + 65 ms | `0x62`    |
| `High Fuse (HFUSE)`     | **Bootloader size**: 4096 bytes, **SPI interface**: Enabled during reset | `0xD9`    |
| `Extended Fuse (EFUSE)` | **External oscillator start-up time**: 0 ms, **Clock output**: Disabled   | `0xFF`    |

### **Explanation of Arduino Uno Fuse Settings:**

1. **Low Fuse (`0x62`)**:  
   - **Clock source**: The microcontroller uses the **internal 8 MHz RC oscillator**.
   - **Start-up time**: The clock stabilizes in **6 clock cycles** plus **65 ms**, which is a reasonable delay for reliable startup.
   - **CKDIV8**: Clock division by 8 is disabled, ensuring full clock speed.

2. **High Fuse (`0xD9`)**:
   - **Bootloader**: The Arduino Uno uses a **4 KB bootloader** (4096 bytes), which allows you to upload sketches via the serial port.
   - **SPI Interface**: The **SPI interface** is enabled during reset, allowing external programming devices to communicate with the ATmega328 during boot.

3. **Extended Fuse (`0xFF`)**:
   - **Clock output**: The **clock output** on the CLKO pin is disabled, meaning the clock is not fed back to external devices.
   - **External Oscillator**: The **start-up time for the external crystal oscillator** is set to **0 ms** by default, as the Arduino Uno typically uses the internal oscillator.

### **Important Notes for Arduino Uno Users**:
- The default fuse settings for the Arduino Uno are already optimized for use with the **Arduino IDE** and the **bootloader**. 
- **If you modify these fuse bits**, make sure you understand their implications. For instance, disabling the **bootloader** or changing the **clock source** could affect your ability to upload code via the standard Arduino programming method.
- Use the **Engbedded Fuse Calculator** or a similar tool to verify fuse settings when making custom configurations.

# Conclusion
Fuse bits are a powerful feature of the **ATmega328** microcontroller that allow you to configure various settings, such as clock sources, reset behavior, and memory protection. Properly setting the fuse bits ensures the correct operation of the microcontroller, and understanding their function is crucial for optimizing your project.

By following this guide, you should now be able to configure and modify the fuse bits of the ATmega328 microcontroller according to your project needs.

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