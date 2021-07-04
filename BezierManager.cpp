/*********************************************************************************
  *Copyright(C),WalterWhite
  *FileName:                BezierManager.cpp.cc
  *Author:                  Walter White
  *Version:                 0.1
  *Date:                    2021/7/4
  *Description:
  *Others:
  *Function List:
**********************************************************************************/

#include "BezierManager.h"

namespace InterpolationSplineUtil {

    BezierManager::BezierManager() {}

    BezierManager::BezierManager(const CurveManager &rhs) : CurveManager(rhs) {}

    BezierManager::BezierManager(const std::vector<QPointF> &interpolationPointList,
                                 const std::vector<QPointF> &pantingPointList, const std::vector<QPointF> &controlPoint)
            : CurveManager(interpolationPointList, pantingPointList), controlPointList(controlPoint) {}

    BezierManager::BezierManager(const BezierManager &rhs) {
        this->interpolationPointList = rhs.interpolationPointList;
        this->pantingPointList = rhs.pantingPointList;
        this->controlPointList = rhs.controlPointList;
    }

    const std::vector<QPointF> &BezierManager::getControlPoint() const {
        return controlPointList;
    }

    void BezierManager::setControlPoint(const std::vector<QPointF> &controlPoint) {
        BezierManager::controlPointList = controlPoint;
    }

    BezierManager &BezierManager::operator=(const BezierManager &rhs) {
        if (this != &rhs) {
            this->interpolationPointList = rhs.interpolationPointList;
            this->pantingPointList = rhs.pantingPointList;
            this->controlPointList = rhs.controlPointList;
        }
        return *this;
    }

    std::string BezierManager::GenerateControlPointList() {
        this->controlPointList.clear();
        if (this->interpolationPointList.empty())
            return "ERROR::The Interpolation Point List is empty";

        auto pointList = this->interpolationPointList;
        int count = pointList.size();

        //  先加入第一个点
        this->controlPointList.push_back(pointList[0]);
        //  再加入第二个
        this->controlPointList.push_back(this->GetControlPointByTwoPoint(pointList[0], pointList[1]));

        //  对中间的点进行遍历处理
        for (int i = 1; i < count - 1; ++i) {
            auto tempPointList = this->GetControlPointByThreePoint(pointList[i - 1], pointList[i], pointList[i + 1]);
            this->controlPointList.insert(this->controlPointList.end(), tempPointList.begin(), tempPointList.end());
        }

        //  对最后的点进行赋值
        this->controlPointList.push_back(
                this->GetControlPointByTwoPoint(pointList[count - 2], pointList[count - 1]));
        this->controlPointList.push_back(pointList[count - 1]);

        return "Success!";
    }

    std::string BezierManager::GeneratePantingPointList() {
        this->pantingPointList.clear();

        for (int i = 3; i < controlPointList.size(); ++i) {
            auto model = GetSingleBazierList(controlPointList[i - 3], controlPointList[i - 2], controlPointList[i - 1],
                                             controlPointList[i]);
            this->pantingPointList.insert(pantingPointList.end(), model.begin(), model.end());
        }

        return "Success!";
    }

    QPointF BezierManager::GetControlPointByTwoPoint(QPointF begin, QPointF end) {
        QPointF res;

        auto x = end.x() - begin.x();
        x /= 4.0f;
        auto y = end.y() - begin.y();
        y /= 4.0f;
        res.setX(x);
        res.setY(y);

        return res;
    }

    std::vector<QPointF> BezierManager::GetControlPointByThreePoint(QPointF begin, QPointF middle, QPointF end) {
        std::vector<QPointF> res;

        QPointF directionVec{(end.x() - begin.x()) / 4.0f, (end.y() - begin.y()) / 4.0f};
        QPointF first{middle.x() - directionVec.x(), middle.y() - directionVec.y()};
        QPointF last{middle.x() + directionVec.x(), middle.y() + directionVec.y()};

        res.push_back(first);
        res.push_back(middle);
        res.push_back(last);

        return res;
    }

    std::vector<QPointF>
    BezierManager::GetSingleBazierList(QPointF first, QPointF second, QPointF third, QPointF last) {
        std::vector<QPointF> res;

        //  加入第一个点
        res.push_back(first);

        while ()

        //  加入最后一个点
        res.push_back(last);
        return res;
    }

}