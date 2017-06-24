/*
 
 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 An accessibility object representing a single tic tac toe piece.
 
 */

#import "AAPLTicTacToeSquareAccessibilityElement.h"
#import "AAPLTicTacToeSquare.h"
#import "AAPLTicTacToeBoard.h"

@implementation AAPLTicTacToeSquareAccessibilityElement

- (instancetype)initWithRow:(NSUInteger)row column:(NSUInteger)column delegate:(id <AAPLTicTacToeBoardViewDelegate>)delegate
{
    self = [super init];
    if ( self != nil )
    {
        self.row = row;
        self.column = column;
        self.delegate = delegate;
    }
    return self;
}

- (NSRect)accessibilityFrame
{
    return [super accessibilityFrame];
}

- (id)accessibilityParent
{
    return [super accessibilityParent];
}

- (NSString *)accessibilityLabel
{
    NSUInteger row = self.row;
    NSUInteger column = self.column;

    AAPLTicTacToeSquare *square = [self.delegate squareAtRow:row column:column];
    return [AAPLTicTacToeBoard descriptionForSquare:square row:row column:column];
}

- (BOOL)accessibilityPerformPress
{
    [self.delegate playSquareAtRow:self.row column:self.column];
    return YES;
}

// It is not legal to play in an occupied square or when the game is over, disable the button in these cases.
- (BOOL)isAccessibilityEnabled
{
    AAPLTicTacToeSquare *square = [self.delegate squareAtRow:self.row column:self.column];
    BOOL gameOver = [self.delegate isGameOver];

    return !gameOver && square.isEmpty;
}

@end
