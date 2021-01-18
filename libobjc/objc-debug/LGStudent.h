//
//  LGStudent.h
//  objc-debug
//
//  Created by Cooci on 2019/11/26.
//

#import "LGPerson.h"
#import "LGTeacher.h"

NS_ASSUME_NONNULL_BEGIN

@interface LGStudent : LGPerson
@property (nonatomic, strong) LGTeacher *teacher;
@end

NS_ASSUME_NONNULL_END
