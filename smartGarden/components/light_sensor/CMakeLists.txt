idf_component_register(SRCS "light_sensor.c"
                    INCLUDE_DIRS "include" 
                    REQUIRES "sensor_data" 
                    PRIV_REQUIRES driver)
