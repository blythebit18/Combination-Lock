const int button1 = A5, button2 = A4, button3 = A3, button4 = A2, button5 = A1;  //Applying variable for each button

const int LED[] = {9, 10, 11, 12, 13};  //Applying array variable for the LED 

const int True = 4;  //Applying variable for the LED if the password is correct
const int False = 5; //Applying variable for the LED if the password is incorrect                                                                 


int answer[] = {2, 2, 1,1,1};  //Applying array variable for the correct answer

int enter[5];   //Create a empty array variable for the storage to store the 5 digit password


void setup() {
Serial.begin(9600);  //Enable the serial monitor     
pinMode(button1, INPUT_PULLUP); //Enable the pull up feature for button number 1
pinMode(button2, INPUT_PULLUP); //Enable the pull up feature for button number 2
pinMode(button3, INPUT_PULLUP); //Enable the pull up feature for button number 3
pinMode(button4, INPUT_PULLUP); //Enable the pull up feature for button number 4
pinMode(button5, INPUT_PULLUP); //Enable the pull up feature for button number 5

pinMode(False, OUTPUT);  //Configure the False LED as OUTPUT
pinMode(True, OUTPUT);   //Configure the True LED as OUTPUT

for(int i = 0; i<= 5; i++){  //Configure the LED[] array as OUTPUT
  pinMode(LED[i], OUTPUT);  //
  }
digitalWrite(LED[4], LOW);  //Turn off the LED on pin number 13
}



void loop() {

if(digitalRead(button1) == LOW){  //if statement : When the button number 2 being pressed
  Serial.println("The button 1 is being pressed"); //Only for debugging
  checkEntered1(1); //Send 1 digit value to checkEntered1 function
  delay(250); //delay if the users press the button twice at the same time
  Serial.println(""); 

  }else if(digitalRead(button2) == LOW){   
    Serial.println("The button 2 is being pressed");  
    checkEntered1(2);  //Send 2 digit value to checkEntered2 function
    delay(250); //delay if the users press the button twice at the same time
    Serial.println("");
    
    }else if(digitalRead(button3) == LOW){
      Serial.println("The button 3 is being pressed");
      checkEntered1(3); //Send 3 digit value to checkEntered3 function
      delay(250);  //delay if the users press the button twice at the same time
      Serial.println("");
      
      }else if(digitalRead(button4) == LOW){
        Serial.println("The button 4 is being pressed");
        checkEntered1(4); //Send 4 digit value to checkEntered4 function
        delay(250); //delay if the users press the button twice at the same time
        Serial.println("");
        
        }else if(digitalRead(button5) == LOW){
          Serial.println("The button 5 is being pressed");
          checkEntered1(5); //Send 5 digit value to checkEntered5 function
          delay(250);  //delay if the users press the button twice at the same time
          Serial.println("");
          }
}



////////////////////////////////////////////////////////////
void checkEntered1(int button){  //checkEntered1 function will receive number from the loop function
  Serial.println("check enter 1");  //Debugging purposed
  digitalWrite(LED[button-1], HIGH);  //turn on the LED according to number
  if(enter[0] != 0){ // if the storage number 0 not empty send to checkEntered2
    Serial.println("Storage 1 full");  //Debugging purposed
    Serial.println("Data is send to checkEntered2");  //Debugging purposed
    checkEntered2(button);  //Forward to checkEnter2  
    }else{    //if the storage number 0 empty, fill the storage with incoming number
      Serial.println("Data 1 is fill");  //Debugging purpose
      Serial.print("1: ");  //Debugging purpose
      Serial.println(button);  //Debugging purpose
      enter[0] = button;  //storage 0 equal to the incoming number
      }
}
//////////////////////////////////////////////////////////
void checkEntered2(int button){  //checkEntered2 function will receive number from the checkEntered1 function
 Serial.println("");
 Serial.println("check enter 2");
 digitalWrite(LED[button-1], HIGH);
 if(enter[1] != 0){ //if the storage number 1 not empty send to checkEntered3
  Serial.println("Storage 2 full");
  Serial.println("Data is send to checkEntered3");
  checkEntered3(button); //forward to checkEntered3
  }else{  //if the storage number 1 empty, fill the storage with incoming number
 Serial.println("Data 2 is fill");  
 Serial.print("2: ");
 Serial.println(button);
 enter[1] = button;  //storage 1 equal to incoming number
}
}
//////////////////////////////////////////////////////////
void checkEntered3(int button){ //checkEntered3 function will receive number from the checkEntered2 function
  Serial.println("");
  Serial.println("check enter3"); 
  digitalWrite(LED[button-1],HIGH);
  if(enter[2] != 0){  //if the storage number 2 not empty send to checkEntered4
    Serial.println("Storage 3 full");
    Serial.println("Data is send to checkEntered4");
    checkEntered4(button);  //forward to checkEntered4
    }else{  //if the storage number 2 empty, fill the storage with incoming number
    Serial.println("Data 3 is fill");
    Serial.print("3: ");
    Serial.println(button); 
    enter[2] = button;  //storage 2 equal to incoming number
  }
}
////////////////////////////////////////////////////////////
void checkEntered4(int button){  //checkEntered4 function will receive number from the checkEntered3 function
Serial.println("");
Serial.println("check enter 4");
digitalWrite(LED[button-1], HIGH);
if(enter[3] != 0){  //if the storage number 3 not empty send to checkEntered5
  Serial.println("Storage 4 full");
  Serial.println("Data is send to checkEntered5");
  checkEntered5(button);  //forward to checkEntered5
  }else{  //if the storage number 3 empty, fill the storage with incoming number
    Serial.println("Data 4 is fill");
    Serial.print("4: ");
    Serial.println(button);
    enter[3] = button; //storage number 3 equal to incoming number
    }
}
///////////////////////////////////////////////////////////
 void checkEntered5(int button){  //checkEntered5 function will recceive number from the checkEntered4 function
  Serial.println("");
  Serial.println("check enter 5");
  digitalWrite(LED[button-1], HIGH);
  Serial.println("Data 5 is fill");
  Serial.println("5: ");  
  Serial.println(button);  
  enter[4]= button;  //if the storage number 4 empty, fill the storage with incoming number


  Serial.println("");
  Serial.println("Send to unlock"); 
  unlock();  //call in unlock() function

  }
/////////////////////////////////////////////////////////////



void unlock(){  //function that will be compare the entered password with the correct password
  Serial.println("");
  Serial.println("Ask Mr Unlock");
  if((enter[0] == answer[0]) && (enter[1] == answer[1]) && (enter[2] == answer[2]) && (enter[3] == answer[3]) && (enter[4] == answer[4])){  //if the password is correct
  Serial.println("");
  Serial.println("Unlock!");
       digitalWrite(False, LOW);  //turn off false LED
       digitalWrite(True, HIGH);  //turn on true LED in looping mode
       digitalWrite(in2, LOW);   //Unlock Solenoid lock
       digitalWrite(in3, HIGH);  //Unlock Solenoid lock
       
       delay(1000);
       
       Restart();
   }
   }else{  //loop the false LED if the password entered is incorrect
    Serial.println("False");
    for(int i=0; i <= 5; i++){
      digitalWrite(False, HIGH);
      delay(100);
      digitalWrite(False, LOW);
      delay(100);
      }
    Restart();  //call in Restart() function
    }
}
///////////////////////////////////////////////////////
void Restart(){  //Restart the overall system
for(int i; i<=5; i++){
  digitalWrite(LED[i], LOW); //turn off the LED
  enter[i] = 0; //empty the password storage
 
  }
  Serial.println("Enter Key Again");   
} 
