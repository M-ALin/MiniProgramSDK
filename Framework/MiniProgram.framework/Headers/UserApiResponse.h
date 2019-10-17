//
//  UserApiResponse.h
//  MiniProgram
//
//  Created by meifenglin on 2019/6/19.
//  Copyright © 2019 meifenglin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UserApiResponse : NSObject

/// 返回正确结果的回调
@property (nonatomic, copy) void (^resolve) (id result);

/// 返回错误结果的回调
@property (nonatomic, copy) void (^reject) (id error);
@end

