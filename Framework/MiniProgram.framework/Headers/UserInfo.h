//
//  UserInfo.h
//  MiniProgram
//
//  Created by meifenglin on 2019/10/24.
//  Copyright © 2019 meifenglin. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    UserGenderTypeUnknown = 0,
    UserGenderTypeMan,
    UserGenderTypeWoman
} UserGenderType;

@interface UserInfo : NSObject
// 用户id
@property (nonatomic, strong) NSString *uid;
// 用户token
@property (nonatomic, strong) NSString *token;
// 用户昵称
@property (nonatomic, strong) NSString *nickname;
// 用户头像（base64编码）
@property (nonatomic, strong) NSString *avatar;
// 用户性别 0-未知 1-男 2-女
@property (nonatomic, assign) UserGenderType gender;
// 用户所在国家
@property (nonatomic, strong) NSString *country;
// 用户所在省份
@property (nonatomic, strong) NSString *province;
// 用户所在城市
@property (nonatomic, strong) NSString *city;
// 拓展字段
@property (nonatomic, strong) NSDictionary *extra;
@end
