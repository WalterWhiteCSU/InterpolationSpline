/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                BezierManager.h
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/4
  *Description:             管理贝塞尔曲线信息
  *Others:
  *Function List:
**********************************************************************************/

#ifndef INTERPOLATIONSPLINE_BEZIERMANAGER_H
#define INTERPOLATIONSPLINE_BEZIERMANAGER_H

#include <vector>
#include <string>
#include <QPointF>
#include "CurveManager.h"

namespace InterpolationSplineUtil {

    class BezierManager : public CurveManager {
    private:
        std::vector<QPointF> controlPointList;
    public:
        BezierManager();

        BezierManager(const CurveManager &rhs);

        BezierManager(const std::vector<QPointF> &interpolationPointList, const std::vector<QPointF> &pantingPointList,
                      const std::vector<QPointF> &controlPoint);

        BezierManager(const BezierManager &rhs);

        const std::vector<QPointF> &getControlPoint() const;

        void setControlPoint(const std::vector<QPointF> &controlPoint);

        BezierManager &operator=(const BezierManager &rhs);

    private:
        QPointF GetControlPointByTwoPoint(QPointF begin, QPointF end);

        std::vector<QPointF> GetControlPointByThreePoint(QPointF begin, QPointF middle, QPointF end);

        std::vector<QPointF> GetSingleBazierList(QPointF first, QPointF second, QPointF third, QPointF last);

    public:
        std::string GenerateControlPointList();

        std::string GeneratePantingPointList() override;
    };
}


#endif //INTERPOLATIONSPLINE_BEZIERMANAGER_H
