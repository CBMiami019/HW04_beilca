/*	Author:	Carter Beil
	Date:	October 20, 2012
	File: beilcaStarbucks.cpp
*/

#include "Starbucks.h"
#include "beilcaStarbucks.h"


Node::Node(){
	left_ = right_ = NULL;
	data = new Entry();			
}



beilcaStarbucks::beilcaStarbucks(){

}

//beilcaStarbucks::beilcaStarbucks(Entry* e){
	//this->entry = data;
	//this-> = NULL;
	//this->right = NULL;
//}

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
 void beilcaStarbucks::build(Entry* e, int count){
	 randomize(e, count);
	 Entry* root = &e[0];

	 Entry* build = new Entry [count];
	 
	 for (int i = 0; i< count; i++){
			insert(e[i], true);
	 }
 }

 /*
 * Return a pointer to the entry that is closest to the given coordinates. Your
 *  answer may be approximate, but then you will lose points on the "Accuracy" quality measure
 */
 Entry* getNearest(double x, double y, Node* r, bool xLevel){

	 //I will implement the search function here, and probably just loop through
	 // the data in the getNearest function

	 return nearestStarbucks;
 }

 Node* beilcaStarbucks::insert(Entry* e, Node* r, bool xLevel) {
	 if (r->data == NULL) return;

	 if(e->x == r->data->x && e->y == r->data->y) return r;

	 if(xLevel){
		 if(e->x < r->data->x){
			 r->left_ = insert(e, r->left_, !xLevel);
		 }else{
			 r->right_ = insert(e, r->right_, !xLevel);
		 }
		
		 //my brain really hurts 
	 }else{
		 if(e->y < r->data->y){
			 r->left_ = insert(e, r->left_, !xLevel);
		 }else{
			 r->right_ = insert(e, r->right_, !xLevel);
		 }
	 }

	 return r;
}

Entry* beilcaStarbucks::search(double x, double y, Node* r, bool isXLevel){ 

}


//I would love to randomize my array before trying to build it!!!

//Helped from *uthnp*
void beilcaStarbucks::randomize(Entry* e, int arrayLength){
	int temp1 = 0;
	int temp2 = 0;
	Entry temp;

	for (int i = 0; i< arrayLength; i++){
			for (int i = 0; i < arrayLength; i++){
				//If the random numbers are the same, choose new ones until they are different
				while (temp1 == temp2){
					temp1 = (rand() % arrayLength);
					temp2 = (rand() % arrayLength);
				}
			//Switch the values of the temp values with the ones in the array, to scramble it
			temp = e[temp1];
			e[temp1] = e[temp2];
			e[temp2] = temp;
		}
	}
}