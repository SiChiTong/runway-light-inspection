//
// Created by silverback on 11/12/20.
//

#ifndef RUNWAY_IMAGEPROC_POSITIONESTIMATOR_H
#define RUNWAY_IMAGEPROC_POSITIONESTIMATOR_H
#include <ros/ros.h>
#include <runway_ImageProc/MetersCoordinates.h>
#include <runway_ImageProc/MetersPointsArrays.h>
#include <runway_ImageProc/LightCoordinates.h>
#include <math.h>
#include <mutex>
#include <utility>

#define EARTHS_RADIUS 6378137
#define PI 3.14159265359
std::mutex mtx;

class SubscribeAndPublish
{
public:
    SubscribeAndPublish();
    void metersCallback(const runway_ImageProc::MetersPointsArrays::ConstPtr& msg);
    void gnssCallback(const runway_ImageProc::MetersPointsArrays::ConstPtr& msg);
private:
    std::pair<float,float> globalFrame_transform(float x, float y);
    ros::NodeHandle nh;
    ros::Publisher pub;
    ros::Subscriber meters_sub;
    ros::Subscriber gnss_sub;
    float gnss_x, gnss_y, gnss_rot;
};//End of class SubscribeAndPublish

#endif //RUNWAY_IMAGEPROC_POSITIONESTIMATOR_H
