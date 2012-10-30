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
#include "beilcaStarbucks.h"

/*
I was absolutely correct in my assumption that my K-D Tree would be an 8 on the difficulty scale to build.
Since starting this project I have realized I just do not understand c++/cinder and its syntax as much as
I need in order to complete this project to the best of my ability. Through hours of video tutorials and 
other tutorials on www.cplusplus.com I am still stuck in a rut, and now it has put me a day behind.

For part 2, I understand it is late, and I also did not follow through with my K-D tree, and thus will 
suffer a harsh grade penalty, with which I am not proud of in the least. I will have to suck it up and just 
build an array, and sort through the items in a list. I better be dead accurate. 
*/

//Big thanks for help from Adam Rasfeld on the tasks that I did manage to accomplish on this assignment.

//Using reference and tutorials for i/o streams
//http://cplusplus.com/reference/iostream/

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
/*	Since part 1 of this assignment doesn't include graphics, we can do all of our coding inside the
	setup, and just work with 'cin' and 'cout' for input and output to and from the console with our
	current test results.
*/

//First off I need to get the data from "Starbucks_2006.csv" and put that data into an array

	ifstream inStream("../Resources/Starbucks_2006.csv");

	string line;

	//Variable to keep track of how many numbers are in the list, to then be able to build
	//an array of 'count' length
	int count = 0;

	//This will not work in cinder
	//cout << "Count is: " << count << endl;

	do {
		//To get each line's identifier, x value, and y value
		Entry entry;
		getline(inStream, line, ',');
		count++;
		//Needs to be !inStream, because if it there was no 'not' then it would stop on the first iteration... dealt with that for a bit
	} while(!inStream.eof());


	//This will not work in cinder
	//cout << "Count is: " << count << endl;

	Entry* data = new Entry [count];

	//Restart the input stream at the beginning

	ifstream newStream("../Resources/Starbucks_2006.csv");

	for (int i = 0; i < count; i++){
		//To get each line's identifier, x value, and y value
		Entry entry;
		getline(newStream, line, ',');
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

	
	//create a beilcaStarbucks and build a regular array...(tried K-D many times with 0 success)
	beilcaStarbucks* starbucks = new beilcaStarbucks();
	starbucks->build(data, count);	

	Entry* nearestStarbucks = starbucks->getNearest(0.534987, .1283099);


	HW04_beilcaApp::console() << "Closest Starbucks is located here: " << nearestStarbucks->identifier << std::endl;

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

	//BLEHH I can't get anything to work..
	//gl::drawString	("hello", Vec2f & (0,0,0,0), ColorA & 	color = ColorA( 1, 1, 1, 1 ), Font 	font = Font());	

}

CINDER_APP_BASIC( HW04_beilcaApp, RendererGl )
