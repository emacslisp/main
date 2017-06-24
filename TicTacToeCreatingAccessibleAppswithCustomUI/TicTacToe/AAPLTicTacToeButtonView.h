/*

 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 An example demonstrating adding accessibility to an NSView subclass that behaves like a button by implementing the NSAccessibilityButton protocol.

 */

@import Cocoa;

@protocol AAPLTicTacToeButtonDelegate <NSObject>
- (void)buttonPressed:(id)sender;
@end

IB_DESIGNABLE
@interface AAPLTicTacToeButtonView : NSView <NSAccessibilityButton>

@property (nonatomic, weak) id <AAPLTicTacToeButtonDelegate> delegate;

@end
