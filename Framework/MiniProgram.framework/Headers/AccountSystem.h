//
//  AccountSystem.h
//  MiniProgram
//
//  Created by meifenglin on 2019/9/2.
//  Copyright © 2019 meifenglin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AccountSystemResponse.h"

@interface AccountSystem : NSObject

// 获取当前用户信息
- (void)getCurrentUser:(AccountSystemResponse *)response;

@end

