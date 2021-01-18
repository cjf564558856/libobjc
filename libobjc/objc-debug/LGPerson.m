//
//  LGPerson.m
//  objc-debug
//
//  Created by Cooci on 2019/10/28.
//

#import "LGPerson.h"

@implementation LGPerson

- (void)saySomething{
    NSLog(@"%s",__func__);
}
+ (void)sayNB{
    NSLog(@"%s",__func__);
}

@end
