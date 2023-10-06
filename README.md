# Arduino Current Monitoring Project (WIP)

## Overview

Hello there! 👋 I'm Spiro, and I'm on a journey to learn more about IoT monitoring with my trusty Arduino Nano RP2040 Connect. You see, I've always been fascinated by the world of Internet of Things (IoT), and I thought it would be a fantastic opportunity to dive into it with a fun project.

I wanted to do more than just tinker with my Arduino; I wanted to monitor and understand its power consumption over time. This is crucial for me because I'm planning to power it with solar panels and batteries, and I need to make informed decisions about the setup. So, I embarked on this adventure to create a solution that would not only help me monitor my Arduino's power usage but also store and visualize the data in a user-friendly way.

In my quest to accomplish this, I decided to leverage some powerful tools like InfluxDB, Telegraf and MQTT. To make things even more exciting, I'm running it all within a Minikube Kubernetes cluster. This setup gives me the flexibility to experiment, learn, and fine-tune the project in a controlled environment.

But hey, I must emphasize that this project is primarily for learning purposes. While I'm doing my best to make it work smoothly, I can't guarantee that everything will be flawless. It's a journey of exploration, and I'm sharing it with the community in the hope that it might inspire others or spark collaborative improvements.

So, join me on this adventure as I explore the world of IoT monitoring, data storage, and experimentation. Feel free to contribute, offer suggestions, or just follow along to see how it all unfolds.

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
