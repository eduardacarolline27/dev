String toString(String code) {
  
  return "";
}

void Display(String code) {
  int code_len = code.length() + 1;
  char code_array[code_len];
  code.toCharArray(code_array, code_len);
  for (int i = 0; i < code_len; i++) {
    if (code_array[i] == '.')
    {
     
      digitalWrite(buzzerpin, HIGH);
      delay(dotLen);
      
      digitalWrite(buzzerpin , LOW);
      delay(elemGap);
      Serial.print(code_array[i]);
    }
    else if (code_array[i] == '-')
    {
     
      digitalWrite(buzzerpin , HIGH);
      delay(dashLen);
      
      digitalWrite(buzzerpin, LOW);
      delay(elemGap);
      Serial.print(code_array[i]);
    }
    else if (code_array[i] == ' ')
    {
      delay(Space);
      Serial.print("   ");
    }
    else if (code_array[i] == charDelimiter)
    {
      delay(charGap);
      Serial.print(" ");
    }
  }
  Serial.println();
  Serial.println("Pronto");
}
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}