/*	Author:	Carter Beil
	Date:	October 20, 2012
	File: beilcaStarbucks.h
*/

#pragma once
#include "Starbucks.h"
// std includes
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>

 class Node{
public:		

	//Constructors
	Node();
	Node(Entry e);
	
	//Node pointers in the tree
	Node* left_;
	Node* right_;
	
	//Entry object to hold data	
	Entry* data;		

  }; 

 class beilcaStarbucks : public Starbucks {
 public:

	 beilcaStarbucks();


	 /*
	 * add all entries in the array to your data structure
	 *
	 * The "c" parameter is a pointer to an array of all the entries to be added, and n is the length of
	 * the array.
	 *
	 * Note: If you detect that two items have the same coordinates, then do not add the new item
	 *       that has the same coordinates as another item. This is guaranteed to happen, by the way,
	 *       because some Starbucks locations are listed in the database twice. We will define two locations
	 *       to be the "same location" if both |x1 - x2| <= 0.00001 and |y1 - y2| < 0.00001
	 */
	 void build(Entry* c, int n);


	 /*
	 * Return a pointer to the entry that is closest to the given coordinates. Your
	 *  answer may be approximate, but then you will lose points on the "Accuracy" quality measure
	 */
	 Entry* getNearest(double x, double y);

 };