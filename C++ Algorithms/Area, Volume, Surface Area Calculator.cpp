/*********************************************************************************************
This program calculates all of the following with the correctly entered information

Perimeter:          Area:               Surface Area:           Volume:

Square              Square              Cube                    Cube
Rectangle           Rectangle           Sphere                  Rectangular Prism
Parallelogram       Parallelogram       Cylinder                Sphere
Triangle            Triangle            Cone                    Ellipsoid
Regular n-Polygon   Regular n-Polygon   Torus                   Cylinder
Trapezoid           Trapezoid           Pyramid                 Cone
Circle              Circle              Ellipsoid               Pyramid
Ellipse             Ellipse             Rectangular Prism       Torus
Sector              Sector

To add another category:
    1. add it to the list above
    2. go to the "Constants" section
    3. change NUM_CATEGORIES as necessary
    4. change CATEGORIES as necessary
    5. add a new case to switch(firstVal) at approximately line 91

To add another shape within a category:
    1. add it to the list above
    2. go to the "Constants" section
    3. change the appropriate NUM_OPS (number of shapes in a category) value to reflect the addition
    4. change the appropriate OPS (name of shapes in a category) value to reflect the addition
    5. add a new case to one of the switch(secVal) within switch(firstVal) at approximately line 91
    6. create a method that runs the calculations
**********************************************************************************************/

/***************************************Libraries*********************************************/
#include<iostream>
    using std::cout;
    using std::cin;

#include <math.h>

/***************************************Constants*********************************************/
const int NUM_CATEGORIES = 4;
const int NUM_PERIM_OPS = 9;
const int NUM_AREA_OPS = 9;
const int NUM_SA_OPS = 8;
const int NUM_VOL_OPS = 8;

const char CATEGORIES[NUM_CATEGORIES][25] = {"1. Perimeter", "2. Area", "3. Surface Area", "4. Volume"};
const char PERIM_OPS[NUM_PERIM_OPS][25] = {"1. Circle", "2. Ellipse", "3. Parallelogram", "4. Rectangle", "5. Regular n-Polygon",
                                         "6. Sector", "7. Square", "8. Trapezoid", "9. Triangle"};
const char AREA_OPS[NUM_AREA_OPS][25] = {"1. Circle", "2. Ellipse", "3. Parallelogram", "4. Rectangle", "5. Regular n-Polygon",
                                         "6. Sector", "7. Square", "8. Trapezoid", "9. Triangle"};
const char SA_OPS[NUM_SA_OPS][25] = {"1. Cone", "2. Cube", "3. Cylinder", "4. Ellipsoid", "5. Pyramid",
                                     "6. Rectangular Prism", "7. Sphere", "8. Torus"};
const char VOL_OPS[NUM_VOL_OPS][25] = {"1. Cone", "2. Cube", "3. Cylinder", "4. Ellipsoid", "5. Pyramid",
                                     "6. Rectangular Prism", "7. Sphere", "8. Torus"};
const float PI = 3.14159265;
/**********************************Function Prototypes****************************************/
//user input methods
int firstOption();
int secondOption( int calcVal, char* calcOpt, int calcNum );

//perimeter calculation methods
void circlePerim();
void ellipsePerim();
void parallelogramPerim();
void rectanglePerim();
void regularPolygonPerim();
void sectorPerim();
void squarePerim();
void trapezoidPerim();
void trianglePerim();

//area calculation methods
void circleArea();
void ellipseArea();
void parallelogramArea();
void rectangleArea();
void regularPolygonArea();
void sectorArea();
void squareArea();
void trapezoidArea();
void triangleArea();

//surface area calculation methods
void coneSA();
void cubeSA();
void cylinderSA();
void ellipsoidSA();
void pyramidSA();
void rectangularPrismSA();
void sphereSA();
void torusSA();

//volume calculation methods
void coneVol();
void cubeVol();
void cylinderVol();
void ellipsoidVol();
void pyramidVol();
void rectangularPrismVol();
void sphereVol();
void torusVol();

/*********************************************************************************************
main

Introduces user to the program. Calls methods that get user input and perform calculations.

**********************************************************************************************/
int main()
{
    int firstVal = 0, secVal = 0, numOpts = 0;
    char* firstOpt = "";

    cout << "This program calculates perimeters, areas, surface areas and volumes of various shapes.\n";

    //determine category
    firstVal = firstOption();

    switch( firstVal )
    {
        case 1: firstOpt = "perimeter";
                numOpts = NUM_PERIM_OPS;
            break;
        case 2: firstOpt = "area";
                numOpts = NUM_AREA_OPS;
            break;
        case 3: firstOpt = "surface area";
                numOpts = NUM_SA_OPS;
            break;
        case 4: firstOpt = "volume";
                numOpts = NUM_VOL_OPS;
            break;
    }//switch

    //determine shape within category
    secVal = secondOption( firstVal, firstOpt, numOpts );
    cout << "\n";

    //choose the correct option so the user can input further info and get a result
    switch( firstVal )
    {
        //perimeter
        case 1:
            switch(secVal)
            {
                case 1: circlePerim();
                    break;
                case 2: ellipsePerim();
                    break;
                case 3: parallelogramPerim();
                    break;
                case 4: rectanglePerim();
                    break;
                case 5: regularPolygonPerim();
                    break;
                case 6: sectorPerim();
                    break;
                case 7: squarePerim();
                    break;
                case 8: trapezoidPerim();
                    break;
                case 9: trianglePerim();
                    break;
            }//switch
            break;

        //area
        case 2:
            switch(secVal)
            {
                case 1: circleArea();
                    break;
                case 2: ellipseArea();
                    break;
                case 3: parallelogramArea();
                    break;
                case 4: rectangleArea();
                    break;
                case 5: regularPolygonArea();
                    break;
                case 6: sectorArea();
                    break;
                case 7: squareArea();
                    break;
                case 8: trapezoidArea();
                    break;
                case 9: triangleArea();
                    break;
            }//switch
            break;

        //Surface Area
        case 3:
            switch(secVal)
            {
                case 1: coneSA();
                    break;
                case 2: cubeSA();
                    break;
                case 3: cylinderSA();
                    break;
                case 4: ellipsoidSA();
                    break;
                case 5: pyramidSA();
                    break;
                case 6: rectangularPrismSA();
                    break;
                case 7: sphereSA();
                    break;
                case 8: torusSA();
                    break;
            }//switch
            break;

        //volume
        case 4:
            switch(secVal)
            {
                case 1: coneVol();
                    break;
                case 2: cubeVol();
                    break;
                case 3: cylinderVol();
                    break;
                case 4: ellipsoidVol();
                    break;
                case 5: pyramidVol();
                    break;
                case 6: rectangularPrismVol();
                    break;
                case 7: sphereVol();
                    break;
                case 8: torusVol();
                    break;
            }//switch
            break;
    }//switch

}//end main

/**************************************************************************************
firstOption

presents user a menu to determine the category under which he wants a shape calculations

returns: val (the value associated with the category)
***************************************************************************************/
int firstOption()
{
    int val = 0;

    do
    {
        cout << "\n";
        cout << "Choose a category from below.\n";
        for(int x = 0; x < NUM_CATEGORIES; x++)
            cout << CATEGORIES[x] << "\n";
        cin >> val;

        if( val < 1 || val > NUM_CATEGORIES )
            cout << "Invalid choice. Choose again.\n";

    }while( val < 1 || val > NUM_CATEGORIES );

    return val;

}//end firstOption

/**************************************************************************************
secondOption

presents user a menu so they can pick a shape option within the previously selected catgory

input parameters: calcVal - the number associated with the user selected category
                  calcOpt - the name of the category
                  calcNum - the number of shapes within the user selected category

returns: val - the number associated with the shape within the user selected category
***************************************************************************************/
int secondOption( int calcVal, char* calcOpt, int calcNum )
{
    int val = 0;

    do
    {
        cout << "\nChoose a(n) " << calcOpt << " option from below.\n";

        switch( calcVal )
        {
            case 1: for(int x = 0; x < calcNum; x++)
                        cout << PERIM_OPS[x] << "\n";
                break;
            case 2: for(int x = 0; x < calcNum; x++)
                        cout << AREA_OPS[x] << "\n";
                break;
            case 3: for(int x = 0; x < calcNum; x++)
                        cout << SA_OPS[x] << "\n";
                break;
            case 4: for(int x = 0; x < calcNum; x++)
                        cout << VOL_OPS[x] << "\n";
                break;
        }//switch

        cin >> val;

        if( val < 1 || val > calcNum )
            cout << "Invalid choice. Choose again.\n";

    }while( val < 1 || val > calcNum );

    return val;

}//end perOption

/*************************************Perimeter Equations************************************/
void circlePerim()
{
    float r, per;

    cout << "The perimeter of a circle is: pi*diameter or 2*pi*radius.\n";
    cout << "Enter the value for radius: ";
    cin >> r;

    per = 2 * PI * r;

    cout << "The perimeter is: " << per << "\n\n";
}//circlePerim

void ellipsePerim()
{
    float a, b, h, per;

    cout << "An ellipse has a major axis(a) and minor axis(b).\n";
    cout << "Enter the length of the major axis(a): ";
    cin >> a;
    cout << "Enter the length of the minor axis(b): ";
    cin >> b;

    a = a/2;
    b = b/2;
    h = (a-b)*(a-b);
    h = h/((a+b)*(a+b));
    per = PI*(a+b)*(1+(h/4)+((h*h)/64)+((h*h*h)/256)+((25*h*h*h*h)/16384));

    cout << "The perimeter is approximately: " << per << "\n\n";

}//ellipsePerim

void parallelogramPerim()
{
    float w, h, per;

    cout << "The perimeter of a parallelogram is: 2*width + 2*height.\n";
    cout << "Enter the value for the width: ";
    cin >> w;
    cout << "Enter the value for the height: ";
    cin >> h;

    per = 2*w + 2*h;

    cout << "The perimeter is: " << per << "\n\n";
}//parallelogramPerim

void rectanglePerim()
{
    float w, h, per;

    cout << "The perimeter of a rectangle is: 2*width + 2*height.\n";
    cout << "Enter the value for the width: ";
    cin >> w;
    cout << "Enter the value for the height: ";
    cin >> h;

    per = 2*w + 2*h;

    cout << "The perimeter is: " << per << "\n\n";

}//rectanglePerim

void regularPolygonPerim()
{
    float n, s, per;

    cout << "The perimeter of a regular polygon is: n*side.\n";
    cout << "Enter the number of sides(n): ";
    cin >> n;
    cout << "Enter the length of the side: ";
    cin >> s;

    per = n*s;

    cout << "The perimeter is: " << per << "\n\n";

}//regularPolygonPerim

void sectorPerim()
{
    float r, a, per;
    int opt;

    cout << "The perimeter of a sector of a circle has two equations:\n";
    cout << "If the angle is in radians: 2*radius + radius*angle \n";
    cout << "If the angle is in degrees: 2*radius + (angle/360)*2*pi*radius\n";

    cout << "Enter the value for the radius: ";
    cin >> r;
    cout << "\n";

    do
    {
        cout << "1. radians\n";
        cout << "2. degrees\n";
        cout << "Choose an angle measure: ";
        cin >> opt;
        cout << "\n";
    }while( opt < 1 || opt > 2);

    cout << "Enter the value for the angle: ";
    cin >> a;
    cout << "\n";

    switch( opt )
    {
        case 1: per = 2*r + r*a;
            break;
        case 2: per = 2*r + (a/360)*2*PI*r;
            break;
    }//switch

    cout << "The perimeter is: " << per << "\n\n";

}//sectorPerim

void squarePerim()
{
    float s, per;

    cout << "The perimeter of a square is: 4*side.\n";
    cout << "Enter the value for the side: ";
    cin >> s;

    per = 4*s;

    cout << "The perimeter is: " << per << "\n\n";
}//squarePerim

void trapezoidPerim()
{
    float s1, s2, s3, s4, per;

    cout << "The perimeter of a trapezoid is: side1 + side2 + side3 + side4.\n";
    cout << "Enter the value for side1: ";
    cin >> s1;
    cout << "Enter the value for side2: ";
    cin >> s2;
    cout << "Enter the value for side3: ";
    cin >> s3;
    cout << "Enter the value for side4: ";
    cin >> s4;

    per = s1 + s2 + s3 + s4;

    cout << "The perimeter is: " << per << "\n\n";

}//trapezoidPerim

void trianglePerim()
{
    float s1, s2, s3, per;

    cout << "The perimeter of a triangle is: side1 + side2 + side3.\n";
    cout << "Enter the value for side1: ";
    cin >> s1;
    cout << "Enter the value for side2: ";
    cin >> s2;
    cout << "Enter the value for side3: ";
    cin >> s3;

    per = s1 + s2 + s3;

    cout << "The perimeter is: " << per << "\n\n";

}//trianglePerim

/****************************************Area Equations************************************/
void circleArea()
{
    float r, area;

    cout << "The area of a circle is: PI*r*r.\n";
    cout << "Enter the value for the radius(r): ";
    cin >> r;

    area = PI*r*r;

    cout << "The area is: " << area << "\n\n";

}//circleArea

void ellipseArea()
{
    float a, b, h, area;

    cout << "An ellipse has a major axis(a) and minor axis(b).\n";
    cout << "Enter the length of the major axis(a): ";
    cin >> a;
    cout << "Enter the length of the minor axis(b): ";
    cin >> b;

    a = a/2;
    b = b/2;
    area = PI * a * b;

    cout << "The area is approximately: " << area << "\n\n";

}//ellipseArea

void parallelogramArea()
{
    float b, h, area;

    cout << "The area of a parallelogram is: base*height.\n";
    cout << "Enter the value for the base: ";
    cin >> b;
    cout << "Enter the value for the height: ";
    cin >> h;

    area = b*h;

    cout << "The area is: " << area << "\n\n";
}//parallelogramArea

void rectangleArea()
{
    float w, h, area;

    cout << "The area of a rectangle is: width*height.\n";
    cout << "Enter the value for the width: ";
    cin >> w;
    cout << "Enter the value for the height: ";
    cin >> h;

    area = w*h;

    cout << "The area is: " << area << "\n\n";
}//rectangleArea

void regularPolygonArea()
{
    float s, n, area;
    int opt;

    do
    {
        cout << "1. Use the length of a side.\n";
        cout << "2. Use the radius (center to vertex).\n";
        cout << "3. Use the apothem (center to side).\n";
        cout << "Choose an option: ";
        cin >> opt;

    }while( opt < 1 || opt > 3 );

    cout << "Enter the number of sides: ";
    cin >> n;

    switch( opt )
    {
        case 1:
            cout << "Enter the value for the side: ";
            cin >> s;
            area = 0.25*s*s*n/(tan(PI/n));
            break;
        case 2:
            cout << "Enter the value for the radius: ";
            cin >> s;
            area = 0.5*s*s*n*(sin((2*PI)/n));
            break;
        case 3:
            cout << "Enter the value for the apothem: ";
            cin >> s;
            area = s*s*n*(tan(PI/n));
            break;
    }//switch

    cout << "The area is: " << area << "\n\n";

}//regularPolygonArea

void sectorArea()
{
    float r, a, area;
    int opt;

    cout << "The area of a sector of a circle has two equations:\n";
    cout << "If the angle is in radians: PI*r*r*(angle/2*PI) \n";
    cout << "If the angle is in degrees: PI*r*r*(angle/360)\n";

    cout << "Enter the value for the radius(r): ";
    cin >> r;
    cout << "\n";

    do
    {
        cout << "1. radians\n";
        cout << "2. degrees\n";
        cout << "Choose an angle measure: ";
        cin >> opt;
        cout << "\n";
    }while( opt < 1 || opt > 2);

    cout << "Enter the value for the angle: ";
    cin >> a;
    cout << "\n";

    switch( opt )
    {
        case 1: area = 0.5*r*r*a;
            break;
        case 2: area = PI*r*r*(a/360);
            break;
    }//switch

    cout << "The area is: " << area << "\n\n";
}//sectorArea

void squareArea()
{
    float s, area;

    cout << "The area of a square is: side*side.\n";
    cout << "Enter the value for the side: ";
    cin >> s;

    area = s*s;

    cout << "The area is: " << area << "\n\n";
}//squareArea

void trapezoidArea()
{
    float b1, b2, h, area;

    cout << "The area of a trapezoid is: height*((base1+base2)/2).\n";
    cout << "Enter the value for base1: ";
    cin >> b1;
    cout << "Enter the value for base2: ";
    cin >> b2;
    cout << "Enter the value for the height: ";
    cin >> h;

    area = h*((b1+b2)/2);

    cout << "The area is: " << area << "\n\n";

}//trapezoidArea

void triangleArea()
{
    float b, h, area;

    cout << "The area of a triangle is: 0.5*base*height.\n";
    cout << "Enter the value for the base: ";
    cin >> b;
    cout << "Enter the value for the height: ";
    cin >> h;

    area = 0.5*b*h;

    cout << "The area is: " << area << "\n\n";
}//triangleArea

/***********************************Surface Area Equations************************************/
void coneSA()
{
    float r, h, s, area;

    cout << "The surface area of a cone is: PI*radius*side + PI*radius^2.\n";
    cout << "Enter the value for the radius: ";
    cin >> r;
    cout << "Enter the value for the height: ";
    cin >> h;
    cout << "Enter the value for the side: ";
    cin >> s;

    area = PI*r*s + PI*r*r;

    cout << "The surface area is: " << area << "\n\n";

}//coneSA

void cubeSA()
{
    float s, area;

    cout << "The surface area of a cube is: 6*side*side.\n";
    cout << "Enter the value for the side: ";
    cin >> s;

    area = 6*s*s;

    cout << "The surface area is: " << area << "\n\n";

}//cubeSA

void cylinderSA()
{
    float r, h, area;

    cout << "The surface area of a cylinder is: 2*PI*radius^2 + 2*PI*radius*height.\n";
    cout << "Enter the value for the radius: ";
    cin >> r;
    cout << "Enter the value for the height: ";
    cin >> h;

    area = 2*PI*r*r + 2*PI*r*h;

    cout << "The surface area is: " << area << "\n\n";

}//cylinderSA

void ellipsoidSA()
{


}//ellipsoidSA

void pyramidSA()
{
    float b, s, area;

    cout << "The surface area of a pyramid is: 2*base*side + base*base.\n";
    cout << "Enter the value for the base: ";
    cin >> b;
    cout << "Enter the value for the side: ";
    cin >> s;

    area = 2*b*s + b*b;

    cout << "The surface area is: " << area << "\n\n";
}//pyramidSA

void rectangularPrismSA()
{
    float l, w, h, area;

    cout << "The surface area of a rectangular prism is: 2(w*h + l*w + l*h).\n";
    cout << "Enter the value for the length: ";
    cin >> l;
    cout << "Enter the value for the width: ";
    cin >> w;
    cout << "Enter the value for the height: ";
    cin >> h;

    area = 2*(w*h + l*w + l*h);

    cout << "The surface area is: " << area << "\n\n";

}//rectangularPrismSA

void sphereSA()
{
    float r, area;

    cout << "The surface area of a sphere is: 4*PI*radius^2.\n";
    cout << "Enter the value for the radius: ";
    cin >> r;

    area = 4*PI*r*r;

    cout << "The surface area is: " << area << "\n\n";

}//sphereSA

void torusSA()
{

}//torusSA

/****************************************Volume Equations************************************/
void coneVol()
{

}//coneVol

void cubeVol()
{

}//cubeVol

void cylinderVol()
{

}//cylinderVol

void ellipsoidVol()
{

}//ellipsoidVol

void pyramidVol()
{

}//pyramidVol

void rectangularPrismVol()
{

}//rectangularPrismVol

void sphereVol()
{

}//sphereVol

void torusVol()
{

}//torusVol
