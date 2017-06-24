/*
 
 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 An example demonstrating adding accessibility to an NSView subclass that behaves like a button by implementing the NSAccessibilityButton protocol.
 
 */

#import "AAPLTicTacToeButtonView.h"

@interface AAPLTicTacToeButtonView ()

@property (nonatomic) BOOL depressed;

@end

@implementation AAPLTicTacToeButtonView

- (BOOL)acceptsFirstResponder
{
    return YES;
}

- (void)drawFocusRingMask
{
    NSRectFill(self.bounds);
}

- (NSRect)focusRingMaskBounds
{
    return self.bounds;
}

- (void)mouseDown:(NSEvent *)theEvent
{
    [super mouseUp:theEvent];
    self.depressed = YES;
    [self setNeedsDisplay:YES];
}

- (void)mouseUp:(NSEvent *)theEvent
{
    [super mouseUp:theEvent];

    self.depressed = NO;
    [self setNeedsDisplay:YES];
    [self.delegate buttonPressed:self];
}

- (void)drawRect:(NSRect)dirtyRect
{
    [super drawRect:dirtyRect];

    if (self.depressed)
    {
        [[NSColor grayColor] set];
    }
    else
    {
        [[NSColor lightGrayColor] set];
    }

    [NSBezierPath fillRect:self.bounds];

    [[NSColor blackColor] set];
    [NSBezierPath setDefaultLineWidth:2.0];
    NSRect insetRect = NSInsetRect(self.bounds, 1, 1);
    [NSBezierPath strokeRect:insetRect];

    NSString *text = @"Restart Game";
    NSRect textRect = NSMakeRect(20, -15, self.bounds.size.width, self.bounds.size.height);

    NSDictionary *textAttributes = @{ NSFontAttributeName : [NSFont fontWithName:@"Andale Mono" size:16.0f],
                                      NSForegroundColorAttributeName : [NSColor blackColor] };
    [text drawInRect:textRect withAttributes:textAttributes];
}

- (void)performPress
{
    // Set down and release after momentary delay so the button flickers.
    [self pressDown];

    double delayInSeconds = 0.1;
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, delayInSeconds * NSEC_PER_SEC);
    dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
        [self pressUpInside:YES andHighlight:NO];
    });
}

- (void)pressDown
{
    self.depressed = YES;
    [self setNeedsDisplay:YES];
}

- (void)pressUpInside:(BOOL)inside andHighlight:(BOOL)shouldHighlight
{
    self.depressed = NO;
    [self setNeedsDisplay:YES];

    if ( inside )
    {
        [self.delegate buttonPressed:self];
    }
}

#pragma mark Keyboard events

- (void)keyDown:(NSEvent *)keyEvent
{
    NSString *characters = [keyEvent characters];

    if ([characters isEqualToString:@" "])
    {
        [self performPress];
    }
    else
    {
        [super keyDown:keyEvent];
    }
}

# pragma mark - Accessibility

- (NSString *)accessibilityLabel
{
    return NSLocalizedString(@"reset game", nil);
}

- (BOOL)accessibilityPerformPress
{
    [self.delegate buttonPressed:self];
    return YES;
}


@end
