//
//  TICClassroomViewController.h
//  TIC_SaaS
//
//  Created by jameskhdeng(邓凯辉) on 2019/3/8.
//  Copyright © 2019 Tencent. All rights reserved.
//  课堂主页

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol TICEventListener, TICMessageListener;
@interface TICClassParams : NSObject
@property (nonatomic, copy) NSString *classId;
@property (nonatomic, copy) NSString *topic;
@property (nonatomic, copy) NSString *userID;
@property (nonatomic, copy) NSString *teacherID;
@property (nonatomic, assign) NSUInteger durationTime;
@end

@interface TICClassroomViewController : UIViewController <TICEventListener, TICMessageListener>

    
/**
初始化接口

@param classId 课堂ID
*/
- (instancetype)initWithClassId:(NSString *)classId;
    
/**
 请用 initWithClassId: 方法初始化 TICClassroomViewController，而不是下面的方法
 */
- (instancetype)init __attribute__((unavailable("Please use 'initWithClassId:' instead")));
- (instancetype)new __attribute__((unavailable("Please use ’initWithClassId:’ instead")));

@end

NS_ASSUME_NONNULL_END
