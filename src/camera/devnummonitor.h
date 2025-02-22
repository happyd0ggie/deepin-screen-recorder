/*
* Copyright (C) 2020 ~ 2021 Uniontech Software Technology Co.,Ltd.
*
* Author:     shicetu <shicetu@uniontech.com>
*             hujianbo <hujianbo@uniontech.com>
* Maintainer: shicetu <shicetu@uniontech.com>
*             hujianbo <hujianbo@uniontech.com>
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

#ifndef DEVNUMMONITOR_H
#define DEVNUMMONITOR_H

#include <QThread>
#include <QTimer>

#ifdef __cplusplus
extern "C" {
#endif
#include "LPF_V4L2.h"
#include "v4l2_core.h"
#include"v4l2_devices.h"
#include "stdlib.h"
#include "malloc.h"
#include "stdio.h"
#include "math.h"

#ifdef __cplusplus
}
#endif

/**
* @brief DevNumMonitor　设备数目监视器
*/
class DevNumMonitor: public QObject
{
    Q_OBJECT
public:
    explicit DevNumMonitor();

    ~DevNumMonitor();


    void setWatch(const bool isWatcher);

    /**
     * @brief setCanUse:存在一种特殊的情况，就是摄像头被占用，使用v4l2无法判断，需加上QCameraInfo来判断
     * 但是使用QCameraInfo来判断需要有一个范围
     * 在录屏应用未打开摄像头时，可以使用这个判断
     * 在录屏应用打开摄像头时，不可使用这个判断
     * @param canUse
     */
    void setCanUse(bool canUse);
signals:
    /**
     * @brief existDevice 存在摄像头设备信号
     * @param isExist: false:不存在 true:存在
     */
    void existDevice(bool isExist);

protected:
    /**
    * @brief run 运行
    */
    //void run();
    /**
    * @brief init 初始化
    */
    void init();
private slots:
    /**
    * @brief timeOutSlot 监视设备数目槽，根据相机数目执行相应的处理
    */
    void timeOutSlot();

private:
    QTimer             *m_pTimer;
    bool               m_noDevice;
    bool m_canUse;

};

#endif // DEVNUMMONITOR_H
