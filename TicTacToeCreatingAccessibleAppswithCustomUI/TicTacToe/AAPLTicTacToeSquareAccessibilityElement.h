/*

 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 An accessibility object representing a single tic tac toe square.

 */

@import Cocoa;
#import "AAPLTicTacToeBoardViewDelegate.h"

@interface AAPLTicTacToeSquareAccessibilityElement : NSAccessibilityElement <NSAccessibilityButton>

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithRow:(NSUInteger)row column:(NSUInteger)column delegate:(id <AAPLTicTacToeBoardViewDelegate>)delegate NS_DESIGNATED_INITIALIZER;

@property (nonatomic, weak) id <AAPLTicTacToeBoardViewDelegate> delegate;
@property (nonatomic) NSUInteger row;
@property (nonatomic) NSUInteger column;

@end
