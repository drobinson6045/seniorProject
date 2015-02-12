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

void problem_init(int argc, char* argv[]){
	// Setup constants
	dt = 1e-2;
	tmax = 10000;
	boxsize = 0.1;
	double radius = 20;  //In Au
	int nAsteroids = 10000;
	double mAsteroid = 100; //In Kg
	//Calculate Velocity Magnitude
	double G = 1;
	double v0 = sqrt(3/5*G*nAsteroids*mAsteroid/radius);  //In Au/Day
	double unityMassMod = 6.7218859374E33;
	//coefficient_of_restitution = 1; // elastic collisions
	// Do not use any ghost boxes
	nghostx = 0; nghosty = 0; nghostz = 0;

	// Setup particle structures
	init_box();
	// Initial conditions
	//Place particles
	struct particle p;
	for (int i=0;i<nAsteroids;i++){
		double xdir = ((double)rand()/(double)RAND_MAX-0.5);
		double ydir = ((double)rand()/(double)RAND_MAX-0.5);
		double zdir = ((double)rand()/(double)RAND_MAX-0.5);
		double dirMag = sqrt(xdir*xdir+ydir*ydir+zdir*zdir);
		p.x = radius*xdir/dirMag;
		p.y = radius*ydir/dirMag;
		p.z = radius*zdir/dirMag;
		p.m = mAsteroid;
		p.m = mAsteroid/unityMassMod;
		p.r  = calculate_radius(p.m);
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
