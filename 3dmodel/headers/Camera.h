/*
 * Camera.h
 *
 *  Created on: 27 lis 2013
 *      Author: Dawid
 */

#ifndef CAMERA_H_
#define CAMERA_H_
#include<Math.h>
#include<GL/gl.h>

struct StructCamera {

    struct Eye {
    	GLdouble x, y, z;
    } eye;

    struct Center {
    	GLdouble x, y, z;
    } center;

    struct Up {
        GLdouble x, y, z;
    } up;

    //rotateFunction -> more than important
    void rotateX(float angle) {if(angle > 0 && center.x >= 360) center.x = 0; else center.x += angle;}
    void rotateY(float angle) {if(angle > 0 && center.y >= 360) center.y = 0; else center.y += angle;}
    void move(float x, float z) {
    	//rotate vector x, z in point 0,0;
    	float angle = (center.x/180) * M_PI;
    	float x_r = x*cos(angle) - z*sin(angle); //it is wrong, really wrong
    	float z_r = x*sin(angle) + z*cos(angle); //perhaps it is better to extract values from matrix
    	//add it to existing position
    	eye.z += z_r;
    	eye.x += x_r;
    }
} typedef Camera;



#endif /* CAMERA_H_ */
