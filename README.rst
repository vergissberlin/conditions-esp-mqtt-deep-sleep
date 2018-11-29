===============
conditions
===============

.. image:: https://readthedocs.org/projects/esp8266-mqtt-deep-sleep/badge/?version=latest
    :target: https://esp8266-mqtt-deep-sleep.readthedocs.io/en/latest/?badge=latest
    :alt: Documentation Status

MQTT sensor project for `DHT sensor <https://amzn.to/2zySODF>`_ to messure temperature an humanitiy, 
send it to a MQTT broker (Adafruit in this example) and go to deep sleep. 

Features
========

- It uses deep sleep mode to save energy.
- It messures the temperature and send the result as MQTT message to the broker.
- It messures the humidity and send the result as MQTT message to the broker.
- It uses the internal LED for status messages

Hardware
========

- ESP8266 ESP12F
    - Flash Size:   32 Mbit
    - Flash Mode:   DIO
    - Flash Speed:  40 MHz
- DHT22
