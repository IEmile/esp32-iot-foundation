# esp32-iot-foundation
After a long period of time, I have decided to commit to c and cpp and make my way to embedded systems.
Some of the concepts covered are:
# memory_demo
GPIO: General Purpose input/output -> its responsiable for communication on the board via digital signals 3.3v as high(1) and 0v as low(0).
Inputs can be from Modules or sensors while as outputs can be shown on LID, motters and speacker. 
# Makefile document
The makefile is an important script that automates the process of bulding software(compiling and linking) or excuting repititive shell commands. some signs used and meaning
The:
@ - used to hide the statements being executed from the terminal
$ - used to point at the declared constants that can be changed
$@ - points to the current target being built
$^ - Refers to the entire list of files the target depens on
$< - Refers only to the first file in the dependency list

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

# Staring with ESP IDF
install esp-idf and chech compatibility. 


