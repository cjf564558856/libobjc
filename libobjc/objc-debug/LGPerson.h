//
//  LGPerson.h
//  objc-debug
//
//  Created by Cooci on 2019/10/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LGPerson : NSObject
@property (nonatomic, copy) NSString *pName;
@property (nonatomic, assign) int pAge;

- (void)saySomething;
+ (void)sayNB;

@end

NS_ASSUME_NONNULL_END
