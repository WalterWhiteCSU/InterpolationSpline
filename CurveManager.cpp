/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                CurveManager.cpp.cc
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/4
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#include "CurveManager.h"

namespace InterpolationSplineUtil {

    CurveManager::CurveManager() {}

    CurveManager::CurveManager(const std::vector<QPointF> &interpolationPointList,
                               const std::vector<QPointF> &pantingPointList) : interpolationPointList(
            interpolationPointList), pantingPointList(pantingPointList) {}

    CurveManager::CurveManager(const CurveManager &rhs) {
        this->interpolationPointList = rhs.interpolationPointList;
        this->pantingPointList = rhs.pantingPointList;
    }

    const std::vector<QPointF> &CurveManager::getInterpolationPointList() const {
        return interpolationPointList;
    }

    void CurveManager::setInterpolationPointList(const std::vector<QPointF> &interpolationPointList) {
        CurveManager::interpolationPointList = interpolationPointList;
    }

    const std::vector<QPointF> &CurveManager::getPantingPointList() const {
        return pantingPointList;
    }

    void CurveManager::setPantingPointList(const std::vector<QPointF> &pantingPointList) {
        CurveManager::pantingPointList = pantingPointList;
    }

    CurveManager &CurveManager::operator=(const CurveManager &rhs) {
        if (this != &rhs) {
            this->interpolationPointList = rhs.interpolationPointList;
            this->pantingPointList = rhs.pantingPointList;
        }
        return *this;
    }
}
