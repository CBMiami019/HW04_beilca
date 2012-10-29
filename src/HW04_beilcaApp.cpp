#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

#include "boost/date_time/posix_time/posix_time.hpp"
#include "cinder/Text.h"
#include "cinder/Rand.h"
#include "cinder/ImageIo.h"
#include "cinder/app/KeyEvent.h"
#include <vector>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>
#include <ios>
#include <istream>

#include "Starbucks.h"
//For some reason, I can't get my #include "beilcaStarbucks.h" to work, I'll look more into this
#include "beilcaStarbucks.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04_beilcaApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void HW04_beilcaApp::setup(){
	vector<Entry*> vect;
/*	Since part 1 of this assignment doesn't include graphics, we can do all of our coding inside the
	setup, and just work with 'cin' and 'cout' for input and output to and from the console with our
	current test results.
*/

//First off I need to get the data from "Starbucks_2006.csv" and put that data into an array

	ifstream inStream("..\\resources\\Starbucks_2006.csv");

	if (inStream.fail()){ 
		cout << "Error opening file" << endl;
	}

	string line;

	//Variable to keep track of how many numbers are in the list, to then be able to build
	//an array of 'count' length
	int count = 0;

	//This will not work in cinder
	//cout << "Count is: " << count << endl;

	do {
		//To get each line's identifier, x value, and y value
		Entry entry;
		getline(inStream, line, '\r');
		count++;
		//Needs to be !inStream, because if it there was no 'not' then it would stop on the first iteration... dealt with that for a bit
	} while(!inStream.eof());


	//This will not work in cinder
	//cout << "Count is: " << count << endl;

	Entry* data = new Entry [count];

	//Restart the input stream at the beginning
	ifstream newStream("Starbucks_2006.csv");

	for (int i = 0; i < (count-1); i++){
		//To get each line's identifier, x value, and y value
		Entry entry;
		getline(newStream, line, '\r');
		data[i].identifier = line;
		
		//Have the current node get the x value stored in the document
		inStream.get();
		//data[i].x = line will not work because you can't convert a string to a double
		inStream >> data[i].x;

		//Have the current node get the y value stored in the document
		inStream.get();
		//Similarly data[i].y = line will not work because you can't convert a string to a double
		inStream >> data[i].y;
	}
	
	/*Entry* entryArray = new Entry[vect.size()];
	int len = vect.size();
	for (int i = 0; i < len; i++)
	{
		entryArray[i] = *(vect.at(i));
	}
	*/
	
	//close the input stream and delete the 
	newStream.close();
	//delete &entryArray;

	//create a beilcaStarbucks and build a K-D tree
	beilcaStarbucks* root;
	(*root).build(data, count);

	//Was trying to use "pause" to see what my 'cout' values were, but cout does not work in cinder, at least to my understanding
	//system("pause");
	
}

void HW04_beilcaApp::mouseDown( MouseEvent event )
{
}

void HW04_beilcaApp::update()
{
}

void HW04_beilcaApp::draw()
{
	// clear out the window with black
	//gl::clear( Color( 0, 0, 0 ) ); 

	//gl::drawString	("hello", Vec2f & (0,0,0,0), ColorA & 	color = ColorA( 1, 1, 1, 1 ), Font 	font = Font());	

}

CINDER_APP_BASIC( HW04_beilcaApp, RendererGl )
