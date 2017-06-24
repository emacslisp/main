/*
 
 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 Piece class encapsulates a single space on the board.
 
 */

#import "AAPLTicTacToePiece.h"

@implementation AAPLTicTacToePiece

+ (AAPLTicTacToePiece *)X
{
    return [[self alloc] initWithType:AAPLTicTacToePieceTypeX];
}

+ (AAPLTicTacToePiece *)O
{
    return [[self alloc] initWithType:AAPLTicTacToePieceTypeO];
}

+ (AAPLTicTacToePiece *)Empty
{
    return [[self alloc] initWithType:AAPLTicTacToePieceTypeEmpty];
}

- (instancetype)initWithType:(AAPLTicTacToePieceType)type
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
    return self.type == AAPLTicTacToePieceTypeX;
}

- (BOOL)isO
{
    return self.type == AAPLTicTacToePieceTypeO;
}

- (BOOL)isEmpty
{
    return self.type == AAPLTicTacToePieceTypeEmpty;
}

- (void)makeX
{
    self.type = AAPLTicTacToePieceTypeX;
}

- (void)makeO
{
    self.type = AAPLTicTacToePieceTypeO;
}

- (void)makeEmpty
{
    self.type = AAPLTicTacToePieceTypeEmpty;
}

- (BOOL)sameTypeAs:(AAPLTicTacToePiece *)piece
{
    return piece.type == self.type;
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