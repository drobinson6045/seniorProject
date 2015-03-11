/**
 * @file 	problem.c
 * @brief 	Example problem: bouncing balls.
 * @author 	Hanno Rein <hanno@hanno-rein.de>
 * @detail 	This example is a simple test of collision detection 
 * methods. To change the collision detection algorithm, you can replace
 * the module collisions_direct.c to either collisions_tree.c or 
 * collisions_sweep.c in the Makefile. 
 * 
 * @section 	LICENSE
 * Copyright (c) 2011 Hanno Rein, Shangfei Liu
 *
 * This file is part of rebound.
 *
 * rebound is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rebound is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rebound.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include "main.h"
#include "particle.h"
#include "boundaries.h"

extern double coefficient_of_restitution; 
//extern double OMEGA;

void problem_init(int argc, char* argv[]){

	// Setup constants
	double OMEGA = 0.00013143527;
	dt = 36;
	//dt = dt/604800; // Convert to weeks
	tmax = 1e10000;
	boxsize = 10000*10;
	double radius = 50000;  //In kiloMeters
	int nAsteroids = 1000;
	double mAsteroid = 1./nAsteroids; //In Earth masses

	double G = 2.9736e15;

	//Calculate Velocity Magnitude
	double v0 = sqrt(3/5*G*nAsteroids*mAsteroid/radius);  //In MKS
	//double unityMassMod = 6.7218859374E33;
	//coefficient_of_restitution = 1; // elastic collisions
	// Do not use any ghost boxes
	nghostx = 0; nghosty = 0; nghostz = 0;

	// Setup particle structures
	init_box();
	// Initial conditions
	//Place particles
	struct particle p;
	/*p.x=0;
	p.y=0;
	p.z=0;
	p.m=1;
	p.r=10;
	particles_add(p);*/
	for (int i=0;i<nAsteroids;i++){
		double theta = ((double)rand()/(double)RAND_MAX-0.5)*2*M_PI;
		double phi = ((double)rand()/(double)RAND_MAX-0.5)*M_PI;

		double xdir = ((double)rand()/(double)RAND_MAX-0.5);
		double ydir = ((double)rand()/(double)RAND_MAX-0.5);
		double zdir = ((double)rand()/(double)RAND_MAX-0.5);
		double dirMag = sqrt(xdir*xdir+ydir*ydir+zdir*zdir);
		p.x = ((double)rand()/(double)RAND_MAX-0.5)*radius*sin(phi)*cos(theta);
		p.y = ((double)rand()/(double)RAND_MAX-0.5)*radius*sin(phi)*sin(theta);
		p.z = ((double)rand()/(double)RAND_MAX-0.5)*radius*cos(phi);
		p.m = mAsteroid;
		p.temp = 11472.999999;
		//p.m = mAsteroid/unityMassMod;
		p.r  = calculate_radius(p.m);
		//p.r = 1;
		p.ax =  0; p.ay =  0; p.az =  0;
		xdir = ((double)rand()/(double)RAND_MAX-0.5);
		ydir = ((double)rand()/(double)RAND_MAX-0.5);
		zdir = ((double)rand()/(double)RAND_MAX-0.5);
		dirMag = sqrt(xdir*xdir+ydir*ydir+zdir*zdir);
		p.vx = v0*xdir/dirMag;
		p.vy = v0*zdir/dirMag;
		p.vz = v0*zdir/dirMag;
		particles_add(p);
		
	}

        
}

void problem_inloop(){
}

void problem_output(){
}

void problem_finish(){
  
}
