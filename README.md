# Rasberry-Pi-3-install-Jenkins
1. Install System to SD Card with Rspberry Pi Imager(Raspberry Pi OS Lite or Ubuntu Server)<br>
**Tips: also setting up the ssh connection and wifi ssid/password via Rspberry Pi Imager.**<br>
Rspberry Pi Imager https://www.raspberrypi.com/software/ (software download)

3. excute rb3_install_jenkins.sh<br>

# Troubleshooting
1. While Jenkins get error message with **_jenkins.service: start operation timed out. Terminating._**
![image](https://github.com/abandsdx/Rasberry-Pi-3-install-Jenkins/blob/main/error.png)
2. Use command *systemctl edit jenkins* and add [Service] TimeoutStartSec=600
![image](https://github.com/abandsdx/Rasberry-Pi-3-install-Jenkins/blob/main/modify.png)


