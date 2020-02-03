/*
 * project1.cpp
 *
 *  Created on: Feb 2, 2020
 *      Author: Parker Williams
 */

#include <iostream>
using namespace std;
//define all your classes here (as given above)
//write the methods after the class definition (not inside the class
//definition, see above in the Intervals class

class Point {
protected:
	double x; //x coordinate value
	double y; //y coordinate value
public:
	Point(); //default constructor; x = 0.0 and y = 0.0
	Point(double xvalue, double yvalue); //no-default constructor
	void setLocation(double xvalue, double yvalue);// set x = xvalue and
	// y = yvalue
	double getXValue(); //return x
	double getYValue(); //return y
	void display(); // Print (0.0, 0.0)
	//other methods that are necessary
};
//The following are the constructors for the Point class
Point::Point(){
	x = 0.0;
	y = 0.0;
}
Point::Point(double xvalue, double yvalue){
	x = xvalue;
	y = yvalue;
}
//This method changes the location of the Point
void Point::setLocation(double xvalue, double yvalue){
	x = xvalue;
	y = yvalue;
}
//This method returns the x coordinate of the point
double Point::getXValue(){
	return x;
}
//This method returns the y coordinate of the point
double Point::getYValue(){
	return y;
}
//This method prints the Point
void Point::display(){
	cout << "(" << x << ", " << y << ")" << endl;
}

class LineSegment {
protected:
	Point P1;
	Point P2;
public:
	LineSegment(); //default constructor
	LineSegment(Point one, Point two);
	double length(); //return the length of the line segment
	Point midpoint(); //return the midpoint of the line segment
	Point xIntercept(); //return the x-intercept of the line segment
	Point yIntercept(); //return the y-intercept of the line segment
	double slope(); //return the slope of the line segment
	bool itIntersects(LineSegment L); //returns true if L intersects
	//with this line segment
	Point intersectionPoint(LineSegment L);
	bool isParallel(LineSegment L); //check if slopes are same
	void displayEquation(); // you will print in the format
	// y = m * x + c where m is the slope
	// and c is the y-intercept
	//other methods that are necessary
	double squareroot(double givenNumber);

};
// The following are the Line Segment class constructors
LineSegment::LineSegment(){
	P1 = NULL;
	P2 = NULL;
}
LineSegment::LineSegment(Point one, Point two){
	P1 = one;
	P2 = two;
}
//Squareroot method finds the squareroot of a given
//SquareRoot method was given through Canvas by TA
double LineSegment::squareroot(double givenNumber){
	double eps = 1e-6;
	double k = givenNumber;
	double l = 0.0, r, mid;

	if (k >= 1) {
		r = k;
	}
	if (k < 1)  {
		r = 1;
	}

	while (l - k / l > eps || l - k / l < -eps)
	{
		mid = l + (r - l) /2 ;
		if (mid<k/mid)
		{
			l = mid;
		}
		else {
			r = mid;
		}
	}
	return l;
}
// length() returns the length of the Line segment using the distance formula
double LineSegment::length(){
	double xSquared = (P1.getXValue() - P2.getXValue()) * (P1.getXValue() - P2.getXValue());
	double ySquared = (P1.getYValue() - P2.getYValue()) * (P1.getYValue() - P2.getYValue());
	double length = squareroot(xSquared + ySquared);
	return length;
}
// midpoint() returns the midpoint of the line segment
Point LineSegment::midpoint(){
	double xCoordinate = (P1.getXValue() + P2.getXValue()) / 2;
	double yCoordinate = (P1.getYValue() + P2.getYValue()) / 2;
	Point P(xCoordinate, yCoordinate);
	return P;
}
// slope() returns the slope of the line segment
double LineSegment::slope(){
	double slope;
	if(P2.getXValue() == P1.getXValue()){
		slope = NULL; //This is for a vertical line with undefined slope
	}
	else
		slope = (P2.getYValue() - P1.getYValue()) / (P2.getXValue() - P1.getXValue());
	return slope;
}
// xIntercept() finds and returns the line segment's x Intercept
Point LineSegment::xIntercept(){
	double xInterceptCoordinate = P1.getXValue() - (P1.getYValue() * slope());
	Point xIntercept(xInterceptCoordinate, 0);
	return xIntercept;
}
// yIntercept() finds and returns the line segment's y Intercept
Point LineSegment::yIntercept(){
	double yInterceptCoordinate = P1.getYValue() - (P1.getXValue() * slope());
	Point yIntercept(0, yInterceptCoordinate);
	return xIntercept;
}

class Intervals {
protected:
	LineSegment *segments;
	int count;
	int maxSize;
public:
	Intervals(); //segments = NULL; count = 0; maxSize = 0;
	Intervals(int size); //non-default constructor
	void addLineSegment(LineSegment L);
	void display();
	/* display all line segment stored in
	 the y=mx+c format; see display for LineSegment and print points, length,
	 midpoint, x-intercept, y-intercept, for example:
	 Line Segment: 1
	 P1 = (3.0, 9.0); P2 = (8.0, 16.0)
	 slope = 1.4
	 equation = y = 1.4*x + 4.8
	 length = 8.60
	 mid point = (10.5, 12.5)
	 x-intercept = ...
	 y-intercept = ...
	 Line Segment: 2
	 P1 = (...); P2 = (...)
	 slope = ...
	 equation = y = ...
	 length = ...
	 mid point = ...
	 x-intercept = ...
	 y-intercept = ...
	 ...
	 */
};
//some extra help below: in case you need it
Intervals::Intervals() {
	segments = NULL;
	count = 0;
	maxSize = 0;
}
Intervals::Intervals(int size) {
	segments = new LineSegment[size];
	count = 0; //currently there is none
	maxSize = size;
}




int main() {
	//make sure you define all the variables; I have defined ANY
//first line of input contains the number of segments
	cin >> noOfSegments;
	//Go through a loop (noOfSegments times) and read the information about
	// each segment it will be as follows:
	// 2.3 3.5 2.5 8.12
	// 5.13 8.13 9.0 12.8
	//. . .
	//. . .
	//After you read information on each segment you need to create two
	//Point objects, with these Point objects you will next create a
	//LineSegment object and then this LineSegment object is placed in the
	//object you create for Intervals class using the addLineSegment method

	//Next ...
	//Call the display method on the Intervals Object you created
	//Next ...
	//
	/* Determine ALL PAIRS of intersecting Line Segments and print just
	 their position in which they are stored in the array. For example,
	 (0, 8)
	 (0, 14)
	 (0, 32)
	 (1, 11)
	 (1, 6)
	 ...
	 */
}

