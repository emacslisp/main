//
//  ViewController.m
//  UICatalog
//
//  Created by eddy.wu on 6/27/17.
//  Copyright © 2017 eddy.wu. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

NSMutableArray *listOfMovies;

- (void)viewDidLoad {
    
    //----initialize the array----
    listOfMovies = [[NSMutableArray alloc] init];
    //----add items----
    [listOfMovies addObject:@"Training Day"];
    [listOfMovies addObject:@"Remember the Titans"];
    [listOfMovies addObject:@"John Q."];
    [listOfMovies addObject:@"The Bone Collector"];
    [listOfMovies addObject:@"Ricochet"];
    [listOfMovies addObject:@"The Siege"];
    [listOfMovies addObject:@"Malcolm X"];
    [listOfMovies addObject:@"Antwone Fisher"];
    [listOfMovies addObject:@"Courage Under Fire"];
    [listOfMovies addObject:@"He Got Game"];
    [listOfMovies addObject:@"The Pelican Brief"];
    [listOfMovies addObject:@"Glory"];
    [listOfMovies addObject:@"The Preacher’s Wife"];
    [super viewDidLoad];
    
}


- (UITableViewCell *)tableView:(UITableView *)tableView
         cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *CellIdentifier = @"Cell";
    //---try to get a reusable cell---
    UITableViewCell *cell =[tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    //----create new cell if no reusable cell is available----
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                      reuseIdentifier:CellIdentifier];
        
    }
    //----set the text to display for the cell----
    NSString *cellValue = [listOfMovies objectAtIndex:indexPath.row];
    cell.textLabel.text = cellValue;
    
    return cell;
}

//----set the number of rows in the table view----
- (NSInteger)tableView:(UITableView *)tableView
 numberOfRowsInSection:(NSInteger)section {
    return [listOfMovies count];
}

- (NSString *)tableView:(UITableView *)tableView
titleForHeaderInSection:(NSInteger)section{
    //---display “Movie List” as the header---
    return @"Movie List";
}
- (NSString *)tableView:(UITableView *)tableView
titleForFooterInSection:(NSInteger)section {
    return @"by Eddy Wu";
}

- (void) alert: (NSString*)title :(NSString *)message {
    UIAlertController * view=   [UIAlertController
                                 alertControllerWithTitle:title
                                 message:message
                                 preferredStyle:UIAlertControllerStyleActionSheet];
    
    UIAlertAction* ok = [UIAlertAction
                         actionWithTitle:@"OK"
                         style:UIAlertActionStyleDefault
                         handler:^(UIAlertAction * action)
                         {
                             //Do some thing here
                             [view dismissViewControllerAnimated:YES completion:nil];
                             
                         }];
    UIAlertAction* cancel = [UIAlertAction
                             actionWithTitle:@"Cancel"
                             style:UIAlertActionStyleDefault
                             handler:^(UIAlertAction * action)
                             {
                                 [view dismissViewControllerAnimated:YES completion:nil];
                                 
                             }];
    
    
    [view addAction:ok];
    [view addAction:cancel];
    [self presentViewController:view animated:YES completion:nil];
}

/*
 -(void) Show :(NSString *)title :(NSString *)message
 {
 UIAlertView *alert =
 [[UIAlertView alloc] initWithTitle:title
 message:message
 delegate:self
 cancelButtonTitle:@\"OK\"
 otherButtonTitles:nil];
 [alert show];
 }
 */

- (void) tableView:(UITableView *)tableView
didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSString *movieSelected = [listOfMovies objectAtIndex:indexPath.row];
    //NSString *message = [NSString stringWithFormat:@"You have selected %@",movieSelected];
  
    //[self alert:@"warn" :message];

        [self performSegueWithIdentifier:@"SegueTestView" sender:self];
    
}

// modify the height of Cell
- (CGFloat) tableView:(UITableView *)tableView
heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 70;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
