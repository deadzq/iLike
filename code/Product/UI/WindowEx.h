/*基于捂脸猫FaceCat框架 v1.0 https://github.com/FaceCat007/facecat.git
 1.创始人-矿洞程序员-上海宁米科技创始人-脉脉KOL-陶德 (微信号:suade1984);
 2.联合创始人-上海宁米科技创始人-袁立涛(微信号:wx627378127);
 3.联合创始人-肖添龙(微信号:xiaotianlong_luu);
 4.联合开发者-陈晓阳(微信号:chenxiaoyangzxy)，助理-朱炜(微信号:cnnic_zhu);
 5.该程序开源协议为BSD，欢迎对我们的创业活动进行各种支持，欢迎更多开发者加入。
 */

#ifndef __WINDOWEX_H__
#define __WINDOWEX_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "FCDraw.h"
#include "WindowButton.h"

typedef enum WindowStateA{
	WindowStateA_Max,
	WindowStateA_Min,
	WindowStateA_Normal
};

//自定义窗体
class WindowEx : public FCWindow{
private:
	int m_animateDirection;
	bool m_animateMoving;
	int m_animateType;
	WindowButton *m_closeButton;
	bool m_isChildWindow;
	WindowButton *m_maxOrRestoreButton;
	WindowButton *m_minButton;
	FCPoint m_normalLocation;
	FCSize m_normalSize;
	bool m_showMaxBox;
	bool m_showMinBox;
	int m_timerID;
	WindowStateA m_windowState;
private:
	static void clickButton(void *sender, FCTouchInfo touchInfo, void *pInvoke);
public:
	WindowEx();
	virtual ~WindowEx();
	//是否动画
	bool isAnimateMoving();
	//关闭按钮
	WindowButton* getCloseButton();
	void setCloseButton(WindowButton* closeButton);
	//是否子窗体
	bool isChildWindow();
	void setChildWindow(bool isChildWindow);
	//最大化按钮
	WindowButton* getMaxOrRestoreButton();
	void setMaxOrRestoreButton(WindowButton *maxOrRestoreButton);
	//最小化按钮
	WindowButton* getMinButton();
	void setMinButton(WindowButton *minButton);
	//是否显示最大化按钮
	bool showMaxBox();
	void setShowMaxBox(bool showMaxBox);
	//是否显示最小化按钮
	bool showMinBox();
	void setShowMinBox(bool showMinBox);
	//窗体状态
	WindowStateA getWindowState();
	void setWindowState(WindowStateA windowState);
public:
	//动画隐藏
	void animateHide();
	//动画显示
	void animateShow(bool showDialog);
	//获取属性
	virtual void getProperty(const String& name, String *value, String *type);
	//获取属性列表
	virtual ArrayList<String> getPropertyNames();
	//最大化
	void maxWindow();
	//最大化
	void maxOrRestore();
	//最小化
	void minWindow();
	//控件添加方法
	virtual void onAdd();
	//拖动控件开始方法
	virtual void onDragReady(FCPoint *startOffset);
	//重绘背景方法
	virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
	//秒表方法
	virtual void onTimer(int timerID);
	//恢复
	void restore();
	//设置属性
	virtual void setProperty(const String& name, const String& value);
	//控件布局更新方法
	virtual void update();
};
#endif