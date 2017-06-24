/*

 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 An example demonstrating adding accessibility to an NSView subclass that behaves like a group by implementing the NSAccessibilityGroup protocol
  and using NSAccessibilityElement to represent each of the items the view draws.

 */

@import Cocoa;
#import "AAPLTicTacToeGame.h"
#import "AAPLTicTacToeBoardViewDelegate.h"

IB_DESIGNABLE
@interface AAPLTicTacToeBoardView : NSView <NSAccessibilityGroup>

@property (nonatomic, weak) id <AAPLTicTacToeBoardViewDelegate> delegate;
@property (nonatomic, strong) AAPLTicTacToeGame *game;

@end
