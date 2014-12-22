Teensyterpreter
===============

A small C-based script for the Teensy to be compiled on the Arduino IDE (for maximum support). The primary function of this script is to open a reverse TCP shell between the victim and attacker in as little time as possible, using as little memory as possible, and bypassing all file-scanning antivirus countermeasures and all tested heuristic antivirus countermeasures.

A detailed, typical attack scenario is as follows:

1. Open up a Metasploit Console on a home computer/laptop.
2. Use the multi/handler module.
3. Set LHOST to 0.0.0.0, LPORT to any port, and PAYLOAD to windows/meterpreter/reverse_tcp.
4. Optionally, set ExitOnSession to false and AutoRunScript to your custom script.
5. Forward the machine's local IP address and listening port on your router.
6. When ready, enter the "exploit" command (or "exploit -j" to run it in the background).
7. Plug in the Teensy to any computer—even computers not on the local network.
8. Wait a few seconds until the tiny command prompt box disappears.
9. Unplug the Teensy from the computer.
10. You are now connected via reverse TCP shell to that computer.

NOTE: You will need to change line 151 in the script to reflect your own information, i.e. your public IP address and any port of your choice (the port you choose MUST be the same one that you configure Metasploit to listen on and the same one you forward on your router).

NOTE 2: By altering usb_desc.h, usb_inst.cpp, and usb_keyboard.h, you can force the Teensy to act as ONLY a Keyboard HID device instead of a Keyboard, Mouse, and Joystick, thus speeding up the attacking time on untested computers. Since I was using a Teensy 3.1 on a 64-bit version of Windows 7, these files were found in [ArduinoInstallationFolder]\hardware\teensy\cores\teensy3. I have provided my own changes for reference, but I don't recommend using those—my changes overwrite the default Keyboard+Mouse+Joystick configuration.
