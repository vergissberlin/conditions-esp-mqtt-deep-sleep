==========
conditions
==========

.. image:: https://readthedocs.org/projects/conditions-esp-mqtt-deep-sleep/badge/?version=latest
    :target: https://conditions-esp-mqtt-deep-sleep.readthedocs.io/en/latest/?badge=latest
    :alt: Documentation Status

MQTT sensor project for `DHT sensor <https://amzn.to/2zySODF>`_ to messure temperature an humanitiy, 
send it to a MQTT broker (Adafruit in this example) and go to deep sleep. 

.. image:: documentation/conditions-door.jpg
    :alt: 3D printed case
    :width: 112
.. image:: documentation/conditions-case.jpg
    :alt: 3D printed case
    :width: 112
.. image:: documentation/conditions-open.jpg
    :alt: 3D printed case
    :width: 112



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
- 3D `printed case <https://www.tinkercad.com/things/1bR34X0fXlm-esp01-dht11-and-18650-battery-lipo-case>`_

Development
===========

FTDI
----

Driver: https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver

ESP01
-----


- Tools ➤ Board ➤ Generic ESP8266
- Tools ➤ Upload Speed ➤ 115200
- Tools ➤ CPU Frequency ➤ 80 
- Tools ➤ Crystal Frequency ➤ 26MHz
- Tools ➤ Flash Size ➤ 1M (no SPIFFS)
- Tools ➤ Flash Mode ➤ DIO
- Tools ➤ Flash Frequency ➤ 40 MHz
- Tools ➤ Reset Mode ➤ DIO
- Tools ➤ Debug Port ➤ Disabled
- Tools ➤ Debug Level ➤ None
- Tools ➤ Builtin Led ➤ 1
- Tools ➤ IwIP Varrianr ➤ v2 Lower Memory
- Tools ➤ Erease Flash: All Flash Contents
- Tools ➤ Programmer ➤ USBasp

https://cdn.instructables.com/FMB/MPX4/JCUUFKU6/FMBMPX4JCUUFKU6.LARGE.jpg?auto=webp&width=273