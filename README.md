Teensyterpreter
===============

A small C-based script for the Teensy to be compiled on the Arduino IDE (for maximum support). The primary function of this script is to open a reverse TCP shell between the victim and attacker in as little time as possible, using as little memory as possible, and bypassing all file-scanning antivirus countermeasures and all tested heuristic antivirus countermeasures.

NOTE: You will need to change line 228 in the script to reflect your own information, i.e. your public IP address and any port of your choice (the port you choose MUST be the same one that you configure Metasploit to listen on and the same one you forward on your router).


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
