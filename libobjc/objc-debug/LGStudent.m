//
//  LGStudent.m
//  objc-debug
//
//  Created by Cooci on 2019/11/26.
//

#import "LGStudent.h"
#import "LGTeacher.h"

@implementation LGStudent
static LGTeacher * te;

+(void)load
{
    NSLog(@"%s",__func__);
}
@end
