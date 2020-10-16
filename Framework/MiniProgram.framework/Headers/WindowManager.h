//
//  WindowManager.h
//  MiniProgram
//
//  Created by meifenglin on 2019/5/7.
//  Copyright © 2019年 meifenglin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WindowManager : NSObject

// 允许在后台运行的小程序最大数量,默认3个
@property (nonatomic, assign) NSInteger cacheCount;

// 正在运行的所有小程序id
@property (nonatomic, copy) NSMutableArray *apps;

/**
 当小程序启动时触发
 @param appId 小程序ID
 */
- (void)handleLaunch:(NSString *)appId;

/**
 当小程序关闭时触发
 @param appId 小程序ID
 */
- (void)handleClose:(NSString *)appId;

/**
 当小程序从后台切换到前台时触发
 @param appId 小程序ID
 */
- (void)handleShow:(NSString *)appId;

/**
 当小程序从前台切换到后台时触发
 @param appId 小程序ID
 */
- (void)handleHide:(NSString *)appId;

/**
 判断小程序是否在运行
 @param appId 小程序ID
 */
- (BOOL)isAppRunning:(NSString *)appId;

/**
 获取当前正在运行的小程序id
 */
- (NSString *)currentAppId;
@end

