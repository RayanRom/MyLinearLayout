//
//  MyLinearLayout.h
//  MyLinearLayoutDEMO
//
//  Created by oybq on 15/2/12.
//  Copyright (c) 2015年. All rights reserved.
//

#import "MyLayoutBase.h"


@interface UIView(LinearLayoutExt)

//设置视图的高度或者宽度占用线性布局剩余空间比重，取值1>= weight >0。默认值是0表示不按比重来决定自身的高度或者宽度。当父视图是垂直线性布局时指定的是高度在父视图剩余高度中的比重，而当父视图是水平线性布局时则指定的是宽度在父视图剩余宽度中的比重。
//设置比重的目的是为了解决设置子视图的相对尺寸的问题，通过比重的设置可以不需要让子视图明确的指定具体的高度或者宽度。
@property(nonatomic, assign) CGFloat weight;

@end



/*
 线性布局，分为水平和垂直方向，根据添加进入的子视图的顺序依次从上到下或者从左到右依次的线条形式的排列。
 线性布局支持wrapContentHeight,wrapContentWidth特性
 */
@interface MyLinearLayout : MyLayoutBase


//用方向初始化一个线性布局
-(id)initWithOrientation:(LineViewOrientation)orientation;
+(id)linearLayoutWithOrientation:(LineViewOrientation)orientation;


//方向，默认是纵向的,请在布局视图建立后立即调用这个属性设置方向,对于垂直布局系统默认设置wrapContentHeight为YES，而对于水平布局则设置wrapContentWidth为YES
@property(nonatomic,assign) LineViewOrientation orientation;


//里面的所有子视图的停靠位置，默认是MGRAVITY_NONE，表示不控制子视图的停靠，可以分别控制水平和垂直的停靠位置
//具体参考MarignGravity中的值，通过设置子视图的停靠位置，则里面的所有子视图都将按统一的停靠方式进行布局和排列
@property(nonatomic, assign) MarignGravity gravity;


//均分子视图和间距,布局会根据里面的子视图的数量来平均分配子视图的高度或者宽度以及间距。
//这个函数只对已经加入布局的视图有效，函数调用后加入的子视图无效。
//centered属性描述是否所有子视图居中，当居中时顶部和底部会保留出间距，而不居中时则顶部和底部不保持间距
-(void)averageSubviews:(BOOL)centered;

//均分子视图，并指定固定的边距
-(void)averageSubviews:(BOOL)centered withMargin:(CGFloat)margin;

//均分子视图的间距，上面函数会使子视图和间距的尺寸保持一致，而这个函数则是子视图的尺寸保持不变而间距自动平均分配。
//centered的意义同上。
-(void)averageMargin:(BOOL)centered;


//指定子视图之间的间距,布局总是会为两个子视图之间添加这个间距值，默认为0
//这个属性的意义是当子视图之间的间距是固定时，不需要分别为每个子视图都设置相等的间距，而是设置一个值即可。
//这个属性通常和padding结合用来设置一些统一的边距值
@property(nonatomic, assign) CGFloat subviewMargin;



@end
