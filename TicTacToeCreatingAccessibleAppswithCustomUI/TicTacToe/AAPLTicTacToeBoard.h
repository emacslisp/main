/*

 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 Board class encapsulates the nine grid.

 */

@import Foundation;
#import "AAPLTicTacToeSquare.h"

@interface AAPLTicTacToeBoard : NSObject

+ (NSString *)descriptionForSquare:(AAPLTicTacToeSquare *)square row:(NSUInteger)row column:(NSUInteger)column;

- (AAPLTicTacToeSquare *)squareAtRow:(NSUInteger)row column:(NSUInteger)column;
- (NSArray *)squaresInRow:(NSUInteger)row;
- (NSArray *)squaresInColumn:(NSUInteger)column;
@property (NS_NONATOMIC_IOSONLY, readonly) NSUInteger numRows;
@property (NS_NONATOMIC_IOSONLY, readonly) NSUInteger numColumns;
@property (NS_NONATOMIC_IOSONLY, getter=isFull, readonly) BOOL full;

- (void)reset;

@end
