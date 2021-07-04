/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                CurveManager.h
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/4
  *Description:             曲线信息的管理类
  *Others:
  *Function List:
**********************************************************************************/

#ifndef INTERPOLATIONSPLINE_CURVEMANAGER_H
#define INTERPOLATIONSPLINE_CURVEMANAGER_H

#include <vector>
#include <string>
#include <QPointF>

namespace InterpolationSplineUtil {

    class CurveManager {
    protected:
        std::vector<QPointF> interpolationPointList;
        std::vector<QPointF> pantingPointList;
    public:
        CurveManager();

        CurveManager(const std::vector<QPointF> &interpolationPointList, const std::vector<QPointF> &pantingPointList);

        CurveManager(const CurveManager &rhs);

        const std::vector<QPointF> &getInterpolationPointList() const;

        void setInterpolationPointList(const std::vector<QPointF> &interpolationPointList);

        const std::vector<QPointF> &getPantingPointList() const;

        void setPantingPointList(const std::vector<QPointF> &pantingPointList);

        CurveManager &operator=(const CurveManager &rhs);

    public:
        virtual std::string GeneratePantingPointList();
    };
}


#endif //INTERPOLATIONSPLINE_CURVEMANAGER_H
