/*

 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 An example demonstrating adding accessibility to an NSView subclass that behaves like a checkbox by implementing the NSAccessibilityCheckBox protocol.

 */

@import Cocoa;

@protocol AAPLTicTacToeCheckboxDelegate <NSObject>
- (void)checkboxCheckedStateChanged:(id)sender;
@end

IB_DESIGNABLE
@interface AAPLTicTacToeCheckboxView : NSView <NSAccessibilityCheckBox>

@property (nonatomic, readonly) BOOL checked;
@property (nonatomic, weak) id <AAPLTicTacToeCheckboxDelegate> delegate;

@end
