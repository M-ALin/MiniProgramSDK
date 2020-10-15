//
//  Config.h
//  MiniProgram
//
//  Created by meifenglin on 2019/5/10.
//  Copyright © 2019年 meifenglin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class WindowManager;
@class AccountSystem;

@interface Config : NSObject

// Config单例
+ (instancetype)defaultConfig;

// 窗口管理器(Default和LRU两种方式)
@property (nonatomic, strong) WindowManager *windowManager;

// 指定小程序的本地存储路径,必须为合法路径。当传入nil时，默认设置Document目录
@property (nonatomic, strong) NSString *storagePath;

// 指定小程序服务器地址
@property (nonatomic, strong) NSString *host;

// 是否打开小程序网络请求时进行域名白名单拦截功能
@property (nonatomic, assign) BOOL isCheckHostValid;

/**
 注册自定义账号系统
 @param accountSystem 获取账号信息实现类的实例
 */
- (void)setAccountSystem:(AccountSystem *)accountSystem;

/**
 注册自定义API
 @param package 自定义API名称
 @param object 自定义方法的实现类
 @param context 实现类需要传递给调用类的数据
 */
- (void)createPackage:(NSString *)package object:(NSObject *)object context:(id)context;

- (NSArray *)getPackages;

- (void)setupAccountSystemWithMethod:(id)method params:(id)params callback:(void (^)(id result, id err))callback;

- (void)setupUserApiWithMethod:(id)method params:(id)params callback:(void (^)(id result, id err))callback;
@end

