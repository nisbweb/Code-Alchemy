/*
    Create a system that can translate a text message into Morse code using an LED. 
    The LED should blink to represent the Morse code: short blink for a dot ('.') and a longer blink for a dash ('-').

    Example 
    Input
    "SOS"

    Output
    Blink Pattern:  ... --- ...

*/

/*
solution:

the standard morse rules were followed, 
the unit of measurement is= 500ms
dot=1 unit
dash=3 unit
delay b/w dots and dashes =1 unit
delay b/w diffrent letters=3 units
delay b/w diffrent words=7 units

!!the below code can read letters, numbers and spaces.. each of which is represented by its respective morse code;


*/

//might improve the code in future, but i am done for now... 


const int led=13;

void setup(){

    pinMode(led, OUTPUT);

}

void loop(){
char message[]="ANMOL";

for (int i = 0; message[i] != '\0' ; i++)
{
    toMorse(message[i]);
 	delay(1500);
}



}

const char *morse[]={
 ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
  "..-", "...-", ".--", "-..-", "-.--", "--..", // A-Z
  
  "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." // 0-9
};

void toMorse(char A){
 
  const char *Ac;
   if(isdigit(A)){  Ac=morse[A-'0'+26] ;}
   if(isalpha(A)){  Ac=morse[A-'A'] ;}
   if(A==' '){delay(3500);return;}




     while (*Ac) {
      if (*Ac == '.') {
        Dot();
      } else if (*Ac == '-') {
        Dash();
      }
      Ac++;
		delay(500);
    }
    delay(1500);
}

void Dot(){
    digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
}

void Dash() {
  digitalWrite(led, HIGH);
  delay(1500);
  digitalWrite(led, LOW); // Space between symbols
}