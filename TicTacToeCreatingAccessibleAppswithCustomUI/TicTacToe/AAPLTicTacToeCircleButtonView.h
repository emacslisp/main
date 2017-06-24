/*

 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 NSButton subclass demonstrating accessibility provided by AppKit.

 */

@import Cocoa;

IB_DESIGNABLE
@interface AAPLTicTacToeCircleButtonView : NSButton

@property (nonatomic, readonly) CGFloat lineWidth;
@property (nonatomic, readonly) NSColor *color;
@property (nonatomic, readonly) NSColor *backgroundColor;
@property (nonatomic, readonly) NSColor *backgroundDepressedColor;
@property (nonatomic, readonly) CGFloat inset;

@property (NS_NONATOMIC_IOSONLY, readonly) NSPoint centerPoint;
@property (NS_NONATOMIC_IOSONLY, readonly) CGFloat radius;

@end
