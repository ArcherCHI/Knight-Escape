#include <iostream>   // Library Imports
#include <string>

void swapPos(std::string& x, std::string &y){ // Swap Function
  std::string temp = x;
  x = y;
  y = temp;
}

// Variable Declarations
std::string p1, p2, p3, p4, p5;
std::string p6, p7, p8, p9, p10;
std::string p11, p12, p13, p14, p15;
std::string p16, p17, p18, p19, p20;
std::string p21, p22, p23, p24, p25;

const std::string WhiteKnight = "\u2658"; // White Knight character set to string
const std::string BlackKnight = "\u265E"; // Black Knight character set to string
int score = 500;
std::string entry; // User input to choose to continue, retry, or exit
std::string blankPos; 
std::string exitGame;
std::string exitGameX;

bool status = true; 
// std::string p1 = BlackKnight;

int userPosI = 0; // source position
int userPosII = 0; // destination position
int numMoves = 1; // Counter to count moves

void displayWelcomeMessage() { // Welcome Message
  std::cout << "Program 2: Knight Escape \n"
        << "CS 141, Spring 2022, UIC \n"
        << " \n"
        << "The objective of this puzzle is to get the white knight "
    << "up to the empty square in the top right corner of the board. "
    << "Use standard knight moves from a traditional chess game, "
    << "where a knight moves in an L-shape. \n"
    << "This means that a knight can only move either "
    << "1) two squares in a horizontal direction, then one in a vertical direction, OR "
    << "2) two squares in a vertical direction, then one in a horizontal direction."
    << " \n"
    << "Your score decreases by 5 with each valid move, and by 10 with each invalid move. \n"
    << "Try to complete the puzzle with the smallest number of valid moves!"
    << std::endl;
    std::cout << std::endl;
}

void displayMenuOptions(){ // Function to display menu options, increments move counter
  std::cout << numMoves << ". Enter one of the following: \n"; // after each call / move
  std::cout << "- 'M' to move a knight from one position to another, \n";
  std::cout << "- 'R' to reset the board back to the beginning, or \n";
  std::cout << "- 'X' to exit the game. ";
  numMoves++;
}

void displayStarterBoard(){     // sets pieces to default locations

  p1=p2=p3=p4=p6=p7=p8=p9=p10 = BlackKnight;
  p11=p12=p13=p14=p15 = BlackKnight;
  p16=p17=p18=p19=p20 = BlackKnight;
  p22=p23=p24=p25 = BlackKnight;
  p5 = " ";
  p21 = WhiteKnight;

  // Board Layout
  std::cout << std::endl;
  std::cout << " \t   Board   " << "  \t   Position \n";
  
  // FIRST ROW 
  std::cout << " |" << p1 << " |" << p2 << " |" << p3 << " |" << p4 << " |" << p5 << " |" << "     1  2  3  4  5 \n";

  // SECOND ROW
  std::cout << " |" << p6 << " |" << p7 << " |" << p8 << " |" << p9 << " |" << p10 << " |" << "     6  7  8  9 10 \n";
  
  // THIRD ROW
  std::cout << " |" << p11 << " |" << p12 << " |" << p13 << " |" << p14 << " |" << p15 << " |" << "    11 12 13 14 15 \n";
  
  // FOURTH ROW
  std::cout << " |" << p16 << " |" << p17 << " |" << p18 << " |" << p19 << " |" << p20 << " |" << "    16 17 18 19 20 \n";
  
  // FIFTH ROW
  std::cout << " |" << p21 << " |" << p22 << " |" << p23 << " |" << p24 << " |" << p25 << " |" << "    21 22 23 24 25 \n";

  std::cout << std::endl;
  std::cout << "Current Score: " << score << std::endl;
}

void displayBoard(){  // Displays current board with newly chosen locations for pieces

  std::cout << std::endl;
  std::cout << " \t   Board   " << "  \t   Position \n";
  // FIRST ROW 
  std::cout << " |" << p1 << " |" << p2 << " |" << p3 << " |" << p4 << " |" << p5 << " |" << "     1  2  3  4  5 \n";

  // SECOND ROW
  std::cout << " |" << p6 << " |" << p7 << " |" << p8 << " |" << p9 << " |" << p10 << " |" << "     6  7  8  9 10 \n";
  
  // THIRD ROW
  std::cout << " |" << p11 << " |" << p12 << " |" << p13 << " |" << p14 << " |" << p15 << " |" << "    11 12 13 14 15 \n";
  
  // FOURTH ROW
  std::cout << " |" << p16 << " |" << p17 << " |" << p18 << " |" << p19 << " |" << p20 << " |" << "    16 17 18 19 20 \n";
  
  // FIFTH ROW
  std::cout << " |" << p21 << " |" << p22 << " |" << p23 << " |" << p24 << " |" << p25 << " |" << "    21 22 23 24 25 \n";

  std::cout << std::endl;
  std::cout << "Current Score: " << score << std::endl;
  std::cout << std::endl;
}

int main() {
  displayWelcomeMessage();
  displayStarterBoard();
  // displayMenuOptions();
  // displayStarterBoard();

  // std::cin >> entry;

  p1=p2=p3=p4=p6=p7=p8=p9=p10 = BlackKnight;
  p11=p12=p13=p14=p15=p16=p17=p18=p19=p20 = BlackKnight;
  p22=p23=p24=p25 = BlackKnight;
  blankPos = ' ';
  exitGame = 'x';
  exitGameX = 'X';
  p5 = " ";
  p21 = WhiteKnight;

  while ( status == true ) {    // Keeps everything up to date

    if (( p5 == WhiteKnight ) ){  // Checks if objective achieved yet, continues if not
      std::cout << "Congratulations, you did it!";
      break;
    }

    if ( ( score > 0 ) && ( entry != exitGame ) || ( entry != exitGameX) ){     // Checks if game is lost 
      displayMenuOptions(); // asks user to keep going, exit, or retry
      std::cin >> entry;  // takes in user input and decides where to go based off entry
      std::cout << "Your choice -> " << entry << std::endl;
    } else { // exits the game if score <= 0
      std::cout << "You have run out of moves. Try to do better next time!";
      entry = 'X';
      break;
    } 

    if ( ( entry == "m" ) || ( entry == "M") ){   // starts / continues game, moves new piece
      std::cout << std::endl;
      std::cout << "Enter the positions from and to, separated by a space (e.g. 14 5 to move the knight in position 14 to position 5): ";
      
      std::cin >> userPosI;  // takes in source position
      std:: cin >> userPosII; // takes in destination position

      std::cout << "You have chosen to move a knight from position " << userPosI << " to position " << userPosII << "." << std::endl;
      // std::cout << userPosI << " " << userPosII;


      if ( ( userPosI >= 1 ) && ( userPosI <= 25 ) && ( userPosII >= 1 ) && ( userPosII <= 25 ) ){ // checks if source and destination position on board
        if ( userPosI == 1 ) {
          if ( ( p1 == BlackKnight ) || ( p1 == WhiteKnight ) ) {
            // this if statement ^^^ checks if source pos is knight 
            if ( ( userPosII == 8 ) && ( p8 == blankPos) ) {
              /* These if else statements check if source position is valid and if destination position is empty */
              swapPos(p1, p8);
              score -= 5;
            } else if ( ( userPosII == 12 ) && ( p12 == blankPos ) ){
              swapPos(p1, p12);
              score -= 5;
            } else if ( ( userPosII == 8 )  && ( p8 != blankPos) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 12 ) && ( p12 != blankPos )){ 
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else {
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 2 ) {
          if ( ( p2 == BlackKnight ) || ( p2 == WhiteKnight ) ) {
            if ( ( userPosII == 9 ) && ( p9 == blankPos) ){
              swapPos(p2, p9);
              score -= 5;
            } else if ( ( userPosII == 11 ) && ( p11 == blankPos) ){
              swapPos(p2, p11);
              score -= 5;
            } else if ( ( userPosII == 13 ) && ( p13 == blankPos ) ){
              swapPos(p2, p13);
              score -= 5;
            } else if ( ( userPosII == 11 ) && ( p11 != blankPos )){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 13 ) && ( p13 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 3 ) {
          if ( ( p3 == BlackKnight ) || ( p3 == WhiteKnight ) ) {
            if ( ( userPosII == 6 ) && ( p6 == blankPos ) ) {
              swapPos(p3, p6);
              score -= 5;
            } else if ( ( userPosII == 10 ) && ( p10 == blankPos ) ){
              swapPos(p3, p10);
              score -= 5;
            } else if ( ( userPosII == 12 ) && ( p12 == blankPos ) ){
              swapPos(p3, p12);
              score -= 5;
            } else if ( ( userPosII == 14 ) && ( p14 == blankPos ) ){
              swapPos(p3, p14);
              score -= 5;
            } else if ( ( userPosII == 6 ) && ( p6 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
            } else if ( ( userPosII == 10 ) && ( p10 != blankPos )) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
            } else if ( ( userPosII == 12 ) && ( p12 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
            } else if ( ( userPosII == 14 ) && ( p14 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 4 ) {
          if ( ( p4 == BlackKnight ) || ( p4 == WhiteKnight ) ) {
            if ( ( userPosII == 7 ) && ( p7 == blankPos ) ){
              swapPos(p4, p7);
              score -= 5;
            } else if ( ( userPosII == 13 ) && ( p13 == blankPos ) ){
              swapPos(p4, p13);
              score -= 5;
            } else if ( ( userPosII == 15 ) && ( p15 == blankPos ) ){
              swapPos(p4, p15);
              score -= 5;
            } else if ( ( userPosII == 7 ) && ( p7 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 13 ) && ( p13 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 15 ) && ( p15 != blankPos )){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 5 ) {
          if ( ( p5 == BlackKnight ) || ( p5 == WhiteKnight ) ) {
            if ( ( userPosII == 8 ) && ( p8 == blankPos ) ){
              swapPos(p5, p8);
              score -= 5;
            } else if ( ( userPosII == 14 ) && ( p14 == blankPos ) ){
              swapPos(p5, p14);
              score -= 5;
            } else if ( ( userPosII == 8 ) && ( p8 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 14 ) && ( p14 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            } 
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 6 ) {
          if ( ( p6 == BlackKnight ) || ( p6 == WhiteKnight ) ) {
            if ( ( userPosII == 3 ) && ( p3 == blankPos ) ){
              swapPos(p6, p3);
              score -= 5;
            } else if ( ( userPosII == 13 ) && ( p13 == blankPos ) ){
              swapPos(p6, p13);
              score -= 5;
            } else if ( ( userPosII == 17 ) && ( p17 == blankPos ) ){
              swapPos(p6, p17);
              score -= 5;
            } else if ( ( userPosII == 3) && ( p3 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 13 ) && ( p13 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 17 ) && ( p17 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 7 ) {
          if ( ( p7 == BlackKnight ) || ( p7 == WhiteKnight ) ){
            if ( ( userPosII == 4 ) && ( p4  == blankPos ) ){
              swapPos(p7, p4);
              score -= 5;
            } else if ( ( userPosII == 14 ) && ( p14 == blankPos ) ){
              swapPos(p7, p14);
              score -= 5;
            } else if ( ( userPosII == 16 ) && ( p16 == blankPos ) ){
              swapPos(p7, p16);
              score -= 5;
            } else if ( ( userPosII == 18 ) && ( p18 == blankPos ) ){
              swapPos(p7, p18);
              score -= 5;
            } else if ( ( userPosII == 4 ) && ( p4 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 14 ) && ( p14 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 16 ) && ( p16 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 18 ) && ( p18 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI== 8 ) {
          if ( ( p8 == BlackKnight ) || ( p8 == WhiteKnight ) ) {
            if ( (userPosII == 1 ) && ( p1 == blankPos ) ){
              swapPos(p8, p1);
              score -= 5;
            } else if ( ( userPosII == 5 ) && ( p5 == blankPos ) ){
              swapPos(p8, p5);
              score -= 5;
            } else if ( ( userPosII == 11 ) && ( p11  == blankPos )){
              swapPos(p8, p11);
              score -= 5;
            } else if ( ( userPosII == 15 ) && ( p15 == blankPos ) ){
              swapPos(p8, p15);
              score -= 5;
            } else if ( ( userPosII == 17 ) && ( p17 == blankPos ) ){
              swapPos(p8, p17);
              score -= 5;
            } else if ( ( userPosII == 19 ) && ( p19 == blankPos ) ){
              swapPos(p8, p19);
              score -= 5;
            } else if ( ( userPosII == 1 ) && ( p1 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 5 ) && ( p5 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 11 ) && ( p11 != blankPos )) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 15 ) && ( p15 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 17 ) && ( p17 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 19 ) && ( p19 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 9 ) {
          if ( ( p9 == BlackKnight ) || ( p9 == WhiteKnight ) ){ 
            if ( ( userPosII == 2 ) && ( p2 == blankPos ) ){
              swapPos(p9, p2);
              score -= 5;
            } else if ( ( userPosII == 12 ) && ( p12 == blankPos ) ){
              swapPos(p9, p12);
              score -= 5;
            } else if ( ( userPosII == 18 ) && ( p18 == blankPos ) ){
              swapPos(p9, p18);
              score -= 5;
            } else if ( ( userPosII == 20 ) && ( p20 == blankPos )){ 
              swapPos(p9, p20);
              score -= 5;
            } else if ( ( userPosII == 2 ) && ( p2 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;          
            } else if ( ( userPosII == 12 ) && ( p12 != blankPos )) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 18 ) && ( p18 != blankPos )) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 20 ) && ( p20 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI== 10 ) {
          if ( ( p10 == BlackKnight ) || ( p10 == WhiteKnight ) ) {
            if ( ( userPosII == 3 ) && ( p3 == blankPos ) ){
              swapPos(p10, p3);
              score -= 5;
            } else if ( ( userPosII == 13 ) && ( p13 == blankPos ) ){
              swapPos(p10, p13);
              score -= 5;
            } else if ( ( userPosII == 19 ) && ( p19 == blankPos ) ){
              swapPos(p10, p19);
              score -= 5;
            } else if ( ( userPosII == 3 ) && ( p3 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 13 ) && ( p13 != blankPos )){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 19 ) && ( p19 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI== 11 ) {
          if ( ( p11 == BlackKnight ) || ( p11 == WhiteKnight ) ) {
            if ( ( userPosII == 2 ) && ( p2 == blankPos ) ){
              swapPos(p11, p2);
              score -= 5;
            } else if ( ( userPosII == 8 ) && ( p8 == blankPos ) ){
              swapPos(p11, p8);
              score -= 5;
            } else if ( ( userPosII == 18 ) && ( p18 == blankPos ) ){
              swapPos(p11, p18);
              score -= 5;
            } else if ( ( userPosII == 20 ) && ( p20 == blankPos ) ){
              swapPos(p11, p20);
              score -= 5;
            } else if ( ( userPosII == 2 ) && ( p2 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 8 ) && ( p8 != blankPos ) ){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 18 ) && ( p18 != blankPos )) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 20 ) && ( p20 != blankPos )){
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI== 12 ) {
          if ( ( p12 == BlackKnight ) || ( p12 == WhiteKnight ) ) {
            if ( ( userPosII == 1 ) && ( p1 == blankPos ) ){
              swapPos(p12, p1);
              score -= 5;
            } else if ( ( userPosII == 3 ) && ( p3 == blankPos ) ){
              swapPos(p12, p3);
              score -= 5;
            } else if ( ( userPosII == 9 ) && ( p9 == blankPos ) ){
              swapPos(p12, p9);
              score -= 5;
            } else if ( ( userPosII == 19 ) && ( p19 == blankPos ) ){
              swapPos(p12, p19);
              score -= 5;
            } else if ( ( userPosII == 21 ) && ( p21 == blankPos ) ){
              swapPos(p12, p21);
              score -= 5;
            } else if ( ( userPosII == 23 ) && ( p23 == blankPos ) ){
              swapPos(p12, p23);
              score -= 5;
            } else if ( ( userPosII == 1 ) && ( p1 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 3 ) && ( p3 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 9 ) && ( p9 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 19 ) && ( p19 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 21 ) && ( p21 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 23 ) && ( p23 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI== 13 ) {
          if ( ( p13 == BlackKnight ) || ( p13 == WhiteKnight ) ) {
            if ( ( userPosII == 2 ) && ( p2 == blankPos) ){
              swapPos(p13, p2);
              score -= 5;
            } else if ( ( userPosII == 4 ) && ( p4 == blankPos ) ){
              swapPos(p13, p4);
              score -= 5;
            } else if ( ( userPosII == 6 ) && ( p6 == blankPos ) ){
              swapPos(p13, p6);
              score -= 5;
            } else if ( ( userPosII == 10 ) && ( p10 == blankPos ) ){
              swapPos(p13, p10);
              score -= 5;
            } else if ( ( userPosII == 16 ) && ( p10 == blankPos ) ){
              swapPos(p13, p16);
              score -= 5;
            } else if ( ( userPosII == 20 ) && ( p20 == blankPos ) ){
              swapPos(p13, p20);
              score -= 5;
            } else if ( ( userPosII == 22 ) && ( p22 == blankPos ) ){
              swapPos(p13, p22);
              score -= 5;
            } else if ( ( userPosII == 24 ) && ( p24 == blankPos ) ){
              swapPos(p13, p24);
              score -= 5;
            } else if ( ( userPosII == 2) && ( p2 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 4 ) && ( p4 != blankPos) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 6 ) && ( p6 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 10 ) && ( p10 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 16 ) && ( p16 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 20 ) && ( p20 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 22 ) && ( p22 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 24 ) && ( p24 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 14 ) {
          if ( ( p14 == BlackKnight ) || ( p14 == WhiteKnight ) ) {
            if ( ( userPosII == 3 ) && ( p3 == blankPos ) ) {
              swapPos(p14, p3);
              score -= 5;
            } else if ( ( userPosII == 5 ) && ( p5 == blankPos ) ){
              swapPos(p14, p5);
              score -= 5;
            } else if ( ( userPosII == 7 ) && ( p7 == blankPos ) ){
              swapPos(p14, p7);
              score -= 5;
            } else if ( ( userPosII == 17 ) && ( p17 == blankPos ) ){
              swapPos(p14, p17);
              score -= 5;
            } else if ( ( userPosII == 23 ) && ( p23 == blankPos ) ){
              swapPos(p14, p23);
              score -= 5;
            } else if ( ( userPosII == 25 ) && ( p25 == blankPos ) ){
              swapPos(p14, p25);
              score -= 5;
            } else if ( ( userPosII == 3 ) && ( p3 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 5 ) && ( p5 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 7 ) && ( p7 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 17 ) && ( p17 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 23 ) && ( p23 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 25 ) && ( p25 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 15 ) {
          if ( ( p15 == BlackKnight ) || ( p15 == WhiteKnight ) ) {
            if ( ( userPosII == 4 ) && ( p4 == blankPos ) ){
              swapPos(p15, p4);
              score -= 5;
            } else if ( ( userPosII == 8 ) && ( p8 == blankPos ) ) {
              swapPos(p15, p8);
              score -= 5;
            } else  if ( ( userPosII == 18 ) && ( p18 == blankPos ) ) {
              swapPos(p15, p18);
              score -= 5;
            } else if ( ( userPosII == 24 ) && ( p24  == blankPos ) ) {
              swapPos(p15, p24);
              score -= 5;
            } else if ( ( userPosII == 4 ) && ( p4 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 8 ) && ( p8 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 18 ) && ( p18 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 24 ) && ( p24 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl; 
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 16 ) {
          if ( ( p16 == BlackKnight ) || ( p16 == WhiteKnight ) ) {
            if ( ( userPosII == 7 ) && ( p7 == blankPos ) ){
              swapPos(p16, p6);
              score -= 5;
            } else if ( ( userPosII == 13 ) && ( p13 == blankPos ) ){
              swapPos(p16, p13);
              score -= 5;
            } else if ( ( userPosII == 23 ) && ( p23 == blankPos ) ){
              swapPos(p13, p23);
              score -= 5;
            } else if ( ( userPosII == 7 ) && ( p7 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 13 ) && ( p13 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 23 ) && ( p23 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl; 
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 17 ) {
          if ( ( p17 == BlackKnight ) || ( p17 == WhiteKnight ) ) {
            if ( ( userPosII == 6 ) && ( p6 == blankPos ) ){
              swapPos(p17, p6);
              score -= 5;
            } else if ( ( userPosII == 8 ) && ( p8 == blankPos ) ){
              swapPos(p17, p8);
              score -= 5;
            } else if ( ( userPosII == 14 ) && ( p14 == blankPos ) ){
              swapPos(p17, p14);
              score -= 5;
            } else if ( ( userPosII == 24 ) && ( p24 == blankPos ) ){
              swapPos(p17, p24);
              score -= 5;
            } else if ( ( userPosII == 6 ) && ( p6 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 8 ) && ( p8 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 14 ) && ( p14 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 24 ) && ( p24 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 18 ) {
          if ( ( p18 == BlackKnight ) || ( p18 == WhiteKnight ) ) {
            if ( ( userPosII == 7 ) && ( p7 == blankPos ) ){
              swapPos(p18, p7);
              score -= 5;
            } else if ( ( userPosII == 9 ) && ( p9 == blankPos ) ){
              swapPos(p18, p9);
              score -= 5;
            } else if ( ( userPosII == 11 ) && ( p11 == blankPos ) ){
              swapPos(p18, p11);
              score -= 5;
            } else if ( ( userPosII == 15 ) && ( p15 == blankPos ) ){
              swapPos(p18, p15);
              score -= 5;
            } else if ( ( userPosII == 21 ) && ( p21 == blankPos ) ){
              swapPos(p18, p21);
              score -= 5;
            } else if ( ( userPosII == 25 ) && ( p25 == blankPos ) ){
              swapPos(p18, p25);
              score -= 5;
            } else if ( ( userPosII == 7 ) && ( p7 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 9 ) && ( p9 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 11 ) && ( p11 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 15 ) && ( p15 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 21 ) && ( p21 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 25 ) && ( p25 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 19 ) {
          if ( ( p19 == BlackKnight ) || ( p19 == WhiteKnight ) ) {
            if ( ( userPosII == 8 ) && ( p8 == blankPos ) ){
              swapPos(p19, p8);
              score -= 5;
            } else if ( ( userPosII == 10 ) && ( p10 == blankPos ) ){
              swapPos(p19, p10);
              score -= 5;
            } else if ( ( userPosII == 12 ) && ( p12 == blankPos ) ){
              swapPos(p19, p12);
              score -= 5;
            } else if ( (  userPosII == 22 ) && ( p22 == blankPos )){
              swapPos(p19, p22);
              score -= 5;
            } else if ( ( userPosII == 8 ) && ( p8 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 10 ) && ( p10 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 12 ) && ( p12 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 22 ) && ( p22 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 20 ) {
          if ( ( p20 == BlackKnight ) || ( p20 == WhiteKnight ) ) {
            if ( ( userPosII == 9 ) && ( p9 == blankPos ) ){
              swapPos(p20, p9);
              score -= 5;
            } else if ( ( userPosII == 13 ) && ( p13 == blankPos ) ){
              swapPos(p20, p13);
              score -= 5;
            } else if ( ( userPosII == 23 ) && ( p23 == blankPos ) ){
              swapPos(p20, p23);
              score -= 5;
            } else if ( ( userPosII == 9 ) && ( p9 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 13 ) && ( p13 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 23 ) && ( p23 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 21 ) {
          if ( ( p21 == BlackKnight ) || ( p21 == WhiteKnight ) ) { 
            if ( ( userPosII == 12 ) && ( p12 == blankPos ) ){
              swapPos(p21, p12);
              score -= 5;
            } else if ( ( userPosII == 18 ) && ( p18 == blankPos ) ){
              swapPos(p21, p18);
              score -= 5;
            } else if ( ( userPosII == 12 ) && ( p13 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 18 ) && ( p18 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 22 ) {
          if ( ( p22 == BlackKnight ) || ( p22 == WhiteKnight ) ) {
            if ( ( userPosII == 11 ) && ( p11 == blankPos ) ){
              swapPos(p22, p11);
              score -= 5;
            } else if ( ( userPosII == 13 ) && ( p13 == blankPos ) ){
              swapPos(p22, p13);
              score -= 5;
            } else if ( ( userPosII == 19 ) && ( p19 == blankPos ) ){
              swapPos(p22, p19);
              score -= 5;
            } else if ( ( userPosII == 11 ) && ( p11 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 13 ) && ( p13 != blankPos ) ) {    std::cout << "The destination position should be empty.     Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 19 ) && ( p19 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 23 ) {
          if ( ( p23 == BlackKnight ) || ( p23 == WhiteKnight ) ) {
            if ( ( userPosII == 12 ) && ( p12 == blankPos ) ){
              swapPos(p23, p12);
              score -= 5;
            } else if ( ( userPosII == 14 ) && ( p14 == blankPos ) ){
              swapPos(p23, p14);
              score -= 5;
            } else if ( ( userPosII == 16 ) && ( p16 == blankPos ) ){
              swapPos(p23, p16);
              score -= 5;
            } else if ( ( userPosII == 20 ) && ( p20 == blankPos ) ){
              swapPos(p23, p20);
              score -= 5;
            } else if ( ( userPosII == 12 ) && ( p12 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 14 ) && ( p14 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 16 ) && ( p16 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 20 ) && ( p20 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 24 ) {
          if ( ( p24 == BlackKnight ) || ( p24 == WhiteKnight ) ) {
            if ( ( userPosII == 13 ) && ( p13 == blankPos ) ){
              swapPos(p24, p13);
              score -= 5;
            } else if ( ( userPosII == 15 ) && ( p15 == blankPos ) ){
              swapPos(p24, p15);
              score -= 5;
            } else if ( ( userPosII == 17 ) && ( p17 == blankPos ) ){
              swapPos(p24, p17);
              score -= 5;
            } else if ( ( userPosII == 13 ) && ( p13 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 15 ) && ( p15 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 17 ) && ( p17 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
        } else if ( userPosI == 25 ) {
          if ( ( p25 == BlackKnight ) || ( p25 == WhiteKnight ) ) { 
            if ( ( userPosII == 14 ) && ( p14 == blankPos ) ) {
              swapPos(p25, p14);
              score -= 5;
            } else if ( ( userPosII == 18 ) && ( p18 == blankPos) ){
              swapPos(p25, p18);
              score -= 5;
            } else if ( ( userPosII == 14 ) && ( p14 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else if ( ( userPosII == 18 ) && ( p18 != blankPos ) ) {
              std::cout << "The destination position should be empty. Try again. " << std::endl;
              score -= 10;
            } else {
              std::cout << "Invalid move. Knights can only move in an L-shape. Try again." << std::endl;
              score -= 10;
            }
          } else { 
            std::cout << "The source position should have a knight. Try again." << std::endl;
            score -= 10;
          }
      } else if ( ( userPosI < 1 ) || ( userPosI > 25 ) || ( userPosII < 1 ) || ( userPosII > 25 ) ) {
        std::cout << "The source and destination position should be valid positions on the board (1-25). Try again." << std::endl;
        score -= 10;
      }
    } else if ( ( entry == "r" ) || ( entry == "R") ){ 
      std::cout << "*** Restarting \n";
      displayStarterBoard();
      score = 500;
      continue;
      // this if block resets board and score
    } else if ( ( entry == "x" ) || ( entry == "X" ) ) {
      std::cout << "Exiting... \n";
      status = false;
      break;
      // this if block exits the game 
    }
    displayBoard(); // display current board to help user see where                     to move next
    } 
  }
  std::cout << std::endl;
  std::cout << "Thank you for playing";
}
