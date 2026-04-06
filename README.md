# esp32-iot-foundation
After a long period of time, I have decided to commit to c and cpp and make my way to embedded systems.
Some of the concepts covered are:
## memory_demo
GPIO: General Purpose input/output -> its responsiable for communication on the board via digital signals 3.3v as high(1) and 0v as low(0).
Inputs can be from Modules or sensors while as outputs can be shown on LID, motters and speacker. 
## Makefile document
The makefile is an important script that automates the process of bulding software(compiling and linking) or excuting repititive shell commands. some signs used and meaning
The:
- @ - used to hide the statements being executed from the terminal
- $ - used to point at the declared constants that can be changed
- $@ - points to the current target being built
- $^ - Refers to the entire list of files the target depens on
- $< - Refers only to the first file in the dependency list

| Concept             | Status |
| ------------------- | ------ |
| C fundamentals      | ✅      |
| Memory model        | ✅      |
| Compilation         | ✅      |
| Architecture layers | ✅      |
| Interrupts          | ✅      |
| State machines      | ✅      |
| Timers              | ✅      |
| Events              | ✅      |

## Starting with ESP IDF
- install esp-idf and chech compatibility. 
- We will start by using predefined drivers from idf or pre-sourced on github.
### hello
used to test the idf installetion by runing: -idf   
| create-project project_name
| build
| flash
| monitor
### motionSensor
Understanding PIR pins, and incoporates -idf drivers 
| gpio.h -controll the input/output pins
| freertos.h -supports chip mult-tasking

PIR reads the sensor data via pin. high and low purses are optained to conclude the results true or false.
pull_down was used to keep the value at 0(false) in case of no motion.
PIR does not require any initial handshake with the chip as no timing is required.
### tempHumiditySensor
Understanding time delazs, multdata processing, and data conversion -obtained data bits from the chip and then converted into decimal redable.
Understanding processor/sensor hand shake. Duration based data transimision(Pull_up used; - a down 50us signal shows the start of a bit,a short 28us up signal (0); a long 70us up signal (1) )
introducing new idf drivers and outsorcing from github:-   |dht.h (outsourced from github)
### lightHumiditySensor
Understanding I2C driver, adressing, and command sending   | i2c.h -using i2c bus-    |SDA 21
                                                                                      |SLC 22
                                                                                      |ADDR GND,VCC
### multiSensor
- System Architecture

┌──────────────┐
│   ESP32      │
│              │
│  GPIO 14 ← PIR
│  GPIO 4  ← DHT22
│  I2C     ← BH1750
│              │
│  UART → Output
└──────────────┘
- Combined all the above projects in on file with comments to explain and visualize easly;
