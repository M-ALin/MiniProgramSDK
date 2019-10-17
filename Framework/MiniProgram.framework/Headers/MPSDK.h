//
//  MPSDK.h
//  MiniProgram
//
//  Created by meifenglin on 2019/5/7.
//  Copyright © 2019年 meifenglin. All rights reserved.
//

#import <Foundation/Foundation.h>
@class WindowManager;
@class Config;
@class MiniProgramWindow;

@interface MPSDK : NSObject

/// MPSDK单例
+ (instancetype)sharedInstance;

/// 窗口管理器(Default和LRU两种方式)
@property (nonatomic, strong) WindowManager *windowManager;

/// 当前显示小程序的UIWindow
@property (nonatomic, strong) MiniProgramWindow *currentMiniWindow;

/**
 初始化SDK
 *config SDK配置
*/
- (void)initWithConfig:(Config *)config;

/**
 launchMain类似launchApp，但main app右上角没有关闭按钮，并且也不允许调用closeApp来关闭它。launchApp启动的小程序返回到main app， 类似于小程序列表，小程序管理页面，
 *appId 小程序id
 */
- (void)launchMain:(NSString *)appId;

/**
 打开小程序
 *appId 小程序id
 */
- (void)launchApp:(NSString *)appId;

/**
 打开小程序
 *appId 小程序id
 *path 要打开的小程序指定页面的相对路径， 没有默认进入首页
 *query 要打开的小程序指定页面的查询参数
 */
- (void)launchAppOpt:(NSString *)appId path:(NSString *)path query:(NSDictionary *)query;

/**
 打开指定URL
 *url 要打开的url
*/
-(void)launchURL:(NSString *)url;

/**
 隐藏小程序到后台
 *appId 小程序id
 */
- (void)hideApp:(NSString *)appId;

/**
 关闭小程序
 *appId 小程序id
 */
- (void)closeApp:(NSString *)appId;

/**
 关闭所有小程序
 */
- (void)closeAllApp;

/**
 卸载小程序
 *appId 小程序id
 */
- (void)removeApp:(NSString *)appId;

/**
 获取小程序信息
 *appId 小程序id
 */
- (NSDictionary *)getAppInfo:(NSString *)appId;

/**
 获取SDK版本号
*/
- (NSString *)version;

@end

