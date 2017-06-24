/*
 
 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 AI engine that calculates a move for the computer opponent from the current board state.
 
 */

#import "AAPLTicTacToeAIEngine.h"

@implementation AAPLTicTacToeAIEngine

- (instancetype)init
{
    self = [super init];

    if ( self != nil )
    {
        _difficulty = 5;
    }

    return self;
}

- (NSPoint)moveForBoard:(AAPLTicTacToeBoard *)board
{
    // pick a random open location

    NSPoint move = NSZeroPoint;

    if ( !board.isFull )
    {
        int row;
        int column;
        do
        {
            row = arc4random() % board.numRows;
            column = arc4random() % board.numColumns;
        }
        while ( ![board squareAtRow:row column:column].isEmpty );

        move = NSMakePoint(row, column);
    }

    return move;
}

@end
