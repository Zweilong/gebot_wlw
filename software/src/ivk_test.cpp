
#include"robotcontrol.h"
#include "ADS1x15.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <atomic>
#include <boost/lockfree/spsc_queue.hpp>

int LastJointPos = 0;

int main()
{
    CLeg* leg_rf = new CLeg(RF,65.5,84.0,21.0);
    Matrix<float, 1, 3> cmdpos = {84.0/1000, -65.5/1000, -21.0/1000};  //基坐标系下的末端位置
    float theta4 = 0.0f; //默认垂直于水平面theta4是0
    Matrix<float,3,1> jointCmdPos;
    jointCmdPos = leg_rf->InverseKinematic(cmdpos, theta4);
    // Matrix<float,3,1> jointCmdPos;
    // float L1=65.5,L2=84,L3=21;
    // float factor_x, factor_y, factor_z, factor_1, factor_2, factor_0;
    // float x, y, z;
    
    // x = cmdpos(0, 0);
    // y = cmdpos(0, 1);
    // z = cmdpos(0, 2);
    // // std::cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<std::endl; ---ok
    // x = x;
    // y = y - L3*sin(theta4);
    // z = z + L3*cos(theta4);
    // std::cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<std::endl;
    // L3 = 0;

    // float temp[3];
    // temp[0]=x;
    // temp[1]=y;
    // temp[2]=z;
    // x=-temp[1];
    // y=-temp[2];
    // z=temp[0];
    // std::cout<<"temp: "<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<std::endl;
    // jointCmdPos(0, 0)=atan2(-L3+y,x);
    // float c1=cos(jointCmdPos(0, 0)),s1=sin(jointCmdPos(0, 0));
    // float tmp1 = atan2(L3*s1,L2);
    // float tmp2 = atan2((x*x+y*y+z*z-(L1 * L1 + L2 * L2 + L3 * L3))/(2*L1),sqrt((L3*s1)*(L3*s1)+L2*L2-(((x*x+y*y+z*z)-(L1 * L1 + L2 * L2 + L3 * L3))/(2*L1))*(((x*x+y*y+z*z)-(L1 * L1 + L2 * L2 + L3 * L3))/(2*L1))));
    // std::cout<<"tmp1: "<<tmp1<<"tmp2: "<<tmp2<<std::endl;
    // jointCmdPos(2, 0)=tmp1-tmp2;
    // float c3=cos(jointCmdPos(2, 0)),s3=sin(jointCmdPos(2, 0));
    // jointCmdPos(1, 0)=atan2(-L2*c3-L3*s1*s3,L1-L2*s3+L3*s1*c3)-atan2(-z,sqrt((-L2*c3-L3*s1*s3)*(-L2*c3-L3*s1*s3)+(L1-L2*s3+L3*s1*c3)*(L1-L2*s3+L3*s1*c3)-z*z));   
   
    std::cout << "Joint Command Position: " << jointCmdPos.transpose() << std::endl;
}