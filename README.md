## Rasberry-Pi-3-install-Jenkins
1. Install System to SD Card with Rspberry Pi Imager(Raspberry Pi OS Lite or Ubuntu Server)<br>
**Tips: also setting up the ssh connection and wifi ssid/password via Rspberry Pi Imager.**<br>

2. Clone sh file and excute<br>

## Troubleshooting
While Jenkins get error message with **_jenkins.service: start operation timed out. Terminating._**<br>
Use command systemctl edit jenkins and add [Service] TimeoutStartSec=180

