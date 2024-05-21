//Title: Smart shelf – Single item
//Description: Single Item is the function that tracks the addition or subtraction of items upon the smart shelf. With only one item being placed or removed at a time.
//Author: David Wood
//Created: 13/2/2024
//Updated: 20/05/2024

void singleItems(float newTotalWeight){                                 //This function will determine if a range of single items have been added
  float weightDifference = newTotalWeight - baseWeight;                 //Weight difference is the total weight minus the baseweight.

  if (weightDifference >= item1_low && weightDifference <= item1_high){  //If positive weight difference is between the high and low point of item 1. 
    Serial.print("One item1 has been added total: ");                    //Print to the serial that item 1 has been added. 
    totalitem1 = totalitem1 + 1;                                         //Update Item 1 count to include one item 1 to count.
    totalitems = totalitems + 1;
    Serial.println(totalitem1);                                          //Print to serial the total number of item 1.
    itemchange = true;                                                   //Item change state is set to true, showing that an item was added and it's not unknown.
    baseWeight = newTotalWeight;                                            //Update base weight to include the new weight.
  }
  else if (weightDifference <= -(item1_low) && weightDifference >= -(item1_high) && totalitem1 > 0){  //If negative weight difference is between the negative high and low point of item 1. 
    totalitem1 = totalitem1 - 1;                                         //Update Item 1 count to remove one item 1 from count.
    totalitems = totalitems - 1;
    Serial.print("One item1 has been removed total: ");                  //Print to the serial that item 1 has been removed.
    Serial.println(totalitem1);                                          //Print to serial the total number of item 1.
    itemchange = true;                                                   //Item change state is set to true, showing that an item was added and it's not unknown.
    baseWeight = newTotalWeight;                                            //Update base weight to include the removed weight.
  }  
  else if (weightDifference >= item2_low && weightDifference <= item2_high){  //If positive weight difference is between the high and low point of item 2.
    totalitem2 = totalitem2 + 1;                                              //Update Item 2 count to include one item 2 to count.
    totalitems = totalitems + 1;
    Serial.print("One item2 has been added total: ");                         //Print to the serial that item 2 has been added.
    Serial.println(totalitem2);                                               //Print to serial the total number of item 2.
    itemchange = true;                                                        //Item change state is set to true, showing that an item was added and it's not unknown.
    baseWeight = newTotalWeight;                                                 //Update base weight to include the new weight.
  }
  else if (weightDifference <= -(item2_low) && weightDifference >= -(item2_high) && totalitem2 > 0){  //If negative weight difference is between the negative high and low point of item 2. 
    totalitem2 = totalitem2 - 1;                                              //Update Item 2 count to remove one item 2 from count.
    totalitems = totalitems - 1;
    Serial.print("One item2 has been removed total: ");                       //Print to the serial that item 2 has been removed.
    Serial.println(totalitem2);                                               //Print to serial the total number of item 2.
    itemchange = true;                                                        //Item change state is set to true, showing that an item was added and it's not unknown.
    baseWeight = newTotalWeight;                                                 //Update base weight to include the removed weight.
  }
  else if (weightDifference >= item3_low && weightDifference <= item3_high){  //If positive weight difference is between the high and low point of item 3.
    totalitem3 = totalitem3 + 1;                                              //Update Item 3 count to include one item 3 to count.
    totalitems = totalitems + 1;
    Serial.print("One item3 has been added total: ");                         //Print to the serial that item 3 has been added.
    Serial.println(totalitem3);                                               //Print to serial the total number of item 3.
    itemchange = true;                                                        //Item change state is set to true, showing that an item was added and it's not unknown.
    baseWeight = newTotalWeight;                                                 //Update base weight to include the new weight.
  }
  else if (weightDifference <= -(item3_low)&& weightDifference >= -(item3_high) && totalitem3 > 0){  //If negative weight difference is between the negative high and low point of item 3.
    totalitem3 = totalitem3 - 1;                                              //Update Item 3 count to remove one item 3 from count.
    totalitems = totalitems - 1;
    Serial.print("One item3 has been removed total: ");                       //Print to the serial that item 3 has been removed.
    Serial.println(totalitem3);                                               //Print to serial the total number of item 3.
    itemchange = true;                                                        //Item change state is set to true, showing that an item was added and it's not unknown.
    baseWeight = newTotalWeight;                                                 //Update base weight to include the removed weight.
  }
  else if (weightDifference >= 15 && !itemchange )                        //If positive weight difference above 15 grams and itemchange is false.
  {
    totalUnknown = totalUnknown + 1;                                     //Update total uknown count to add one to the total.
    totalitems = totalitems + 1;
    Serial.print("An Uknown item has been added total: ");               //Print in serial that an unknown item has been added.
    Serial.println(totalUnknown);                                        //Print total unknown items.
    Serial.println("Recalibration or item check required. ");            //Print warning message in serial.
    itemchange = true;                                                   //Item change state is set to true, showing that the item has been counted for.
    Unknown_weight = weightDifference;                                   //Set Uknown_weight to track removal.  
    Unknown_low = Unknown_weight - 3;                                    //Set Uknown low to include a slight varition in weight.
    Unknown_high = Unknown_weight + 3;                                   //Set Uknown high to include a slight varition in weight.
    baseWeight = newTotalWeight;                                            //Update base weight to include 
  }
  else if(weightDifference <= -(Unknown_low)&& weightDifference >= -(Unknown_high) && totalUnknown > 0){  //If negative weight difference is between the negative high and low point of item 3.
    totalUnknown = totalUnknown - 1;                                              //Update Item 3 count to remove one item 3 from count.
    totalitems = totalitems - 1;
    Serial.print("One Uknown has been removed total: ");                          //Print to the serial that item 3 has been removed.
    Serial.println(totalUnknown);                                                 //Print to serial the total number of item 3.
    itemchange = true;                                                            //Item change state is set to true, showing that an item was added and it's not unknown.
    baseWeight = newTotalWeight;                                                     //Update base weight to include the removed weight.
  }
  
}

// Skeleton Code for expansion 
/*
else if (weightDifference >= itemXX_low && weightDifference <= itemXX_high){  //If positive weight difference is between the high and low point of item XX.
    totalitemXX = totalitemXX + 1;                                              //Update Item XX count to include one item XX to count.
    totalitems = totalitems + 1;
    Serial.print("One itemXX has been added total: ");                         //Print to the serial that item XX has been added.
    Serial.println(totalitemXX);                                               //Print to serial the total number of item XX.
    itemchange = true;                                                        //Item change state is set to true, showing that an item was added and it's not unknown.
    baseWeight = newTotalWeight;                                                 //Update base weight to include the new weight.
  }
  else if (weightDifference <= -(itemXX_low) && weightDifference >= -(itemXX_high) && totalitemXX > 0){  //If negative weight difference is between the negative high and low point of item XX. 
    totalitem2 = totalitemXX - 1;                                              //Update Item XX count to remove one item XX from count.
    totalitems = totalitems - 1;
    Serial.print("One itemXX has been removed total: ");                       //Print to the serial that item XX has been removed.
    Serial.println(totalitemXX);                                               //Print to serial the total number of item XX.
    itemchange = true;                                                        //Item change state is set to true, showing that an item was added and it's not unknown.
    baseWeight = newTotalWeight;                                                 //Update base weight to include the removed weight.
  }
  */
