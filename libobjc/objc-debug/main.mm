//
//  main.m
//  objc-debug
//
//  Created by Cooci on 2019/10/9.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "LGPerson.h"
#import "LGStudent.h"



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
    
        
        LGPerson *object = [LGPerson alloc];
        NSLog(@"Hello, World! %@",object);


    }
    return 0;
}


