/*

 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 View controller for a tic-tac-toe game demonstrating accessible custom controls using the accessibility methods of NSControl subclasses, accessibility protocols, and NSAccessibilityElement.

 */

@import Cocoa;
#import "AAPLTicTacToeBoardView.h"
#import "AAPLTicTacToeButtonView.h"
#import "AAPLTicTacToeCircleMinusButtonView.h"
#import "AAPLTicTacToeCirclePlusButtonView.h"
#import "AAPLTicTacToeCheckboxView.h"

@interface AAPLTicTacToeViewController : NSViewController <AAPLTicTacToeButtonDelegate, AAPLTicTacToeBoardViewDelegate, AAPLTicTacToeCheckboxDelegate>

@property (weak) IBOutlet AAPLTicTacToeBoardView *boardView;
@property (weak) IBOutlet AAPLTicTacToeButtonView *resetGameButton;
@property (weak) IBOutlet NSTextField *statusText;
@property (weak) IBOutlet NSTextField *difficultyText;
@property (weak) IBOutlet AAPLTicTacToeCheckboxView *playAICheckbox;
@property (weak) IBOutlet AAPLTicTacToeCircleMinusButtonView *decreaseDifficultyButton;
@property (weak) IBOutlet AAPLTicTacToeCirclePlusButtonView *increaseDifficultyButton;

- (IBAction)decreaseDifficulty:(id)sender;
- (IBAction)increaseDifficulty:(id)sender;

- (IBAction)playTopLeft:(id)sender;
- (IBAction)playTop:(id)sender;
- (IBAction)playTopRight:(id)sender;
- (IBAction)playLeft:(id)sender;
- (IBAction)playCenter:(id)sender;
- (IBAction)playRight:(id)sender;
- (IBAction)playBottomLeft:(id)sender;
- (IBAction)playBottom:(id)sender;
- (IBAction)playBottomRight:(id)sender;

@end
