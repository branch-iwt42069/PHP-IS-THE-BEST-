#include <gtest/gtest.h>
#include "../headers/design.h"

using namespace std;
  
TEST(CheckAnswer, Answer1){
	short questionNumbers[20];
	*questionNumbers=massive();
    EXPECT_EQ(checkAnswer(1, 1), 1);
}
TEST(CheckAnswer,Answer2){
short questionNumbers[20];
    
    *questionNumbers = massive();
EXPECT_EQ(checkAnswer( 2, 3), 1 );

}
TEST(CheckAnswer,Answer3){
short questionNumbers[20];
    
    *questionNumbers = massive();
EXPECT_EQ(checkAnswer( 3, 1), 1 );

}
TEST(CheckAnswer,Answer4){
short questionNumbers[20];
    
    *questionNumbers = massive();
EXPECT_EQ(checkAnswer( 4, 3), 1 );

}
TEST(CheckAnswer,Answer5){
short questionNumbers[20];
    
    *questionNumbers = massive();
EXPECT_EQ(checkAnswer( 5, 3), 1 );

}
