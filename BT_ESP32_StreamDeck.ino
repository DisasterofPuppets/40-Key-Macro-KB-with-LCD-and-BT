/*******************************************************************
Disaster of Puppets
YouTube: Http://disasterofpuppets.com
Twitch: Https://twitch.tv/disasterofpuppets

//I needed to use (DOIT ESP32 DEVKIT V1) as the board I had, yours may differ
Don't forget to press the flash button when uploading the sketch

Based on Tv-K's https://github.com/T-vK/ESP32-BLE-Keyboard

To DO
Doesn't seem to work unless you remove and re-add the Bluetooth connection each time.

 *******************************************************************/

#include <BleKeyboard.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

bool muted = false;
bool runonce = true;
bool blur = false;

BleKeyboard bleKeyboard("BT Stream Deck", "JoMamma", 100);

int keypress = 100; // delay between keypad press and release
const byte ROWS = 6;
const byte COLS = 8;

char hexaKeys[ROWS][COLS] = 
{

    {'0', '1', '2', '3', '4', '5', '6', '7'}, 
    {'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'},
    {'G', 'H', '~', '~', '~', '~', 'I', 'J'},
    {'K', 'L', '~', '~', '~', '~', 'M', 'N'},
    {'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'},
    {'W', 'X', 'Y', 'Z', '!', '@', '#', '$'},
};

byte rowPins[ROWS] = {13, 14, 27, 26, 25, 33}; //13,14,27,26,25,33 
byte colPins[COLS] = {15,16,17,18,19,23,32,4}; // PINS 15,RX2,TX2,18,19,23,32,4

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

LiquidCrystal_I2C lcd(0x27,16,2); 


// put your setup code here, to run once:
void setup() {
  

  Serial.begin(115200);
  bleKeyboard.begin();
  lcd.init(); // initialize the lcd
  lcd.init();
  lcd.backlight();

}

void loop() {


  if(bleKeyboard.isConnected()) {

if (runonce){
// You can make a custom message here, or even duplicate one of the buttons so it is default
    Serial.println("Connected to Bluetooth");
    delay(keypress);
    lcd.setCursor(0,0);
    lcd.print("BT Connected");
    lcd.setCursor(0,1);
    lcd.print("                ");
    runonce = false;
}

  /* 
   //saving here for example of multiple keys at once
    Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);
    delay(100);
    bleKeyboard.releaseAll();
    */


//*********** Keypad Matrix *************

char customKey = customKeypad.getKey();
 
if (customKey){
     switch (customKey){

// ROW 1-------------------------------------------        


// Live   
    
  case '0':
    Serial.println("0");
    Serial.println("Live");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F1);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("PC / Live");
    break;

// Blur

  case '1':
    if (!blur) {
    Serial.println("1");
    Serial.println("Blur On");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F2);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Blurred         ");
    blur = true;
    }
    else if (blur) {
    Serial.println("1");
    Serial.println("Blur Off");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F2);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("                ");
    blur = false;
    }
    break;
          
//

  // Craft Desk FullScreen Cam

  case '2':
    Serial.println("2");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F3);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("                ");
    break;

// Spare

  case '3':
    Serial.println("3");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F4);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("                ");
    break;

// Idle

  case '4':
    Serial.println("4");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F5);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("IDLE            ");
    break;

//Disclaimer

  case '5':
    Serial.println("5");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F6);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                "); 
    lcd.setCursor(0,0);
    lcd.print("Disclaimer");
    break;

// Zoom

  case '6':
    Serial.println("6");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F7);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Zoom");
    break;

// BRB
  case '7':
    Serial.println("7");        
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F8);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Brb");
    break;

// ROW 2 ---------------------------------

// Fullscreen PC Webcam

  case '8':
    Serial.println("8");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F9);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("F/S Webcam");
    break;

//Spare

  case '9':
    Serial.println("9");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F10);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Spare");
    break;

// Dodgy Paintbrush Time
  case 'A':
    Serial.println("A");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F11);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Dodgy PB");
    break;

//Spare
  case 'B':
    Serial.println("B");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_F12);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Spare");
    break;

//Red
  case 'C':
    Serial.println("C");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(48);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Red Door");
    break;

//Green
  case 'D':
    Serial.println("D");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(49);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Green Door");
    break;

//Blue
  case 'E':
    Serial.println("E");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(50);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Blue Door");
    break;

//DoorPrize
  case 'F':
    Serial.println("F");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(51);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Door Prize");
    break;

// ROW 3 ---------------------------------

// Spare

  case 'G':
    Serial.println("G");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(52);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Spare");
    break;

// Spare

  case 'H':
    Serial.println("H");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(53);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Spare");
    break;
    
// Spare

  case 'I':
    Serial.println("I");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(54);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Spare");
    break;

// Spare

  case 'J':
    Serial.println("J");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(55);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Spare");
    break;
          
    
// ROW 4 ---------------------------------


//Spare

  case 'K':
    Serial.println("K");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(56);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Spare");
    break;

// Spare
  
  case 'L':
    Serial.println("L");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(57);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Spare");
    break;

//Spare

  case '~':
    Serial.println("~ NULL ~");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(58);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Spare");
    break;

// Spare

  case 'M':
    Serial.println("M");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(59);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Spare");
    break;

// Spare

  case 'N':
    Serial.println("N");
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F1);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Spare");
    break;        

// ROW 5 ---------------------------------

// Stamp

  case 'O':
    Serial.println("O");
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F2);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Stamp");
    break;        

// BS

  case 'P':
    Serial.println("P");
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F3);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Bullshit");
    break;        

// KISS

  case 'Q':
    Serial.println("Q");
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F4);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Kiss");
    break;        

//PUN

  case 'R':
    Serial.println("R");
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F5);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Pun");
    break;        

// Who are these people?

  case 'S':
    Serial.println("S");
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F6);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Who are these people");
    break;        

// I disagree

  case 'T':
    Serial.println("T");
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F7);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("I disagree");
    break;        

// Sexytimes

  case 'U':
    Serial.println("U");
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F8);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("He does Sex");
    break;        

// Why is / isn't it working gif?

  case 'V':
    Serial.println("V");
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F9);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Not Working");
    break;          

// ROW 6 ------------------------------

// GG

  case 'W': 
    Serial.println("W");
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F10);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Good Game");
    break;        

// McScuse me          

  case 'X':
    Serial.println("X");
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F11);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("McScuse Me Bitch");
    break;        

// Cheese it

  case 'Y':
    Serial.println("Y");
    bleKeyboard.press(KEY_LEFT_SHIFT);
    bleKeyboard.press(KEY_F12);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Cheese It");
    break;        

// Tech support

  case 'Z':
    Serial.println("Z");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(48);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Tech Support");
    break;        

// Sthap it

  case '!':
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(49);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Sthap it");
    break; 

// Phrasing

  case '@':
    Serial.println("@");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(50);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Phrasing");
    break; 

// Kruiz Control Reset

  case '#':
    Serial.println("#");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(51);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Kruiz Control Resetting");
    break;   

// Mute

  case '$':
    Serial.println("$");
  if (!muted) {
    Serial.println("Mute");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(52);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("Muted**         ");
    muted = true;
    }
    else if (muted) {
    Serial.println("$");
    Serial.println("Mute Off");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(52);
    delay(keypress);
    bleKeyboard.releaseAll();
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print("                ");
    muted = false;
    }
    break;
 


            
     }
  }

//*********** END Keypad Matrix *************
  
  }
}
