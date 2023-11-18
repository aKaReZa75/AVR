# AVR
[![](https://img.shields.io/badge/Microcontroller-YouTube-orange)](https://www.youtube.com/playlist?list=PLDdvbHxhit_X3Aj13pAqfhCX3Dn080p6r)
[![](https://img.shields.io/badge/AVR-YouTube-brown)](https://www.youtube.com/playlist?list=PLDdvbHxhit_Wx2JMPtw0zOPWzKg26iM7O)

MicroController Fundamental
-------------
[![](https://img.shields.io/badge/uC-Introduction-orange)](https://youtu.be/Clsv0KyD4RM)
[![](https://img.shields.io/badge/uC-Architecture-orange)](https://youtu.be/vrKq5oZxuT0)
[![](https://img.shields.io/badge/uC-Requirement-orange)](https://youtu.be/GfvmpeDFT_o)
[![](https://img.shields.io/badge/uC-Basics-orange)](https://youtu.be/XhBq_QvCxYE)
[![](https://img.shields.io/badge/uC-Oscillators-orange)](https://youtu.be/WPOZ_3E0mC8)
[![](https://img.shields.io/badge/uC-GPIO_Part_A-orange)](https://youtu.be/_i_MXrbRf7o)
[![](https://img.shields.io/badge/uC-GPIO_Part_B-orange)](https://youtu.be/QGhRRsIICUU)
[![](https://img.shields.io/badge/uC-Assigning_value_to_a_register-orange)](https://youtu.be/kBbZi6WWGiM)

AVR MicroController
-------------
[![](https://img.shields.io/badge/AVR-Introduction-brown)](https://youtu.be/MzOPimZQYaU)
[![](https://img.shields.io/badge/AVR-fuseBits-brown)](https://youtu.be/fGsOeDv1-gI)
[![](https://img.shields.io/badge/AVR-GPIO_Part_A-brown)](https://youtu.be/_0uQSh0qBBo)
[![](https://img.shields.io/badge/AVR-Programing-brown)](https://youtu.be/Kn6aQvtuO08)

Contact Us
-------------
[![](https://img.shields.io/badge/E-Mail-yellow)](mailto:aKaReZa75@gmail.com)
[![](https://img.shields.io/badge/You-Tube-red)](https://www.youtube.com/@aKaReZa75)
[![](https://img.shields.io/badge/Linked-in-blue)](https://www.linkedin.com/in/akareza75)

# Macros
```
#define setBit(Reg, Bit) (Reg |= (1<<Bit))
#define clearBit(Reg, Bit) (Reg &= ~(1<<Bit))
#define toggleBit(Reg, Bit) (Reg ^= 1<<Bit)
#define checkBit(Reg, Bit) ((Reg>>Bit) & 0x01)
#define changeBit(Reg, Bit, Value) (Value == 1 ? setBit(Reg, Bit) : clearBit(Reg, Bit))
```

# PlatformIO Project Configuration for USBasp
```
[env:ATmega328P]
platform = atmelavr
board = ATmega328P
framework = arduino
board_build.f_cpu = 8000000UL
upload_protocol = custom
upload_port = usb 
upload_flags = 
   -C
     $PROJECT_PACKAGES_DIR/tool-avrdude/avrdude.conf 
   -p
     $BOARD_MCU
   -P 
     $UPLOAD_PORT
   -c
     usbasp
   -u 
     -Uefuse:w:0xFF:m ; Extended fuseBit
     -Uhfuse:w:0xD7:m ; High fuseBit
     -Ulfuse:w:0xE2:m ; Low fuseBit
     -Ulock:w:0xFF:m  ; lockBit
upload_command = avrdude $UPLOAD_FLAGS -U flash:w:$SOURCE:i
```

# PlatformIO Project Configuration for MKII
```
[env:ATmega328P]
platform = atmelavr
board = ATmega328P
framework = arduino
board_build.f_cpu = 8000000UL
upload_protocol = custom
upload_port = usb 
upload_flags = 
   -C
     $PROJECT_PACKAGES_DIR/tool-avrdude/avrdude.conf 
   -p
     $BOARD_MCU
   -P 
     $UPLOAD_PORT
   -c
     avrispmkII
   -u 
     -Uefuse:w:0xFF:m ; Extended fuseBit
     -Uhfuse:w:0xD7:m ; High fuseBit
     -Ulfuse:w:0xE2:m ; Low fuseBit
     -Ulock:w:0xFF:m  ; lockBit
upload_command = avrdude $UPLOAD_FLAGS -U flash:w:$SOURCE:i
```
