//Title: Smart shelf - Center of gravity
//Description: The center of gravity file calculates the center of gravity and newest items location. 
//Author: David Wood
//Created: 13/2/2024
//Updated: 20/05/2024

void calculateCenterOfGravity(float &Xavg, float &Yavg) {

  float weighted_sum_x = (cell1_x * currentWeight1) + (cell2_x * currentWeight2) + (cell3_x * currentWeight3) + (cell4_x * currentWeight4); // Calculate weighted sum of x coordinates
  float weighted_sum_y = (cell1_y * currentWeight1) + (cell2_y * currentWeight2) + (cell3_y * currentWeight3) + (cell4_y * currentWeight4); // Calculate weighted sum of y coordinates
  
  // Calculate center of gravity
  Xavg = weighted_sum_x / newTotalWeight;         //Calculate X location
  Yavg = weighted_sum_y / newTotalWeight;         //Calculate Y location
  
  // Print center of gravity
  Serial.print("Center of gravity (X, Y): ");   //Print centre gravity label
  Serial.print(Xavg);                           //Print X average
  Serial.print(", ");                           //Print a comma
  Serial.println(Yavg);                         //Print Y average with a new line below

  if (totalitems < previousItemTotal){
      //Dont print anything if item has been removed and update the previous location if total items is zero
      // Update previous weight and location for future calculations
      previousWeight1 = currentWeight1;                  // newWeight 1 becomes previousWeight1
      previousWeight2 = currentWeight2;                  // newWeight 2 becomes previousWeight2
      previousWeight3 = currentWeight3;                  // newWeight 3 becomes previousWeight3
      previousWeight4 = currentWeight4;                  // newWeight 4 becomes previousWeight4
      
      if (totalitems < 1) {
          previousWeight1 = 1;                  // newWeight 1 becomes previousWeight1
          previousWeight2 = 1;                  // newWeight 2 becomes previousWeight2
          previousWeight3 = 1;                  // newWeight 3 becomes previousWeight3
          previousWeight4 = 1;                  // newWeight 4 becomes previousWeight4 
    }
  }
  else{
    float newWeight1  =  currentWeight1 - previousWeight1;    //Subtract the previousWeight1 from currentWeight1 and call it newWeight1
    float newWeight2  =  currentWeight2 - previousWeight2;    //Subtract the previousWeight2 from currentWeight2 and call it newWeight2
    float newWeight3  =  currentWeight3 - previousWeight3;    //Subtract the previousWeight3 from currentWeight3 and call it newWeight3
    float newWeight4  =  currentWeight4 - previousWeight4;    //Subtract the previousWeight4 from currentWeight4 and call it newWeight4
    float newWeighted_sum_x = (cell1_x * newWeight1) + (cell2_x * newWeight2) + (cell3_x * newWeight3) + (cell4_x * newWeight4); // Calculate weighted sum of x coordinates
    float newWeighted_sum_y = (cell1_y * newWeight1) + (cell2_y * newWeight2) + (cell3_y * newWeight3) + (cell4_y * newWeight4); // Calculate weighted sum of y coordinates
  
    // Calculate new location
    X_loc = newWeighted_sum_x / _weightDifference;         //Calculate X location
    Y_loc = newWeighted_sum_y / _weightDifference;         //Calculate Y location
  
    // Print new location
    Serial.print("New item location(X, Y): ");     //Print new item locationlabel
    Serial.print(X_loc);                           //Print X location
    Serial.print(", ");                            //Print a comma
    Serial.println(Y_loc);                         //Print Y location with a new line below

    // Update previous weight and location for future calculations
    previousWeight1 = currentWeight1;                  // newWeight 1 becomes previousWeight1
    previousWeight2 = currentWeight2;                  // newWeight 2 becomes previousWeight2
    previousWeight3 = currentWeight3;                  // newWeight 3 becomes previousWeight3
    previousWeight4 = currentWeight4;                  // newWeight 4 becomes previousWeight4
  }
}
