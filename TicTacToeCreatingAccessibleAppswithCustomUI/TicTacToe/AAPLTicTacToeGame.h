/*

 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 Game state class encapsulates the current board state, player turn, and game rules (e.g. win conditions, playing a square).

 */

@import Foundation;
#import "AAPLTicTacToeBoard.h"

typedef NS_ENUM(NSUInteger, AAPLTicTacToeGameState)
{
    AAPLTicTacToeGameStateXTurn,
    AAPLTicTacToeGameStateOTurn,
    AAPLTicTacToeGameStateXWin,
    AAPLTicTacToeGameStateOWin,
    AAPLTicTacToeGameStateTie
};

typedef NS_ENUM(NSUInteger, AAPLTicTacToeGameWinType)
{
    AAPLTicTacToeGameWinTypeNone,
    AAPLTicTacToeGameWinTypeRow,
    AAPLTicTacToeGameWinTypeColumn,
    AAPLTicTacToeGameWinTypeTopLeftDiagonal,
    AAPLTicTacToeGameWinTypeTopRightDiagonal,
};

@interface AAPLTicTacToeGame : NSObject

@property (nonatomic, strong, readonly) AAPLTicTacToeBoard *board;
@property (nonatomic, readonly) AAPLTicTacToeGameState state;
@property (nonatomic, readonly) AAPLTicTacToeGameWinType winType;
@property (nonatomic, readonly) NSUInteger winningRow;
@property (nonatomic, readonly) NSUInteger winningColumn;

- (AAPLTicTacToeSquare *)playSquareAtRow:(NSUInteger)row column:(NSUInteger)column;
- (void)reset;

@end
