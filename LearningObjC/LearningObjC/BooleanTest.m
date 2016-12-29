//
//  BooleanTest.m
//  LearningObjC
//
//  Created by wu di on 16/12/28.
//  Copyright © 2016年 wu di. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BooleanTest.h"



@implementation BooleanTest

////@example: Objc - objc class non-static method
-(void)booleanTestMethod
{
    bool a = YES;
    //NSLog(a);
    //@todo: convert bool to string
    NSLog(@"This is body method");
}

+(void) main
{
    //@example: Objc - objc class how to new Type s = new Type();
    BooleanTest *s = [[BooleanTest alloc] init];
    
    //@example: Objc - objc class how to call non-static method
    [s booleanTestMethod];
}

@end
