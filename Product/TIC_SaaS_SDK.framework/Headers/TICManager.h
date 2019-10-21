//
//  TICManager.h
//  Pods
//
//  Created by jameskhdeng(邓凯辉) on 2019/7/10.
//  对外接口


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
extern NSString * const TICNotificationUserForceOffline;    //!< 用户 IM 账号被踢通知
extern NSString * const TICNotificationUserSigExpired;      //!< 用户 IM 账号 usersig 过期通知


@class TICClassroomConfig, TICVisitorClassroomConfig, TICCompanyInfo;
@interface TICManager : NSObject

/**
 * 获取单例
 **/
+ (instancetype)sharedInstance;

/**
 获取SDK版本号
 */
+ (NSString *)getVersion;

/**
 初始化组件，默认开启 bugly，建议 App 启动时调用

 @param sdkAppId 腾讯云应用程序标识
 @param callback 回调
 */
- (void)initWithSdkAppId:(int)sdkAppId callback:(void (^)(int code, NSString *desc))callback;


/**
  初始化组件，建议 App 启动时调用

 @param sdkAppId 腾讯云应用程序标识
 @param isOpen 是否开启SDK内 bugly 模块
 @param callback 回调
 
 @discussion 如用户自己的 App 也用到了 bugly，建议关闭 SDK 内的bug
 */
- (void)initWithSdkAppId:(int)sdkAppId openBugly:(BOOL)isOpen callback:(void (^)(int code, NSString *desc))callback;


/**
  学生加入课堂

 @param config 课堂配置
 @param succ 成功回调
 @param failed 失败回调
 */
- (void)joinClassroomWith:(TICClassroomConfig *)config succ:(void (^)(void))succ failed:(void (^)(int code, NSString *errMsg))failed;

/**
 游客加入课堂
 
 @param config 课堂配置
 @param succ 成功回调
 @param failed 失败回调
 */
- (void)visitorJoinClassroomWith:(TICVisitorClassroomConfig *)config succ:(void (^)(void))succ failed:(void (^)(int code, NSString *errMsg))failed;


/**
 通过机构ID获取机构信息

 @param companyID 机构ID
 */
- (void)getCompanyInfoWithCompanyID:(int)companyID succ:(void (^)(TICCompanyInfo *companyInfo))succ failed:(void (^)(int code, NSString *errMsg))failed;

- (void)getSJInfoWithCompanyID:(int)companyID succ:(void (^)(NSDictionary *dic))succ failed:(void (^)(int code, NSString *errMsg))failed;

@end


/**
 课堂配置类，加入课堂时需传入这些信息，带✅的为必填项
 */
@interface TICClassroomConfig : NSObject
    
@property (nonatomic, copy) NSString *classID;  // 课堂ID✅
@property (nonatomic, copy) NSString *userID;   // 用户ID✅
@property (nonatomic, copy) NSString *userToken;// 用户密码✅
@property (nonatomic, strong) NSNumber *companyID;  // 机构码（腾讯云互动课堂后台为每个注册企业的分配唯一标识码）✅

@property (nonatomic, copy) NSString *userSig;  // 用户签名（没有在腾讯云互动课堂后台设置IM私钥的，必填；设置了IM私钥的填 nil）
@property (nonatomic, copy) NSString *password;   // 游客进房密码（游客进房必填，否则不用填）
    
@end

/**
 游客加入课堂配置类，加入课堂时需传入这些信息，带✅的为必填项
 */
@interface TICVisitorClassroomConfig : NSObject

@property (nonatomic, copy) NSString *classID;  // 课堂ID✅
@property (nonatomic, copy) NSString *nickname;   // 用户昵称✅
@property (nonatomic, copy) NSString *password;   // 游客进房密码

@end


/**
 机构信息模型类
 */
@interface TICCompanyInfo : NSObject

@property (nonatomic, strong) NSNumber *sdkappID;   // 腾讯云官网注册的SDKAppID
@property (nonatomic, copy) NSString *companyName;         // 公司名
@property (nonatomic, copy) NSString *iconUrl;         // 公司图标URL

@end
NS_ASSUME_NONNULL_END
