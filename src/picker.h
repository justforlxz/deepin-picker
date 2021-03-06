/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2011 ~ 2018 Deepin, Inc.
 *               2011 ~ 2018 Wang Yong
 *
 * Author:     Wang Yong <wangyong@deepin.com>
 * Maintainer: Wang Yong <wangyong@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */ 

#ifndef PICKER_H
#define PICKER_H

#include <QWidget>
#include <QMenu>
#include "colormenu.h"
#include "animation.h"
#include <QAction>
#include <QTimer>

class Picker : public QWidget
{
    Q_OBJECT
    
    Q_CLASSINFO("D-Bus Interface", "com.deepin.Picker")
    
    public:
    Picker(bool launchByDBus);
	~Picker(); 
             
    QColor getColorAtCursor(int x, int y);
                                         
signals:
    void copyColor(QColor color, QString colorType);
    void exit();
               
    Q_SCRIPTABLE void colorPicked(QString appid, QString color);
                 
public slots:
    void handleLeftButtonPress(int x, int y);
    void handleMouseMove(int x, int y);
    void handleRightButtonRelease(int x, int y);
    void popupColorMenu();
    void updateScreenshot();
    
    Q_SCRIPTABLE void StartPick(QString appid);
    
protected:
    void paintEvent(QPaintEvent *);
    
private:
    Animation *animation;
    ColorMenu *menu;
    QPixmap screenPixmap;
    QPixmap screenshotPixmap;
    QTimer *updateScreenshotTimer;
    QColor cursorColor;
    QPixmap shadowPixmap;
    bool displayCursorDot;
    int blockHeight;
    int blockWidth;
    int cursorX;
    int cursorY;
    int height;
    int screenshotSize;
    int width;
    int windowHeight;
    int windowWidth;
    bool isLaunchByDBus;
    QString appid;
};	

#endif
