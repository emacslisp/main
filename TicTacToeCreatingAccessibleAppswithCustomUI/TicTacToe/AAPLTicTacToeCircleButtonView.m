/*
 
 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 NSButton subclass demonstrating accessibility provided by AppKit.
 
 */

#import "AAPLTicTacToeCircleButtonView.h"

@interface AAPLTicTacToeCircleButtonView ()

@property (nonatomic) BOOL depressed;

@end

@implementation AAPLTicTacToeCircleButtonView

- (instancetype)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];

    if ( self != nil )
    {
        // `commonSetup` was factored out of `initWithFrame:` for use in `prepareForInterfaceBuilder`.
        [self commonSetup];
    }

    return self;
}

- (void)commonSetup
{
    _lineWidth = 2.0;
    _color = [NSColor blackColor];
    _backgroundColor = [NSColor lightGrayColor];
    _backgroundDepressedColor = [NSColor grayColor];
    _inset = self.bounds.size.width / 10.0;
}

- (void)mouseDown:(NSEvent *)mouseEvent
{
    [super mouseDown:mouseEvent];

    self.depressed = YES;
    [self setNeedsDisplay:YES];
}

- (void)mouseUp:(NSEvent *)mouseEvent
{
    [super mouseUp:mouseEvent];

    self.depressed = NO;
    [self setNeedsDisplay:YES];
}

- (NSPoint)centerPoint
{
    return NSMakePoint(NSMidX(self.bounds), NSMidY(self.bounds));
}

- (CGFloat)radius
{
    return self.bounds.size.width / 2.0 - self.inset;
}

- (void)drawRect:(NSRect)dirtyRect
{
    [NSBezierPath setDefaultLineWidth:self.lineWidth];
    NSBezierPath *circlePath = [[NSBezierPath alloc] init];
    [circlePath appendBezierPathWithArcWithCenter:self.centerPoint
                                           radius:self.radius
                                       startAngle:0.0
                                         endAngle:360.0];
    if ( self.depressed )
    {
        [self.backgroundDepressedColor set];
    }
    else
    {
        [self.backgroundColor set];
    }

    [circlePath fill];

    [self.color set];
    [circlePath stroke];

    // Draw the focus ring
    BOOL isFirstResponder = [[[NSApp mainWindow] firstResponder] isEqual:self];
    if ( isFirstResponder )
    {
        [NSGraphicsContext saveGraphicsState];
        NSSetFocusRingStyle(NSFocusRingOnly);
        [circlePath fill];
        [NSGraphicsContext restoreGraphicsState];
    }
}

#pragma - Support IB_DESIGNABLE

// Executed when your view is being prepared for display in Interface Builder.
- (void)prepareForInterfaceBuilder {
    // Perform the `commonSetup` functionality to allow buttons to draw correctly.
    [self commonSetup];
}

@end
