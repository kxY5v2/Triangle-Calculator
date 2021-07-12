/*
  WELCOME TO THE TRIANGLE CALCULATOR!
  IT CAN DO THE FOLLOWING:
    FIND A SIDE:
      RIGHT TRIANGLE:
        SIDE 1 - GIVEN SIDE 2 & HYPOTENUSE
        SIDE 2 - GIVEN SIDE 1 & HYPOTENUSE
        HYPOTENUSE - GIVEN SIDE 1 & SIDE 2
      EQUILATERAL TRIANGLE:
        ALL SIDES - GIVEN 1 SIDE
      ISOSCELES TRIANGLE:
        SIDE 1 - GIVEN SIDE 2 & ALTITUDE
        SIDE 2 - GIVEN SIDE 1 & SIDE 2
        ALTITUDE - GIVEN SIDE 1 & SIDE 2
    FIND THE AREA:
      RIGHT TRIANGLE - GIVEN SIDE 1 & SIDE 2
      EQUILATERAL TRIANGE - GIVEN 1 SIDE
      ISOSCELES TRIANGLE - GIVEN SIDE 2 & ALTITUDE
    FIND PERIMETER:
      RIGHT TRIANGLE - GIVEN SIDE 1 & SIDE 2
      EQUILATERAL TRIANGLE - GIVEN 1 SIDE
      ISOSCELES TRIANGLE - GIVEN SIDE 1 & SIDE 2
*/

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <windows.h>
using namespace std;

// TRIANGLE SIDES:
  double side1, side2, side3, sideH, sideX;
// TRIANGLE AREA:
  double thearea;
// TRIANGLE TYPE:
  int type;
  // (1) = RIGHT
  // (2) = EQUILATERAL
  // (3) = ISOSCELES
// MENU CHOICES:
  int menuChoice, typeChoice;

// DRAW MENUS: -----------------------------------------------------------------
// DRAW  MAIN MENU: ============================================================
void drawMenu()
{
  cout << "|----------------------------------|" << endl;
  cout << "|  /\\                       /\\     |" << endl;
  cout << "| /  \\ Triangle Calculator /  \\    |" << endl;
  cout << "|/____\\                   /____\\   |" << endl;
  cout << "|__________________________________|" << endl;
  cout << "|             MAIN MENU            |" << endl;
  cout << "|__________________________________|" << endl;
  cout << "| [1] FIND A SIDE                  |" << endl;
  cout << "| [2] CALCULATE THE AREA           |" << endl;
  cout << "| [3] CALCULATE THE PERIMETER      |" << endl;
  cout << "| [4] QUIT                         |" << endl;
  cout << "|__________________________________|" << endl;
}
// DRAW TRIANGLE MENU: =========================================================
void drawTriangleMenu()
{
  cout << "|----------------------------------|" << endl;
  cout << "|  /\\                       /\\     |" << endl;
  cout << "| /  \\ Triangle Calculator /  \\    |" << endl;
  cout << "|/____\\                   /____\\   |" << endl;
  cout << "|__________________________________|" << endl;
  cout << "|          TRIANGLE MENU           |" << endl;
  cout << "|__________________________________|" << endl;
  cout << "| [ ] WHAT KIND OF TRIANGLE?       |" << endl;
  cout << "| [1] RIGHT                        |" << endl;
  cout << "| [2] EQUILATERAL                  |" << endl;
  cout << "| [3] ISOSCELES                    |" << endl;
  cout << "| [4] BACK                         |" << endl;
  cout << "|__________________________________|" << endl;
}
//------------------------------------------------------------------------------

// DRAW TRIANGLES: -------------------------------------------------------------
// DRAW RIGHT TRIANGLE: ========================================================
void drawRight()
{
  cout << "       |\\" << endl;
  cout << "       | \\" << endl;
  cout << "Side 1 |  \\   Hypotenuse" << endl;
  cout << "       |   \\" << endl;
  cout << "       |_   \\" << endl;
  cout << "       | |   \\" << endl;
  cout << "       ========" << endl;
  cout << "        Side 2" << endl;
  cout << endl;
}
// DRAW EQUILATERAL TRIANGLE: ==================================================
void drawEquilateral()
{
  cout << "         /\\" << endl;
  cout << "        /--\\"<< endl;
  cout << "Side   /    \\   Side " << endl;
  cout << "      /      \\" << endl;
  cout << "     /        \\" << endl;
  cout << "    /\\________/\\" << endl;
  cout << "        Side " << endl;
  cout << endl;
}
// DRAW ISOSCELES TRIANGLE: ====================================================
void drawIsosceles()
{
  cout << "           ^ " << endl;
  cout << "          /|\\" << endl;
  cout << "         / | \\ " << endl;
  cout << "Side 1  /  |<-\\---Altitude" << endl;
  cout << "       /   |   \\" << endl;
  cout << "      /    |    \\" << endl;
  cout << "     <)---------(>" << endl;
  cout << "         Side 2" << endl;
  cout << endl;
}
//------------------------------------------------------------------------------

// LOGIC:-----------------------------------------------------------------------
// RESET - SET VARIABLES TO 0:
void Reset()
{
  side1 = side2 = side3 = sideH = thearea = 0;
}
// BACK - TRIANGLE MENU [4] OPTION:
void Back(){
  Reset();
  system("cls");
}
//------------------------------------------------------------------------------

// RIGHT TRIANGLE LOGIC: -------------------------------------------------------
// FIND SIDE 1: ================================================================
double findSide1Right(double side2, double sideH)
{
  side1 = sqrt(pow(sideH,2) - pow(side2,2));
  return side1;
}
// FIND SIDE 2: ================================================================
double findSide2Right(double side1, double sideH)
{
  side2 = sqrt(pow(sideH,2) - pow(side1,2));
  return side2;
}
// FIND SIDE HYPOTENUSE: =======================================================
double findHypotenuse(double side1, double side2)
{
  sideH = sqrt(pow(side1,2) + pow(side2,2));
  return sideH;
}
//------------------------------------------------------------------------------

// ISOSCELES TRIANGLE LOGIC: ---------------------------------------------------
// FIND SIDE 1: ================================================================
double findSide1Isos(double side2, double sideH)
{
  // sqrt(hypotenuse^2 - base/2^2)
  side2 = side2/2;
  side1 = sqrt(pow(sideH,2) + pow(side2,2));
  return side1;
}
// FIND SIDE 2: ================================================================
double findSide2Isos(double side1, double sideH)
{
  // use pythagorean theorem to find side/2
  side2 = (2 * findSide2Right(side1, sideH));
  return side2;
}
// FIND ALTITUDE: ==============================================================
double findAltitude(double side1, double side2)
{
  // H = altitude
  side2 = side2/2;
  sideH = sqrt(pow(side1,2) - pow(side2,2));
  return sideH;
}
//------------------------------------------------------------------------------

// MATHEMATICAL LOGIC: ---------------------------------------------------------
// RIGHT / ISOSCELES TRIANGLE AREA: ============================================
double calcArea(double height, double base)
{
  side1 = height;
  side2 = base;
  thearea =(base*height)/2;
  return thearea;
}
// EQUILATERAL TRIANGLE AREA: ==================================================
double calcAreaEQ(double side1)
{
  double x = (sqrt(3)/4);
  thearea = (x * pow(side1,2));
  return thearea;
}
//------------------------------------------------------------------------------

// INPUT: ----------------------------------------------------------------------
// MAIN MENU INPUT: ============================================================
void menuInput()
{
  cout << "| ";
  cin >> menuChoice;
}
// TYPE MENU INPUT: ============================================================
void typeInput()
{
  cout << "| ";
  cin >> typeChoice;
}
// FIND A SIDE - RIGHT TRIANGLE INPUT: =========================================
void sideInputRight()
{
  cout << "Find: Side1 (1), Side2 (2), or Hypotenuse (3): ";
  cin >> sideX;
}
// FIND A SIDE - ISOSCELES TRIANLE INPUT: ======================================
void sideInputIsosceles()
{
  cout << "Find: Side1 (1), Side2 (2), or Altitude (3): ";
  cin >> sideX;
}
// FIND PERIMETER - ANY TRIANGLE TYPE INPUT: ===================================
void enterSides()
{
  cout << "Enter Side 1: ";
  cin >> side1;
  cout << "Enter Side 2: ";
  cin >> side2;
}
//------------------------------------------------------------------------------

// FIND A SIDE: ----------------------------------------------------------------
void findASide()
{
  // RIGHT TRIANGLE: ===========================================================
  if (menuChoice == 1 && typeChoice ==1)
  {
    // DRAW RIGHT TRIANGLE:
      drawRight();
    // CHOSE SIDE TO FIND:
      sideInputRight();
    // FIND SIDE 1: ############################################################
    if (sideX==1)
    {
      cout << "Enter Side2: ";
      cin >> side2;
      cout << "Enter Hypotenuse: ";
      cin >> sideH;
      cout << "Side1: " << findSide1Right(side2, sideH) << endl;
    }
    // FIND SIDE 2: ############################################################
    else if (sideX==2)
    {
      cout << "Enter Side1: ";
      cin >> side1;
      cout << "Enter Hypotenuse: ";
      cin >> sideH;
      cout << "Side2: " << findSide2Right(side1, sideH) << endl;
    }
    // FIND HYPOTENUSE: ########################################################
    else if (sideX==3)
    {
      cout << "Enter Side1: ";
      cin >> side1;
      cout << "Enter Side2: ";
      cin >> side2;
      cout << "Hypotenus: " << findHypotenuse(side1,side2) << endl;
    }
    // INVALID INPUT: ##########################################################
    else {
      sideInputRight();
    }
  }
  // EQUILATERAL: ==============================================================
  else if (menuChoice == 1 && typeChoice == 2)
  {
    drawEquilateral();
    // FIND 1 SIDE: #############################################################
    cout << "Enter a Side: ";
    cin >> side1;
    cout << "In an Equilateral Triangle, all side lengths are the same so..." << endl;
    cout << "Sides: " << side1 << endl;
  }
  // ISOSCELES: ================================================================
  else if (menuChoice == 1 && typeChoice == 3)
  {
    drawIsosceles();
    sideInputIsosceles();
    // FIND SIDE 1: ############################################################
    if (sideX==1)
    {
      cout << "Enter Side2: ";
      cin >> side2;
      cout << "Enter Altitude: ";
      cin >> sideH;
      cout << "Side1: " << findSide1Isos(side2, sideH) << endl;
    }
    // FIND SIDE 2: ############################################################
    else if (sideX==2)
    {
      // Side1 = hypotenuse in this case
      cout << "Enter Side1: ";
      cin >> sideH;
      cout << "Enter Altitude: ";
      cin >> side1;
      cout << "Side2: " << findSide2Isos(side1, sideH) << endl;
    }
    // FIND ALTITUDE: ##########################################################
    else if (sideX==3)
    {
      cout << "Enter Side1: ";
      cin >> side1;
      cout << "Enter Side2: ";
      cin >> side2;
      cout << "Altitude: " << findAltitude(side1, side2) << endl;
    }
    // INVALID INPUT : #########################################################
    else
    {
      sideInputIsosceles();
    }
  }
  // BACK: =====================================================================
  else if (menuChoice == 1 && typeChoice == 4)
  {
    Back();
  }
  // INVALID INPUT: ============================================================
  else
  {
    findASide();
  }
}
//------------------------------------------------------------------------------

// FIND AREA: ------------------------------------------------------------------
void findArea()
{
  // RIGHT TRIANGLE: ###########################################################
  if (menuChoice==2 && typeChoice==1)
  {
    drawRight();
    cout << "Enter Side1: ";
    cin >> side1;
    cout << "Enter Side2: ";
    cin >> side2;
    cout << "Area: " << calcArea(side1,side2) << endl;
  }
  // EQUILATERAL TRIANGE: ######################################################
  else if (menuChoice==2 && typeChoice==2)
  {
    drawEquilateral();
    cout << "Enter Side: ";
    cin >> side1;
    cout << "Area: " << calcAreaEQ(side1) << endl;
  }
  // ISOSCELES TRIANGE: ########################################################
  else if (menuChoice==2 && typeChoice==3)
  {
    drawIsosceles();
    cout << "Enter Side2: ";
    cin >> side2;
    cout << "Enter the Altitude: ";
    cin >> sideH;
    cout << "Area: " << calcArea(side2,sideH) << endl;
  }
  // BACK: #####################################################################
  else if (menuChoice==2 && typeChoice==4)
  {
    Back();
  }
  // INVALID INPUT: ############################################################
  else{
    findArea();
  }
}
//------------------------------------------------------------------------------

// FIND PERIMETER:--------------------------------------------------------------
void findPerimeter()
{
  // RIGHT TRIANGLE: ===========================================================
  if (menuChoice == 3 && typeChoice == 1)
  {
    drawRight();
    enterSides();
    //cout << "Enter Hypotenus: ";
    //cin >> sideH;
    findHypotenuse(side1,side2);
    cout << "Perimeter: " << (side1 + side2 + sideH) << endl;
  }
  // EQUILATERAL TRIANGLE: =====================================================
  else if (menuChoice == 3 && typeChoice == 2)
  {
    drawEquilateral();
    cout << "Enter Side: ";
    cin >> side1;
    cout << "Perimeter: " << (side1 * 3) << endl;
  }
  // ISOSCELES TRIANGLE: =======================================================
  else if (menuChoice == 3 && typeChoice == 3)
  {
    drawIsosceles();
    enterSides();
    cout << "Perimeter: " << ((side1 * 2) + side2) << endl;
  }
}
//------------------------------------------------------------------------------

// QUIT: -----------------------------------------------------------------------
void Quit()
{
  if (menuChoice == 4)
  {
    system("cls");
    cout << "GOODBYE!";
    abort();
  }
}
// MAIN: -----------------------------------------------------------------------
int main()
{
  while(1)
  {
    system("cls");
    drawMenu();
    menuInput();
    if (menuChoice == 4)
      Quit();
    system("cls");
    drawTriangleMenu();
    typeInput();
    if (menuChoice == 1)
      findASide();
    else if (menuChoice == 2)
      findArea();
    else if (menuChoice == 3)
      findPerimeter();
    else
    {
      drawMenu();
      menuInput();
      system("cls");
    }
    system("pause"); // wont be able to see answer if not.
    Reset();
  }
  return 0;
}
//------------------------------------------------------------------------------

// NOTES:-----------------------------------------------------------------------
/*
PROBLEMS:
  BACK OPTION NOT WORKING - RESOLVED!
  CAN ONLY DO ONE MENU OPTION IN MAIN - RESOLVED!
*/
//==============================================================================
/*
TODO:
  TODO: FIX PROBLEMS
  TODO: CALCULATE PERIMETER - DONE
  TODO: QUIT - DONE
  TODO: TEST FUNCIONS - DONE
  TODO: FINAL TEST - DONE
  TODO: CHANGE EQUILATERAL TRIANGLE TO SAY SIDE INSTEAD OF SIDE1 - DONE
  // POSIBLY ADD SCALENE TRIANGLE
  // COULD TURN ADD TO BIGGER PROJECT WITH MORE SHAPES
*/
//==============================================================================
/*
TESTS:
  FIND A SIDE - CHECK
  FIND AREA - CHECK
  FIND PERIMETER - CHECK
  QUIT - CHECK
*/
//------------------------------------------------------------------------------
