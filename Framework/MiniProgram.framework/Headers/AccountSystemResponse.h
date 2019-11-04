//
//  AccountSystemResponse.h
//  MiniProgram
//
//  Created by meifenglin on 2019/9/9.
//  Copyright © 2019 meifenglin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UserInfo;

@interface AccountSystemResponse : NSObject

// 返回正确结果的回调
@property (nonatomic, copy) void (^resolve) (UserInfo *userInfo);

// 返回错误结果的回调
@property (nonatomic, copy) void (^reject) (NSString *errMsg);
@end

