//Title: Smart shelf – Item calibration
//Description: This file calibrates the list of items that the user wants to sample. With three samples of each item are taken.
//Author: David Wood
//Created: 13/2/2024
//Updated: 20/05/2024

void itemCali(float totalWeight){
  float weightDifference = totalWeight - baseWeight;

  float item1_Mean = 0;                               // Initialise mean for item one                   
  float item2_Mean = 0;                               // Initialise mean for item two
  float item3_Mean = 0;                               // Initialise mean for item three

  float item1_Dev = 0;                                // Initialise standard deviation for item one 
  float item2_Dev = 0;                                // Initialise standard deviation for item two
  float item3_Dev = 0;                                // Initialise standard deviation for item three

  float item1_1 = 0;                                  // Initialise first sample for item one 
  float item1_2 = 0;                                  // Initialise second sample for item one
  float item1_3 = 0;                                  // Initialise third sample for item one
  
  float item2_1 = 0;                                  // Initialise first sample for item two
  float item2_2 = 0;                                  // Initialise second sample for item two
  float item2_3 = 0;                                  // Initialise third sample for item two
  
  float item3_1 = 0;                                  // Initialise first sample for item three
  float item3_2 = 0;                                  // Initialise second sample for item three
  float item3_3 = 0;                                  // Initialise third sample for item three

  

  Serial.println("Please Prepare Items for calibration");                 // Prompt user to prepare items for calibration
  delay (2000);                                                           // Delay for 2 seconds
  Serial.println("To calculate the distribution of weight, place one item at a time, totaling three.");       // Prompt user with instructions
  delay (2000);                                                           // Delay for 2 seconds
  Serial.println("Place the first item1 on shelf");                       // Prompt user to place first item on shelf
  delay (2000);                                                           // Delay for 2 seconds
  
  currentWeight1 = scale1.get_units();                                    // Get weight from load cell 1
  currentWeight2 = scale2.get_units();                                    // Get weight from load cell 2    
  currentWeight3 = scale3.get_units();                                    // Get weight from load cell 3
  currentWeight4 = scale4.get_units();                                    // Get weight from load cell 4
  totalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;                      // Calculate total weight
  
  item1_1 = totalWeight;                                                  // Set sample to be total weight
  Serial.print("item1 first: ");                                          // Prompt user with first sample weight
  Serial.println(item1_1);                                                // Display first sample weight
  delay(500);                                                             // Delay 500ms 
  Serial.println("Please clear shelf");                                   // Prompt user to clear shelf
  delay (2000);                                                           // Delay for 2 seconds
  Serial.println("Place the second item1 on shelf");                      // Prompt user to place second sample on shelf
  delay (2000);                                                           // Delay for 2 seconds

  currentWeight1 = scale1.get_units();                                    // Get weight from load cell 1
  currentWeight2 = scale2.get_units();                                    // Get weight from load cell 2
  currentWeight3 = scale3.get_units();                                    // Get weight from load cell 3
  currentWeight4 = scale4.get_units();                                    // Get weight from load cell 4
  totalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;                      // Calculate total weight
  
  item1_2 = totalWeight;                                                  // Set sample to be total weight
  Serial.print("item1 second: ");                                         // Prompt user with second sample weight
  Serial.println(item1_2);                                                // Display second sample weight
  delay(500);                                                             // Delay 500ms
  Serial.println("Please clear shelf");                                   // Prompt user to clear shelf
  delay (2000);                                                           // Delay for 2 seconds
  Serial.println("Place the third item1 on shelf");                       // Prompt user to place third sample on shelf
  delay (2000);                                                           // Delay for 2 seconds

  currentWeight1 = scale1.get_units();                                    // Get weight from load cell 1
  currentWeight2 = scale2.get_units();                                    // Get weight from load cell 2
  currentWeight3 = scale3.get_units();                                    // Get weight from load cell 3
  currentWeight4 = scale4.get_units();                                    // Get weight from load cell 4
  totalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;                      // Calculate total weight
  
  item1_3 = totalWeight;                                                  // Set sample to be total weight
  Serial.print("item1 third: ");                                          // Prompt user with third sample weight
  Serial.println(item1_3);                                                // Display third sample weight
  delay(500);                                                             // Delay 500ms
  Serial.println("Please clear shelf");                                   // Prompt user to clear shelf
  delay (5000);                                                           // Delay for 5 seconds


  Serial.println("Place the first item2 on shelf");                       // Prompt user to place first sample on shelf
  delay (2000);                                                           // Delay for 2 seconds

  currentWeight1 = scale1.get_units();                                    // Get weight from load cell 1
  currentWeight2 = scale2.get_units();                                    // Get weight from load cell 2
  currentWeight3 = scale3.get_units();                                    // Get weight from load cell 3
  currentWeight4 = scale4.get_units();                                    // Get weight from load cell 4
  totalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;                      // Calculate total weight
  
  item2_1 = totalWeight;                                                  // Set sample to be total weight
  Serial.print("item2 first: ");                                          // Prompt user with first sample weight
  Serial.println(item2_1);                                                // Display first sample weight
  delay(500);                                                             // Delay 500ms
  Serial.println("Please clear shelf");                                   // Prompt user to clear shelf
  delay (2000);                                                           // Delay for 2 seconds
  Serial.println("Place the second item2 on shelf");                      // Prompt user to place second sample on shelf
  delay (2000);                                                           // Delay for 2 seconds

  currentWeight1 = scale1.get_units();                                    // Get weight from load cell 1
  currentWeight2 = scale2.get_units();                                    // Get weight from load cell 2
  currentWeight3 = scale3.get_units();                                    // Get weight from load cell 3
  currentWeight4 = scale4.get_units();                                    // Get weight from load cell 4
  totalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;                      // Calculate total weight

  item2_2 = totalWeight;                                                  // Set sample to be total weight
  Serial.print("item2 second: ");                                         // Prompt user with second sample weight
  Serial.println(item2_2);                                                // Display second sample weight
  delay(500);                                                             // Delay 500ms
  Serial.println("Please clear shelf");                                   // Prompt user to clear shelf
  delay (2000);                                                           // Delay for 2 seconds
  Serial.println("Place the third item2 on shelf");                       // Prompt user to place third sample on shelf
  delay (2000);                                                           // Delay for 2 seconds

  currentWeight1 = scale1.get_units();                                    // Get weight from load cell 1
  currentWeight2 = scale2.get_units();                                    // Get weight from load cell 2
  currentWeight3 = scale3.get_units();                                    // Get weight from load cell 3
  currentWeight4 = scale4.get_units();                                    // Get weight from load cell 4
  totalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;                      // Calculate total weight

  item2_3 = totalWeight;                                                  // Set sample to be total weight
  Serial.print("item2 third: ");                                          // Prompt user with third sample weight
  Serial.println(item2_3);                                                // Display third sample weight
  delay(500);                                                             // Delay 500ms
  Serial.println("Please clear shelf");                                   // Prompt user to clear shelf
  delay (5000);                                                           // Delay for 5 seconds


  Serial.println("Place the first item3 on shelf");                       // Prompt user to place first sample on shelf
  delay (2000);                                                           // Delay for 2 seconds

  currentWeight1 = scale1.get_units();                                    // Get weight from load cell 1
  currentWeight2 = scale2.get_units();                                    // Get weight from load cell 2
  currentWeight3 = scale3.get_units();                                    // Get weight from load cell 3
  currentWeight4 = scale4.get_units();                                    // Get weight from load cell 4
  totalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;                      // Calculate total weight

  item3_1 = totalWeight;                                                  // Set sample to be total weight
  Serial.print("item3 first: ");                                          // Prompt user with first sample weight
  Serial.println(item3_1);                                                // Display first sample weight
  delay(500);                                                             // Delay 500ms
  Serial.println("Please clear shelf");                                   // Prompt user to clear shelf
  delay (2000);                                                           // Delay for 2 seconds
  Serial.println("Place the second item3 on shelf");                      // Prompt user to place second sample on shelf
  delay (2000);                                                           // Delay for 2 seconds

  currentWeight1 = scale1.get_units();                                    // Get weight from load cell 1
  currentWeight2 = scale2.get_units();                                    // Get weight from load cell 2
  currentWeight3 = scale3.get_units();                                    // Get weight from load cell 3
  currentWeight4 = scale4.get_units();                                    // Get weight from load cell 4
  totalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;                      // Calculate total weight

  item3_2 = totalWeight;                                                  // Set sample to be total weight
  Serial.print("item3 second: ");                                         // Prompt user with second sample weight
  Serial.println(item3_2);                                                // Display second sample weight
  delay(500);                                                             // Delay 500ms
  Serial.println("Please clear shelf");                                   // Prompt user to clear shelf
  delay (2000);                                                           // Delay for 2 seconds
  Serial.println("Place the third item3 on shelf");                       // Prompt user to place third sample on shelf
  delay (2000);                                                           // Delay for 2 seconds

  currentWeight1 = scale1.get_units();                                    // Get weight from load cell 1                                      
  currentWeight2 = scale2.get_units();                                    // Get weight from load cell 2
  currentWeight3 = scale3.get_units();                                    // Get weight from load cell 3
  currentWeight4 = scale4.get_units();                                    // Get weight from load cell 4
  totalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;                      // Calculate total weight

  item3_3 = totalWeight;                                                  // Set sample to be total weight
  Serial.print("item3 third: ");                                          // Prompt user with third sample weight
  Serial.println(item3_3);                                                // Display third sample weight
  delay(500);                                                             // Delay 500ms
  Serial.println("Please clear shelf");                                   // Prompt user to clear shelf
  delay (2000);                                                           // Delay for 2 seconds

  //Calculate item1_ deviation 
  item1_Mean = (item1_1 + item1_2 + item1_3)/3;                           // Calculate the mean of the items
  item1_Dev = sqrt((sq(item1_1-item1_Mean)+sq(item1_2-item1_Mean)+sq(item1_3-item1_Mean) )/(3-1));          //Calculate the standard deviation of the item
  Serial.print("item1_ standard deviation: ");                            // Prompt user with standard deviation
  Serial.println(item1_Dev);                                              // Display standard deviation
  item1_low = item1_Mean - (item1_Dev + 10);                              // Calculate the minimum point for the item
  item1_high = item1_Mean + (item1_Dev + 10);                             // Calculate the maximum point for the item
  Serial.print("item1 minium: ");                                         // Prompt user with minimum
  Serial.println(item1_low);                                              // Display minimum of item one
  Serial.print("item1 maxium: ");                                         // Prompt user with maximum
  Serial.println(item1_high);                                             // Display maximum of item one

  //Calculate item2 deviation   
  item2_Mean = (item2_1 + item2_2 + item2_3)/3;                           // Calculate the mean of the items
  item2_Dev = sqrt((sq(item2_1-item2_Mean)+sq(item2_2-item2_Mean)+sq(item2_3-item2_Mean) )/(3-1));          //Calculate the standard deviation of the item
  Serial.print("item2_ standard deviation: ");                            // Prompt user with standard deviation
  Serial.println(item2_Dev);                                              // Display standard deviation
  item2_low = item2_Mean - (item2_Dev + 10);                              // Calculate the minimum point for the item
  item2_high = item2_Mean + (item2_Dev + 10);                             // Calculate the maximum point for the item
  Serial.print("item2 minium: ");                                         // Prompt user with minimum
  Serial.println(item2_low);                                              // Display minimum of item two
  Serial.print("item2 maxium: ");                                         // Prompt user with maximum
  Serial.println(item2_high);                                             // Display maximum of item two

  //Calculate item3 deviation 
  item3_Mean = (item3_1 + item3_2 +item3_3)/3;                            // Calculate the mean of the items
  item3_Dev = sqrt((sq(item3_1-item3_Mean)+sq(item3_2-item3_Mean)+sq(item3_3-item3_Mean) )/(3-1));        //Calculate the standard deviation of the item
  Serial.print("item3_ standard deviation: ");                            // Prompt user with standard deviation
  Serial.println(item3_Dev);                                              // Display standard deviation
  item3_low = item3_Mean - (item3_Dev + 10);                              // Calculate the minimum point for the item
  item3_high = item3_Mean + (item3_Dev + 10);                             // Calculate the maximum point for the item
  Serial.print("item3 minium: ");                                         // Prompt user with minimum
  Serial.println(item3_low);                                              // Display minimum of item three
  Serial.print("item3 maxium: ");                                         // Prompt user with maximum
  Serial.println(item3_high);                                             // Display maximum of item three

}


//Skeleton code for expansion
/*
  float itemXX_Mean = 0;
  float itemXX_Dev = 0;
  float itemXX_1 = 0;
  float itemXX_2 = 0;
  float itemXX_3 = 0;


  Serial.println("Place the first itemXX on shelf");
  delay (2000);

  currentWeight1 = scale1.get_units();
  currentWeight2 = scale2.get_units();
  currentWeight3 = scale3.get_units();
  currentWeight4 = scale4.get_units();
  totalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;

  itemXX_1 = totalWeight;
  Serial.print("itemXX first: ");
  Serial.println(itemXX_1);
  delay(500);
  Serial.println("Please clear shelf");
  delay (2000);
  Serial.println("Place the second itemXX on shelf");
  delay (2000);

  currentWeight1 = scale1.get_units();
  currentWeight2 = scale2.get_units();
  currentWeight3 = scale3.get_units();
  currentWeight4 = scale4.get_units();
  totalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;

  itemXX_2 = totalWeight;
  Serial.print("itemXX second: ");
  Serial.println(itemXX_2);
  delay(500);
  Serial.println("Please clear shelf");
  delay (2000);
  Serial.println("Place the third itemXX on shelf");
  delay (2000);

  currentWeight1 = scale1.get_units();
  currentWeight2 = scale2.get_units();
  currentWeight3 = scale3.get_units();
  currentWeight4 = scale4.get_units();
  totalWeight = currentWeight1 + currentWeight2 + currentWeight3 + currentWeight4;

  itemXX_3 = totalWeight;
  Serial.print("itemXX third: ");
  Serial.println(itemXX_3);
  delay(500);
  Serial.println("Please clear shelf");
  delay (2000);

  //Calculate itemXX deviation 
  itemXX_Mean = (itemXX_1 + itemXX_2 +itemXX_3)/3;
  itemXX_Dev = sqrt((sq(itemXX_1-itemXX_Mean)+sq(itemXX_2-itemXX_Mean)+sq(itemXX_3-itemXX_Mean) )/(3-1));
  Serial.print("itemXX_ standard deviation: ");
  Serial.println(itemXX_Dev);
  itemXX_low = itemXX_Mean - (itemXX_Dev + 10);
  itemXX_high = itemXX_Mean + (itemXX_Dev + 10);
  Serial.print("itemXX minium: ");
  Serial.println(itemXX_low);
  Serial.print("itemXX maxium: ");
  Serial.println(itemXX_high);
*/
