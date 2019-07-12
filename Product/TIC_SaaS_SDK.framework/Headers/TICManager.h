//
//  TICManager.h
//  Pods
//
//  Created by jameskhdeng(邓凯辉) on 2019/7/10.
//  对外接口

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class TICClassroomConfig;
@interface TICManager : NSObject

/**
 * 获取单例
 **/
+ (instancetype)sharedInstance;


/**
 初始化【建议 App 启动时调用】，默认开启 bugly

 @param sdkAppId 腾讯云应用程序标识
 @param callback 回调
 */
- (void)initWithSdkAppId:(int)sdkAppId callback:(void (^)(int code, NSString *desc))callback;


/**
  初始化【建议 App 启动时调用】

 @param sdkAppId 腾讯云应用程序标识
 @param isOpen 是否开启SDK内 bugly 模块
 @param callback 回调
 
 @discussion 如用户自己的 App 也用到了 bugly，建议关闭 SDK 内的bug
 */
- (void)initWithSdkAppId:(int)sdkAppId openBugly:(BOOL)isOpen callback:(void (^)(int code, NSString *desc))callback;


/**
 加入课堂

 @param config 课堂配置
 @param succ 成功回调
 @param failed 失败回调
 */
- (void)joinClassroomWith:(TICClassroomConfig *)config succ:(void (^)(void))succ failed:(void (^)(int code, NSString *errMsg))failed;

@end


/**
 课堂配置类
 */
@interface TICClassroomConfig : NSObject
@property (nonatomic, copy) NSString *classId;  // 课堂ID
@property (nonatomic, copy) NSString *userID;   // 用户ID
@property (nonatomic, copy) NSString *userToken;// 用户签名
@property (nonatomic, copy) NSString *userSig;  // 腾讯云用户签名
@end

NS_ASSUME_NONNULL_END
