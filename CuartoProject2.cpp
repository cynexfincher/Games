
#include <iostream>   // for cin and cout
#include <iomanip>    // for setw()
#include <cctype>     // for toupper()
#include <string>     // needed to use type string in some compilers, though not all
using namespace std;  // so that we don't need to preface every cin and cout with std::
 

char p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16;
string upRowPiece    = "OO/CC  II/ZZ";
string lowRowPiece = "oo/cc  ii/zz";
 
//-------------------------------------------------------------------------------------
void displayInstructions() //  this function is to display the initial set of instructions and instruct the user how to exit
{
   cout << "Welcome to the game of Cuatro, where you try to complete a set      \n"
        << "of four pieces that are alike.  Players take turns making moves.    \n"
        << "On each move your OPPONENT chooses the piece, then YOU get to       \n"
        << "place it on the board.  If you create a set of four alike when      \n"
        << "you place your piece, then you win!       \n"
        << endl
        << "A set of four alike can be completed by using four all upper (or all\n"
        << "lower) case characters, four all vowels (or all consonants), or four\n"
        << "all curved (or all straight-lined). Curved letters are 'O' and 'C'\n"
        << "(upper or lower), and straight-line letters are 'I' and 'Z' (upper or\n"
        << "lower). Groups of four can be created in a row, column, diagonal, or\n"
        << "corner quadrant.\n"
        << endl
        << "When prompted for input you may also enter 'x' or 'X' to exit." << endl;
}// end displayInstructions()
 
 
//-------------------------------------------------------------------------------------

void displayBoard() //  this function is to display the default board setup
{
cout << endl
    << "      ---------    Square #  \n"
    << "     | "<< p1<<" "<< p2<<" "<< p3<<" "<< p4<<" |  1  2  3  4 \n"
    << "     | "<< p5<<" "<< p6<<" "<< p7<<" "<< p8<<" |  5  6  7  8 \n"
    << "     | "<< p9<<" "<<p10<<" "<<p11<<" "<<p12<<" |  9 10 11 12 \n"
    << "     | "<<p13<<" "<<p14<<" "<<p15<<" "<<p16<<" | 13 14 15 16 \n"
    << "      ---------              \n"
    << "     Pieces:     Curved Straight                \n"
    << "           Upper: " << upRowPiece    << endl
    << "           Lower: " << lowRowPiece << endl
    << "                 Vowel/Consonant  "
    << endl;
} // end displayBoard()
 
//-------------------------------------------------------------------------------------

char getPieceAt( int position) // this function is to assign the correct node for redistribution into the setPieceAt() function
{
   char thePiece = ' ';   // Piece value to be returned will be stored here.
  
   switch( position) {
      case  1: thePiece =  p1; break;
      case  2: thePiece =  p2; break;
      case  3: thePiece =  p3; break;
      case  4: thePiece =  p4; break;
      case  5: thePiece =  p5; break;
      case  6: thePiece =  p6; break;
      case  7: thePiece =  p7; break;
      case  8: thePiece =  p8; break;
      case  9: thePiece =  p9; break;
      case 10: thePiece = p10; break;
      case 11: thePiece = p11; break;
      case 12: thePiece = p12; break;
      case 13: thePiece = p13; break;
      case 14: thePiece = p14; break;
      case 15: thePiece = p15; break;
      case 16: thePiece = p16; break;
      otherwise: // Sanity We need to check
           cout << "Invalid position " << position
                << " inside getPieceAt() function.  Exiting..." << endl;
           exit( -1);
           break;
   }//end switch( position)
  
   return thePiece;
} // end getPieceAt()
 
 
//-------------------------------------------------------------------------------------

void setPieceAt(
       char node_piece,  // The character that needs to be stored
       int destination)    // The variable number into which it is to be stored
{
   switch( destination) {
      case  1:  p1 = node_piece; break;
      case  2:  p2 = node_piece; break;
      case  3:  p3 = node_piece; break;
      case  4:  p4 = node_piece; break;
      case  5:  p5 = node_piece; break;
      case  6:  p6 = node_piece; break;
      case  7:  p7 = node_piece; break;
      case  8:  p8 = node_piece; break;
      case  9:  p9 = node_piece; break;
      case 10: p10 = node_piece; break;
      case 11: p11 = node_piece; break;
      case 12: p12 = node_piece; break;
      case 13: p13 = node_piece; break;
      case 14: p14 = node_piece; break;
      case 15: p15 = node_piece; break;
      case 16: p16 = node_piece; break;
      otherwise: // Sanity We need to check, should never get here
           cout << "Invalid destination " << destination
                << " inside setPieceAt() function.  Exiting..." << endl;
           exit( -1);
           break;
   }//end switch( position)
} // end setPieceAt()
 
//-------------------------------------------------------------------------------------

void turnAssigner( // turnAssignerping function
       int &player1,   // 1 or 2
       int &player2)    // 2 or 1
{
   int temp = player1;
   player1 = player2;
   player2 = temp;
} // end turnAssigner()
 
//-------------------------------------------------------------------------------------

bool canFindPiece(
       char playPiece,       
       string piecesToPlay)    // string containing the character to be found
{
   bool pieceWasFound = false; // to keep track whether or not the desired piece is found
  
   // Iterated through the string, comparing one by one until the piece to be played is found.
   for( int i=0; i<piecesToPlay.length(); i++) {
       if( piecesToPlay[ i] == playPiece) {
           pieceWasFound = true;     // Indicate that piece was found
           break;                    // Break out of loop, since we're done
       }
   }
  
   return pieceWasFound;
} // end canFindPiece()
 
 
//-------------------------------------------------------------------------------------

bool ommitPiece(
       char playPiece,       // The single character to be played
       string &piecesToPlay)   
{
   bool pieceWasFound = false; 

   for( int i=0; i<piecesToPlay.length(); i++) {
       if( piecesToPlay[ i] == playPiece) {
           pieceWasFound = true;     // this is for indicating that the piece was found
           piecesToPlay[ i] = ' ';   // The piece needs to be blanked to prevent showing it
           break;                    // Break out of loop
       }
   }
  
   return pieceWasFound;
} // end ommitPiece()
 
 
//-------------------------------------------------------------------------------------

bool invalidMove(
       char playPiece,     // The piece that needs to be placed on the board
       int destination)       // the destination where the piece has to land up
{
   // We need to check if piece is one of the valid pieces remaining to be played
   if( !canFindPiece( playPiece, upRowPiece) &&
       !canFindPiece( playPiece, lowRowPiece)
     ) {
       cout << "*** Sorry, that is an invalid piece.  Please retry." << endl;
       return true;   // the move is invalid
      }
  
   // if the destination is within the valid range
   if( destination < 1 || destination > 16) {
       cout << "*** Sorry, that destination is invalid.  Please retry." << endl;
       return true;   // Move is invalid
   }
  
   // if the destination is not already occupied
   if( getPieceAt( destination) != '.') {
       cout << "*** Sorry, that destination is occupied.  Please retry." << endl;
       return true;   // Move is invalid
   }
  
   return false;
} // end invalidMove()
 
 
//-------------------------------------------------------------------------------------

void makeMove( // function to perform move
       char playPiece,     // piece that needs to be placed on the board
       int destination)      // The destination where this piece is to be played
{
   bool pieceWasFound = false;     // Used for move validation
 
   //we need to remove the piece from the list of possible pieces for remaining nodes
   if( isupper( playPiece) ) {
       pieceWasFound = ommitPiece( playPiece, upRowPiece);
   }
   else {
       pieceWasFound = ommitPiece( playPiece, lowRowPiece);
   }
  
   // Sanity Check
   if( ! pieceWasFound) {
       cout << "Inside makeMove(), piece " << playPiece
            << " was not found in " << upRowPiece << " or in "
            << lowRowPiece << ". Exiting program..." << endl;
       exit( -1);
   }
  
   setPieceAt( playPiece, destination);
} // end makeMove()
 
//-------------------------------------------------------------------------------------

bool matched(
       char c,     // The character to compare
       char c1,    // The first character against which to compare
       char c2)    // The second character against which to compare
{
   c = toupper( c);    // Convert original character to upper case to make subsequent
                       //    comparison simpler.
   if( c == c1 || c == c2) {
       return true;
   }
   else {
       return false;
   }
} // end matched()
 
 
//-------------------------------------------------------------------------------------

bool isStraight( char c) // We need to check for straight
{
   return matched( c, 'Z', 'I');
} // end isStraight()
 
 
//-------------------------------------------------------------------------------------

bool isCurved( char c)// We need to check for curved
{
   return matched( c, 'C', 'O');
} // end isCurved()
 
 
//-------------------------------------------------------------------------------------

bool isVowel( char c) // We need to check for a vowel
{
   return matched( c, 'O', 'I');
} // end isVowel()
 
 
//-------------------------------------------------------------------------------------

bool isConsonant( char c) // We need to check for consonant
{
   return matched( c, 'Z', 'C');
} // end isConsonant()
 
 
//-------------------------------------------------------------------------------------
  
bool piecesMatch( char c1, char c2, char c3, char c4) // We need to check for 4 match
{
   if( // We need to check if all are upper case
       ( isupper( c1) && isupper( c2) && isupper( c3) && isupper( c4) ) ||
     
       // We need to check if all are lower case
       ( islower( c1) && islower( c2) && islower( c3) && islower( c4) ) ||
     
       // We need to check if all are straight-line
       ( isStraight( c1) && isStraight( c2) && isStraight( c3) && isStraight( c4) ) ||
     
       // We need to check if all are curved
       ( isCurved( c1) && isCurved( c2) && isCurved( c3) && isCurved( c4) ) ||
     
       // We need to check if all are vowels
       ( isVowel( c1) && isVowel( c2) && isVowel( c3) && isVowel( c4) ) ||
     
       // We need to check if all are consonants
       ( isConsonant( c1) && isConsonant( c2) && isConsonant( c3) && isConsonant( c4) )
     ) {
     return true;      // All four pieces match according to one of the criteria
   }
   else {
       return false;   // Pieces do not match
   }
} // end piecesMatch()
 
 
//-------------------------------------------------------------------------------------
// If no one has won and there is still space on the board,  true, else false.


bool notDone( int playerWhoJustMoved)
{
   if( // We need to check rows, top down
       piecesMatch( getPieceAt( 1), getPieceAt( 2), getPieceAt( 3), getPieceAt( 4)) ||
       piecesMatch( getPieceAt( 5), getPieceAt( 6), getPieceAt( 7), getPieceAt( 8)) ||
       piecesMatch( getPieceAt( 9), getPieceAt(10), getPieceAt(11), getPieceAt(12)) ||
       piecesMatch( getPieceAt(13), getPieceAt(14), getPieceAt(15), getPieceAt(16)) ||
     
       // We need to check columns, left to right
       piecesMatch( getPieceAt( 1), getPieceAt( 5), getPieceAt( 9), getPieceAt(13)) ||
       piecesMatch( getPieceAt( 2), getPieceAt( 6), getPieceAt(10), getPieceAt(14)) ||
       piecesMatch( getPieceAt( 3), getPieceAt( 7), getPieceAt(11), getPieceAt(15)) ||
       piecesMatch( getPieceAt( 4), getPieceAt( 8), getPieceAt(12), getPieceAt(16)) ||
     
       // We need to check diagonals, first upper-left to lower-right, then lower-left to upper-right
       piecesMatch( getPieceAt( 1), getPieceAt( 6), getPieceAt(11), getPieceAt(16)) ||
       piecesMatch( getPieceAt(13), getPieceAt(10), getPieceAt( 7), getPieceAt( 4)) ||
     
       // We need to check corner quadrants, clockwise starting from upper-left
       piecesMatch( getPieceAt( 1), getPieceAt( 2), getPieceAt( 6), getPieceAt( 5)) ||
       piecesMatch( getPieceAt( 3), getPieceAt( 4), getPieceAt( 8), getPieceAt( 7)) ||
       piecesMatch( getPieceAt(11), getPieceAt(12), getPieceAt(16), getPieceAt(15)) ||
       piecesMatch( getPieceAt( 9), getPieceAt(10), getPieceAt(14), getPieceAt(13))
     ) {
       displayBoard();   // Display the winning board configuration
       cout << "*** Player " << playerWhoJustMoved << " you won!" << endl;
       return false;   // We *are* done, since there was a winning set of 4
   }
   else {
       return true;    // We are not done yet
   }
} // end notDone()
 
//------------------------------------------------------------------------------------- 
//-------------------------------------------------------------------------------------
int main()
{
   // Initialize the global board piece variables to all be '.'
   p1=p2=p3=p4=p5=p6=p7=p8=p9=p10=p11=p12=p13=p14=p15=p16='.';
   int moveNumber = 1;      // Is incremented after every move
   int player1 = 1;    // The current player to move, alternating between 1 and 2
   int player2 = 2;     // The other player, alternating between 2 and 1
   char playPiece = ' ';  // the move needs to be in exchange for this piece in the menu
   int destination = 0;     // destination where piece is to be placed
  
   displayInstructions();
  
   do {
       displayBoard();
      
       // Exit the game play loop if all nodes have been played and no one has won.
       if( moveNumber == 17) {
           break;              // Break out of game play loop
       }
      
       // Display the prompt and get the input from the user
       cout << moveNumber << ". Player " << player1 << " enter piece, "
            << "and Player " << player2 << " enter destination: ";
       cin >> playPiece;
      
       
       if( playPiece == 'x' || playPiece == 'X') { // use input to quit the game
           cout << "Exiting program...\n";
           exit( 0);
       }
       cin >> destination;
      
       
       if( invalidMove( playPiece, destination) ) {// this step is for validation of the move by the user
           // Loop back to try this move again
           continue;
       }
      
       // once the move is validated, we can make the move on the board
       makeMove( playPiece, destination);
      
       
       turnAssigner( player1, player2); // assign the turn of the players along with what input is expected
       moveNumber++;  // Increment the moveNumber
      
   } while(notDone( player1));
  
   return 0;
} // end main()


