# smartGarden ("A Smart Environmental Monitoring & Security System")
## smartGarden (ESP32)
### Description
This project was designed to be installed or implemented on a closed system( Green house. ).
To simulate real life this project uses data collected on different research documents point on tomato farming.
We use this system to imprement or modify the nature conditions required for tomatoe grow on a larger scale; This project also combines different attributes menstioned below to provide the optimal conditions as we a security.


This project will be able to measure:-
- Temperature
- Humidity
- Light intensity
- Motion

### Project structer
smartGarden/
│
├── main/
│   ├── main.c
│   ├── motion.c
│   ├── dht_sensor.c
│   ├── light_sensor.c
│   ├── system_logic.c
│
├── include/
│   ├── motion.h
│   ├── dht_sensor.h
│   ├── light_sensor.h
│   ├── system_logic.h
│   ├── sensor_data.h
│
├── README.md