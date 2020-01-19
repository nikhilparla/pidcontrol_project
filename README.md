#### Project Notes and Observations

1. Initial parameters were chosen based on the class projects. Values of 0.2, 0.004 and 3.0 respectively chosen for Kp, Ki and Kd. The car could complete the track without leaving the drivable track surface. This is at 30mph. 
2. Twiddle implementation with initial parameter values as above and vector values for potential changes as {1,1,1} caused the car to veer off track even before it could correct itself. Reduced the speed from 30mph to 10mph to give some time for stabilization, still not sufficient.
3.  Observed that changing param values by a large number , ‘1’ in our case , is really making the steering value jump causing the car to veer off. Will reduce the change to 0.5
4. Corrected the error calculating mechanism. Printing out the accumulated error at every place. Reducing the dp values to 0.5,0.5,0.1. Any change in Ki is drastically affecting steering angle.
5. Car now finishes the track at 10Mph with final parameter values from Twiddle output of {Kp:0.463243	Kd:3.5	Ki: 0.014}