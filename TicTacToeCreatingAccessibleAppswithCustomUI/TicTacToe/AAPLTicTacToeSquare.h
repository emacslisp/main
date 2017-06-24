/*

 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 Square class encapsulates a single square on the board.

 */

@import Foundation;

typedef NS_ENUM (NSUInteger, AAPLTicTacToeSquareType)
{
    AAPLTicTacToeSquareTypeEmpty,
    AAPLTicTacToeSquareTypeX,
    AAPLTicTacToeSquareTypeO,
};

@interface AAPLTicTacToeSquare : NSObject

@property (nonatomic) AAPLTicTacToeSquareType type;

+ (AAPLTicTacToeSquare *)X;
+ (AAPLTicTacToeSquare *)O;
+ (AAPLTicTacToeSquare *)Empty;

@property (NS_NONATOMIC_IOSONLY, getter=isX, readonly) BOOL x;
@property (NS_NONATOMIC_IOSONLY, getter=isO, readonly) BOOL o;
@property (NS_NONATOMIC_IOSONLY, getter=isEmpty, readonly) BOOL empty;

- (BOOL)sameTypeAs:(AAPLTicTacToeSquare *)square;

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *description;

@end
