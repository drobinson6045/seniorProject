 #!/usr/bin/python

import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
import time
import math
import random
import sys

### Use whenever receiving input (no need to repeat it anymore!)
def InputFormat(minimum, maximum, string, inclusive):
  exit = 'exit'
  while True:
    variable = raw_input(string)
    if variable == exit:
      break
    else:
      try:
        variable = int(variable)

        if inclusive == True:
          if variable < minimum:
            print'Input must be greater than or equal to %d' % (minimum)
            continue
          elif variable > maximum:
            print 'Input must be less than or equal to %d' % (maximum)
            continue

        elif inclusive == False:
          if variable <= minimum:
            print 'Input must be greater than %d' % (minimum)
            continue
          elif variable >= maximum:
            print 'Input must be less than %d' % (maximum)
            continue

        else:
          break
        break

      except ValueError:
        print 'Invalid input, please try again.'
  return variable
###

iteration_string = 'Enter the number of iterations: '
iterations = int(InputFormat(0, 10000000, iteration_string, False))

particle_string = 'Enter the maximum number of particles for each timestep: '
max_num_particles = int(InputFormat(0, 10000, particle_string, False))

f_data = open('DataFile.txt', 'w')
f_data.write('%d\n' % iterations)
for i in xrange(0, iterations):
  particle_count = int(random.uniform(1, max_num_particles))
  f_data.write('%d\n' % particle_count)
  for j in xrange(0, particle_count):
    data_point = random.uniform(0, 10)
    f_data.write('%f\n' % data_point)
f_data.close()
  




