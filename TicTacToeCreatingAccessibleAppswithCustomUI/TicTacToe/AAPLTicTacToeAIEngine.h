/*

 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 AI engine that calculates a move for the computer opponent from the current board state.

 */

@import Foundation;
#import "AAPLTicTacToeBoard.h"

@interface AAPLTicTacToeAIEngine : NSObject

@property (nonatomic) NSInteger difficulty;

// Returns a point whose x coordinate represents the row
// and y coordinate represents the column for the move
- (NSPoint)moveForBoard:(AAPLTicTacToeBoard *)board;

@end
