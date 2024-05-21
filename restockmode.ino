//Title: Smart shelf – Restock mode
//Description: The restock mode allows for multiple items to be placed on the shelf at once with user feedback.
//Author: David Wood
//Created: 13/2/2024
//Updated: 20/05/2024

void restockmode(float totalWeight){ // Multiple items can be restocked here prompting user input
  float weightDifference = totalWeight - baseWeight;

  //Multi item idetenification
  float item1x2_low = item1_low * 2;                      // Define two of low item one
  float item1x3_low = item1_low * 3;                      // Define three of low item one
  float item1x2_high = item1_high * 2;                    // Define two of high item one
  float item1x3_high = item1_high * 3;                    // Define three of high item one

  float item2x2_low = item2_low * 2;                      // Define two of low item two
  float item2x3_low = item2_low * 3;                      // Define three of low item two
  float item2x2_high = item2_high * 2;                    // Define two of high item two
  float item2x3_high = item2_high * 3;                    // Define three of high item two

  float item3x2_low = item3_low * 2;                      // Define two of low item three
  float item3x3_low = item3_low * 3;                      // Define three of low item three
  float item3x2_high = item3_high * 2;                    // Define two of high item three
  float item3x3_high = item3_high * 3;                    // Define three of high item three
  

  //This is sorted by item then weight categories
  // item1
  if (weightDifference >= item1x2_low && weightDifference <= item1x2_high){  //Adding 2 item1
    Serial.println("Were 2 of item1 added? Button 3= yes");                       // User Prompt 
    if (digitalRead(GPGreen_pin) == LOW) {                                      // If GPio 13 pulled low
      totalitem1 = totalitem1 + 2;                                           // Add two to item total 
      Serial.print("2 of item1 added total: ");                              // Display to user two were added
      Serial.println(totalitem1);                                            // Display total number of item one
      baseWeight = totalWeight;                                              // Update base weight
    }
  }
  else if (weightDifference >= item1x3_low && weightDifference <= item1x3_high){  // Adding 3 item1
    Serial.println("Were 3 of item1 added? Button 3= yes");                      // User Prompt
    if (digitalRead(GPGreen_pin) == LOW) {                                      // If GPio 13 pulled low
      totalitem1 = totalitem1 + 3;                                           // Add three to item total 
      Serial.print("3 item1 have been added total: ");                       // Display to user three were added
      Serial.println(totalitem1);                                            // Display total number of item one
      baseWeight = totalWeight;                                              // Update base weight
    }  
  }
  else if (weightDifference <= -(item1x2_low) && weightDifference >= -(item1x2_high) && totalitem1 > 1){  // Removing 2 item1  
    Serial.println("Were 2 of item1 removed? Button 3= yes");                    // User Prompt
    if (digitalRead(GPGreen_pin) == LOW) {                                      // If GPio 13 pulled low                   
      totalitem1 = totalitem1 - 2;                                           // Remove two to item total
      Serial.print("2 of item1 have been removed total: ");                  // Display to user two were removed
      Serial.println(totalitem1);                                            // Display total number of item one
      baseWeight = totalWeight;                                              // Update base weight
    }
  }
  else if (weightDifference <= -(item1x3_low) && weightDifference >= -(item1x3_high) && totalitem1 > 2){  // Removing 3 item1
    Serial.println("Were 3 of item1 removed? Button 3= yes");                    // User Prompt
    if (digitalRead(GPGreen_pin) == LOW) {                                      // If GPio 13 pulled low 
      totalitem1 = totalitem1 - 3;                                           // Remove three to item total
      Serial.print("3 of item1 have been removed total: ");                  // Display to user three were removed
      Serial.println(totalitem1);                                            // Display total number of item one
      baseWeight = totalWeight;                                              // Update base weight
    }
  }


  //item2
  if (weightDifference >= item2x2_low && weightDifference <= item2x2_high){  // Adding 2 item2
    Serial.println("Were 2 of item2 added? Button 2= yes ");                     // User Prompt
    if (digitalRead(GPOrange_pin) == LOW) {                                      // If GPio 12 pulled low
      totalitem2 = totalitem2 + 2;                                           // Add two to item total
      Serial.print("2 of item2 have been added total: ");                    // Display to user two were added
      Serial.println(totalitem2);                                            // Display total number of item two
      baseWeight = totalWeight;                                              // Update base weight
    }
  }
  else if (weightDifference >= item2x3_low && weightDifference <= item2x3_high){  //Adding 3 item2
    Serial.println("Were 3 of item2 added? Button 2= yes");                      // User Prompt 
    if (digitalRead(GPOrange_pin) == LOW) {                                      // If GPio 12 pulled low
      totalitem2 = totalitem2 + 3;                                           // Add three to item total
      Serial.print("3 of item2 have been added total: ");                    // Display to user three were added
      Serial.println(totalitem2);                                            // Display total number of item two
      baseWeight = totalWeight;                                              // Update base weight
    }
  }
  else if (weightDifference <= -(item2x2_low) && weightDifference >= -(item2x2_high) && totalitem2 > 1){  //Removing 2 item2
    Serial.println("Were 2 of item2 removed? Button 2= yes");                    // User Prompt 
    if (digitalRead(GPOrange_pin) == LOW) {                                      // If GPio 12 pulled low
      totalitem2 = totalitem2 - 2;                                           // Remove two to item total
      Serial.print("2 of item2 have been removed total: ");                  // Display to user two were removed
      Serial.println(totalitem2);                                            // Display total number of item two
      baseWeight = totalWeight;                                              // Update base weight
    }  
  }
  else if (weightDifference <= -(item2x3_low) && weightDifference >= -(item2x3_high) && totalitem2 > 2){  //Removing 3 item2
    Serial.println("Were 3 of item2 removed? Button 2= yes");                    // User Prompt 
    if (digitalRead(GPOrange_pin) == LOW) {                                      // If GPio 12 pulled low
      totalitem2 = totalitem2 - 3;                                           // Remove three to item total
      Serial.print("3 of item2 have been removed total: ");                  // Display to user three were removed
      Serial.println(totalitem2);                                            // Display total number of item two
      baseWeight = totalWeight;                                              // Update base weight
    }
  }

  // item3
    if (weightDifference >= item3x2_low && weightDifference <= item3x2_high){  // Adding 2 item3
    Serial.println("Were 2 of item3 added? Button 1= yes ");                       // User Prompt
    if (digitalRead(GPRed_pin) == LOW) {                                        // If GPio 11 pulled low
      totalitem3 = totalitem3 + 2;                                             // Add two to item total
      Serial.print("2 of item3 have been added total: ");                      // Display to user two were added
      Serial.println(totalitem3);                                              // Display total number of item three
      baseWeight = totalWeight;                                                // Update base weight
    }
  }
  else if (weightDifference >= item3x3_low && weightDifference <= item3x3_high){  // Adding 3 item3
    Serial.println("Were 3 of item3 added? Button 1= yes");                           // User Prompt
    if (digitalRead(GPRed_pin) == LOW) {                                           // If GPio 11 pulled low
      totalitem3 = totalitem3 + 3;                                                // Add three to item total
      Serial.print("3 of item3 have been added total: ");                         // Display to user three were added
      Serial.println(totalitem3);                                                 // Display total number of item three
      baseWeight = totalWeight;                                                   // Update base weight
    }
  }
  else if (weightDifference <= -(item3x2_low) && weightDifference >= -(item3x2_high) && totalitem3 > 1){  //Removing item3
    Serial.println("Were 2 of item3 removed? Button 1= yes ");                        // User Prompt
    if (digitalRead(GPRed_pin) == LOW) {                                           // If GPio 11 pulled low
      totalitem3 = totalitem3 - 2;                                                // Remove two to item total
      Serial.print("2 of item3 have been removed total: ");                       // Display to user two were removed
      Serial.println(totalitem3);                                                 // Display total number of item three
      baseWeight = totalWeight;                                                   // Update base weight
    }
  }
  else if (weightDifference <= -(item3x3_low) && weightDifference >= -(item3x3_high) && totalitem3 > 2){  //Removing item3
    Serial.println("Were three of item3 removed? Button 1= yes ");                    // User Prompt
    if (digitalRead(GPRed_pin) == LOW) {                                           // If GPio 11 pulled low
      totalitem3 = totalitem3 - 3;                                                // Remove three to item total
      Serial.print("3 of item3 have been removed total: ");                       // Display to user three were removed
      Serial.println(totalitem3);                                                 // Display total number of item three
      baseWeight = totalWeight;                                                   // Update base weight
    }
  }
}


// Skeleton code for expansion
/* 
 *    
 *float itemXXx2_low = itemXX_low * 2;
  float itemXXx3_low = itemXX_low * 3;
  float itemXXx2_high = itemXX_high * 2;
  float itemXXx3_high = itemXX_high * 3;
  
   // itemXX
    if (weightDifference >= itemXXx2_low && weightDifference <= itemXXx2_high){  //Adding 2 itemXX
    Serial.println("Were 2 of itemXX added? GP12= yes ");
    if (digitalRead(GP12_pin) == LOW) {
      totalitemXX = totalitemXX + 2;
      Serial.print("2 of itemXX have been added total: ");
      Serial.println(totalitemXX);
      baseWeight = totalWeight;
    }
  }
  else if (weightDifference >= itemXXx3_low && weightDifference <= itemXXx3_high){  //Adding 3 itemXX
    Serial.println("Were 3 of itemXX added? GP12= yes");
    if (digitalRead(GP12_pin) == LOW) {
      totalitemXX = totalitemXX + 3;
      Serial.print("3 of itemXX have been added total: ");
      Serial.println(totalitemXX);
      baseWeight = totalWeight;
    }
  }
  else if (weightDifference <= -(itemXXx2_low) && weightDifference >= -(itemXXx2_high) && totalitemXX > 1){  //Removing itemXX
      totalitemXX = totalitemXX - 2;
      Serial.print("2 of itemXX have been removed total: ");
      Serial.println(totalitemXX);
      baseWeight = totalWeight;
  }
  else if (weightDifference <= -(itemXXx3_low) && weightDifference >= -(itemXXx3_high) && totalitemXX > 2){  //Removing itemXX
    totalitemXX = totalitemXX - 3;
    Serial.print("3 of itemXX have been removed total: ");
    Serial.println(totalitemXX);
    baseWeight = totalWeight;
  }
  */
