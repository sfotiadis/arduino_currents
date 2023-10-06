# Arduino Current Monitoring Project (WIP)

## Overview

This Arduino Current Monitoring Project is a practical and educational project designed to monitor and log the power consumption of an Arduino Nano RP2040 Connect. By collecting and analyzing this data, you can make informed decisions about selecting the right solar panel and battery setup for extended operation in remote or off-grid locations.

## Table of Contents

- [Arduino Code](#arduino-code)
- [Kubernetes Infrastructure](#kubernetes-infrastructure)
- [Getting Started](#getting-started)
- [Contributing](#contributing)
- [License](#license)
- [Disclaimer](#disclaimer)

## Arduino Code

The Arduino code for measuring current using the INA169 sensor is located in the [`arduino`](arduino) directory. You can upload this code to your Arduino Nano RP2040 Connect to start measuring and sending the data to the MQTT broker.

### Prerequisites

Before you begin, make sure you have the following:

- [Arduino IDE](https://www.arduino.cc/en/software)
- Libraries: 
    - WiFiNINA, 
    - ArduinoMqttClient 

You can install these libraries using the Arduino IDE.

### Configuration

To get your Arduino up and running, update the following variables in the Arduino code (`current_publisher.ino`) with your specific configuration:

- `SECRET_SSID` and `SECRET_PASS`: Your WiFi network name and password.
- `const char broker[]`: MQTT broker address.
- `const int port`: MQTT broker port.
- `const char topic[]`: MQTT topic where the data will be published.

## Kubernetes Infrastructure

The [`kubernetes`](kubernetes) directory contains the Kubernetes configuration files for deploying the essential components of this project:

- InfluxDB: A time-series database for storing measurement data.
- Eclipse Mosquitto: An MQTT broker for handling communication between devices.
- Telegraf: An agent for collecting, processing, and forwarding data.

### Prerequisites

Before deploying the Kubernetes infrastructure, ensure that you have the following:

- A Kubernetes cluster (e.g., Minikube)
- The `kubectl` command-line tool

### Getting Started
To get started with the Arduino Current Monitoring Project, follow these steps:

Upload the Arduino code to your Arduino Nano RP2040 Connect.

Deploy the Kubernetes infrastructure using the provided configuration files.

Access the InfluxDB web UI to view and analyze the collected data.

### Contributing
Contributions to this project are welcome! If you have any suggestions, improvements, or bug fixes, please open an issue or submit a pull request.

### License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

### Disclaimer
This project is provided for educational and experimental purposes only. The code and infrastructure may not be suitable for production use. The project author assumes no liability for the functionality or reliability of the code or its components. Use at your own risk.
