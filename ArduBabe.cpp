#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <algorithm>

using namespace std;

int menu(string cpuspd, string chip, string path, string lang, string name, string port, string baud);

int flash(string cpuspd, string chip, string path, string lang, string name, string port, string baud){
  string ans;
  system("clear");
  std::cout << "\nspd: " + cpuspd + " chip: " + chip + " path: " + path + " language: " + lang + " port: " + port + " baudrate: " + baud + "\nCorrect? (y / n)\n";
  std::cin >> ans;
  if (ans == "y"){
     if(path == "" || chip == "" || cpuspd == "" || lang == "" || name == "" || port == "" || baud == ""){
      system("clear");
      std::cout << "Empty field!\n";
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else if (lang == "C") {
      system(("avr-gcc -Os -DF_CPU=" + cpuspd + " -mmcu=" + chip + " -c -o " + name + ".o " + path).c_str());
      system(("avr-gcc -o " + name + ".bin " + name + ".o").c_str());
      system(("avr-objcopy -O ihex -R .eeprom " + name + ".bin " + name + ".hex").c_str());
      transform(chip.begin(), chip.end(), chip.begin(), ::toupper); 
      system(("sudo avrdude -F -V -c arduino -p " + chip + " -P /dev/" + port + " -b " + baud + " -U flash:w:" + name + ".hex").c_str());
    }
    else if (lang == "C++") {
      system(("avr-g++ -Os -DF_CPU=" + cpuspd + " -mmcu=" + chip + " -c -o " + name + ".o " + path).c_str());
      system(("avr-g++ -o " + name + ".bin " + name + ".o").c_str());
      system(("avr-objcopy -O ihex -R .eeprom " + name + ".bin " + name + ".hex").c_str());
      transform(chip.begin(), chip.end(), chip.begin(), ::toupper); 
      system(("sudo avrdude -F -V -c arduino -p " + chip + " -P /dev/" + port + " -b " + baud + " -U flash:w:" + name + ".hex").c_str());
    }
  }
  else if (ans == "n"){
    system("clear");
    menu(cpuspd, chip, path, lang, name, port, baud);
  }
  else {
    system("clear");
    std::cout << "Wrong option!";
    flash(cpuspd, chip, path, lang, name, port, baud);
  }
  return(0);
}

int menu(string cpuspd, string chip, string path, string lang, string name, string port, string baud){
  string answer; 
  //show options
  std::cout << "1) Set CPU speed\n2) Set MCU chip\n3) Path\n4) Programming language\n5) Program name\n6) Port\n7) Baudrate\n8) Flash!\n9) Exit\n";
  
  //wait for asnwer
  std::cin >> answer;

  //prcoess the answers
  if (answer == "1") {
    std::cout << "\na) 16 MHz\nb) 8 MHz\nc) 20 MHz\nd) 12 MHz\ne) 4 MHz\n";
    std::cin >> cpuspd;
    if(cpuspd == "a"){
      cpuspd = "16000000UL";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    if(cpuspd == "b"){
      cpuspd = "8000000UL";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    if(cpuspd == "c"){
      cpuspd = "20000000UL";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    if(cpuspd == "d"){
      cpuspd = "12000000UL";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    if(cpuspd == "e"){
      cpuspd = "4000000UL";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
  
    else {
      system("clear");
      std::cout << "Wrong option!\n";
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
  }
  else if (answer == "2") {
    std::cout << "\na) ATmega32u4 (Leonardo, Yún Rev2, Micro) \nb) ATmega328P (UNO R3 SMD, UNO R3, UNO Mini Limited Edition) \nc) ATmega328 (Nano) \nd) ATmega4809 (UNO WiFi Rev2, Nano Every) \ne) ATmega2560 (Mega 2560 Rev3) \nf) ATtiny85\ng) ATmega1280\nh) ATtiny2313\ni) ATmega2561\nj) ATmega1284\nk) ATtiny13\n";
    std::cin >> chip;
    if(chip == "a"){
      chip = "atmega32u4";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else if(chip == "b"){
      chip = "atmega328p";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else if(chip == "c"){
      chip = "atmega328";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else if(chip == "d"){
      chip = "atmega4809";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else if(chip == "e"){
      chip = "atmega2560";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else if(chip == "f"){
      chip = "attiny85";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else if(chip == "g"){
      chip = "atmega1280";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else if(chip == "h"){
      chip = "attiny2313";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else if(chip == "i"){
      chip = "atmega2561";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else if(chip == "j"){
      chip = "atmega1284";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else if(chip == "k"){
      chip = "attiny13";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
 
    else {
      system("clear");
      std::cout << "Wrong option!\n";
      menu(cpuspd, chip, path, lang, name, port, baud);
    }

  }
  else if (answer == "8") {
    flash(cpuspd, chip, path, lang, name, port, baud);
  }
  else if (answer == "3") {
    std::cout << "\nYour code path:\n";
    std::cin >> path;
    if(path != ""){
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
  }
  else if (answer == "4"){
    std::cout << "\nCodes writteni in language:\na) C\nb) C++\n";
    std::cin >> lang;
    if(lang == "a"){
      lang = "C";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else if(lang == "b"){
      lang = "C++";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else{
      system("clear");
      std::cout << "Wrong option!";
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
  }
  else if(answer == "5") {
    std::cout << "\nYour output file name:\n";
    std::cin >> name;
    system("clear");
    menu(cpuspd, chip, path, lang, name, port, baud);
  }
  else if(answer == "6") {
    std::cout << "\nPort you arduino is connected to:\n";
    system("ls /dev/ | grep USB");
    std::cin >> port;
    system("clear");
    menu(cpuspd, chip, path, lang, name, port, baud);
  }
  else if(answer == "7") {
    std::cout << "\nBaudrate:\na) 9600\nb) 115200\n";
    std::cin >> baud;
    if(baud == "a"){
      baud = "9600";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else if(baud == "b"){
      baud = "115200";
      system("clear");
      menu(cpuspd, chip, path, lang, name, port, baud);
    }
    else{
      system("clear");
      std::cout << "Wrong option!";
      menu(cpuspd, chip, path, lang, name, port, baud);
    } 
  } 
  else if (answer == "9") {
    exit(1);
  }
  else{
    system("clear");
    std::cout << "wrong option\n";
    menu(cpuspd, chip, path, lang, name, port, baud);
  }
  return 0;
}


int main () {
  system("clear");
  std::cout << "\033[1;96mWelcome to ArduBabe!\n\n";
  menu("", "", "", "", "", "", "");
  return 0;
}
