# Accessible Tic Tac Toe

This sample contains a game with several custom controls and code to make them accessible, including using the accessibility methods of NSControl subclasses and implementing accessibility protocols for custom elements.

## Requirements

### Build

Xcode 6.0 or later; OS X 10.10 SDK or later

### Runtime

OS X 10.10 or later

Copyright (C) 2014-16 Apple Inc. All rights reserved.

## Major files and folders

### Models

This folder contains all the files that define a game of tic tac toe. There is no accessibility code in these files.

### Views

This folder contains all the files that define the UI for the game. Most of the accessibility code for this application can be found in these files under the section marked `#pragma mark - Accessibility`.

#### AAPLTicTacToeButtonView

An NSView that behaves like a button and implements the NSAccessibilityButton protocol.

#### AAPLTicTacToeCheckboxView

An NSView that behaves like a checkbox and implements the NSAccessibilityCheckbox protocol.

#### AAPLTicTacToeBoardView

An NSView that draws many individual items and implements the NSAccessibilityGroup protocol.

#### AAPLTicTacToeSquareAccessibilityElement

An NSAccessibilityElement subclass that demonstrates how to create an interactive accessibility object for UI with no backing view.

### Controllers

#### AAPLTicTacToeViewController

View controller demonstrating accessibility announcements.

### MainMenu.xib

#### Tic Tac Toe Circle Plus and Minus Button Views

NSButton subclasses that demonstrate adding an accessibility information in Interface Builder by editing the Accessibiliity Identity section of the Indentity Inspector.
