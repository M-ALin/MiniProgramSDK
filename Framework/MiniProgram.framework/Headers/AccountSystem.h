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

/// 获取自定义账号系统的uid信息
- (void)getUid:(AccountSystemResponse *)response;;

/// 获取自定义账号系统的userInfo信息
- (void)getUserInfo:(AccountSystemResponse *)response;;
@end

