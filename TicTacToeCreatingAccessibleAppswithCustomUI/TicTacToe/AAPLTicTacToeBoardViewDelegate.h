/*

 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 Delegate methods for an object that can provide information about the game state.

 */

@import Foundation;
#import "AAPLTicTacToeSquare.h"

@protocol AAPLTicTacToeBoardViewDelegate <NSObject>

- (void)playSquareAtRow:(NSUInteger)row column:(NSUInteger)column;
- (AAPLTicTacToeSquare *)squareAtRow:(NSUInteger)row column:(NSUInteger)column;
- (BOOL)isGameOver;

@end