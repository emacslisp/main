/*
 
 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 NSButton subclass demonstrating accessibility provided by AppKit.
 
 */

#import "AAPLTicTacToeCircleMinusButtonView.h"

@implementation AAPLTicTacToeCircleMinusButtonView

- (void)drawRect:(NSRect)dirtyRect
{
    [super drawRect:dirtyRect];

    NSPoint centerPoint = self.centerPoint;

    [NSBezierPath strokeLineFromPoint:NSMakePoint(2 * self.inset, centerPoint.y)
                              toPoint:NSMakePoint(2 * self.radius, centerPoint.y)];
}

@end
