//
//  TICClassroomViewController.h
//  TIC_SaaS
//
//  Created by jameskhdeng(邓凯辉) on 2019/3/8.
//  Copyright © 2019 Tencent. All rights reserved.
//  课堂主页控制器，只支持横屏展示

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@interface TICClassroomViewController : UIViewController

/**
初始化接口

@param classId 课堂ID
*/
- (instancetype)initWithClassId:(NSString *)classId;

/**
初始化接口

@param classId 课堂ID
 @param isOnlyStudent 移动端是否仅允许学生进入课堂，老师端进入会提示在桌面端登录（默认是NO）
*/
- (instancetype)initWithClassId:(NSString *)classId onlyStudent:(BOOL)isOnlyStudent;
    
/**
 请用 initWithClassId: 方法初始化 TICClassroomViewController，而不是下面的方法
 */
- (instancetype)init __attribute__((unavailable("Please use 'initWithClassId:' instead")));
- (instancetype)new __attribute__((unavailable("Please use ’initWithClassId:’ instead")));
- (instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((unavailable("Please use ’initWithClassId:’ instead")));
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil __attribute__((unavailable("Please use ’initWithClassId:’ instead")));

@end

NS_ASSUME_NONNULL_END
