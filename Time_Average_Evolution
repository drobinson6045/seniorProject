 #!/usr/bin/python

import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
import time
import math
import random
import sys

dt = 1 # Time step of simulation

iteration_array = []
f = open('DataFile.txt', 'r')
dataArray = f.readlines()
iterations = np.float(dataArray[0][0:])
file_location = 1
max_value = 0

for i in xrange(0, int(iterations)): # This loop reads data from the textfile and places it into nested arrays
  particle_array = []
  num_particles = np.float(dataArray[int(file_location)][0:]) # Read the number of particles for the current timestep

  for j in xrange(0, int(num_particles)): # Scan over the number of particles for the current time step
    value = np.float(dataArray[int(file_location+j+1)][0:])
    if value > max_value:
      max_value = value
    particle_array.append(value)

  iteration_array.append(particle_array) # Append the array of particle data as an element of the iteration array
  file_location = file_location + num_particles + 1
f.close()

average_array = []  # For plotting
timestep_array = [] # For plotting

# Compute average value for each timestep
for i in xrange(0, int(iterations)):
  cumulative_sum = 0
  for j in xrange(0, len(iteration_array[i])):
    cumulative_sum = cumulative_sum + iteration_array[i][j]
  average_array.append( cumulative_sum/len(iteration_array[i]) )
  timestep_array.append(i*dt)

# Plot
plt.plot(timestep_array, average_array, 'ko')
plt.xlabel('Time')
plt.ylabel('Average Value')
plt.ylim(0, max_value)
plt.grid(b=True, which='major', color='grey', linestyle='-')
plt.title('Average Value as a Function of Time')
plt.show()



