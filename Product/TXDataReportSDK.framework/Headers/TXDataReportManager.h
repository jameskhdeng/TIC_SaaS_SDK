//
//  TXDataReportManager.h
//  test_data_report
//
//  Created by jameskhdeng on 2019/1/28.
//  Copyright © 2019 Tencent. All rights reserved.
//  数据上报管理类

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TXDataReportConfig;
@interface TXDataReportManager : NSObject

@property (nonatomic, assign) BOOL isOpenConsoleLog;     //!< 是否打开上报数据控制台输出

/**
 @brief 获取单例对象
 
 @return 单例对象
 */
+ (instancetype)sharedInstance;

/**
 @brief 上报配置，需要所有上报前进行
 */
- (void)setConfig:(TXDataReportConfig *)config;

/**
 @brief 上报日志
 */
- (void)reportLogData:(NSDictionary *)dataDic;

/**
 @brief 上报事件
 */
- (void)reportEventData:(NSDictionary *)dataDic;

/**
 @brief 上报日志，带回调
 
 @param succ 成功回调
 @param fail 失败回调
 */
- (void)reportLogData:(NSDictionary *)dataDic succ:(void(^ __nullable)(void))succ fail:(void(^ __nullable)(NSError *error))fail;

/**
 @brief 上报事件，带回调
 
 @param succ 成功回调
 @param fail 失败回调
 */
- (void)reportEventData:(NSDictionary *)dataDic succ:( void(^ _Nullable )(void))succ fail:(void(^ __nullable)(NSError *error))fail;

@end

@interface TXDataReportConfig : NSObject
@property (nonatomic, copy) NSString *dcid;     //!< 接口ID
@end

NS_ASSUME_NONNULL_END
