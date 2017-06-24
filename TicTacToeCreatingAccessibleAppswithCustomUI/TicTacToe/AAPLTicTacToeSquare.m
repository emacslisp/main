/*

 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 Square class encapsulates a single square on the board.

 */

#import "AAPLTicTacToeSquare.h"

@implementation AAPLTicTacToeSquare

+ (AAPLTicTacToeSquare *)X
{
    return [[self alloc] initWithType:AAPLTicTacToeSquareTypeX];
}

+ (AAPLTicTacToeSquare *)O
{
    return [[self alloc] initWithType:AAPLTicTacToeSquareTypeO];
}

+ (AAPLTicTacToeSquare *)Empty
{
    return [[self alloc] initWithType:AAPLTicTacToeSquareTypeEmpty];
}

- (instancetype)initWithType:(AAPLTicTacToeSquareType)type
{
    self = [super init];

    if ( self != nil )
    {
        _type = type;
    }

    return self;
}

- (BOOL)isX
{
    return self.type == AAPLTicTacToeSquareTypeX;
}

- (BOOL)isO
{
    return self.type == AAPLTicTacToeSquareTypeO;
}

- (BOOL)isEmpty
{
    return self.type == AAPLTicTacToeSquareTypeEmpty;
}

- (void)makeX
{
    self.type = AAPLTicTacToeSquareTypeX;
}

- (void)makeO
{
    self.type = AAPLTicTacToeSquareTypeO;
}

- (void)makeEmpty
{
    self.type = AAPLTicTacToeSquareTypeEmpty;
}

- (BOOL)sameTypeAs:(AAPLTicTacToeSquare *)square
{
    return square.type == self.type;
}

- (NSString *)description
{
    if ( self.isX )
    {
        return NSLocalizedString(@"X", nil);
    }
    else if ( self.isO )
    {
        return NSLocalizedString(@"O", nil);
    }
    else
    {
        return  NSLocalizedString(@"empty", nil);
    }
}

@end