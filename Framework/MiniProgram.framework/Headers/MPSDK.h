//
//  MPSDK.h
//  MiniProgram
//
//  Created by meifenglin on 2019/5/7.
//  Copyright © 2019年 meifenglin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// 用户账号信息发生改变类型
typedef enum : NSUInteger {
    UserAccountEventTypeLogin = 0,
    UserAccountEventTypeLogout,
    UserAccountEventTypeChanged
} UserAccountEventType;

// 启动小程序参数
typedef struct LaunchOptions{
    NSString *offlineAssetsPath; // 本地离线包路径
}LaunchOptions;

static inline LaunchOptions LaunchOptionsMake(NSString *path){
    LaunchOptions opt;
    opt.offlineAssetsPath = path;
    return opt;
}

@class WindowManager;
@class Config;
@class MiniProgramWindow;

@interface MPSDK : NSObject

// MPSDK单例
+ (instancetype)sharedInstance;

// 窗口管理器(Default和LRU两种方式)
@property (nonatomic, strong) WindowManager *windowManager;

// 当前显示小程序的UIWindow
@property (nonatomic, strong) MiniProgramWindow *currentMiniWindow;

/**
 初始化SDK
 @param config SDK配置
*/
- (void)initWithConfig:(Config *)config;

/**
 启动主小程序，类似launchApp，但main App右上角没有关闭按钮，并且也不允许调用closeApp来关闭它。在main App启动的小程序返回到main App， main App可以实现类似于小程序列表，小程序管理页面
 @param appId 小程序id
 @param completion 启动小程序回调 success: YES:启动小程序成功 NO:启动小程序失败 msg:回调信息
 */
- (void)launchMain:(NSString *)appId completion:(void(^)(BOOL success, NSString *msg))completion;

/**
 启动小程序
 @param appId 小程序id
 @param completion 启动小程序回调 success: YES:启动小程序成功 NO:启动小程序失败 msg:回调信息
 */
- (void)launchApp:(NSString *)appId completion:(void(^)(BOOL success, NSString *msg))completion;

/**
启动小程序
@param appId 小程序id
@param options 启动参数
@param completion 启动小程序回调 success: YES:启动小程序成功 NO:启动小程序失败 msg:回调信息
*/
- (void)launchApp:(NSString *)appId options:(LaunchOptions)options completion:(void (^)(BOOL success, NSString *msg))completion;

/**
 启动小程序，并跳转至指定页面，传递页面参数
 @param appId 小程序id
 @param path 要打开的小程序指定页面的相对路径， 没有则默认进入首页
 @param query 传递给指定页面的参数
 @param completion 启动小程序回调 success: YES:启动小程序成功 NO:启动小程序失败 msg:回调信息
 */
- (void)launchAppOpt:(NSString *)appId path:(NSString *)path query:(NSString *)query completion:(void(^)(BOOL success, NSString *msg))completion;

/**
 打开指定URL
 @param url 要打开的url
 @param completion 打开指定URL回调 success: YES:打开指定URL成功 NO:打开指定URL失败 msg:回调信息
*/
-(void)launchURL:(NSString *)url completion:(void(^)(BOOL success, NSString *msg))completion;

/**
 打开单页面小程序，push出加载小程序的控制器，不单独创建window，与宿主程序导航控制器结合
 @param appId 小程序id
 @param completion 启动回调 success: YES:启动成功 NO:启动失败 msg:回调信息
 */
- (UIViewController *)startAppWithAppId:(NSString *)appId completion:(void(^)(BOOL success, NSString *msg))completion;

/**
 隐藏小程序到后台
 @param appId 小程序id
 */
- (void)hideApp:(NSString *)appId;

/**
 关闭小程序
 @param appId 小程序id
 */
- (void)closeApp:(NSString *)appId;

/**
 关闭所有小程序
 */
- (void)closeAllApp;

/**
 卸载小程序
 @param appId 小程序id
 */
- (void)removeApp:(NSString *)appId;

/**
 获取小程序信息
 @param appId 小程序id
 */
- (NSDictionary *)getAppInfo:(NSString *)appId;

/**
 获取SDK版本号
*/
- (NSString *)version;

/**
 判断SDK是否已经初始化
 */
- (BOOL)checkSDKIsInitialized;

/**
 用户信息发生改变事件
 @param eventType 事件类型
*/
- (void)fireAccountEvent:(UserAccountEventType)eventType;

@end

