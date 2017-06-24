/*
 
 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 NSButton subclass demonstrating accessibility provided by AppKit.
 
 */

#import "AAPLTicTacToeCirclePlusButtonView.h"

@implementation AAPLTicTacToeCirclePlusButtonView

- (void)drawRect:(NSRect)dirtyRect
{
    [super drawRect:dirtyRect];

    NSPoint centerPoint = self.centerPoint;

    [NSBezierPath strokeLineFromPoint:NSMakePoint(2 * self.inset, centerPoint.y)
                              toPoint:NSMakePoint(2 * self.radius, centerPoint.y)];

    [NSBezierPath strokeLineFromPoint:NSMakePoint(centerPoint.x, 2 * self.inset)
                              toPoint:NSMakePoint(centerPoint.x, 2 * self.radius)];

}

@end
